#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // Abrindo um arquivo para leitura
    ifstream myFileRead("example.txt");

    // Abrindo um arquivo para escrita
    ofstream myFileWrite("example.txt");

    // Abrindo um arquivo em modo de apêndice
    ofstream myFileAppend("example.txt", ios::out | ios::app);

    // Lendo uma linha do arquivo
    string line;
    getline(myFileRead, line);
    cout << "Linha lida do arquivo: " << line << endl;

    // Fechando o arquivo de leitura
    myFileRead.close();

    // Verificando a integridade do fluxo de escrita
    if (myFileWrite.good()) { 
        cout << "Stream de escrita está em bom estado." << endl;
    } else {
        cout << "Stream de escrita está corrompido." << endl;
    }

    // Escrevendo dados no arquivo
    myFileWrite << "Dados de exemplo para escrita." << endl;

    // Fechando o arquivo de escrita
    myFileWrite.close();

    // Abrindo novamente o arquivo para apêndice
    myFileAppend << "Mais dados de exemplo para apêndice." << endl;

    // Fechando o arquivo de apêndice
    myFileAppend.close();

    // Reabrindo o arquivo para leitura após as operações de escrita e apêndice
    ifstream myFileReopen("example.txt");

    // Lendo novamente uma linha do arquivo
    getline(myFileReopen, line);
    cout << "Linha lida do arquivo após escrita e apêndice: " << line << endl;

    // Obtendo um ponteiro para o objeto de buffer do fluxo atual
    streambuf* buffer = myFileReopen.rdbuf();
    // Pode ser usado para redirecionar o fluxo do arquivo

    // Fechando o arquivo de leitura após as operações
    myFileReopen.close();
    std::ifstream fin("example.txt");
    char c = fin.peek(); // c = '2'
    while (fin.good()) {
        int var;
        fin >> var;
    std::cout << var;   
    } // print 2370445789
    fin.seekg(4);
    c = fin.peek(); // c = '0'
    fin.close();

    return 0;
}

