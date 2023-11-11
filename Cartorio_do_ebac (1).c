#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastaos usu�rios no sistema 
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("digite o CPF a ser cadastrado: ");//coletando informa��o de usu�rio 
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // respoponsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{  
    setlocale(LC_ALL,  "Portuguese"); //definindo a liguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser comsultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o aquivor, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��o do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuario n�o se encontra no sistema!.\n");
    	system("pause");
    	
	}
    
}

int main()
{ 
    int opcao=0; //Definindo variavios
	int loca=1;
	
	for(loca=1;loca=1;) 
	{
		system("cls");//resposavel por limpar a tela 
	
    
    
	setlocale(LC_ALL,  "Portuguese"); //definindo a liguagem 
	
	printf("### cart�rio da EBAC ###\n\n"); //inicio do menu
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");	
	printf("\t3 - Deletar nomes\n\n");
	printf("opcao: "); //fim do menu 
	
	scanf("%d", &opcao); //armazenando a escolha do usuario 
	
	system("cls");
	
	switch(opcao) //come�o da sele��o do menu 
	{
		case 1:
		registro();// chama de fun��es 
		break;
		
		case 2:
		consultar();
		break;
			
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa op��o � inv�lida!\n");
		system("pause");
		break; 
			
	}
    
  }
}
