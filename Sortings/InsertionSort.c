#include <stdio.h>
//insertion sort 
void insertionSort(int a[],int n){
  
  for(int i=0;i<n;i++){
    int j=i-1;
    int x=a[i];
    while(a[j]>x&&j>-1){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=x;
  }
  
  
}

int main()
{
   int arr[] = {5, 2, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
