//
//  main.c
//  Algorithm
//
//  Created by 刘力瑄 on 2018/3/26.
//  Copyright © 2018年 Alexander. All rights reserved.
//

#include "main.h"
#define N 3

int ** matrix_multiple(int (*a)[N], int (*b)[N]){
    int **c = (int **)malloc(sizeof(int) * N * N);
    for (int i = 0; i < N; i++)
    {
        c[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
            for (int z = 0; z < N; z++) {
                c[i][j] = c[i][j] + a[i][z] * b[z][j];
            }
        }
    }
    return c;
}

//int main(int argc, const char* argv[]){
//    int a[N][N] = {{1,2,3}, {1,2,3}, {1,2,3}};
//    int b[N][N] = {{1,2,3}, {1,2,3}, {1,2,3}};
//    int **c = NULL;
//    c = matrix_multiple(a, b);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("i:%d, j:%d, %d \n", i, j, c[i][j]);
//        }
//    }
//    return 0;
//}

