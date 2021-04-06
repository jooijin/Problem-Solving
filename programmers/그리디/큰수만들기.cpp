// 굉장히 비효율적으로 푼거같다
// 그리디 좀 더 공부하고 수정할 계획

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int erase = 0;
    
    for(int i=0; i<number.size(); i++) {
        if(number[i] < number[i+1]) {
            number.erase(i, 1);
            erase++;
            i = -1;
            if(erase == k)
                break;
        }
    }
    if (erase < k) {
        for(int i=0; i<k-erase; i++) {
            number.pop_back();
        }    
    }
    
    answer = number;
    
    return answer;
}
