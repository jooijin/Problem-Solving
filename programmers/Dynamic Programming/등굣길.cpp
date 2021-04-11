#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    
    for(int i=0; i<puddles.size(); i++) {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if(dp[j][i] == -1) {dp[j][i] = 0; continue;}
            if(j == 1 && i == 1) continue;
            dp[j][i] = (dp[j-1][i] + dp[j][i-1])%1000000007;
        }
    
    answer = dp[m][n];
    
    return answer;
}
