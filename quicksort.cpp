//quick sort
#include <iostream>
using namespace std;

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *a,int start,int end){
	int piv = a[start];
	int i=start+1;
	for(int j=start+1;j<=end;j++){
		if(piv>a[j]){
			swap(&a[j],&a[i]);
			i++;
		}
	}
	swap(&a[i-1],&a[start]);
	return (i-1);
}

void quick_sort(int *a,int start,int end){
	if(start<end){
		int piv_index = partition(a,start,end);
		quick_sort(a,start,piv_index-1);
		quick_sort(a,piv_index+1,end); 
	}
}

int main(){

	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	quick_sort(a,0,N-1);
	for(int i=0;i<N;i++)
		cout<<a[i];
}