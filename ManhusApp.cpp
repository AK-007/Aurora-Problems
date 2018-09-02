#include <bits/stdc++.h>
using namespace std;
int zValue[200005];
void Zarray(string s){
	int l=0,r=0;
	for(int i=1;i<s.length();i++){
		if(i>r){
			l=i;
			r=i;
			while(r<s.length() && s[r-l]==s[r]){
				r++;
			}
			zValue[i]=r-l;
			r--;
		}
		else{
			if(zValue[i-l]<r-i+1){
				zValue[i]=zValue[i-l];
			}
			else{
				l=i;
				while(r<s.length() && s[r-l]==s[r]){
					r++;
				}
				zValue[i]=r-l;
				r--;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s,h,y,k;
		cin>>s;
		h=s;
		reverse(h.begin(),h.end());
		k=s+"#"+h;
		Zarray(k);
		int mx=0;
		for(int i=s.length()+1;i<k.length();i++){
			mx=max(mx,zValue[i]);
		}
		y=s.substr(0,mx);
		reverse(y.begin(),y.end());
		cout<<y<<"\n";
	}
	return 0;
}