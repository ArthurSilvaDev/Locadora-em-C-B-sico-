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
	// COLOCAR EM PORTUGUÊS
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
	
	
	// FIM INICIAÇÃO VARIÁVEIS
	
	// CADASTRAR GUERREIRO INICIAL E DRAGÃO
	strcpy(NomeGuerreiro[3],"Joao");
	strcpy(Reino[3],"Osorio");
	strcpy(Titulo[3], "Rei");
	
	strcpy(NomeDragao[1], "Pikachu");
	strcpy(ElementoDragao[1], "Terra");
	IdadeDragao[1] = 102;
	
	strcpy(NomeDragao[5], " Chicken Little");
	strcpy(ElementoDragao[5], "Ar");
	IdadeDragao[5] = 60;
	
	// INICIO CÓDIGO
	 
	int menu = 0;
	system("cls");
	do{
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - LISTAR GUERREIROS\n");
		printf("2  - CADASTRAR GUERREIRO PELO CÓDIGO\n");
		printf("3  - PESQUISAR GUERREIRO PELO NOME\n");
		printf("4  - EXCLUIR GUERREIRO PELO CÓDIGO\n");
		printf("5  - LISTAR DRAGÕES\n");
		printf("6  - CADASTRAR DRAGÃO PELO CÓDIGO\n");
		printf("7  - PESQUISAR DRAGÃO PELO NOME\n");
		printf("8  - EXCLUIR DRAGÃO PELO CÓDIGO\n");
		printf("9  - LISTAR DRAGÕES LOCADOS\n");
		printf("10 - LOCAR DRAGÃO\n");
		printf("11 - DEVOLVER DRAGÃO PELO CÓDIGO DO CLIENTE\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a opção desejada: ");
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
					printf("Já existe guerreiro cadastrado! \n");
					system("pause");
				}
			}
			else{
				printf("Codigo inválido\n");
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
				printf("O código do guerreiro é: %d \n", i);
				encontrado++;
			}
		}
		if (encontrado == 0){
			printf("Cadastro não encontrado!\n");
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
	 	
	 	
	 	printf("Digite o código do guerreiro que deseja excluir: ");
	 	scanf("%d", &i);
	 	
	 	int deletar;
	 	
	 	if (i<MAX_GUERREIRO && i>-1){
		 
		 	if(NomeGuerreiro[i][0] == '\0'){
		 		printf("Nenhum guerreiro cadastrado neste código!\n");
		 		system("pause");
			 }
			 else if(DragaoLocado[i] != -1){
			 	printf("Este guerreiro não pode ser excluido antes de devolver o dragão!\n");
			 	system("pause");
			 	
			 }
			 else{
			 	printf("Você selecionou o guerreiro %s\n", NomeGuerreiro[i]);
			 	printf("Digite 1 para confirmar a exclusão ou 2 para cancelar a exclusão: ");
			 	scanf("%d", &deletar);
			 	
			 		if (deletar == 1){
					   NomeGuerreiro[i][0] = '\0';
					   Reino[i][0] = '\0';
					   Titulo[i][0] = '\0';
				
					   				printf("Guerreiro deletado com sucesso!\n");
			 						system("pause");
					}
					else if (deletar == 2){
						 printf("Exclusão cancelada!\n");
						 system("pause");
					}
					else {
						 printf("Codigo invalido!\n");
				   		 system("pause");
			 }
		
			}
	

	}
	else{
		printf("Codigo inválido!\n");
		system("pause");
	}
		system("cls");
			
	} 
	
	// FIM MENU 4
	
	else if (menu == 5){ //LISTAR DRAGOES
		 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::  Dragões cadastrados  :::::::::::::::::\n");
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
  		printf(":::::::::::::  Cadastrar Dragões  ::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
			int codigo;
			printf("Digite o codigo onde deseja cadastrar: ");
			scanf("%d", &codigo);
			fflush(stdin);
			if (codigo < MAX_DRAGAO && codigo > -1){
				if (NomeDragao[codigo][0] == '\0'){
				
					printf("Digite o nome do dragão: ");
					scanf("%[^\n]s", NomeDragao[codigo]);
					fflush(stdin);
					printf("Digite a idade do dragão: ");
					scanf("%d", &IdadeDragao[codigo]);
					fflush(stdin);
					printf("Digite o elemento do dragao: ");
					scanf("%[^\n]s", ElementoDragao[codigo]);
					fflush(stdin);
	
					printf("DRAGÃO CADASTRADO!! \n");
					system("Pause");
				}
				else{
					printf("Já existe DRAGÃO cadastrado! \n");
					system("pause");
				}
			}
			else{
				printf("Codigo inválido\n");
				system("pause");
			}
			fflush(stdin);
			system ("cls");
		}
		
		else if (menu == 7){ //PESQUISAR DRAGÃO
		
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf(":::::::::::::  Pesquisar Dragão  :::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		
		
		
		char procurado[20];
		fflush(stdin);
		printf("Digite o nome do dragão: ");
		scanf("%[^\n]s", &procurado);
		int i;
		int encontrado =0;
		for(i=0; i < MAX_DRAGAO; i++){
			
			if(strcmp(procurado, NomeDragao[i]) == 0){
				printf("O código do Dragão é: %d \n", i);
				printf("Nome: %s \n", NomeDragao[i]);
				printf("Idade: %d \n", IdadeDragao[i]);
				printf("Elemento: %s \n",ElementoDragao[i]);
				encontrado++;
			}
		}
		if (encontrado == 0){
			printf("Cadastro não encontrado!\n");
		}
			
		system("pause");
		system("cls");
		}
		
	
		// ******************** INICIO MENU 8 *************
		else if(menu == 8){// EXCLUIR DRAGAO
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
  		printf("::::::::::::::  Excluir Dragão  ::::::::::::::::::::\n");
	 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		 
  		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  	  	 printf("::::::::::::::  Dragões cadastrados  :::::::::::::::\n");
  	  	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_DRAGAO; g++){
				if(NomeDragao[g][0] != '\0'){
						printf("CODIGO: %d    DRAGÃO: %s  IDADE: %d  ELEMENTO: %s \n\n", g, NomeDragao[g], IdadeDragao[g], ElementoDragao[g] );
			}
		}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 	
	 	
	 	printf("Digite o código do dragão que deseja excluir: ");
	 	scanf("%d", &i);
	 	
	 	int deletar;
	 	
	 	if (i<MAX_DRAGAO && i>-1){
		 
		 	if(NomeDragao[i][0] == '\0'){
		 		printf("Nenhum dragão cadastrado neste código!\n");
		 		system("pause");
			 }
			 else if(DragaoLocado[i] != -1){
			 	printf("Você não pode excluir um dragão que está locado!\n");
			 	system("pause");
			 }
			 else{
			 	printf("Você selecionou o Dragão %s\n", NomeDragao[i]);
			 	printf("Digite 1 para confirmar a exclusão ou 2 para cancelar a exclusão: ");
			 	scanf("%d", &deletar);
			 	
			 		if (deletar == 1){
					   NomeDragao[i][0] = '\0';
					   IdadeDragao[i] = -1;
					   ElementoDragao[i][0] = '\0';
				
					   				printf("Dragão deletado com sucesso!\n");
			 						system("pause");
					}
					else if (deletar == 2){
						 printf("Exclusão cancelada!\n");
						 system("pause");
					}
					else {
						 printf("Codigo invalido!\n");
				   		 system("pause");
			 }
		
			}
	

	}
	else{
		printf("Codigo inválido!\n");
		system("pause");
	}
		system("cls");
			
	} 
	else if (menu == 9){ //LISTAR DRAGOES LOCADOS 
		 	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::::  Dragões locados  :::::::::::::::::::\n");
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
	
	else if (menu == 10){// LOCAR DRAGÃO
	int g = 0;
		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf("::::::::::::::: Locar Dragões  :::::::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		 
		 
	int guerreirocadastro;
		printf("Digite o código do guerreiro: ");
		scanf("%d", &guerreirocadastro);
		
		if(( guerreirocadastro >= 0) && (guerreirocadastro < MAX_GUERREIRO) && (NomeGuerreiro[guerreirocadastro][0] != '\0')){
			if (DragaoLocado[guerreirocadastro] != -1){
				printf("Você já tem um dragão locado!!");
				system("pause");
			}
			else{
		 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
  	  	 printf("::::::::::::::  Dragões cadastrados  :::::::::::::::\n");
  	  	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
			int g;
			for (g=0; g < MAX_DRAGAO; g++){
				if(NomeDragao[g][0] != '\0'){
					
						printf("CODIGO: %d    DRAGÃO: %s  IDADE: %d  ELEMENTO: %s \n\n", g, NomeDragao[g], IdadeDragao[g], ElementoDragao[g] );
			}
		}
			printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			
			int locar;
			printf("Digite o código que deseja locar: ");
			scanf("%d", &locar);
			if(locar < MAX_DRAGAO && locar > -1){
			
			int encontrado = 0;
			for(i=0; i < MAX_GUERREIRO; i++){
					 if(locar == DragaoLocado[i]){
				printf("Este dragão já está locado");
				encontrado++;
				system("pause");
			}
			}
		 	if (encontrado == 0){
		 		fflush(stdin);
		 		printf("Digite a data de devolução: ");
		 		scanf("%[^\n]s", DataEntrega[guerreirocadastro]);
		 		DragaoLocado[guerreirocadastro] = locar;
		 	
		 	
			
			}
		
		
		}
		system("cls");
	}
	
	
		
					  }
		}
		
		// FIM DO MENU 10
		
		
		else if (menu == 11){ //DEVOLVER DRAGÕES
			
			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		   printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		   printf(":::::::::::::: Devolver Dragões  :::::::::::::::::::\n");
		   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		   
		   
			int i;
			for (i = 0; i < MAX_GUERREIRO; i++){
				if (NomeGuerreiro[i][0] != '\0'){
						printf("CODIGO: %d    GUERREIRO: %s  REINO: %s  TITULO: %s \n\n", i, NomeGuerreiro[i], Reino[i], Titulo[i] );
				}
			}
		printf("Digite o código do guerreiro que deseja devolver o dragão: ");
		scanf("%d", &i);
		
		if ((i < 0) || (i > MAX_DRAGAO)){
			printf("Codigo invalido\n\n");
		}
		else if(NomeGuerreiro[i][0] == '\0'){
			printf("Guerrreiro inexistente! \n\n");
		}
		else if(DragaoLocado[i] == -1){
			printf("Este guerreiro não tem um dragão locado!\n\n");
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
