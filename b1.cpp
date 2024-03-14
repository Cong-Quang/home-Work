#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inputArr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        arr[i] =rand() % 20 + 1;
    }
}
void showArr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: %d\n",i,arr[i]);
    }
    
}
void reverseArr(int arr[],int n){
    int l = 0, r = n-1;
    while (l < r)
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++; 
        r--;
    }
}
int SumArr(int arr[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
float average(int arr[], int n){
    return SumArr(arr,n)*1.0/n;
}
int maxArr(int arr[],int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int minArr(int arr[],int n){
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Duyệt qua từng phần tử
        for (int j = 0; j < n-i-1; j++) {
            // Nếu phần tử hiện tại lớn hơn phần tử kế tiếp, hoán đổi chúng
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main(){
    srand(time(NULL));
    int n; scanf("%d",&n);
    int * a = (int *) calloc(n,sizeof(int)); // create a new pointer // array
    inputArr(a,n);
    showArr(a,n);
    printf("==========================");
    reverseArr(a,n);
    showArr(a,n);
    free(a); // release case 
    return 0;
}