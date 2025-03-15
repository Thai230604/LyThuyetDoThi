#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> size;

struct edge{
	int u, v;
	int w;
	edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	}
};

void make_set(int n){
	parent.resize(n + 1);
	size.resize(n + 1);
	for(int i  =0 ; i <= n ; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false; // cung cha roi ko lay lam cay khung
	if(size[a] < size[b]) swap(a, b);
	parent[b] = a;
	size[a] += size[b];
	return true;
}

bool compare(edge a, edge b){
	return a.w < b.w;
}
void kruskal(vector<edge> &canh, int n){
	vector<edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), compare);
	
	for(int i = 0 ; i < canh.size(); i++){
		if(mst.size() == n - 1) break;
		if(uni(canh[i].u , canh[i].v)){
			mst.push_back(canh[i]);
			d += canh[i].w;
		}
	}
	if(mst.size() != n - 1){
		cout << "Ko tao ra cay khung cuc tieu";
	}else{
		for(auto &it : mst){
			cout << it.u << " den " << it.v << " dai " << it.w << endl;
 		}
	}
}



int main(){
	int n = 6;
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
	make_set(n);
	kruskal(canh, n);
}

//Thuật toán Kruskal là một trong những thuật toán nổi tiếng trong lý thuyết đồ thị, 
//dùng để tìm cây khung nhỏ nhất (Minimum Spanning Tree - MST) của một đồ thị liên thông, vô hướng và có trọng số. 
//Cây khung nhỏ nhất là cây con của đồ thị bao gồm tất cả các đỉnh của đồ thị và có tổng trọng số các cạnh nhỏ nhất.