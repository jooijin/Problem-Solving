// 아직 미완성,,,
// dfs로 풀면 답은 맞으나 시간이 초과된다.
// bfs로 변경해야 할 것 같다

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m;

bool visit[101][101];
int arr[101][101];

int MIN = 10001;
int answer;

/*void dfs(int x, int y, int depth){
    if(x == n && y == m){
        MIN = min(MIN, depth);
        answer = MIN;
    }
    bool flag = false;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
        if(!visit[ny][nx] && arr[ny][nx] == 1){
            visit[ny][nx] = true;
            dfs(nx, ny, depth+1);
            visit[ny][nx] = false;
            flag = true;
        }
        if(i >= 3 && flag == true)
            break;
    }
}*/

void bfs(int x, int y, int depth) {
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    depth++;
    visit[y][x] = true;
    
    while(!q.empty()) {
        pair<int,int> temp = q.front();
        q.pop();
        //cout<<temp.first<<" "<<temp.second<<" "<<depth<<endl;
        depth--;
        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if(visit[ny][nx] || arr[ny][nx] == 0) continue;
            q.push(make_pair(nx, ny));
            depth++;
            cout<<nx<<" "<<ny<<" "<<depth<<endl;
            visit[ny][nx] = true;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    n = maps[0].size()-1;
    m = maps.size()-1;
    
    for(int y=0; y<=m; y++){
        for(int x=0; x<=n; x++) {
            arr[y][x] = maps[y][x];
        }
    }
    
    bfs(0, 0, 1);
    
    if(answer == 0)
        return -1;
    
    return answer;
}
