#include <bits/stdc++.h>

using namespace std;

struct Hoithao{
	string ten;
	float start;
	float end;
	Hoithao(string t, float s, float e){
		ten = t;
		start = s;
		end = e;
	}
};
bool com(Hoithao a, Hoithao b){
	return a.end < b.end;
}
pair<int , vector<string>> A(vector<Hoithao> &h){
	sort(h.begin(), h.end(), com);
	float last = h[0].end;
	int k = 1;
	vector<string> s;
	s.push_back(h[0].ten);
	for(int i = 1; i < h.size() ; i++){
		if(h[i].start >= last){
			s.push_back(h[i].ten);
			last = h[i].end;
			k++;
		}
	}
	return {k, s};
}
int main(){
	Hoithao h1 = Hoithao("Tim kiem viec lam 1", 7, 8.5);
	Hoithao h2 = Hoithao("Tim kiem viec lam 2", 8.5, 9.5);
	Hoithao h3 = Hoithao("Tim kiem viec lam 3", 9, 10);
	Hoithao h4 = Hoithao("Tim kiem viec lam 4", 10, 11.5);
	Hoithao h5 = Hoithao("Tim kiem viec lam 5", 11, 12);
	Hoithao h6 = Hoithao("Tim kiem viec lam 6", 11.5, 12.5);
	vector<Hoithao> h = {h5, h4, h3, h2, h1, h6};
	auto it = A(h);
	cout << it.first<<endl;
	for(string i : it.second){
		cout << i << endl;
	}
	
}