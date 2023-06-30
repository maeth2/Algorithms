#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int arr[1000];
int dp[1000][1000];

int r, td, bu;

int recurse(int i, int j, int c){
    r++;
    if(i == 0 || j == 0) return c;
    if(arr[i] < arr[j]){
        return recurse(i, j - 1, c);
    }else{
        return max(recurse(i, j - 1, c), recurse(j, j - 1, c + 1));
    }
}

int top_down(int i, int j, int c){
    td++;
    if(i == 0 || j == 0) return c;
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    if(arr[i] < arr[j]){
        dp[i][j] = top_down(i, j - 1, c);
    }else{
        dp[i][j] = max(top_down(i, j - 1, c), top_down(j, j - 1, c + 1));
    }
    return dp[i][j];
}

int bottom_up(int n){
    //i = Current Size of Array
    //j = Current Index of Array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            bu++;
            if(arr[i] < arr[j]){
                dp[i][j] = dp[i][j - 1];
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[j][j - 1] + 1);
            }
        }
    }
    return dp[n][n];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << recurse(n, n - 1, 1) << ", Iterations: " << r << "\n";
    cout << top_down(n, n - 1, 1) << ", Iterations: " << td << "\n";
    cout << bottom_up(n) << ", Iterations: " << bu << "\n";
}

int main(void){
    solve();
    return 1;
}