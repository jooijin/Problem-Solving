// 11051

// 이항 계수는 파스칼의 삼각형으로
// 수학을 너무 안했더니 이산수학 문제를 못풀겠다.. 고등학교 확통문제집이라도 봐야겠다

/*
문제
자연수 N과 정수 K가 주어졌을 때 이항 계수 NCK를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)

출력
 
NCK를 10,007로 나눈 나머지를 출력한다.
*/

#include <iostream>

using namespace std;

int N, K;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>K;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=N; i++){
    	dp[i][0] = 1;
    	dp[i][i] = 1;
    	for(int j=1; j<i; j++)
    		dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
	}
	
	cout<<dp[N][K]<<'\n';
    
    return 0;
}
