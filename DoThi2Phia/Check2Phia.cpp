#include <bits/stdc++.h>

using namespace std;
int n = 6;
vector<int> color(n + 1, -1);

bool bfs(int u, vector<int> d[]){
	queue<int> q;
	q.push(u);
	color[u] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i : d[top]){
			if(color[i] == -1){
				color[i] = 1 - color[top];
			}else if(color[i] == color[top]){
				return false;
			}
		}
	}
	return true;
}

bool dfs(int u, vector<int> d[], int c){
	color[u] = c;
	for(int i : d[u]){
		color[i] = 1 - c;
		if(color[i] == -1){
			if(!dfs(i, d, color[u])) return false;
		}else if(color[i] == color[u]){
			return false;
		}
	}
	return true;
} 
int main(){
	vector<int> d[n + 1];
	d[1] = {2, 6};
	d[2] = {1, 3};
	d[3] = {4, 2};
	d[4] = {3, 5};
	d[5] = {4};
	d[6] = {1};
	cout << dfs(1, d, 0);
}