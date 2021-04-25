#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if(a.size() < b.size())
        return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> temp;
    
    for(int i=0; i<s.size(); i++) {
        int cnt = 0;
        if(s[i] != '{' && s[i] != '}' && s[i] != ',') {
            while(s[i] != '}'){
                cnt++;
                i++;
            }
            temp.push_back(s.substr(i-cnt, cnt));
        }
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i=0; i<temp.size(); i++) {
        istringstream ss(temp[i]);
        string stringBuffer;
        vector<int> x;
        x.clear();
        
        while (getline(ss, stringBuffer, ',')){
            int num = stoi(stringBuffer);
            x.push_back(num);
        }
        
        for(int j=0; j<x.size(); j++) {
            if(find(answer.begin(), answer.end(), x[j]) == answer.end())
                answer.push_back(x[j]);
        }
    }
    
    return answer;
}
