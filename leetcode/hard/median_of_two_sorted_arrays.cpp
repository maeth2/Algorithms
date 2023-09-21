#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> a, b;
    a = nums1.size() > nums2.size() ? nums1 : nums2;
    b = nums1.size() > nums2.size() ? nums2 : nums1;
    int n2 = b.size();
    int li = 0;
    for(int i = 0; i < n2; i++){
        int left = li;
        int right = a.size() - 1;
        int middle = (left + right) / 2;
        while(left <= right){
            middle = (left + right) / 2;
            if(b[0] == a[middle]){
                left = middle;
                break;
            }else if(b[0] > a[middle]){
                left = middle + 1;
            }else if(b[0] < a[middle]){
                right = middle - 1;
            }
        }
        li = left;
        a.insert(a.begin() + left, b[0]);
        b.erase(b.begin());
    }
    int middle = a.size() / 2;
    return a.size() % 2 == 1 ? a[middle] : (a[middle] + a[middle - 1]) / 2.0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    cout << findMedianSortedArrays(a, b);
}

int main(void){
    solve();
    return 1;
}