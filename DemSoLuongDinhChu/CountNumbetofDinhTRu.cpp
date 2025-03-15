#include <bits/stdc++.h>

using namespace std;

int n = 7;
vector<int> visit( n + 1);
void dfs(int u, vector<int> d[]){
	visit[u] = 1;
	for(int i : d[u]){
		if(!visit[i]) dfs(i, d);
	}
}
void dinhTru(vector<int> d[]){
	int an = 0;
	for(int  i = 1 ; i <= 7 ; i++){
		visit.assign(n+1 , 0);
		visit[i] = 1;
		int c = 0;
		for(int j = 1; j <= 7 ; j++){
			if(!visit[j]){
				c++;
				dfs(j, d);
			}
		}
		if(c > 1) cout << i << " ";
	}
	//cout << an;
}
int main(){
	vector<int> d[8];
	d[1] = {6};
	d[2] = {6, 5};
	d[3] = {5};
	d[4] = {5};
	d[5] = {2,3,4};
	d[6] = {7,2,1};
	d[7] = {6};
	dinhTru(d);
	return  0;
}