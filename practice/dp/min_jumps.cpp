#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n;
int arr[10000];
int dp[10000];

int r, td, bu;

int recurse(int i){
    r++;
    if(i == n) return 0;
    if(i > n) return -1;
    int c = INT16_MAX;
    for(int j = 1; j <= arr[i]; j++){
        int n = recurse(i + j);
        if(n == -1) continue;
        c = min(c, n + 1);
    }
    if(c == INT16_MAX) c = -1;
    return c;
}

int top_down(int i){
    td++;
    if(i == n) return 0;
    if(i > n) return -1;
    if(dp[i] != 0) return dp[i];
    int c = INT16_MAX;
    for(int j = 1; j <= arr[i]; j++){
        int next = top_down(i + j);
        if(next == -1) continue;
        c = min(c, next + 1);
    }
    if(c == INT16_MAX) c = -1;
    dp[i] = c;
    return dp[i];
}

int bottom_up(){
    vector<int> dp(n + 1);
    dp[n] = 0;
    for(int i = n - 1; i > 0; i--){
        int c = INT16_MAX;
        for(int j = 1; j <= arr[i]; j++){
            bu++;
            if(i + j <= n){
                c = min(c, dp[i + j] + 1);
            }
        }
        if(c == INT16_MAX) c = -1;
        dp[i] = c;
    }
    return dp[1];
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << recurse(1) << ' ' << r << "\n";
    cout << top_down(1) << ' ' << td << "\n";
    cout << bottom_up() << ' ' << bu << "\n";
}

int main(void){
    solve();
    return 1;
}