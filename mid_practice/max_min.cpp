#include<iostream>
#include<climits>
using namespace std;

pair<int,int>find_minMax(int arr[],int low,int high)
{
    if(low==high)
    {
        return{arr[low],arr[low]};
    }
    else if(high==low+1)
    {
        if(arr[low]<arr[high])
        {
            return{arr[high],arr[low]};
        }
        else
        {
            return {arr[low],arr[high]};
        }
    }
    else
    {
        int mid=(high+low)/2;
        pair<int,int>left=find_minMax(arr,low,mid);
        pair<int,int>right=find_minMax(arr,mid+1,high);

        int finalMax=max(left.first,right.first);
        int finalMin=min(left.second,right.second);
        return {finalMax,finalMin};
    }
}

int main()
{
    cout<<"enter array size-";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter array element:";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    pair<int,int>result=find_minMax(arr,0,n-1);
    cout<<"max value="<<result.first<<endl;
    cout<<"min value="<<result.second<<endl;
}
