void GSV(char *trame2){
	// POSSIBILITER DE METTRE DANS UNE BOUCLE POUR NE PAS SE REPETER !!
	char plop[20];
	float i;
	virgule(trame2, 1, plop);
	printf("\n*** TRAME GSV ***\n");
	printf("\nIl y a %s trames GSV avec des donnes completes\n",plop);

	if (virgule(trame2, 3, plop)==0){
		printf("Il n'y a pas de satellites visibles\n"); // si erreur -> pas de sattelite
	}
	else{
		virgule(trame2, 3, plop);

		i = atof(plop);
		printf("Il y a %.0f satellite visible\n", i);
		

		virgule(trame2, 4, plop);
		i = atof(plop);
		printf("Le numero d'identification du premier satellite est %.0f\n",i);

		virgule(trame2, 5, plop);
		i = atof(plop);
		printf("L'elevation est de %0.f degres\n",i);

		virgule(trame2, 6, plop);
		i = atof(plop);
		printf("Son azimuth est %.0f\n",i);

		virgule(trame2, 7, plop);

		if (plop[0]=='*'){
		 printf("Il n'y pas d'autre satellites visibles\n");
		 //si 1 seul sattelite on quitte car pas d'autre a afficher
		}
		else{
			virgule(trame2, 8, plop);
		i = atof(plop);
			printf("Le numero d'identification du deuxieme satellite est %.0f\n",i);

			virgule(trame2, 9, plop);
		i = atof(plop);
			printf("L'elevation est de %.0f degres\n",i);

			virgule(trame2, 10, plop);
		i = atof(plop);
			printf("Son azimut est %.0f\n",i);
		}

	
		if (virgule(trame2, 11, plop)==0){
			printf("Il n'y pas d'autres satellites visibles\n");
		}
		else{
			virgule(trame2, 12, plop); 
		i = atof(plop);
			printf("Le numero d'identification du troisieme satellite est %.0f\n",i);

			virgule(trame2, 13, plop);
		i = atof(plop);
			printf("L'elevation est de %.0f degres\n",i);

			virgule(trame2, 14, plop);
		i = atof(plop);
			printf("Son azimut est %.0f\n",i);
		}

		
		if (virgule(trame2, 15, plop)==0){
			printf("Il n'y pas d'autres satellites visibles\n");
		}

		else{
			virgule(trame2, 16, plop); 
		i = atof(plop);
			printf("Le numero d'identification du deuxieme satellite est %.0f\n",i);

			virgule(trame2, 17, plop);
		i = atof(plop);
			printf("L'elevation est de %.0f degres\n",i);

			virgule(trame2, 18, plop);
					i = atof(plop);
			printf("Son azimut est %.0f\n",i);
		}

	}

}