/***
 * Razorpay Coding Test Qs:
 * Given an array of size N containing positive integers.
 * The value of an array or subarray is defined as the bitwise AND of all the elements in it.
 * Determine the length of the longest subarray whose value is maximum.
 * Eg: N = 3, arr = [2, 2, 2, 2, 2]
 * Output: 5
 * Explanation: The maximum value possible is 2. The value of entire array is also 2. So, length of array i.e 5 is the longest subarray.
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= N <= 10^5
 * 0 <= arr[i] <= 10^9
 * (Sum of N for all the testcases doesn't exceed 10^6)
 * 
 * Time limit: 1s
 ***/
#include <bits/stdc++.h>

using namespace std;
// Brute Force, Time: O(n^2)
int findLongestSubarray(int n, vector<long long> arr) {
    if(n == 0)
        return 0;
    
    int ans = 1;
    long long maxv = arr[0];
    for(int i = 1; i < n; i++) {
        if(maxv < arr[i])
            maxv = arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        long long x = arr[i];
        int ctr = 0;

        for(int j = i; j < n; j++) {
            x = x & arr[j];
            ctr++;
            if(x >= maxv)
                ans = max(ans, ctr);
        }
    }
    return ans;
}
int main() {
    vector<long long> arr;
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(16);
    arr.push_back(15);
    
    cout << findLongestSubarray(4, arr);
}