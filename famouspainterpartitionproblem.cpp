#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n,k;
vector<int> arr;

bool check(lli mid) {
	int count=0;
	lli sum=0;
	for(int i=0;i<n;i++) {
		if(arr[i]>mid) return false;
		if(sum+arr[i]<=mid) {
			sum+=arr[i];
		}
		else {
			count++;
			sum=arr[i];
		}
	}
	count++;
	return count<=k;
}

int main() {
	int t;cin >> t;while(t--) {
		cin >> n >> k;
		arr.resize(n);
		lli hi = 0;
		for(int i=0;i<n;i++) {
			cin >> arr[i];
			hi+=arr[i];
		}

		lli ans=-1;
		lli lo=0;
		while(lo<=hi) {
			lli mid = (lo+hi)/2;
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