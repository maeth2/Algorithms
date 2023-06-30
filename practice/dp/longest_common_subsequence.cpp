#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
    
string s1, s2;

int recurse(int i, int j, int count){
    if(i == 0 || j == 0) return count;
    if(s1[i] == s2[j]){
        return recurse(i - 1, j - 1, count + 1);
    }
    return max(recurse(i - 1, j, count), recurse(i, j -1, count));
}

int dp(){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

void solve(){
    cin >> s1 >> s2;
    cout << recurse(s1.length(), s2.length(), 0) << "\n";
    cout << dp() << "\n";
}

int main(void){
    solve();
    return 1;
}