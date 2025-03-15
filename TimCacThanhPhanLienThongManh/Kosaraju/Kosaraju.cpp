#include <bits/stdc++.h>

using namespace std;
vector<bool> visit(10, 0);
stack<int> st;
void dfs(int u, vector<int> a[]){
	visit[u] = 1;
	for(int i : a[u]){
		if(visit[i] == 0){
			dfs(i, a);
		}
	}
	st.push(u);
}

int main(){
	vector<int> a[9];
	a[1] = {2};
	a[2] = {3};
	a[3] = {4, 5};
	a[4] = {1};
	a[5] = {6};
	a[6] = {7};
	a[7] = {8};
	a[8] = {6};
	dfs(1, a);
	visit.assign(10, 0);
	vector<int> b[9];
	for(int i = 1; i <= 8 ; i++){
		for(int j : a[i]){
			b[j].push_back(i);
		}
	}
	int c = 0;
	while(!st.empty()){
		int i = st.top();
		st.pop();
		if(visit[i] == 0){
			dfs(i, b);
			c++;
		}
	}
	cout << c;
	if(c == 1) cout << "Ok"; else cout << "No";
	//Thanh phần liên thông mạnh
	
}