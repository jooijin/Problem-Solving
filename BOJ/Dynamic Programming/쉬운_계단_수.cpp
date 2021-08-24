// 10844

// 아주 전형적인 DP문제이다. 하지만 난 아직 DP 연습을 좀 더 해야할 것 같다..

/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/

#include <iostream>

using namespace std;

int dp[101][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
	cin>>N;
	for(int i=1; i<=9; i++){
		dp[1][i] = 1;
	}
	for(int i=2; i<=N; i++){
		dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
		for(int j=1; j<=8; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
		}
	}
	for(int i=1; i<=9; i++)
		dp[N][0] = (dp[N][0] + dp[N][i])%1000000000;
	
	cout<<dp[N][0]<<'\n';
    
    return 0;
}
