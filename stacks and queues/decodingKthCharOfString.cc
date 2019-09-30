#include<bits/stdc++.h>
using namespace std;

char decodeKthChar(string str, int k){
	int size = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i]>='0' && str[i] <= '9'){
			size*= int(str[i]-'0');
		}
		else size++;
	}
	 for(int i = str.length()-1; i >= 0; i--){
	 	if(str[i]>='0' && str[i] <= '9'){
	 		size = size/int(str[i]-'0');
	 	}
	 	else{
	 		if((k+1)%size == 0) return str[i];
	 		else{
	 			k = k%size;
	 			size--;
	 		}
	 	}
	 }
}

int main(){
	string str;
	cin >> str;
	int k; cin >> k;
	char ans = decodeKthChar(str, k);
	cout << ans;
}