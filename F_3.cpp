#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
	lli T;cin >> T;
	for(lli t=1;t<=T;t++) {
		lli d,n,x;
		cin >> d >> n >> x;
		lli profit=0;
		vector<pair<lli,pair<lli,lli>>> v;
		lli a,b,c;
		for(lli i=0;i<n;i++) {
			cin>>a>>b>>c;
			v.push_back({-c,{b,a}});
		}
		sort(v.begin(), v.end());
		vector<lli>days(d+1,x);
		for(lli i=0;i<n;i++) {
			lli lastday = d-v[i].second.first;
			for(lli j=lastday;j>0;j--) {
				if(v[i].second.second==0) break;
				if(days[j]>0) {
					lli num = min(v[i].second.second, days[j]);
					v[i].second.second-=num;
					days[j]-=num;
					profit-=(1LL*num*v[i].first);
				}
			}
		}
		cout << "Case #" << t << ": " << profit << endl;
	}
	return 0;
}