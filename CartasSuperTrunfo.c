#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui a biblioteca padrão para funções de conversão como atof

// Estrutura de dados para representar uma carta
typedef struct {
    char  pais[50]; // ome do país
    char  estado; // Uma letra de 'A' a 'H'
    char  codigo[4]; // Um código de duas letras
    char  cidade[50]; // nome da cidade
    int   populacao; // Um inteiro representando a população da cidade
    float area; // A área da cidade em km²
    float pib; // O PIB da cidade em bilhões de reais
    int   pontos_turisticos; // O número de pontos turísticos da cidade
    float densidade_populacional; // A densidade populacional da cidade
    float pib_per_capita; // O PIB per capita da cidade
} carta;

carta ler_carta(char* numero_carta) {
    carta c;
    printf("Digite o nome do país: ");
    scanf(" %49[^\n]", c.pais); // Lê o nome do país, permitindo espaços

    printf("Digite o estado: ");
    scanf(" %c", &c.estado);

    c.codigo[0] = c.estado;
    c.codigo[1] = numero_carta[0];
    c.codigo[2] = numero_carta[1];
    c.codigo[3] = '\0';

    printf("Digite a cidade: ");
    scanf(" %49[^\n]", c.cidade); // Lê o nome da cidade, permitindo espaços

    printf("Digite a população da cidade: ");
    scanf("%d", &c.populacao);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &c.area);

    printf("Digite o PIB da cidade em bilhões de reais: ");
    scanf("%f", &c.pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &c.pontos_turisticos);

    // Calcula a densidade populacional e o PIB per capita
    // 2.1
    c.densidade_populacional = c.populacao / c.area;
    // Calcula o PIB per capita
    // 2.2
    c.pib_per_capita = c.pib * 1e9 / c.populacao; // PIB em reais, dividindo pela população

    return c;
}

void mostrar_carta(carta* c) {
    printf("País: %s\n", c->pais);
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->cidade);
    printf("População: %d\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: R$ %.2f bilhões de reais\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", c->densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", c->pib_per_capita);
}

void comparar_cartas(carta* c1, carta* c2, int* atributo1, int* atributo2, const char* opcoes_nomes[]) {
    printf("Comparando as cartas dos paises %s e %s:\n", c1->pais, c2->pais);

    printf("Atributos selecionados para comparação:\n");
    printf("1. %s\n", opcoes_nomes[0]);
    printf("2. %s", opcoes_nomes[1]);

    printf("\n\n");

    printf("%s da carta 1: %d\n", opcoes_nomes[0], atributo1[0]);
    printf("%s da carta 2: %d\n", opcoes_nomes[0], atributo1[1]);
    printf("\n");

    printf("%s da carta 1: %d\n", opcoes_nomes[1], atributo2[0]);
    printf("%s da carta 2: %d\n", opcoes_nomes[1], atributo2[1]);
    printf("\n");

    printf("\n");

    float soma[2] = { atributo1[0] + atributo2[0], atributo1[1] + atributo2[1] };

    printf("Soma dos atributos selecionados para comparação:\n");

    for(int i = 0; i < 2; i++) {
        printf("Carta %d: %.2f\n", i + 1, soma[i]);
    }

    printf("\n");

    if(soma[0] > soma[1]) {
        printf("A carta 1 é a vencedora.\n");
    } else if(soma[0] < soma[1]) {
        printf("A carta 2 é a vencedora.\n");
    } else {
        printf("Empate!\n");
    }
}

int main() {
    // Cria a primeira carta
    printf("Carta 1\n");
    carta carta1 = ler_carta("01");

    // Pula uma linha
    printf("\n");

    printf("Carta 2\n");
    // Cria a segunda carta
    carta carta2 = ler_carta("02");

    // Pula uma linha
    printf("\n");

    // Mostra a primeira carta
    printf("Carta 1:\n");
    mostrar_carta(&carta1);

    // Pula uma linha
    printf("\n");

    // Mostra a segunda carta
    printf("Carta 2:\n");
    mostrar_carta(&carta2);

    // Pula duas linhas
    printf("\n\n");

    // Menu com as opções de atributos para comparação
    int atributo1[2];
    int atributo2[2];

    char opcao1_selecionada = 0;
    int opcao_atual = 1; // Variável para controlar a opção atual

    const char* opcoes_nomes[2];

    while(1) {
        printf("Escolha um atributo para comparar:\n");
        if(opcao1_selecionada != '1') {
            printf("1. PIB\n");
        }
        if(opcao1_selecionada != '2') {
            printf("2. PIB per capita\n");
        }
        if(opcao1_selecionada != '3') {
            printf("3. Densidade populacional\n");
        }
        if(opcao1_selecionada != '4') {
            printf("4. Número de pontos turísticos\n");
        }
        if(opcao1_selecionada != '5') {
            printf("5. Área\n");
        }

        printf("\n");

        char escolha;
        do {
            escolha = getchar(); // Lê a entrada do usuário
        } while(escolha == '\n' || escolha == ' '); // Ignora espaços e novas linhas

        opcao1_selecionada = escolha;

        float atributo_selecionado[2];

        switch(escolha)
        {
            case '1':
                atributo_selecionado[0] = carta1.pib;
                atributo_selecionado[1] = carta2.pib;
                opcoes_nomes[opcao_atual-1] = "PIB";
            break;
            case '2':
                atributo_selecionado[0] = carta1.pib_per_capita;
                atributo_selecionado[1] = carta2.pib_per_capita;
                opcoes_nomes[opcao_atual-1] = "PIB per capita";
            break;
            case '3':
                atributo_selecionado[0] = carta1.densidade_populacional;
                atributo_selecionado[1] = carta2.densidade_populacional;
                opcoes_nomes[opcao_atual-1] = "Densidade populacional";
            break;
            case '4':
                atributo_selecionado[0] = carta1.pontos_turisticos;
                atributo_selecionado[1] = carta2.pontos_turisticos;
                opcoes_nomes[opcao_atual-1] = "Número de pontos turísticos";
            break;
            case '5':
                atributo_selecionado[0] = carta1.area;
                atributo_selecionado[1] = carta2.area;
                opcoes_nomes[opcao_atual-1] = "Área";
            break;
            default:
                printf("\nOpção '%c' é inválida. Tente novamente.\n\n", escolha);
                continue; // Volta para o início do loop
            break;
        }

        if(opcao_atual == 1) {
            atributo1[0] = atributo_selecionado[0];
            atributo1[1] = atributo_selecionado[1];
        } else if(opcao_atual == 2) {
            atributo2[0] = atributo_selecionado[0];
            atributo2[1] = atributo_selecionado[1];
        }

        opcao_atual++; // Incrementa a opção atual

        if(opcao_atual == 3) {
            break;
        }

        printf("\n");
    }

    comparar_cartas(&carta1, &carta2, atributo1, atributo2, opcoes_nomes);
    return 0;
}