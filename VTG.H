void VTG(char *trame2){
	char plop[20];
	float i ;
	printf("\n*** TRAME VTG ***\n");
	if (virgule(trame2, 1, plop)==0){
		printf("\nAucun mouvement detecte\n");
	}

	else {
		virgule(trame2, 1, plop);

		i = atof(plop);
		printf("\nLe cap reel est de %.1f deges",i);

		if(virgule(trame2, 3, plop)!=0){

			i=(plop[0]-48)*100+(plop[1]-48)*10+(plop[2]-48)+(plop[4]-48)*0.1;
			printf("\nLe cap vrai magnetique est de %.1f degres",i);
		}
		
		virgule(trame2, 5, plop);
		i = atof(plop);
		printf("\nLa vitesse du deplacement par rapport au sol est de %.1f Noeuds",i);

		virgule(trame2, 7, plop);
		i = atof(plop);
		printf("\nLa vitesse de deplacement par rapport au sol est de %.1f kilometres heure",i);
	}
}
