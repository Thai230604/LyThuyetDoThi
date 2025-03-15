#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<vector<int>> a(5, vector<int>(5, 0));
vector<vector<int>> b(5);
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y;
        b[x - 1].push_back(y);
        b[y - 1].push_back(x);
    }
    for(int i = 0; i < n; i++){
        cout << i + 1 << " ";
        for(int x : b[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}