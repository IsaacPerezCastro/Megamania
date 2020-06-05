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
void color(int x){
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,x);
}
//Apariencia
void Letras(){
	//color(5);
	
	gotoxy(17,2);
	cout<<"                     888b     d888                                                            d8b          ";
	gotoxy(17,3);
	cout<<"                     8888b   d8888                                                            Y8P          ";
	gotoxy(17,4);
	cout<<"                     88888b.d88888                                                                         ";
	gotoxy(17,5);
	cout<<"                     888Y88888P888  .d88b.   .d88b.   8888b.  88888b.d88b.   8888b.  88888b.  888  8888b.  ";
	gotoxy(17,6);
	cout<<"                     888 Y888P 888 d8P  Y8b d88P 88b      88b 888  888  88b      88b 888  88b 888      88b ";
	gotoxy(17,7);
	cout<<"                     888  Y8P  888 88888888 888  888 .d888888 888  888  888 .d888888 888  888 888 .d888888 ";
	gotoxy(17,8);
	cout<<"                     888       888   Y8888   Y888888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(17,9);
	cout<<"                     888       888   Y8888    Y88888  Y888888 888  888  888  Y888888 888  888 888  Y888888 ";
	gotoxy(17,10);
	cout<<"                                                 888                                                       ";
	gotoxy(17,11);
	cout<<"                                            Y8b d88P                                                       ";
	gotoxy(17,12);
	cout<<"                                              Y88P                                                         ";

}
void Marco(){
	color(3);
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
	
	gotoxy(48,16);
 	cout<<"  ___           _                       _                       ";
 	gotoxy(48,17);
 	cout<<" |_ _|_ __  ___| |_ _ __ _   _  ___ ___(_) ___  _ __   ___  ___ ";
 	gotoxy(48,18);
 	cout<<"  | || '_  / __| __| '__| | | |/ __/ __| |/ _  | '_  /  _  |  __|";
 	gotoxy(48,19);
 	cout<<"  | || | |  __ | |_| |  | |_| | (_| (__| | (_) | | | |  __/ __    " ;
 	gotoxy(48,20);
 	cout<<" |___|_| |_|___/ __|_|    __,_| ___ ___|_| ___/|_| |_| ___||___/";
 	
 	gotoxy(60,23);
 	cout<<"   ____              _ _ _            ";
 	gotoxy(60,24);
 	cout<<"  / ___|_ __ ___  __| (_) |_ ___  ___ ";
 	gotoxy(60,25);
 	cout<<" | |   | '__/ _  / _` | | __/ _  / __|";
 	gotoxy(60,26);
 	cout<<" | |___| | |  __/ (_| | | || (_)  __    ";
 	gotoxy(60,27);
 	cout<<"   ____|_|   ___| __,_|_| __ ___/|___/  ";
 	

 	
 	gotoxy(59,30);
 	cout<<"  ____                                     ";
 	gotoxy(59,31);
 	cout<<" |  _   ___  __ _ _ __ ___  ___  __ _ _ __ ";
 	gotoxy(59,32);
 	cout<<" | |_) / _  / _` | '__/ _  / __|/ _` | '__|";
 	gotoxy(59,33);
 	cout<<" |    <  __/ (_| | | |  __/ __   (_| | |   ";
 	gotoxy(59,34);
 	cout<<" |_| |_ ___| __, |_|   ___||___/ __,_|_|   ";
 	gotoxy(59,35);
 	cout<<"            |___/                          ";
 	
 
	gotoxy(x1,y1);
	cout<<flechita;
 }
