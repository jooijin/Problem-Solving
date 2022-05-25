// 4991

/*
문제
오늘은 직사각형 모양의 방을 로봇 청소기를 이용해 청소하려고 한다. 이 로봇 청소기는 유저가 직접 경로를 설정할 수 있다.

방은 크기가 1×1인 정사각형 칸으로 나누어져 있으며, 로봇 청소기의 크기도 1×1이다. 
칸은 깨끗한 칸과 더러운 칸으로 나누어져 있으며, 로봇 청소기는 더러운 칸을 방문해서 깨끗한 칸으로 바꿀 수 있다.

일부 칸에는 가구가 놓여져 있고, 가구의 크기도 1×1이다. 
로봇 청소기는 가구가 놓여진 칸으로 이동할 수 없다. 

로봇은 한 번 움직일 때, 인접한 칸으로 이동할 수 있다. 또, 로봇은 같은 칸을 여러 번 방문할 수 있다.

방의 정보가 주어졌을 때, 더러운 칸을 모두 깨끗한 칸으로 만드는데 필요한 이동 횟수의 최솟값을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에는 방의 가로 크기 w와 세로 크기 h가 주어진다. (1 ≤ w, h ≤ 20) 
둘째 줄부터 h개의 줄에는 방의 정보가 주어진다. 방의 정보는 4가지 문자로만 이루어져 있으며, 각 문자의 의미는 다음과 같다.

.: 깨끗한 칸
*: 더러운 칸
x: 가구
o: 로봇 청소기의 시작 위치
더러운 칸의 개수는 10개를 넘지 않으며, 로봇 청소기의 개수는 항상 하나이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각각의 테스트 케이스마다 더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동 횟수의 최솟값을 한 줄에 하나씩 출력한다. 만약, 방문할 수 없는 더러운 칸이 존재하는 경우에는 -1을 출력한다.
*/

#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

int w, h;
char map[21][21];
int ans;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool v[21][21];
bool visit[11];
int dis[11][11];

struct robot{
	int x, y, move;
	robot(int x, int y, int move){
		this->x = x;
		this->y = y;
		this->move = move;
	}
};

void init(){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			v[i][j] = false;
		}
	}
}

void bfs(int x, int y, int now){
	queue<robot> q;
	v[x][y] = true;
	q.push(robot(x,y,0));
	while(!q.empty()){
		robot cur = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w||map[nx][ny]=='x'||v[nx][ny]) continue;
			if(0<=map[nx][ny] && map[nx][ny]<=10){
				dis[now][map[nx][ny]] = cur.move+1;
				dis[map[nx][ny]][now] = cur.move+1;
			}
			v[nx][ny] = true;
			q.push(robot(nx,ny,cur.move+1));
		}	
	}
}

void dfs(int now, int k, int depth, int move){
	if(depth == k){
		if(move < ans)
			ans = move;
		return;
	}
	for(int i=0; i<k; i++){
		if(visit[i]) continue;
		if(dis[now][i] < 0) return;
		visit[i] = true;
		dfs(i, k, depth+1, move+dis[now][i]);
		visit[i] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while(true){
		cin>>w>>h;
		if(w==0 && h==0) break;
		int k = 0;
		int start;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin>>map[i][j];
				if(map[i][j] == 'o'){
					start = k;
					map[i][j] = k;
					k++;
				}
				if(map[i][j] == '*'){
					map[i][j] = k;
					k++;
				}
			}
		}
		
		for(int i=0; i<k; i++){
			for(int j=0; j<k; j++)
				dis[i][j] = -1;
		}
	
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(map[i][j] == k-1) break;
				if(0 <= map[i][j] && map[i][j] <= 10){
					init();
					bfs(i, j, map[i][j]);
					map[i][j] = '.';
				}
			}
		}
		
		visit[start] = true;
		ans = INF;
		dfs(start, k, 1, 0);
		visit[start] = false;
		
		if(ans == INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	
	return 0;
}
