// 1005

/*
문제
서기 2012년! 드디어 2년간 수많은 국민들을 기다리게 한 게임 ACM Craft (Association of Construction Manager Craft)가 발매되었다.

이 게임은 지금까지 나온 게임들과는 다르게 ACM크래프트는 다이나믹한 게임 진행을 위해 건물을 짓는 순서가 정해져 있지 않다. 
즉, 첫 번째 게임과 두 번째 게임이 건물을 짓는 순서가 다를 수도 있다. 매 게임시작 시 건물을 짓는 순서가 주어진다. 
또한 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 Delay가 존재한다.

 



위의 예시를 보자.

이번 게임에서는 다음과 같이 건설 순서 규칙이 주어졌다. 1번 건물의 건설이 완료된다면 2번과 3번의 건설을 시작할수 있다. (동시에 진행이 가능하다) 
그리고 4번 건물을 짓기 위해서는 2번과 3번 건물이 모두 건설 완료되어야지만 4번건물의 건설을 시작할수 있다.

따라서 4번건물의 건설을 완료하기 위해서는 우선 처음 1번 건물을 건설하는데 10초가 소요된다. 
그리고 2번 건물과 3번 건물을 동시에 건설하기 시작하면 2번은 1초뒤에 건설이 완료되지만 아직 3번 건물이 완료되지 않았으므로 4번 건물을 건설할 수 없다. 
3번 건물이 완성되고 나면 그때 4번 건물을 지을수 있으므로 4번 건물이 완성되기까지는 총 120초가 소요된다.

프로게이머 최백준은 애인과의 데이트 비용을 마련하기 위해 서강대학교배 ACM크래프트 대회에 참가했다! 
최백준은 화려한 컨트롤 실력을 가지고 있기 때문에 모든 경기에서 특정 건물만 짓는다면 무조건 게임에서 이길 수 있다. 
그러나 매 게임마다 특정건물을 짓기 위한 순서가 달라지므로 최백준은 좌절하고 있었다. 
백준이를 위해 특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램을 작성해주자.

입력
첫째 줄에는 테스트케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다. 
첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다) 

둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다. 
셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다) 

마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다.

출력
건물 W를 건설완료 하는데 드는 최소 시간을 출력한다. 
편의상 건물을 짓는 명령을 내리는 데는 시간이 소요되지 않는다고 가정한다.

건설순서는 모든 건물이 건설 가능하도록 주어진다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, N, K;
int dp[1001];
int cost[1001]; // 건설하는데 걸리는 시간
int degree[1001]; // 노드로 들어오는 간선 수
int dest;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T>0){
        cin>>N>>K;
        vector<int> edge[N+1]; // 간선정보
        queue<int> q;
        memset(dp, 0, sizeof(dp));
        memset(degree, 0, sizeof(degree));
        memset(cost, 0, sizeof(cost));
        for(int i=1; i<=N; i++){
            cin>>cost[i];
        }
        for(int i=0; i<K; i++){
            int x, y;
            cin>>x>>y;
            edge[x].push_back(y);
            degree[y]++;
        }
        cin>>dest;
        
        for(int i=1; i<=N; i++){
            if(degree[i] == 0){
                q.push(i);
                dp[i] = cost[i];
            }
        }
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i=0; i<edge[tmp].size(); i++){
                int next = edge[tmp][i];
                dp[next] = max(dp[next], dp[tmp] + cost[next]);
                if(--degree[next] == 0){
                    q.push(next);
                }
            }
        }
        cout<<dp[dest]<<endl;
        T--;
    }
    
    return 0;
}
