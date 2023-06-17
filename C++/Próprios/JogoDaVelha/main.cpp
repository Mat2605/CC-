#include <iostream>
#include <vector>
using namespace std;

void Jogador01(vector<vector<int>>& matriz, int tamanhoMatriz) {
    int linha, coluna;
    while (true) {
        cout << "Rodada do Jogador 01..." << endl;
        cout << "Digite uma posição: ";
        cin >> linha >> coluna;
        cout << "Posição escolhida: [" << linha << "][" << coluna << "]" << endl;

        if (linha < tamanhoMatriz && coluna < tamanhoMatriz && matriz[linha][coluna] == -1) {
            matriz[linha][coluna] = 1;
            break;
        } else {
            cout << "Posição inválida! Tente novamente." << endl;
        }
    }
}

void Jogador02(vector<vector<int>>& matriz, int tamanhoMatriz) {
    int linha, coluna;
    while (true) {
        cout << "Rodada do Jogador 02..." << endl;
        cout << "Digite uma posição: ";
        cin >> linha >> coluna;
        cout << "Posição escolhida: [" << linha << "][" << coluna << "]" << endl;

        if (linha < tamanhoMatriz && coluna < tamanhoMatriz && matriz[linha][coluna] == -1) {
            matriz[linha][coluna] = 0;
            break;
        } else {
            cout << "Posição inválida! Tente novamente." << endl;
        }
    }
}

int verificarVencedor(const vector<vector<int>>& matriz, int tamanhoMatriz) {
    // Verificar linhas
    for (int i = 0; i < tamanhoMatriz; i++) {
        if (matriz[i][0] != -1 && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            return matriz[i][0];
        }
    }

    // Verificar colunas
    for (int i = 0; i < tamanhoMatriz; i++) {
        if (matriz[0][i] != -1 && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
            return matriz[0][i];
        }
    }

    // Verificar diagonais
    if (matriz[0][0] != -1 && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        return matriz[0][0];
    }

    if (matriz[0][2] != -1 && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        return matriz[0][2];
    }

    // Nenhum vencedor encontrado
    return -1;
}

void imprimirTabuleiro(const vector<vector<int>>& matriz, int tamanhoMatriz) {
    cout << "Tabuleiro:" << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            if (matriz[i][j] == -1) {
                cout << "- ";
            } else if (matriz[i][j] == 1) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    const int tamanhoMatriz = 3;
    vector<vector<int>> velha(tamanhoMatriz, vector<int>(tamanhoMatriz, -1));

    cout << "=== Jogo da Velha ===" << endl;

    int rodada = 1;
    int vencedor = -1;
    while (rodada <= tamanhoMatriz * tamanhoMatriz && vencedor == -1) {
        if (rodada % 2 == 1) {
            Jogador01(velha, tamanhoMatriz);
        } else {
            Jogador02(velha, tamanhoMatriz);
        }

        imprimirTabuleiro(velha, tamanhoMatriz);
        vencedor = verificarVencedor(velha, tamanhoMatriz);
        rodada++;
    }

    if (vencedor == 1) {
        cout << "Jogador 01 (X) venceu!" << endl;
    } else if (vencedor == 0) {
        cout << "Jogador 02 (O) venceu!" << endl;
    } else {
        cout << "Empate!" << endl;
    }

    return 0;
}
