#include <bits/stdc++.h>
using namespace std;
long long ans=0;
struct Trie{
    Trie *child[5];
    bool end;
    long long w;
    Trie(){
        for(int i=0;i<5;i++){
            child[i]=NULL;
        }
        end=false;
        w=0;
    }
};
void insert(Trie *root,string s){
    Trie *cur=root;
    int c;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A')c=0;
        if(s[i]=='E')c=1;
        if(s[i]=='I')c=2;
        if(s[i]=='O')c=3;
        if(s[i]=='U')c=4;
        Trie *node = cur->child[c];
        if(!node){
            node = new Trie();
            cur->child[c]=node;
        }
        cur=node;
        cur->w=cur->w+1;
    }
    cur->end=true;
}
void traverse(Trie *root,long long level){
    Trie *cur=root;
    if(!cur->end){
        for(int i=0;i<5;i++){
            if(cur->child[i]){
                    ans=max(ans,level*cur->child[i]->w);
                    traverse(cur->child[i],level+1);
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
        ans=0;
        int n;
        cin>>n;
        string s;
        Trie *root = new Trie();
        for(int i=0;i<n;i++){
            cin>>s;
            insert(root,s);
        }
        traverse(root,1);
        cout<<ans<<"\n";
    }
    return 0;
}