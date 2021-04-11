// 11724

#include <stdio.h>

using namespace std;

bool arr[1001][1001];
bool visited[1001];
int M, N;

void dfs(int start) {
	visited[start] = true;
	for(int i=1; i<N+1; i++) {
		if(!visited[i] && arr[start][i])
			dfs(i);
	}
}

int main() {
	
	scanf("%d %d",&N,&M);
	int cnt = 0;
	int u,v;
	
	for(int i=0; i<M; i++) {
		scanf("%d %d",&u,&v);
		arr[u][v] = arr[v][u] = true;
	}
	
	for(int i=1; i<N+1; i++) {
		
		if(!visited[i]) {
			dfs(i);
			cnt++;
		}
		
	}
	
	printf("%d", cnt);
	
	return 0;
}
