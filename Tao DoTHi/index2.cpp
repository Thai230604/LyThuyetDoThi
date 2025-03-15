#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;

vector<pair<int ,int>> c;
int main(){
    cin >> n ;
    vector<vector<bool>> in = {{0,1,1,1,0},
                                {1,0,1,1,1},
                                {1,1,0,1,1},
                                {1,1,1,0,1},
                                {0,1,1,1,0}};

    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0; j < n; j++){
            if(in[i][j] == 1){
                pair<int , int> a = {i+ 1, j + 1};
                pair<int, int> b = {j + 1, i + 1};
                if(find(c.begin(), c.end(),b) == c.end()){
                    c.push_back(a);
                }
            }
        }
    }
    for(pair x : c){
        cout << x.first << " " << x.second;
        cout << endl;
    }

}