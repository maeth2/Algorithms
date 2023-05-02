/*
Given a set of coins, find the number of ways to sum up to a certain value.

Each coin can be used more then once.

To solve for this problem we have to first find all the conditions:
    1. If we use the coin, we have to subtract the value of the coin from the total and keep using the same coin
    2. If we don't use the coin, we skip to the next coin
    3. If the total reaches exactly 0, then we have found a way to get to that value

Doing this recursively means that we have to make add the amount when we use the coin and when we dont for each call.

To further optimise this algorithm, we will use the recursive formula where i is the target value:
    count(i) = sum(count(i - coins[]))

Since we know that when the target value is 0 there is only 1 way to obtain it, we can dynamically solve the problem by
iterating through each count at each target for each coin.

However, we cannot iterate through all the coins first then the targets. This is because the number of ways to build up to the 
target is the same as the combination of coins to that value. A combination is not ordered and therefore each one can only be
counted once. By iterating through all the coins before the targets, we are unable to keep track of the of used combinations and
therefore will get an incorrect result. To counter this, we either need to flip the order of iteration, or keep track of the
combinations using a 2D array.
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int dp(int v, vector<int> coins){
    vector<int> dp(v + 1);
    dp[0] = 1;
    for(int c : coins){
        for(int i = c; i <= v; i++){
            dp[i] += dp[i - c];
        }
    }
    return dp[v];
}

int dp(int v, int n, vector<int> coins){
    vector<vector<int>> dp(v + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= n; j++){
            if(i - coins[j - 1] >= 0){
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
            dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[v][n];
}

void solve(){
    int n, v;
    cin >> n >> v;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    cout << dp(v, n, coins)<< "\n";
    cout << dp(v, coins)<< "\n";
}

int main(void){
    solve();
    return 1;
}