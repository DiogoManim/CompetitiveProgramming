// Diogo Manim - COMPUTER SCIENCE @FCUP - COMPETITIVE PROGRAMMING 2024

// UVA MAXIMUM SUM

#include <iostream>
#include <algorithm>

using namespace std;

int maxSubRectangle(int matrix[100][100], int n){
    int maxSum = -1000000;              // Initialize maxSum as a very small value

    // To obtain the maximum sum subrectangle in the 2D matrix, the problem is divided into several
    // 1D problems, solved with the Kadane's algorithm applied on each max sum subarray.
    // The variables L (left) and R (right), just keep track of the columns to do all the possible combinations

    for(int L = 0; L < n; L++) {
        int temp[100] = {0};            // Temp array to store the sum on each row

        for(int R = L; R < n; R++) {
            // Update row sums given the column range L <-> R
            for(int i = 0; i < n; ++i) {
                temp[i] += matrix[i][R];
            }

            // Variables initialization for Kadane's
            int curSum = 0;
            int localMax = -127 * 100; // Minimum possible value based on constraints (min value -127, times 100 (max num on the matrix))

            // Applying 1D Kadane's algorithm
            for(int i = 0; i < n; i++) {
                curSum = max(temp[i], curSum + temp[i]);
                localMax = max(localMax, curSum);
            }

            maxSum = max(maxSum, localMax);
        }
    }

    return maxSum;
}

int main(){
    int n, maxSum;

    cin >> n;   // Number of rows/columns
    
    int matrix[100][100];

    // Reading the data into the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    maxSum = maxSubRectangle(matrix, n);

    cout << maxSum << endl;

    return 0;
}


// VIDEO: https://youtu.be/yCQN096CwWM