// 11047번

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	int ans=0;
	vector<int> coin;
	cin>>N>>K;
	
	for(int i=0; i<N; i++) {
		int tmp;
		cin>>tmp;
		coin.push_back(tmp);
	}
	
	for(int i=N-1; i>=0; i--) {
		if(K/coin[i] > 0) {
			ans += K/coin[i];
			K %= coin[i];
			if(K==0)
				break;
		}
	}
	
	cout<<ans;
	
	return 0;
	
}
