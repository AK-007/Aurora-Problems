#include <bits/stdc++.h>
using namespace std;
bool prime[100005];
vector<long long> p;
#define mod 1000000007
void sieve(){
	memset(prime,true,sizeof prime);
	prime[0]=prime[1]=false;
	for(int i=4;i<100005;i+=2)prime[i]=false;
	for(int i=3;i*i<100005;i+=2){
		if(prime[i]){
			for(int j=i*i;j<100005;j+=2*i){
				prime[j]=false;
			}
		}
	}
	for(int i=2;i<100005;i++){
		if(prime[i])p.push_back(i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int t;
	cin>>t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		if(l==1 && r==1){
			cout<<1<<"\n";
			continue;
		}
		if(l==1)l++;
		long long arr[100005];
		long long ss[100005];
		for(int i=l;i<=r;i++){
			arr[i-l]=1;
			ss[i-l]=i;
		}
		for(int i=0;i<p.size();i++){
			if(p[i]>r)break;
			int base=(l/p[i])*p[i];
			if(base<l)base+=p[i];
			for(int j=base;j<=r;j+=p[i]){
				int gg=ss[j-l];
				long long c=0;
				while(gg%p[i]==0){
					gg/=p[i];
					c++;
				}
				c++;
				arr[j-l]=(arr[j-l]*c)%mod;
				ss[j-l]=gg;
			}
			if(base==p[i]){
				arr[base-l]=1;
				ss[base-l]=base;
			}
		}
		long long ans=1;
		for(int i=0;i<=r-l;i++){
			if(ss[i]!=1)arr[i]*=2;
			ans=(ans%mod*arr[i]%mod)%mod;
		}
		cout<<ans%mod<<"\n";
	}
	return 0;
}