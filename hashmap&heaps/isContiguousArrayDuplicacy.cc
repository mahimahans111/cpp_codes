#include <iostream>
  #include <string>
  #include <vector>
  #include <unordered_set>
  #include <climits>
  
  using namespace std;
  
  //----------------------------------------
  bool isContiguous(vector<int> &arr)
  {
      unordered_set<int>s;
      int max = INT_MIN;
      int min = INT_MAX;
      for(int i = 0; i < arr.size(); i++){
          if(arr[i] > max) max = arr[i];
          if(arr[i] < min) min = arr[i];
          s.insert(arr[i]);
      }
      return s.size() == max-min+1;
      // Write your code here
  }
  //----------------------------------------
  
  int main()
  {
      int n = 0;
      cin >> n;
      vector<int> num(n, 0);
      for (int i = 0; i < n; i++)
      {
          cin >> num[i];
      }
  
      if (isContiguous(num))
      {
          cout << "true" << endl;
      }
      else
      {
          cout << "false" << endl;
      }
  
      return 0;
  }