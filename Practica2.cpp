/*
	*GATO: 
		Debe tener nivel: Fácil, Medio y Difícil.
	*Adivinar un número:
		El usuario elige el rango y debe de adivinar. 
		Darle 3 oportunidades.
	*Adivinar una palabra:
		Dar 3 pistas al usuario y un intento por cada pista.
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <String.h>
#include <iostream>
#include <ctype.h>
#include <locale.h>//Librería para que acepte acentos y Ñ's el programa.
using namespace std;

/**************FUNCIONES**********************/
void Adivinar_Numero(void);
void Adivinar_Palabra(void);
int Menu();//Funcion Menu
void gotoxy(int,int);//Funcion Gotoxy.
/**************FUNCIONES**********************/

/**************MAIN**********************/
main()
{
	setlocale(LC_CTYPE,"Spanish");//Para que acepte caracteres del teclado en español.
	char opc='\0';
	
	do
	{
		opc=Menu();
		switch(opc)
		{
			case 27://ESC.
				system("color 0C");
				system("cls");
				gotoxy(40,2);cout<<"Adios, gracias por usar el programa.";
				exit(0);
				
			break;
			
			case 49://Numero 1.//Gato.
				system("cls");
				//MenuGato();
			break;
			
			case 50://Numero 2.// Adivinar un Numero.
				system("cls");
				Adivinar_Numero();
			break;
			
			case 51://Numero 3.// Adivinar una palabra.
				system("cls");
				Adivinar_Palabra();
			break;
			
			default:
				if(opc!=27)
				{
					Beep(1000,100);
				}
		}
		
	}while(opc!=27);
}
/**************MAIN**********************/

void Adivinar_Numero()
{
	int Inicio=0, Final=0, NumUsu=0, NumPC=0, contador=1;
	string Resp=" "; bool Bandera=false, Ganador=false;
	char interrogacion=168;
	do
	{
		fflush(stdin);
		
		system("cls");
		system("color 0F");//Color negro con blanco.
		gotoxy(42,1);cout<<"[      ADIVINAR UN NUMERO      ]";
		gotoxy(45,5);cout<<"INSTRUCCIONES:";
		gotoxy(40,6);cout<<"* EL USUARIO ELIGIRA UN RANGO: UN NUMERO INFERIOR Y UNO SUPERIOR.        *";
		gotoxy(40,7);cout<<"* EL JUEGO ELIGIRA UN NUMERO RANDOM, EL CUAL EL USUARIO DEBERA ADIVINAR. *";
		gotoxy(40,8);cout<<"* EL USUARIO TENDRA 3 OPORTUNIDADES PARA ACERTAR.                        *";
		gotoxy(40,9);cout<<"* SI NO LOGRA DAR CON EL NUMERO, PERDERA LA PARTIDA.                     *";
		
		gotoxy(5,7);cout<<interrogacion<<"QUIERES INICIAR CON EL JUEGO?";
		gotoxy(14,8);getline(cin,Resp);
		
		if(Resp=="sI"||Resp=="si"||Resp=="SI"||Resp=="Si")
		{
			system("color 02");//Color negro con verde.
			Sleep(1000);
			system("cls");
			system("color 0F");//Color negro con blanco.
			
			gotoxy(42,0);cout<<"[      ADIVINAR UN NUMERO      ]";
			gotoxy(15,2);cout<<"ELIGE EL RANGO INFERIOR:";
			gotoxy(39,2);cin>>Inicio;
			gotoxy(15,3);cout<<"ELIGE EL RANGO SUPERIOR:";
			gotoxy(39,3);cin>>Final;
			
			NumPC = Inicio + rand() % (Final-Inicio);
			gotoxy(39,4);cout<<NumPC;
			
			do
			{
				gotoxy(80,2);cout<<"INTENTOS:";
				gotoxy(84,3);cout<<contador;
				
				system("color 0F");
				gotoxy(15,5);cout<<"ESCRIBE EL NUMERO:";
				gotoxy(34,5);cin>>NumUsu;
				
				if(NumUsu == NumPC)
				{
					system("color 02");
					gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
					gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
					getch();
					Ganador=true;
					contador=4;
				}
				else
				{
					system("color 0C");
					gotoxy(34,5);cout<<"NO ES EL NUMERO DENTRO DEL RANGO, INTENTA OTRA VEZ.";
					Sleep(850);
					gotoxy(34,5);cout<<"                                                   ";
					Ganador=false;
				}
				
				contador++;
			}while(contador<4 || (contador<4 && Ganador==false));
			if(Ganador==false)
			{
				system("color 0C");
				gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
				gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
				getch();
			}
		}
		else if(Resp=="NO"||Resp=="no"||Resp=="No"||Resp=="nO")
		{
			system("cls");
			system("color 01");//Color negro con verde.
			gotoxy(40,9);cout<<"[GRACIAS POR USAR EL JUEGO]";
			gotoxy(40,10);cout<<"VOLVERAS AL MENU...";
			Sleep(1500);
			Menu();
		}
		else
		{
			system("color 0C");//Color negro con rojo.
			gotoxy(14,8);cout<<"PALABRA INCORRECTA.";
			Sleep(1500);
			gotoxy(14,8);cout<<"                   ";
			Bandera=true;
		}
		
	}while(Bandera==true);
}

