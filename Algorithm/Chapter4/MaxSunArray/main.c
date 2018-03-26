//
//  main.c
//  最大子数组问题(数组中存在负数)
//  采用暴力方法解决问题，问题使用的时间 (n-1) + (n-2) + (n-3) + ... + 2 + 1 , 时间复杂度是O(n^2)
//  有没有其他方案呢，更快的方案?
//  使用分治策略, 时间复杂度为: O(n*lg(n))
//
//  Created by 刘力瑄 on 2018/3/23.
//  Copyright © 2018年 Alexander. All rights reserved.
//

#include "main.h"

typedef struct {
    int lowIndex;
    int highIndex;
    int value;
} Info;

// 计算middle的左右相加值最大的情况。时间复杂度是:O(n)
Info find_max_cross_subarray(int *arr, int low, int middle, int high){
    Info info;
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = middle; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            info.lowIndex = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = middle + 1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            info.highIndex = i;
        }
    }
    info.value = left_sum + right_sum;
    return info;
}

Info find_maximum_subarray(int *arr, int low, int high){
    Info info;
    if (low == high) {
        info.lowIndex = low;
        info.highIndex = high;
        info.value = arr[low];
        return info;
    } else {
        int middle = floor((low+high)/2);
        Info left = find_maximum_subarray(arr, low, middle);
        Info right = find_maximum_subarray(arr, middle + 1, high);
        Info cross = find_max_cross_subarray(arr, low, middle, high);
        if (left.value >= right.value && left.value >= cross.value) {
            return left;
        } else if (right.value >= left.value && right.value >= cross.value) {
            return right;
        } else {
            return cross;
        }
    }
}


//int main(){
//    int arr[] = {1,2,-3,-6,3,7,9,-8,6};
//    int len = sizeof(arr)/sizeof(int);
//    Info result = find_maximum_subarray(arr, 0, len - 1);
//    printf("i: %d, j: %d, result: %d", result.lowIndex, result.highIndex, result.value);
//    return 0;
//}

