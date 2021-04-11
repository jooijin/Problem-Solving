// 1012

#include <stdio.h>
#include <string.h>

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int M,N,K, ans;
bool arr[50][50];
bool visited[50][50];

void dfs(int x, int y);

using namespace std;

int main(){	
	int T;
	scanf("%d", &T);
	
	while(T>0){
	
		memset(arr, false, sizeof(arr));
		memset(visited, false, sizeof(visited));
		
		scanf("%d %d %d", &M,&N,&K);
		
		
		for(int i=0; i<K; i++){
			int x, y;
			scanf("%d %d", &x,&y);
			arr[x][y]=true;
		}
		
		ans=0;
		
		for(int i=0; i<M; i++) 
			for(int j=0; j<N; j++)
				if(arr[i][j] && !visited[i][j]){
					visited[i][j] = true;
					dfs(i, j);
					ans++;
				}
		
		printf("%d\n", ans);
		
		T--;
	}
	
	return 0;
}

void dfs(int x, int y){
	int nx, ny;
	
	for(int i=0; i<4; i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0 || ny<0 || nx >= M || ny >= N) continue;
		if(arr[nx][ny] && !visited[nx][ny]){
			visited[nx][ny] = true;
			dfs(nx,ny);
		}
	}	
}
