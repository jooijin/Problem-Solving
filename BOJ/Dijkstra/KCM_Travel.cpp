// 10217

// solve.ac 기준 골드1 문제.. 너무 어렵다 사실 이정도는 기업 코테에서 자주 나오진 않는거같다
// 다른 사람들의 코드를 참고해서 풀었다. 처음 생각한 풀이 아이디어는 맞았다.. 하지민 구현할 능력이 부족하다ㅠㅠ

/*
문제
각고의 노력 끝에 찬민이는 2014 Google Code Jam World Finals에 진출하게 되었다. 
구글에서 온 초대장을 받고 기뻐했던 것도 잠시, 찬찬히 읽어보던 찬민이는 중요한 사실을 알아차렸다. 
최근의 대세에 힘입어 구글 역시 대기업답게 비용 감축에 열을 내고 있었던 것이다.

초대장 내용에 의하면 구글은 찬민에게 최대 M원까지의 비용만을 여행비로써 부담해주겠다고 한다. 
인천에서 LA행 직항 한 번 끊어주는게 그렇게 힘드냐고 따지고도 싶었지만, 다가올 결승 대회를 생각하면 대회 외적인 곳에 마음을 쓰고 싶지 않은 것 또한 사실이었다. 
그래서 찬민은 인천에서 LA까지 M원 이하로 사용하면서 도착할 수 있는 가장 빠른 길을 차선책으로 택하기로 하였다.

각 공항들간 티켓가격과 이동시간이 주어질 때, 찬민이 인천에서 LA로 갈 수 있는 가장 빠른 길을 찾아 찬민의 대회 참가를 도와주자.

입력
입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 
그 다음에는 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 줄에는 공항의 수 N (2 ≤ N ≤ 100), 총 지원비용 M (0 ≤ M ≤ 10,000), 티켓정보의 수 K (0 ≤ K ≤ 10,000)가 공백으로 구분되어 주어진다. 
이어서 K개의 줄에 걸쳐 각 티켓의 출발공항 u, 도착공항 v (1 ≤ u, v ≤ N, u ≠ v), 비용 c (1 ≤ c ≤ M, 정수), 그리고 소요시간 d (1 ≤ d ≤ 1,000) 가 공백으로 구분되어 주어진다. 
인천은 언제나 1번 도시이고, LA는 언제나 N번 도시이다

출력
각 테스트 케이스당 한 줄에 찬민이 LA에 도착하는 데 걸리는 가장 짧은 소요시간을 출력한다.

만약, LA에 도착할 수 없는 경우 "Poor KCM"을 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

struct Ticket{
	int arr, cost, time;
};

struct cmp{
	bool operator()(Ticket &a, Ticket &b){
		return a.time > b.time;
	}
};

int N, M, K, ans;
int d[101][10001];
vector<vector<Ticket>> map;

void init(){
	ans = INF;
	map.clear();
	cin>>N>>M>>K;
	map.resize(N+1);
	for(int i=1; i<=N; i++){
		for(int j=0; j<=M; ++j){
			d[i][j] = INF;
		}
	}
    for(int i=0; i<K; i++){
		int u;
		Ticket t;
		cin>>u>>t.arr>>t.cost>>t.time;
		map[u].push_back(t);
	}
		
}

void dijkstra(){
	priority_queue<Ticket, vector<Ticket>, cmp> pq;
	d[1][0] = 0;
	Ticket start;
	start.arr = 1;
	start.cost = 0;
	start.time = 0;
	pq.push(start);
	
	while(!pq.empty()){
		Ticket curr = pq.top();
		pq.pop();
		
		if(d[curr.arr][curr.cost] < start.time) continue;
		
		for(Ticket t : map[curr.arr]){
			Ticket next;
			next.arr = t.arr;
			next.time = d[curr.arr][curr.cost] + t.time;
			next.cost = curr.cost + t.cost;
			if(next.cost > M) continue;
			//if(next.cost > 10000) continue;
			if(d[next.arr][next.cost] > next.time){
				d[next.arr][next.cost] = next.time;
				pq.push(next);
			}
		}
	}
}

void solve(){
	for(int i=0; i<=M; ++i){
		ans = min(ans, d[N][i]);
	}
	if(ans != INF)
		cout<<ans<<'\n';
	else
		cout<<"Poor KCM"<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin>>T;
    while(T>0){
	init();
	dijkstra();
	solve();
	T--;	
    }
	
    return 0;
}
