#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
int arr[10000];
int dp[10000][10000];

int r, td, bu;

int recurse(int i, int j){
    r++;
    if(j == 0) return 1;
    if(abs(arr[i] - arr[j]) == 1){
        return max(recurse(i, j - 1), recurse(j, j - 1)) + 1;
    }
    return max(recurse(j, j - 1), recurse(i, j - 1));
}

int top_down(int i, int j){
    td++;
    if(j == 0) return 1;
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    if(abs(arr[i] - arr[j]) == 1){
        dp[i][j] = max(top_down(i, j - 1), top_down(j, j - 1)) + 1;
    }else{
        dp[i][j] = max(top_down(j, j - 1), top_down(i, j - 1));
    }
    return dp[i][j];
}

int bottom_up(int n){
    for(int i = 1; i<= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            bu++;
            if(abs(arr[i] - arr[j]) == 1){
                dp[i][j] = max(dp[i][j - 1], dp[j][j]) + 1;
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[j][j]);
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
    cout << recurse(n, n - 1) << " | ITERATIONS: " << r << "\n";
    cout << top_down(n, n - 1) << " | ITERATIONS: " << td << "\n";
    cout << bottom_up(n) << " | ITERATIONS: " << bu << "\n";
}

int main(void){
    solve();
    return 1;
}