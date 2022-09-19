#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<lli>> arr(n+1,vector<lli>(m+1,0));
    int a,b,c,d,val;
    for(int i=0;i<q;i++) {
        cin >> a >> b >> c >> d >> val;
        arr[a][b]+=val;
        if(d!=m) arr[a][d+1]-=val;
        if(c!=n) arr[c+1][b]-=val;
        if(c!=n && d!=m) arr[c+1][d+1]+=val;
    }
    lli maxval = -(1e18);
    int count=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            arr[i][j] = arr[i][j] - arr[i-1][j-1] + arr[i-1][j] + arr[i][j-1];
            if(arr[i][j]>maxval) {
                maxval = arr[i][j];
                count=1;
            }
            else if(arr[i][j]==maxval) {
                count++;
            }
        }
    }
    cout << maxval << " " << count;
    return 0;
}