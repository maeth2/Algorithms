#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, m;
int r, td, bu;
int obstacles[10000][10000];
int dp[10000][10000];

int recursion(int i, int j){
    r++;
    if(i == 1 && j == 1) return 1;
    if(i < 1 || j < 1) return 0;
    if(obstacles[i][j]) return 0;
    return recursion(i - 1, j) + recursion(i, j - 1);
}

int top_down(int i, int j){
    td++;
    if(i == 1 && j == 1) return 1;
    if(i < 1 || j < 1) return 0;
    if(obstacles[i][j]) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    dp[i][j] = top_down(i - 1, j) + top_down(i, j - 1);
    return dp[i][j];
}

int bottom_up(){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bu++;
            if(i == 1 && j == 1) continue;
            if(obstacles[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][m];
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> obstacles[i][j];
        }
    }
    cout << recursion(n, m) << ' ' << r << "\n";
    cout << top_down(n, m) << ' ' << td << "\n";
    cout << bottom_up() << ' ' << bu << "\n";

}

int main(void){
    solve();
    return 1;
}