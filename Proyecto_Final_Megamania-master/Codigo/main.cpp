#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mmsystem.h>
#include <cstdlib>
#include <unistd.h>

#define _ARR  0x4800
#define _ABJ  0x5000
#define _IZQ  0x4b00
#define _DER  0x4d00
#define _ESP   0x3920
using namespace std;

template <typename T>
//Ajustes
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

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}  
//Apariencia
void Letras(){
	
	gotoxy(15,5);
	cout<<"                     888b     d888                                                            d8b          ";
	gotoxy(15,6);
	cout<<"                     8888b   d8888                                                            Y8P          ";
	gotoxy(15,7);
	cout<<"                     88888b.d88888                                                                         ";
	gotoxy(15,8);
	cout<<"                     888Y88888P888  .d88b.   .d88b.   8888b.  88888b.d88b.   8888b.  88888b.  888  8888b.  ";
	gotoxy(15,9);
	cout<<"                     888 Y888P 888 d8P  Y8b d88P 88b      88b 888  888  88b      88b 888  88b 888      88b ";
	gotoxy(15,10);
	cout<<"                     888  Y8P  888 88888888 888  888 .d888888 888  888  888 .d888888 888  888 888 .d888888 ";
	gotoxy(15,11);
	cout<<"                     888       888   Y8888   Y888888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(15,12);
	cout<<"                     888       888   Y8888    Y88888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(15,13);
	cout<<"                                                 888                                                       ";
	gotoxy(15,14);
	cout<<"                                            Y8b d88P                                                       ";
	gotoxy(15,15);
	cout<<"                                              Y88P                                                         ";
}
void Marco(){
	//Largo del marco X
	int largo=39;
	//Largo del marco Y
	int ancho=159;
	 for(int y=0;y<=largo;++y){
		for(int x=0;x<=ancho;++x){
		//----Lineas del marco----
			//Parte superior
			if(x!=0 and y==0){
				gotoxy(x,y);
				system("color 09");
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
//Menus
void MenuOpciones(int x1,int y1,char flechita){
 	system("cls");
	Marco();
	Letras();
	system("color 07");
	y1=19,x1=44;
	gotoxy(45,19);
	cout<<"Instrucciones";
	gotoxy(45,21);
	cout<<"Creditos";
	gotoxy(45,23);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
 }
void Instrucciones(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	system("color 05");
	y1=19,x1=44;
	gotoxy(45,19);
	cout<<"Instrucciones";
	gotoxy(45,20);
	cout<<"Izquierda,derecha: Moverse";
	gotoxy(45,21);
	cout<<"Espacio: Disparar";
	gotoxy(45,22);
	cout<<"Enter: Pausa";
	gotoxy(45,23);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
} 
void Creditos(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	system("color 02");
	y1=15,x1=44;
	gotoxy(45,19);
	cout<<"Creditos";
	gotoxy(45,20);
	cout<<"Isaac Alejandro Perez Castro";
	gotoxy(45,21);
	cout<<"Abdiel Flores Gastelum";
	gotoxy(45,23);
	cout<<"Regresar";
	gotoxy(x1,y1);
	cout<<flechita;
 }
void Menu(int x1,int y1,char flechita){
	
 	x1=44,y1=19;
 	gotoxy(45,19);
	cout<<"Iniciar juego";
	gotoxy(45,21);
	cout<<"Opciones";
	gotoxy(45,23);
	cout<<"Salir";
	gotoxy(x1,y1);
	cout<<flechita;
 }
//Enemigos Lvl.1
 void enemigos(bool destruidos[21], int x){
 	char ene=220;
 	//Primera fila
	if(destruidos[0]==true){//
		gotoxy(x+10,2);
		cout<<ene;
	}
	if(destruidos[1]==true){
		gotoxy(x+38,2);
		cout<<ene;
	}
	if(destruidos[2]==true){
		gotoxy(x+66,2);
		cout<<ene;
	}
	if(destruidos[3]==true){
		gotoxy(x+94,2);
		cout<<ene;
	}
	if(destruidos[4]==true){
		gotoxy(x+122,2);
		cout<<ene;
	}
	if(destruidos[5]==true){
		gotoxy(x+150,2);
		cout<<ene;
	}
	//Segunda fila
	if(destruidos[6]==true){
		gotoxy(x+17,4);
		cout<<ene;
	}
	if(destruidos[7]==true){
		gotoxy(x+31,4);
		cout<<ene;
	}
	if(destruidos[8]==true){
		gotoxy(x+45,4);
		cout<<ene;
	}
	if(destruidos[9]==true){
		gotoxy(x+59,4);
		cout<<ene;
	}
	if(destruidos[10]==true){
		gotoxy(x+73,4);
		cout<<ene;
	}
	if(destruidos[11]==true){
		gotoxy(x+87,4);
		cout<<ene;
	}
	if(destruidos[12]==true){
		gotoxy(x+101,4);
		cout<<ene;
	}
	if(destruidos[13]==true){
		gotoxy(x+115,4);
		cout<<ene;
	}
	if(destruidos[14]==true){
		gotoxy(x+129,4);
		cout<<ene;
	}
	if(destruidos[15]==true){
		gotoxy(x+144,4);
		cout<<ene;
	}
 	//Tercera fila
	if(destruidos[16]==true){
		gotoxy(x+24,6);
		cout<<ene;
	}
	if(destruidos[17]==true){
		gotoxy(x+52,6);
		cout<<ene;
	}
	if(destruidos[18]==true){
		gotoxy(x+80,6);
		cout<<ene;
	}
	if(destruidos[19]==true){
		gotoxy(x+108,6);
		cout<<ene;
	}
	if(destruidos[20]==true){
		gotoxy(x+136,6);
		cout<<ene;
	}
 }
//Enemigo
void EnemigosNivel1(){
	system("cls");
	system("color 07");
	//char soundfile[] = "LASRLIT3.wav";
	                     /*                               FILAS                                        */
	                     /*1*/                                   /*2*/                              /*3*/
	bool destruidos[21]={true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
	//Jugador
	char nave=219,bala=250;
	int tecla,cont=0;
	int x=75,y=29;
	int x1=0;
	int xBala,yBala;
	gotoxy(x,y);
	cout<<nave;
	//
	int n=0;
	bool run=true;
	while(run){
		if(n%5000==0){x1++;system("cls");enemigos(destruidos,x1);}
		if(n==0){enemigos(destruidos,x1);}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
            	//Derecha
            	case 77:
					if(x<159){
						x++;
					}
            		system("cls");
            		enemigos(destruidos,x1);
            		break;
            	//Izquierda
				case 75:
					if(x>0){
						x--;
					}
					system("cls");
					enemigos(destruidos,x1);
            		break;
            	//Espacio
            
				case 32:
			    	xBala=x,yBala=y;
			    	gotoxy(xBala,yBala-1);
					cout<<bala;
			    	//PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC ); 
			    	for(int yBala=y-1;yBala>-2;--yBala){
						system("cls");
						gotoxy(xBala,yBala);
//Validaciones
						//Fila 1
						if(yBala==2){
							if(xBala==x1+10){
								destruidos[0]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+38){
								destruidos[1]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+66){
								destruidos[2]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+94){
								destruidos[3]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+122){
								destruidos[4]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+150){
								destruidos[5]=false;
								enemigos(destruidos,x1);
								break;
							}
						}
						//Fila 2
						if(yBala==4){
							if(xBala==x1+17){
								destruidos[6]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+31){
								destruidos[7]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+45){
								destruidos[8]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+59){
								destruidos[9]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+73){
								destruidos[10]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+87){
								destruidos[11]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+101){
								destruidos[12]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+115){
								destruidos[13]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+129){
								destruidos[14]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+144){
								destruidos[15
								]=false;
								enemigos(destruidos,x1);
								break;
							}
						}
						//Fila 3
						if(yBala==6){
							if(xBala==x1+24){
								destruidos[16]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+52){
								destruidos[17]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+80){
								destruidos[18]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+108){
								destruidos[19]=false;
								enemigos(destruidos,x1);
								break;
							}
							if(xBala==x1+136){
								destruidos[20]=false;
								enemigos(destruidos,x1);
								break;
							}
						}
//de colociones
						enemigos(destruidos,x1);
						cout<<bala;
						gotoxy(x,y);
						cout<<nave;
					}
            		break;
    		}
    	}
    	gotoxy(x,y);
		cout<<nave;
		n++;
	}
}
int main(){
	
	AjustarVentana(160,40);  // Para otras de menor resolución
	int tecla,op=0,arrabj=0;
	int x=45,y=19;
	int x1=44,y1=19;
	bool run=true,run2=true;
	char flechita='>';
	int pantalla=0;
	do{
	x1=44,y1=19;
	x=45,y=19;
	switch(pantalla){
		case 0:
			system("cls");
			Marco();
			Letras();
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
		case 4:
			system("cls");
			//jugador();
			EnemigosNivel1();
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
            		//Validacion de flechita arriba
            		//PlaySound((LPCSTR)"Menu", NULL, SND_FILENAME | SND_ASYNC ); 
					if(y1>19){
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
            		//Validacion de flechita abajo
            	//	PlaySound((LPCSTR)"Menu", NULL, SND_FILENAME | SND_ASYNC ); 
					if(y1<23){
						y1=y1+2;
						op++;
					}
					arrabj=1;
            		break;
            	//Enter
				case 13:
					if(y1==19){
						if(pantalla==1){
							pantalla=3;
							run=false;
						}	
						if(pantalla==0){
							pantalla=4;
							run=false;
						}
							
					}

					if(y1==21){
						if(pantalla==0){
							pantalla=1;
							run=false;
						}else if(pantalla==1){
							pantalla=2;
							run=false;
						}	
							
					}
					if(y1==23){
						if(pantalla==0){
							system("cls");
							gotoxy(45,19);
							cout<<"Adios :)";
							return 0;
							}else if(pantalla==1){
							system("cls");
							pantalla=0;
							run=false;
							}else if(pantalla==2){
							system("cls");
							pantalla=1;
							run=false;
							}else if(pantalla==3){
							system("cls");
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
