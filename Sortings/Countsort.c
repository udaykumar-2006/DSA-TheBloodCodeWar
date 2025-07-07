#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

int find(int a[],int n){
  int max=INT_MIN;
  for(int i=0;i<n;i++){
    if(a[i]>max){
      max=a[i];
    }
  }
  return max;
}
void CountSort(int a[],int n){
  int max;
  int *c;
  max=find(a,n);
  c=(int*)malloc(sizeof(int)*(max+1));
  for(int i=0;i<max+1;i++){
    c[i]=0;
  }
  for(int i=0;i<n;i++){
    c[a[i]]++;
  }
  int x=0;
  int y=0;
  while(y<max+1){
    if(c[y]>0){
      a[x++]=y;
      c[y]--;
    }else{
      y++;
    }
  }
}
int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    CountSort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
