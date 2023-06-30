#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int m, n;
int a, b, c;
int path[100][100];

//Recursion
int recursion(int x, int y){
    a++;
    if(x == n - 1 && y == m - 1) return 1;
    if(x >= n || y >= m) return 0;
    return recursion(x + 1, y) + recursion(x, y + 1);
}

//Top-Down approach
int dp(int x, int y){
    b++;
    if(x == n - 1 && y == m - 1) return 1;
    if(x >= n || y >= m) return 0;
    if(path[y][x] != 0){
        return path[y][x];
    }else {
        path[y][x] = dp(x + 1, y) + dp(x, y + 1);
        return path[y][x];
    }
}

//Bottom-Up approach (Kinda)
int dp2(int m, int n){
    vector<vector<int>> dp (m + 1, vector<int>(n + 1));
    dp[m - 1][n - 1] = 1;
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            c++;
            if(i == m - 1 && j == n - 1) continue;
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}

void solve(){
    cin >> m >> n;
    cout << recursion(0, 0) << " " << a << "\n";
    cout << dp(0, 0) << " " << b << "\n";
    cout << dp2(m, n) << " " << c << "\n";
}

int main(void){
    solve();
    return 1;
}