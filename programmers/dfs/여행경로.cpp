//미완성

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> rts;
bool visit[99999];

void routes(int start, vector<vector<string>> tickets) {
    visit[start] = true;
    rts.push_back(tickets[start][1]);
    for(int i=0; i<tickets.size(); i++) {
        if(!visit[i] && tickets[start][1] == tickets[i][0]){
            routes(i, tickets);
            break;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
     
    rts.push_back("ICN");
    
    sort(tickets.begin(), tickets.end());
    
    int i=0;
    
    for(; i<tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            routes(i, tickets);
            if(rts.size() == tickets.size()+1 || answer.size() == tickets.size()+1) return rts;
            temp = rts;
            rts.clear();
            rts.push_back("ICN");
            break;
        }
    }
    
    i++;
    
    for(;i<tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            routes(i, tickets);
            rts.pop_back();
            answer.insert(answer.end(), rts.begin(), rts.end());
            answer.insert(answer.end(), temp.begin(), temp.end());
            break;
        }
    }
    
    if(answer.size() != tickets.size()+1) {
        for(int i=0; i<tickets.size(); i++) {
            if(!visit[i]) {
                routes(i, tickets);
                rts.pop_back();
                break;
            }
        }
    }
    
    for(int i=0; i<answer.size(); i++) {
        if(answer[i] == rts[0]) {
            rts.erase(rts.begin());
            auto it = answer.begin();
            answer.insert(it+i, rts.begin(), rts.end());
        }
    }
    
    return answer;
}
