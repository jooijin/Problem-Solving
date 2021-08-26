// 11053

/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/

#include <iostream>

using namespace std;

int N;
int A[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    for(int i=1; i<=N; i++){
    	cin>>A[i];
	}
	
	dp[1] = 1;
	
	for(int i=2; i<=N; i++){
		for(int j=0; j<i; j++){
			if(A[j] < A[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int max = 0;
	for(int i=1; i<=N; i++){
		if(max < dp[i])
			max = dp[i];
	}
    
    cout<<max<<'\n';
    
    return 0;
}
