#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
int price[1000];
int dp[1000][1000];

int max(int a, int b){return a > b ? a : b;}

int a, b, c;

int recurse(int i, int n){
    a++;
    if(i == 0){
        return 0;
    }
    return max(recurse(i - 1, n), price[i] + recurse(n - i, n - i));
}

int top_down(int i, int n){
    b++;
    if(i == 0){
        return 0;
    }
    if(dp[i][n] != 0){
        return dp[i][n];
    }else{
        dp[i][n] = max(top_down(i - 1, n), price[i] + top_down(n - i, n - i));
        return dp[i][n];
    }
}

int bottom_up(int n){
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            c++;
            if(j - i < 0) continue;
            dp[i][j] = max(dp[i - 1][j], price[i] + dp[j - i][j - i]);
        }
    }
    return dp[n][n];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    cout << recurse(n, n) << ' ' << a << "\n";
    cout << top_down(n, n) << ' ' << b << "\n";
    cout << bottom_up(n) << ' ' << c << "\n";
}

int main(void){
    solve();
    return 1;
}