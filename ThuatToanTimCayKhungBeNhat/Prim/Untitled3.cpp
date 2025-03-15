#include <bits/stdc++.h>

using namespace std;
float sum(vector<float> &a, int l, int r){
	if(l == r){
		return (a[l] > 0) ? a[l] : 0;
	}
	int m = (r + l)/2;
	float b = sum(a, l, m);
	float c = sum(a, m + 1, r);
	return b + c;
}

int main(){
	int n = 10;
	vector<float> a = {-1, 2, -3, -4, 5, -6, 7, -8,9 ,10};
	cout << sum(a, 0, a.size() - 1);
}