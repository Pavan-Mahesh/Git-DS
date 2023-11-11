#include <stdio.h>
#include <conio.h>

void quick_sort(int [], int, int);
void print_array(int [], int);

int len;

int main() {
    int a[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    len = sizeof(a)/sizeof(a[0]);
    
    printf("\nGiven list: ");
    print_array(a, len);

    printf("===============================");
    quick_sort(a, 0, len-1);
    printf("===============================");

    printf("\nSorted list: ");
    print_array(a, len);

    getch();
    return 0;
}

void print_array(int a[], int len) {
    printf("\n");
    for(int i=0; i<len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void quick_sort(int a[], int low, int high) {
    if(low < high) {
        int pivot = a[low], start=low, end=high;
        do_again:
        print_array(a, len);
        while(!(a[start] > pivot) && start<high)
            start++;
        while(!(a[end] <= pivot) && end>low)
            end--;
        if(start<end) {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            goto do_again;
        } else { // start >= end
            int temp = a[low];
            a[low] = a[end];
            a[end] = temp;
            quick_sort(a, low, end-1);
            quick_sort(a, end+1, high);
        }
    }
}