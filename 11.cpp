#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main() {
    std::string ifName;
    std::cout << "Please enter the input file name: ";
    std::cin >> ifName;

    std::ifstream inFile(ifName);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    int sum = 0;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream lineStream(line);

        std::string word;
        while (lineStream >> word) {
            try {
                int number = std::stoi(word);
                sum += number;
            }
            catch (const std::invalid_argument& e) {
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Integer is out of range: " << word << std::endl;
            }
        }
    }
    inFile.close();
    std::cout << "The sum of all integers in that file is: " << sum << std::endl;

    return 0;
}

