#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <windows.h>
#include <stdexcept>
using namespace std;

template <typename T>
T Min(T a,T b){
return (a < b) ? a : b;
}
void ResizeWindow(HANDLE hConsole, SHORT xSize, SHORT ySize){
CONSOLE_SCREEN_BUFFER_INFO csbi;
BOOL bSuccess;
SMALL_RECT srWindowRect;
COORD coordScreen;
 
bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
coordScreen = GetLargestConsoleWindowSize(hConsole);
srWindowRect.Right = (SHORT) (Min(xSize, coordScreen.X) - 1);
srWindowRect.Bottom = (SHORT) (Min(ySize, coordScreen.Y) - 1);
srWindowRect.Left = srWindowRect.Top = (SHORT) 0;
coordScreen.X = xSize;
coordScreen.Y = ySize;
if ((DWORD) csbi.dwSize.X * csbi.dwSize.Y > (DWORD) xSize * ySize){
bSuccess = SetConsoleWindowInfo(hConsole, TRUE, &srWindowRect);
bSuccess = SetConsoleScreenBufferSize(hConsole, coordScreen);
}
 
if ((DWORD) csbi.dwSize.X * csbi.dwSize.Y < (DWORD) xSize * ySize){
bSuccess = SetConsoleScreenBufferSize(hConsole, coordScreen);
bSuccess = SetConsoleWindowInfo(hConsole, TRUE, &srWindowRect);
 
}
 return;}

int main(){
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
ResizeWindow(hStdout,110,30);
cout << "Hola Mundo";
}
