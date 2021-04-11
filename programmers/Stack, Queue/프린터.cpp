#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int temp;
    bool flag = false;

    for (; priorities.empty() != true ; location--)
    {
        temp = priorities[0];
        priorities.erase(priorities.begin());
        flag = false;
        for(int j=0; j<priorities.size(); j++)
        {
            if (temp< priorities[j])
                flag = true;
        }
        if (flag == true)
            priorities.push_back(temp);
        else
            answer++;
        if (location == 0)
        {
            if (flag == true)
                location += (priorities.size());
            else
                return answer;
        }
    }    

    return answer;
}
