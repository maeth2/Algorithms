#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

#define PI 3.14

using namespace std;
using ll = long long;

void solve(){
    float n;
    cin >> n;

    for(float i = 0; i <= 1; i += 1/n){
        for(float j = 0; j < n; j++){
            float r = j / n / 2;
            float theta = PI * 2 * i;
            float x = r * cos(theta) + 0.5;
            float y = r * sin(theta) + 0.5;
            cout << x << " " << y << "\n";
        }
    }
}

int main(void){
    solve();
    return 1;
}   