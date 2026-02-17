#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void select_sort(unsigned int* item, int n)
{
    printf("\nСортировка отбором\n");
    printf("Получен массив: ");
    for (int i = 0; i < n; ++i) {
        printf("%d,", item[i]);
    }
    int a, b,c,cbuff;
    int change;

    for(a=0; a < (n- 1); ++a) {
        cbuff= item[a];
        c = a;
        change=0;
        for (b = a + 1; b < n; ++b)
            if (item[b] < cbuff)
            {
                cbuff=item[b];
                c=b;
                change= 1;
            }
        if (change) {
            item[c]=item[a];
            item[a]=cbuff;
        }
    }
    printf("\nПосле сортировки: ");
    for (int i = 0; i < n; ++i) {
        printf("%d,", item[i]);
    }
}

void shellSort(unsigned int* arr, int n) {
    printf("\n\nСортировка Шелла\n");
    printf("Получен массив: ");
    for (int i = 0; i < n; ++i) {
        printf("%d,", arr[i]);
    }
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
    printf("\nПосле сортировки: ");
    for (int i = 0; i < n; ++i) {
        printf("%d,", arr[i]);
    }
}
int main(void) {
    srand(time(NULL));
    unsigned int arrayRAND1[10];
    for (int i = 0; i < 10; ++i) {
        arrayRAND1[i] = rand()%15;
    }
    unsigned int arrayRAND2[10];
    for (int i = 0; i < 10; ++i) {
        arrayRAND2[i] = rand()%15;
    }

    unsigned int arrayForward1[10] = {1,2,3,4,5,6,7,8,9,10};
    unsigned int arrayForward2[10] = {1,2,3,4,5,6,7,8,9,10};

    unsigned int arrayBack1[10]={10,9,8,7,6,5,4,3,2,1};
    unsigned int arrayBack2[10]={10,9,8,7,6,5,4,3,2,1};

    printf("\nМассив со случайными числами\n");
    select_sort(arrayRAND1, 10);
    shellSort(arrayRAND2,10);

    printf("\n\nМассив, отсортированный в порядке возрастания\n\n");
    select_sort(arrayForward1, 10);
    shellSort(arrayForward2,10);

    printf("\n\nМассив, отсортированный в порядке убывания\n\n");
    select_sort(arrayBack1, 10);
    shellSort(arrayBack2,10);



    return 0;
}