void Instrucciones(int x1,int y1,char flechita){
 
 	system("cls");
 	
	Marco();
	Letras();
	system("color 05");
	y1=19,x1=44;
	
	gotoxy(48,16);
 	cout<<"  ___           _                       _                       ";
 	gotoxy(48,17);
 	cout<<" |_ _|_ __  ___| |_ _ __ _   _  ___ ___(_) ___  _ __   ___  ___ ";
 	gotoxy(48,18);
 	cout<<"  | || '_  / __| __| '__| | | |/ __/ __| |/ _  | '_  /  _  |  __|";
 	gotoxy(48,19);
 	cout<<"  | || | |  __ | |_| |  | |_| | (_| (__| | (_) | | | |  __/ __    " ;
 	gotoxy(48,20);
 	cout<<" |___|_| |_|___/ __|_|    __,_| ___ ___|_| ___/|_| |_| ___||___/";
	
	gotoxy(55,25);
	cout<<"Izquierda,derecha: Moverse";
	gotoxy(55,26);
	cout<<"Espacio: Disparar";
	gotoxy(55,27);
	cout<<"Enter: Pausa";
	
	
	gotoxy(59,31);
 	cout<<"  ____                                     ";
 	gotoxy(59,32);
 	cout<<" |  _   ___  __ _ _ __ ___  ___  __ _ _ __ ";
 	gotoxy(59,33);
 	cout<<" | |_) / _  / _` | '__/ _  / __|/ _` | '__|";
 	gotoxy(59,34);
 	cout<<" |    <  __/ (_| | | |  __/ __   (_| | |   ";
 	gotoxy(59,35);
 	cout<<" |_| |_ ___| __, |_|   ___||___/ __,_|_|   ";
 	gotoxy(59,36);
 	cout<<"            |___/                          ";
	gotoxy(x1,y1);
	cout<<flechita;
} 
void Creditos(int x1,int y1,char flechita){
 
 	system("cls");
	Marco();
	Letras();
	system("color 02");
	y1=19,x1=44;
	gotoxy(60,16);
 	cout<<"   ____              _ _ _            ";
 	gotoxy(60,17);
 	cout<<"  / ___|_ __ ___  __| (_) |_ ___  ___ ";
 	gotoxy(60,18);
 	cout<<" | |   | '__/ _  / _` | | __/ _  / __|";
 	gotoxy(60,19);
 	cout<<" | |___| | |  __/ (_| | | || (_)  __    ";
 	gotoxy(60,20);
 	cout<<"   ____|_|   ___| __,_|_| __ ___/|___/  ";
 	gotoxy(60,24);
	cout<<"Universidad Autonoma de Baja California Sur";
 	gotoxy(60,25);
	cout<<"Departamento Academico de Sistemas Computacionales";
	gotoxy(60,26);
	cout<<"Prof: Ing. Jonathan Soto";
	gotoxy(60,27);
	cout<<"Isaac Alejandro Perez Castro";
	gotoxy(60,28);
	cout<<"Abdiel Flores Gastelum";
	gotoxy(45,23);
	
	
	gotoxy(9,31);
 	cout<<" _   _   _ ____   ____ ____  ";
 	gotoxy(9,32);
 	cout<<"| | | | / | __ ) / ___/ ___| ";
 	gotoxy(9,33);
 	cout<<"| | | |/ _|  _  | |    ___   ";
 	gotoxy(9,34);
 	cout<<"| |_| / __| |_) | |___ ___)|";
 	gotoxy(9,35);
 	cout<<"  ___/_/  |____/  ____|____/";

	gotoxy(128,31);
 	cout<<"  ____    _  ____   ____ ";
 	gotoxy(128,32);
 	cout<<" |  _    /  / ___|/ ___|";
 	gotoxy(128,33);
 	cout<<" | | | |/ _|___  | |    ";
 	gotoxy(128,34);
 	cout<<" | |_| / __ ___) | |___ ";
 	gotoxy(128,35);
 	cout<<" |____/_/  |____/  ____|";
	
	gotoxy(59,31);
 	cout<<"  ____                                     ";
 	gotoxy(59,32);
 	cout<<" |  _   ___  __ _ _ __ ___  ___  __ _ _ __ ";
 	gotoxy(59,33);
 	cout<<" | |_) / _  / _` | '__/ _  / __|/ _` | '__|";
 	gotoxy(59,34);
 	cout<<" |    <  __/ (_| | | |  __/ __   (_| | |   ";
 	gotoxy(59,35);
 	cout<<" |_| |_ ___| __, |_|   ___||___/ __,_|_|   ";
 	gotoxy(59,36);
 	cout<<"            |___/                          ";
	gotoxy(x1,y1);
	cout<<flechita;

 }
