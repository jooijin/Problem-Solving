#include <string>
#include <vector>

using namespace std;

bool arr[201][201];
bool visited[201];

void dfs(int start, int n) {
    visited[start] = true;
    for(int i=0; i<n; i++) {
        if(visited[i] || !arr[start][i]) continue;
        dfs(i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = arr[j][i] = computers[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i]){
            dfs(i, n);
            answer++;
        }
    }
    
    return answer;
}
