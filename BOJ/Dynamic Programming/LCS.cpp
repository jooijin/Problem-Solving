// 9251

// 못 풀었다.. 다른 사람의 코드를 참고하였다

/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/

#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    string A, B;
    cin>>A>>B;
    for(int i=0; i<A.length(); i++){
    	for(int j=0; j<B.length(); j++){
    		dp[i+1][j+1] = max(dp[i+1][j], max(dp[i][j+1], dp[i][j] + (A[i] == B[j])));
		}
	}
	cout<<dp[A.length()][B.length()]<<'\n';
    
    return 0;
}
