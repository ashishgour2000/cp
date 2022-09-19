#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

int main() {
	int T;cin >> T;
	for(int t=1;t<=T;t++) {
		int n,q;
		cin >> n >> q;
		vector<vector<int>> v(n+1);
		int a,b;
		for(int i=0;i<n-1;i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		/*cout << "=========================" << endl;
		for(int j=1;j<=n;j++) {
			for(int i=0;i<v[j].size();i++) {
			    cout << v[j][i] << " ";
			}
			cout << endl;
		}
		cout << "=========================" << endl;*/
		int level[n+1];
		for(int i=1;i<=n;i++) {
			level[i]=0;
		}
		level[1]=1;
		int max_level=1;
		queue<int> que;
		que.push(1);
		while(!que.empty()) {
			int num = que.front();
			que.pop();
			for(int i=0;i<v[num].size();i++) {
			    int z = v[num][i];
				if(level[z]==0) {
				    que.push(z);
					level[z]=level[num]+1;
					if(level[z]>max_level) max_level=level[z];
				}
			}
		}
		int countarr[max_level+1];
		for(int i=1;i<=max_level;i++) {
			countarr[i]=0;
		}
		for(int i=1;i<=n;i++) {
			countarr[level[i]]++;
		}
		for(int i=0;i<q;i++) {
			cin >> a;
		}
		/*for(int i=1;i<=max_level;i++) {
			cout << countarr[i] << " ";
		}
		cout << endl;*/
		int num=0;
		int i=1;
		while(q>0) {
		    if(q>=countarr[i]) {
				q-=countarr[i];
				num+=countarr[i];
				i++;
			}
			else{
			    q=0;
			}
		}
		cout << "Case #" << t << ": " << num << endl;
	}
	return 0;
}