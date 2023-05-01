#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}

int LCS(string a, string b, int i){
    int ans = 0;
    int la = a.length();
    int lb = b.length();

    if(la == 0 || lb == 0){
        return i;
    }

    string na = a.substr(0, la - 1);
    string nb = b.substr(0, lb - 1);

    if(a[la - 1] == b[lb - 1]){
        ans = LCS(na, nb, i + 1);
    }else{
        ans = max(LCS(na, b, i), LCS(a, nb, i));
    }
    return ans;
}

void solve(){
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();

    /*
    DP approach:

    Instead of calculating top down, we calculate bottom up.

    For example:
        ABCBDAB
        BDCABA

        The first loop checks the LCS for A and BDCABA.
        The second loop checks the LCS for AB and BDCABA.
        etc...

    It essentially keeps track of the LCS at each index of the two strings
    */
    vector<vector<int>> dp (la + 1, vector<int>(lb + 1));

    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << LCS(a, b, 0) << "\n";
    cout << dp[la][lb] << "\n";
}

int main(void){
    solve();
    return 1;
}