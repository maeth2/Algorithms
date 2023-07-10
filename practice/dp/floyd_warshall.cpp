#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            string c;
            cin >> c;
            if(c == "i") grid[i][j] = INT16_MAX;
            else grid[i][j] = stoi(c);
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] > grid[i][k] + grid[k][j]){
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
        }
    }
    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == INT16_MAX) cout << "i ";
            else cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 1;
}