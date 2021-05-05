#include <string>
#include <vector>

using namespace std;

int numOfOne(int n){
    int cnt = 0;
    while(n>0) {
        if(n%2 == 1) cnt++;
        n = n/2;
    }
    
    return cnt;
}

int solution(int n) {
    int num = numOfOne(n);
    
    for(int i=n+1; ;i++){
        if(numOfOne(i) == num){
            return i;
        }
    }
}
