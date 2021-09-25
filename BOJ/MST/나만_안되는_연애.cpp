// 14621

/*
문제
깽미는 24살 모태솔로이다. 깽미는 대마법사가 될 순 없다며 자신의 프로그래밍 능력을 이용하여 미팅 어플리케이션을 만들기로 결심했다. 
미팅 앱은 대학생을 타겟으로 만들어졌으며 대학교간의 도로 데이터를 수집하여 만들었다.

이 앱은 사용자들을 위해 사심 경로를 제공한다. 이 경로는 3가지 특징을 가지고 있다.

사심 경로는 사용자들의 사심을 만족시키기 위해 남초 대학교와 여초 대학교들을 연결하는 도로로만 이루어져 있다.
사용자들이 다양한 사람과 미팅할 수 있도록 어떤 대학교에서든 모든 대학교로 이동이 가능한 경로이다.
시간을 낭비하지 않고 미팅할 수 있도록 이 경로의 길이는 최단 거리가 되어야 한다.
만약 도로 데이터가 만약 왼쪽의 그림과 같다면, 오른쪽 그림의 보라색 선과 같이 경로를 구성하면 위의 3가지 조건을 만족하는 경로를 만들 수 있다.



이때, 주어지는 거리 데이터를 이용하여 사심 경로의 길이를 구해보자.

입력
입력의 첫째 줄에 학교의 수 N와 학교를 연결하는 도로의 개수 M이 주어진다. (2 ≤ N ≤ 1,000) (1 ≤ M ≤ 10,000)

둘째 줄에 각 학교가 남초 대학교라면 M, 여초 대학교라면 W이 주어진다.

다음 M개의 줄에 u v d가 주어지며 u학교와 v학교가 연결되어 있으며 이 거리는 d임을 나타낸다. (1 ≤ u, v ≤ N) , (1 ≤ d ≤ 1,000)

출력
깽미가 만든 앱의 경로 길이를 출력한다. (모든 학교를 연결하는 경로가 없을 경우 -1을 출력한다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int N, M;
int sex[1000]; //0 man 1 woman
int root[1000];

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) root[b] = a;
    else root[a] = b;
}

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>M;
    for(int i=1; i<=N; i++){
    	root[i] = i;
	}
    for(int i=1; i<=N; i++){
        char c;
        cin>>c;
        if(c == 'M')
            sex[i] = 0;
        else
            sex[i] = 1;
    }
    vector<Edge> v;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v.push_back(Edge(a,b,c));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int num = 0;
    for(int i=0; i<v.size(); i++){
        if(find(v[i].node[0]) != find(v[i].node[1]) && sex[v[i].node[0]] != sex[v[i].node[1]]){
            ans += v[i].cost;
            num++;
            unite(v[i].node[0], v[i].node[1]);
        }
    }
    if(num < N-1) 
		cout<<-1<<endl;
    else
    	cout<<ans<<endl;
    
    return 0;
}
