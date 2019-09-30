#include<bits/stdc++.h>
using namespace std;

void printDig(int dig){
	char words[][10] = {
		"zero", "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine"
	};
	cout << words[dig];
}

void printNum(int n){
	if(n == 0) return;
	int unitDig = n % 10;
	int remNum = n / 10;
	printNum(remNum);
	printDig(unitDig);
	cout << " ";
}

int main(){
	int n;
	cout << "Enter a number, nibba ! \n";
	cin >> n;
	printNum(n);
}