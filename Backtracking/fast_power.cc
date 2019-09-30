#include<bits/stdc++.h>
using namespace std;
//normalPower takes b steps! b can be very large..so we write an optimized solution.
int normalPower(int a, int b){
	if(b == 0) return 1;

	return a*normalPower(a, b-1);
}
//The following fast power function has a log(2)N complexity. 
/*mine
int fastPower(int a, int b){
	if(b == 0) return 1;

	if(b%2 == 0) return pow(fastPower(a, b/2), 2);
	else return pow(fastPower(a, b/2), 2)*a;
}*/
int fastPower(int a, int b){
	if(b == 0) return 1;
	int smallAns = fastPower(a, b/2);
	smallAns *= smallAns;

	if(b&1) return a*smallAns;
	else return smallAns;
}

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	//int ans = normalPower(n1, n2);
	//cout << ans;
	cout << endl << fastPower(n1, n2);
}