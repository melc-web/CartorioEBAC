#include <stdio.h> //biblioteca de comunicação do usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de locação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

int main() //Função principal
{
//Definindo as variáveis
int opcao=0;
int x=1;
	
for(x=1;x=1;) //Repetição para voltar do início do menu
  {
		
	system("cls"); //Responsável por limpar a tela
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
//Início do menu
	printf("### Cartório da EBAC ###\n\n");
	printf("Escolha a opção desejada do menu\n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n");
	printf("Opção: "); 
//Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	system("cls"); //Responsável por limpar a tela
	
//Início da seleção do menu
	switch(opcao) 
	{
		case 1:
		registro(); //Chamada de funções
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
		printf("Essa opção não está disponível! \n");
		system("pause");
		break;
	} //Fim da seleção do menu
  }
}

int registro() //Função responsável por cadastrar os usuários no sistema
{
	printf("* Você escolheu registar nomes!\n\n");
	setlocale(LC_ALL, "Portuguese");
	
//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",cpf); //%strings
	
//Função
	strcpy(arquivo, cpf); //strcpy = string copy. Responsável por copiar os valores das strings
	
//Criando o arquivo do banco de dados
	FILE *file; //O arquivo
	file = fopen(arquivo, "w"); //w = write
	fprintf(file,cpf); //printf dentro do arquivo, o file. salvo o valor da variável
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo já salvo do sistema. a = atualização
	fprintf(file,",\t"); //Separação do texto por , e espaço
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

int consulta() //Função responsável por consultar os usuários no sistema
{
	printf("* Você escolheu o consultar nomes!\n");
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //Consulta pelo cpf cadastrado do usuário
	char conteudo[40];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //r = read
	
	if(file == NULL) // == comparação
	{
		printf("Não foi possível abrir o arquivo, não foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto busca o conteúdo no arquivo de 200 caracteres que estão dentro do arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() //Função responsável por deletar os usuários no sistema
{
	printf("* Você escolheu deletar nomes!\n");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se o arquivo não for localizado, o sistema não vai ler
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}
