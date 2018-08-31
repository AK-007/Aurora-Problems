#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int g=b.length();
		string ans="";
		for(int i=0;i<a.length();i++){
			int aa=a[i]-'a'+1;
			int bb=b[i%g]-'a'+1;
			int g=(aa+bb-1)%26;
			ans.push_back(g+'a');
		}
		cout<<ans<<"\n";
	}
	return 0;
}