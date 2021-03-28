// 2667

#include <stdio.h>
#include <vector>
#include <algorithm>

int N, cnt, n;
bool a[26][26];
bool visited[26][26] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j);

using namespace std;

int main() {
    
    vector<int> ans;
	scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
        	scanf("%1d", &a[i][j]);
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(a[i][j] && !visited[i][j]) {
                cnt = 1;
                dfs(i, j);
                ans.push_back(cnt);
                n++;
            }
            visited[i][j] = true;
        }
    }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", n);
    
    for(int i=0; i<ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}

void dfs(int i, int j) {
    visited[i][j] = true;
    for(int n=0; n<4; n++) {
    	int x = i+dx[n];
    	int y = j+dy[n];
    	if(x < 0 || y < 0 || x >= N || y >= N) continue;
        if(!visited[x][y] && a[x][y]) {
			cnt++;
        	dfs(x, y);
    	}
    }
}
