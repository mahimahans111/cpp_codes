#include<climits>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

void minLengthWord(char input[], char output[]){
    int count, m, index;
    int i,j,k;
    int a = 0;
    //int n = strlen(input);
    m = INT_MAX;
    i = 0;

    while(input[i]!='\0'){
        count = 0;
        while(input[i]!=' ' && input[i]!='\0'){
            count ++;
            i++;
        }
        if(count<m){
            index = i - count;
            m = count;
        }
        if(input[i]=='\0')break;
        else i++;
    }
    for(i=0;i<m;i++){
        output[i]=input[index];
        index++;
    }
    output[m] = '\0';
}
int main(){
    char input[100];
    cin.getline(input, 100);
    char output[100];
    minLengthWord(input, output);
    cout << output << endl;
}