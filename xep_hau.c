#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N = 8;

bool ktraVT(int b[N][N], int Row, int Col) {  // ham noolean ktra vi tri co thoa man cac cot truoc hay khong

    // ktra hang ngang ben trai
    for (int i = 0; i < Col; i++)
    {
        if(b[Row][i] == 1) {
            return false;
        }
    }


    //ktra duong cheo tren ben trai
    int i=Row, j = Col;
    while(i >= 0 && j >= 0) {
        if(b[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }


    //ktra duong cheo duoi ben trai
    i=Row; 
    j = Col;
    while(i < N && j >= 0) {
        if(b[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

bool datHau(int b[N][N], int Col) {
    if(Col >= N) {
        return true;
    }
    for(int i = 0; i < N; i++) {
        if(ktraVT(b,i,Col)) {
            b[i][Col] = 1;  // dat duoc thi dat 1
            if(datHau(b,Col+1)) {   //de quy tim vi tri tiep theo co dat duoc hay khong
                return true;
            }
            b[i][Col] = 0;  // neu khong dat duoc thi tra ve 0;
        }
    }
    return false;
}

void printArray(int b[N][N]) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
        
    }
    
}


int main() {
    int b[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[i][j] = 0;
        }
        
    }

    if(setHau(b,0)) {
        printArray(b);
    } else {
        printf("Ko ton tai");
    }
    

}