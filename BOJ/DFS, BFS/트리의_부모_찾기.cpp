// 11725

/*
문제
루트 없는 트리가 주어진다. 
이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 
둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

vector<int> edge[100001];
int parent[100001];

void bfs(){
    queue<int> q;
    q.push(1);
    parent[1] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<edge[curr].size(); i++){
            if(parent[edge[curr][i]] == 0){
                q.push(edge[curr][i]);
                parent[edge[curr][i]] = curr;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin>>N;
	for(int i=0; i<N-1; i++){
		int x, y;
        cin>>x>>y;
		edge[x].push_back(y);
        edge[y].push_back(x);
	}
    bfs();
	for(int i=2; i<=N; i++){
        cout<<parent[i]<<endl;
    }
    
	return 0;
}
