// 인덱스를 잘 활용하자,,


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    answer = people.size();
    
    sort(people.begin(), people.end(), greater<>());
    
    for(int i=0, j=people.size()-1; i<j; i++) {
        if(people[i]+people[j]<=limit){
            j--;
            answer--;
        }
    }
    
    return answer;
}
