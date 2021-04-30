// 미완성
// 그냥 DFS로 하려고 하면 시간초과
// 정점까지의 최단거리니까 다익스트라를 활용하면 풀릴것 같다.. 다익스트라 구현하는 걸 조금 더 연습하고 수정해야겠다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[51];
bool done[51];
int arr[51][51];

int answer = 1;

void dfs(int start, int cost, int N, int K) {
    if(!done[start] && cost<=K){
        done[start] = true;
        answer++;
    }
    for(int i=2; i<N; i++){
        if(arr[start][i] != 0 && !visit[i]){
            visit[i] = true;
            dfs(i, cost+arr[start][i], N, K);
            visit[i] = false;
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    
    for(int i=0; i<road.size(); i++) {
        if(arr[road[i][0]][road[i][1]] != 0)
            arr[road[i][0]][road[i][1]] = arr[road[i][1]][road[i][0]] = min(road[i][2], arr[road[i][0]][road[i][1]]);
        arr[road[i][0]][road[i][1]] = arr[road[i][1]][road[i][0]] = road[i][2];
    }
    
    dfs(1, 0, N, K);
    
    return answer;
}
