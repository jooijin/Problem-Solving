// 9663

/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/

#include <stdio.h>
#include <math.h>

using namespace std;

int N;
int board[15];
int ans = 0;

void putQ(int n){
	if(n == N){
		ans++;
		return;
	}
    for(int i=0; i<N; i++){
    	board[n] = i;
    	bool check = true;
    	for(int i=0; i<n; i++){
			if(board[i] == board[n] || n-i == abs(board[n] - board[i])){
				check = false;
				break;
			}
		}
    	if(check){
    		putQ(n+1);
		}
	}
}

int main(){
    scanf("%d", &N);
    putQ(0);
    printf("%d\n", ans);
    
    return 0;
}
