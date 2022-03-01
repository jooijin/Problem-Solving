// 1629

/*
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
*/

#include <iostream>
#define endl '\n'

using namespace std;

long long A, B, C;

long long int pow(long long int x, long long int y) {
	if(y == 0)
		return 1;
	else if (y == 1)
		return x;
	if(y%2 > 0)
		return pow(x, y-1)*x;
	long long int half = pow(x, y/2);
	half %= C;
	return (half*half)%C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>A>>B>>C;
    
    cout<<pow(A,B)%C<<endl;
    
    return 0;
}
