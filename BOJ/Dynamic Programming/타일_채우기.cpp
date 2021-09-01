// 2133

/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다.
*/

#include <iostream>

using namespace std;

int N;
int dp[31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    if(N%2 != 0){
        cout<<0<<'\n';
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=N; i+=2){
    	int sum = 0;
    	for(int j=0; j<=i-4; j+=2)
    		sum += dp[j]*2;
        dp[i] = dp[i-2]*3 + sum;
    }
    
    cout<<dp[N]<<'\n';
    
    return 0;
}
