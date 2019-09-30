#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return maximum absolue 
// difference in linear time. 
int maxDistance(int arr[], int n) 
{ 
    // max and min variables as described 
    // in algorithm. 
    int max1 = INT_MIN, min1 = INT_MAX; 
    int max2 = INT_MIN, min2 = INT_MAX; 
  
    for (int i = 0; i < n; i++) { 
  
        // Updating max and min variables 
        // as described in algorithm. 
        max1 = max(max1, arr[i] + i); 
        min1 = min(min1, arr[i] + i); 
        max2 = max(max2, arr[i] - i); 
        min2 = min(min2, arr[i] - i); 
    } 
  
    // Calculating maximum absolute difference. 
    return max(max1 - min1, max2 - min2); 
} 
  
// Driver program to test the above function. 
int main() 
{ 
    int arr[] = { -70, -64, -6, -56, 64, 
                  61, -57, 16, 48, -98 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << maxDistance(arr, n) << endl; 
    return 0; 
} 