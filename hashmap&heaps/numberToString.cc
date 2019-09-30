#include<bits/stdc++.h>
using namespace std;

string got[] = {"", "thousand", "million", "billion"};
string teens[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string f2(int n){
	int num = n;
	string ans = "";
	if(num/100!=0){
		ans+=teens[num/100];
		ans+=" hundred ";
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
	cout << f1(123456789, 0);
}