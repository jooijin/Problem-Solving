#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int temp;
    
    for (int i=0; i<prices.size()-1; i++)
    {
        temp=0;
        for (int j=i+1; j<prices.size(); j++)
        {
            //if (prices[i]<=prices[j]) -> 쓸모없는 코드 쓰지말자
            
            temp++;
            
            if (prices[i]>prices[j] || j == prices.size()-1)
            {
                answer.push_back(temp);
                break;
            }
            
            /*if(j == prices.size()-1)
            {
                answer.push_back(temp);
                break;
            }*/
        }
    }
    
    answer.push_back(0);
    
    return answer;
}
