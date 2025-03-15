#include <bits/stdc++.h>

using namespace std;
vector<int> kq;
vector<bool> visit(20, 0);
int parent[100];
void hien(){
	for(int i : kq){
		cout <<  i << " ";
	}
}
void dfs(int u, vector<int> d[]){
	visit[u] = 1;
	for(int v : d[u]){
		if(visit[v] == 0){
			parent[v] = u;
			dfs(v, d);
		}
	}
}
void bfs(int u, vector<int> d[]){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int v : d[a]){
			if(visit[v] == 0){
				q.push(v);
				visit[v] = 1;
				parent[v] = a;		
		}
		}
	}
}
void findPath(int s, int e, vector<int> d[]){
	dfs(1, d);
	if(visit[e] == 0){
		cout << "Ko co dg di" << endl;
	}else{
		while( e != s){
			kq.push_back(e);
			e = parent[e];
		}
		kq.push_back(s);
		reverse(kq.begin(), kq.end());
		hien();
	}
}
int main(){
//	int n , m, s, t;
//	cin >> n >> m >> s >> t;
	vector<int> d[100];
	d[1] = {2, 10};
	d[2] = {3, 4};
	d[3] = {6, 7};
	d[5] = {8, 10};
	d[6] = { 7};
	d[7] = {5};
	d[8] = {9};
	findPath(1, 9, d);
}