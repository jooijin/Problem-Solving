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
