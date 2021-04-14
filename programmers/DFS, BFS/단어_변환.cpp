// 전형적인 dfs 문제인 것 같다
// depth를 잘 활용하는 걸 잊지말자... 여러개의 루트를 확인하는 문제에서는 visit 다시 false로 해주는것도!

#include <string>
#include <vector>

using namespace std;

int min_dep = 51;
bool visit[51];

int dfs(string now, string target, vector<string> words, int depth) {
    if(now == target){
        if(depth < min_dep)
            min_dep = depth;
        return 0;
    }
    
    for(int i=0; i<words.size(); i++) {
        int cnt=0;
        for(int j=0; j<now.size(); j++) {
            if(now[j] != words[i][j])
                cnt++;
        }
        if(cnt == 1 && !visit[i]) {
            visit[i] = true;
            dfs(words[i], target, words, depth+1);
            visit[i] = false;
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    dfs(begin, target, words, 0);
    
    answer = min_dep;
    
    if(answer == 51)
        return 0;
    
    return answer;
}
