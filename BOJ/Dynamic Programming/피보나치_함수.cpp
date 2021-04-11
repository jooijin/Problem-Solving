// 1003

#include <stdio.h>

using namespace std;

int dp[41];
int T, N;

int fib(int N){
	for(int i=2; i<=N; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
    
    return 0;
}

int main(){
	scanf("%d", &T);
	dp[0] = 1; dp[1] = 1;

	for(int i=0; i<T; i++){
		scanf("%d", &N);
		fib(N);
		printf("%d %d\n", dp[N]-dp[N-1],dp[N-1]);
	}

	return 0;
}
