#include<bits/stdc++.h>
using namespace std;

string got[] = {"", "Thousand", "Million", "Billion"};
string teens[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string f2(int n){
	int num = n;
	string ans = "";
	if(num/100!=0){
		ans+=teens[num/100];
		ans+=" Hundred ";
	}
	num = num%100;
	if(num< 20){
		ans+=teens[num];
	}
	else {
		ans+=tens[num/10];
		ans+=" ";
		num = num%10;
		ans+=teens[num];
	}
	return ans;
}

string f1(int n, int i){
	if(n == 0) return "";

	if(n >= 1000)
	return f1(n/1000, i+1)+ " "+got[i+1]+" " +f2(n%1000);

	else return f2(n%1000);
}

int main(){
	int n; cin >> n;
	if(n == 0) cout << "Zero";
	else
	cout << f1(n, 0);
}