#include <string>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

bool visit[31][31];

vector<string> reArray(int m, int n, vector<string> board) {
    for(int j=0; j<n; j++) {
        for(int i=0; i<m-1; i++) {
            if(board[i][j] != '0' && board[i+1][j] == '0'){
                board[i+1][j] = board[i][j];
                board[i][j] = '0';
                i = -1;
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int, int>> del;
        
    while(true) {
        memset(visit, false, sizeof(visit));
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(board[i][j] == '0') continue;
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]) {
                    del.push_back(make_pair(i, j));
                }
            }
        }
    
        if (del.size() == 0)
            break;
    
        while(del.size()>0) {
            pair<int, int> temp = del.back();
            del.pop_back();
            if(!visit[temp.first][temp.second]) {
                board[temp.first][temp.second] = '0';
                visit[temp.first][temp.second] = true;
                answer++;
            }
            if(!visit[temp.first][temp.second+1]) {
                board[temp.first][temp.second+1] = '0';
                visit[temp.first][temp.second+1] = true;
                answer++;
            }
            if(!visit[temp.first+1][temp.second]) {
                board[temp.first+1][temp.second] = '0';
                visit[temp.first+1][temp.second] = true;
                answer++;
            }
            if(!visit[temp.first+1][temp.second+1]) {
                board[temp.first+1][temp.second+1] = '0';
                visit[temp.first+1][temp.second+1] = true;
                answer++;
            }
        }
        
        board = reArray(m, n, board);
    }
    
    return answer;
}
