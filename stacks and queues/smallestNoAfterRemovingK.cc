#include <iostream>
 #include <stack>
 #include <string>
 using namespace std;
 
 string removeMakeSmallest(string arr, int k)
 {
     int n = arr.length();
     // write your code here and return the minimum number as string;
     stack<char>s;
// 	char ans[n-k];
	s.push(arr[0]);
	int p = k;
	for(int i = 1; i < n; i++){
		if(arr[i] >= s.top()){
			s.push(arr[i]);
		}
		else{
			while(!s.empty() && s.top() > arr[i]){
				if(p == 0) break;
				s.pop();
				p--;
			}
			s.push(arr[i]);
		}
	}
	int in = 0;
	string ans;
	while(!s.empty()){
		ans[in] = s.top();
		in++;
		s.pop();
	}

	for(int i = 0; i < (n-k)/2; i++){
		swap(ans[i],ans[n-k-1-i]);
	}
	
// 	for(int i = 0; i < n-k; i++){
// 		cout << ans[i];
// 	}
// 	cout << endl;
    return ans;
 }
 
 int main()
 {
     int k = 0;
     cin >> k;
     string s;
     cin >> s;
     cout << removeMakeSmallest(s, k) << endl;
     return 0;
 }