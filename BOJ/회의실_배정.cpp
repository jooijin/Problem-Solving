// 1931

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.second<b.second) {
		return true;
	}
	else if(a.second == b.second) {
		if(a.first<b.first)
			return true;
	}
	return false;
}

int main() {
	int N, now;
	int ans = 1;
	vector<pair<int, int> > time;
	
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int tmp1,tmp2;
		cin>>tmp1>>tmp2;
		time.push_back(make_pair(tmp1, tmp2));
	}
	
	sort(time.begin(), time.end(), compare);
	
	now = time[0].second;
	
	for(int i=1; i<N; i++) {
		if(time[i].first>=now) {
			ans++;
			now = time[i].second;
		}
	}
	
	cout<<ans;
	
	return 0;
	
}
