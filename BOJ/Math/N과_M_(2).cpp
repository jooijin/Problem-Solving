// 15650

/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.


*/

#include <iostream>

using namespace std;

int N,M;

void solve(int arr[], int cnt){
    if(cnt == M){
        for(int i=1; i<=M; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=arr[cnt]+1; i<=N-M+cnt+1; i++){
        arr[cnt+1] = i;
        solve(arr, cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=1; i<=N-M+1; i++){
        int arr[9];
        arr[1] = i;
        solve(arr, 1);
    }
    
    return 0;
}
