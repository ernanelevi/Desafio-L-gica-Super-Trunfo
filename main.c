#include <stdio.h>

int main()
{
    // declaração das variáveis, carta 1 e carta 2
    char estado1, estado2; // estado é um char pois representa apenas uma letra
    char codigo1[50], cidade1[50], codigo2[50], cidade2[50];
    unsigned long int populacao1, populacao2; // Alterado para unsigned long int
    int pontos_turisticos1, pontos_turisticos2;
    float area1, pib1, area2, pib2, densidade_populacional1, densidade_populacional2, pib_per_capita1, pib_per_capita2, super_poder1, super_poder2; // Adicionados a densidade populacional e o PIB per capita
    // Adicionado o "Super poder"

    // coleta dos dados da primeira carta
    printf("Digite o estado da primeira carta (A - H): ");
    scanf("%c", &estado1);
    getchar(); // é necessário para evitar o erro do buffer do teclado

    printf("Digite o código da primeira carta (A01 - H04): ");
    fgets(codigo1, 50, stdin); // é necessário usar o fgets para nomes completos

    printf("Digite o nome da cidade (carta 1): ");
    fgets(cidade1, 50, stdin);

    printf("Digite a população desta cidade (carta 1): ");
    scanf("%lu", &populacao1); // alteração de %i para %lu
    getchar();                 // Limpa o buffer após ler um número inteiro

    printf("Digite a área desta cidade (carta 1): ");
    scanf("%f", &area1); // o scanf não aceita especificadores de formato, o correto é %f e não %.2f
    getchar();

    printf("Digite o PIB desta cidade (carta 1): ");
    scanf("%f", &pib1);
    getchar();

    printf("Digite o número de pontos turísticos (carta 1): ");
    scanf("%i", &pontos_turisticos1);
    getchar();

    // Adição da densidade populacional e do PIB per capita (carta 1)
    densidade_populacional1 = populacao1 / area1;
    pib_per_capita1 = pib1 / populacao1;
    super_poder1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1 / densidade_populacional1); // Calculo do super poder

    // Coleta dos dados da Segunda Carta
    printf("Digite o estado da segunda carta (A - H): ");
    scanf("%c", &estado2);
    getchar();

    printf("Digite o código da segunda carta (A01 - H04): ");
    fgets(codigo2, 50, stdin);

    printf("Digite o nome da cidade (carta 2): ");
    fgets(cidade2, 50, stdin);

    printf("Digite a população desta cidade (carta 2): ");
    scanf("%lu", &populacao2);
    getchar();

    printf("Digite a área desta cidade (carta 2): ");
    scanf("%f", &area2);
    getchar();

    printf("Digite o PIB desta cidade (carta 2): ");
    scanf("%f", &pib2);
    getchar();

    printf("Digite o número de pontos turísticos (carta 2): ");
    scanf("%i", &pontos_turisticos2);
    getchar();

    // Adição da densidade populacional e do PIB per capita (carta 2)
    densidade_populacional2 = populacao2 / area2;
    pib_per_capita2 = pib2 / populacao2;
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1 / densidade_populacional2);

    // impressão das cartas (resumo)
    printf("\n --- Carta 1 --- \n");
    printf("Estado: %c \n", estado1);
    printf("Código: %s", codigo1); // o fgets já pula para a próxima linha, então não é necessário usar um \n
    printf("Nome da cidade: %s", cidade1);
    printf("População: %lu \n", populacao1);
    printf("Área: %.2f Km² \n", area1); // o %.2f tem que vir aqui
    printf("PIB: %.2f bilhões de reais \n", pib1);
    printf("Número de Pontos Turísticos: %i \n", pontos_turisticos1);
    printf("Densidade populacional: %.2f \n", densidade_populacional1); // Densidade populacional (carta 1)
    printf("PIB per capita: %.2f \n", pib_per_capita1);                 // PIB per capita (carta 1)
    printf("Super poder: %.2f \n", super_poder1);

    printf("\n --- Carta 2 --- \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s", codigo2);
    printf("Nome da cidade: %s", cidade2);
    printf("População: %lu \n", populacao2);
    printf("Área: %.2f Km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", pib2);
    printf("Número de Pontos Turísticos: %i \n", pontos_turisticos2);
    printf("Densidade populacional: %.2f \n", densidade_populacional2); // Densidade populacional (carta 2)
    printf("PIB per capita: %.2f \n", pib_per_capita2);                 // PIB per capita (carta 2)
    printf("Super poder: %.2f \n", super_poder2);

    // Comparação - pib_per_capita
    printf("\n--- Comparação de Cartas (PIB per capita) ---\n"); // Adicionei uma comparação do pib_per_capita
    printf("Carta 1 - %s: %.2f \n", cidade1, pib_per_capita1);
    printf("Carta 2 - %s: %.2f \n", cidade2, pib_per_capita2);

    if (pib_per_capita1 > pib_per_capita2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }
    else if (pib_per_capita2 > pib_per_capita1)
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    else
    {
        printf("Resultado: Empate! \n");
    }

    // Comparação - população
    printf("\n--- Comparação de Cartas (População) ---\n"); // Adicionei uma comparação da população
    printf("Carta 1 - %s: %lu \n", cidade1, populacao1);
    printf("Carta 2 - %s: %lu \n", cidade2, populacao2);

    if (populacao1 > populacao2)
    {
        printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
    }
    else if (populacao2 > populacao1)
    {
        printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
    }
    else
    {
        printf("Resultado: Empate! \n");
    }

    return 0;
}