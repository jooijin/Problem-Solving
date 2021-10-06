// 18870

/*
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>N;
	vector<int> v(N);
	for(int i=0; i<N; i++){
		cin>>v[i];
	}
	vector<int> tmp(v);
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	
	for(int i=0; i<N; i++){
		cout<<lower_bound(tmp.begin(),tmp.end(),v[i])-tmp.begin()<<" ";
	}
	
	return 0;
}
