#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_GUERREIRO 5
#define MAX_DRAGAO 6

char NomeGuerreiro[MAX_GUERREIRO][20];
char Reino[MAX_GUERREIRO][20];
char Titulo[MAX_GUERREIRO][20];
int DragaoLocado[MAX_GUERREIRO];
char DataEntrega[MAX_GUERREIRO][20];

char NomeDragao[MAX_DRAGAO][20];
int IdadeDragao[MAX_DRAGAO];
char ElementoDragao[MAX_DRAGAO][20];

int main(int argc, char *argv[]) {
	// COLOCAR EM PORTUGU�S
	setlocale(LC_ALL, "Portuguese");
	
	// INICIAR AS VARIAVEIS:
	int i;
	for (i = 0; i < MAX_GUERREIRO; i++)
		{
		NomeGuerreiro[i][0] = '\0';
		Reino[i][0] = '\0';
		Titulo[i][0] = '\0';
		DataEntrega[i][0] = '\0';
		DragaoLocado[i] = -1;
		}
		
	for (i = 0; i < MAX_DRAGAO; i++){
		NomeDragao[i][0] = '\0';
		ElementoDragao[i][0] = '\0';
		IdadeDragao[i] = -1;
		}
	
	
	// FIM INICIA��O VARI�VEIS
	
	// CADASTRAR GUERREIRO INICIAL E DRAG�O
	strcpy(NomeGuerreiro[3],"Joao");
	strcpy(Reino[3],"Osorio");
	strcpy(Titulo[3], "Rei");
	
	strcpy(NomeDragao[1], "Pikachu");
	strcpy(ElementoDragao[1], "Terra");
	IdadeDragao[1] = 102;
	
	strcpy(NomeDragao[5], " Chicken Little");
	strcpy(ElementoDragao[5], "Ar");
	IdadeDragao[5] = 60;
	
	// INICIO C�DIGO
	 
	int menu = 0;
	system("cls");
	do{
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - LISTAR GUERREIROS\n");
		printf("2  - CADASTRAR GUERREIRO PELO C�DIGO\n");
		printf("3  - PESQUISAR GUERREIRO PELO NOME\n");
		printf("4  - EXCLUIR GUERREIRO PELO C�DIGO\n");
		printf("5  - LISTAR DRAG�ES\n");
		printf("6  - CADASTRAR DRAG�O PELO C�DIGO\n");
		printf("7  - PESQUISAR DRAG�O PELO NOME\n");
		printf("8  - EXCLUIR DRAG�O PELO C�DIGO\n");
		printf("9  - LISTAR DRAG�ES LOCADOS\n");
		printf("10 - LOCAR DRAG�O\n");
		printf("11 - DEVOLVER DRAG�O PELO C�DIGO DO CLIENTE\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a op��o desejada: ");
		scanf("%i", &menu);
		system ("cls");
		
		
			// ******************** INICIO MENU 1 ************* 
		if (menu == 1){ //LISTAR GUERREIROS
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf(":::::::::::  Guerreiros cadastrados  :::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_GUERREIRO; g++){
				if(NomeGuerreiro[g][0] != '\0'){
						printf("CODIGO: %d    GUERREIRO: %s  REINO: %s  TITULO: %s \n\n", g, NomeGuerreiro[g], Reino[g], Titulo[g] );
			}
				}
			
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			system("pause");
			
			system ("cls");
		}
		
			// ******************** INICIO MENU 2 ************* 
		
		else if (menu == 2){ // CADASTRAR GUERREIROS
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf("::::::::::::  Cadastrar Guerreiro  :::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
			int codigo;
			printf("Digite o codigo onde deseja cadastrar: ");
			scanf("%d", &codigo);
			fflush(stdin);
			if (codigo < MAX_GUERREIRO && codigo > -1){
				if (NomeGuerreiro[codigo][0] == '\0'){
				
					printf("Digite o nome do guerreiro: ");
					scanf("%[^\n]s", NomeGuerreiro[codigo]);
					fflush(stdin);
					printf("Digite o reino do guerreiro: ");
					scanf("%[^\n]s", Reino[codigo]);
					fflush(stdin);
					printf("Digite o titulo do guerreiro: ");
					scanf("%[^\n]s", Titulo[codigo]);
					fflush(stdin);
	
					printf("GUERREIRO CADASTRADO!! \n");
					system("pause");
				}
				else{
					printf("J� existe guerreiro cadastrado! \n");
					system("pause");
				}
			}
			else{
				printf("Codigo inv�lido\n");
				system("pause");
			}
			fflush(stdin);
			system ("cls");
		}
		
		
			// ******************** INICIO MENU 3 ************* 
			
			
		else if (menu == 3){ //PESQUISAR GUERREIRO
		
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf("::::::::::::  Pesquisar Guerreiro  :::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
		
		
		char procurado[20];
		fflush(stdin);
		printf("Digite o nome do guerreiro: ");
		scanf("%[^\n]s", &procurado);
		int i;
		int encontrado =0;
		for(i=0; i < MAX_GUERREIRO; i++){
			
			if(strcmp(procurado, NomeGuerreiro[i]) == 0){
				printf("O c�digo do guerreiro �: %d \n", i);
				encontrado++;
			}
		}
		if (encontrado == 0){
			printf("Cadastro n�o encontrado!\n");
		}
			
		system("pause");
		system("cls");
		}
		
		// ******************** INICIO MENU 4 *************
		else if(menu == 4){// EXCLUIR GUERREIRO
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf("::::::::::::::  Excluir Guerreiro  :::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		 
  		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  	  	 printf(":::::::::::  Guerreiros cadastrados  :::::::::::::::\n");
  	  	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_GUERREIRO; g++){
				if(NomeGuerreiro[g][0] != '\0'){
						printf("CODIGO: %d    GUERREIRO: %s  REINO: %s  TITULO: %s \n\n", g, NomeGuerreiro[g], Reino[g], Titulo[g] );
			}
		}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 	
	 	
	 	printf("Digite o c�digo do guerreiro que deseja excluir: ");
	 	scanf("%d", &i);
	 	
	 	int deletar;
	 	
	 	if (i<MAX_GUERREIRO && i>-1){
		 
		 	if(NomeGuerreiro[i][0] == '\0'){
		 		printf("Nenhum guerreiro cadastrado neste c�digo!\n");
		 		system("pause");
			 }
			 else if(DragaoLocado[i] != -1){
			 	printf("Este guerreiro n�o pode ser excluido antes de devolver o drag�o!\n");
			 	system("pause");
			 	
			 }
			 else{
			 	printf("Voc� selecionou o guerreiro %s\n", NomeGuerreiro[i]);
			 	printf("Digite 1 para confirmar a exclus�o ou 2 para cancelar a exclus�o: ");
			 	scanf("%d", &deletar);
			 	
			 		if (deletar == 1){
					   NomeGuerreiro[i][0] = '\0';
					   Reino[i][0] = '\0';
					   Titulo[i][0] = '\0';
				
					   				printf("Guerreiro deletado com sucesso!\n");
			 						system("pause");
					}
					else if (deletar == 2){
						 printf("Exclus�o cancelada!\n");
						 system("pause");
					}
					else {
						 printf("Codigo invalido!\n");
				   		 system("pause");
			 }
		
			}
	

	}
	else{
		printf("Codigo inv�lido!\n");
		system("pause");
	}
		system("cls");
			
	} 
	
	// FIM MENU 4
	
	else if (menu == 5){ //LISTAR DRAGOES
		 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::  Drag�es cadastrados  :::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_DRAGAO; g++){
				if(NomeDragao[g][0] != '\0'){
			
				printf("CODIGO: %d    DRAGAO: %s  IDADE: %d  ELEMENTO: %s \n\n", g, NomeDragao[g], IdadeDragao[g], ElementoDragao[g] );
					}
			}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			system("pause");
			
			system ("cls");
	}
	else if (menu == 6){ // CADASTRAR DRAGOES
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf(":::::::::::::  Cadastrar Drag�es  ::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
			int codigo;
			printf("Digite o codigo onde deseja cadastrar: ");
			scanf("%d", &codigo);
			fflush(stdin);
			if (codigo < MAX_DRAGAO && codigo > -1){
				if (NomeDragao[codigo][0] == '\0'){
				
					printf("Digite o nome do drag�o: ");
					scanf("%[^\n]s", NomeDragao[codigo]);
					fflush(stdin);
					printf("Digite a idade do drag�o: ");
					scanf("%d", &IdadeDragao[codigo]);
					fflush(stdin);
					printf("Digite o elemento do dragao: ");
					scanf("%[^\n]s", ElementoDragao[codigo]);
					fflush(stdin);
	
					printf("DRAG�O CADASTRADO!! \n");
					system("Pause");
				}
				else{
					printf("J� existe DRAG�O cadastrado! \n");
					system("pause");
				}
			}
			else{
				printf("Codigo inv�lido\n");
				system("pause");
			}
			fflush(stdin);
			system ("cls");
		}
		
		else if (menu == 7){ //PESQUISAR DRAG�O
		
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf(":::::::::::::  Pesquisar Drag�o  :::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
		
		
		char procurado[20];
		fflush(stdin);
		printf("Digite o nome do drag�o: ");
		scanf("%[^\n]s", &procurado);
		int i;
		int encontrado =0;
		for(i=0; i < MAX_DRAGAO; i++){
			
			if(strcmp(procurado, NomeDragao[i]) == 0){
				printf("O c�digo do Drag�o �: %d \n", i);
				printf("Nome: %s \n", NomeDragao[i]);
				printf("Idade: %d \n", IdadeDragao[i]);
				printf("Elemento: %s \n",ElementoDragao[i]);
				encontrado++;
			}
		}
		if (encontrado == 0){
			printf("Cadastro n�o encontrado!\n");
		}
			
		system("pause");
		system("cls");
		}
		
	
		// ******************** INICIO MENU 8 *************
		else if(menu == 8){// EXCLUIR DRAGAO
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf("::::::::::::::  Excluir Drag�o  ::::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		 
  		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  	  	 printf("::::::::::::::  Drag�es cadastrados  :::::::::::::::\n");
  	  	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_DRAGAO; g++){
				if(NomeDragao[g][0] != '\0'){
						printf("CODIGO: %d    DRAG�O: %s  IDADE: %d  ELEMENTO: %s \n\n", g, NomeDragao[g], IdadeDragao[g], ElementoDragao[g] );
			}
		}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 	
	 	
	 	printf("Digite o c�digo do drag�o que deseja excluir: ");
	 	scanf("%d", &i);
	 	
	 	int deletar;
	 	
	 	if (i<MAX_DRAGAO && i>-1){
		 
		 	if(NomeDragao[i][0] == '\0'){
		 		printf("Nenhum drag�o cadastrado neste c�digo!\n");
		 		system("pause");
			 }
			 else if(DragaoLocado[i] != -1){
			 	printf("Voc� n�o pode excluir um drag�o que est� locado!\n");
			 	system("pause");
			 }
			 else{
			 	printf("Voc� selecionou o Drag�o %s\n", NomeDragao[i]);
			 	printf("Digite 1 para confirmar a exclus�o ou 2 para cancelar a exclus�o: ");
			 	scanf("%d", &deletar);
			 	
			 		if (deletar == 1){
					   NomeDragao[i][0] = '\0';
					   IdadeDragao[i] = -1;
					   ElementoDragao[i][0] = '\0';
				
					   				printf("Drag�o deletado com sucesso!\n");
			 						system("pause");
					}
					else if (deletar == 2){
						 printf("Exclus�o cancelada!\n");
						 system("pause");
					}
					else {
						 printf("Codigo invalido!\n");
				   		 system("pause");
			 }
		
			}
	

	}
	else{
		printf("Codigo inv�lido!\n");
		system("pause");
	}
		system("cls");
			
	} 
	else if (menu == 9){ //LISTAR DRAGOES LOCADOS 
		 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::::  Drag�es locados  :::::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_GUERREIRO; g++){
				if(DragaoLocado[g] >=0){
			
				printf("CODIGO: %d    DRAGAO: %s  IDADE: %d  ELEMENTO: %s LOCADO POR: %s ENTREGA: %s \n\n", DragaoLocado[g], NomeDragao[DragaoLocado[g]], IdadeDragao[DragaoLocado[g]], ElementoDragao[DragaoLocado[g]], NomeGuerreiro[g], DataEntrega[g]);
					}
			}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			system("pause");
			
			system ("cls");
	
			}
	
	else if (menu == 10){// LOCAR DRAG�O
	int g = 0;
		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::::: Locar Drag�es  :::::::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		 
		 
	int guerreirocadastro;
		printf("Digite o c�digo do guerreiro: ");
		scanf("%d", &guerreirocadastro);
		
		if(( guerreirocadastro >= 0) && (guerreirocadastro < MAX_GUERREIRO) && (NomeGuerreiro[guerreirocadastro][0] != '\0')){
			if (DragaoLocado[guerreirocadastro] != -1){
				printf("Voc� j� tem um drag�o locado!!");
				system("pause");
			}
			else{
		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  	  	 printf("::::::::::::::  Drag�es cadastrados  :::::::::::::::\n");
  	  	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_DRAGAO; g++){
				if(NomeDragao[g][0] != '\0'){
					
						printf("CODIGO: %d    DRAG�O: %s  IDADE: %d  ELEMENTO: %s \n\n", g, NomeDragao[g], IdadeDragao[g], ElementoDragao[g] );
			}
		}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			
			int locar;
			printf("Digite o c�digo que deseja locar: ");
			scanf("%d", &locar);
			if(locar < MAX_DRAGAO && locar > -1){
			
			int encontrado = 0;
			for(i=0; i < MAX_GUERREIRO; i++){
					 if(locar == DragaoLocado[i]){
				printf("Este drag�o j� est� locado");
				encontrado++;
				system("pause");
			}
			}
		 	if (encontrado == 0){
		 		fflush(stdin);
		 		printf("Digite a data de devolu��o: ");
		 		scanf("%[^\n]s", DataEntrega[guerreirocadastro]);
		 		DragaoLocado[guerreirocadastro] = locar;
		 	
		 	
			
			}
		
		
		}
		system("cls");
	}
	
	
		
					  }
		}
		
		// FIM DO MENU 10
		
		
		else if (menu == 11){ //DEVOLVER DRAG�ES
			
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf(":::::::::::::: Devolver Drag�es  :::::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		   
		   
			int i;
			for (i = 0; i < MAX_GUERREIRO; i++){
				if (NomeGuerreiro[i][0] != '\0'){
						printf("CODIGO: %d    GUERREIRO: %s  REINO: %s  TITULO: %s \n\n", i, NomeGuerreiro[i], Reino[i], Titulo[i] );
				}
			}
		printf("Digite o c�digo do guerreiro que deseja devolver o drag�o: ");
		scanf("%d", &i);
		
		if ((i < 0) || (i > MAX_DRAGAO)){
			printf("Codigo invalido\n\n");
		}
		else if(NomeGuerreiro[i][0] == '\0'){
			printf("Guerrreiro inexistente! \n\n");
		}
		else if(DragaoLocado[i] == -1){
			printf("Este guerreiro n�o tem um drag�o locado!\n\n");
		}
		else {
			DataEntrega[i][0] = '\0';
			DragaoLocado[i] = -1;
			printf("Dragao devolvido com sucesso!! \n\n");
		}
		system("pause");
		system("cls");
			
			
		}

	}while(menu != 0);
	
	
	
	
	return 0;
}
