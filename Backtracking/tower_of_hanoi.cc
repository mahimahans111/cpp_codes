//ahaan twist : no disk can be placed on the top of a smaller disk ! :)
#include<bits/stdc++.h>	
using namespace std;

void towerOfHanoi(int n, char src, char dest, char helper){
	if(n == 0) return;

	towerOfHanoi(n-1, src, helper, dest);
	cout << n << " : " << src << " -> " << dest << endl;
	towerOfHanoi(n-1, helper, dest, src);
}

int main(){
	int n;
	cout << "Enter the number of disks : ";
	cin >> n;
	towerOfHanoi(n, 'A', 'B', 'C');
}

