// 내 힘으로 풀지 못해서 다른 사람의 코드를 참고하였다.. https://yabmoons.tistory.com/376

#include <iostream>
#include <queue>
#include <vector>

#define INF 999999

using namespace std;

int V, E, K;
vector<pair<int, int>> ver[20001];
int d[20001];

void dijkstra(){
    priority_queue<pair<int,int>> PQ;
    PQ.push(make_pair(0, K));
    d[K] = 0;
    
    while (PQ.empty() == 0){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < ver[Cur].size(); i++){
            int Next = ver[Cur][i].first;
            int nCost = ver[Cur][i].second;
 
            if (d[Next] > Cost + nCost){
                d[Next] = Cost + nCost;
                PQ.push(make_pair(-d[Next], Next));
            }
        }
    }
    
    for(int i=1; i<=V; i++){
        if(d[i] == INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>V>>E>>K;
    
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        ver[u].push_back(make_pair(v, w));
    }
    for(int i=1; i<=V; i++) d[i] = INF;
    
    dijkstra();
    
    return 0;
}
