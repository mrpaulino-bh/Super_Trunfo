#include <stdio.h>      // Biblioteca para entrada e sa�da padr�o (printf, scanf)
#include <locale.h>     // Biblioteca para configura��es regionais (idioma, formata��o)
#include <string.h>     // Biblioteca para manipula��o de strings (strings)
#include <ctype.h>      // Biblioteca para fun��es de teste de caracteres (toupper)

// Fun��o para limpar o buffer de entrada do teclado
void limpar_buffer() {
    int caractere;
    // L� caracteres do buffer at� encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    while ((caractere = getchar()) != '\n' && caractere != EOF);
}

// Fun��o para remover a quebra de linha ('\n') que a fun��o fgets pode adicionar ao final de uma string
void remover_newline(char *string) {
    // Procura a primeira ocorr�ncia do caractere de nova linha na string
    size_t posicao_newline = strcspn(string, "\n");
    // Se a nova linha for encontrada (a posi��o n�o for o comprimento total da string)
    if (posicao_newline < strlen(string)) {
        // Substitui a nova linha por um caractere nulo ('\0'), que marca o fim da string
        string[posicao_newline] = '\0';
    }
}

// Defini��o da estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado;             // Uma �nica letra (A-H) representando o estado
    char codigo[4];          // C�digo da carta (ex: A01, B03) - 3 caracteres + '\0'
    char nome_cidade[50];    // Nome da cidade - at� 49 caracteres + '\0'
    char sigla_estado[3];    // Sigla do estado (ex: MG, RJ) - 2 caracteres + '\0'
    float populacao;         // N�mero de habitantes da cidade
    float area;              // �rea da cidade em quil�metros quadrados
    float pib;               // Produto Interno Bruto da cidade
    int num_pontos_turisticos; // Quantidade de pontos tur�sticos na cidade
} Carta;

int main() {
    // Define a localiza��o para portugu�s, o que pode influenciar a exibi��o de caracteres acentuados
    setlocale(LC_ALL, "Portuguese");

    // Declara um array de estruturas 'Carta' para armazenar os dados de duas cartas
    Carta cartas[2];

    // *** CADASTRO DA PRIMEIRA CARTA ***
    printf("Cadastrando a Carta 01:\n");
    printf("------------------------------\n");

    // --- Entrada do Estado ---
    do {
        printf("ESTADO (A-H): ");
        scanf(" %c", &cartas[0].estado); // L� um �nico caractere para o estado
        cartas[0].estado = toupper(cartas[0].estado); // Converte a letra para mai�scula
        // Verifica se o estado inserido est� dentro do intervalo v�lido (A-H)
        if (cartas[0].estado < 'A' || cartas[0].estado > 'H') {
            printf("Estado inv�lido. Digite uma letra entre A e H.\n");
        }
        limpar_buffer(); // Limpa o buffer de entrada ap�s o scanf
    } while (cartas[0].estado < 'A' || cartas[0].estado > 'H'); // Repete at� o estado ser v�lido

    // --- Entrada da Sigla do Estado ---
    printf("SIGLA DO ESTADO (Ex: MG): ");
    scanf("%2s", cartas[0].sigla_estado); // L� at� 2 caracteres para a sigla do estado
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do C�digo da Carta ---
    printf("C�DIGO (ex: %c01): ", cartas[0].estado);
    scanf("%3s", cartas[0].codigo); // L� at� 3 caracteres para o c�digo da carta
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do Nome da Cidade ---
    printf("Nome da Cidade: ");
    fgets(cartas[0].nome_cidade, sizeof(cartas[0].nome_cidade), stdin); // L� uma linha inteira para o nome da cidade
    remover_newline(cartas[0].nome_cidade); // Remove a poss�vel quebra de linha do fgets

    // --- Entrada da Popula��o ---
    printf("Popula��o: ");
    scanf("%f", &cartas[0].populacao); // L� um n�mero de ponto flutuante para a popula��o
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada da �rea ---
    printf("�rea: ");
    scanf("%f", &cartas[0].area); // L� um n�mero de ponto flutuante para a �rea
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do PIB ---
    printf("PIB: ");
    scanf("%f", &cartas[0].pib); // L� um n�mero de ponto flutuante para o PIB
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do N�mero de Pontos Tur�sticos ---
    printf("N�mero de Pontos Tur�sticos: ");
    scanf("%d", &cartas[0].num_pontos_turisticos); // L� um n�mero inteiro para os pontos tur�sticos
    limpar_buffer(); // Limpa o buffer de entrada

    // *** CADASTRO DA SEGUNDA CARTA ***
    printf("\nCadastrando a Carta 02:\n");
    printf("------------------------------\n");

    // Repete o processo de entrada de dados para a segunda carta (armazenando em cartas[1])
    do {
        printf("ESTADO (A-H): ");
        scanf(" %c", &cartas[1].estado);
        cartas[1].estado = toupper(cartas[1].estado);
        if (cartas[1].estado < 'A' || cartas[1].estado > 'H') {
            printf("Estado inv�lido. Digite uma letra entre A e H.\n");
        }
        limpar_buffer();
    } while (cartas[1].estado < 'A' || cartas[1].estado > 'H');

    printf("SIGLA DO ESTADO (Ex: MG): ");
    scanf("%2s", cartas[1].sigla_estado);
    limpar_buffer();

    printf("C�DIGO (ex: %c01): ", cartas[1].estado);
    scanf("%3s", cartas[1].codigo);
    limpar_buffer();

    printf("Nome da Cidade: ");
    fgets(cartas[1].nome_cidade, sizeof(cartas[1].nome_cidade), stdin);
    remover_newline(cartas[1].nome_cidade);

    printf("Popula��o: ");
    scanf("%f", &cartas[1].populacao);
    limpar_buffer();

    printf("�rea: ");
    scanf("%f", &cartas[1].area);
    limpar_buffer();

    printf("PIB: ");
    scanf("%f", &cartas[1].pib);
    limpar_buffer();

    printf("N�mero de Pontos Tur�sticos: ");
    scanf("%d", &cartas[1].num_pontos_turisticos);
    limpar_buffer();

    // *** EXIBI��O DAS CARTAS CADASTRADAS ***
    printf("\n\n--- Cartas Cadastradas ---\n");

    // Exibe os dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", cartas[0].estado);
    printf("Sigla do Estado: %s\n", cartas[0].sigla_estado);
    printf("C�digo: %s\n", cartas[0].codigo);
    printf("Nome da Cidade: %s\n", cartas[0].nome_cidade);
    printf("Popula��o: %.0f\n", cartas[0].populacao);
    printf("�rea: %.2f km�\n", cartas[0].area);
    printf("PIB: %.2f bilh�es de reais\n", cartas[0].pib);
    printf("N�mero de Pontos Tur�sticos: %d\n", cartas[0].num_pontos_turisticos);

    // Exibe os dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", cartas[1].estado);
    printf("Sigla do Estado: %s\n", cartas[1].sigla_estado);
    printf("C�digo: %s\n", cartas[1].codigo);
    printf("Nome da Cidade: %s\n", cartas[1].nome_cidade);
    printf("Popula��o: %.0f\n", cartas[1].populacao);
    printf("�rea: %.2f km�\n", cartas[1].area);
    printf("PIB: %.2f bilh�es de reais\n", cartas[1].pib);
    printf("N�mero de Pontos Tur�sticos: %d\n", cartas[1].num_pontos_turisticos);

    return 0; // Indica que o programa terminou com sucesso
}
