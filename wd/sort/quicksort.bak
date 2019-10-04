#include <cstdio>

int partition(int arr[], int left, int right) {
    int target = arr[left];
    while (left < right) {
        while (left < right && arr[right] > target) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] > taret) left++;
        arr[right] = arr[left];
    }
    arr[left] = target;
    return target;
}

void qs(int arr[], int left, int right) {
    if (left < right) {
        int target = partition(arr, left, right);
        qs(arr, left, target - 1);
        qs(arr, left, target);
    }
}