void Menu(int x1,int y1,char flechita){
	
 	x1=44,y1=19;
 	gotoxy(62,16);
 	cout<<"  ___       _      _             ";
 	gotoxy(62,17);
 	cout<<" |_ _|_ __ (_) ___(_) __ _ _ __  ";
 	gotoxy(62,18);
 	cout<<"  | || '_  | |/ __| |/ _` | '__|  ";
 	gotoxy(62,19);
 	cout<<"  | || | | | | (__| | (_| | |   ";
 	gotoxy(62,20);
 	cout<<" |___|_| |_|_| ___|_| __,_|_|    ";
 //	cout<<""<<endl;
 //	cout<<""<<endl;
 //	cout<<""<<endl;
//	cout<<"Iniciar juego";
    gotoxy(57,23);
 	cout<<"   ___             _                      ";
 	gotoxy(57,24);
 	cout<<"  / _   _ __   ___(_) ___  _ __   ___  ___ ";
 	gotoxy(57,25);
 	cout<<" | | | | '_   / __| |/ _  | '_   / _  / __|";
 	gotoxy(57,26);
 	cout<<" | |_| | |_) | (__| | (_) | | | |  __/ __     ";
 	gotoxy(57,27);
 	cout<<"   ___/| .__/  ___|_| ___/|_| |_| ___||___/";
 	gotoxy(57,28);
 	cout<<"       |_|                                 ";
 	
 	gotoxy(66,31);
 	cout<<"  ____        _ _      ";
 	gotoxy(66,32);
 	cout<<" / ___|  __ _| (_)_ __ ";
 	gotoxy(66,33);
 	cout<<"  ___   / _` | | | '__|";
 	gotoxy(66,34);
 	cout<<"  ___) | (_| | | | |   ";
 	gotoxy(66,35);
 	cout<<" |____/  __,_|_|_|_|   ";

	gotoxy(45,27);
//	cout<<"Opciones";
	gotoxy(45,28);
//	cout<<"Salir";
	gotoxy(x1,y1);
	cout<<flechita;
 }
