// Fly me to Alpha Centauri
// 사실 코딩문제라기보다는 수학문제같다

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	double x, y;
	double max, temp;
	
	cin>>T;
	
	for (int i=0; i<T; i++)
	{
		cin>>x>>y;
		max = int(sqrt(y-x));
		temp = max*max;
		
		if (y-x == temp)
			cout<<2*max-1<<endl;
			
		else if (temp<(y-x) && (y-x)<=temp+max)
			cout<<2*max<<endl;
			
		else if (temp+max<(y-x) && (y-x)<=temp+2*max)
			cout<<2*max+1<<endl;

	}
	
	return 0;
}
