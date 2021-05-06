/*
단체사진 찍기

가을을 맞아 카카오프렌즈는 단체로 소풍을 떠났다. 
즐거운 시간을 보내고 마지막에 단체사진을 찍기 위해 카메라 앞에 일렬로 나란히 섰다. 
그런데 각자가 원하는 배치가 모두 달라 어떤 순서로 설지 정하는데 시간이 오래 걸렸다. 
네오는 프로도와 나란히 서기를 원했고, 튜브가 뿜은 불을 맞은 적이 있던 라이언은 튜브에게서 적어도 세 칸 이상 떨어져서 서기를 원했다. 
사진을 찍고 나서 돌아오는 길에, 무지는 모두가 원하는 조건을 만족하면서도 다르게 서는 방법이 있지 않았을까 생각해보게 되었다. 
각 프렌즈가 원하는 조건을 입력으로 받았을 때 모든 조건을 만족할 수 있도록 서는 경우의 수를 계산하는 프로그램을 작성해보자.

입력 형식
입력은 조건의 개수를 나타내는 정수 n과 n개의 원소로 구성된 문자열 배열 data로 주어진다. 
data의 원소는 각 프렌즈가 원하는 조건이 N~F=0과 같은 형태의 문자열로 구성되어 있다. 제한조건은 아래와 같다.

1 <= n <= 100
data의 원소는 다섯 글자로 구성된 문자열이다. 각 원소의 조건은 다음과 같다.
첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다. {A, C, F, J, M, N, R, T} 
각각 어피치, 콘, 프로도, 제이지, 무지, 네오, 라이언, 튜브를 의미한다. 
첫 번째 글자는 조건을 제시한 프렌즈, 세 번째 글자는 상대방이다. 
첫 번째 글자와 세 번째 글자는 항상 다르다.
두 번째 글자는 항상 ~이다.
네 번째 글자는 다음 3개 중 하나이다. {=, <, >} 각각 같음, 미만, 초과를 의미한다.
다섯 번째 글자는 0 이상 6 이하의 정수의 문자형이며, 조건에 제시되는 간격을 의미한다. 
이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다.

출력 형식
모든 조건을 만족하는 경우의 수를 리턴한다.
*/

// 테스트 케이스가 뭐일지 너무 궁금하다.
// next_permutation함수를 잘 활용해야겠다.

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string frnds = "ACFJMNRT";
    
    do{
        bool flag = true;
        for(int j=0; j<n; j++){
            auto start = find(frnds.begin(), frnds.end(), data[j][0]);
            auto end = find(frnds.begin(), frnds.end(), data[j][2]);
            int dist = (data[j][4] - '0') +1;
            char op = data[j][3];
            if(op == '='){
                if(abs(start - end) == dist) continue;
                flag = false; break;
            }
            else if(op == '>'){
                if(abs(start - end) > dist) continue;
                flag = false; break;
            }
            else{
                if(abs(start - end) < dist) continue;
                flag = false; break;
            }
        }
        
        if(flag)answer++;
        
    }while(next_permutation(frnds.begin(), frnds.end()));
    
    
    
    return answer;
}
