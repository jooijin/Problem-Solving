// 11722

/*
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/

#include <iostream>

using namespace std;

int N;
int arr[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    int ans = 0;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
        dp[i] = 1;
        for(int j=1; j<i; j++){
        	if(arr[i-j] > arr[i])
        		dp[i] = max(dp[i],dp[i-j]+1);
		}
		ans = max(ans, dp[i]);
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
