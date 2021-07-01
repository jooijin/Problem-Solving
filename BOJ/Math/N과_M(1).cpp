// 15649

//못 풀었다... 다른 사람의 코드를 참고하였다
//[출처]https://jaimemin.tistory.com/1237 이 분의 코드를 참고함
//백트래킹과 재귀함수 잘 쓰는법을 더 공부해야될거같다 N과 M 시리즈 다 풀기

/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.


*/

#include <iostream>

using namespace std;

#define MAX 9

int N, M;
int arr[MAX];
bool v[MAX];

void permut(int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(!v[i]){
            v[i] = true;
            arr[cnt] = i;
            permut(cnt+1);
            v[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N>>M;
    permut(0);
    
    return 0;
}
