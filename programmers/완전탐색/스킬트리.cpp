#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool flag;
    
    for(int i=0; i<skill_trees.size(); i++) {
        flag = true;
        for(int j=0; j<skill.size()-1; j++) {
            if(skill_trees[i].find(skill[j]) > skill_trees[i].find(skill[j+1]) && skill_trees[i].find(skill[j+1]) != -1) {
                flag = false;
                break;
            }
            if(skill_trees[i].find(skill[j]) == -1) {
                for(int k=j+1; k<skill.size(); k++) {
                    if(skill_trees[i].find(skill[k]) != -1)
                        flag = false;
                }
                break;
            }
        }
        if(flag == true)
            answer++;
    }
    
    return answer;
}
