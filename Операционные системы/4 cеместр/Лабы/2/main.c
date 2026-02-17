#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define TOTAL_BYTES (32 * 1024L * 1024L * 1024L)  // 32 ГБ
#define PAGE_SIZE 4096
#define TOTAL_PAGES (TOTAL_BYTES / PAGE_SIZE)       // 8 388 608
#define INTS_PER_PAGE (PAGE_SIZE / sizeof(int))     // 1024

void takeAndInit() {
    int** pages = malloc(TOTAL_PAGES * sizeof(int*));
    for (long i = 0; i < TOTAL_PAGES; i++) {
        pages[i] = malloc(PAGE_SIZE);
        if (pages[i] == NULL) {
            printf("Ошибка на странице %ld\n", i);
            return;
        }
        pages[i][0] = 10;
            if (i % 100000 == 0) printf("takeThenInit alloc: %ld/%ld\n", i, TOTAL_PAGES);

    }
    for (long i = 0; i < TOTAL_PAGES; i++) {
        free(pages[i]);
    }
    free(pages);
}

void takeThenInit() {
    int** array = malloc(TOTAL_PAGES * sizeof(int*));
if (array == NULL) {
    printf("malloc failed!\n");
    return;
}
    for (long i = 0; i < TOTAL_PAGES; i++) {
        array[i] = malloc(PAGE_SIZE);
        if (i % 100000 == 0) printf("takeThenInit alloc: %ld/%ld\n", i, TOTAL_PAGES);
    }

    printf("Press Enter to init...\n");
    getchar();

    for (long i = 0; i < TOTAL_PAGES; i++) {
        array[i][0] = 10;
        if (i % 100000 == 0) printf("takeThenInit init: %ld/%ld\n", i, TOTAL_PAGES);
    }

    for (long i = 0; i < TOTAL_PAGES; i++) free(array[i]);
    free(array);
}
struct ArrayWrapper {
    int data[100];
};
void stack(int depth, struct ArrayWrapper arr) {
    size_t frame_size = sizeof(struct ArrayWrapper) + 32;  // 400 + 32 = 432 байта

    // Использовано стека = глубина * размер кадра
    size_t stack_used = depth * frame_size;

    printf("Глубина: %d | Примерный размер стека: %zu байт (%.2f КБ)\n",
           depth, stack_used, stack_used / 1024.0);

    stack(depth + 1, arr);
}


int main() {
    int choice;
    printf("Какую операцию выполнить? 1.Захват+И-я 2.Раздельно 3.Стек :");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("total pages: %ld\n", TOTAL_PAGES);
            printf("Press Enter to start takeAndInit...\n");
            getchar();
            takeAndInit();
            break;
        case 2:
            printf("total pages: %ld\n", TOTAL_PAGES);
            printf("Press Enter to start takeThenInit...\n");
            getchar();
            takeThenInit();
            break;
        case 3:
            printf("Press Enter to start stack...\n");
            getchar();
            struct ArrayWrapper end;
            stack(0,end);
            break;
    }

    return 0;
}