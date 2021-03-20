// 11726

#include <stdio.h>

using namespace std;

int dp[1001];

void DP(int n){
	for(int i=2; i<=n; i++)
		dp[i] = (dp[i-1]+dp[i-2])%10007;
}

int main(){
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 1;
	
	DP(n);
	printf("%d", dp[n]);
	
	return 0;
}