//Contador
void contador(int tiempo){
	char l[120];
	char k[120];
	int z=0;
	for(int x=30;x<=120;++x){
		color(4);
		gotoxy(x,34);
		l[z]=219;
		cout<<l[z];
		z++;
	}
	z=0;
	for(int x=30;x<=120;++x){
		k[z]=219;
		z++;
	}
	z=0;
	color(7);
	gotoxy(19,34);
	cout<<"Energia";
	//gotoxy(119,33);
	//cout<<tiempo;
	for(int x=30+tiempo;x<=120;++x){
		color(6);
		gotoxy(x,34);
		cout<<k[z];
		z++;
	}
	
}
//Enemigos Lvl.1
 void enemigos(bool destruidos[21], int x){
 	color(14);
	char ene=220;
 	//Primera fila
	if(destruidos[0]==true){
		if(x+10<150){
			gotoxy(x+10,2);
			cout<<ene;
		}
	}
	if(destruidos[1]==true){
		if(x+38<150){
			gotoxy(x+38,2);
			cout<<ene;
		}
		
	}
	if(destruidos[2]==true){
		if(x+66<150){
			gotoxy(x+66,2);
			cout<<ene;
		}
	}
	if(destruidos[3]==true){
		if(x+94<150){
			gotoxy(x+94,2);
			cout<<ene;
		}
	}
	if(destruidos[4]==true){
		if(x+122<150){
			gotoxy(x+122,2);
			cout<<ene;
		}
	}
	if(destruidos[5]==true){
		if(x+150<155){
			gotoxy(x+150,2);
			cout<<ene;
		}
	}
	//Segunda fila
	if(destruidos[6]==true){
		if(x+17<150){
			gotoxy(x+17,4);
			cout<<ene;
		}
	}
	if(destruidos[7]==true){
		if(x+31<150){
			gotoxy(x+31,4);
			cout<<ene;
		}
	}
	if(destruidos[8]==true){
		if(x+45<150){
			gotoxy(x+45,4);
			cout<<ene;
		}
	}
	if(destruidos[9]==true){
		if(x+59<150){
			gotoxy(x+59,4);
			cout<<ene;
		}
	}
	if(destruidos[10]==true){
		if(x+73<150){
			gotoxy(x+73,4);
			cout<<ene;
		}
	}
	if(destruidos[11]==true){
		if(x+87<150){
			gotoxy(x+87,4);
			cout<<ene;
		}
	}
	if(destruidos[12]==true){
		if(x+101<150){
			gotoxy(x+101,4);
			cout<<ene;
		}
	}
	if(destruidos[13]==true){
		if(x+115<150){
			gotoxy(x+115,4);
			cout<<ene;
		}
	}
	if(destruidos[14]==true){
		if(x+129<150){
			gotoxy(x+129,4);
			cout<<ene;
		}
	}
	if(destruidos[15]==true){
		if(x+144<150){
			gotoxy(x+144,4);
			cout<<ene;
		} 
	}
 	//Tercera fila
	if(destruidos[16]==true){
		if(x+24<150){
			gotoxy(x+24,6);
			cout<<ene;
		}
	}
	if(destruidos[17]==true){
		if(x+52<150){
			gotoxy(x+52,6);
			cout<<ene;
		}
	}
	if(destruidos[18]==true){
		if(x+80<150){
			gotoxy(x+80,6);
			cout<<ene;
		}
	}
	if(destruidos[19]==true){
		if(x+108<150){
			gotoxy(x+108,6);
			cout<<ene;
		}
	}
	if(destruidos[20]==true){
		if(x+136<150){
			gotoxy(x+136,6);
			cout<<ene;
		}
	}
	color(9);
 }
