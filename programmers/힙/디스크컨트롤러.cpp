// OS 시간에 배웠던 SJF 스케줄링을 떠올리며 작성하였다
// 변수가 너무 많은 것 같아 추후에 좀 더 깔끔하게 정리해야겠다

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0;
    int min;
    int index;
    int sum=0;
    int size = jobs.size();
    
    while (!jobs.empty())
    {
        min = 1000;
        index = -1;
        
        for(int j=0; j<jobs.size(); j++)
        {
            if (jobs[j][0] <= now && jobs[j][1]<=min)
            {
                min = jobs[j][1];
                index = j;
            }
        }
        
        if(index == -1)
        {
            now++;
            continue;
        }
        
        now += jobs[index][1];
        sum += now-jobs[index][0];
        jobs.erase(jobs.begin()+index);
    }
    
    answer = sum/size;
    
    return answer;
}
