// 10819

/*
문제
N개의 정수로 이루어진 배열 A가 주어진다. 
이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 
배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
*/

#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int N;
vector<int> v;
int arr[8];
bool visit[8];
int answer = 0;

void line(int cnt){
    if(cnt == N){
        int sum = 0;
        for(int i=0; i<N-1; i++){
            sum += abs(arr[i+1] - arr[i]);
        }
        if(sum > answer)
            answer = sum;
    }
    for(int i=0; i<N; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = v[i];
            line(cnt+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    for(int i=0; i<N; i++){
        arr[0] = v[i];
        visit[i] = true;
        line(1);
        visit[i] = false;
    }
    cout<<answer<<endl;
    
    return 0;
}
