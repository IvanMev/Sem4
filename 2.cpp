#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    deque<int> D;
    
    cout << "Введите элементы дека:" << endl;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(D));

    int N = static_cast<int>(D.size());
    if (N == 0 || N % 2 != 0) {
        cout << "Количество элементов должно быть положительным и четным." << endl;
        return 0;
    }

    deque<int>::iterator i = D.begin() + N / 2;

    for (int k = 0; k < N / 2; ++k) {
        i = D.insert(--i, -1);
    }

    cout << "Результат:" << endl;
    for (int x : D) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}

