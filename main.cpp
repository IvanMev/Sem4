#include <iostream>
#include <deque>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    deque<int> D;
    int n;

    cout << "Введите четное количество элементов дека: ";
    if (!(cin >> n) || n <= 0 || n % 2 != 0) {
        cout << "Размер должен быть положительным и четным." << endl;
        return 0;
    }

    cout << "Введите " << n << " элементов:" << endl;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        D.push_back(x);
    }

    int N = static_cast<int>(D.size());
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

