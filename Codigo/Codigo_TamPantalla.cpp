/*#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
template <typename T>
bool AjustarVentana(int Ancho, int Alto);
bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tama�o
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tama�o de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
*/
