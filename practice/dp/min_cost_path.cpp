#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;
int n, m;
int arr[1000][1000];
int dp[1000][1000];

int r, td, bu, dj;

int recurse(int i, int j){
    r++;
    if(i == n && j == m) return arr[n][m];
    if(i > n || j > m) return INT_MAX;
    int down = recurse(i, j + 1);
    int right = recurse(i + 1, j);
    int diagonal = recurse(i + 1, j + 1);
    return arr[i][j] + min(down, min(right, diagonal));
}

int top_down(int i, int j){
    td++;
    if(i == n && j == m) return arr[n][m];
    if(dp[i][j] != 0) return dp[i][j];
    if(i > n || j > m) return INT_MAX;
    int down = top_down(i, j + 1);
    int right = top_down(i + 1, j);
    int diagonal = top_down(i + 1, j + 1);
    dp[i][j] = arr[i][j] + min(down, min(right, diagonal)); 
    return dp[i][j];
}

int bottom_up(){
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= m; i++){
        dp[n + 1][i] = INT_MAX;
    }
    for(int i = 1; i <= m; i++){
        dp[i][m + 1] = INT_MAX;
    }
    dp[n][m] = arr[n][m];
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j--){
            bu++;
            if(i == n && j == m) continue;
            int down = dp[i][j + 1];
            int right = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];
            dp[i][j] = arr[i][j] + min(down, min(right, diagonal));
        }
    }
    return dp[1][1];
}

int djikstra(){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, 1, 1);
    while(!pq.empty()){
        dj++;
        int c = get<0>(pq.top());
        int i = get<1>(pq.top());
        int j = get<2>(pq.top());
        pq.pop();
        if(i > n || j > m) continue;
        if(i == n && j == m) return c + arr[n][m];
        pq.emplace(c + arr[i][j], i + 1, j);
        pq.emplace(c + arr[i][j], i, j + 1);
        pq.emplace(c + arr[i][j], i + 1, j + 1);
    }
    return -1;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    cout << recurse(1, 1) << ' ' << r << "\n";
    cout << top_down(1, 1) << ' ' << td << "\n";
    cout << bottom_up() << ' ' << bu << "\n";
    cout << djikstra() << ' ' << dj << "\n";
}

int main(void){
    solve();
    return 1;
}