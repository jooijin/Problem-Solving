// 미완성

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool flag;
    
    for(int i=0; i<skill_trees.size(); i++) {
        for(int j=0; j<skill_trees[i].size(); j++) {
            flag = false;
            for(int k=0; k<skill.size(); k++){
                if(skill_trees[i][j] == skill[k]) { 
                    flag = true;
                    break;
                }
                else
                    flag = false;
            }
            if flag = false;
        }
    }
    
    return answer;
}
