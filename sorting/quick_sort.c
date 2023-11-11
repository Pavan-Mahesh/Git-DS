#include <stdio.h>
#include <conio.h>

void quick_sort(int, int);
void print_array();

int a[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
int len = sizeof(a)/sizeof(a[0]);

int main() {
    printf("\nGiven list: ");
    print_array();

    quick_sort(0, len-1);

    printf("\nSorted list: ");
    print_array();

    getch();
    return 0;
}

void print_array() {
    printf("\n");
    for(int i=0; i<len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int p, int q) {
    int temp = a[p];
    a[p] = a[q];
    a[q] = temp;
}

void quick_sort(int low, int high) {
    if(low < high) {
        int pivot = a[low], start=low, end=high;
        do_again:
        while(!(a[start] > pivot) && start<high)
            start++;
        while(!(a[end] <= pivot) && end>low)
            end--;
        if(start<end) {
            swap(start, end);
            goto do_again;
        } else { // start >= end
            swap(low, end);
            quick_sort(low, end-1);
            quick_sort(end+1, high);
        }
    }
}