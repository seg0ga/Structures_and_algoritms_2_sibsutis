#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comparisons = 0;
int swaps = 0;

void piram(int arr[], int L, int R) {
    int x = arr[L];
    int i = L;
    while (1) {
        int j = 2 * i;
        if (j > R)
            break;
        if (j < R) {
            if (arr[j + 1] > arr[j]) {
                comparisons++;
                j = j + 1;
            }
        }
        if (x >= arr[j]) {
            comparisons++;
            break;
        }
        swaps++;
        arr[i] = arr[j];
        i = j;
    }
    if (i != L) {
        swaps++;
    }
    swaps++;
    arr[i] = x;
}

void buildHeap(int arr[], int n) {
    for (int start = n/2 - 1; start >= 0; start--) {
        piram(arr, start, n - 1);
    }
}

void generateArray(int arr[], int n, int type) {
    switch(type) {
        case 0:
            for (int i = 0; i < n; i++) arr[i] = n - i;
            break;
        case 1:
            for (int i = 0; i < n; i++) arr[i] = rand() % (2*n);
            break;
        case 2:
            for (int i = 0; i < n; i++) arr[i] = i + 1;
            break;
    }
}

void testHeapConstruction(int n) {
    int arr[n];
    int theoretical = 2 * log2(n)+log2(n)+3;
    
    printf("| %4d ", n);
    
    for (int type = 0; type < 3; type++) {
        generateArray(arr, n, type);
        
        comparisons = 0;
        swaps = 0;
        piram(arr,1, n);
        
        printf("| %7d   ", comparisons + swaps);
    }
    printf("| %7d  |\n", theoretical);
}

void siftDown(int arr[], int start, int end) {
    int root = start;
    
    while (2 * root + 1 <= end) {
        int child = 2 * root + 1;
        int swapIdx = root;
        
        comparisons++;
        if (arr[swapIdx] < arr[child]) {
            swapIdx = child;
        }
        
        if (child + 1 <= end) {
            comparisons++;
            if (arr[swapIdx] < arr[child + 1]) {
                swapIdx = child + 1;
            }
        }
        
        if (swapIdx == root) {
            return;
        } else {
            swaps++;
            int temp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = temp;
            root = swapIdx;
        }
    }
}

void heapSort(int arr[], int n) {
    comparisons = 0;
    swaps = 0;
    
    for (int start = n/2 - 1; start >= 0; start--) {
        siftDown(arr, start, n - 1);
    }
    
    for (int end = n - 1; end > 0; end--) {
        swaps++;
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        
        siftDown(arr, 0, end - 1);
    }
}

void testHeapSort(int n) {
    int arr[n];
    
    printf("| %4d ", n);
    
    for (int type = 0; type < 3; type++) {
        generateArray(arr, n, type);
        heapSort(arr, n);
        printf("| %8d  ", comparisons + swaps);
    }
    printf("|\n");
}

int main() {
    srand(time(NULL));
    
    printf("Трудоемкость построения пирамиды\n");
    printf("+------+-----------+-----------+-----------+----------+\n");
    printf("|  N   | Убывающий | Случайный | Возрастаю | Теория   |\n");
    printf("+------+-----------+-----------+-----------+----------+\n");
    
    int sizes[] = {100, 200, 300, 400, 500};
    for (int i = 0; i < 5; i++) {
        testHeapConstruction(sizes[i]);
    }
    
    printf("+------+-----------+-----------+-----------+----------+\n");
    
    printf("\nТрудоемкость пирамидальной сортировки\n");
    printf("+------+-----------+-----------+-----------+\n");
    printf("|  N   |  Убыв.    |  Возр.    |  Случ.    |\n");
    printf("+------+-----------+-----------+-----------+\n");
    
    for (int i = 0; i < 5; i++) {
        testHeapSort(sizes[i]);
    }
    
    printf("+------+-----------+-----------+-----------+\n");
    return 0;
}
