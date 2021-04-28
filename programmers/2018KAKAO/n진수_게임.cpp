#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char LUT[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string convert(int num, int n){
    string result = "";
    while(num>0){
        int con = num % n;
        result += LUT[con];
        num /= n;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "0";
    
    for(int i=1; ;i++) {
        str += convert(i, n);
        if(str.size()>=(t-1)*m+p)
            break;
    }
    
    for(int i=p-1; answer.size()<t ; i+=m){
        answer += str[i];
    }
    
    return answer;
}
