#include<iostream>
#include<cstring>
using namespace std;

char keypad[20][20] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void keypad_codes(char in[], char out[], int i, int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout << out << endl; return;
	}

	if(in[i] == '0'){
		keypad_codes(in, out, i+1, j);
	}

	int digit = in[i] - '0';
	for(int k = 0; keypad[digit][k] != '\0'; k++){
		
		out[j] = keypad[digit][k];
		keypad_codes(in, out, i+1, j+1);
	}
}

int main(){
	char in[100];
	cin >> in;
	char out[100];
	keypad_codes(in, out, 0, 0);
}
