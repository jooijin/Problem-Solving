// 1789

/*
문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.
*/

#include <iostream>
#define endl '\n'

using namespace std;

unsigned int S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>S;
    int sum = 1;
    int N = 1;
    for(int i=2; i<S-sum; i++){
        sum += i;
        N++;
    }
    cout<<N<<endl;
    
    return 0;
}
