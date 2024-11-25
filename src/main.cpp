#include "../include/Fonksiyonlar.hpp"
#include <chrono>
using namespace std::chrono;

int main()
{
    // Record the start time before executing the program
    auto start = std::chrono::system_clock::now();

    // Call the main program function
    Fonksiyonlar::Program();

    // Record the end time after execution
    auto end = std::chrono::system_clock::now();

    // Calculate and display elapsed time in milliseconds
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "\nIslem suresi: " << elapsed.count() << " ms" << '\n';

    return 0;
}
