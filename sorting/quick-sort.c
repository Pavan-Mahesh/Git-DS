#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int greater = low - 1;
    for(int lesser = low; lesser < high; lesser++) {
        if(a[lesser] <= pivot) {
            greater++;
            swap(&a[lesser], &a[greater]);
        }
    }
    swap(&a[greater+1], &a[high]);
    return greater+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int partitionIdx = partition(a, low, high);
        quickSort(a, low, partitionIdx-1);
        quickSort(a, partitionIdx+1, high);
    }
}

void printArray(int a[], int size) {
    for(int i=0; i<size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {12, 56, 78, 98, 69, 21, 41, 85, 11, 69};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: \n");
    printArray(a, size);
    quickSort(a, 0, size-1);
    printf("After sorting: \n");
    printArray(a, size);
    return 0;
}