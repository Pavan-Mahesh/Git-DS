#include <stdio.h>
#include <string.h>

void computeLPS(int lps[], char *ptn, int ptnLen) {
    lps[0] = 0;
    int len = 0, idx = 1;
    while(idx < ptnLen) {
        if(ptn[len] == ptn[idx]) {
            len++;
            lps[idx] = len;
            idx++;
        } else {
            if(len != 0) {
                len = lps[len-1];
            } else {
                lps[idx] = 0;
                idx++;
            }
        }
    }
}

void kmpSearch(char *str, char *ptn) {
    int strLen = strlen(str);
    int ptnLen = strlen(ptn);
    int lps[ptnLen];
    computeLPS(lps, ptn, ptnLen);
    int strIdx = 0, ptnIdx = 0;
    while(strIdx < strLen) {
        while(ptnIdx < ptnLen && str[strIdx] == ptn[ptnIdx]) {
            strIdx++;
            ptnIdx++;
        }
        if(ptnIdx == ptnLen) {
            printf("\nPattern found at index: %d", strIdx - ptnIdx);
            return;
        } else {
            if(ptnIdx != 0)
                ptnIdx = lps[ptnIdx - 1];
            else
                strIdx++;
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
    kmpSearch(str, ptn);
    return 0;
}