// 2234

/*
문제


대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 
점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다. 
이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.

이 성에 있는 방의 개수
가장 넓은 방의 넓이
하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 
위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.

성은 M × N(1 ≤ M, N ≤ 50)개의 정사각형 칸으로 이루어진다. 
성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

입력
첫째 줄에 두 정수 N, M이 주어진다. 다음 M개의 줄에는 N개의 정수로 벽에 대한 정보가 주어진다. 
벽에 대한 정보는 한 정수로 주어지는데, 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다. 
참고로 이진수의 각 비트를 생각하면 쉽다. 따라서 이 값은 0부터 15까지의 범위 안에 있다.

출력
첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.
*/

#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int N, M;
int num = 1;
int cnt;
int oneroom, tworoom;
int map[51][51];
int ans[51][51];
int wall[] = {1,2,4,8};
bool v[51][51];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int roomsize[2501];
vector<int> adjoin[2501];

void bfs(int x, int y){
	v[x][y] = true;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		cnt++;
		int cx = q.front().first;
		int cy = q.front().second;
		ans[cx][cy] = num;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if(nx<0||nx>=M||ny<0||ny>=N) continue;
			if((wall[i]&map[cx][cy]) == 0 && !v[nx][ny]){
				v[nx][ny] = true;
				q.push({nx,ny});
			}
			else if(ans[nx][ny] != 0 && ans[nx][ny] != num){
				adjoin[num].push_back(ans[nx][ny]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>N>>M;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(!v[i][j]){
				cnt = 0;
				bfs(i,j);
				roomsize[num] = cnt;
				if(cnt > oneroom)
					oneroom = cnt;
				num++;
			}
		}
	}
	
	for(int i=1; i<num; i++){
		for(int j=0; j<adjoin[i].size(); j++){
			if(roomsize[i] + roomsize[adjoin[i][j]] > tworoom)
				tworoom = roomsize[i] + roomsize[adjoin[i][j]];
		}
	}
	
	cout<<num-1<<endl;
	cout<<oneroom<<endl;
	cout<<tworoom<<endl;
	
	return 0;
}
