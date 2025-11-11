#include <stdio.h>
#define N 8
#define MAX 100

void DFS_Stack(int u,int A[][N],int n){
    int visited[N]={0};
    int stack[MAX];
    int top=-1;
    stack[++top]=u;
    printf("%d ",u);
    visited[u]=1;
    int v=0;
    while(top!=-1){
        while(v<n){
            if(A[u][v]==1&&visited[v]==0){
                stack[++top]=u;
                u=v;
                printf("%d ",u);
                visited[u]=1;
                v=-1;
            }
            v++;
        }
        v=u;
        u=stack[top--];
    }
}

void dfs_simple(int u,int A[][N],int n){
    int visited[N]={0};
    int stack[MAX];
    int top=-1;
    stack[++top]=u;
    while(top!=-1){
        u=stack[top--];
        if(!visited[u]){
            printf("%d ",u);
            visited[u]=1;
            for(int v=n-1;v>=0;v--){
                if(A[u][v]==1&&visited[v]==0){
                    stack[++top]=v;
                }
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
    int u=5;
    printf("DFS Vertex:%d -> ",u);
    DFS_Stack(u,A,8);
    printf("\n");
    printf("dfs Vertex:%d -> ",u);
    dfs_simple(u,A,8);
    printf("\n");
    return 0;
}
