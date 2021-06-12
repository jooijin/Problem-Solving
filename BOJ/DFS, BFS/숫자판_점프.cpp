// 2210
/*
문제
5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다. 
이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다. 
이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.

숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.

입력
다섯 개의 줄에 다섯 개의 정수로 숫자판이 주어진다.

출력
첫째 줄에 만들 수 있는 수들의 개수를 출력한다.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[6][6];
vector<string> nums;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
    
int dfs(int x, int y, int dep, string str){
    if(dep == 5){
        if(find(nums.begin(), nums.end(), str) == nums.end()){
            nums.push_back(str);
        }
        return 0;
    }
    
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=5 || ny >= 5) continue;
        dfs(nx, ny, dep+1, str+to_string(arr[nx][ny]));
    }
    
    return 0;
}

int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d",&arr[i][j]);    
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs(i,j,0,to_string(arr[i][j]));
        }
    }
    
    printf("%d\n",nums.size());
    
    return 0;
}
