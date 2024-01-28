#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for(int i=0; i<n1; i++)
        left[i] = a[low + i];
    for(int i=0; i<n2; i++)
        right[i] = a[mid + i + 1];

    int leftIdx, rightIdx, aIdx = low;
    leftIdx = rightIdx = 0;
    while(leftIdx < n1 && rightIdx < n2) {
        if(left[leftIdx] < right[rightIdx])
            a[aIdx++] = left[leftIdx++];
        else
            a[aIdx++] = right[rightIdx++];
    }
    while(leftIdx < n1) 
        a[aIdx++] = left[leftIdx++];
    while(rightIdx < n2)
        a[aIdx++] = right[rightIdx++];
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = ( low + high ) / 2;
        mergeSort(a, low, mid); // including value at mid index
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high); 
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
    mergeSort(a, 0, size-1);
    printf("After sorting: \n");
    printArray(a, size);
    return 0;
}