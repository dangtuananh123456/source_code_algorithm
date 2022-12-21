#include<bits/stdc++.h>
#define MAX 100
using namespace std;

//thao tác tạo ra heapify
void heapify(int a[],int n,int i){
	int left = 2 * i +1;
	int right = 2 * i + 2;
	int largest = i ; 
	if(left < n && a[left] > a[largest]){
		largest = left;
	}
	if(right < n && a[right] > a[largest]){
		largest = right ; 
	}
	if(largest != i){
		swap(a[i] , a[largest]);
		heapify(a, n, largest);
	}
}

// heap sort
void heapsort(int a[],int n){
	//tạo ra max heap
	for(int i=n/2 -1 ; i>=0; i--){
		heapify(a, n, i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

int main(){
	int a[MAX],n;
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap gia tri tung phan tu cua mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	heapsort(a,n);
	cout<<"mang sau khi sap xep la:\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}