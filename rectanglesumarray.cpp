#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<lli>> arr(n+1,vector<lli>(m+1,0));
    lli mod=1e9+7;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
            /*if(i!=0) arr[i][j]+=arr[i-1][j];
            if(j!=0) arr[i][j]+=arr[i][j-1];
            if(i!=0 && j!=0) arr[i][j]-=arr[i-1][j-1];*/
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            arr[i][j] %= mod;
            arr[i][j] = (arr[i][j]+mod)%mod;
        }
    }
    int a,b,c,d;
    lli ans;
    for(int i=0;i<q;i++) {
        cin >> a >> b >> c >> d;
        ans = arr[c][d];
        ans -= arr[a-1][d];
        ans -= arr[c][b-1];
        ans += arr[a-1][b-1];
        ans %= mod;
        ans = (ans+mod)%mod;
        cout << ans << endl;
    }
    return 0;
}