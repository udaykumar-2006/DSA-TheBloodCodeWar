#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node*next;
} Node;

void insert(Node**bin, int value) {
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=value;
  temp->next= NULL;

  if(*bin==NULL) {
    *bin=temp;
  } else{
    Node* p=*bin;
  while(p->next!= NULL)
  p=p->next;
   p->next=temp;
  }
}

int deleteNode(Node** bin) {
    Node*temp=*bin;
  int value=temp->data;
  *bin=(*bin)->next;
  free(temp);
   return value;
}
int findMax(int a[], int n) {
 int max = a[0];
  for (int i = 1; i < n; i++) {
   if (a[i] > max)
    max = a[i];
  }
 return max;
}

void binSort(int a[],int n) {
  int max =findMax(a,n);
  int i,j;
  
Node** Bins=(Node**)malloc((max + 1)*sizeof(Node*));
  for (i=0;i<= max;i++){
    Bins[i]=NULL;
  }

  for (i=0;i<n;i++){
    insert(&Bins[a[i]],a[i]);
 }

i = 0;
j = 0;
 while(i <= max) {
  while(Bins[i]!=NULL){
    a[j++]=deleteNode(&Bins[i]);
  }
  i++;
}
free(Bins);
}


int main()
{
    int a[] = {5, 3, 7, 2, 5, 3, 1, 9, 0};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    binSort(a, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
