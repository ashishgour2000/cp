#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n;
vector<int> arr;

bool check(int mid) {
	return arr[mid]<arr[0];
}

int main() {
	int t;cin >> t;while(t--) {
		cin >> n;
		arr.resize(n);
		lli hi = n-1;
		for(int i=0;i<n;i++) {
			cin >> arr[i];
			//hi+=arr[i];
		}

		int ans=0;
		int lo=0;
		while(lo<=hi) {
			int mid = (lo+hi)/2;
			if(check(mid)) {
				hi=mid-1;
				ans=mid;
			}
			else {
				lo=mid+1;
			}
		}
		cout << ans << endl;
	}
}