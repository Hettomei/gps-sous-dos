#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VIRGULE.H"
#include "VTG.H"
#include "RMC.H"
#include "GSV.H"
#include "GGA.H"
#include "GSA.H"

#define ADBASE 0x3F8

void init(){

	outportb(ADBASE+3,0x82); // LCR <- pour mettre DLAB à 1  -> LCR 10000111 -> 87h
	outportb(ADBASE,0x18);   // DLL -> bit de poids faible de la vitesse 115200/4800 = 24 = 18h
	outportb(ADBASE+1,0x00); // DLM -> bit de poids fort de la vitesse
	outportb(ADBASE+3,0x07); // on remet le DLAB à 0
	outportb(ADBASE+1,0x00); // ier a 0 scrutation

}

void void_trame(char *trame2){

	int mask = 1 ;
	int bit0 = 0;
	int i=0;
	int j;
	int debut=0;        //sert a marquer le $
	char recu;

	while(recu !='\n'){      //recevoir 1 trame de $ a \n
		while(bit0 == 0){
			bit0 = inportb(ADBASE+5) & mask;
		}
		
		recu = inportb(ADBASE) ;
		if (recu=='$'){
			debut = 1;
		}
		if (debut == 1){
			bit0 = inportb(ADBASE+5) & mask; //on remet bit0 a 0 pour que la boucle premiere se refasse
			trame2[i]=recu;
			i++;
		}
		if (debut == 0){
			recu='\0';
		}
	}

	i--;

	if(trame2[1]=='$'){          //ce if sert a supprimer le $ en trop parfois recu
		for (j=0;j<i-1;j++){
			trame2[j]=trame2[j+1];
		}
	}

}

int quel_trame(char *trame2){
	char QuelTrame[6];
	int selection ; 

	virgule(trame2,0,QuelTrame);

	selection=0; // On le remet a 0 pour si les caracteres ne sont pas bons les erreurs
	if (strcmp(QuelTrame, "GPGGA") == 0) { selection=1 ;} // Si strcmp renvoie 0 (chaines identiques)
//	if (strcmp(QuelTrame, "GPGLL") == 0) { selection=x ;} //GLL n'apparait jamais.
	if (strcmp(QuelTrame, "GPGSA") == 0) { selection=2 ;}
	if (strcmp(QuelTrame, "GPGSV") == 0) { selection=3 ;}
	if (strcmp(QuelTrame, "GPVTG") == 0) { selection=4 ;}
	if (strcmp(QuelTrame, "GPRMC") == 0) { selection=5 ;}
	
	return selection;
}
void sel_case(int selection, char *trame){

	switch (selection)
	{
		case 1:
		GGA(trame);
		break;

		case 2:
		GSA(trame);
		break;

		case 3:
		GSV(trame);
		break;

		case 4:
		VTG(trame);
		break;

		case 5:
		RMC(trame);
		break;

		default:
		printf("\nERREUR dans la trame :\n%s\n", trame); //si erreur on affiche la trame qui pose probleme
		break;
	}

}
int main(){
	char trame[90];
	int selection=0 ; //determinera la trame
	int i=1; //boucle pour nbr de trame
	
	int j; // selection trame à afficher
	int k=-1; //pour temporiser
	int l ; //pour boucle de temporisation
	
	int temp[5] = {0,0,0,0,0}; //savoir quelle trame est sortie
	int count_temp=0;			//nbr de trame sortie
	
	init();
		
	printf("\n\nProgramme de decodage des trames NMEA\n");
	printf("Par le port serie configure : 4800-8-n-1\n\n");
	printf("Quelles trames voulez vous afficher ?");
	printf("\n1 : GGA\t\t2 : GSA\n3 : GSV\t\t4 : VTG\n5 : RMC\t\t6 : Toutes\n\n");
	while(j<1 || j > 6){
		printf("Faites votre choix : ");
		scanf("%d",&j);
	}
	printf("\nAfin de temporiser l'affichage, entrez le nombre de trame a laisser passer, conseil : 20");
	while(k<0){
		printf("Faites votre choix : ");
		scanf("%d",&k);
	}
	
	trame[0]='\0'; //initialisation

	while(i){ //Analyse x trames, on peut mettre une boucle infinie, et quitter avec ctrl+C
		void_trame(trame);  //"telecharge la trame"
		selection = quel_trame(trame); //analyse de quelle trame il s'agit GGA VGT...

/**********************************************///si 1 seule trame choisie au départ
		if (selection==j){
			sel_case(j, trame);           //En fonction de la selection de l'utilisateur on affiche la ou les trames
			for(l=0;l<k;l++){
				void_trame(trame);			//on temporise
			}
		}
/*******************************************/

/*******************************************/ //Si toutes trames choisies:
	
		else if (j==6){					//toutes les trames
			if (temp[selection-1]==0){         //vérifie si la trame est déjà sortie
				sel_case(selection, trame);
				temp[selection-1]=1;             //1 = trame déjà lu
				count_temp=count_temp+1;
				
				for(l=0;l<k;l++){                 //on temporise
					void_trame(trame);
				}
			}
			if (count_temp>=5){
				for(l=0;l<=4;l++){
					temp[l]=0;
				}
				count_temp=0;
			}		
		}						
		
/*******************************************/
// en cas de probleme
		else if (selection==0){
			printf("Erreur : %s",trame);
		}
	}

	return 0;

}