// 3197

/*
문제
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.

호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.

호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 
두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.

아래에는 세 가지 예가 있다.

...XXXXXX..XX.XXX ....XXXX.......XX .....XX.......... 
....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... 
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... 
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX.... 
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... 
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ 
..XXXXX...XXX.... ....XX.....X..... ................. 
....XXXXX.XXX.... .....XX....X..... ................. 
      처음               첫째 날             둘째 날
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.

며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.

다음 R개의 줄에는 각각 길이 C의 문자열이 하나씩 주어진다. '.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define endl '\n'

using namespace std;

int R, C;
int day = 0;
char arr[1500][1500];
bool v[1500][1500];
vector<pair<int,int> > swans;
queue<pair<int,int> > water;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>R>>C;
    for(int i=0; i<R; i++){
        string str;
        cin>>str;
        for(int j=0; j<C; j++){
            arr[i][j] = str[j];
            if(arr[i][j] == 'L'){
                swans.push_back({i,j});
                water.push({i,j});
                arr[i][j] = '.';
            }
            else if(arr[i][j] == '.') water.push({i,j});
        }
    }
    
    queue<pair<int,int> > swan;
    swan.push(swans[0]);
    v[swans[0].first][swans[0].second] = true;
    while(true){
    	queue<pair<int,int> > nSwan;
	    while(!swan.empty()){
	        int y = swan.front().first;
	        int x = swan.front().second;
	        swan.pop();
	        for(int i=0; i<4; i++){
	            int ny = y + dy[i];
	            int nx = x + dx[i];
	            if(nx<0 || nx>=C || ny<0 || ny>=R || v[ny][nx]) continue;
	            else if(swans[1] == make_pair(ny, nx)){
	            	cout<<day<<endl;
	            	return 0;
				}
	            else if(arr[ny][nx] == 'X') nSwan.push({ny,nx});
				else swan.push({ny,nx});
				v[ny][nx] = true;
	        }
	    }
	    swan = nSwan;
	    day++;
	    
	    int n = water.size();
	    while(n--){
	    	int y = water.front().first;
	        int x = water.front().second;
	        water.pop();
	        for(int i=0; i<4; i++){
	            int ny = y + dy[i];
	            int nx = x + dx[i];
	            if(nx<0 || nx>=C || ny<0 || ny>=R) continue;
				else if(arr[ny][nx] == 'X'){
	                water.push({ny,nx});
	                arr[ny][nx] = '.';
	            }
	        }
		}
	}
    
    return 0;
}
