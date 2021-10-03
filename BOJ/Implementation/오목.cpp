// 2615

/*
문제
오목은 바둑판에 검은 바둑알과 흰 바둑알을 교대로 놓아서 겨루는 게임이다. 
바둑판에는 19개의 가로줄과 19개의 세로줄이 그려져 있는데 가로줄은 위에서부터 아래로 1번, 2번, ... ,19번의 번호가 붙고 세로줄은 왼쪽에서부터 오른쪽으로 1번, 2번, ... 19번의 번호가 붙는다.



위의 그림에서와 같이 같은 색의 바둑알이 연속적으로 다섯 알을 놓이면 그 색이 이기게 된다. 
여기서 연속적이란 가로, 세로 또는 대각선 방향 모두를 뜻한다. 즉, 위의 그림은 검은색이 이긴 경우이다. 
하지만 여섯 알 이상이 연속적으로 놓인 경우에는 이긴 것이 아니다.

입력으로 바둑판의 어떤 상태가 주어졌을 때, 검은색이 이겼는지, 흰색이 이겼는지 또는 아직 승부가 결정되지 않았는지를 판단하는 프로그램을 작성하시오. 
단, 검은색과 흰색이 동시에 이기거나 검은색 또는 흰색이 두 군데 이상에서 동시에 이기는 경우는 입력으로 들어오지 않는다.

입력
19줄에 각 줄마다 19개의 숫자로 표현되는데, 검은 바둑알은 1, 흰 바둑알은 2, 알이 놓이지 않는 자리는 0으로 표시되며, 숫자는 한 칸씩 띄어서 표시된다.

출력
첫줄에 검은색이 이겼을 경우에는 1을, 흰색이 이겼을 경우에는 2를, 아직 승부가 결정되지 않았을 경우에는 0을 출력한다. 
검은색 또는 흰색이 이겼을 경우에는 둘째 줄에 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알
(연속된 다섯 개의 바둑알이 세로로 놓인 경우, 그 중 가장 위에 있는 것)의 가로줄 번호와, 세로줄 번호를 순서대로 출력한다.
*/

#include <iostream>
#define endl '\n'

using namespace std;

int arr[20][20];
bool visit[20][20][4];
                            // 0 세로 1 가로 1 왼쪽 대각 2 오른쪽 대각
bool isWinner(int r, int c, int n){
    int dol = arr[r][c];
    visit[r][c][n] = true;
    int cnt = 1;
    if(n == 0){
        r++;
        while(arr[r][c] == dol && r<19){
            visit[r][c][n] = true;
            cnt++;
            r++;
        }
        if(cnt == 5){
        	cout<<arr[r-5][c]<<endl;
            cout<<r+1-5<<" "<<c+1<<endl;
            return true;
		}
    }
    else if(n == 1){
        c++;
        while(arr[r][c] == dol && c<19){
            visit[r][c][n] = true;
            cnt++;
            c++;
        }
        if(cnt == 5){
        	cout<<arr[r][c-5]<<endl;
            cout<<r+1<<" "<<c+1-5<<endl;
            return true;
		}
    }
    else if(n == 2){
        r++;
        c--;
        while(arr[r][c] == dol && 0<=r && c<19){
            visit[r][c][n] = true;
            cnt++;
            r++;
            c--;
        }
        if(cnt == 5){
        	cout<<arr[r-5][c+5]<<endl;
            cout<<r<<" "<<c+2<<endl;
            return true;
		}
    }
    else{
        r++;
        c++;
        while(arr[r][c] == dol && r<19 && c<19){
            visit[r][c][n] = true;
            cnt++;
            r++;
            c++;
        }
        if(cnt == 5){
        	cout<<arr[r-5][c-5]<<endl;
            cout<<r+1-5<<" "<<c+1-5<<endl;
            return true;
		}
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(arr[i][j] != 0){
                for(int n=0; n<4; n++){
                    if(!visit[i][j][n]){
                        bool win = isWinner(i, j, n);
                        if(win) return 0;
                    }
                }
            }
        }
    }
    cout<<0<<endl;
    
    return 0;
}
