#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
    int t;cin >> t;while(t--) {
        int n,m,q;
        cin >> n >> m >> q;
        vector<pair<int,lli>> v;
        int a,b;
        for(int i=0;i<n;i++) {
            cin >> a;
            v.push_back(make_pair(a,0LL));
        }
        for(int i=0;i<m;i++) {
            cin >> a >> b;
            if(b!=n) v[b].second--;
            v[a-1].second++;
        }
        for(int i=1;i<n;i++) {
            v[i].second+=v[i-1].second;
        }
        sort(v.begin(), v.end());
        lli A[n];
        A[0]=v[0].second;
        for(int i=1;i<n;i++) {
            A[i]=A[i-1]+v[i].second;
        }
        lli k;
        for(int i=0;i<q;i++) {
            cin >> k;
            if(k>A[n-1]) cout << "-1 ";
            else cout << v[lower_bound(A,A+n,k)-A].first << " ";
        }
        cout << endl;

    }
    return 0;
}