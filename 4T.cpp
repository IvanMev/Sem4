#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

struct less_abs : std::binary_function<int, int, bool> {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};

static void print_vector(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> V;
    enum InputMode {
        keyboard = 1,
        random_generated = 2
    };

    std::cout
        << "Способ задания вектора:\n"
        << "  1 — ввести с клавиатуры\n"
        << "  2 — сгенерировать случайные целые числа\n"
        << "Выбор: ";

    int mode = 0;
    std::cin >> mode;

    switch (mode) {
    case keyboard: {
        std::cout << "Введите целые числа через пробел\n";
        std::string line;
        std::getline(std::cin >> std::ws, line);
        std::istringstream iss(line);
        int x = 0;
        while (iss >> x) {
            V.push_back(x);
        }
        break;
    }
    case random_generated: {
        std::size_t n = 0;
        int lo = 0;
        int hi = 0;
        std::cout << "Количество элементов: ";
        std::cin >> n;
        std::cout << "Минимальное и максимальное значение: ";
        std::cin >> lo >> hi;
        if (lo > hi) {
            std::swap(lo, hi);
        }
        V.reserve(n);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(lo, hi);
        for (std::size_t i = 0; i < n; ++i) {
            V.push_back(dist(gen));
        }
        break;
    }
    default:
        std::cout << "Неизвестный вариант.\n";
        return 1;
    }

    std::sort(V.begin(), V.end(), less_abs());

    std::cout << "После сортировки по |x|:\n";
    print_vector(V);

    return 0;
}
