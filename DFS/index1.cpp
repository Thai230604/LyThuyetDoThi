#include <bits/stdc++.h>

using namespace std;
//10 11
//1 2
//1 3
//1 5
//1 10
//2 4
//3 6
//3 7
//3 9
//6 7
//5 8
//8 9
int n ,m ;
vector<int> a[100];
vector<bool> visited(100, 0);

void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x , y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
void dfs(int u){
	cout << u << " ";
	visited[u] = 1;
	for(int v : a[u]){
		if(visited[v] == 0){
			dfs(v);
		}
	}
}
void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v ;
		for(int x : a[v]){
			if(visited[x] == 0){
				q.push(x);
				visited[x] = 1;
			}
		}
	}
}
int main(){
	inp();
	bfs(1);
}
