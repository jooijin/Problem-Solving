// 4386

/*
문제
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

입력
첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)

둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.

출력
첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'

using namespace std;

int n;
vector<pair<int,int>> star;
int root[100];

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
    double node[2];
    double cost;
    Edge(double a, double b, double cost){
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
    cin>>n;
    vector<Edge> v;
    for(int i=0; i<n; i++){
        root[i] = i;
    }
    for(int i=0; i<n; i++){
        double x, y;
        cin>>x>>y;
        star.push_back({x,y});
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            v.push_back(Edge(i, j, sqrt(pow(star[i].first-star[j].first,2)+pow(star[i].second-star[j].second,2))));
        }
    }
    sort(v.begin(), v.end());
    double ans = 0;
    for(int i=0; i<v.size(); i++){
        if(find(v[i].node[0]) != find(v[i].node[1])){
            ans += v[i].cost;
            unite(v[i].node[0], v[i].node[1]);
        }
    }
    cout<<fixed;
    cout<<setprecision(2);
    cout<<ans<<endl;
    
    return 0;
}
