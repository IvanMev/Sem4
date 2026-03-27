#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::string name;
    int n = 0;

    std::cout << "Enter file name: ";
    std::cin >> name;
    std::cout << "Enter N (1..26): ";
    std::cin >> n;

    if (!std::cin || n < 1 || n > 26) {
        std::cerr << "Invalid N. Expected integer in range 1..26.\n";
        return 1;
    }

    std::ofstream out(name);
    if (!out) {
        std::cerr << "Cannot open file: " << name << '\n';
        return 1;
    }

    char next = 'A';
    std::generate_n(std::ostream_iterator<char>(out, " "), n, [&next]() {
        return next++;
    });

    return 0;
}
