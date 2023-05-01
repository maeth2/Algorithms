#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int fib(int i){
    if(i == 0) return 0;
    if(i == 1) return 1;

    return fib(i - 1) + fib(i - 2);
}

void solve(){
    int i;
    cin >> i;

    vector<ll> dp(i + 1);

    dp[0] = 0;
    dp[1] = 1;

    for(int j = 2; j <= i; j++){
        dp[j] = dp[j - 1] + dp[j - 2]; 
    }

    cout << dp[i] << "\n";
}

int main(void){
    solve(); 
    return 1;
}