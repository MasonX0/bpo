#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL,"RU");  // Устанавливаем русскую локаль для консоли
    system("chcp 65001");    // Переключаем консоль в UTF-8 режим (Windows)

    const int lenght = 10000;
    ifstream file("input.txt");  // Открываем файл для чтения
    string list[lenght];      // Массив для хранения lenght слов
    string line;             // Переменная для хранения одной строки файла
    int cnt = 0;             // Счетчик слов

    if (!file.is_open()) {   // Проверяем, открылся ли файл
        cout << "Ошибка: не удалось открыть файл" << endl;
        return 1;            // Выход с ошибкой
    }

    // Основной цикл чтения файла
    while (getline(file, line)) {
        string word;  // Переменная для текущего слова

        // Обрабатываем каждый символ в строке
        for (int i = 0; i < line.length(); i++) {
            unsigned char c = line[i];  // Текущий байт

            // ПРОВЕРКА: Является ли этот байт началом русской буквы в UTF-8?
            // Русские буквы в UTF-8 начинаются с байтов 0xD0-0xDF
            if (c >= 0xD0 && c <= 0xDF && i + 1 < line.size()) {
                unsigned char next = line[i + 1];  // Следующий байт

                // ПРОВЕРКА: Является ли это корректной русской буквой?
                if ((c == 0xD0 && next >= 0x90 && next <= 0xBF) || // Буквы А-п
                    (c == 0xD1 && next >= 0x80 && next <= 0x8F) || // Буквы р-я
                    (c == 0xD0 && next == 0x81) ||                 // Буква Ё
                    (c == 0xD1 && next == 0x91)) {                 // Буква ё

                    // ДОБАВЛЯЕМ букву в слово (оба байта!)
                    word += c;     // Первый байт UTF-8
                    word += next;  // Второй байт UTF-8
                    i++;           // Пропускаем уже обработанный следующий байт
                }
            } else {
                // Если встретили НЕ русскую букву
                if (!word.empty()) {  // Если есть накопленное слово
                    list[cnt] = word; // Сохраняем слово в массив
                    cnt++;            // Увеличиваем счетчик
                    word.clear();     // Очищаем переменную слова
                }
                // Не-русские символы (кавычки, тире и т.д.) просто пропускаются
            }
        }

        // Обрабатываем слово, которое могло остаться в конце строки
        if (!word.empty()) {
            list[cnt] = word;
            cnt++;
        }
    }

    // СОЗДАЕМ выходные файлы
    ofstream chet_output("chet_output.txt");   // Для слов с четной длиной
    ofstream nechet_output("nechet_output.txt"); // Для слов с нечетной длиной

    // РАСПРЕДЕЛЯЕМ слова по файлам ПО ПОРЯДКОВОМУ НОМЕРУ
    for (int i = 0; i < cnt; i++) {
        if ((i + 1) % 2 == 0) {  // Если порядковый номер четный (второе, четвертое и т.д.)
            chet_output << list[i] << endl;
        } else {                  // Если порядковый номер нечетный (первое, третье и т.д.)
            nechet_output << list[i] << endl;
        }
    }

    cout << "Обработано слов: " << cnt << endl;
    cout << "Результаты сохранены в chet_output.txt и nechet_output.txt" << endl;

    return 0;
}