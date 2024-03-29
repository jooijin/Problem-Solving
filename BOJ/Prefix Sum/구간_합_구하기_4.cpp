// 11659

/*
문제
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 
수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.
*/

#include <iostream>
#define endl '\n'

using namespace std;

int N, M;
int sum[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        int num;
        cin>>num;
        sum[i] += sum[i-1]+num;
    }
    for(int i=0; i<M; i++){
        int x,y;
        cin>>x>>y;
        cout<<sum[y]-sum[x-1]<<endl;
    }
    
    return 0;
}
