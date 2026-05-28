#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> v;

    std::cout << "Введите элементы (для завершения нажмите Ctrl+Z или введите не число): ";

    std::copy(
        std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(v)
    );

    std::map<int, int> m;

    std::for_each(v.begin(), v.end(), [&m](int x) {
        m[x]++;
        });

    std::cout << "Вывод: \n";

    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}