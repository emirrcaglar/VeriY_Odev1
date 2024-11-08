#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For seeding rand()

// Function to generate a random sequence
std::string generateRandomSequence(int length) {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    std::string sequence;

    for (int i = 0; i < length; ++i) {
        sequence += chars[rand() % chars.size()];
    }
    return sequence;
}

// Main function to create the test file
void createTestFile(const std::string& filename, int numLines, int minLineLength, int maxLineLength) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numLines; ++i) {
        int lineLength = minLineLength + (rand() % (maxLineLength - minLineLength + 1));
        outFile << generateRandomSequence(lineLength) << '\n';
    }

    outFile.close();
    std::cout << "File created with " << numLines << " lines.\n";
}

int main() {
    std::string filename = "../Dna.txt";
    int numLines = 1000000;        // Number of lines to generate
    int minLineLength = 5;       // Minimum characters per line
    int maxLineLength = 20;      // Maximum characters per line

    createTestFile(filename, numLines, minLineLength, maxLineLength);
    return 0;
}
