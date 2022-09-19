#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int n,q;
vector<int> arr;

int binary_search(int hi,int num) {
	int lo=0;
	while(lo<=hi) {
		int mid=(lo+hi)/2;
		if(arr[mid]==num) return mid;
		else if(arr[mid]>num) {
			hi=mid-1;
		}
		else {
			lo=mid+1;
		}
	}
	return -1;
}

int binary_search_1(int lo,int num) {
	int hi=n-1;
	while(lo<=hi) {
		int mid=(lo+hi)/2;
		if(arr[mid]==num) return mid;
		else if(arr[mid]>num) {
			lo=mid+1;
		}
		else {
			hi=mid-1;
		}
	}
	return -1;
}

int main() {
	int t;cin >> t;while(t--) {
		cin >> n >> q;
		arr.resize(n);
		cin>>arr[0];
		int highest=0;
		for(int i=1;i<n;i++) {
			cin >> arr[i];
			if(arr[i]>arr[i-1]) highest=i;
		}
		int num;
		for(int i=1;i<=q;i++) {
			cin >> num;
			int ans = binary_search(highest, num);
			if(ans!=-1) cout << ans+1 << " ";
			int ans1 = binary_search_1(highest, num);
			if(ans1!=-1 && ans1!=ans) cout << ans1+1;
			cout << endl;
		}
	}
}