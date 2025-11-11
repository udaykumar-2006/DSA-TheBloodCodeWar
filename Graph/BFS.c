#include <stdio.h>
#define N 8
#define MAX 100

void BFS(int vtx,int A[][N],int n){
    int visited[N]={0};
    int queue[MAX];
    int front=-1,rear=-1;
    printf("%d ",vtx);
    visited[vtx]=1;
    queue[++rear]=vtx;
    while(front!=rear){
        int u=queue[++front];
        for(int v=1;v<=n;v++){
            if(A[u][v]==1&&visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                queue[++rear]=v;
            }
        }
    }
    printf("\n");
}

int main(){
    int A[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,1,0,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0}};
    printf("Vertex:1 -> ");
    BFS(1,A,8);
    printf("Vertex:4 -> ");
    BFS(4,A,8);
    return 0;
}
