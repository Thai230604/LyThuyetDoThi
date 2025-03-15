#include <bits/stdc++.h>

using namespace std;

vector<int> color(10, 0);
vector<int> par(10, 0);
vector<int> vao(10, 0); // banbacvao
bool dfs(int u, vector<int> d[]){  // ap dung cho do thi lien thong
	color[u] = 1;
	for(int i : d[u]){
		if(color[i] == 0){
			par[i] = u;
			if(dfs(i, d)) return true;
		}else if(color[i] == 1){
			return true;
		}
	}
	color[u] = 2;
	return false;
}
bool bfs(vector<int> d[]){ // ko lien thong van dc
	queue<int> q;
	for(int i = 1; i <= 7; i++){
		if(vao[i] == 0){
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cnt++;
		for(int i : d[top]){
			vao[i]--;
			if(vao[i] == 0) q.push(i);
		}
	}
	return !(cnt == 7);
}
void ghiBanBacVao(vector<int> d[]){
	for(int i = 1; i <= 7 ; i++){
		for(int j : d[i]) vao[j]++;
	}
}
int main(){
	vector<int> d[10];
	d[1] = {2, 5};
	d[2] = {3};
	d[3] = {6, 7};
	d[4] = {2};
	d[6] = {7};
//	d[7] = {3};
	ghiBanBacVao(d);
//	for(int i = 1; i <= 7; i ++){
//		if(color[i] == 0){
//			if(dfs(i, d)){
//				cout << "OK";
//				return 0;
//			}
//		}
//	}
//	cout << "No";
   if(bfs(d)) cout << "ok";
   else cout << "No";
}