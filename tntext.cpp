#include <iostream>
#include <cstdlib>
#include "console.h"
#include <windows.h> // Sleep
#include <conio.h> //funções de teclado

using namespace std;

# define LINHAS 26
# define COLUNAS 81

	
int main() {
	inicio:
	
	int campo_tnt [COLUNAS] [LINHAS]; // array 2-D
	
	int coluna=0;
	int linha=0;
	int vitoria=0;
	int x=1;
	int pos_col = 0;
	int pos_lin = 0 ;
		
	clrscr(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_WHITE); 
	mostratexto(1,1, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,2, "TXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXT", FOREGROUND_YELLOW | BACKGROUND_BLUE);
	mostratexto(1,3, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,4, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,5, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,6, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,7, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,8, "         TTTTTTTT   NN    NN   TTTTTTTT   EEEEEE   XX      XX   TTTTTTTT", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,9, "            TT      NNNN  NN      TT      EE         XX  XX        TT   ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,10,"            TT      NN  NNNN      TT      EEEEEE       XX          TT   ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,11,"            TT      NN    NN      TT      EE         XX  XX        TT   ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,12,"            TT      NN    NN      TT      EEEEEE   XX      XX      TT   ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,13," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,14," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,15," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,16," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,17,"       ENZO AUGUSTO MARCHIORATO              (TXTEXT BETA 0.1)  ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,18,"       PUC PR - DESENVOLVIMENTO DE JOGOS DIGITAIS - PROJETO 1", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,19," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,20," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,21," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,22," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	mostratexto(1,23,"TXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXT", FOREGROUND_YELLOW | BACKGROUND_BLUE);
	mostratexto(1,24," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
	//mostratexto(1,25," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);

int pretnt1=20;
int pretnt2=30;
int pretnt3=14;
int pretnt4=60;

int anda=1;

	int tecla=0;

		while (true) {
			if (kbhit()) {
				tecla = getch();
				if (tecla == 13) {
					break;
				}  
				if (tecla == 27) {
					break;
				} 
			}
			pretnt1 = pretnt1+4;
			pretnt2 = pretnt2+4;
			pretnt3 = pretnt3+4;
			pretnt4 = pretnt4+4;

			if (pretnt1 > 65){
				pretnt1 = 2;
			}
			if (pretnt2 > 65){
				pretnt2 = 2;
			}
			if (pretnt3 > 65){
				pretnt3 = 2;
			}
			if (pretnt4 > 65){
				pretnt4 = 2;
			}
		}

	char FIMJOGO = 'N';
	clrscr(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	linha=1;
	while (linha <= 23){
		int casa=0;
		while (coluna <= 80){
			//mostratexto(coluna,linha," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
			//campo_tnt[linha][coluna] = 0;
			
			if (linha<=20 && coluna>1 && coluna<=77) {
					if (casa<4){
						if (linha==1 || linha==2 || linha==5|| linha==6 || linha==9 || linha==10 || linha==13 || linha==14 || linha==17  || linha==18){ 
							mostratexto(coluna,linha,"°", FOREGROUND_YELLOW | BACKGROUND_WHITE);
						}else{
							mostratexto(coluna,linha," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
						}
					}else{
						if (linha==1 || linha==2 || linha==5|| linha==6 || linha==9 || linha==10 || linha==13 || linha==14 || linha==17  || linha==18){ 
							mostratexto(coluna,linha," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
						}else{
							mostratexto(coluna,linha,"°", FOREGROUND_YELLOW | BACKGROUND_WHITE);
						}
					}
					casa++;
					if (casa>7){
						casa=0;
					}		
			}
			if (linha>20 && coluna>1 && coluna<=77) {
				mostratexto(coluna,linha," ", FOREGROUND_YELLOW | BACKGROUND_RED);		
			}
			campo_tnt [coluna][linha] = 0;
			coluna = coluna + 1;
		}
	coluna = 0;
	linha=linha + 1;
	}	

	mostratexto(pretnt1,5,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	mostratexto(pretnt1,6,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	campo_tnt [pretnt1][5] = 1;

	mostratexto(pretnt2,9,   "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	mostratexto(pretnt2,10,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	campo_tnt [pretnt2][9] = 1;

	mostratexto(pretnt3,13,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	mostratexto(pretnt3,14,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	campo_tnt [pretnt3][13] = 1;

	mostratexto(pretnt4,17,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	mostratexto(pretnt4,18,  "    ", FOREGROUND_YELLOW | BACKGROUND_RED);
	campo_tnt [pretnt4][17] = 1;

 	coluna=2;
	linha=1;

	gotoxy(coluna, linha); 

	mostratexto(coluna,linha,  " 00 ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
	mostratexto(coluna,linha+1,"|°°|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
	


	while (true) {
		if (vitoria > 188){
			x=1;
			for(x=1;x<15;x++) {
				Beep(4000,50);

				clrscr(BACKGROUND_BLUE);
				mostratexto(10,8, "YY    YY  OOOOOOOO  UU    UU      WW      WW  II  NN    NN", FOREGROUND_BLUE);
				mostratexto(10,9, " YY  YY   OO    OO  UU    UU      WW  WW  WW  II  NNN   NN", FOREGROUND_BLUE);
				mostratexto(10,10,"  YYYY    OO    OO  UU    UU      WW  WW  WW  II  NNNN  NN", FOREGROUND_BLUE);
				mostratexto(10,11,"   YY     OO    OO  UU    UU       WW WW WW   II  NN NN NN", FOREGROUND_BLUE);
				mostratexto(10,12,"   YY     OOOOOOOO  UUUUUUUU        WWWWWW    II  NN  NNNN", FOREGROUND_BLUE);

				Sleep(100);
				clrscr(BACKGROUND_WHITE);

				mostratexto(10,8, "YY    YY  OOOOOOOO  UU    UU      WW      WW  II  NN    NN", BACKGROUND_WHITE);
				mostratexto(10,9, " YY  YY   OO    OO  UU    UU      WW  WW  WW  II  NNN   NN", BACKGROUND_WHITE);
				mostratexto(10,10,"  YYYY    OO    OO  UU    UU      WW  WW  WW  II  NNNN  NN", BACKGROUND_WHITE);
				mostratexto(10,11,"   YY     OO    OO  UU    UU       WW WW WW   II  NN NN NN", BACKGROUND_WHITE);
				mostratexto(10,12,"   YY     OOOOOOOO  UUUUUUUU        WWWWWW    II  NN  NNNN", BACKGROUND_WHITE);
					
				Sleep(100);
			}
			//FIMJOGO = 'S';
			Beep(4000,40);
			Sleep(3000);
			goto inicio;
		}
		
		if (kbhit()) {
			tecla = getch();
			if (tecla == 27) {
				break;
			}                
			if (linha <= 20 && linha >=0 && coluna>=0 && coluna<=77) {
				switch (tecla) {
					case 72: 
						if (linha > 1){
							gotoxy(coluna, linha=linha-2); 
						}
						break;
					case 80: 
						if (linha < 19){
							gotoxy(coluna, linha=linha+2);
						}
						break;
					case 75: 
						if (coluna > 2){
							gotoxy(coluna=coluna-4, linha);
						}
						break;
					case 77:
						if (coluna < 73){
							gotoxy(coluna=coluna+4, linha);
						}
						break;
				}
				Beep(1000,40);
				switch (anda){
					case 1:
						mostratexto(coluna,linha,  "|0o ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						mostratexto(coluna,linha+1," °°|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						anda=anda+1;
						break;
					case 2:
						mostratexto(coluna,linha,  "|o0 ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						mostratexto(coluna,linha+1," °°|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						anda=anda+1;
						break;
					case 3:
						mostratexto(coluna,linha,  " 0o ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						mostratexto(coluna,linha+1,"|°°|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						anda=anda+1;
						break;
					case 4:
						mostratexto(coluna,linha,  " o0|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						mostratexto(coluna,linha+1,"|°° ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						anda=anda+1;
						break;
					case 5:
						mostratexto(coluna,linha,  "|0o|", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						mostratexto(coluna,linha+1," °° ", FOREGROUND_YELLOW | BACKGROUND_BLUE);
						anda=1;
						break;
				}
			}	
			
			if (campo_tnt [coluna][linha] == 0){
				campo_tnt [coluna][linha] = 1;
			}
			
			if (pos_col == coluna && pos_lin == linha){
				mostratexto(coluna,linha,  "° ° ", FOREGROUND_YELLOW | BACKGROUND_GREEN);
				mostratexto(coluna,linha+1," ° °", FOREGROUND_YELLOW | BACKGROUND_GREEN);
			}
			
			pos_col = coluna;
			pos_lin = linha ;

			x=1;

			if (campo_tnt [coluna][linha] >= 10000){
				for(x=1;x<15;x++) {
					Beep(4000,50);

					clrscr(BACKGROUND_RED);
					mostratexto(10,8, "KK    KK  AAAAAAAA  BBBBBBBB  OOOOOOOO  OOOOOOOO   MM    MM", BACKGROUND_RED);
					mostratexto(10,9, "KK  KK    AA    AA  BB    BB  OO    OO  OO    OO   MMM  MMM", BACKGROUND_RED);
					mostratexto(10,10,"KKKK      AAAAAAAA  BBBBBB    OO    OO  OO    OO   MMMMMMMM", BACKGROUND_RED);
					mostratexto(10,11,"KK  KK    AA    AA  BB    BB  OO    OO  OO    OO   MM MM MM", BACKGROUND_RED);
					mostratexto(10,12,"KK    KK  AA    AA  BBBBBBBB  OOOOOOOO  OOOOOOOO   MM    MM", BACKGROUND_RED);

					Sleep(100);
					clrscr(BACKGROUND_WHITE);

					mostratexto(10,8, "KK    KK  AAAAAAAA  BBBBBBBB  OOOOOOOO  OOOOOOOO   MM    MM", BACKGROUND_WHITE);
					mostratexto(10,9, "KK  KK    AA    AA  BB    BB  OO    OO  OO    OO   MMM  MMM", BACKGROUND_WHITE);
					mostratexto(10,10,"KKKK      AAAAAAAA  BBBBBB    OO    OO  OO    OO   MMMMMMMM", BACKGROUND_WHITE);
					mostratexto(10,11,"KK  KK    AA    AA  BB    BB  OO    OO  OO    OO   MM MM MM", BACKGROUND_WHITE);
					mostratexto(10,12,"KK    KK  AA    AA  BBBBBBBB  OOOOOOOO  OOOOOOOO   MM    MM", BACKGROUND_WHITE);
					
					Sleep(100);
				}
				clrscr(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_WHITE); 
				mostratexto(1,1, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,2, "TXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXT", FOREGROUND_YELLOW | BACKGROUND_BLUE);
				mostratexto(1,3, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,4, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,5, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,6, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,7, " ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,8, "GGGGGGGG  AAAAAAAA  MMM  MMM  EEEEEEEE  OOOOOOOO   VV    VV  EEEEEEEE  RRRRRRRR", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,9, "GG        AA    AA  MMM  MMM  EE        OO    OO   VV    VV  EE        RR    RR", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,10,"GG  GGGG  AAAAAAAA  MM MM MM  EEEE      OO    OO    VV  VV   EEEE      RRRRRRRR", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,11,"GG    GG  AA    AA  MM    MM  EE        OO    OO     VVVV    EE        RR  RR  ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,12,"GGGGGGGG  AA    AA  MM    MM  EEEEEEEE  OOOOOOOO      VV     EEEEEEEE  RR    RR", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,13," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,14," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,15," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,16," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,17,"       ENZO AUGUSTO MARCHIORATO              (TXTEXT BETA 0.1)  ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,18,"       PUC PR - DESENVOLVIMENTO DE JOGOS DIGITAIS - PROJETO 1", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,19," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,20," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,21," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,22," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				mostratexto(1,23,"TXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXTTXTEXT", FOREGROUND_YELLOW | BACKGROUND_BLUE);
				mostratexto(1,24," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				//mostratexto(1,25," ", FOREGROUND_YELLOW | BACKGROUND_WHITE);
				FIMJOGO = 'S';
				//return EXIT_SUCCESS;
				Beep(4000,40);
				Sleep(3000);
				goto inicio;
			}
		}
	
		int  tntx=0;
		int  tnty=0;
		int  tempo_ativado=0;
		
		if (FIMJOGO == 'N'){
				if (tecla != 13){
					while (tnty++ < 19){
						while (tntx++ < 77) {
							tempo_ativado=(campo_tnt[tntx][tnty]);
							if (tempo_ativado > 0){
								if (tempo_ativado < 10000) {
									//Sleep (10);wA
									(campo_tnt[tntx][tnty])++;
									tempo_ativado=(campo_tnt[tntx][tnty]);
									if (tempo_ativado >= 10000){
										mostratexto(tntx,tnty,  "° ° ", FOREGROUND_YELLOW | BACKGROUND_RED);
										mostratexto(tntx,tnty+1," ° °", FOREGROUND_YELLOW | BACKGROUND_RED);
										Beep(2000,50);
										vitoria++;
									}
								}
							}
						}
					tntx = 0;
					}
				}
		}
	}
	return 0;
}


