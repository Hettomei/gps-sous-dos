void RMC(char *trame2){
	char plop[20];
	float i;

	printf("\n*** TRAME RMC ***\n");
		
	virgule(trame2, 9, plop);  
	printf("\nLa date du fix est le %c%c/%c%c/%c%c",plop[0],plop[1],plop[2],plop[3],plop[4],plop[5]);
	
	virgule(trame2, 1, plop);
	printf("\nIl est: %c%ch %c%cmin %c%csec\n",plop[0],plop[1],plop[2],plop[3],plop[4],plop[5]);

	virgule(trame2, 3, plop);
	i=(plop[0]-48)*10+(plop[1]-48);
	printf("\nLa latitude est de %0.f degres ",i);
	
	i=(plop[2]-48)*10+(plop[3]-48)+(plop[5]-48)*0.1+(plop[6]-48)*0.01;
	printf("%.2f min ",i);
	
	virgule(trame2, 4, plop);
	if (plop[0]=='N'){ printf("Nord\n"); }
	if (plop[0]=='S'){ printf("Sud\n"); }
	if (plop[0]=='E'){ printf("Est\n"); }
	if (plop[0]=='W'){ printf("Ouest\n"); }

	virgule(trame2, 5, plop); 
	i=(plop[0]-48)*100+(plop[1]-48)*10+(plop[2]-48);
	printf("La longitude est de %.0f degres ",i);

	i=(plop[3]-48)*10+(plop[4]-48)+(plop[6]-48)*0.1+(plop[7]-48)*0.01;
	printf("%.2f min ",i);
	virgule(trame2, 6, plop);
	if (plop[0]=='N'){ printf("Nord\n"); }
	if (plop[0]=='S'){ printf("Sud\n"); }
	if (plop[0]=='E'){ printf("Est\n"); }
	if (plop[0]=='W'){ printf("Ouest\n"); }


	virgule(trame2, 7, plop);
	i = atof(plop);	
	printf("La vitesse sol est de %.2f Knots soit %.2f Km/h",i, i*1.852);
	
	if(virgule(trame2, 8, plop)==0){
		printf("\nAucun cap vrai detecte");
	}
	else{
		printf("\nLe cap vrai est de %s",plop);
	}
	
	if (virgule(trame2, 10, plop)==0){
		printf("\nPas de declinaison magnetique\n");
	}
	else{
		i=(plop[0]-48)*100+(plop[1]-48)*10+(plop[2]-48)+(plop[4]-48)*0.1;
		printf("\nLa declinaison magnetique et de %.1f\n",i);
	}
}