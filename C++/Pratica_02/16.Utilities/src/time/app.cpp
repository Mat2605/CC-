#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {
    // Iniciando a contagem de tempo usando std::chrono
    auto chrono_start_time = chrono::system_clock::now();

    // Iniciando a contagem de tempo usando std::clock
    clock_t clock_start_time = std::clock();

    // Finalizando a contagem de tempo usando std::chrono
    auto chrono_end_time = chrono::system_clock::now();

    // Finalizando a contagem de tempo usando std::clock
    clock_t clock_end_time = std::clock();

    // Calculando a diferença de tempo usando std::chrono
    chrono::duration<double> chrono_diff = chrono_end_time - chrono_start_time;

    // Calculando a diferença de tempo usando std::clock
    float clock_diff = static_cast<float>(clock_end_time - clock_start_time) / CLOCKS_PER_SEC;

    // Exibindo o tempo decorrido usando std::chrono em segundos
    cout << "Elapsed (std::chrono): " << chrono_diff.count() << " seconds" << endl;

    // Exibindo o tempo decorrido usando std::clock em segundos
    cout << "Elapsed (std::clock): " << clock_diff << " seconds" << endl;

    return 0;
}
