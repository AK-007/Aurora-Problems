#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<long long,int>>v[10005];
double ans=0;
int n;
int dfs(int u,int p){
	int sz=1;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i].second==p)continue;
		int x=dfs(v[u][i].second,u);
		ans+=x*(n-x)*v[u][i].first;
		sz+=x;
	}
	return sz;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=0;i<n-1;i++){
			int x,y;
			long long z;
			cin>>x>>y>>z;
			v[x].push_back({z,y});
			v[y].push_back({z,x});
		}
		for(int i=1;i<=n;i++){
			if(v[i].size()==1){
				int y=dfs(i,i);
				break;
			}
		}
		double ff=(double)(n*(n-1))/(double)2.0;
		ans=(double)ans/ff;
		printf("%.6f\n",ans);
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}