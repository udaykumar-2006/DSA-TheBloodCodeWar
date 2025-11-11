#include <stdio.h>
#define N 8

void DFS(int u,int A[][N],int n){
    static int visited[N]={0};
    if(visited[u]==0){
        printf("%d ",u);
        visited[u]=1;
        for(int v=1;v<n;v++){
            if(A[u][v]==1&&visited[v]==0){
                DFS(v,A,n);
            }
        }
    }
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
    printf("Vertex:4 -> ");
    DFS(4,A,8);
    printf("\n");
    return 0;
}
