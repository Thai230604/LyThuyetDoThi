#include <bits/stdc++.h>

using namespace std;

void xuat(set<int> d){
	for(int i : d){
		cout << i << " ";
	}
}
int main(){
	set<int> a= { 1,2,3};
	set<int> b= {4,5,6};
	xuat(a + b);
}