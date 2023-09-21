#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int grid[10000][10000];
int dp[10000][10000];
int n;

//i = start
//j = destination
//k = how many nodes to go through
int recurse(int i, int j, int k){
    if(k == 1) return grid[i][j];
    return min(recurse(i, j, k - 1), recurse(i, k, k - 1) + recurse(k, j, k - 1));
}

void bottom_up(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            string c;
            cin >> c;
            if(c == "i") grid[i][j] = INT16_MAX;
            else grid[i][j] = stoi(c);
            dp[i][j] = grid[i][j];
        }
    }

    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int c = recurse(i, j, n);
            if(c == INT16_MAX) cout << "i ";
            else cout << c << " ";
        }
        cout << "\n";
    }
    
    bottom_up();
    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INT16_MAX) cout << "i ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 1;
}