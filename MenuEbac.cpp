#include <stdio.h> //biblioteca de comunuca��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das strings

int Registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usuarios
	scanf("%s", cpf); // refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por criar os valores das strings

    FILE *file; //Cria o arquivo e o "w" siginifica Escrever
	file = fopen(arquivo, "w");     //cria o arquivo
    fprintf(file,cpf);             // salva o valor da variavel
	fclose(file);                 // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado; ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int Consulta(){
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem

     //inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	 // fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	
	}
	
	while(fgets(conteudo,200,file) !=NULL);
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int Deletar(){
	
	char cpf[40];
	
	printf("Digite o CPF a ser Deletado ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario Deletado! \n");
			system("pause");
		
	}
	

}

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=10;)
	{
		system("cls");  //Responsavel por limpar a tela
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do Sistema\n\n");
	printf("op��o: ");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1: 
	     Registro();
	     break;
	     
	    case 2: 
	    Consulta();
	     break;
	     
	    case 3:
	    Deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o Sistema!\n");
	    return 0;
	    break;
	    
	    
	    default: printf("Essa op��o n�o esta disponivel \n");
	    system("pause");
	    break;
	    
	}
	
	
	}
  }
  

