//Console.cpp - Defini��o das fun��es de console

#include "console.h"

/*----------------------------------------------------------------------------*\
|   clrscr                                                                     |
|                                                                              |
|   Descri��o:                                                                 |
|       Limpa a tela do console.                                               |
|                                                                              |
|   Par�metros:                                                                |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Limpa a tela com letras brancas em fundo preto                     |
|         clrscr(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);         |
|                                                                              |
|         //Limpa a tela com letras pretas em fundo branco                     |
|         clrscr(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void clrscr( WORD atributos)
{
	#define MY_BUFSIZE 1024			// Tamanho do buffer para o t�tulo da janela

	COORD coordScreen = { 0, 0 };   // Posi��o do cursor
	BOOL bSuccess;					// Auxiliar para armazenamento do retorno das fun��es
	DWORD cCharsWritten,
	      dwConSize;                // N�mero de caracteres atuais da janela
	CONSOLE_SCREEN_BUFFER_INFO csbi;// Informa��es sobre a janela
	HANDLE hConsole;				// Handle para a janela
 

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Recupera informa��es sobre a janela
	bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );

	//Calcula n�mero de caracteres
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 
	//Preenche janela com brancos
    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
							dwConSize, coordScreen, &cCharsWritten );
 
	//Preenche janela com o atributo escolhido
	bSuccess = FillConsoleOutputAttribute( hConsole, atributos,
							dwConSize, coordScreen, &cCharsWritten );
 
	//Posiciona o cursor no canto superior esquerdo 
	bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
}

/*----------------------------------------------------------------------------*\
|   gotoxy                                                                     |
|                                                                              |
|   Descri��o:                                                                 |
|       Posiciona o cursor em determinado local                                |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void gotoxy (int x, int y)
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posi��o do cursor

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Posiciona o cursor no canto superior esquerdo 
	SetConsoleCursorPosition( hConsole, coord );
}

/*----------------------------------------------------------------------------*\
|   mostratexto                                                                |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra uma string em determinada posi��o da tela com cores diferentes. |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostratexto ( int x, int y, char *texto, WORD atributos )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posi��o do cursor
	DWORD dChar;				// N�mero de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posi��o indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}

/*----------------------------------------------------------------------------*\
|   mostrar                                                                    |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra uma string em determinada posi��o da tela com cores diferentes. |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostrar ( int x, int y, WORD atributos, char *texto )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posi��o do cursor
	DWORD dChar;				// N�mero de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posi��o indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}


/*----------------------------------------------------------------------------*\
|   mostrar                                                                    |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra um long em determinada posi��o da tela com cores diferentes.    |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       valor -> n�mero a ser mostrado                                         |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostrar ( int x, int y, WORD atributos, long valor )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posi��o do cursor
	DWORD dChar;				// N�mero de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posi��o indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Monta string
	char texto[10];
	ltoa(valor, texto, 10);

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}

/*----------------------------------------------------------------------------*\
|   mostrar                                                                    |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra um char em determinada posi��o da tela com cores diferentes.    |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       valor -> n�mero a ser mostrado                                         |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostrar ( int x, int y, WORD atributos, char valor )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posi��o do cursor
	DWORD dChar;				// N�mero de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posi��o indicada
	SetConsoleCursorPosition( hConsole, coord );

    char texto[2] = {valor, '\0'};

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}
