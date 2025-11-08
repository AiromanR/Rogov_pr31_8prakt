#include <iostream>
#include <windows.h>
#include <string>
struct Turtle {
    int position;
    int name;
    bool isFinished;
    Turtle() : position(1), isFinished(false) {}
};

int findedWinner = -1;

DWORD WINAPI turtleRun(LPVOID voidTurtle) {
    Turtle* t = (Turtle*)voidTurtle;

    srand(time(NULL) + GetCurrentThreadId());
    int distant = 50;
    while (t->position < distant) {
        int step = (rand() % 3);
        t->position += step;

        if (t->position >= distant) {
            t->position = distant;
            t->isFinished = true;
            break;
        }
        Sleep(100 + (rand() % 200));
    }
    return 0;
}


void drawRace(Turtle& t1, Turtle& t2, Turtle& t3, Turtle& t4, Turtle& t5, Turtle& t6, Turtle& t7, Turtle& t8, Turtle& t9, Turtle& t10) {
    std::cout << "Гонки черепах"<< std::endl;
    char arr[10][50];
    for (int i = 0; i <= 10; i++) {
        switch (i)
        {
        case(1):
            for (int j = 0; j < t1.position; j++) arr[0][j] = '~';
            arr[0][t1.position - 1] = '@';
            for (int j = 49; j >= t1.position; j--) arr[0][j] = '*';
            break;
        case(2):
            for (int j = 0; j < t2.position; j++) arr[1][j] = '~';
            arr[1][t2.position - 1] = '@';
            for (int j = 49; j >= t2.position; j--) arr[1][j] = '*';
            break;
        case(3):
            for (int j = 0; j < t3.position; j++) arr[2][j] = '~';
            arr[2][t3.position - 1] = '@';
            for (int j = 49; j >= t3.position; j--) arr[2][j] = '*';
            break;
        case(4):
            for (int j = 0; j < t4.position; j++) arr[3][j] = '~';
            arr[3][t4.position - 1] = '@';
            for (int j = 49; j >= t4.position; j--) arr[3][j] = '*';
            break;
        case(5):
            for (int j = 0; j < t5.position; j++) arr[4][j] = '~';
            arr[4][t5.position - 1] = '@';
            for (int j = 49; j >= t5.position; j--) arr[4][j] = '*';
            break;
        case(6):
            for (int j = 0; j < t6.position; j++) arr[5][j] = '~';
            arr[5][t6.position - 1] = '@';
            for (int j = 49; j >= t6.position; j--) arr[5][j] = '*';
            break;
        case(7):
            for (int j = 0; j < t7.position; j++) arr[6][j] = '~';
            arr[6][t7.position - 1] = '@';
            for (int j = 49; j >= t7.position; j--) arr[6][j] = '*';
            break;
        case(8):
            for (int j = 0; j < t8.position; j++) arr[7][j] = '~';
            arr[7][t8.position - 1] = '@';
            for (int j = 49; j >= t8.position; j--) arr[7][j] = '*';
            break;
        case(9):
            for (int j = 0; j < t9.position; j++) arr[8][j] = '~';
            arr[8][t9.position - 1] = '@';
            for (int j = 49; j >= t9.position; j--) arr[8][j] = '*';
            break;
        case(10):
            for (int j = 0; j < t10.position; j++) arr[9][j] = '~';
            arr[9][t10.position - 1] = '@';
            for (int j = 49; j >= t10.position; j--) arr[9][j] = '*';
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }


    if (findedWinner == -1) {
        if (t1.isFinished == true) findedWinner = 1;
        else if (t2.isFinished == true) findedWinner = 2;
        else if (t3.isFinished == true) findedWinner = 3;
        else if (t4.isFinished == true) findedWinner = 4;
        else if (t5.isFinished == true) findedWinner = 5;
        else if (t6.isFinished == true) findedWinner = 6;
        else if (t7.isFinished == true) findedWinner = 7;
        else if (t8.isFinished == true) findedWinner = 8;
        else if (t9.isFinished == true) findedWinner = 9;
        else if (t10.isFinished == true) findedWinner = 10;
    }
    else {
        if (findedWinner == 1) std::cout << "Победитель " << t1.name;
        else if (findedWinner == 2) std::cout << "Победитель " << t2.name;
        else if (findedWinner == 3) std::cout << "Победитель " << t3.name;
        else if (findedWinner == 4) std::cout << "Победитель " << t4.name;
        else if (findedWinner == 5) std::cout << "Победитель " << t5.name;
        else if (findedWinner == 6) std::cout << "Победитель " << t6.name;
        else if (findedWinner == 7) std::cout << "Победитель " << t7.name;
        else if (findedWinner == 8) std::cout << "Победитель " << t8.name;
        else if (findedWinner == 9) std::cout << "Победитель " << t9.name;
        else if (findedWinner == 10) std::cout << "Победитель " << t10.name;
    }

}

int main()
{
    setlocale(0, "rus");

    Turtle turtle1; turtle1.name = 1;
    Turtle turtle2; turtle2.name = 2;
    Turtle turtle3; turtle3.name = 3; 
    Turtle turtle4; turtle4.name = 4;
    Turtle turtle5; turtle5.name = 5;
    Turtle turtle6; turtle6.name = 6;
    Turtle turtle7; turtle7.name = 7;
    Turtle turtle8; turtle8.name = 8;
    Turtle turtle9; turtle9.name = 9;
    Turtle turtle10; turtle10.name = 10;

    HANDLE handleTurtle1;
    HANDLE handleTurtle2;
    HANDLE handleTurtle3;
    HANDLE handleTurtle4;
    HANDLE handleTurtle5;
    HANDLE handleTurtle6;
    HANDLE handleTurtle7;
    HANDLE handleTurtle8;
    HANDLE handleTurtle9;
    HANDLE handleTurtle10;

    DWORD idTurtle1;
    DWORD idTurtle2;
    DWORD idTurtle3;
    DWORD idTurtle4;
    DWORD idTurtle5;
    DWORD idTurtle6;
    DWORD idTurtle7;
    DWORD idTurtle8;
    DWORD idTurtle9;
    DWORD idTurtle10;
    
    handleTurtle1 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle1, 0, &idTurtle1);
    handleTurtle2 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle2, 0, &idTurtle2);
    handleTurtle3 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle3, 0, &idTurtle3);
    handleTurtle4 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle4, 0, &idTurtle4);
    handleTurtle5 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle5, 0, &idTurtle5);
    handleTurtle6 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle6, 0, &idTurtle6);
    handleTurtle7 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle7, 0, &idTurtle7);
    handleTurtle8 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle8, 0, &idTurtle8);
    handleTurtle9 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle9, 0, &idTurtle9);
    handleTurtle10 = CreateThread(NULL, 0, &turtleRun, (void*)&turtle10, 0, &idTurtle10);

    while (!(turtle1.isFinished && turtle2.isFinished && turtle3.isFinished && turtle4.isFinished && turtle5.isFinished && turtle6.isFinished && turtle7.isFinished && turtle8.isFinished && turtle9.isFinished && turtle10.isFinished)) {
        system("cls");
        drawRace(turtle1, turtle2, turtle3, turtle4, turtle5, turtle6, turtle7, turtle8, turtle9, turtle10);
        Sleep(500);
    }
    system("cls");
    drawRace(turtle1, turtle2, turtle3, turtle4, turtle5, turtle6, turtle7, turtle8, turtle9, turtle10);
    
    CloseHandle(handleTurtle1);
    CloseHandle(handleTurtle2);
    CloseHandle(handleTurtle3);
    CloseHandle(handleTurtle4);
    CloseHandle(handleTurtle5);
    CloseHandle(handleTurtle6);
    CloseHandle(handleTurtle7);
    CloseHandle(handleTurtle8);
    CloseHandle(handleTurtle9);
    CloseHandle(handleTurtle10);
}