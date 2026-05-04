#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
#include <iterator>

/**
 * @struct less_abs
 * @brief Функтор для сравнения двух чисел по их абсолютному значению.
 */
struct less_abs : std::binary_function<int, int, bool> {
    /**
     * @brief Сравнивает модули двух целых чисел.
     * @param a Первое число
     * @param b Второе число
     * @return true, если |a| < |b|
     */
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};

/**
 * @brief Выводит элементы контейнера в стандартный поток вывода.
 * Использует функциональный подход через std::copy и итераторы.
 * @param Ссылка на вектор для вывода
 */
static void print_vector(const std::vector<int>& v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

/**
 * @enum InputMode
 * @brief Перечисление доступных режимов ввода данных.
 */
enum InputMode {
    KEYBOARD = 1,        
    RANDOM_GENERATED = 2 
};

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> V;

    std::cout
        << "Способ задания вектора:\n"
        << "  " << KEYBOARD << " — ввести с клавиатуры\n"
        << "  " << RANDOM_GENERATED << " — сгенерировать случайные целые числа\n"
        << "Выбор: ";

    int choice = 0;
    std::cin >> choice;
    InputMode mode = static_cast<InputMode>(choice);

    switch (mode) {
    case KEYBOARD: {
        std::cout << "Введите целые числа через пробел (завершите ввод Enter):\n";
        std::string line;
        std::getline(std::cin >> std::ws, line);
        std::istringstream iss(line);

        std::copy(std::istream_iterator<int>(iss),
            std::istream_iterator<int>(),
            std::back_inserter(V));
        break;
    }
    case RANDOM_GENERATED: {
        std::size_t n = 0;
        int lo = 0;
        int hi = 0;
        std::cout << "Количество элементов: ";
        std::cin >> n;
        std::cout << "Минимальное и максимальное значение: ";
        std::cin >> lo >> hi;
        if (lo > hi) std::swap(lo, hi);

        V.reserve(n);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(lo, hi);

        std::generate_n(std::back_inserter(V), n, [&]() {
            return dist(gen);
            });
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