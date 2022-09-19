#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n;
lli k;
vector<int> arr;

int check(int mid) {
	lli count=0;
	for(int i=1;i<n;i++) {
		int d = arr[i]-arr[i-1];
		count += (d+mid-1)/mid;
		count--;
	}
	return count<=k;
}

int main() {
	int t;cin >> t;while(t--) {
		cin >> n >> k;
		arr.resize(n);
		for(int i=0;i<n;i++) {
			cin >> arr[i];
		}
		int lo=1;
		int hi=1e9;
		int ans=-1;
		while(lo<=hi) {
			int mid = (lo+hi)/2;
			if(check(mid)) {
				ans=mid;
				hi=mid-1;
			}
			else {
				lo=mid+1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}