//
// Created by admin on 16.09.2025.
//
#include "winbgim.h"  // Используйте кавычки для своих заголовочных файлов

int main() {
    // Инициализация графического окна
    initwindow(800, 600, "BGI Graphics Window");

    // Установка цвета фона
    setbkcolor(WHITE);
    cleardevice();

    // Рисование
    setcolor(RED);
    circle(400, 300, 100);

    setcolor(BLUE);
    rectangle(200, 200, 600, 400);

    setcolor(GREEN);
    outtextxy(350, 50, "Hello BGI!");

    // Ожидание клика мыши
    getch();

    // Закрытие графического окна
    closegraph();

    return 0;
}