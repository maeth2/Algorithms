/*
Given a set of positive integers, find if it is possible for any subset to sum to a target value V.

This problem can be easily solved using recursion as well as dynamic programming.

Looking at the set, we know that we can only use each value once. This means that when traversing through the set,
for each index we can recursively call two scenarios:
    1. We use the value, add the value to the sum, check the next value
    2. We do not use the value, don't add the value to the sum, check the next value.

By starting from the last value, we can recursively call each index using the scenarios stated above. If we start with the 
V and subtract from it, we will know that there is a valid subset if the target ever reaches 0.

This recursive approach has a time complexity of O(2^N).

To further optimise the solution, we can implement a dynamic program approach. We can memoise the recurcive calls by creating 
and storing the results of each value and remaining target:
    dp[i][j] = dp[sum][value]

The solution below encorporates a bottom-up approach where we calculate whether each k target from 0 to V can be represented
by a subset sum. This is similar to the recursive approach, as we also use data from other sum/value pairs to build our answer:
    recurse(index - 1, sum - value) vs dp[sum - value][index - 1]
But rather then calling from the top to the bottom and then up again, we iteratively calculate each sum/value from the bottom-up
knowing that the base case of k = 0 is always true.

The time complexity for both top-down and bottom-up solutions are O(N*V).
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

bool recurse(int n, int v, vector<int> values){
    if(v == 0){
        return true;
    }
    if(v < 0 || n <= 0){
        return false;
    }
    return recurse(n - 1, v - values[n - 1], values) || recurse(n - 1, v, values);
}

bool dynamic_approach(int n, int v, vector<int> values){
    vector<vector<bool>> dp(v + 1, vector<bool>(n + 1));
    for(int i = 0; i <= n; i++){
        dp[0][i] = true;
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= n; j++){
            if(i - values[j - 1] >= 0){
                dp[i][j] = dp[i - values[j - 1]][j - 1];
            };
            dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
    }
    return dp[v][n];
}

void solve(){
    int n, v;
    cin >> n >> v;
    vector<int> values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    cout << recurse(n, v, values) << "\n";
    cout << dynamic_approach(n, v, values) << "\n";
}

int main(void){
    solve();
    return 1;
}