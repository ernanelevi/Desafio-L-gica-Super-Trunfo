#include <stdio.h>

// Função para buscar valor do atributo
float get_valor(int opcao, unsigned long int pop, float area, float pib, int pontos, float dens, float ppcap)
{
    switch (opcao)
    {
    case 1: return pop;
    case 2: return area;
    case 3: return pib;
    case 4: return pontos;
    case 5: return dens;
    case 6: return ppcap;
    default: return 0;
    }
}

int main()
{
    char estado1, estado2;
    char codigo1[50], cidade1[50], codigo2[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    int pontos1, pontos2;
    float area1, pib1, area2, pib2;
    float dens1, dens2, ppcap1, ppcap2;
    float valor1_atrib1, valor2_atrib1, valor1_atrib2, valor2_atrib2;
    float soma1, soma2;
    int opcao1, opcao2;

    // Carta 1
    printf("Digite o estado da primeira carta (A - H): ");
    scanf(" %c", &estado1);
    getchar(); // limpar buffer

    printf("Digite o código da primeira carta (A01 - H04): ");
    fgets(codigo1, 50, stdin);

    printf("Digite o nome da cidade (carta 1): ");
    fgets(cidade1, 50, stdin);

    printf("Digite a população desta cidade (carta 1): ");
    scanf("%lu", &populacao1);

    printf("Digite a área desta cidade (carta 1): ");
    scanf("%f", &area1);

    printf("Digite o PIB desta cidade (carta 1): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos (carta 1): ");
    scanf("%d", &pontos1);
    getchar(); // limpar buffer

    // Carta 2
    printf("Digite o estado da segunda carta (A - H): ");
    scanf(" %c", &estado2);
    getchar();

    printf("Digite o código da segunda carta (A01 - H04): ");
    fgets(codigo2, 50, stdin);

    printf("Digite o nome da cidade (carta 2): ");
    fgets(cidade2, 50, stdin);

    printf("Digite a população desta cidade (carta 2): ");
    scanf("%lu", &populacao2);

    printf("Digite a área desta cidade (carta 2): ");
    scanf("%f", &area2);

    printf("Digite o PIB desta cidade (carta 2): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos (carta 2): ");
    scanf("%d", &pontos2);

    // Cálculos
    dens1 = populacao1 / area1;
    dens2 = populacao2 / area2;

    ppcap1 = pib1 / populacao1;
    ppcap2 = pib2 / populacao2;

    // Menu
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica (menor vence)\n6. PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++)
    {
        if (i == opcao1) continue;
        switch (i)
        {
        case 1: printf("1. População\n"); break;
        case 2: printf("2. Área\n"); break;
        case 3: printf("3. PIB\n"); break;
        case 4: printf("4. Pontos Turísticos\n"); break;
        case 5: printf("5. Densidade Demográfica (menor vence)\n"); break;
        case 6: printf("6. PIB per capita\n"); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2 || opcao1 < 1 || opcao1 > 6 || opcao2 < 1 || opcao2 > 6)
    {
        printf("\nOpção inválida! Reinicie o programa.\n");
        return 1;
    }

    // Busca dos atributos
    valor1_atrib1 = get_valor(opcao1, populacao1, area1, pib1, pontos1, dens1, ppcap1);
    valor2_atrib1 = get_valor(opcao1, populacao2, area2, pib2, pontos2, dens2, ppcap2);

    valor1_atrib2 = get_valor(opcao2, populacao1, area1, pib1, pontos1, dens1, ppcap1);
    valor2_atrib2 = get_valor(opcao2, populacao2, area2, pib2, pontos2, dens2, ppcap2);

    // Comparações
    char *atributos[] = {
        "População",
        "Área",
        "PIB",
        "Pontos Turísticos",
        "Densidade Demográfica",
        "PIB per capita"
    };

    printf("\n--- COMPARAÇÃO ---\n");
    printf("Cidade: %sVS %s", cidade1, cidade2);

    printf("\nAtributo 1: %s\n", atributos[opcao1 - 1]);
    printf("%s: %.2f | %s: %.2f\n", cidade1, valor1_atrib1, cidade2, valor2_atrib1);

    int resultado1 = (opcao1 == 5) ?
                     (valor1_atrib1 < valor2_atrib1 ? 1 : (valor1_atrib1 > valor2_atrib1 ? 2 : 0)) :
                     (valor1_atrib1 > valor2_atrib1 ? 1 : (valor1_atrib1 < valor2_atrib1 ? 2 : 0));

    printf("Resultado do Atributo 1: %s\n",
           resultado1 == 1 ? "Carta 1 venceu!" :
           resultado1 == 2 ? "Carta 2 venceu!" : "Empate!");

    printf("\nAtributo 2: %s\n", atributos[opcao2 - 1]);
    printf("%s: %.2f | %s: %.2f\n", cidade1, valor1_atrib2, cidade2, valor2_atrib2);

    int resultado2 = (opcao2 == 5) ?
                     (valor1_atrib2 < valor2_atrib2 ? 1 : (valor1_atrib2 > valor2_atrib2 ? 2 : 0)) :
                     (valor1_atrib2 > valor2_atrib2 ? 1 : (valor1_atrib2 < valor2_atrib2 ? 2 : 0));

    printf("Resultado do Atributo 2: %s\n",
           resultado2 == 1 ? "Carta 1 venceu!" :
           resultado2 == 2 ? "Carta 2 venceu!" : "Empate!");

    // Soma e resultado final
    soma1 = valor1_atrib1 + valor1_atrib2;
    soma2 = valor2_atrib1 + valor2_atrib2;

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f", cidade1, soma1);
    printf("%s: %.2f", cidade2, soma2);

    if (soma1 > soma2)
        printf("\nResultado final: Carta 1 venceu!\n");
    else if (soma2 > soma1)
        printf("\nResultado final: Carta 2 venceu!\n");
    else
        printf("\nResultado final: Empate!\n");

    return 0;
}
