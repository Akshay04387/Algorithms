
#include <iostream>


using namespace std;

void merge_sort(int *a,int start,int mid,int end){
    int arr[end-start+1];
    int i,j,k,p;
    k=0;
    i=start;j=mid+1;
    for(p=start;p<=end;p++){
        if(i==mid+1)
            arr[k++]=a[j++];
        else if(j==end+1)
            arr[k++]=a[i++];
        else if(a[i]<a[j])
            arr[k++]=a[i++];
        else if(a[i]>a[j])
            arr[k++]=a[j++];
    }
    for(i=0;i<k;i++){
        a[start+i]=arr[i];
    }
}

void divider_sort(int *a,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        divider_sort(a,start,mid);
        divider_sort(a,mid+1,end);
        merge_sort(a,start,mid,end);
    }
}

int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    divider_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<"-->";
    
    return 0;
}
