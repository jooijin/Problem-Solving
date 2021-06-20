// 2610
/*
문제
KOI 준비를 위해 회의를 개최하려 한다. 
주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다. 
위원회를 구성하는 방식은 다음과 같다.

서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 
각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다. 
그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다. 
대표에게 의견을 전달하는 경로가 여러 개 있을 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며 이때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.

위원회에서 모든 참석자들의 의사전달시간 중 최댓값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.

예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 서로 알고 있다고 하자. 
1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서 2번을 거쳐야만 한다. 
반대로 3번이 대표가 되어도 1번이 대표인 3번에게 의견을 전달하려면 2번을 거쳐야만 한다. 
하지만 2번이 대표가 되면 1번과 3번 둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 
따라서 이와 같은 경우 2번이 대표가 되어야 한다.

입력
첫째 중에 회의에 참석하는 사람의 수 N이 주어진다. 
참석자들은 1부터 N까지의 자연수로 표현되며 회의에 참석하는 인원은 100 이하이다. 
둘째 줄에는 서로 알고 있는 관계의 수 M이 주어진다. 
이어 M개의 각 줄에는 서로 아는 사이인 참석자를 나타내는 두개의 자연수가 주어진다.

출력
첫째 줄에는 구성되는 위원회의 수 K를 출력한다. 
다음 K줄에는 각 위원회의 대표 번호를 작은 수부터 차례로 한 줄에 하나씩 출력한다. 
한 위원회의 대표가 될 수 있는 사람이 둘 이상일 경우 그중 한 명만 출력하면 된다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool arr[101][101];
bool visit[101];
vector<int> ans;

void floydWarshall(vector<int> grp){
    int size = grp.size();
    if(size == 1){ans.push_back(grp[0]); return;}
    int d[101][101];
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (i == j) d[i][j] = 0;
            else if(arr[grp[i]][grp[j]] == true) d[i][j] = 1;
            else d[i][j] = size+1;
        }
    }
    
    for(int k=0; k<size; k++){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    // 위원장
    int rep;
    int tmp = size+1;
    
    for(int i=0; i<size; i++){
        // 정점으로부터 다른 정점까지의 거리의 최대값이 제일 작은 정점 -> 위원장
        int dis = 0;
        for(int j=0; j<size; j++){
            dis = max(dis, d[i][j]);
        }
        if(dis < tmp){
            tmp = dis;
            rep = grp[i];
        }
    }
    
    ans.push_back(rep);
}

void bfs(int V){
    // 위원회 회원들을 담을 벡터 grp
    vector<int> grp;
    queue<int> q;
    q.push(V);
    visit[V] = true;
    
    while(!q.empty()) {
        V = q.front();
        grp.push_back(V);
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == true || arr[i][V] == false) continue;
            q.push(i);
            visit[i] = true;
        }
    }
    floydWarshall(grp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        arr[a][b] = arr[b][a] = true;
    }
    
    for(int i=1; i<=N; i++){
        // 위원회 구성
        if(!visit[i])
            bfs(i);
    }
    
    cout<<ans.size()<<endl;
    
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
