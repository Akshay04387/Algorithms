//counting sort
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(int *a,int N){
	int m=0;
	for(int i=0;i<N;i++){
		m=max(m,a[i]);
	}
	int arr[m+1],j=0;
	for(int i=0;i<=m;i++){
		arr[i]=0;
	}
	for(int i=0;i<N;i++){
		arr[a[i]]++;
	}
	j=0;
	for(int i=0;i<=m;i++){
		int temp=arr[i];
		while(temp--){
			a[j]=i;
			j++;
		}
	}
}

int main(){
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	counting_sort(a,N);
	for(int i=0;i<N;i++)
		cout<<a[i];
}