// 못풀었다... 이건 다른 사람의 답안이다 내 방식으로 다시 정리해서 업로드 할 계획
// 플로이드-와샬

/*
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define inf 1987654321
int res[3][201];
struct Node {
    vector<pair<int,int>> next;
};
Node node[201];
void dij(int idx, int n, int start) {
    res[idx][start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ -0, start });
    for (int i = 1; i <= n; i++) res[idx][i] = inf;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (res[idx][cur.second] != inf) continue;
        int cost = -cur.first;
        res[idx][cur.second] = cost;
        for (int i = 0; i < node[cur.second].next.size(); i++) {
            auto next = node[cur.second].next[i];
            if (res[idx][next.second] != inf) continue;
            pq.push({ -(cost + next.first), next.second});
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i < fares.size(); i++) {
        node[fares[i][0]].next.push_back({ fares[i][2] ,fares[i][1] });
        node[fares[i][1]].next.push_back({ fares[i][2] ,fares[i][0] });
    }
    dij(0, n, s);
    dij(1, n, a);
    dij(2, n, b);
    answer = inf;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, res[0][i] + res[1][i] + res[2][i]);
    }
    return answer;
}
*/
