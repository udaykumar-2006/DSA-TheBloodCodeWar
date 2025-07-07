#include <stdio.h>
#include <stdio.h>
//Recursive method of mergeSort

void Merging(int a[],int l,int h,int mid){
  int i,j,k;
  i=l;j=mid+1;k=l;
  int b[h+1];
  while(i<=mid&&j<=h){
    if(a[i]<a[j]){
      b[k++]=a[i++];
    }else{
      b[k++]=a[j++];
    }
  }
  for(;i<=mid;i++){
    b[k++]=a[i];
  }
  for(;j<=h;j++){
    b[k++]=a[j];
  } 
  
  for(i=l;i<=h;i++){
    a[i]=b[i];
  }
  
}

void merge(int a[],int l,int h){
  
  
  if(l<h){
    int mid=((l+h)/2);
    merge(a,l,mid);
    merge(a,mid+1,h);
    Merging(a,l,mid,h);
  }
}
int main() {
    int a[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);

    merge(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
