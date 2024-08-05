#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar da string

int registro()  // função responsável por cadastrar os usuários no sistema
{
    // início de criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim de criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // responsável por copiar os valores da string

    FILE *file;
    file = fopen(arquivo, "w"); // cria o arquivo (o w significa escrever)
    fprintf(file, cpf); // salva o valor da variável
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

int consulta() // função responsável por consultar os usuários no sistema
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
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
        return 1;
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    system("pause");

    return 0;
}

int deletar() // função responsável por deletar os usuários no sistema
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: "); // coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string

    if (remove(cpf) == 0) { // Remove o arquivo
        printf("Usuário deletado com sucesso!\n"); // Confirmação de deleção
    } else {
        printf("Erro ao deletar o usuário.\n"); // Mensagem de erro ao deletar
    }

    // Verificar se o arquivo ainda existe
    FILE *file = fopen(cpf, "r"); // Abre o arquivo para leitura (o r significa ler)
    if (file == NULL) { // Verificação se o arquivo foi aberto com sucesso
        printf("O usuário não se encontra no sistema!\n"); // Mensagem de arquivo não encontrado
    } else {
        fclose(file); // Fecha o arquivo
    }

    system("pause"); // Pausa o sistema para que o usuário veja a mensagem

    return 0;
}

int main() // função principal do programa
{
    int opcao = 0; // Definindo variáveis
    int x = 1;

    for (x = 1; x == 1;)
    {
        system("cls"); // responsável por limpar a tela

        setlocale(LC_ALL, "portuguese"); // Definindo linguagem

        printf("### Cartório da EBAC ###\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - registrar nomes\n");
        printf("\t2 - consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

        system("cls"); // Início da seleção

        switch (opcao)
        {
            case 1:
                registro(); // Chama a função de registro
                break;

            case 2:
                consulta(); // Chama a função de consulta
                break;

            case 3:
                deletar(); // Chama a função de deleção
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

