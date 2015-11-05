void GSA(char *trame2){
	int i;
	int j=0;
	char plop[20];
	printf("\n*** TRAME GSA ***\n\n");
	
	virgule(trame2, 2, plop);
	if (plop[0]=='1'){ printf("Information peu fiable car peu de satellites reçu.\n"); }
	else if (plop[0]=='2'){ printf("Informations fiable.\n"); }
	else if (plop[0]=='3'){ printf("Informations très fiable, suffisament de satellites.\n"); }
	
	printf("Id des satellites capte :\n");
	for (i = 1 ;i < 12;i++){
		if(virgule(trame2,i+3, plop) != 0){
			printf("%s, ",plop);
			j++;
			}
	}
	if (j==0){printf("aucun Id reçu !\n\n");}
	
}