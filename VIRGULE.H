char virgule(char *trame2, int nombre, char *tableau){

	unsigned int i;
	int p=0;
	int j=0;
	char k=0; // <- si probleme de trame ou de virgule
	
	*(tableau+j)='\0';
	for(i=0;i<strlen(trame2);i++){
		if (*(trame2+i)==','){
			p++;
		}
		
		if (p==nombre){
			i++; //on avance de la virgule
			if (*(trame2+i)==','){ //si apres la virgule on a une virgule
				k=0;              //rien ne sera marqué
				*(tableau+j)='\0';
				break;
			}
			while(*(trame2+i)!=',' && i<strlen(trame2)){
					*(tableau+j)=*(trame2+i);
					i++;
					j++;
			}
			k=1;
			*(tableau+j)='\0';
			break;
		}
	}
	return k; // <- si k= 1 then tableau en %s marqué qqchose, si k=0 -> rien de marqué
}