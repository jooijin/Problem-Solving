// 17472

/*
문제
섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 한다. 
이 나라의 지도는 N×M 크기의 이차원 격자로 나타낼 수 있고, 격자의 각 칸은 땅이거나 바다이다.

섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 말하고, 아래 그림은 네 개의 섬으로 이루어진 나라이다. 색칠되어있는 칸은 땅이다.



다리는 바다에만 건설할 수 있고, 다리의 길이는 다리가 격자에서 차지하는 칸의 수이다. 
다리를 연결해서 모든 섬을 연결하려고 한다. 
섬 A에서 다리를 통해 섬 B로 갈 수 있을 때, 섬 A와 B를 연결되었다고 한다. 
다리의 양 끝은 섬과 인접한 바다 위에 있어야 하고, 한 다리의 방향이 중간에 바뀌면 안된다. 
또, 다리의 길이는 2 이상이어야 한다.

다리의 방향이 중간에 바뀌면 안되기 때문에, 다리의 방향은 가로 또는 세로가 될 수 밖에 없다. 
방향이 가로인 다리는 다리의 양 끝이 가로 방향으로 섬과 인접해야 하고, 방향이 세로인 다리는 다리의 양 끝이 세로 방향으로 섬과 인접해야 한다.

섬 A와 B를 연결하는 다리가 중간에 섬 C와 인접한 바다를 지나가는 경우에 섬 C는 A, B와 연결되어있는 것이 아니다. 

아래 그림은 섬을 모두 연결하는 올바른 2가지 방법이고, 다리는 회색으로 색칠되어 있다. 
섬은 정수, 다리는 알파벳 대문자로 구분했다.

	
다리의 총 길이: 13

D는 2와 4를 연결하는 다리이고, 3과는 연결되어 있지 않다.

다리의 총 길이: 9 (최소)

다음은 올바르지 않은 3가지 방법이다

		
C의 방향이 중간에 바뀌었다	D의 길이가 1이다.	
가로 다리인 A가 1과 가로로 연결되어 있지 않다.
다리가 교차하는 경우가 있을 수도 있다. 교차하는 다리의 길이를 계산할 때는 각 칸이 각 다리의 길이에 모두 포함되어야 한다. 
아래는 다리가 교차하는 경우와 기타 다른 경우에 대한 2가지 예시이다.

	
A의 길이는 4이고, B의 길이도 4이다.

총 다리의 총 길이: 4 + 4 + 2 = 10

다리 A: 2와 3을 연결 (길이 2)

다리 B: 3과 4를 연결 (길이 3)

다리 C: 2와 5를 연결 (길이 5)

다리 D: 1과 2를 연결 (길이 2)

총 길이: 12

나라의 정보가 주어졌을 때, 모든 섬을 연결하는 다리 길이의 최솟값을 구해보자.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. 둘째 줄부터 N개의 줄에 지도의 정보가 주어진다. 
각 줄은 M개의 수로 이루어져 있으며, 수는 0 또는 1이다. 0은 바다, 1은 땅을 의미한다.

출력
모든 섬을 연결하는 다리 길이의 최솟값을 출력한다. 모든 섬을 연결하는 것이 불가능하면 -1을 출력한다.

제한
1 ≤ N, M ≤ 10
3 ≤ N×M ≤ 100
2 ≤ 섬의 개수 ≤ 6
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int arr[10][10];
bool visit[10][10];
int root[6];
int N, M;
vector<pair<int,int>> land[6];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dis[6][6];

int getParent(int x){
    if(root[x] == x) return x;
    return root[x] = getParent(root[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) root[b] = a;
    else root[a] = b;
}

bool find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    return false;
}

// 섬을 노드로 섬사이의 거리를 edge로
class Edge{
public:
    int node[2];
    int cost;
    Edge(int a, int b, int cost){
        this->node[0] = a;
        this->node[1] = b;
        this->cost = cost;
    }
    bool operator <(Edge &edge){
        return this->cost < edge.cost;
    }
};

void bfs(int i, int j, int num){
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] == true;
    arr[i][j] += num;
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = now.first+dx[i], ny = now.second+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(!visit[nx][ny] && arr[nx][ny] == 1){
                visit[nx][ny] = true;
                arr[nx][ny] += num;
                land[num].push_back({nx,ny});
                q.push({nx,ny});
            }
        }
    }
}

void dfs(pair<int, int> now, int n, int start, int des, int cost){
    // n 탐색할 방향 des 목적지 섬
    int nx = now.first + dx[n];
    int ny = now.second + dy[n];
    if(nx<0 || nx>=N || ny<0 || ny>=M) return;
    if(arr[nx][ny] != 0){
        if(arr[nx][ny] != des || cost < 2) return;
        if(arr[nx][ny] == des && dis[start-1][des-1]>cost){
            dis[start-1][des-1] = cost;
            dis[des-1][start-1] = cost;
        }
        return;
    }
    else
    	dfs(make_pair(nx, ny), n, start, des, cost+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    // 섬에 번호 붙여줌
    int num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1 && !visit[i][j]){
                land[num].push_back({i,j});
                bfs(i, j, num);
                num++;
            }
        }
    }
    // dis 초기화
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            dis[i][j] = 101;
        }
    }
    // 섬에서 섬끼리 길이 구함
    for(int i=0; i<num; i++){
        for(int j=0; j<land[i].size(); j++){
            // 자기 자신보다 번호가 작은 섬까지의 최적 거리는 이미 구해져있음
            for(int des=i+1; des<num; des++){
                for(int n=0; n<4; n++){
                    dfs(land[i][j], n, i+1, des+1, 0);
                }
            }
        }
    }
    // root 초기화
    for(int i=0; i<num; i++){
        root[i] = i;
    }
    vector<Edge> v; // 노드 정보 저장
    // Edge 정보 저장
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            v.push_back(Edge(i,j,dis[i][j]));
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0; i<num; i++){
        if(!find(v[i].node[0], v[i].node[1])){
            ans += v[i].cost;
            unionParent(v[i].node[0], v[i].node[1]);
        }
    }
    if(ans >= 101)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    
    return 0;
}
