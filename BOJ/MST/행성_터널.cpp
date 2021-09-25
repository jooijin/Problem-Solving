// 2887

/*
문제
때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 
왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.

행성은 3차원 좌표위의 한 점으로 생각하면 된다. 
두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를 터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.

민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 
이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 
다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 
좌표는 -109보다 크거나 같고, 109보다 작거나 같은 정수이다. 
한 위치에 행성이 두 개 이상 있는 경우는 없다. 

출력
첫째 줄에 모든 행성을 터널로 연결하는데 필요한 최소 비용을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int N;
int set[100001];

int getParent(int x){
    if(x == set[x]) return x;
    return set[x] = getParent(set[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) set[b] = a;
    else set[a] = b;
}

bool find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    return false;
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
    cin>>N;
    vector<pair<int,int>> x;
    vector<pair<int,int>> y;
    vector<pair<int,int>> z;
    vector<Edge> v;
    for(int i=0; i<N; i++){
    	set[i] = i;
    	int a,b,c;
    	cin>>a>>b>>c;
    	x.push_back(make_pair(a,i));
    	y.push_back(make_pair(b,i));
    	z.push_back(make_pair(c,i));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(z.begin(),z.end());
	
	for(int i=0; i<N-1; i++){
		v.push_back(Edge(x[i].second,x[i+1].second,x[i+1].first - x[i].first));
		v.push_back(Edge(y[i].second,y[i+1].second,y[i+1].first - y[i].first));
		v.push_back(Edge(z[i].second,z[i+1].second,z[i+1].first - z[i].first));
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i=0; i<v.size(); i++){
		if(!find(v[i].node[0],v[i].node[1])){
            sum += v[i].cost;
            unionParent(v[i].node[0],v[i].node[1]);
        }
	}
	cout<<sum<<endl;
    
    return 0;
}
