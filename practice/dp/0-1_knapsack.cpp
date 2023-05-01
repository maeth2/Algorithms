/*
0-1 Knapsack problem.

You have a set of items with a value and weight.
You want to maxmise the value of items you can carry in a knapsack of a specific weight.

For each item, there are 2 possibilities:
    1. The item is in the bag
    2. The item isn't in the bag

Recursive Method:
If the item's weight is greater then the remaining weight, then assume that it is not in the bag
Otherwise, check if the MAXIMUM value of the knapsack is greater with or without the item.


Let W be the remaining weight, 
Let n be the index,
Let optimised() be the function which returns the optimised value of the knapsack,

if(weight > W) return optimised(n - 1, W)
else return max(value + optimised(n - 1, W - weight), optimised(n - 1, W))

Time Complexity: O(2^N)
    2 choices recursion per index

Top-Down Dynamic Programming:
You can further optimise this by memomising the optimised() function to an array:
    dp[n][W]

if(weight > W) return dp[n - 1][W]
else return max(value + dp[n - 1][W - weight], dp[n - 1][W])

However, this method requires the recursive loop to run which may be ineffiecient for larger data

To fix this, notice that the dp array represents the maximum value of a knapsack at the said index and weight

Therefore, we can build the dp array by using the same logic and iteratively finding the maximum of every index 
at every weight.

Bottom-Up Iterative method:
1st loop <- check maxes for each index if weight is 0
2nd loop <- check maxes for each index if weight is 1
3rd loop <- check maxes for each index if weight is 2
4th loop <- check maxes for each index if weight is 3
5th loop <- check maxes for each index if weight is 4
etc...

Time Complexity: O(N * W)
    Calculation per index is O(1), therefore the Time Complexity is equal to the array size.

To visualise this set all of the weights to 1, essentially making the maximum weight the same as the maximum amount of items. 

Now, when checking the maximum value of the knapsack it will be either for the cell directly on top (No change to weight) 
or the cell directly diagonal(Weight is changed by 1)
 
This allows us to see how by calculating the first row, each subsequent row can also be computed.

Visualizaion:
    (a) (b) (c)
     | \ | \ |
    (d) (e) (f)
     | \ | \ |
    (g) (h) (I)

In reality, the weights will differ for each item however the connection between each cell will remain the same conceptually.
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}

int recurse(int W, int i, vector<int> weights, vector<int> values){
    if(i == 0 || W == 0){
        return 0;
    }

    if(weights[i] > W){
        return recurse(W, i - 1, weights, values);
    }else{
        return max(values[i] + recurse(W - weights[i], i - 1, weights, values), recurse(W, i - 1, weights, values));
    }
}

int dynamic_knapsack(int W, int n, vector<int> weights, vector<int> values){
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for(int w = 0; w <= W; w++){
        for(int i = 1; i <= n; i++){
            if(weights[i] > w){
                dp[i][w] = dp[i - 1][w];
            }else{
                dp[i][w] = max(values[i] + dp[i - 1][w - weights[i]], dp[i - 1][w]);
            }
        }
    }

    return dp[n][W];
}

void solve(){
    int n;
    int w;
    cin >> n >> w;
    vector<int> weights(n + 1);
    vector<int> values(n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> weights[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> values[i];
    }

    cout << recurse(w, n, weights, values) << "\n";
    cout << dynamic_knapsack(w, n, weights, values) << "\n";
}

int main(void){
    solve();
    return 1;
}