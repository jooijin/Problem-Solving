// 5052

/*
문제
전화번호 목록이 주어진다. 이때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.

전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.

예를 들어, 전화번호 목록이 아래와 같은 경우를 생각해보자

긴급전화: 911
상근: 97 625 999
선영: 91 12 54 26
이 경우에 선영이에게 전화를 걸 수 있는 방법이 없다. 전화기를 들고 선영이 번호의 처음 세 자리를 누르는 순간 바로 긴급전화가 걸리기 때문이다. 
따라서, 이 목록은 일관성이 없는 목록이다. 

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50) 각 테스트 케이스의 첫째 줄에는 전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000) 
다음 n개의 줄에는 목록에 포함되어 있는 전화번호가 하나씩 주어진다. 전화번호의 길이는 길어야 10자리이며, 목록에 있는 두 전화번호가 같은 경우는 없다.

출력
각 테스트 케이스에 대해서, 일관성 있는 목록인 경우에는 YES, 아닌 경우에는 NO를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'

using namespace std;

struct Trie{
	bool finish;
	Trie* node[10];
	Trie(){
		for(int i=0; i<10; i++)
			node[i] = NULL;
	}

	void insert(string& s, int idx){
		if(s.size() == idx) return;
		if(node[s[idx]-'0'] == NULL) 
			node[s[idx]-'0'] = new Trie();
		node[s[idx]-'0']->insert(s, idx+1);
	}

	bool find(string& s, int idx){
		if(s.size() == idx) return true;
		if(node[s[idx]-'0'] == NULL)
			return false;
		return node[s[idx]-'0']->find(s, idx+1);
	}
};

void checkNumber(){
	int n; cin>>n;
	vector<string> number;
	Trie* trie = new Trie();
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		number.push_back(str);
	}

	sort(number.begin(), number.end(), greater<>());

	for(int i=0; i<n; i++){
		if(trie->find(number[i], 0)){
			cout<<"NO"<<endl;
			return;
		};
		trie->insert(number[i],0);
	}

	cout<<"YES"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t--){
		checkNumber();
	}

	return 0;
}
