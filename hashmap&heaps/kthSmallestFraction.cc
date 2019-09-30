#include<bits/stdc++.h>
using namespace std;
 
 // -----------------------------------------------------
     // This is a functional problem. Only this function has to be written.
     // This function takes as input the head of the linked list.
     // It should return the head of the modified list.
 
 class Fraction{
     public:
   int num;
   int den;
   double value;
   
    Fraction(int num, int den, double value){
        this->num = num;
        this->den = den;
        this->value = value;
    }   
    
    Fraction(){
        
    }
 };
 
 
 class myComparator 
{ 
public: 
    bool operator() (const Fraction& p1, const Fraction& p2) 
    { 
        return p1.value > p2.value; 
    } 
};
 
 vector<int> kthSmallestPrimeFraction(vector<int> &v, int K)
 {
     int n = v.size();
     sort(v.begin(), v.end());
     int den = n-1;
     int k = 1;
     priority_queue< Fraction, vector<Fraction>, myComparator > pq;
      for(int i = 0; i < den; i++){
         pq.push(Fraction(i, den,  double(v[i])/double(v[den]) ));
     }
     pair<int, int> ans;
     while(k <= K){
        Fraction cur = pq.top();
        ans = pair<int, int>(cur.num, cur.den);
        pq.pop();
        int curden = ans.second;
        Fraction newcur = Fraction(cur.num, cur.den-1, double(v[cur.num])/double(v[cur.den-1]));
        
        pq.push(newcur);
     k++;
     }
     //code here.
    vector<int>finalans;
    finalans.push_back(ans.first);
    finalans.push_back(ans.second);
    return finalans;
 }
 
 int main()
 {
     int k, n;
     cin >> k >> n;
     vector<int> arr(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> arr[i];
     }
 
      vector<int>ans = kthSmallestPrimeFraction(arr, k);
     cout << arr[ans[0]] << '/' << arr[ans[1]]; 
     cout << endl;
 }