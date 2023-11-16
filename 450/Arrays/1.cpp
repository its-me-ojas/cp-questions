// Given an array A of size N of integers. Your task is to find the minimum and
// maximum elements in the array.

//

// Example 1:

// Input:
// N = 6
// A[] = {3, 2, 1, 56, 10000, 167}
// Output: 1 10000
// Explanation: minimum and maximum elements of array are 1 and 10000.
//

// Example 2:

// Input:
// N = 5
// A[]  = {1, 345, 234, 21, 56789}
// Output: 1 56789
// Explanation: minimum and maximum element of array are 1 and 56789.
//

// Your Task:
// You don't need to read input or print anything. Your task is to complete the
// function getMinMax() which takes the array A[] and its size N as inputs and
// returns the minimum and maximum element of the array.

//

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

//

// Constraints:
// 1 <= N <= 105
// 1 <= Ai <=1012

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    pair<ll, ll> pp = getMinMax(a, n);

    cout << pp.first << " " << pp.second << endl;
  }
  return 0;
}
// } Driver Code Ends

pair<long long, long long> getMinMax(long long a[], int num) {
  pair<long long, long long> p = {LLONG_MAX, LLONG_MIN};
  for (int i = 0; i < num; i++) {
    if (p.first >= a[i]) {
      p.first = a[i];
    }
    if (p.second <= a[i]) {
      p.second = a[i];
    }
  }
  return p;
}
