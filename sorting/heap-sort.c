#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[largest]) 
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;
    if(largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int size) {
    for(int i=size/2-1; i>=0; i--)
        heapify(a, size, i);
    for(int i=size-1; i>0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int a[], int size) {
    for(int i=0; i<size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: \n");
    printArray(a, size);
    heapSort(a, size);
    printf("After sorting: \n");
    printArray(a, size);
    return 0;
}