//
// Created by admin on 16.09.2025.
//

#include <algorithm>
#include <iostream>
#include <math.h>
#include <ostream>
using namespace std;

int sum_with_recursive(int from, int to) {
    if (from > to) {
        return 0;
    }
    return (1 - from) + sum_with_recursive(from + 1, to);
}

int sum_without_recursive(int from, int to) {
    int total = 0;
    for (int i = from; i <= to; i++) {
        total += 1 - i;
    }
    return total;
}


int main() {
    system("chcp 65001");// для русского языка в консоли
    int count_from, count_to;
    cout << "Введите диапазон целых чисел " << endl;
    cout << "Начало: ";
    cin >> count_from;
    cout << "Конец: ";
    cin >> count_to;
    int total_sum_with_recursive = sum_with_recursive(count_from, count_to);
    int total_sum_without_recursive = sum_without_recursive(count_from, count_to);
    cout << "Итоговая сумма (с рекурсией): " << total_sum_with_recursive << endl;
    cout << "Итоговая сумма (без рекурсии): " << total_sum_without_recursive << endl;
    return 0;
}
