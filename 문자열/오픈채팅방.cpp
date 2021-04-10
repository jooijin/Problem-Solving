// 역시 속도면에서는 C++이 가장 빠른것같다

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> map;
    
    for(int i=0; i<record.size(); i++) {
        istringstream ss(record[i]);
        string stringBuffer;
        vector<string> arr;
        arr.clear();
        
        while (getline(ss, stringBuffer, ' ')){
            arr.push_back(stringBuffer);
        }
        
        if(arr[0] == "Enter" || arr[0] == "Change")
            map[arr[1]] = arr[2];
    }
    
    for(int i=0; i<record.size(); i++) {
        istringstream ss(record[i]);
        string stringBuffer;
        vector<string> arr;
        arr.clear();
        
        while (getline(ss, stringBuffer, ' ')){
            arr.push_back(stringBuffer);
        }
            
        if(arr[0] == "Enter")
            answer.push_back(map[arr[1]] + "님이 들어왔습니다.");
        else if(arr[0] == "Leave")
            answer.push_back(map[arr[1]] + "님이 나갔습니다.");
    }
    
    return answer;
}
