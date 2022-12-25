#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const int maxN = 5e5;
int n, t[maxN];

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

/*
    Merge function for two segments
*/
int merge(int a, int b){
    return a + b;
}
/*
    Build the Segment tree.
    Children of index i will be at index i * 2 (left) and i * 2 + 1 (right).
*/
void build(int a[], int v, int l, int r){
    if(l == r){
        t[v] = a[l];
    }else{
        int m = (l + r) / 2;
        build(a, v * 2, l, m);
        build(a, v * 2 + 1, m + 1, r);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}

/*
    Shortcut function for build()
*/
void build(int *a){
    n = sizeof(a);
    build(a, 1, 0, n - 1);
}

/*
    query for specific range in segment tree
    tl and tr are the current vertex ranges while l and r are the query ranges
*/
int query(int v, int tl, int tr, int l, int r) {
    cout << "QUERYING: " << tl << " to " << tr << "\n";
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

/*
    Shortcut function for sum()
*/
int query(int l, int r){
    return query(1, 0, n - 1, l, r);
}

/*
    Update segmented tree given position and value
    Recursively search for desired position, change value, then update when traveling back
*/
void update(int v, int l, int r, int pos, int new_sum){
    if(l == r){
        t[v] = new_sum;
    }else{
        int m = (l + r) / 2;
        if(pos <= m){
            update(v * 2, l, m, pos, new_sum);
        }else{
            update(v * 2 + 1, m + 1, r, pos, new_sum);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

/*
    Shortcut function for update()
*/
void update(int pos, int new_sum){
    update(1, 0, n - 1, pos, new_sum);
}

int main(void){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    build(a);
    cout << query(5, 7) << "\n";
    return 1;
}