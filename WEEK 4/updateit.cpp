// Diogo Manim - COMPUTER SCIENCE @FCUP - COMPETITIVE PROGRAMMING CLASS 2024

// SPOJ UPDATEIT

#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree Implementation based on: geeksforgeeks.org/fenwick-tree-for-competitive-programming/

// Update the array
void add(int idx, int X, vector<int>& FenwickTree) {
    while(idx < static_cast<int>(FenwickTree.size())) {     // static_cast forces FenwickTree.size() to convert from unsigned integer -> int
        FenwickTree[idx] += X;
        idx += (idx & -idx);
    }
}

// Calculate prefix sum until index idx
int sum(int idx, vector<int>& FenwickTree) {
    int runningSum = 0;
    
    while(idx > 0) {
        runningSum += FenwickTree[idx];
        idx -= (idx & -idx);
    }

    return runningSum;
}

int main() {
    int t;          // Number of test cases

    cin >> t;

    while(t--) {
        int n, u;   // Number of elements and updates

        cin >> n >> u;

        // Fenwick Tree initialized with 0, and with 1-based indexing
        vector<int> FenwickTree(n + 1, 0);

        // Process the updates
        for(int i = 0; i < u; i++) {
            int l, r, val;

            cin >> l >> r >> val;

            // Transforms input into 1-based indexing, and adds 'val' from [l + 1, r + 1]
            add(l + 1, val, FenwickTree);       // Adds 'val' starting from position l + 1
            add(r + 2, -val, FenwickTree);      // Subtracts 'val' after position r + 1
        }

        int q;      // Number of queries

        cin >> q;

        // Process each query
        for(int i = 0; i < q; i++) {
            int index;
            cin >> index;

            // Convert to 1-based indexing and fetch result
            cout << sum(index + 1, FenwickTree) << "\n";
        }
    }

    return 0;
}

// LINK: spoj.com/problems/UPDATEIT/