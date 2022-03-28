#include <stdio.h>
#include <stdlib.h>


void merge(int a[],int L,int R,int M) { 
    int i = L,i1 =0,i2=0;
    int n1 = M-L+1;
    int n2 = R-M;
    int n = n1+n2;
    int a1[n1],a2[n2];
    for (int k = 0; k < n1; k++)
    {
        a1[k] = a[k+L];
    }

    for (int k = 0; k < n2; k++)
    {
        a2[k] = a[M+k+1];
    }
    
    while(i1 < n1 && i2 < n2) {
        if(a1[i1] <= a2[i2]) {
            a[i] = a1[i1];
            i1++;
        } else{
            a[i] = a2[i2];
            i2++;
        }
        i++;
    } 
    while(i1 < n1) {
            a[i] = a1[i1];
            i++;
            i1++;
    } 
    while(i2 < n2) {
            a[i] = a2[i2];
            i++;
            i2++;

    }
    
}

void mergeSort(int a[], int L, int R) {
    if(L < R) {
        int M = L+(R-L)/2;
        mergeSort(a,L,M);
        mergeSort(a,M+1,R);
        merge(a,L,R,M);
    }
}

void printArray(int a[],int aL) {
    for (int i = 0; i < aL; i++)
    {
        printf("%d",a[i]);
    }
    
}


int main() {
    int a[] = {2,5,6,1,4,8,3};
    mergeSort(a,0,6);
    printf("day da xep la \n");
    printArray(a,7);

}