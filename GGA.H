void GGA(char *trame2){

	char plop[20];
	float i;
	
	printf("\n*** TRAME GGA ***\n");
	virgule(trame2, 1, plop);
	printf("\nIl est: %c%ch %c%cmin %c%c.%csec\n",plop[0],plop[1],plop[2],plop[3],plop[4],plop[5],plop[7]);
	
	virgule(trame2, 2, plop);
	i=(plop[0]-48)*10+(plop[1]-48);
	printf("\nLa latitude est de %0.f degres ",i);

	i=(plop[2]-48)*10+(plop[3]-48)+(plop[5]-48)*0.1+(plop[6]-48)*0.01+(plop[7]-48)*0.001;
	printf("%.3f' ",i);
	virgule(trame2, 3, plop);
	if (plop[0]=='N'){ printf("Nord\n"); }
	if (plop[0]=='S'){ printf("Sud\n"); }
	if (plop[0]=='E'){ printf("Est\n"); }
	if (plop[0]=='W'){ printf("Ouest\n"); }
	
	virgule(trame2, 4, plop);
	i=(plop[0]-48)*100+(plop[1]-48)*10+(plop[2]-48);
	printf("La longitude est de %0.f degres ",i);

	i=(plop[3]-48)*10+(plop[4]-48)+(plop[6]-48)*0.1+(plop[7]-48)*0.01+(plop[8]-48)*0.001;
	printf("%.3f' ",i);
	
	virgule(trame2, 5, plop);
	if (plop[0]=='N'){ printf("Nord\n"); }
	if (plop[0]=='S'){ printf("Sud\n"); }
	if (plop[0]=='E'){ printf("Est\n"); }
	if (plop[0]=='W'){ printf("Ouest\n"); }
	
	virgule(trame2, 7, plop);
	i = atof(plop);
	printf("Satellites en poursuite : %.0f\n" , i);

	virgule(trame2, 9, plop);
	if (plop[0] != '0') {
		i = atof(plop);
		printf("%s Altitude : %.2f\n",plop,i);
	}
	else{
		printf("Aucune altitude détectée\n\n");
	}
}