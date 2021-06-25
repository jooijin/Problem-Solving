// 13549

/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/

#include <iostream>
#include <queue>
#define MAX_N 100001

using namespace std;

int N, K;
int d[MAX_N];
bool visit[MAX_N];

void bfs(){
    queue<int> q;
    q.push(N);
    visit[N] = true;
    
    while(!q.empty()){
        int X = q.front();
        q.pop();
        if(0<=X-1){
            if(!visit[X-1]){
                q.push(X-1); 
                visit[X-1] = true; 
                d[X-1] = d[X]+1;
            }
            else{
                if(d[X-1] > d[X]+1){
                    q.push(X-1);
                    d[X-1] = d[X]+1;
                }
            }
        }
        if(X+1<MAX_N){
            if(!visit[X+1]){
                q.push(X+1); 
                visit[X+1] = true; 
                d[X+1] = d[X]+1;
            }
            else{
                if(d[X+1] > d[X]+1){
                    q.push(X+1);
                    d[X+1] = d[X]+1;
                }
            }
        }
        if(2*X<MAX_N){
            if(!visit[2*X]){
                q.push(2*X); 
                visit[2*X] = true; 
                d[2*X] = d[X];
            }
            else{
                if(d[2*X] > d[X]){
                    q.push(2*X);
                    d[2*X] = d[X];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    cin>>N>>K; 
    if(N == K){cout<<0<<endl; return 0;}
    
    bfs();
    
    cout<<d[K]<<endl;
    
    return 0;
}
