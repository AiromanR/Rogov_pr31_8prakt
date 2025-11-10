#include <iostream>
#include <Windows.h>

volatile int array[50] = { 0 };
volatile int turtlesPlaces[10] = { 0 };
volatile bool raceFinished = false;
volatile int finishedCount = 0;

DWORD WINAPI Move(LPVOID turtleID)
{
    int position = 0;
    int turtleNum = (int)turtleID;
    srand(time(NULL) + GetCurrentThreadId());

    while (!raceFinished) {

        if (array[position] == turtleNum) array[position] = 0;
        position += rand() % 3;
        if (position >= 50) break;
        array[position] = turtleNum;
        Sleep(1000 + (rand() % 2000));
    }

    for (int i = 0; i < 10; i++) {
        if (turtlesPlaces[i] == 0) {
            turtlesPlaces[i] = turtleNum;
            finishedCount++;
            break;
        }
    }

    if (finishedCount >= 10) {
        raceFinished = true;
    }

    return 0;
}

void DisplayRace()
{
    std::cout << "Гонка" << std::endl;
    std::cout << "Старт [";
    for (int i = 0; i < 50; i++) {
        if (array[i] == 0) {
            std::cout << "_";
        }
        else {
            if (array[i] >= 10) {
                std::cout << array[i];
                i++;
            }
            else {
                std::cout << array[i];
            }
        }
    }
    std::cout << "] Финиш" << std::endl;
    std::cout << "Финишировало: " << finishedCount << "/10" << std::endl;
}

int main()
{
    setlocale(0, "rus");
    HANDLE hThreads[10];
    DWORD IDThreads[10];

    for (int i = 0; i < 10; i++) hThreads[i] = CreateThread(NULL, 0, &Move, (void*)(i + 1), 0, &IDThreads[i]);

    while (!raceFinished) {
        DisplayRace();
        Sleep(500);
        system("cls");
    }

    for (int i = 0; i < 10; i++) CloseHandle(hThreads[i]);

    std::cout << "Результаты:" << std::endl;
    for (int i = 0; i < 10; i++) {
        if (i == 0) std::cout << "Победитель!" << " - черепаха: " << turtlesPlaces[i] << std::endl;
        else std::cout << "Место " << i + 1 << " - черепаха: " << turtlesPlaces[i] << std::endl;
    }

    return 0;
}