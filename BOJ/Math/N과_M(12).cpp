//15666
/*
문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, arr[9] = {0};
vector<int> num;
bool visit[10001];

void solve(int cnt, int idx){
    if(cnt == M){
        for(int i=1; i<=M; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    
    for(int i=idx; i<num.size(); i++){
        arr[cnt+1] = num[i];
        solve(cnt+1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        if(visit[tmp]) continue;
        num.push_back(tmp);
        visit[tmp] = true;
    }
    
    sort(num.begin(), num.end());
    
    solve(0, 0);
    
    return 0;
}
