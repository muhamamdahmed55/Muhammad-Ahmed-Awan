#include<iostream>
using namespace std;
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	int n,s,e,m,loc=-1;
	s=0;
	e=8;
	cout<<"Enter any search value: "<<endl;
	cin>>n;
	while(s<=e)
	{
	m=s+e/2

	}
	if(n==a[m])
	{
	loc=m;
	}
	else if(n>m){
	s=m+1;
	}
	else
	{
    e=m-1;
	}
	return 0;
	}
