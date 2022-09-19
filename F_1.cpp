#include<bits/stdc++.h>
using namespace std;

using lli = long long int;


int main() {
	int T;cin >> T;
	for(int t=1;t<=T;t++) {
		int n; cin >> n;
		vector<pair<string,int>> ada;
		vector<pair<int,int>> charles;
		string str;
		int a,b;
		for(int i=0;i<n;i++) {
			cin >> str >> a >> b;
			ada.push_back({str,b});
			charles.push_back({a,b});
		}
		sort(ada.begin(), ada.end());
		sort(charles.begin(), charles.end());
		int count=0;
		for(int i=0;i<n;i++) {
			if(ada[i].second == charles[i].second) count++;
		}
		cout << "Case #" << t << ": " << count << endl;
	}
	return 0;
}