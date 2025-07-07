#include <stdio.h>
//iterative method of mergeSort

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
void iterativeMerge(int a[],int n){
  int m,i,l,h,mid,p;
  for(p=2;p<=n;p=p*2){
    for(i=0;i+p-1<n;i=i+p){
      l=i;
      h=i+p-1;
      mid=((l+h)/2);
      Merging(a,l,mid,h);
    }
  }
  if(p/2<n){
    Merging(a,0,p/2,n-1);
  }
}

int main() {
    int a[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);

    iterativeMerge(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
