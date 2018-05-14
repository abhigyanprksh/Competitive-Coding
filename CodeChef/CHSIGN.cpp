//Problem Link: https://www.codechef.com/MAY18B/problems/CHSIGN

#include<bits/stdc++.h>
using namespace std;
 
 
void resolve(long long int a[], int ib, int ie, unordered_map<int,int> &m)
{   
	vector<int> v1,v2;
	vector <int> :: iterator it;
	long long int max1,max2,temp; max1 = a[ib]; v1.push_back(ib); if(a[ib+2] > a[ib]) { max2 = a[ib+2]; v2.push_back(ib+2);} else {max2 = max1; v2.push_back(ib);}
	
	int j=1; m[ib]=0; m[ib+2]=0;
	 
	for(int i=ib+4; i<=ie; i=i+2)
	{   
		  j++; m[i]=0;
		 if(a[i]+max1 > max2) { if(j%2) v2.push_back(i); else v1.push_back(i);  temp = max2; max2 = max1+a[i]; max1=temp;}
		 
		 else{ max1=max2; if(j%2) v2=v1; else v1=v2;}
		 
	}
	
	
    	
       if(j%2)
       {for(it=v2.begin(); it!=v2.end() ; it++)
    	{
    		m[*it]=1; 
        }
 
     }
    	
    
     else{
       for(it=v1.begin(); it!=v1.end() ; it++)
    	{
    		 m[*it]=1;
        }
	}
	
	
	
}
 
		 	
		 	
		 
main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int t; cin>>t;
	while(t--)
	{   unordered_map <int, int> m;
		int n; cin>>n;
		long long int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    
	    int flag=0,ib,ie;
	    
	    for(int i=0;i<n;i++)
	    {
	    	if(i==0 || i==n) 
	    	{
			
			if(i==0 && a[i+1] > a[i]) m[i]=1;
			
			if(i==n && a[i-1] > a[i]) m[i]=1;}
			
			else{ if(a[i] < a[i-1] && a[i] < a[i+1]) m[i]=1;}
			
			if(m[i-2]==1 && m[i]==1 &&  (a[i-2] + a[i] >= a[i-1])) {if(flag==0) {flag=1; ib=i-2;ie=i;} else ie=i;  }
			
			else {if(flag && i==ie+2) { flag=0; resolve(a,ib,ie,m);}}
	   
	   }
	   if(flag) { resolve(a,ib,ie,m);} 
	  
	    for(int i=0; i<n; i++)  if(m[i]==1) cout<<a[i]*-1<<" "; else cout<<a[i]<<" ";
	  
	    cout<<"\n";
	
	}
	
}
			
