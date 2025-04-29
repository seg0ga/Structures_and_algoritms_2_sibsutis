#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1024

void FillRandomLetters(char* buffer, size_t size) {
    const char charset[] = "Every year we go to Florida. We like to go to the beach."
                          "My favorite beach is called Emerson Beach. It is very long, "
                          "with soft sand and palm trees. It is very beautiful. I like "
                          "to make sandcastles and watch the sailboats go by. Sometimes "
                          "there are dolphins and whales in the water!";
    for (size_t i = 0; i < size - 1; i++) {
        buffer[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    buffer[size - 1] = '\0';
}

// Линейное пробирование
int linear_probing_chars(char A[], char table[], int n, int m) {
    int collisions = 0;
    for (int i = 0; i < n; i++) {
        int h = A[i] % m;
        int j = 0;
        while (j < m) {
            int idx = (h + j) % m;
            if (table[idx] == 0) {
                table[idx] = A[i];
                break;
            }
            collisions++;
            j++;
        }
    }
    return collisions;
}

// Квадратичное пробирование
int quadratic_probing_chars(char A[], char table[], int n, int m) {
    int collisions = 0;
    for (int i = 0; i < n; i++) {
        int h = A[i] % m;
        int j = 1;
        int attempt = 0;
        while (attempt < m) {
            if (table[h] == 0) {
                table[h] = A[i];
                break;
            }
            collisions++;
            h = (h + j * j) % m;
            j++;
            attempt++;
        }
    }
    return collisions;
}

// Красивая печать таблицы символов
void PrintSymbolTableFormatted(const char table[], int size, const char* title) {
    printf("\n%s:\n", title);
    const int cols = 10;

    for (int row = 0; row < (size + cols - 1) / cols; row++) {
        int start = row * cols;
        int end = (start + cols) < size ? (start + cols) : size;
        
        printf("Индексы: ");
        for (int i = start; i < end; i++) {
            printf("%4d", i);
        }
        printf("\nСимволы: ");
        for (int i = start; i < end; i++) {
            if (table[i] == 0)
                printf("%4c", '.');
            else
                printf("%4c", table[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void task2() {
    const int n = 1024;
    const int m = 101;
    char A[n];
    char linear_table[m];
    char quadratic_table[m];
    
    memset(linear_table, 0, m);
    memset(quadratic_table, 0, m);

    srand(time(NULL));
    FillRandomLetters(A, n);

    int linear_coll = linear_probing_chars(A, linear_table, n, m);
    int quad_coll = quadratic_probing_chars(A, quadratic_table, n, m);

    PrintSymbolTableFormatted(linear_table, m, "Хеш-таблица (линейные пробы)");
    PrintSymbolTableFormatted(quadratic_table, m, "Хеш-таблица (квадратичные пробы)");

    printf("Количество коллизий:\n");
    printf(" - Линейные пробы:      %d\n", linear_coll);
    printf(" - Квадратичные пробы:  %d\n", quad_coll);
    printf("==============================================================\n\n");
}

void task3() {
    int table_sizes[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 52, 66, 87, 95, 101};
    const int num_sizes = sizeof(table_sizes) / sizeof(table_sizes[0]);
    const int n = 100;

    printf("┌────────────────┬───────────┬────────────┬────────────────┐\n");
    printf("│ Размер таблицы │ Элементов │ Линейные   │ Квадратичные   │\n");
    printf("│       (m)      │   (n)     │ коллизии   │   коллизии     │\n");
    printf("├────────────────┼───────────┼────────────┼────────────────┤\n");

    for (int i = 0; i < num_sizes; i++) {
        int m = table_sizes[i];
        char A[n];
        char linear_table[m];
        char quadratic_table[m];
        
        memset(linear_table, 0, m);
        memset(quadratic_table, 0, m);
        
        FillRandomLetters(A, n);

        int linear_coll = linear_probing_chars(A, linear_table, n, m);
        int quad_coll = quadratic_probing_chars(A, quadratic_table, n, m);

        printf("│ %14d │ %9d │ %10d │ %14d │\n", m, n, linear_coll, quad_coll);
    }

    printf("└────────────────┴───────────┴────────────┴────────────────┘\n\n");
}

int main() {
    task2();
    task3();
    return 0;
}
