//
//  main.c
//  InsertSort
//
//  Created by 刘力瑄 on 2018/3/21.
//  Copyright © 2018年 Alexander. All rights reserved.
//

#include <stdio.h>
#define GET_ARRAY_LEN(array, len){len = sizeof(array) / sizeof(array[0]);}

// 插入排序
void insertSort(int *arr, int len){
    int key;
    int j;
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//int main(int argc, const char * argv[]) {
//    int arr[] = {1,9,2,8,3,8,4,7,5,6};
//    int len;
//    GET_ARRAY_LEN(arr, len);
//    insertSort(arr, len);
//    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}

