#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        vector<int> temp;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++) {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);
        temp.clear();
    }
    
    return answer;
}

// for 문 하나만으로 풀 수 있다

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        vector<int> temp;
        temp = array;
        sort(temp.begin()+commands[i][0]-1, temp.begin()+commands[i][1]);
        answer.push_back(temp[commands[i][0]+commands[i][2]-1]);
    }
    
    return answer;
}
