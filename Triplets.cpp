#include <bits/stdc++.h>
using namespace std;
int mp[100005];
int bit1[100005],bit2[100005];
void update(int i,int val){
	for(;i<100005;i+=(i&-i)){
		bit1[i]+=val;
	}
}
void update2(int i,int val){
	for(;i>0;i-=(i&-i)){
		bit2[i]+=val;
	}
}
long long query(int i){
	long long ans=0;
	for(;i>0;i-=(i&-i)){
		ans+=bit1[i];
	}
	return ans;
}
long long query2(int i){
	long long ans=0;
	for(;i<100005;i+=(i&-i)){
		ans+=bit2[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n];
		memset(bit1,0,sizeof bit1);
		memset(bit2,0,sizeof bit2);
		memset(mp,0,sizeof mp);
		for(int i=0;i<n;i++){
			cin>>a[i];
			mp[a[i]]=i+1;
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			b[i]=mp[b[i]];
		}
		for(int i=n-1;i>=0;i--){
			update2(b[i],1);
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			update2(b[i],-1);
			long long y=query2(b[i]);
			long long x=query(b[i]);
			ans+=x*y;
			update(b[i],1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}