#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;


int dp(int n, int k){
    vector<int> dp(n + 1);
    dp[1] = k;
    dp[2] = k * k;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
    }
    return dp[n];
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << dp(n, k) << "\n";
}

int main(void){
    solve();
    return 1;
}