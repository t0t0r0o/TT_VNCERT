#include <stdio.h>
#include <stdlib.h>

void Sorting(int a[],int n) {
    for (int i = 1; i < n ; i++)
    {
        int ai = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > ai) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = ai;
    }
    
}

int main() {
    int a[] = {3,4,2,5,7,8};
    Sorting(a,6);
    for (size_t i = 0; i < 6; i++)
    {
       printf("%d ",a[i]);
    }
    
}