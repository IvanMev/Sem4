#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    deque<int> D;

    cout << "Введите элементы дека (Ctrl+Z для конца):" << endl;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(D));

    size_t N = D.size();
    if (N == 0 || N % 2 != 0) {
        cout << "Количество элементов должно быть положительным и четным." << endl;
        return 0;
    }

    deque<int>::iterator it = D.begin() + (N / 2);

    for (size_t k = 0; k < N / 2; ++k) {
        it = D.insert(it, -1);
    }

    cout << "Результат:" << endl;
    copy(D.begin(), D.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}