#include <stdio.h>      // Biblioteca para entrada e saída padrão (printf, scanf)
#include <locale.h>     // Biblioteca para configurações regionais (idioma, formatação)
#include <string.h>     // Biblioteca para manipulação de strings (strings)
#include <ctype.h>      // Biblioteca para funções de teste de caracteres (toupper)

// Função para limpar o buffer de entrada do teclado
void limpar_buffer() {
    int caractere;
    // Lê caracteres do buffer até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    while ((caractere = getchar()) != '\n' && caractere != EOF);
}

// Função para remover a quebra de linha ('\n') que a função fgets pode adicionar ao final de uma string
void remover_newline(char *string) {
    // Procura a primeira ocorrência do caractere de nova linha na string
    size_t posicao_newline = strcspn(string, "\n");
    // Se a nova linha for encontrada (a posição não for o comprimento total da string)
    if (posicao_newline < strlen(string)) {
        // Substitui a nova linha por um caractere nulo ('\0'), que marca o fim da string
        string[posicao_newline] = '\0';
    }
}

// Definição da estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado;             // Uma única letra (A-H) representando o estado
    char codigo[4];          // Código da carta (ex: A01, B03) - 3 caracteres + '\0'
    char nome_cidade[50];    // Nome da cidade - até 49 caracteres + '\0'
    char sigla_estado[3];    // Sigla do estado (ex: MG, RJ) - 2 caracteres + '\0'
    float populacao;         // Número de habitantes da cidade
    float area;              // Área da cidade em quilômetros quadrados
    float pib;               // Produto Interno Bruto da cidade
    int num_pontos_turisticos; // Quantidade de pontos turísticos na cidade
} Carta;

int main() {
    // Define a localização para português, o que pode influenciar a exibição de caracteres acentuados
    setlocale(LC_ALL, "Portuguese");

    // Declara um array de estruturas 'Carta' para armazenar os dados de duas cartas
    Carta cartas[2];

    // *** CADASTRO DA PRIMEIRA CARTA ***
    printf("Cadastrando a Carta 01:\n");
    printf("------------------------------\n");

    // --- Entrada do Estado ---
    do {
        printf("ESTADO (A-H): ");
        scanf(" %c", &cartas[0].estado); // Lê um único caractere para o estado
        cartas[0].estado = toupper(cartas[0].estado); // Converte a letra para maiúscula
        // Verifica se o estado inserido está dentro do intervalo válido (A-H)
        if (cartas[0].estado < 'A' || cartas[0].estado > 'H') {
            printf("Estado inválido. Digite uma letra entre A e H.\n");
        }
        limpar_buffer(); // Limpa o buffer de entrada após o scanf
    } while (cartas[0].estado < 'A' || cartas[0].estado > 'H'); // Repete até o estado ser válido

    // --- Entrada da Sigla do Estado ---
    printf("SIGLA DO ESTADO (Ex: MG): ");
    scanf("%2s", cartas[0].sigla_estado); // Lê até 2 caracteres para a sigla do estado
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do Código da Carta ---
    printf("CÓDIGO (ex: %c01): ", cartas[0].estado);
    scanf("%3s", cartas[0].codigo); // Lê até 3 caracteres para o código da carta
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do Nome da Cidade ---
    printf("Nome da Cidade: ");
    fgets(cartas[0].nome_cidade, sizeof(cartas[0].nome_cidade), stdin); // Lê uma linha inteira para o nome da cidade
    remover_newline(cartas[0].nome_cidade); // Remove a possível quebra de linha do fgets

    // --- Entrada da População ---
    printf("População: ");
    scanf("%f", &cartas[0].populacao); // Lê um número de ponto flutuante para a população
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada da Área ---
    printf("Área: ");
    scanf("%f", &cartas[0].area); // Lê um número de ponto flutuante para a área
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do PIB ---
    printf("PIB: ");
    scanf("%f", &cartas[0].pib); // Lê um número de ponto flutuante para o PIB
    limpar_buffer(); // Limpa o buffer de entrada

    // --- Entrada do Número de Pontos Turísticos ---
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &cartas[0].num_pontos_turisticos); // Lê um número inteiro para os pontos turísticos
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
            printf("Estado inválido. Digite uma letra entre A e H.\n");
        }
        limpar_buffer();
    } while (cartas[1].estado < 'A' || cartas[1].estado > 'H');

    printf("SIGLA DO ESTADO (Ex: MG): ");
    scanf("%2s", cartas[1].sigla_estado);
    limpar_buffer();

    printf("CÓDIGO (ex: %c01): ", cartas[1].estado);
    scanf("%3s", cartas[1].codigo);
    limpar_buffer();

    printf("Nome da Cidade: ");
    fgets(cartas[1].nome_cidade, sizeof(cartas[1].nome_cidade), stdin);
    remover_newline(cartas[1].nome_cidade);

    printf("População: ");
    scanf("%f", &cartas[1].populacao);
    limpar_buffer();

    printf("Área: ");
    scanf("%f", &cartas[1].area);
    limpar_buffer();

    printf("PIB: ");
    scanf("%f", &cartas[1].pib);
    limpar_buffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &cartas[1].num_pontos_turisticos);
    limpar_buffer();

    // *** EXIBIÇÃO DAS CARTAS CADASTRADAS ***
    printf("\n\n--- Cartas Cadastradas ---\n");

    // Exibe os dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", cartas[0].estado);
    printf("Sigla do Estado: %s\n", cartas[0].sigla_estado);
    printf("Código: %s\n", cartas[0].codigo);
    printf("Nome da Cidade: %s\n", cartas[0].nome_cidade);
    printf("População: %.0f\n", cartas[0].populacao);
    printf("Área: %.2f km²\n", cartas[0].area);
    printf("PIB: %.2f bilhões de reais\n", cartas[0].pib);
    printf("Número de Pontos Turísticos: %d\n", cartas[0].num_pontos_turisticos);

    // Exibe os dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", cartas[1].estado);
    printf("Sigla do Estado: %s\n", cartas[1].sigla_estado);
    printf("Código: %s\n", cartas[1].codigo);
    printf("Nome da Cidade: %s\n", cartas[1].nome_cidade);
    printf("População: %.0f\n", cartas[1].populacao);
    printf("Área: %.2f km²\n", cartas[1].area);
    printf("PIB: %.2f bilhões de reais\n", cartas[1].pib);
    printf("Número de Pontos Turísticos: %d\n", cartas[1].num_pontos_turisticos);

    return 0; // Indica que o programa terminou com sucesso
}
