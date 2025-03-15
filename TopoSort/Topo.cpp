#include <bits/stdc++.h>

using namespace std;

vector<int> visit(7, 0);
vector<int> topo;
int in[100];
void xuat(){
	for(int i : topo){
		cout << i << " ";
	}
	cout << endl;
}
void dfs(int u, vector<int> d[]){
	//topo.push_back(u);
	visit[u] = 1;
	for(int i : d[u]){
		if(visit[i] == 0){
			dfs(i, d);
		}
	}
	topo.push_back(u);
}

void kahn(int u, vector<int> d[]){
	queue<int > q;
	for(int i = 1; i <= 7 ; i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int top = q.front();
		q.pop();
		topo.push_back(top);
		for(int v : d[top]){
			in[v]--;
			if(in[v] == 0){
				q.push(v);
			}
		}
	}
}

int main(){
	vector<int> d[100];
	d[1] = {2, 6};
	d[2] = {3, 4};
	d[3] = {5};
	d[4] = {5};
	d[7] = {6};
	for(int i = 1; i <= 7; i++){
		for(int j : d[i]){
			in[j]++; // ban bac vao
		}
	}
	
//	for(int i = 1; i <= 7; i++){
//		if(visit[i] == 0){
//			dfs(i, d);
//		}
//	}
	for(int i = 1; i <= 1; i++){
		if(visit[i] == 0){
			kahn(i, d);
		}
	}
	xuat();
}