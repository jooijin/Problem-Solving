#include <string>
#include <vector>

using namespace std;

int arr[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0; i<lost.size(); i++) {
        arr[lost[i]]--;
    }
    
    for(int i=0; i<reserve.size(); i++) {
        arr[reserve[i]]++;
    }
    
    for(int i=1; i<n+1; i++) {
        if (arr[i]<0) {
            if(arr[i-1] > 0) {
                arr[i] = arr[i-1] = 0;
            }
            else if(arr[i+1] > 0) {
                arr[i] = arr[i+1] = 0;
            }
        }
    }
    
    for(int i=1; i<n+1; i++) {
        if(arr[i] >= 0)
            answer++;
    }
    
    return answer;
}
