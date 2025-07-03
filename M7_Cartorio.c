#include <stdio.h> //biblioteca de comunica��o do usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de loca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int main() //Fun��o principal
{
//Definindo as vari�veis
int opcao=0;
int x=1;
	
for(x=1;x=1;) //Repeti��o para voltar do in�cio do menu
  {
		
	system("cls"); //Respons�vel por limpar a tela
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
//In�cio do menu
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Escolha a op��o desejada do menu\n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n");
	printf("Op��o: "); 
//Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	system("cls"); //Respons�vel por limpar a tela
	
//In�cio da sele��o do menu
	switch(opcao) 
	{
		case 1:
		registro(); //Chamada de fun��es
		system("pause");
		break;
		
		case 2:
		consulta();
		system("pause");
		break;
		
		case 3:
		deletar();
		system("pause");
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel! \n");
		system("pause");
		break;
	} //Fim da sele��o do menu
  }
}

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	printf("* Voc� escolheu registar nomes!\n\n");
	setlocale(LC_ALL, "Portuguese");
	
//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //%strings
	
//Fun��o
	strcpy(arquivo, cpf); //strcpy = string copy. Respons�vel por copiar os valores das strings
	
//Criando o arquivo do banco de dados
	FILE *file; //O arquivo
	file = fopen(arquivo, "w"); //w = write
	fprintf(file,cpf); //printf dentro do arquivo, o file. salvo o valor da vari�vel
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo j� salvo do sistema. a = atualiza��o
	fprintf(file,",\t"); //Separa��o do texto por , e espa�o
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\t");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\t");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\t");
	fclose(file);

	system("pause"); //"Paralisa" o texto
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	printf("* Voc� escolheu o consultar nomes!\n");
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //Consulta pelo cpf cadastrado do usu�rio
	char conteudo[40];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //r = read
	
	if(file == NULL) // == compara��o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto busca o conte�do no arquivo de 200 caracteres que est�o dentro do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	printf("* Voc� escolheu deletar nomes!\n");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se o arquivo n�o for localizado, o sistema n�o vai ler
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}