//Enemigos Lvl.2
void enemigos2(bool destruidos[10],int x,int y,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10){
	color(14);
	char ene=220;
	if(destruidos[0]==true){
		if(x+10<150){
			gotoxy(x+9,y);
			cout<<" ";
			gotoxy(x+10,y);
			cout<<ene;
			
		}
	}
	if(destruidos[1]==true){
		if(x2+10<150){
			if(x2+10>10){
				gotoxy(x2+10,y);
				cout<<ene;
				gotoxy(x2+9,y);
				cout<<" ";
			}
		}
	}	
	
	if(destruidos[2]==true){
		if(x3+10<150){
			if(x3+10>10){
				gotoxy(x3+10,y);
				cout<<ene;
				gotoxy(x3+9,y);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[3]==true){
		if(x4+10<150){
			if(x4+10>10){
				gotoxy(x4+10,y);
				cout<<ene;
				gotoxy(x4+9,y);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[4]==true){
		if(x5+10<150){
			if(x5+10>10){
				gotoxy(x5+10,y);
				cout<<ene;
				gotoxy(x5+9,y);
				cout<<" ";
			}
		}
	}
	if(destruidos[5]==true){
		if(x6+10<150){
			if(x6+10>10){
				gotoxy(x6+10,y);
				cout<<ene;
				gotoxy(x6+9,y);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[6]==true){
		if(x7+10<150){
			if(x7+10>10){
				gotoxy(x7+10,y);
				cout<<ene;
				gotoxy(x7+9,y);
				cout<<" ";
			}
		}
	}
	if(destruidos[7]==true){
		if(x8+10<150){
			if(x8+10>10){
				gotoxy(x8+10,y);
				cout<<ene;
				gotoxy(x8+9,y);
				cout<<" ";
			}
		}
	}
	if(destruidos[8]==true){
		if(x9+10<150){
			if(x9+10>10){
				gotoxy(x9+10,y);
				cout<<ene;
				gotoxy(x9+9,y);
				cout<<" ";
			}
		}
	}
	if(destruidos[9]==true){
		if(x10+10<150){
			if(x10+10>10){
				gotoxy(x10+10,y);
				cout<<ene;
				gotoxy(x10+9,y);
				cout<<" ";
			}
		}
	}
 	gotoxy(149,y);
	cout<<" ";
}
//Lvls
void Nivel2(int puntuacion){
	system("cls");
	color(3);
	gotoxy(80,37);
	cout<<puntuacion;
	color(9);
	int tiempo=0;
	bool destruidos[10]={true,true,true,true,true,true,true,true,true,true};
	//Jugador
	char nave=219,bala=221;
	int tecla,cont=0;
	int x=75,y=29;
	int y1=6;
	int x1=0,x2=-10,x3=-20,x4=-30,x5=-40,x6=-50,x7=-60,x8=-70,x9=-80,x10=-90;
	bool vuelta=true;
	int xBala,yBala;
	int n=0;
	gotoxy(x,y);
	cout<<nave;
	contador(tiempo);
	enemigos2(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10);
	bool run=true;
	while(run){
		color(9);
//			 vvvv   Modificar la velocidad del tiempo
		if(n%2000==0){tiempo++;contador(tiempo);gotoxy(33,30);cout<<tiempo;}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%180==0){
			x1++;
			x2++;
			x3++;
			x4++;
			x5++;
			x6++;
			x7++;
			x8++;
			x9++;
			x10++;
			enemigos2(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10);
		}
		if(x1+10>150){x1=0;}
		if(x2+10>150){x2=0;}
		if(x3+10>150){x3=0;}
		if(x4+10>150){x4=0;}
		if(x5+10>150){x5=0;}
		if(x6+10>150){x6=0;}
		if(x7+10>150){x7=0;}
		if(x8+10>150){x8=0;}
		if(x9+10>150){x9=0;}
		if(x10+10>150){x10=0;}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
            	case 27:
            		run=false;
            		
				//Derecha
            	case 77:
					if(x<159){
						gotoxy(x-1,y);
	            		cout<<" ";
						x++;
						
					}
        			gotoxy(x-1,y);
            		cout<<" ";

            		break;
            	//Izquierda
				case 75:
					if(x>0){
						gotoxy(x+1,y);
	            		cout<<" ";
						x--;
					}
					gotoxy(x+1,y);
	            	cout<<" ";
	            	
            		break;
            	//Espacio
            
				case 32:
					color(4);
			    	xBala=x,yBala=y;
			    	gotoxy(xBala,yBala-1);
					cout<<bala;
					//char soundfile[] = "LASRLIT3.wav";
			    	//PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC ); 
			    	for(int yBala=y-1;yBala>-2;--yBala){
						contador(tiempo);
						if(vuelta==true){
							vuelta=false;
							x1++;
							x2++;
							x3++;
							x4++;
							x5++;
							x6++;
							x7++;
							x8++;
							x9++;
							x10++;
						}else{
							vuelta=true;
						}
						enemigos2(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10);
					   	if(yBala==y1){
					   		if(xBala==x1+10 or xBala==x1+11){
					   			destruidos[0]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x2+10 or xBala==x2+11){
					   			destruidos[1]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x3+10 or xBala==x3+11){
					   			destruidos[2]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x4+10 or xBala==x4+11){
					   			destruidos[3]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x5+10 or xBala==x5+11){
					   			destruidos[4]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x6+10 or xBala==x6+11){
					   			destruidos[5]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x7+10 or xBala==x7+11){
					   			destruidos[6]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x8+10 or xBala==x8+11){
					   			destruidos[7]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x9+10 or xBala==x9+11){
					   			destruidos[8]=false;
					   			puntuacion+=50;
					   			break;
							}
						}
						if(yBala==y1){
					   		if(xBala==x10+10){
					   			destruidos[9]=false;
					   			puntuacion+=50;
							}
					   		break;
						}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
				            	case 27:
				            		run=false;
				            		
										//Derecha
						            	case 77:
											if(x<159){
												gotoxy(x-1,y);
							            		cout<<" ";
												x++;
												
											}
						        			gotoxy(x-1,y);
						            		cout<<" ";
						
						            		break;
						            	//Izquierda
										case 75:
											if(x>0){
												gotoxy(x+1,y);
							            		cout<<" ";
												x--;
											}
											gotoxy(x+1,y);
							            	cout<<" ";
							            	
						            		break;
						   	}
						}     
						color(4);
						gotoxy(xBala,yBala);
						cout<<bala;
						color(9);
						gotoxy(x,y);
						cout<<nave;
					}
					system("cls");
					contador(tiempo);

					color(7);
					gotoxy(80,37);
					cout<<puntuacion;
            		break;
    		}
    	}
    	gotoxy(x,y);
		cout<<nave;
		n++;
		color(7);
		gotoxy(80,37);
		cout<<puntuacion;
		//Si destruye los 21 objetivos
		if(cont==10){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			getch();
			system("cls");
			Nivel2(puntuacion);
		}
		if (tiempo==92){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Fin del juego";
		}
	}
}
void Nivel1(int puntuacion){
	system("cls");
	color(3);
	gotoxy(80,37);
	cout<<puntuacion;
	color(9);
	int tiempo=0,polvl1=0;
	                     /*                               FILAS                                        */
	                     /*1*/                                   /*2*/                              /*3*/
	bool destruidos[21]={true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
	//Jugador
	char nave=219,bala=221;
	int tecla,cont=0;
	int x=75,y=29;
	int x1=0;
	int xBala,yBala;
	gotoxy(x,y);
	cout<<nave;
	//
	int n=0;
	contador(tiempo);
	bool run=true;
	while(run){
		color(9);
//			 vvvv   Modificar la velocidad de los enemigos
		if(n%2000==0){tiempo++;contador(tiempo);}
		//if(n%500==0){x1++;system("cls");enemigos(destruidos,x1);}
		if(n==0){enemigos(destruidos,x1);}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
	        	case 27:
            		system("pause");
            		run=false;
            		Nivel2(puntuacion);            		
            	//Derecha
            	case 77:
					if(x<159){
						gotoxy(x-1,y);
	            		cout<<" ";
						x++;
						
					}
        			gotoxy(x-1,y);
            		cout<<" ";
            		enemigos(destruidos,x1);
            		break;
            	//Izquierda
				case 75:
					if(x>0){
						gotoxy(x+1,y);
	            		cout<<" ";
						x--;
					}
					gotoxy(x+1,y);
	            	cout<<" ";
					enemigos(destruidos,x1);
            		break;
            	//Espacio
            
				case 32:
					color(4);
			    	xBala=x,yBala=y;
			    	gotoxy(xBala,yBala-1);
					cout<<bala;
					//char soundfile[] = "LASRLIT3.wav";
			    	//PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC ); 
			    	for(int yBala=y-1;yBala>-2;--yBala){
						contador(tiempo);
						gotoxy(xBala,yBala+1);
						cout<<" ";
						color(4);
						gotoxy(xBala,yBala);
						cout<<bala;
//Validaciones
						//Fila 1
						if(yBala==2){
							if(xBala==x1+10){
								destruidos[0]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+38){
								destruidos[1]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+66){
								destruidos[2]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+94){
								destruidos[3]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+122){
								destruidos[4]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+150){
								destruidos[5]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
						}
						//Fila 2
						if(yBala==4){
							if(xBala==x1+17){
								destruidos[6]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+31){
								destruidos[7]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+45){
								destruidos[8]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+59){
								destruidos[9]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+73){
								destruidos[10]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+87){
								destruidos[11]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+101){
								destruidos[12]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+115){
								destruidos[13]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+129){
								destruidos[14]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+144){
								destruidos[15]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
						}
						//Fila 3
						if(yBala==6){
							if(xBala==x1+24){
								destruidos[16]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+52){
								destruidos[17]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+80){
								destruidos[18]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+108){
								destruidos[19]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
							if(xBala==x1+136){
								destruidos[20]=false;
								enemigos(destruidos,x1);
								cont++;
								puntuacion+=20;
								break;
							}
						}
//de colociones
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
				            	case 27:
				            		run=false;
				            		
										//Derecha
						            	case 77:
											if(x<159){
												gotoxy(x-1,y);
							            		cout<<" ";
												x++;
												
											}
						        			gotoxy(x-1,y);
						            		cout<<" ";
						
						            		break;
						            	//Izquierda
										case 75:
											if(x>0){
												gotoxy(x+1,y);
							            		cout<<" ";
												x--;
											}
											gotoxy(x+1,y);
							            	cout<<" ";
							            	
						            		break;
						   	}
						}
						enemigos(destruidos,x1);
						cout<<bala;
						gotoxy(x,y);
						cout<<nave;
					}
					system("cls");
					contador(tiempo);
					enemigos(destruidos,x1);
					color(7);
					gotoxy(80,37);
					cout<<puntuacion;
            		break;
    		}
    	}
    	gotoxy(x,y);
		cout<<nave;
		n++;
		color(7);
		gotoxy(80,37);
		cout<<puntuacion;
		//Si destruye los 21 objetivos
		if(cont==21){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel2(puntuacion);
		}
		//Se acaba el tiempo
		if (tiempo==91){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Fin del juego";
		}
	}
	
}
int main(){
	
	AjustarVentana(160,40);  // Para otras de menor resolución
	int tecla,op=0,arrabj=0;
	int puntuacion=0;
	int x=45,y=19;
	int x1=44,y1=19;
	bool run=true,run2=true;
	char flechita='>';
    char menu[] = "Sonidos/menu.wav";
    char enter[] = "Sonidos/shineselect.wav";
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
			
			Nivel1(puntuacion);
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
            		//PlaySound((LPCSTR)menu, NULL, SND_FILENAME | SND_ASYNC ); 
					if(y1>19){
	            		y1=y1-7;
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
            		//PlaySound((LPCSTR)menu, NULL, SND_FILENAME | SND_ASYNC ); 
					if(y1<33){
						y1=y1+7;
						op++;
					}
					arrabj=1;
            		break;
            	//Enter
				case 13:
					//PlaySound((LPCSTR)enter, NULL, SND_FILENAME | SND_ASYNC ); 
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
					if(y1==26){
						if(pantalla==0){
							pantalla=1;
							run=false;
						}else if(pantalla==1){
							pantalla=2;
							run=false;
						}	
							
					}
					if(y1==33){
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
				gotoxy(x1,y1-7);
				cout<<" ";
				
			}else{
				gotoxy(x1,y1+7);
				cout<<" ";
			}
        }
	}while(run);
	
	}while(run2);
	return 0;
}
/*
	0 = Black
	1 = Blue
	2 = Green
	3 = Aqua
	4 = Red
	5 = Purple
	6 = Yellow
	7 = White
	8 = Gray
	9 = Light Blue
	10 = Light Green
	11 = Light Aqua
	12 = Light Red
	13 = Light Purple
	14 = Light Yellow
	15 = Bright White
*/
