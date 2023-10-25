#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h> 

char tablero[3][3]; 
char jugarnuevo[10];
const char jugador = 'X';
const char computadora = 'O';
int reiniciar = 0;
void tablero1();
void aparecert ();
int casillaslibres();
void movjugador();
void movcompu();
char ganador();
void imprimirganador(char);

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void aparecert (int a, int b){
	
	int i, j;
	
//system('cls');

	printf("Intrucciones: El usuario tiene que escoger en que fila y luego la columna quiere poner su ficha de juego. \n");
	printf("\n");
	printf("Y luego automaticamente la computadora pondra su ficha siguiente. Espero y te diviertas. Buena suerte! \n");
	
	printf("\n");
	gotoxy(a,b);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,194,196,196,196,194,196,196,196,191);
	gotoxy(a,b+1);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j<2){
				printf("%c %c ",179,tablero[i][j]);
			}else{
				printf("%c %c %c\n",179,tablero[i][j],179);
			}
		}
		if(i==0){
			gotoxy(a,b+2);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
		}else if (i==1){
			gotoxy(a,b+4);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
		}
		if(i==0){
			gotoxy(a,b+3);
		}else if (i==1){
			gotoxy(a,b+5);
		}
	}
	gotoxy(a,b+6);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,193,196,196,196,193,196,196,196,217);
	printf("\n");
	
}

int main()
{
	int a, b, op;

	printf("------TOTITO------\n");
	printf("--Proyecto Final--\n");
	printf("Fatima Lourdes Santos Guzman\n");
	printf("\n");
	

	printf("Donde de quiere el tablero (Ejemplo 15 y 9) \n");
	printf("Coordenada X: ");
	scanf("%d",&a);
	printf("Coordenada y: ");
	scanf("%d",&b);
	
	system("cls");
	
	char jugarnuevo[10];
	char campeon = ' ';

	tablero1();
	
	
	while(campeon == ' ' && casillaslibres() != 0 )
		{
			aparecert(a, b);
			movjugador();
			campeon = ganador();
			if(campeon != ' '||  casillaslibres() == 0 )
			{
				break;	
			}
			
			movcompu();
			campeon = ganador();
			if(campeon != ' '||  casillaslibres() == 0 )
			{
				break;	
			}
		}
		aparecert (a,b);
		imprimirganador(campeon);
		
		printf("\nQuieres volver a jugar? ");
		printf("\n1 .-Si\n2.-No\n Escriba 1 para Si y 2 para no: ");
		
		return 0;
		
		}

	


void tablero1()
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			tablero[i][j] = ' ';
		}
		
	}
	 
}

int casillaslibres(){
	
	int espacioslibres = 9;
	for(int i = 0; i <3; i++)
	{
		for(int j = 0; j <3; j++)
		{
			if (tablero[i][j] != ' ')
			{
				espacioslibres--;
				
			}
		}
		
	}
	
	return espacioslibres; 
}
void movjugador()
{
	int x;
	int y;
	
	do {
			printf("Tu turno \n");
			printf("Escoge la fila (1,2,3): ");
			scanf("%d", &x);
			x--;
			
			printf("Escoge la columna (1,2,3): ");
			scanf("%d", &y);
			printf("");
			y--;
			
			if(tablero[x][y] != ' '  )     
			{
				printf("Casilla ocupada \n");
				
			}
			else 
			{
				tablero[x][y] = jugador;
				break; 
			}
		} while (tablero[x][y] != ' ');
		printf("\n");
		system("cls");
		
		
}

void movcompu(){
	srand(time(0));
	int x;
	int y;
	
	if(casillaslibres() > 0)
	{
		do 
		{
			x = rand() % 3;
			y = rand() % 3;
		}while(tablero[x][y] != ' ');
		
		tablero[x][y] = computadora;	
	}
	else
	{
		imprimirganador(' ');
	}
	
	
}
char ganador(){
	//comprobaré las filas
	for(int i = 0; i < 3; i++){
		if(tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2])
		{
			return tablero[i][0];
		}
		
	}
	//voy a comprobar las columnas
		for(int i = 0; i < 3; i++)
		{
			if(tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i])
			{
				return tablero[0][1];
			}
		
		}
		if(tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
			{
				return tablero[0][0];
			}
		if(tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
			{
				return tablero[0][2];
			}	
	return ' ';
}
void imprimirganador(char campeon ){
	
	 
	if(campeon == jugador){
		printf("Felicidades, tu ganaste! Siuuuu");
		
	}
	else if(campeon == computadora){
		printf("Gana la computadora, lo siento. A una proxima!");
	}
	else{
		printf("Es un empate, repito ES UN EMPATE");
	}
	
}