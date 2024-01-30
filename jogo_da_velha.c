#include <stdio.h>

// Fun��o para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Fun��o para verificar o vencedor
char verificarVencedor(char tabuleiro[3][3]) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return tabuleiro[0][i];
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return tabuleiro[0][2];
    
    // Se n�o houver vencedor
    return ' ';
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int linha, coluna;
    char jogador = 'X';
    char vencedor = ' ';

    printf("Bem-vindo ao Jogo da Velha!\n");

    // Loop do jogo
    while (vencedor == ' ') {
        imprimirTabuleiro(tabuleiro);

        // Jogador faz sua jogada
        printf("Jogador %c, digite a linha (0-2) e coluna (0-2) da sua jogada: ", jogador);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a posi��o est� vazia
        if (tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador;
            
            // Verificar se h� um vencedor
            vencedor = verificarVencedor(tabuleiro);
            
            // Alternar jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posi��o ocupada. Tente novamente.\n");
        }
    }

    // Imprimir resultado
    imprimirTabuleiro(tabuleiro);
    if (vencedor != ' ')
        printf("Parab�ns, jogador %c! Voc� venceu!\n", vencedor);
    else
        printf("Empate!\n");

    return 0;
}
