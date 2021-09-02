// 20500

// 흑 알고리즘 맞게 짰는데 조금만 더 생각해볼걸,,
// MOD 잘 활용하자

/*
문제
욱제는 15라는 수를 굉장히 싫어한다. 
그래서 0으로 시작하지 않고 1과 5로만 구성된 $N$자리 양의 정수 중에서, 15의 배수가 몇 개인지 궁금해졌다.

참가자 여러분도 궁금하지요?

안 궁금함? 15ㄱ

입력
ㅜ이 주어진다.

출력
문제의 답을 1000000007로 나눈 나머지를 출력한다.
*/

#include <iostream>
#define endl '\n'

using namespace std;

int N, MOD = 1000000007;
int dp[1516][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i=3; i<=N; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }
    cout<<dp[N][0]<<endl;
    
    return 0;
}
