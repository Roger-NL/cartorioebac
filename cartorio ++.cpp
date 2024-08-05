#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar da string

int registro()  // fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // in�cio de cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim de cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // respons�vel por copiar os valores da string

    FILE *file;
    file = fopen(arquivo, "w"); // cria o arquivo (o w significa escrever)
    fprintf(file, cpf); // salva o valor da vari�vel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");

    return 0;
}

int consulta() // fun��o respons�vel por consultar os usu�rios no sistema
{
    setlocale(LC_ALL, "portuguese"); // Definindo linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
        return 1;
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    system("pause");

    return 0;
}

int deletar() // fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: "); // coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string

    if (remove(cpf) == 0) { // Remove o arquivo
        printf("Usu�rio deletado com sucesso!\n"); // Confirma��o de dele��o
    } else {
        printf("Erro ao deletar o usu�rio.\n"); // Mensagem de erro ao deletar
    }

    // Verificar se o arquivo ainda existe
    FILE *file = fopen(cpf, "r"); // Abre o arquivo para leitura (o r significa ler)
    if (file == NULL) { // Verifica��o se o arquivo foi aberto com sucesso
        printf("O usu�rio n�o se encontra no sistema!\n"); // Mensagem de arquivo n�o encontrado
    } else {
        fclose(file); // Fecha o arquivo
    }

    system("pause"); // Pausa o sistema para que o usu�rio veja a mensagem

    return 0;
}

int main() // fun��o principal do programa
{
    int opcao = 0; // Definindo vari�veis
    int x = 1;

    for (x = 1; x == 1;)
    {
        system("cls"); // respons�vel por limpar a tela

        setlocale(LC_ALL, "portuguese"); // Definindo linguagem

        printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - registrar nomes\n");
        printf("\t2 - consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usu�rio

        system("cls"); // In�cio da sele��o

        switch (opcao)
        {
            case 1:
                registro(); // Chama a fun��o de registro
                break;

            case 2:
                consulta(); // Chama a fun��o de consulta
                break;

            case 3:
                deletar(); // Chama a fun��o de dele��o
                break;
            
            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;

            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

