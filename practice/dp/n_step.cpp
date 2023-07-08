#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int arr[10000];
int dp[10000];
int n;

int r, td, bu;

int recurse(int i){
    r++;
    if(i > n) return 0;
    if(i == n) return 1;
    int c = 0; 
    for(int j = 1; j <= 3; j++){
        c += recurse(i + j);
    }
    return c;
}

int top_down(int i){
    td++;
    if(i > n) return 0;
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    int c = 0;
    for(int j = 1; j <= 3; j++){
        c += top_down(i + j);
    }
    dp[i] = c;
    return dp[i];
}

int bottom_up(){
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= 3; j++){
            bu++;
            if(i + j <= n) {
                dp[i] += dp[i + j];
            }
        }
    }
    return dp[0];
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    cout << recurse(0) << " " << r << "\n";
    cout << top_down(0) << " " << td << "\n";
    cout << bottom_up() << " " << bu << "\n";
}

int main(void){
    solve();
    return 1;
}