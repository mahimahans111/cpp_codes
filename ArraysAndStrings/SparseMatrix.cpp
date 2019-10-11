#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of Values in Matrix 1:";
    cin>>n;
    int arr1[n+1][3];
    cout<<"Enter Number of Rows of Matrix 1:";
    cin>>arr1[0][0];
    cout<<"Enter Number of Columns of Matrix 1:";
    cin>>arr1[0][1];
    arr1[0][2]=n;
    cout<<"Enter Sparse Matrix 1"<<endl;
    for(int i=0;i<arr1[0][2];++i)
    {
        cin>>arr1[i][0]>>arr1[i][1]>>arr1[i][2];
    }


    cout<<"Enter Number of Values in Matrix 2:";
    cin>>n;
    int arr2[n+1][3];
    cout<<"Enter Number of Rows of Matrix 2:";
    cin>>arr2[0][0];
    cout<<"Enter Number of Columns of Matrix 2:";
    cin>>arr2[0][1];
    arr2[0][2]=n;

    cout<<"Enter Sparse Matrix 2"<<endl;
    for(int i=0;i<arr2[0][2];++i)
    {
        cin>>arr2[i][0]>>arr2[i][1]>>arr2[i][2];
    }

    int add[arr1[0][2]+arr2[0][2]+1][3];
    add[0][0]=arr1[0][0];
    add[0][1]=arr1[0][1];
    int i=1,j=1,k=1;;
    while(i<arr1[0][2] && j<arr2[0][2])
    {
        if(arr1[i][0]<arr2[j][0])
        {
            for(int p=0;p<3;++p)
            {
                add[k][p]=arr1[i][p];
            }
            k++;
            i++;
        }
        else if(arr1[i][0]==arr2[j][0])
        {
            if(arr1[i][1]<arr2[j][1])
            {
                for(int p=0;p<3;++p)
                {
                    add[k][p]=arr1[i][p];
                }
                k++;
                i++;
            }
            else if(arr1[i][1]==arr2[j][1])
            {
                for(int p=0;p<3;++p)
                {
                    add[k][p]=arr2[j][p]+arr1[i][p];
                }
                k++;
                j++;
                i++;
            }
            else
            {
                for(int p=0;p<3;++p)
                {
                    add[k][p]=arr2[j][p];
                }
                k++;
                j++;
            }
        }
        else
        {
            for(int p=0;p<3;++p)
            {
                add[k][p]=arr2[j][p];
            }
            k++;
            j++;
        }
    }
     while(j<arr2[0][2])
    {
        for(int p=0;p<3;++p)
        {
            add[k][p]=arr2[j][p];
        }
        k++;
        j++;
    }
     while(i<arr1[0][2])
    {
        for(int p=0;p<3;++p)
        {
            add[k][p]=arr1[i][p];
        }
        k++;
        i++;
    }
    add[0][2]=k-1;
    cout<<endl;
    cout<<"Final Matrix Is"<<endl;
    for(int p=0;p<add[0][2];++p)
    {
        cout<<add[p][0]<<" "<<add[p][1]<<" "<<add[p][2]<<endl;
    }


}
