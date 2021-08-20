// 16234

// 비효율적으로 푼 것 같다.. 나중에 수정해야지

/*
문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 
각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 
인접한 나라 사이에는 국경선이 존재한다. 
모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.

오늘부터 인구 이동이 시작되는 날이다.

인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)

둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. 
r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)

인구 이동이 발생하는 일수가 2,000번 보다 작거나 같은 입력만 주어진다.

출력
인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, L, R, A[50][50], tmp[50][50];
bool v[50][50], mv;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init(){
	mv = false;
    for(int i=0; i<N; i++){
    	memset(v[i], false, N);
    	for(int j=0; j<N; j++){
    		tmp[i][j] = A[i][j];
		}
	}
}

void bfs(int x, int y){
	int cnt = 1, tot = tmp[x][y];
	queue<pair<int, int>> q;
	queue<pair<int, int>> chg;
	q.push(make_pair(x, y));
	chg.push(make_pair(x, y));
	v[x][y] = true;
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(!v[nx][ny] && L <= abs(tmp[p.first][p.second] - tmp[nx][ny]) && abs(tmp[p.first][p.second] - tmp[nx][ny]) <= R){
				mv = true;
				q.push(make_pair(nx, ny));
				v[nx][ny] = true;
				cnt++;
				tot += tmp[nx][ny];
				chg.push(make_pair(nx, ny));
			}
		}
	}
	
	int n = tot/cnt;
	while(!chg.empty()){
		pair<int, int> p = chg.front();
		chg.pop();
		A[p.first][p.second] = n;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int day = 0;
	cin>>N>>L>>R;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>A[i][j];
		}
	}
    
    while(true){
    	init();
	    for(int x=0; x<N; x++){
	    	for(int y=0; y<N; y++){
	    		if(!v[x][y])
				bfs(x, y);
			}
		}
		if(!mv) break;
		day++;
	}
	
	cout<<day<<'\n';
	    
    return 0;
}
