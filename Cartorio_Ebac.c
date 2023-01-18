#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o na memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h>

int registro() //Fun��o Responsavel por Cria��o dos Usuarios
{
	//Inicio Cria��o de Variaveis
	char arquivo[40];
	char cpf[40];
	char nomes[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do Usuario
	scanf("%s", cpf);//%s refere-se a strings
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar o valor das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o Arquivo/"W" para escrever no arquivo
	fprintf(file,cpf); //Salva o Valor da Variavel
	fclose(file); //Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, ",");
	fclose (file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nomes);
	
	file = fopen(arquivo, "a");
	fprintf(file,nomes);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose (file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	printf("O CPF foi cadastrado! \n");
	
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose (file);
	
	system("pause");
	
}
int consulta() //Fun��o responsavel por consultar os usuarios
{
	setlocale(LC_ALL, "Portuguese");
	
	//Variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado : "); 
	scanf("%s",cpf); //Coletando a primarykey
	
	FILE *file;
	file = fopen(cpf, "r"); // Lendo o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o arquivo!");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	fclose(file);
	
	system("pause");
}
int deletar() //Fun��o Responsavel por Deletar Usuarios
{
	setlocale(LC_ALL, "Portuguese");
	
	//Variaveis
	char cpf[40];
	
	printf("Digite o CPF quer voc� quer deletar? ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("O CPF n�o se encontra no sistema! \n");
		system("pause");
		fclose(file);
	}
	if(file != NULL)
	{
		fclose(file);
		remove(cpf);
		printf("O CPF foi deletado com sucesso! \n ");
		system("pause");
	}
} 

//Fim das Fun��es

int main() //Fun��o Principal a Primeira a Rodar
{

	int opcao=0; //Definindo variaveis
	int laco=1;

	for(laco=1; laco=1;) { //Inicio do Looping

		system("cls"); //Limpa a Tela

		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem

		printf("\tCart�rio da Ebac \n\n"); //Inicio do Menu/Titulo do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n\n");
		printf("\t2 - Consultar Nomes\n\n");
		printf("\t3 - Deletar Nomes\n\n\n");
		printf("Op��o: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usuario

		system("cls"); //Limpar tela

		switch(opcao) //Inicio da Sele��o / Chama as Fun��es
		{ 
			case 1:
				registro();
				break;

			case 2:
				consulta();
				break;

			case 3:
			deletar();
				break;

			default:
				printf("Esta op��o n�o esta disponivel!\n\n");
				system("pause");
				break;
		} //Fim da Sele��o
	} //Fim do Looping
}

