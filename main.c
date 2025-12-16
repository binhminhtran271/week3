#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void matrix_reading(const char *filename, int matrix[100][100], int *row, int *col){
    FILE *fptr = fopen(filename,"r");
    if (fptr == NULL) {printf("Khong mo duoc file\n"); return;}
    
    char line[1000];
    int i=0, j=0;
    while(fgets(line, sizeof(line), fptr)){
        j=0;
        char *t = strtok(line, ",\n");
        while(t != NULL){
            matrix[i][j] = atoi(t);  // Chuyen tu xau ky tu sang so nguyen
            j++;
            t = strtok(NULL, ",\n");
        }
        if (i == 0) *col = j;
        i++;
    }
    *row = i;
    fclose(fptr);
    return;
}

int main(){
    int row1, col1, row2, col2;
    int A[100][100];
    int B[100][100];
    int res[100][100];
    matrix_reading("matrixA.csv", A, &row1, &col1);
    matrix_reading("matrixB.csv", B, &row2, &col2);
    // Cong, Tru
    if (row1 != row2 || col1 != col2) printf("Khong thuc hien duoc phep cong, tru");
    else{
        printf("A + B = \n");
        for(int i=0; i<row1; i++){
            for(int j=0; j<col1; j++){
                res[i][j] = A[i][j] + B[i][j];
                printf("%d ",res[i][j]);
                res[i][j] = 0;
            }
            printf("\n");
        }
        printf("A - B = \n");
        for(int i=0; i<row1; i++){
            for(int j=0; j<col1; j++){
                res[i][j] = A[i][j] - B[i][j];
                printf("%d ",res[i][j]);
                res[i][j] = 0;
            }
            printf("\n");
        }
    }
    // Nhan
    if (col1 != row2) printf("Khong thuc hien duoc phep nhan A*B");
    else{
        printf("A * B = \n");
        for(int i=0; i<row1; i++){
            for(int j=0; j<col2; j++){
                res[i][j]=0;
                for(int k=0; k<col1; k++) res[i][j] += A[i][k] * B[k][j];
                printf("%d ",res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;


    
}
