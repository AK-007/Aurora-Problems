#include <bits/stdc++.h>
using namespace std;
int check(int j){
	string e;
	while(j>0){
		int u=j%2;
		e+=char(u+'0');
		j/=2;
	}
	reverse(e.begin(),e.end());
	string hh(10-e.length(),'0');
	e=hh+e;
	int r=0;
	string y(10,'2');
	string h;
	h=e;
	while(y!=e){
		for(int i=0;i<h.length();i++){
			if(i==0){
				y[i]=h[1];
			}
			else if(i==h.length()-1){
				y[i]=h[i-1];
			}
			else{
				if(h[i-1]==h[i+1])y[i]='0';
				else y[i]='1';
			}
		}
		r++;
		h=y;
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	long long y[1024];
	for(int i=0;i<1024;i++){
		y[i]=check(i);
	}
	while(t--){
		string s;
		cin>>s;
		long long p;
		cin>>p;
		int d=0,k=1;
		for(int i=9;i>=0;i--){
			if(s[i]=='1')d+=k;
			k*=2;
		}
		p=p%y[d];
		string y=s;
		for(int i=0;i<p;i++){
			for(int i=0;i<s.length();i++){
				if(i==0){
					y[i]=s[1];
				}
				else if(i==s.length()-1){
					y[i]=s[i-1];
				}
				else{
					if(s[i-1]==s[i+1])y[i]='0';
					else y[i]='1';
				}
			}
			s=y;
		}
		cout<<y<<"\n";
	}
	return 0;
}