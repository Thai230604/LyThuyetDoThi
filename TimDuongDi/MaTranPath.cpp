#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> visit(6, vector<bool>(6, 0));
vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};
map<pair<int, int> , pair<int, int>> parent;
int l[6][6];
bool dfs(int i , int j , vector<vector<char>> &m){
	if(m[i][j] == 'B') return true;
	visit[i][j] = 1;
	for(int a = 0; a < 4; a++){
		int x = i + dx[a];
		int y = j + dy[a];
		if(x >= 0 && x < 6 && y >= 0 && y < 6 && m[x][y] != 'x' && visit[x][y] == 0){
			if(dfs(x, y, m)) return true;
		}
	}
	return false;
}
int v;
int u;

bool bfs(int i, int j, vector<vector<char>> &m){
	queue<pair<int, int>> q;
	q.push({i, j});
	visit[i][j] = 1;
	l[i][j] = 0;
	while(!q.empty()){
		auto b = q.front(); 
		q.pop();
		for(int a = 0; a < 4 ; a++){
			int x = b.first + dx[a];
			int y = b.second + dy[a];
			if(x >= 0 && x < 6 && y >= 0 && y < 6 && m[x][y] != 'x' && visit[x][y] == 0){
			    visit[x][y] = 1;
			    l[x][y] = l[b.first][b.second] + 1;
			    parent[{x, y}] = {b.first, b.second};
					if(m[x][y] == 'B'){
			    	v = x ;
					u = y;
					return true;
				}
			    q.push({x, y});
				}
		}
		}
	return false;
}
void xuat(){
	for(int i = 0 ; i < 6; i++){
		for(int j = 0 ; j < 6; j++){
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}
void hien(){
	for(int i = 0 ; i < 6; i++){
		for(int j = 0 ; j < 6; j++){
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	vector<vector<char>> m = {{'A', 'o' , 'o', 'x', 'o', 'o'},
							 {'o', 'x' , 'o', 'o', 'o', 'o'},
							 {'o', 'x' , 'o', 'o', 'o', 'o'},
							 {'o', 'o' , 'o', 'o', 'x', 'x'},
							 {'B', 'x' , 'o', 'o', 'x', 'o'},
							 {'o', 'x' , 'o', 'x', 'x', 'x'}};
	if(bfs(0, 0, m)){
		xuat();
	}else{
		cout << "Ko dg di"<< endl;
	}
//	pair<int, int> it = {v, u};
//	int c = 0;
//	while(it.first != 0 || it.second != 0){
//		c ++;
//		it = parent[{it.first, it.second}];
//	}
//	cout << c; 
    cout << l[v][u] << endl;
    hien();
}