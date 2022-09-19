#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n,m;
lli k;
vector<int> arr,brr;

bool check(int mid) {
	lli num=0;
	for(int i=0;i<n;i++) {
		num+=upper_bound(brr.begin(), brr.end(), mid-arr[i])-brr.begin();
	}
	return num>=k;
}

int main() {
	int t;cin >> t;while(t--) {
		cin >> n >> m >> k;
		arr.resize(n);
		brr.resize(m);
		for(int i=0;i<n;i++) {
			cin >> arr[i];
		}
		for(int i=0;i<m;i++) {
			cin >> brr[i];
		}
		if(n>m) {
			swap(n,m);
			swap(arr,brr);
		}
		sort(arr.begin(), arr.end());
		sort(brr.begin(), brr.end());
		int lo=0;
		int hi=arr.back()+brr.back();
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