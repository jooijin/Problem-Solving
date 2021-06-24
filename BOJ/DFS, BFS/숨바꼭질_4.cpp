// 13913

/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
//   소요시간    경로
int t[100001], r[100001];

void bfs(int N){
    queue<int> q;
    q.push(N);
    t[N] = 1;
    
    while(!q.empty()){
        N = q.front();
        q.pop();
        if(N == K) return;
        
        if(0<=N-1 && t[N-1] == 0){
            t[N-1] = t[N]+1;
            r[N-1] = N;
            q.push(N-1);
        }
        if(N+1<=100000 && t[N+1] == 0){
            t[N+1] = t[N]+1;
            r[N+1] = N;
            q.push(N+1);
        }
        if(N*2<=100000 && t[N*2] == 0){
            t[N*2] = t[N]+1;
            r[N*2] = N;
            q.push(N*2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> route;
    cin>>N>>K;
    
    if(N == K){
    	cout<<0<<"\n";
    	cout<<N;
    	return 0;
	}
    
    bfs(N);
    int end = K;
    
    cout<<t[end]-1<<endl;
    
    while(r[K] != N){
    	route.push_back(r[K]);
    	K = r[K];
	}
	
	cout<<N<<" ";
	for(int i=t[end]-3; 0<=i ; i--){
		cout<<route[i]<<" ";
	}
	cout<<end;
    
    return 0;
}
