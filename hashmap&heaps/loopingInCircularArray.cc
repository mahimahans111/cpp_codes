#include<bits/stdc++.h>
using namespace std;

bool findCycle(int arr[], int n){
	int pv[n] ;
	int tv[n] ;
	for(int i = 0; i < n; i++){
		pv[i] = tv[i] = 0;
	}

	int flag = 1;
	int start = 0;
	int len = 0;
	for(int i = 0; i < n; ){
		// cout << i << " " << arr[i] << endl;

		if(start == 0){
				if(arr[i] > 0){
					flag = 1;
				}
				else flag = 0;
				len = 0;
				for(int m = 0; m < n; m++)tv[m] = 0;
				start = 1;
			}
		if(arr[i] == 0){
			start = 0;
			len = 0;
			i = (i+1+n)%n;	
			for(int m = 0; m < n; m++)tv[m] = 0;		
			continue;
		}
		else if(!pv[i] && !tv[i] && start == 1){
			if((arr[i] > 0 && flag == 1) || (arr[i] < 0 && flag == 0)){
				tv[i] = pv[i] = 1;
				if(arr[i]>0)i = (i+arr[i])%n;
				else i = i+arr[i]+n;
				len++;
				continue;
			}
			else {
				start = 0;
				len = 0;
				for(int m = 0; m < n; m++)tv[m] = 0;
				continue;
			}
		}
		else if(pv[i] && !tv[i] && start == 1){
			start = 0;
				len = 0;
				for(int m = 0; m < n; m++)tv[m] = 0;
				continue;
			
		}
		else if(pv[i] && tv[i] && start == 1 && len > 1){
			return true;
		}
		int f=0;
	    	for(int k = 0; k < n; k++){
		    if(pv[k] == 1){
		        f++;
		    }
		 }
		  if(f == n){ return false;}
	
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	bool ans = findCycle(arr, n);
	ans==1?cout << "true":cout << "false";
}