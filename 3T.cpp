#include <iostream>
#include <map>
#include <vector>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> v;
    int n = 0;

    std::cout << "Введите число элементов:  ";
    std::cin >> n;

    v.resize(n);
    std::cout << "Введите элементы: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cin >> *it;
    }

    std::map<int, int> m;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        m[*it]++;
    }

    std::cout << "Вывод: \n";
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}
