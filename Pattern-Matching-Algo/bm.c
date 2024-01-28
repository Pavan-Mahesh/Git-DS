#include <stdio.h>
#include <string.h>

#define MAX 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharacterHeuristic(int badChar[], char *ptn, int ptnLen) {
    for(int i=0; i<MAX; i++)
        badChar[i] = -1;
    for(int i=0; i<ptnLen; i++)
        badChar[(int)ptn[i]] = i;
}

void bmSearch(char *str, char *ptn) {
    int strLen = strlen(str);
    int ptnLen = strlen(ptn);
    int badChar[MAX];
    badCharacterHeuristic(badChar, ptn, ptnLen);
    int shift = 0;
    while(shift <= (strLen - ptnLen)) {
        int ptnIdx = ptnLen - 1;
        while(ptnIdx >= 0 && str[shift + ptnIdx] == ptn[ptnIdx])
            ptnIdx--;
        if(ptnIdx < 0) {
            printf("\nPattern found at index: %d", shift);
            return;
        } else {
            shift += max(1, ptnIdx - badChar[(int)str[shift + ptnIdx]]);
        } 
    }
    printf("\nPattern not found in the string.");
}

int main() {
    char str[1000], ptn[100];
    printf("\nEnter string: \n");
    scanf("%s", str);
    printf("\nEnter pattern: \n");
    scanf("%s", ptn);
    bmSearch(str, ptn);
    return 0;
}