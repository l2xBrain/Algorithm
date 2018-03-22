//
//  main.c
//  Algorithm
//
//  Created by 刘力瑄 on 2018/3/22.
//  Copyright © 2018年 Alexander. All rights reserved.
//

#include "index.h"

void merge(int *arr, unsigned int first, unsigned int middle, unsigned int last){
    int *left = (int*)malloc((middle-first+2)*sizeof(int));
    int *right = (int*)malloc((last-middle+1)*sizeof(int));
    for (int i = first; i <= middle; i++) {
        left[i] = arr[i];
    }
    for (int j = middle+1; j <= last; j++) {
        right[j] = arr[j];
    }
    left[middle-first+1] = INFINITY;
    right[last-middle] = INFINITY;
    int len = last - first + 1;
    int lIndex = 0;
    int rIndex = 0;
    for (int i = 0; i < len; i++) {
        if (left[lIndex] > right[rIndex]) {
            arr[i] = right[rIndex];
            rIndex++;
        }
        if (right[rIndex] > left[lIndex]) {
            arr[i] = left[lIndex];
            lIndex++;
        }
    }
}

void merge_sort(int *arr, unsigned int first, unsigned int last){
    int middle = 0;
    if (first < last) {
        middle = (first + last) / 2;
        merge_sort(arr, first, middle);
        merge_sort(arr, middle+1, last);
        merge(arr, first, middle, last);
    }
}

int main(){
    int arr[] = {4,3,5,7,8,9,2,3,0,1};
    int len = sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, len-1);
    for (int i = 0; i < len; i++) {
        printf("number %d\n", arr[i]);
    }
    return 0;
}
