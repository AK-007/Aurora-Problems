#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
bool prime[1000005];
int mp[1000005][2];
int ww[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prime[0]=prime[1]=true;
    for(int i=2;i<=1000000;i++){
        if(!prime[i]){
         v[i].push_back(i);
        for(int j=2*i;j<=1000000;j+=i){
                v[j].push_back(i);
                prime[j]=true;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a,mx=0,kn=0;
        memset(mp,0,sizeof mp);
        memset(ww,0,sizeof ww);
        int aa,bb;
        for(int i=1;i<=n;i++){
            if(i%2==1){aa=0;bb=1;}
                else {aa=1;bb=0;}
            for(int j=1;j<=m;j++){
                cin>>a;
                if(i==1){
                    for(int h=0;h<v[a].size();h++){
                        mp[v[a][h]][0]=max(mp[v[a][h]][0],a);
                        if(i==n)mx=max(mx,mp[v[a][h]][0]);
                        ww[v[a][h]]=1;
                    }
                }
                else{
                    kn=0;
                    for(int h=0;h<v[a].size();h++){
                        if(ww[v[a][h]]>=i-1){
                            kn=max(kn,mp[v[a][h]][bb]+a);
                            ww[v[a][h]]=i;
                            if(i==n)mx=max(mx,kn);
                        }
                    }
                    for(int h=0;h<v[a].size();h++){
                        mp[v[a][h]][aa]=max(kn,mp[v[a][h]][aa]);
                        if(kn!=0)ww[v[a][h]]=i;
                    }
                }
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}