// 1991

/*
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.



예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다.
각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
*/

#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int N;
char arr[26][2];
string str = "";

void preord(int curr){
	str += (curr+'A');
	if(arr[curr][0] != 0)
		preord(arr[curr][0]);
	if(arr[curr][1] != 0)
		preord(arr[curr][1]);
}
void inord(int curr){
	if(arr[curr][0] != 0){
		inord(arr[curr][0]);
	}
	str += (curr+'A');
	if(arr[curr][1] != 0){
		inord(arr[curr][1]);
	}
}
void postord(int curr){
	if(arr[curr][0] != 0){
		postord(arr[curr][0]);
	}
	if(arr[curr][1] != 0){
		postord(arr[curr][1]);
	}
	str += (curr+'A');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>N;
	for(int i=0; i<N; i++){
		char n;
		cin>>n;
		char l, r;
		cin>>l>>r;
		if(l != '.')
			arr[n-'A'][0] = l-'A';
		if(r != '.')
			arr[n-'A'][1] = r-'A';
	}
	str = "";
	preord(0);
	cout<<str<<endl;
	str = "";
	inord(0);
	cout<<str<<endl;
	str = "";
	postord(0);
	cout<<str<<endl;
	
	return 0;
}
