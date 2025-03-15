#include <bits/stdc++.h>

using namespace std;
vector<bool> visit(10, 0);
vector<int> parent(10, -1);
int start ;
int en;
//bool dfs(int u, vector<int> d[]){
//	visit[u] = 1;
//	for(int v : d[u]){
//		if(visit[v] == 0){
//			parent[v] = u;
//			if(dfs(v, d)){
//				return true;
//			}
//		}else if(v != parent[u]){
//			start = u;
//			end = v;
//			return true;
//		}
//	}
//	return false;
//}
bool bfs(int u, vector<int> d[]){
	queue<int> q;
	q.push(u);
	visit[u] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int v : d[top]){
			if(visit[v] == 0){
				parent[v] = top;
				q.push(v);
				visit[v] = 1;
			}else if(v != parent[top]){
				start = v;
				en = top;
				return true;
			}
		}
	}
	return false;
}
void hien(vector<int> &cyc){
	for(int i : cyc){
		cout << i << " ";
	}
	cout << endl;
}
int main(){
	vector<int> d[10];
	d[1] = {2};
	d[2] = {1, 3, 4};
	d[3] = {2, 6, 7};
	d[4] = {2};
	d[6] = {3, 7};
	d[7] = {3, 6};
	for(int i = 1; i <= 7; i ++){
		if(visit[i] == 0){
			if(bfs(i, d)){
				cout << "Yes";
				vector<int> cyc;
				cyc.push_back(start);
				int temp = en; // thêm biến tạm để duyệt ngược từ en về start
                while (temp != start) {
                    cyc.push_back(temp);
                    temp = parent[temp];
                }
                cyc.push_back(start);

				hien(cyc);
				return 0;
			}
		}
	}
	cout << start << en;

} 