#include <bits/stdc++.h>

using namespace std;

struct Pack{
	int m;
	int v;
	Pack(int a, int b){
		m = a;
		v = b;
	}
};
vector<Pack> tinh(vector<Pack> &p, int m){
	vector<vector<int>> d(p.size() + 1, vector<int>(m + 1, 0));
	vector<Pack> a = p;
	a.insert(a.begin(), Pack(0, 0));
	for(int i = 1; i <= p.size(); i++){
		for(int j = 1; j <= m; j++){
			d[i][j] = d[i- 1][j];
			if(j >= a[i].m && d[i][j] < d[i-1][j - a[i].m] + a[i].v){
				d[i][j] = d[i-1][j - a[i].m] + a[i].v;
			}
		}
	}
	vector<Pack> k;
	int best = m;
	for(int i = p.size() ; i >= 1 ; i--){
		if(best >= a[i].m && d[i][best] != d[i-1][best]){
			best -= a[i].m;
			k.push_back(a[i]);
		}
	}
	reverse(k.begin(), k.end());
	return k;
}
int main(){
	Pack p1 = Pack(12, 34);
	Pack p2 = Pack(15, 23);
	Pack p3 = Pack(17, 34);
	Pack p4 = Pack(10, 19);
	int m = 39;
	vector<Pack> p = {p1, p2, p3, p4};
	vector<Pack> k = tinh(p, m);
	for(Pack &it : k){
		cout << "Khoi luong: " << it.m << " .Gia tri: " << it.v << endl;
	}
}