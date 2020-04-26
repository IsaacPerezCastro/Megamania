#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _ARR  0x4800
#define _ABJ  0x5000
#define _IZQ  0x4b00
#define _DER  0x4d00
using namespace std;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}  

void Letras(){
	
	
	gotoxy(15,2);
	cout<<"888b     d888                                                            d8b          ";
	gotoxy(15,3);
	cout<<"8888b   d8888                                                            Y8P          ";
	gotoxy(15,4);
	cout<<"88888b.d88888                                                                         ";
	gotoxy(15,5);
	cout<<"888Y88888P888  .d88b.   .d88b.   8888b.  88888b.d88b.   8888b.  88888b.  888  8888b.  ";
	gotoxy(15,6);
	cout<<"888 Y888P 888 d8P  Y8b d88P 88b      88b 888  888  88b      88b 888  88b 888      88b ";
	gotoxy(15,7);
	cout<<"888  Y8P  888 88888888 888  888 .d888888 888  888  888 .d888888 888  888 888 .d888888 ";
	gotoxy(15,8);
	cout<<"888       888   Y8888   Y888888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(15,9);
	cout<<"888       888   Y8888    Y88888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(15,10);
	cout<<"                            888                                                       ";
	gotoxy(15,11);
	cout<<"                       Y8b d88P                                                       ";
	gotoxy(15,12);
	cout<<"                         Y88P                                                         ";
}

void Marco(){
	
	//Largo del marco X
	int largo=25;
	//Largo del marco Y
	int ancho=119;
	 for(int y=0;y<=largo;++y){
		for(int x=0;x<=ancho;++x){
		//----Lineas del marco----
			//Parte superior
			if(x!=0 and y==0){
				gotoxy(x,y);
				printf("%c", 205);
			}
			//Partes laterales
			if((x==0 and y!=0) or (x==ancho and y!=0)){
				if(x==0){
					gotoxy(x,y);
					printf("%c", 186);
				}
				if(x==ancho){
					gotoxy(x,y);
					printf("%c", 186);
				}
			}
		//----Esquinas----
			//Parte inferior
			if(x!=0 and y==largo){
				gotoxy(x,y);
				printf("%c", 205);
			}
			//Esquina superior izquierda
			if(x==0 and y==0){
				gotoxy(0,0);
				printf("%c", 201);
			}
			//Esquina superior derecha
			if(x==ancho and y==0){
				gotoxy(x,y);
				printf("%c", 187);
			}
			//Esquina inferior izquierda
			if(x==0 and y==largo){
				gotoxy(x,y);
				printf("%c", 200);
			}
			//Esquina inferior derecha
			if(x==ancho and y==largo){
				gotoxy(x,y);
				printf("%c", 188);
			}
		}
	}
 }
 void MenuOpciones(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	y1=15,x1=44;
	gotoxy(45,15);
	cout<<"Instrucciones";
	gotoxy(45,17);
	cout<<"Creditos";
	gotoxy(45,19);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
 }
 
 
 void Instrucciones(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	y1=15,x1=44;
	gotoxy(45,15);
	cout<<"Instrucciones";
	gotoxy(45,17);
	cout<<"Aqui van las instrucciones";
	gotoxy(45,19);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
 }
 
 
 void Creditos(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	y1=15,x1=44;
	gotoxy(45,15);
	cout<<"Creditos";
	gotoxy(45,16);
	cout<<"El Isaac Perez (Mlp)";
	gotoxy(45,17);
	cout<<"Abdiel Flores AKA El Viejon";
	gotoxy(45,19);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
 }
 
 void Menu(int x1,int y1,char flechita){
 	 x1=44,y1=15;
 		gotoxy(45,15);
	cout<<"Iniciar juego";
	gotoxy(45,17);
	cout<<"Opciones";
	gotoxy(45,19);
	cout<<"Salir";
	gotoxy(x1,y1);
	cout<<flechita;
 }
 
 
int main(){
	int tecla,op=0,arrabj=0;
	int x=45,y=15;
	int x1=44,y1=15;
	bool run=true,run2=true;
	char flechita='>';
	int pantalla=0;
	do{
	x1=44,y1=15;
	x=45,y=15;
	system("cls");
	Marco();
	Letras();
	switch(pantalla){
		case 0:
			Menu(x1,y1,flechita);
		break;
		case 1:
			MenuOpciones(x1,y1,flechita);
		break;
		case 2:
			Creditos(x1,y1,flechita);
		break;
		case 3:
			Instrucciones(x1,y1,flechita);
		break;
	}
	
		run=true;
	do{
		gotoxy(x1,y1);
		cout<<flechita;
		gotoxy(x1,y1);
		//Lectura de tecla precionada
		if (_kbhit())
        {
			tecla = getch();
            //cout<<tecla;
			switch(tecla){
            	//Derecha
            	case 77:
            		break;
            	//Arriba
            	case 72:
            		if(y1>15){
	            		y1=y1-2;
	            		op--;
					}
					arrabj=0;
            		break;
            	//Izquierda
				case 75:
            		break;
            	//Abajo
            	case 80:
            		if(y1<19){
						y1=y1+2;
						op++;
					}
					arrabj=1;
            		break;
            	//Enter
				case 13:
					if(y1==15){
						if(pantalla==1){
							pantalla=3;
							run=false;
						}	
							
					}

					if(y1==17){
						if(pantalla==0){
							pantalla=1;
							run=false;
						}else if(pantalla==1){
							pantalla=2;
							run=false;
						}	
							
					}
					if(y1==19){
						if(pantalla==0){
							system("cls");
							Marco();
							Letras();
							gotoxy(45,15);
							cout<<"Adios :)";
							return 0;
							}else if(pantalla==1){
							system("cls");
							Marco();
							Letras();
							pantalla=0;
							run=false;
							}else if(pantalla==2){
							system("cls");
							Marco();
							Letras();
							pantalla=1;
							run=false;
							}else if(pantalla==3){
							system("cls");
							Marco();
							Letras();
							pantalla=1;
							run=false;
							}
					}
					
					
            		//getch();
            		break;
	            	
			}
			//Limpiar flecha anterior
			if(arrabj==1){
				gotoxy(x1,y1-2);
				cout<<" ";
				
			}else{
				gotoxy(x1,y1+2);
				cout<<" ";
			}
        }
	}while(run);
	
	}while(run2);
	return 0;
}
