// 9095

#include <stdio.h>

using namespace std;

int dp[12] = {};
int T, n;

int DP(int n){
	for(int i = 3; i<=n; ++i){
		dp[i]=dp[i-1] + dp[i-2]+dp[i-3];
		dp[n]=dp[i];
	}
	return dp[n];
}

int main(){
	scanf("%d", &T);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int n;
	for(int i=0; i<T; i++){
		scanf("%d", &n);
		printf("%d\n", DP(n));
	}
	
	return 0;
}
