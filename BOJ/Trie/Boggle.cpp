// 9202

/*
문제
상근이는 보드 게임 "Boggle"을 엄청나게 좋아한다. 
Boggle은 글자가 쓰여 있는 주사위로 이루어진 4×4 크기의 그리드에서 최대한 많은 단어를 찾는 게임이다. 

상근이는 한 번도 부인을 Boggle로 이겨본 적이 없다. 
이렇게 질 때마다 상근이는 쓰레기 버리기, 설거지와 같은 일을 해야 한다. 
이제 상근이는 프로그램을 작성해서 부인을 이겨보려고 한다.

Boggle에서 단어는 인접한 글자(가로, 세로, 대각선)를 이용해서 만들 수 있다. 
하지만, 한 주사위는 단어에 한 번만 사용할 수 있다. 단어는 게임 사전에 등재되어 있는 단어만 올바른 단어이다.

1글자, 2글자로 이루어진 단어는 0점, 3글자, 4글자는 1점, 5글자는 2점, 6글자는 3점, 7글자는 5점, 8글자는 11점이다. 
점수는 자신이 찾은 단어에 해당하는 점수의 총 합이다.

단어 사전에 등재되어 있는 단어의 목록과 Boggle 게임 보드가 주어졌을 때, 얻을 수 있는 최대 점수, 가장 긴 단어, 찾은 단어의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어 사전에 들어있는 단어의 수 w가 주어진다. (1 < w < 300,000) 
다음 w개 줄에는 단어가 주어진다. 단어는 최대 8글자이고, 알파벳 대문자로만 이루어져 있다. 
단어 사전에 대한 정보가 모두 주어진 이후에는 빈 줄이 하나 주어진다.

그 다음에는 Boggle 보드의 개수 b가 주어진다. (1 < b < 30) 
모든 Boggle은 알파벳 대문자로 이루어져 있고, 4줄에 걸쳐 주어진다. 
각 Boggle의 사이에는 빈 줄이 하나  있다.

출력
각각의 Boggle에 대해, 얻을 수 있는 최대 점수, 가장 긴 단어, 찾은 단어의 개수를 출력한다. 
한 Boggle에서 같은 단어를 여러 번 찾은 경우에는 한 번만 찾은 것으로 센다. 
가장 긴 단어가 여러 개인 경우에는 사전 순으로 앞서는 것을 출력한다. 
각 Boggle에 대해서 찾을 수 있는 단어가 적어도 한 개인 경우만 입력으로 주어진다.
*/

#include <iostream>
#include <set>
#define enld '\n'

using namespace std;

struct Trie{
	bool finish;
	Trie* node[26];
	
	Trie():finish(false){
		for(int i=0; i<26; i++)
			node[i] = NULL;
	}
	
	void insert(string& s, int idx){
		if(s.size() == idx){
			finish = true;
			return;
		}
		if(node[s[idx]-'A'] == NULL)
			node[s[idx]-'A'] = new Trie();
		node[s[idx]-'A']->insert(s,idx+1);
	}
	
	bool find(string& s, int idx){
		if(s.size() == idx){
			return finish;
		}
		if(node[s[idx]-'A'] == NULL) return false;
		return node[s[idx]-'A']->find(s, idx+1);
	}
};

int w, b;
Trie* trie;
set<string> visited;
bool v[4][4];
char board[4][4];
int scoreboard[] = {0,0,0,1,1,2,3,5,11};
int cnt, score;
string longest;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

void dfs(int x, int y, string target){
	if(trie->find(target,0)){
		if(visited.insert(target).second){
			cnt++;
			score += scoreboard[target.size()];
			if(target.size() > longest.size()){
				longest = target;
			}
			if(target.size() == longest.size()){
				if(longest > target)
					longest = target;
			}
		} 
	}
	
	if(target.size() >= 8) return;
	
	for(int i=0; i<8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 || nx>=4 || ny<0 || ny>=4 || v[nx][ny]) continue;
		v[nx][ny] = true;
		dfs(nx, ny, target+board[nx][ny]);
		v[nx][ny] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	trie = new Trie();
	cin>>w;
	for(int i=0; i<w; i++){
		string s; cin>>s;
		trie->insert(s, 0);
	}
	
	cin>>b;
	while(b--){
		visited.clear();
		cnt = 0; score = 0;
		longest = "";
		
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin>>board[i][j];
				v[i][j] = false;
			}
		}

		string target = "";

		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				v[i][j] = true;
				dfs(i, j, target+board[i][j]);
				v[i][j] = false;
			}
		}
		
		cout<<score<<" "<<longest<<" "<<cnt<<endl;
	}
	
	return 0;
}
