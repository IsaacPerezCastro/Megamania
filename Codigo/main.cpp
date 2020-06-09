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
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsola, Coordenada);
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
	//color(7);	
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
void MovimientoInst(bool ins){
 	int xizq=54,xder=100,ybala=28,tecla,n=0;
 	int aux1=54,aux2=100,aux3=28,contador=0,cont2=0;
 	char nave=219;
 	char bala=250;
 	tecla = 0;
 	while(ins==true){
		if(n==100000000){
		gotoxy(xizq+1,29);
		cout<<" ";
		gotoxy(xizq-5,29);
		cout<<"     ";
		gotoxy(xizq,29);
		cout<<nave;
		gotoxy(xder-1,29);
		cout<<" ";
		gotoxy(xder+1,29);
		cout<<"     ";
		gotoxy(xder,29);
		cout<<nave;
		if(ybala<28){
		gotoxy(76,ybala+1);
		cout<<" ";
		gotoxy(76,ybala-1);
		cout<<" ";
		cout<<" ";
		gotoxy(76,ybala);
		cout<<bala;	
		}else{
		gotoxy(76,ybala);
		cout<<bala;
		gotoxy(76,ybala-4);
		cout<<" ";	
		}
		xizq--;
		xder++;
		ybala--;
		contador++;
		
		if(contador==5){
			
			xizq=aux1;
			xder=aux2;
			ybala=aux3;
			contador=0;
			cont2++;
		}		
		
		n=0;
		}
		n++;
		
	if(cont2==5){
		ins=false;
	}
	}
 }
void Instrucciones(int x1,int y1,char flechita){
 	int xizq=54,xder=100,ybala=28,tecla,n=0;
 	int aux1=54,aux2=100,aux3=28,contador=0;
 	char nave=219;
 	char bala=250;
 	bool ins=true;
 	system("cls");
	Marco();
	Letras();
	system("color 05");
	y1=19,x1=44;
	gotoxy(48,14);
 	cout<<"  __            _                       _                       ";
 	gotoxy(48,15);
 	cout<<" |_ _|_ __  ___| |_ _ __ _   _  ___ ___(_) ___  _ __   ___  ___ ";
 	gotoxy(48,16);
 	cout<<"  | || '_  / __| __| '__| | | |/ __/ __| |/ _  | '_  /  _  |  __|";
 	gotoxy(48,17);
 	cout<<"  | || | |  __ | |_| |  | |_| | (_| (__| | (_) | | | |  __/ __    " ;
 	gotoxy(48,18);
 	cout<<" |___|_| |_|___/ __|_|    __,_| ___ ___|_| ___/|_| |_| ___||___/";
	gotoxy(49,21);
	cout<<"  Flecha                Espacio                  Flecha";
	gotoxy(49,22);
	cout<<"    <--                   ---                      -->";
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
 	y1=34,x1=44;
	gotoxy(x1,y1);
	cout<<flechita;
	gotoxy(76,29);
	cout<<nave;
	MovimientoInst(ins);
} 
void Creditos(int x1,int y1,char flechita){
 	system("cls");
	Marco();
	Letras();
	system("color 02");
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
	gotoxy(45,28);
	gotoxy(x1,y1);
	cout<<flechita;
 }
