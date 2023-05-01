#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/*
Catalan numbers are a sequence of positive integers denoted by the formula:
    Cn = (2n)! /((n + 1)!n!)

It is simple to calculate it brute force by finding each factorial. However, that approach is inefficient as each factorial can get
exponentially larger.

To solve the equation dynamically, we can devrive that:
    Cn/Cn-1 = (4n^2 - 2n) / (n + 1) / n
            = (4n^2 - 2n) / n(n + 1)
            = n(4n - 2) / n(n + 1)
            = (4n - 2) / (n + 1)
    Cn = (4n - 2) / (n + 1) * Cn-1
           
Alternatively we can also devrive and use the recursive formula:
    Cn = sum(n, i = 0) (Ci * C(n - i - 1))

The dynamic programming approach stores the Catalan number for each index and uses it to solve for the next one.
*/

int recursive_relations(int n){
    int ln = 1;
    for(int i = 2; i <= n; i++){
        ln = ln * (4*i - 2) / (i + 1);
    }
    return ln;
}

int dynamic_programming(int n){
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[0] = 1;
    for(int j = 2; j <= n; j++){
        for(int i = 0; i < j; i++){
            dp[j] += dp[i] * dp[j - i - 1];
        }
    }
    return dp[n];
}

void solve(){
    int n;
    cin >> n;
    
    cout << recursive_relations(n) << "\n";
    cout << dynamic_programming(n) << "\n";

}

int main(void){
    solve();
    return 1;
}