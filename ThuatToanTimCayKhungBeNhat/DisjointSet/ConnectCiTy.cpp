#include <bits/stdc++.h>

using namespace std;
vector<int> parent(6, 0);
vector<int> size(6 , 0);
void make_set(){
	for(int i = 1; i <= 5; i++){
		parent[i] = i;
		size[i] = 1;
	}
}
int find(int v){
	if(v == parent[v]){
		return v;
	}
	parent[v] = find(parent[v]);
	return parent[v];
}
void uni(int x, int y){
	int a = find(x);
	int b = find(y);
	if( a!= b){
		if(size[a] < size[b]){
			swap(a, b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}
bool connected(int x, int y){
	int a = find(x);
	int b = find(y);
	return a == b;
}
void xuat(vector<int> c){
	for(int i : c){
		cout << i << " ";
	}
	cout << endl;
}
int main(){
	vector<int> city = {1,2,3,4,5};
	make_set();
	uni(1, 3);
	cout << connected(1, 3) << endl;
	cout << connected(1, 2) << endl;
	xuat(parent);
	xuat(size);
}