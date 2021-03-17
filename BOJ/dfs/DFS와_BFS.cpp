// 1260

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, V;
bool visit[1001];
bool ver[1001][1001];

void dfs(int V);
void bfs(int V);

int main() {
    scanf("%d %d %d",&N,&M, &V);
    
    for(int i=0; i<M; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        ver[tmp1][tmp2] = ver[tmp2][tmp1] = true;
    }
    dfs(V);
    printf("\n");
    bfs(V);
    
    return 0;
}

void dfs(int V) {
    printf("%d ", V);
    visit[V] = true;
    for(int i=1; i<=N; i++) {
        if(visit[i] == true || ver[i][V] == false) continue;
        dfs(i);
    }
}

void bfs(int V) {
    queue<int> q;
    q.push(V);
    visit[V] = false;
    
    while(!q.empty()) {
        V = q.front();
        printf("%d ", V);
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == false || ver[i][V] == false) continue;
            q.push(i);
            visit[i] = false;
        }
    }
}
