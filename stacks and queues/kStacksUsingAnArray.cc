#include<bits/stdc++.h>
using namespace std;

class kStack{
	int da[100];
	int pa[100];
	int k;
	int sha[100];
	int free;

  public:
  	kStack(int k){
  		this->k = k;
  		free = 0;
  		for(int i = 0; i < 100; i++){
  			da[i] = 0;
  		}
  		for(int i = 0; i < 99; i++){
  			pa[i] = i+1;
  		}
  		pa[99] = -1;
  		for(int i = 0; i < k; i++){
  			sha[i] = -1;
  		}
  	}

  	void push(int i,int x){
  		if(free == -1) return;
  		int temp = free;
  		free = pa[free];
  		pa[temp] = sha[i];
  		sha[i] = temp;
  		da[temp] = x; 
  	}

  	void pop(int i){
  		int temp = sha[i];
  		sha[i] = pa[sha[i]];
  		pa[temp] = free;
  		free = temp;
  		da[temp] = 0;
  	}

  	int top(i){
  		return da[sha[i]];
  	}  	

  	bool isEmpty(int i){
  		if(sha[i] == -1) return true;
  		return false;
  	}

  	bool isFull(){
  		if(free == -1) return true;
  		return false;
  	}

};

int main(){

}