#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> &a , int i){
	if(i == 0){
		return (a[i]%2 == 0) ? 0 : a[i];
	}
	if(a[i] % 2 == 0){
		return sum(a, i-1);
	}else{
		return a[i] + sum(a, i -1);
	}
}
int main(){
	int n = 10;
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8,9 ,10};
	cout << sum(a, a.size() - 1);
}