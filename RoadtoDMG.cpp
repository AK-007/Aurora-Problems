#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
struct S{
    ll p[11];
}tree[4000015];
ll lazy[4000015];
ll a[1000015];
ll fact[11];
ll poww[11];
ll NCR[11][11];
ll ncr(int i,int j){
    ll re=(fact[i]/(fact[j]*fact[i-j]));
    return re;
}
void build(int n,int s,int e){
	lazy[n]=0;
    if(s==e){
        tree[n].p[0]=1;
        for(int i=1;i<=10;i++){
            tree[n].p[i]=(a[s]*tree[n].p[i-1])%mod;
        }
        return;
    }
    int mid=(s+e)/2;
    build(2*n,s,mid);
    build(2*n+1,mid+1,e);
    for(int i=0;i<=10;i++){
        tree[n].p[i]=(tree[2*n].p[i]+tree[2*n+1].p[i])%mod;
    }
}
void update2(int n,int s,int e,int l,int r,int val){
 
    if(lazy[n] != 0)
    {
        poww[0]=1;
        ll hp=lazy[n];
        for(int i=1;i<11;i++){
            poww[i]=poww[i-1]*hp%mod;
        }
        for(int i=10;i>=0;i--){
            ll d=0;
            for(int j=0;j<=i;j++){
                d=(d+NCR[i][j]*poww[j]%mod*tree[n].p[i-j]%mod)%mod;
            }
            tree[n].p[i]=d%mod;
        }
        if(s!=e)
        {
            lazy[2*n]+=hp;             
            lazy[2*n+1]+=hp;            
        }
        lazy[n] = 0;        
    }
    if(s>r || e<l || s>e)return;
    if(s>=l && e<=r)
    {
        poww[0]=1;
        for(int i=1;i<11;i++){
            poww[i]=poww[i-1]*val%mod;
        }
        for(int i=10;i>=0;i--){
            ll d=0;
            for(int j=0;j<=i;j++){
                d=(d+NCR[i][j]*poww[j]%mod*tree[n].p[i-j]%mod)%mod;
            }
            tree[n].p[i]=d%mod;
        }
        if(s!=e)
        {
            lazy[2*n]+=val;             
            lazy[2*n+1]+=val;           
        }
    }
    else{
        int mid = (s+e)/2;
        update2(2*n,s,mid,l,r,val);
        update2(2*n+1,mid+1,e,l,r,val);
        for(int i=0;i<=10;i++){
            tree[n].p[i]=(tree[2*n].p[i]+tree[2*n+1].p[i])%mod;
        }
    }
}
ll query(int n,int s,int e,int l,int r,int h){
     
    if(lazy[n] != 0)
    {
        poww[0]=1;
        ll hp=lazy[n];
        for(int i=1;i<11;i++){
            poww[i]=poww[i-1]*hp%mod;
        }
        for(int i=10;i>=0;i--){
            ll d=0;
            for(int j=0;j<=i;j++){
                d=(d+NCR[i][j]*poww[j]%mod*tree[n].p[i-j]%mod)%mod;
            }
            tree[n].p[i]=d%mod;
        }
        if(s!=e)
        {
            lazy[2*n]+=hp;             
            lazy[2*n+1]+=hp;            
        }
        lazy[n] = 0;        
    }
    if(s>r || s>e || e<l)return 0;
    if(s>=l && e<=r)return tree[n].p[h];
    int mid=(s+e)/2;
    ll p1=query(2*n,s,mid,l,r,h);
    ll p2=query(2*n+1,mid+1,e,l,r,h);
    return (p1+p2)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=10;i++){
        fact[i]=fact[i-1]*i; 
    }
    for(int i=10;i>=0;i--){
        for(int j=0;j<=i;j++){
            NCR[i][j]=ncr(i,j);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        build(1,1,n);
        int q;
        cin>>q;
        while(q--){
            int c;
            cin>>c;
            if(c==1){
                int i,k;
                cin>>i>>k;
                update2(1,1,n,i,i,k);
            }
            if(c==2){
                int l,r,k;
                cin>>l>>r>>k;
                update2(1,1,n,l,r,k);
            }
            if(c==3){
                int l,r,p;
                cin>>l>>r>>p;
                cout<<query(1,1,n,l,r,p)<<"\n";
            }
        }
    }
    return 0;
}