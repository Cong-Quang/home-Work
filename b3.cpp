#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Point
{
   unsigned int x;
}point;

void capPhat(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() %10 +1;
    }
}
void printArr(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: %d ",i,a[i]);
    }
}
int findPoint(int arr[], point p){
    return (arr[p.x] == '\0') ? 0 : 1;
}
void swapArr(int arr[],int n){
    int l = 0, r = n-1;
    while (l < r)
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++; r--;
    }
}
int main(){
    srand(time(NULL));
    int n;
    point p;
    scanf("%d",&n);
    int * a = (int *) calloc(n,sizeof(int));
    capPhat(a,n);
    printArr(a,n);
    printf("\ninput yor Point ");
    scanf("%d",&p.x);
    printf(findPoint(a,p) ? "YES\n": "NO\n");

    swapArr(a,n);
    printArr(a,n);
    free(a);
    return 0;
}