void Adivinar_Palabra()
{
	
	char P1[]="MEXICO",P2[]="JAPON",P3[]="ARGENTINA",P4[]="COLOMBIA",P5[]="BRASIL",RespUsuario[]=" ";
	int Inicio=1, Final=5, NumPC=0, Intentos=0;
	bool Bandera=false, Ganador=false; char interrogacion=168;
	string Resp=" ";
	do
	{
		fflush(stdin);
		system("cls");
		system("color 0F");//Color negro con blanco.
		
		gotoxy(42,1);cout<<"[      ADIVINAR UNA PALABRA      ]";
		gotoxy(45,5);cout<<"INSTRUCCIONES:";
		gotoxy(40,6);cout<<"*  EL PROGRAMA ELIGIRA UNA PALABRA AL AZAR Y EL USUARIO DEBERA ADIVINAR. *";
		gotoxy(40,7);cout<<"*  CON CADA FALLO TENDRA UNA PISTA.                                      *";
		gotoxy(40,8);cout<<"*  LAS PISTAS SE VERAN EN EL LADO SUPERIOR DERECHO.                      *";
		gotoxy(40,9);cout<<"*  EL USUARIO TENDRA 3 OPORTUNIDADES PARA ACERTAR.                       *";
		gotoxy(40,10);cout<<"*  SI NO LOGRA DAR CON LA PALABRA, PERDERA LA PARTIDA.                   *";
		
		gotoxy(5,7);cout<<interrogacion<<"QUIERES INICIAR CON EL JUEGO?";
		gotoxy(14,8);getline(cin,Resp);
		
		if(Resp=="sI"||Resp=="si"||Resp=="SI"||Resp=="Si")
		{
			
			system("color 02");//Color negro con verde.
			Sleep(1000);
			system("cls");
			system("color 0F");//Color negro con blanco.
			
			gotoxy(42,1);cout<<"[      ADIVINAR UNA PALABRA      ]";
			NumPC = Inicio + rand() % (Final-Inicio); //Se va a generar el número de la palabra.
			
			gotoxy(84,4);cout<<NumPC;
			//getch();
			
			switch(NumPC)
			{
				case 1://MÉXICO//P1
					do
					{
						if(Intentos==0)
						{
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"VIGOTES Y CABALLOS.";
						}
						else if(Intentos==1)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"MARIACHIS.";
						}
						else if(Intentos==2)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"NACIERON LOS TACOS.";
						}
						else if(Intentos==3)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(86,6);cout<<"SE DICEN WEY.";
						}
						
						gotoxy(80,2);cout<<"INTENTOS:";
						gotoxy(84,3);cout<<Intentos;
						system("color 0F");
						
						gotoxy(15,5);cout<<interrogacion<<"CUAL ES LA PALABRA?";
						gotoxy(37,5);gets(RespUsuario);
						
						for(int i = 0; RespUsuario[i]; i++)
     						RespUsuario[i] = toupper(RespUsuario[i]); //Convierte a minusculas.
						
						if(strcmp(RespUsuario, P1) == 0)
						{
							system("color 02");
							gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
							gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
							getch();
							Ganador=true;
							Intentos=4;
						}
						else
						{
							system("color 0C");
							gotoxy(36,5);cout<<"PALABRA CORRECTA.";
							Sleep(850);
							gotoxy(34,5);cout<<"                          ";
							Ganador=false;
						}
						Intentos++;
						
					}while(Intentos<4 || (Intentos<4 && Ganador==false));
					
					if(Ganador==false)
					{
						system("color 0C");
						gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
						gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
						getch();
					}
					
				break;
				
				case 2://JAPÓN//P2
					do
					{
						if(Intentos==0)
						{
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"OJOS RASGADOS.";
						}
						else if(Intentos==1)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"SUSHI.";
						}
						else if(Intentos==2)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"CREADORES DE ANIME.";
						}
						else if(Intentos==3)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"GUSTO DE OTAKUS.";
						}
						
						gotoxy(80,2);cout<<"INTENTOS:";
						gotoxy(84,3);cout<<Intentos;
						system("color 0F");
						
						gotoxy(15,5);cout<<interrogacion<<"CUAL ES LA PALABRA?";
						gotoxy(37,5);gets(RespUsuario);
						
						for(int i = 0; RespUsuario[i]; i++)
     						RespUsuario[i] = toupper(RespUsuario[i]); //Convierte a minusculas.
						
						if(strcmp(RespUsuario, P2) == 0)
						{
							system("color 02");
							gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
							gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
							getch();
							Ganador=true;
							Intentos=4;
						}
						else
						{
							system("color 0C");
							gotoxy(36,5);cout<<"PALABRA CORRECTA.";
							Sleep(850);
							gotoxy(34,5);cout<<"                          ";
							Ganador=false;
						}
						Intentos++;
						
					}while(Intentos<4 || (Intentos<4 && Ganador==false));
					
					if(Ganador==false)
					{
						system("color 0C");
						gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
						gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
						getch();
					}
				break;
				
				case 3://ARGENTINA//P3
					do
					{
						if(Intentos==0)
						{
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(83,6);cout<<"TOMAN MUCHO MATE.";
						}
						else if(Intentos==1)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(83,6);cout<<"CREARON EL TANGO.";
						}
						else if(Intentos==2)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"MESSI.";
						}
						else if(Intentos==3)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"SON BOLUDOS.";
						}
						
						gotoxy(80,2);cout<<"INTENTOS:";
						gotoxy(84,3);cout<<Intentos;
						system("color 0F");
						
						gotoxy(15,5);cout<<interrogacion<<"CUAL ES LA PALABRA?";
						gotoxy(37,5);gets(RespUsuario);
						
						for(int i = 0; RespUsuario[i]; i++)
     						RespUsuario[i] = toupper(RespUsuario[i]); //Convierte a minusculas.
						
						if(strcmp(RespUsuario, P3) == 0)
						{
							system("color 02");
							gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
							gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
							getch();
							Ganador=true;
							Intentos=4;
						}
						else
						{
							system("color 0C");
							gotoxy(36,5);cout<<"PALABRA CORRECTA.";
							Sleep(850);
							gotoxy(34,5);cout<<"                          ";
							Ganador=false;
						}
						Intentos++;
						
					}while(Intentos<4 || (Intentos<4 && Ganador==false));
					
					if(Ganador==false)
					{
						system("color 0C");
						gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
						gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
						getch();
					}
				break;
				
				case 4://COLOMBIA//P4
					do
					{
						if(Intentos==0)
						{
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"PREPARAN AREPAS.";
						}
						else if(Intentos==1)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"CAFETALEROS.";
						}
						else if(Intentos==2)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"BOGOTA.";
						}
						else if(Intentos==3)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(86,6);cout<<"SON PARCEROS.";
						}
						
						gotoxy(80,2);cout<<"INTENTOS:";
						gotoxy(84,3);cout<<Intentos;
						system("color 0F");
						
						gotoxy(15,5);cout<<interrogacion<<"CUAL ES LA PALABRA?";
						gotoxy(37,5);gets(RespUsuario);
						
						for(int i = 0; RespUsuario[i]; i++)
     						RespUsuario[i] = toupper(RespUsuario[i]); //Convierte a minusculas.
						
						if(strcmp(RespUsuario, P4) == 0)
						{
							system("color 02");
							gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
							gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
							getch();
							Ganador=true;
							Intentos=4;
						}
						else
						{
							system("color 0C");
							gotoxy(36,5);cout<<"PALABRA CORRECTA.";
							Sleep(850);
							gotoxy(34,5);cout<<"                          ";
							Ganador=false;
						}
						Intentos++;
						
					}while(Intentos<4 || (Intentos<4 && Ganador==false));
					
					if(Ganador==false)
					{
						system("color 0C");
						gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
						gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
						getch();
					}
				break;
				
				case 5://BRASIL//P5
					do
					{
						if(Intentos==0)
						{
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(83,6);cout<<"DESIERTO DE MARANHAO.";
						}
						else if(Intentos==1)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(87,6);cout<<"LA SAMBA.";
						}
						else if(Intentos==2)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"CARPIRINHA.";
						}
						else if(Intentos==3)
						{
							gotoxy(84,6);cout<<"                                  ";
							gotoxy(88,5);cout<<"PISTA #"<<Intentos+1; gotoxy(84,6);cout<<"SAO PAULO.";
						}
						
						gotoxy(80,2);cout<<"INTENTOS:";
						gotoxy(84,3);cout<<Intentos;
						system("color 0F");
						
						gotoxy(15,5);cout<<interrogacion<<"CUAL ES LA PALABRA?";
						gotoxy(37,5);gets(RespUsuario);
						
						for(int i = 0; RespUsuario[i]; i++)
     						RespUsuario[i] = toupper(RespUsuario[i]); //Convierte a minusculas.
						
						if(strcmp(RespUsuario, P5) == 0)
						{
							system("color 02");
							gotoxy(15,7);cout<<"FELICIDADES HAS GANADO EL JUEGO.";
							gotoxy(15,8);cout<<"GRACIAS POR PARTICIPAR.";
							getch();
							Ganador=true;
							Intentos=4;
						}
						else
						{
							system("color 0C");
							gotoxy(36,5);cout<<"PALABRA CORRECTA.";
							Sleep(850);
							gotoxy(34,5);cout<<"                          ";
							Ganador=false;
						}
						Intentos++;
						
					}while(Intentos<4 || (Intentos<4 && Ganador==false));
					
					if(Ganador==false)
					{
						system("color 0C");
						gotoxy(15,7);cout<<"LO SENTIMOS, HAS PERDIDO LA PARTIDA.";
						gotoxy(15,8);cout<<"INTENTALO DE NUEVO. SUERTE.";
						getch();
					}
				break;
				
				default:
					system("cls"); system("color 0C");//Color negro con rojo.
					Beep(400,8000);
					gotoxy(45,10);cout<<"HUBO UN ERROR EN EL PROCESO...";
					exit(0);
			}
		}
		else if(Resp=="NO"||Resp=="no"||Resp=="No"||Resp=="nO")
		{
			system("cls");
			system("color 01");//Color negro con azul.
			gotoxy(40,9);cout<<"[GRACIAS POR USAR EL JUEGO]";
			gotoxy(40,10);cout<<"VOLVERAS AL MENU...";
			Sleep(1500);
			Menu();
		}
		else
		{
			system("color 0C");//Color negro con rojo.
			gotoxy(14,8);cout<<"PALABRA INCORRECTA.";
			Sleep(1500);
			gotoxy(14,8);cout<<"                   ";
			Bandera=true;
		}
	}while(Bandera==true);
}

/***************************************************************************MENU************************************************************************/
int Menu()
{
	system("color 0F");
	char opc1='\0';
	system("cls");
	fflush(stdin);
	gotoxy(38,2);cout<<"********Menu Juegos********";
	gotoxy(46,4);cout<<"[ESC] Salir.";
	gotoxy(46,5);cout<<"[ 1 ] GATO";
	gotoxy(46,6);cout<<"[ 2 ] ADIVINAR UN NUMERO.";
	gotoxy(46,7);cout<<"[ 3 ] ADIVINAR UNA PALABRA.";
	
	gotoxy(56,13);opc1=getch();
}
/***************************************************************************MENU************************************************************************/

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
