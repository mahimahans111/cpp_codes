#include<bits/stdc++.h>
using namespace std;

class MinHeapNode{
public:
	char data;
	int freq;
	MinHeapNode*left, *right;

public:
	MinHeapNode(int data,int freq){
		this->data = data;
		this->freq = freq;
		this->left = this->right = NULL;
	}
};

class mycompare{
public:
	bool operator()(MinHeapNode*l, MinHeapNode*r){
	    if(l->freq == r->freq){
	        return l->data < r->data;
	    }
		return l->freq > r->freq;
	}
};

void printCodes(MinHeapNode* root, string str){
	if(!root) return;

	if(root->data!='$'){
		cout << str << " ";
		return;
	}

	printCodes(root->left, str+"0");
	printCodes(root->right, str+"1");
}


void HuffmanCodes(char data[], int freq[], int n){
	MinHeapNode*left1, *top, *right1;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, mycompare> minHeap;

	for(int i = 0; i < n; i++){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}

		while(minHeap.size() != 1){
			left1 = minHeap.top();
			minHeap.pop();

			right1 = minHeap.top();
			minHeap.pop();

			top =new MinHeapNode('$', left1->freq + right1->freq);

			top->left = left1;
			top->right = right1;

			minHeap.push(top);
		}
	printCodes(minHeap.top(), "");
}

int main(){
// 	int n; cin >> n;
    string str; cin >> str;
    int n = str.length();
	char arr[n];
	int freq[n];
	for(int i = 0; i < n; i++){
		arr[i] = str[i];
	}
	for(int i = 0; i < n; i++){
		cin >> freq[i];
	}
	HuffmanCodes(arr, freq, n);
	return 0;
}