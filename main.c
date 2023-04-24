#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 10

#define swap(a, b) a = a + b; \
                    b = a - b;\
                    a = a - b;

/*--------------------------------------------------------------------------------------------------------------------*/

void heapify(int arr[], int n, int i) {
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void HeapSort(int *arr, int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i])

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/
void BubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1], arr[j])
            }
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

void rand_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 100;
    }
}


// Вспомогательная функция для вывода на экран массива размера n
void print_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

/*--------------------------------------------------------------------------------------------------------------------*/

int main() {
    srand(time(NULL));

    int *arr;
    arr = malloc(sizeof(int) * ARRSIZE);

    puts("Bubble sort arr:\n");
    rand_arr(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);
    BubbleSort(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);

    puts("Heap sort arr:\n");
    rand_arr(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);
    HeapSort(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);

    free(arr);
    return 0;
}
