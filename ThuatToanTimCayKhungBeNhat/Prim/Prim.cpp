#include <bits/stdc++.h>

using namespace std;

int n = 6; // So Dinh
vector<bool> used(n + 1, 0);

struct edge{
	int u, v;
	int w;
	edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	}
};

void prim(vector<pair<int, int>> adj[], int u){
	used[u] = 1;
	vector<edge> mst;
	int d = 0;
	while(mst.size() < n - 1){
		int x, y;
		int min_w = INT_MAX;
		for(int i = 1; i <= n ; i++){
			if(used[i]){
				for(pair<int, int> it : adj[i]){
					if(!used[it.first] && it.second < min_w){
						x = i;
						y = it.first;
						min_w = it.second;
					}
				}
			}
		}
		edge e = edge(x, y, min_w);
		mst.push_back(e);
		d+= min_w;
		used[y] = 1;
	}
	 if (mst.size() != n - 1) {
        cout << "Do thi khong lien thong, khong the tim cay khung nho nhat." << endl;
    } else {
        for (auto &it : mst) {
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
    }
}
int main(){
	vector<pair<int, int>> adj[7];
	vector<edge> canh;
	edge e1 = edge(1, 2, 12);
	edge e2 = edge(2, 3, 1);
	edge e3 = edge(3, 1, 4);
	edge e4 = edge(2, 4, 5);
	edge e5 = edge(3, 5, 2);
	edge e6 = edge(2, 5, 3);
	edge e7 = edge(4, 5, 3);
	edge e8 = edge(4, 6, 10);
	edge e9 = edge(5, 6, 8);
	canh = {e1, e2, e3, e4, e5, e6, e7, e8, e9};
	for(auto &it : canh){
		adj[it.u].push_back({it.v, it.w});
		adj[it.v].push_back({it.u, it.w});
	}
	prim(adj, 1);
	
}