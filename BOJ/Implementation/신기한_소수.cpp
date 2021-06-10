// 메모리 초과를 어떻게 해결해야 할 지 모르겠다
// 2023
/*
문제
수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다. 
요즘 수빈이가 가장 관심있어 하는 소수는 7331이다.

7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 
즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 
수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.

수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. 
N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력
N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 줄에 하나씩 출력한다.
*/
#include <stdio.h>
#include <cmath>

using namespace std;

// 1이면 소수 2이면 소수아님 
int prime[99999999];

bool isPrime(int n){
	
	if(prime[n] == 1) return true;
	else if(prime[n] == 2) return false; 
	
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
        	prime[n] = 2;
			return false;
		}
    }
    
    prime[n] = 1;
    return true;
}

int main(){
    int N;
    prime[0] = 2;
	prime[1] = 2;
    scanf("%d", &N);
    
    for(int i=2*pow(10, N-1); i<4*pow(10, N-1); i++){
        bool flag = true;
        for(int j=N-1; j>=0; j--){
            if(!isPrime(i/(int)pow(10, j))){
				flag = false; 
				break;
			}
        }
        if(flag)
            printf("%d\n", i);
    }
    
    for(int i=5*pow(10, N-1); i<6*pow(10, N-1); i++){
        bool flag = true;
        for(int j=N-1; j>=0; j--){
            if(!isPrime(i/(int)pow(10, j))){
				flag = false; 
				break;
			}
        }
        if(flag)
            printf("%d\n", i);
    }
    
    for(int i=7*pow(10, N-1); i<8*pow(10, N-1); i++){
        bool flag = true;
        for(int j=N-1; j>=0; j--){
            if(!isPrime(i/(int)pow(10, j))){
				flag = false; 
				break;
			}
        }
        if(flag)
            printf("%d\n", i);
    }
    
    return 0;
}
