#include <iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y){
	
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X=x;
	dwPos.Y=y;
	
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

