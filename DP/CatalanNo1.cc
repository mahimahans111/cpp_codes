#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
using namespace std; 

cpp_int binomial(int n, int k){
    k = min(n-k, k);
    cpp_int res = 1;
    for(int i=0; i<k; i++){
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

cpp_int catalan(int n){
    return binomial(n << 1, n) / (n + 1);
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << catalan(n) << endl;
    }
    return 0;
}