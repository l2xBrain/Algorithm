//
//  index.c
//  归并排序算法,采用的是分治法(有三个步骤:分解,解决，合并)
//
//  Created by 刘力瑄 on 2018/3/22.
//  Copyright © 2018年 Alexander. All rights reserved.
//

#include "index.h"
// 解决, 合并
void merge(int *arr, unsigned int first, unsigned int middle, unsigned int last){
    int n1 = middle - first + 1;
    int n2 = last - middle;
    int *left = (int*)malloc((n1+1)*sizeof(int)); // 最后一个位置给哨兵
    int *right = (int*)malloc((n2+1)*sizeof(int)); // 最后一个位置给哨兵
    for (int i = 0; i < n1; i++) {
        left[i] = arr[first + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[middle + 1 + j];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    int lIndex = 0;
    int rIndex = 0;
    for (int i = first; i <= last; i++) {
        if (left[lIndex] > right[rIndex]) {
            arr[i] = right[rIndex];
            rIndex++;
        } else {
            arr[i] = left[lIndex];
            lIndex++;
        }
    }
}
// 分解
void merge_sort(int *arr, unsigned int first, unsigned int last){
    int middle = 0;
    if (first < last) {
        middle = (first + last) / 2;
        merge_sort(arr, first, middle);
        merge_sort(arr, middle+1, last);
        merge(arr, first, middle, last);
    }
    return;
}

int main(){
//    测试merge函数
//    int arr[] = {1,2,3,4,5,6,3,4,5,6,7};
//    merge(arr, 0, 5, 10);
    int arr[] = {4,3,5,7,8,9,2,3,0,1};
    int len = sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, len-1);
    for (int i = 0; i < len; i++) {
        printf("number %d\n", arr[i]);
    }
    return 0;
}