//Suma de puntaje
int sumaPuntos(int puntaje,int tiempo){
	int total;
	total = puntaje + ((90-tiempo)*2);
	return total;
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
	color(14);
	gotoxy(19,34);
	cout<<"Energia";
	for(int x=30+tiempo;x<=120;++x){
		color(6);
		gotoxy(x,34);
		cout<<k[z];
		z++;
	}
}
//Vidas
void vidas(int vidas){
	char nave=219;
	color(14);
	gotoxy(30,37);
	cout<<"Vidas";
	if(vidas >= 1){
		if(vidas>=2){
			if(vidas>=3){
				color(4);
				gotoxy(40,37);
				cout<<nave<<"    "<<nave<<"    "<<nave;
			}
			color(4);
			gotoxy(40,37);
			cout<<nave<<"    "<<nave;
		}
		color(4);
		gotoxy(40,37);
		cout<<nave;		
	}
}
//Enemigos(Lvl)
void enemigos(bool destruidos[21], int x){
 	color(5);
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
void enemigos3(bool destruidos[10],int x,int y,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10,int y2,int y3,int y4,int y5,int y6,int y7,int y8,int y9,int y10){
	color(10);
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
				gotoxy(x2+9,y2);
				cout<<" ";
				gotoxy(x2+10,y2);
				cout<<ene;
				
			}
		}
	}	
	
	if(destruidos[2]==true){
		if(x3+10<150){
			if(x3+10>10){
				gotoxy(x3+9,y3);
				cout<<" ";
				gotoxy(x3+10,y3);
				cout<<ene;
			
			}
		}
	}
	if(destruidos[3]==true){
		if(x4+10<150){
			if(x4+10>10){
				gotoxy(x4+9,y4);
				cout<<" ";
				gotoxy(x4+10,y4);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[4]==true){
		if(x5+10<150){
			if(x5+10>10){
				gotoxy(x5+9,y5);
				cout<<" ";
				gotoxy(x5+10,y5);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[5]==true){
		if(x6+10<150){
			if(x6+10>10){
				gotoxy(x6+9,y6);
				cout<<" ";
				gotoxy(x6+10,y6);
				cout<<ene;
			}
		}
	}
	if(destruidos[6]==true){
		if(x7+10<150){
			if(x7+10>10){
				gotoxy(x7+9,y7);
				cout<<" ";
				gotoxy(x7+10,y7);
				cout<<ene;
			}
		}
	}
	if(destruidos[7]==true){
		if(x8+10<150){
			if(x8+10>10){
				gotoxy(x8+9,y8);
				cout<<" ";
				gotoxy(x8+10,y8);
				cout<<ene;
			}
		}
	}
	if(destruidos[8]==true){
		if(x9+10<150){
			if(x9+10>10){
				gotoxy(x9+9,y9);
				cout<<" ";
				gotoxy(x9+10,y9);
				cout<<ene;
			}
		}
	}
	if(destruidos[9]==true){
		if(x10+10<150){
			if(x10+10>10){
				gotoxy(x10+9,y10);
				cout<<" ";
				gotoxy(x10+10,y10);
				cout<<ene;
			}
		}
	}
 	gotoxy(149,y10);
	cout<<" ";
}
void enemigos4(bool destruidos[20],int x,int y,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10,int x11,int x12,int x13,int x14){
	color(13);
	char ene=220;
	int fila1=6,fila2=9,fila3=12;
	if(destruidos[0]==true){
		if(x+10<150){
			gotoxy(x+9,fila1);
			cout<<" ";
			gotoxy(x+10,fila1);
			cout<<ene;
			
		}
	}
	if(destruidos[1]==true){
		if(x2+10<150){
			if(x2+10>10){
				gotoxy(x2+10,fila2);
				cout<<ene;
				gotoxy(x2+9,fila2);
				cout<<" ";
			}
		}
	}	
	
	if(destruidos[2]==true){
		if(x3+10<150){
			if(x3+10>10){
				gotoxy(x3+10,fila1);
				cout<<ene;
				gotoxy(x3+9,fila1);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[3]==true){
		if(x4+10<150){
			if(x4+10>10){
				gotoxy(x4+10,fila2);
				cout<<ene;
				gotoxy(x4+9,fila2);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[4]==true){
		if(x5+10<150){
			if(x5+10>10){
				gotoxy(x5+10,fila1);
				cout<<ene;
				gotoxy(x5+9,fila1);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[5]==true){
		if(x6+10<150){
			if(x6+10>10){
				gotoxy(x6+10,fila2);
				cout<<ene;
				gotoxy(x6+9,fila2);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[6]==true){
		if(x7+10<150){
			if(x7+10>10){
				gotoxy(x7+10,fila1);
				cout<<ene;
				gotoxy(x7+9,fila1);
				cout<<" ";
			}
		}
	}
	if(destruidos[7]==true){
		if(x8+10<150){
			if(x8+10>10){
				gotoxy(x8+10,fila2);
				cout<<ene;
				gotoxy(x8+9,fila2);
				cout<<" ";
			}
		}
	}
	if(destruidos[8]==true){
		if(x9+10<150){
			if(x9+10>10){
				gotoxy(x9+10,fila1);
				cout<<ene;
				gotoxy(x9+9,fila1);
				cout<<" ";
			}
		}
	}
	if(destruidos[9]==true){
		if(x10+10<150){
			if(x10+10>10){
				gotoxy(x10+10,fila2);
				cout<<ene;
				gotoxy(x10+9,fila2);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[10]==true){
		if(x11+10<150){
			gotoxy(x11+9,fila1);
			cout<<" ";
			gotoxy(x11+10,fila1);
			cout<<ene;
			
		}
	}
	if(destruidos[11]==true){
		if(x12+10<150){
			if(x12+10>10){
				gotoxy(x12+10,fila2);
				cout<<ene;
				gotoxy(x12+9,fila2);
				cout<<" ";
			}
		}
	}	
	
	if(destruidos[12]==true){
		if(x13+10<150){
			if(x13+10>10){
				gotoxy(x13+10,fila1);
				cout<<ene;
				gotoxy(x13+9,fila1);
				cout<<" ";
			}
		}
	}
	
	if(destruidos[13]==true){
		if(x14+10<150){
			if(x14+10>10){
				gotoxy(x14+10,fila2);
				cout<<ene;
				gotoxy(x14+9,fila2);
				cout<<" ";
			}
		}
	}
 	gotoxy(149,fila1);
	cout<<" ";
	gotoxy(149,fila2);
	cout<<" ";
}
void enemigos5(bool destruidos[10],int x,int y,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10,int y2,int y3,int y4,int y5,int y6,int y7,int y8,int y9,int y10){
	color(10);
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
				gotoxy(x2+9,y2);
				cout<<" ";
				gotoxy(x2+10,y2);
				cout<<ene;
				
			}
		}
	}	
	
	if(destruidos[2]==true){
		if(x3+10<150){
			if(x3+10>10){
				gotoxy(x3+9,y3);
				cout<<" ";
				gotoxy(x3+10,y3);
				cout<<ene;
			
			}
		}
	}
	
	if(destruidos[3]==true){
		if(x4+10<150){
			if(x4+10>10){
				gotoxy(x4+9,y4);
				cout<<" ";
				gotoxy(x4+10,y4);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[4]==true){
		if(x5+10<150){
			if(x5+10>10){
				gotoxy(x5+9,y5);
				cout<<" ";
				gotoxy(x5+10,y5);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[5]==true){
		if(x6+10<150){
			if(x6+10>10){
				gotoxy(x6+9,y6);
				cout<<" ";
				gotoxy(x6+10,y6);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[6]==true){
		if(x7+10<150){
			if(x7+10>10){
				gotoxy(x7+9,y7);
				cout<<" ";
				gotoxy(x7+10,y7);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[7]==true){
		if(x8+10<150){
			if(x8+10>10){
				gotoxy(x8+9,y8);
				cout<<" ";
				gotoxy(x8+10,y8);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[8]==true){
		if(x9+10<150){
			if(x9+10>10){
				gotoxy(x9+9,y9);
				cout<<" ";
				gotoxy(x9+10,y9);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[9]==true){
		if(x10+10<150){
			if(x10+10>10){
				gotoxy(x10+9,y10);
				cout<<" ";
				gotoxy(x10+10,y10);
				cout<<ene;
			
			}
		}
	}
	
 	gotoxy(149,y10);
	cout<<" ";
}
void enemigos6(bool destruidos[10],int x,int y,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10,int y2,int y3,int y4,int y5,int y6,int y7,int y8,int y9,int y10){
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
				gotoxy(x2+9,y2);
				cout<<" ";
				gotoxy(x2+10,y2);
				cout<<ene;
				
			}
		}
	}	
	
	if(destruidos[2]==true){
		if(x3+10<150){
			if(x3+10>10){
				gotoxy(x3+9,y3);
				cout<<" ";
				gotoxy(x3+10,y3);
				cout<<ene;
			
			}
		}
	}
	
	if(destruidos[3]==true){
		if(x4+10<150){
			if(x4+10>10){
				gotoxy(x4+9,y4);
				cout<<" ";
				gotoxy(x4+10,y4);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[4]==true){
		if(x5+10<150){
			if(x5+10>10){
				gotoxy(x5+9,y5);
				cout<<" ";
				gotoxy(x5+10,y5);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[5]==true){
		if(x6+10<150){
			if(x6+10>10){
				gotoxy(x6+9,y6);
				cout<<" ";
				gotoxy(x6+10,y6);
				cout<<ene;
				
			}
		}
	}
	
	if(destruidos[6]==true){
		if(x7+10<150){
			if(x7+10>10){
				gotoxy(x7+9,y7);
				cout<<" ";
				gotoxy(x7+10,y7);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[7]==true){
		if(x8+10<150){
			if(x8+10>10){
				gotoxy(x8+9,y8);
				cout<<" ";
				gotoxy(x8+10,y8);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[8]==true){
		if(x9+10<150){
			if(x9+10>10){
				gotoxy(x9+9,y9);
				cout<<" ";
				gotoxy(x9+10,y9);
				cout<<ene;
				
			}
		}
	}
	if(destruidos[9]==true){
		if(x10+10<150){
			if(x10+10>10){
				gotoxy(x10+9,y10);
				cout<<" ";
				gotoxy(x10+10,y10);
				cout<<ene;
			
			}
		}
	}
	
 	gotoxy(149,y);
	cout<<" ";
	gotoxy(149,y2);
	cout<<" ";
	gotoxy(149,y3);
	cout<<" ";
	gotoxy(149,y4);
	cout<<" ";
	gotoxy(149,y5);
	cout<<" ";
	gotoxy(149,y6);
	cout<<" ";
	gotoxy(149,y7);
	cout<<" ";
	gotoxy(149,y8);
	cout<<" ";
	gotoxy(149,y9);
	cout<<" ";
	gotoxy(149,y10);
	cout<<" ";
}
//Lvls
void Nivel6(int puntuacion, int vidasNave){
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
	int x1=0,x2=-10,x3=-20,x4=-30,x5=-40,x6=-50,x7=-60,x8=-70,x9=-80,x10=-90;
	int y1=6,y2=9,y3=6,y4=9,y5=6,y6=9,y7=6,y8=9,y9=6,y10=9;
	bool vuelta=true;
	int xBala,yBala;
	int n=0;
	gotoxy(x,y);
	cout<<nave;
	contador(tiempo);
	enemigos6(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
	bool run=true;
	vidas(vidasNave);
	while(run){
		color(9);
		//Coaliciones con nave
		if(destruidos[0]==true){
			if(x1+10==x and y==y1){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[1]==true){
			if(x2+10==x and y==y2){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
					
			}
		}
		if(destruidos[2]==true){
			if(x3+10==x and y==y3){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[3]==true){
			if(x4+10==x and y==y4){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[4]==true){
			if(x5+10==x and y==y5){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[5]==true){
			if(x6+10==x and y==y6){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[6]==true){
			if(x7+10==x and y==y7){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[7]==true){
			if(x8+10==x and y==y8){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[8]==true){
			if(x9+10==x and y==y9){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}
		}
		if(destruidos[9]==true){
			if(x10+10==x and y==y10){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel6(puntuacion,vidasNave);
			}	
		}
//			 vvvv   Modificar la velocidad del tiempo
		if(n%1500==0){tiempo++;contador(tiempo);}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%100==0){
			x1++;	x6++;
			x2++;	x7++;
			x3++;	x8++;
			x4++;	x9++;
			x5++;	x10++;
			enemigos6(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
		}
		if(x1+10>150){x1=0;y1+=5;}
		if(x2+10>150){x2=0;y2+=5;}
		if(x3+10>150){x3=0;y3+=5;}
		if(x4+10>150){x4=0;y4+=5;}
		if(x5+10>150){x5=0;y5+=5;}
		if(x6+10>150){x6=0;y6+=5;}
		if(x7+10>150){x7=0;y7+=5;}
		if(x8+10>150){x8=0;y8+=5;}
		if(x9+10>150){x9=0;y9+=5;}
		if(x10+10>150){x10=0;y10+=5;}
		if(y1>y){y1=y;}
		if(y3>y){y3=y;}
		if(y5>y){y5=y;}
		if(y7>y){y7=y;}
		if(y8>y){y9=y;}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
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
						if(destruidos[0]==true){
						   	if(yBala==y1){
						   		if(xBala==x1+10 or xBala==x1+11){
						   			destruidos[0]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[1]==true){
							if(yBala==y2){
						   		if(xBala==x2+10 or xBala==x2+11){
						   			destruidos[1]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[2]==true){
							if(yBala==y3){
						   		if(xBala==x3+10 or xBala==x3+11){
						   			destruidos[2]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[3]==true){
							if(yBala==y4){
						   		if(xBala==x4+10 or xBala==x4+11){
						   			destruidos[3]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[4]==true){
							if(yBala==y5){
						   		if(xBala==x5+10 or xBala==x5+11){
						   			destruidos[4]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[5]==true){
							if(yBala==y6){
						   		if(xBala==x6+10 or xBala==x6+11){
						   			destruidos[5]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[6]==true){
							if(yBala==y7){
						   		if(xBala==x7+10 or xBala==x7+11){
						   			destruidos[6]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[7]==true){
							if(yBala==y8){
						   		if(xBala==x8+10 or xBala==x8+11){
						   			destruidos[7]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[8]==true){
							if(yBala==y9){
						   		if(xBala==x9+10 or xBala==x9+11){
						   			destruidos[8]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(destruidos[9]==true){
							if(yBala==y10){
						   		if(xBala==x10+10 or xBala==x10+11){
						   			destruidos[9]=false;
						   			puntuacion+=50;
						   			break;
								}
							}
						}
						if(vuelta==true){
							x1++;	x6++;
							x2++;	x7++;
							x3++;	x8++;
							x4++;	x9++;
							x5++;	x10++;
							enemigos6(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
							vuelta=false;
						}else{vuelta=true;}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit()){
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
					vidas(vidasNave);
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
		//Si destruye los 10 objetivos
		if(cont==10){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel6(puntuacion,vidasNave);
		}
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel6(puntuacion,vidasNave);
		}
	}
}
void Nivel5(int puntuacion, int vidasNave){
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
	int x1=0,x2=-10,x3=-20,x4=-30,x5=-40,x6=-50,x7=-60,x8=-70,x9=-80,x10=-90;
	int y1=4,y2=4,y3=4,y4=4,y5=4,y6=4,y7=4,y8=4,y9=4,y10=4;
	bool vuelta=true;
	int xBala,yBala;
	int n=0;
	gotoxy(x,y);
	cout<<nave;
	contador(tiempo);
	enemigos5(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
	bool run=true;
	vidas(vidasNave);
	while(run){
		color(9);
		//Coaliciones con nave
		if(destruidos[0]==true){
			if(x1+10==x and y==y1){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[1]==true){
			if(x2+10==x and y==y2){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);	
			}
		}
		if(destruidos[2]==true){
			if(x3+10==x and y==y3){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[3]==true){
			if(x4+10==x and y==y4){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[4]==true){
			if(x5+10==x and y==y5){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[5]==true){
			if(x6+10==x and y==y6){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[6]==true){
			if(x7+10==x and y==y7){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[7]==true){
			if(x8+10==x and y==y8){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[8]==true){
			if(x9+10==x and y==y9){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}
		}
		if(destruidos[9]==true){
			if(x10+10==x and y==y10){
				system("cls");
				vidasNave-=1;
				vidas(vidasNave);
				Sleep(1000);
				Nivel5(puntuacion,vidasNave);
			}	
		}
//			 vvvv   Modificar la velocidad del tiempo
		if(n%1200==0){tiempo++;contador(tiempo);}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%100==0){
			x1++;	x6++;
			x2++;	x7++;
			x3++;	x8++;
			x4++;	x9++;
			x5++;	x10++;
			enemigos5(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
		}
		if(x1+10>150){x1=0;y1+=5;}
		if(x2+10>150){x2=0;y2+=5;}
		if(x3+10>150){x3=0;y3+=5;}
		if(x4+10>150){x4=0;y4+=5;}
		if(x5+10>150){x5=0;y5+=5;}
		if(x6+10>150){x6=0;y6+=5;}
		if(x7+10>150){x7=0;y7+=5;}
		if(x8+10>150){x8=0;y8+=5;}
		if(x9+10>150){x9=0;y9+=5;}
		if(x10+10>150){x10=0;y10+=5;}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
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
						if(destruidos[0]==true){
							if(yBala==y1){
						   		if(xBala==x1+10 or xBala==x1+11){
						   			destruidos[0]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[1]==true){
							if(yBala==y2){
						   		if(xBala==x2+10 or xBala==x2+11){
						   			destruidos[1]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[2]==true){
							if(yBala==y3){
						   		if(xBala==x3+10 or xBala==x3+11){
						   			destruidos[2]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[3]==true){
							if(yBala==y4){
						   		if(xBala==x4+10 or xBala==x4+11){
						   			destruidos[3]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[4]==true){
							if(yBala==y5){
						   		if(xBala==x5+10 or xBala==x5+11){
						   			destruidos[4]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[5]==true){
							if(yBala==y6){
						   		if(xBala==x6+10 or xBala==x6+11){
						   			destruidos[5]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[6]==true){
							if(yBala==y7){
						   		if(xBala==x7+10 or xBala==x7+11){
						   			destruidos[6]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[7]==true){
							if(yBala==y8){
						   		if(xBala==x8+10 or xBala==x8+11){
						   			destruidos[7]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[8]==true){
							if(yBala==y9){
						   		if(xBala==x9+10 or xBala==x9+11){
						   			destruidos[8]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[9]==true){
							if(yBala==y10){
						   		if(xBala==x10+10 or xBala==x10+11){
						   			destruidos[9]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(vuelta==true){
							vuelta=false;
							x1++;	x6++;
							x2++;	x7++;
							x3++;	x8++;
							x4++;	x9++;
							x5++;	x10++;
							enemigos5(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
						}else{
							vuelta=true;
						}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
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
					vidas(vidasNave);
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
		//Si destruye los 10 objetivos
		if(cont==10){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel6(puntuacion,vidasNave);
		}
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel5(puntuacion,vidasNave);
		}
	}
}
void Nivel4(int puntuacion, int vidasNave){
	system("cls");
	color(3);
	gotoxy(80,37);
	cout<<puntuacion;
	color(9);
	int tiempo=0;
	bool destruidos[14]={true,true,true,true,true,true,true,true,true,true,true,true,true,true};
	//Jugador
	char nave=219,bala=221;
	int tecla,cont=0;
	int x=75,y=29;
	int y1=6;
	int y2=9;
	int x1=0,x2=-10,x3=-20,x4=-30,x5=-40,x6=-50,x7=-60,x8=-70,x9=-80,x10=-90,x11=-100,x12=-110,x13=-120,x14=-130,x15=-140,x16=-150,x17=-160,x18=-170,x19=-180,x20=-190,x21=-200;
	bool vuelta=true;
	int xBala,yBala;
	int n=0;
	gotoxy(x,y);
	cout<<nave;
	contador(tiempo);
	enemigos4(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,x11,x12,x13,x14);
	bool run=true;
	while(run){
		color(9);
//			 vvvv   Modificar la velocidad del tiempo
		if(n%2000==0){tiempo++;contador(tiempo);}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%170==0){
			x1++;	x8++;
			x2++;	x9++;
			x3++;	x10++;
			x4++;	x11++;
			x5++;	x12++;
			x6++; 	x13++;
			x7++;	x14++;
			enemigos4(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,x11,x12,x13,x14);
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
		if(x11+10>150){x11=0;}
		if(x12+10>150){x12=0;}
		if(x13+10>150){x13=0;}
		if(x14+10>150){x14=0;}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
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
						if(destruidos[0]==true){
						   	if(yBala==y1){
						   		if(xBala==x1+10 or xBala==x1+11){
						   			destruidos[0]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[1]==true){
							if(yBala==y2){
						   		if(xBala==x2+10 or xBala==x2+11){
						   			destruidos[1]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[2]==true){
							if(yBala==y1){
						   		if(xBala==x3+10 or xBala==x3+11){
						   			destruidos[2]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[3]==true){
							if(yBala==y2){
						   		if(xBala==x4+10 or xBala==x4+11){
						   			destruidos[3]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[4]==true){
							if(yBala==y1){
						   		if(xBala==x5+10 or xBala==x5+11){
						   			destruidos[4]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[5]==true){
							if(yBala==y2){
						   		if(xBala==x6+10 or xBala==x6+11){
						   			destruidos[5]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[6]==true){
							if(yBala==y1){
						   		if(xBala==x7+10 or xBala==x7+11){
						   			destruidos[6]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[7]==true){
							if(yBala==y2){
						   		if(xBala==x8+10 or xBala==x8+11){
						   			destruidos[7]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[8]==true){
							if(yBala==y1){
						   		if(xBala==x9+10 or xBala==x9+11){
						   			destruidos[8]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[9]==true){
							if(yBala==y2){
						   		if(xBala==x10+10 or xBala==x10+11){
						   			destruidos[9]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[10]==true){
							if(yBala==y1){
						   		if(xBala==x11+10 or xBala==x11+11){
						   			destruidos[10]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[11]==true){
							if(yBala==y2){
						   		if(xBala==x12+10 or xBala==x12+11){
						   			destruidos[11]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[12]==true){
							if(yBala==y1){
						   		if(xBala==x13+10 or xBala==x13+11){
						   			destruidos[12]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}
						if(destruidos[13]==true){
							if(yBala==y2){
						   		if(xBala==x14+10 or xBala==x14+11){
						   			destruidos[13]=false;
						   			puntuacion+=50;
						   			cont++;
									break;
								}
							}
						}						
						if(vuelta==true){
							x1++;	x8++;
							x2++;	x9++;
							x3++;	x10++;
							x4++;	x11++;
							x5++;	x12++;
							x6++; 	x13++;
							x7++;	x14++;
							vuelta=false;
							enemigos4(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,x11,x12,x13,x14);
						}else{
							vuelta=true;
						}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
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
		//Si destruye los 14 objetivos
		if(cont==14){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel5(puntuacion,vidasNave);
		}
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel4(puntuacion,vidasNave);
		}
	}
}
void Nivel3(int puntuacion, int vidasNave){
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
	int x1=0,x2=-10,x3=-20,x4=-30,x5=-40,x6=-50,x7=-60,x8=-70,x9=-80,x10=-90;
	int y1=4,y2=4,y3=4,y4=4,y5=4,y6=4,y7=4,y8=4,y9=4,y10=4;
	bool vuelta=true;
	int xBala,yBala;
	int n=0;
	gotoxy(x,y);
	cout<<nave;
	contador(tiempo);
	enemigos3(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
	bool run=true;
	vidas(vidasNave);
	while(run){
		color(9);
		//Coliciones con nave
		if(destruidos[0]==true){
			if(x1+10==x and y==y1){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[1]==true){
			if(x2+10==x and y==y2){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[2]==true){
			if(x3+10==x and y==y3){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[3]==true){
			if(x4+10==x and y==y4){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);			
				}
			}
		if(destruidos[4]==true){
			if(x5+10==x and y==y5){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[5]==true){
			if(x6+10==x and y==y6){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[6]==true){
			if(x7+10==x and y==y7){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[7]==true){
			if(x8+10==x and y==y8){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[8]==true){
			if(x9+10==x and y==y9){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
		if(destruidos[9]==true){
			if(x10+10==x and y==y10){
					vidasNave-=1;
					vidas(vidasNave);
					Sleep(1000);
					Nivel3(puntuacion,vidasNave);
				}
			}
//			 vvvv   Modificar la velocidad del tiempo
		if(n%2000==0){tiempo++;contador(tiempo);}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%150==0){
			x1++;	x6++;
			x2++;	x7++;
			x3++;	x8++;
			x4++;	x9++;
			x5++;	x10++;
			enemigos3(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
		}
		if(x1+10>150){x1=0;y1+=5;}
		if(x2+10>150){x2=0;y2+=5;}
		if(x3+10>150){x3=0;y3+=5;}
		if(x4+10>150){x4=0;y4+=5;}
		if(x5+10>150){x5=0;y5+=5;}
		if(x6+10>150){x6=0;y6+=5;}
		if(x7+10>150){x7=0;y7+=5;}
		if(x8+10>150){x8=0;y8+=5;}
		if(x9+10>150){x9=0;y9+=5;}
		if(x10+10>150){x10=0;y10+=5;}
		if (_kbhit())
        {
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
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
					   	if(destruidos[0]==true){
						   if(yBala==y1){
					   		if(xBala==x1+10 or xBala==x1+11){
					   			destruidos[0]=false;
					   			puntuacion+=50;
					   			cont++;
					   			break;
							}
						   }
						}if(destruidos[1]==true){
							if(yBala==y2){
					   			if(xBala==x2+10 or xBala==x2+11){
						   			destruidos[1]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[2]==true){
							if(yBala==y3){
						   		if(xBala==x3+10 or xBala==x3+11){
						   			destruidos[2]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[3]==true){
							if(yBala==y4){
						   		if(xBala==x4+10 or xBala==x4+11){
						   			destruidos[3]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[4]==true){
							if(yBala==y5){
						   		if(xBala==x5+10 or xBala==x5+11){
						   			destruidos[4]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[5]==true){
							if(yBala==y6){
						   		if(xBala==x6+10 or xBala==x6+11){
						   			destruidos[5]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[6]==true){
							if(yBala==y7){
						   		if(xBala==x7+10 or xBala==x7+11){
						   			destruidos[6]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[7]==true){
							if(yBala==y8){
						   		if(xBala==x8+10 or xBala==x8+11){
						   			destruidos[7]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[8]==true){
							if(yBala==y9){
						   		if(xBala==x9+10 or xBala==x9+11){
						   			destruidos[8]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(destruidos[9]==true){
							if(yBala==y10){
						   		if(xBala==x10+10 or xBala==x10+11){
						   			destruidos[9]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
						   		}
							}
						}
						if(vuelta==true){
							x1++;	x6++;
							x2++;	x7++;
							x3++;	x8++;
							x4++;	x9++;
							x5++;	x10++;
							enemigos3(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10,y2, y3, y4, y5, y6, y7,y8, y9, y10);
							vuelta=false;
						}else{
							vuelta=true;
						}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
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
					vidas(vidasNave);
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
		//Si destruye los 10 objetivos
		if(cont>=10){
			run=false;
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel4(puntuacion,vidasNave);
		}
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel3(puntuacion,vidasNave);
		}
	}
}
void Nivel2(int puntuacion, int vidasNave){
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
	vidas(vidasNave);
	while(run){
		color(9);
//			 vvvv   Modificar la velocidad del tiempo
		if(n%1500==0){tiempo++;contador(tiempo);}
//			 vvvv   Modificar la velocidad del los enemigos
		if(n%170==0){
			x1++;	x6++;
			x2++;	x7++;
			x3++;	x8++;
			x4++;	x9++;
			x5++;	x10++;
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
		if (_kbhit()){
			tecla = getch();
			//cout<<tecla;
			switch(tecla){
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
						if(destruidos[0]==true){
						   	if(yBala==y1){
						   		if(xBala==x1+10 or xBala==x1+11){
						   			destruidos[0]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[1]==true){
							if(yBala==y1){
						   		if(xBala==x2+10 or xBala==x2+11){
						   			destruidos[1]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[2]==true){
							if(yBala==y1){
						   		if(xBala==x3+10 or xBala==x3+11){
						   			destruidos[2]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[3]==true){
							if(yBala==y1){
						   		if(xBala==x4+10 or xBala==x4+11){
						   			destruidos[3]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[4]==true){
							if(yBala==y1){
						   		if(xBala==x5+10 or xBala==x5+11){
						   			destruidos[4]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[5]==true){
							if(yBala==y1){
						   		if(xBala==x6+10 or xBala==x6+11){
						   			destruidos[5]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[6]==true){
							if(yBala==y1){
						   		if(xBala==x7+10 or xBala==x7+11){
						   			destruidos[6]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[7]==true){
							if(yBala==y1){
						   		if(xBala==x8+10 or xBala==x8+11){
						   			destruidos[7]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[8]==true){
							if(yBala==y1){
						   		if(xBala==x9+10 or xBala==x9+11){
						   			destruidos[8]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(destruidos[9]==true){
							if(yBala==y1){
						   		if(xBala==x10+10 or xBala==x10+11){
						   			destruidos[9]=false;
						   			puntuacion+=50;
						   			cont++;
						   			break;
								}
							}
						}
						if(vuelta==true){
							vuelta=false;
							x1++;	x6++;
							x2++;	x7++;
							x3++;	x8++;
							x4++;	x9++;
							x5++;	x10++;
							enemigos2(destruidos,x1,y1,x2, x3, x4, x5, x6, x7,x8, x9, x10);
						}else{
							vuelta=true;
						}
						gotoxy(xBala,yBala+1);
						cout<<" ";
						if (_kbhit())
				        {
							tecla = getch();
							//cout<<tecla;
							switch(tecla){
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
					vidas(vidasNave);
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
		//Si destruye los 10 objetivos
		if(cont==10){
			system("cls");
			gotoxy(30,15);
			cout<<"Avanzando al sig nivel";
			Sleep(1500);
			system("cls");
			Nivel3(puntuacion,vidasNave);
		}
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel2(puntuacion,vidasNave);
		}
	}
}
void Nivel1(int puntuacion, int vidasNave){
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
	int n=0;
	contador(tiempo);
	bool run=true;
	vidas(vidasNave);
	while(run){
		color(9);
		//   vvvv   Modificar la velocidad de los enemigos
		if(n%1000==0){tiempo++;contador(tiempo);}
		//if(n%500==0){x1++;system("cls");enemigos(destruidos,x1);}
		if(n==0){enemigos(destruidos,x1);}
		if (_kbhit())
        {
			tecla = getch();
			switch(tecla){
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
							switch(tecla){
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
					color(14);
					vidas(vidasNave);
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
			puntuacion+=sumaPuntos(puntuacion,tiempo);
			Nivel2(puntuacion,vidasNave);
		}
		//Se acaba el tiempo
		if (tiempo==91){
			vidasNave-=1;
			Sleep(1000);
			Nivel1(puntuacion,vidasNave);
		}
	}
}
//main
int main(){
	AjustarVentana(160,40);  // Para otras de menor resolución
	int tecla,op=0,arrabj=0;
	int puntuacion=0;
	int x=45,y=19;
	int vidas=3;
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
				Nivel1(puntuacion, vidas);
			break;
		}
	run=true;
	do{
		if(pantalla==3){
			y1=34,x1=44;	
		}
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
            		if(pantalla!=3){
            			if(y1>19){
		            		y1=y1-7;
		            		op--;
						}
						arrabj=0;
					}
            		break;
            	//Izquierda
				case 75:
            		break;
            	//Abajo
            	case 80:
            		//Validacion de flechita abajo
            		//PlaySound((LPCSTR)menu, NULL, SND_FILENAME | SND_ASYNC ); 
            		if(pantalla!=3){
						if(y1<33){
							y1=y1+7;
							op++;
						}
						arrabj=1;
					}
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
							}
					}
					if(y1==34){
						system("cls");
						pantalla=1;
						run=false;
					}
            		break;
				//Hot-Keys Niveles 1-6
            	case 49:
            		Nivel1(puntuacion,vidas);
            		break;
            	case 50:
            		Nivel2(puntuacion,vidas);
            		break;
            	case 51:
            		Nivel3(puntuacion,vidas);
            		break;
            	case 52:
            		Nivel4(puntuacion,vidas);
            		break;
            	case 53:
            		Nivel5(puntuacion,vidas);
            		break;
            	case 54:
            		Nivel6(puntuacion,vidas);
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
