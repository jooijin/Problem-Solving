// 4948

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n=1;
	int cnt;
	bool flag;
	
	while (n != 0)
	{
		cin>>n;
		cnt = 0;
		
		for (int i = n+1; i <= 2*n; i++)
		{	
			flag = 1;
			for (int j=2; j <= sqrt(i); j++)
			{
				if (i%j == 0)
				{
					flag = 0;
					break;
				}
			}
			
			if (flag == 1)
				cnt++;
		}
		
		if (cnt == 0)
			return 0;
		
		cout<<cnt<<endl;
	}
	
	return 0;
}
