// 2606

#include <stdio.h>

using namespace std;

int N, M, cnt = 0;
bool arr[102][102];
bool visited[102];

void dfs(int start);

int main() {

	scanf("%d %d", &N, &M);
	
	for(int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d",&a, &b);
		arr[a][b] = arr[b][a] = true;
	}
	
	dfs(1);
	
	printf("%d", --cnt);
	
}

void dfs(int start) {
	visited[start] = true;
	cnt++;
	for(int i=1; i<N+1; i++) {
		if(visited[i] || !arr[start][i]) continue;
		dfs(i);
	}
}
