//Problem Link: https://www.codechef.com/LTIME58A/problems/AFK/

#include<bits/stdc++.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b,c;
		cin>>a>>b>>c;
		long long int x =  ceil(abs(2*b - a - c)*1.0/2);
		cout<<x<<"\n";
	}
}
