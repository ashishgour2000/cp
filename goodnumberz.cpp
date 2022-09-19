#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
    int n,k,q;
    cin >> n >> k >> q;
    int arr[1000000];
    memset(arr, 0, sizeof(arr));
    int a,b;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        arr[a-1]++;
        if(b!=1000000)  arr[b]--;
    }
    int brr[1000000];
    if(arr[0]>=k)brr[0]=1;
    else brr[0]=0;
    for(int i=1;i<1000000;i++) {
        arr[i]+=arr[i-1];
        if(arr[i]>=k)brr[i]=1;
        else brr[i]=0;
        brr[i]+=brr[i-1];
    }
    for(int i=0;i<q;i++) {
        cin >> a >> b;
        if(a==1) {
            cout << brr[b-1] << endl;
        }
        else {
            cout << brr[b-1]-brr[a-2] << endl;
        }
    }
    return 0;
}