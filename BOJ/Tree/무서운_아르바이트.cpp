// 12846

// 값의 범위를 잘 확인하자.. 8ㅅ8
// 세그먼트 트리로 하는것까진 알았는데... 인덱스를 안써서 했더니 시간초과가 났다
// 다른 사람들 풀이를 조금 참고해서 고쳤다..

/*
문제
성화는 악독하기로 유명한 편의점 사장이다. 그의 편의점에는 특이한 임금 체계를 가지고 있다.

각 날마다 일의 차이때문에 일마다 급여가 정해져 있다.
돈은 당일에 주지 않고 퇴직을 할 때 한번에 준다.
성화는 욕심쟁이라서 해당 일을 한 동안 중 가장 일급이 작을 때를 기준으로 급여를 지급한다.
일급이 다른 것을 들키지 않기 위하여 한번이라도 퇴직한 자를 다시 취직 시키지 않는다. 
(만약 취직을 한다면, 일을 시작 한 날부터 끝날 때까지 하루도 빠지면 안 된다.)
준수는 n+1일 후에 001에 월세를 내야 해서 성화가 사장으로 있는 편의점에 취직하려 한다. 
다행히 주변 퇴직자들의 얘기로 급여에 관련해 파악했다. 
또한 퇴직자들의 급여 통계를 통해 당장 n일 후까지 일급 정보를 알아냈다. 
최대로 많이 일했을 때가 최대 이익이 아닐 수 있다.

어제까지 과제를 제출하고 지금도 001에서 자고 있는 준수를 위해 코딩 잘하는 여러분이 일을 해서 벌 수 있는 최대 이익을 준수에게 알려주도록 하자.

입력
일을 할 수 있는 날의 수 (0 < n ≤ 100000) 가 주어진다.

그 다음 줄 에는 1일부터 n일 까지 일급 Ti 가 순서대로 주어진다. (0 < Ti ≤ 1,000,000)

출력
준수가 일을 해서 벌 수 있는 최대 이익을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 100001
#define out -1

using namespace std;

int t[NUM];
long long tree[4*NUM];

void init(int start, int end, int node){
    if(start == end){
    	tree[node] = start;
    	return;
	}
    int mid = (start + end)>>1;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    if(t[tree[node*2]] <= t[tree[node*2+1]]){
    	tree[node] = tree[node*2];
	}
	else{
		tree[node] = tree[node*2+1];	
	}
}

long long mini(int start, int end, int node, int left, int right){
    if(left > end || right < start) return out;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)>>1;
    long long l = mini(mid + 1, end, node * 2 + 1, left, right);
    long long r = mini(start, mid, node * 2, left, right);
    if(l == -1) return r;
    if(r == -1) return l;
    return t[r] > t[l] ? l : r;
}

long long solve(int left, int right, int n){
	long long idx = mini(0, n-1, 1, left, right);
	long long res = (long long)(right - left + 1) * (long long)t[idx];
	if(left <= idx - 1){
		long long temp = solve(left, idx-1, n);
		if(temp > res){
			res = temp;
		}
	}
	if(idx + 1 <= right){
		long long temp = solve(idx+1, right, n);
		if(temp > res){
			res = temp;
		}
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t[i];
    }
    init(0, n-1, 1);
    cout<<solve(0, n-1, n)<<'\n';
    
    return 0;
}
