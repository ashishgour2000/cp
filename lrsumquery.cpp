#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
    int n,q;
    cin >> n >> q;
    int mod=1e9+7;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int presum[n];
    presum[0]=arr[0];
    for(int i=1;i<n;i++) {
        presum[i]=((1LL*arr[i]+1LL*presum[i-1])%mod+mod)%mod;
    }
    int a,b;
    for(int i=0;i<q;i++) {
        cin >> a >> b;
        if(a==1) {
            cout << presum[b-1] << endl;
        }
        else {
            cout << ((presum[b-1]-presum[a-2])%mod+mod)%mod << endl;
        }
    }
    return 0;
}