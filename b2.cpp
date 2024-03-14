#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArr(int *arr,int n,int m){
    for (int i = 0; i < n*m; i++)
    {
        arr[i] =rand() % 20 + 1;
    }
}
void showArr(int *arr,int n,int m){
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
            printf("[%d][%d]: %d\t",i,j,arr[i+j]);
       }
       printf("\n");
    }
    
}
void showArrBien(int *arr,int n,int m){
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) 
                printf("%3d",arr[i+j]);
            else printf("   ");
       }
       printf("\n");
    }
}
void findK(int *arr,int n,int m, int k){
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
            if(arr[i+j] == k) {
                printf("[%d][%d]: %d\n",i,j,arr[i+j]);
                continue;
            }
}
void ShowArrR(int *arr,int n,int m, int r){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == r) printf("[%d][%d]: %d \n",i,j,arr[i+j]);
        }
    }
}
int main(){
    int n,m,k,r;
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    int * a = (int *) calloc(n*m+1,sizeof(int));
    inputArr(a,n,m);
    showArr(a,n,m);
    printf("=================\n");
    showArrBien(a,n,m);
    printf("Input K: ");
    scanf("%d",&k);
    findK(a,n,m,k);
    printf("input your R: ");
    scanf("%d",&r);
    ShowArrR(a,n,m,r);
    free(a);
    return 0;
}