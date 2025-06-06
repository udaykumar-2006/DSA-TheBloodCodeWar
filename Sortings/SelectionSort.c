#include <stdio.h>
//selection sort 
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int selectionSort(int a[],int n){
  int i,j;

  for(i=0;i<n-1;i++){
     int min_idx=i;
    for(j=i+1;j<n;j++){
      if (a[j] < a[min_idx]){
       min_idx=j;
      }
      
    }
    if (min_idx != i) {
            swap(&a[i], &a[min_idx]);
        }
  }
}


int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    selectionSort(a, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
