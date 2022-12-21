#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//thuật toán sắp xếp insertion sort
void insertsort(int a[],int n){
	for(int i=1;i<n;i++){
		int tmp=a[i];
		int pos=i-1;
		while(pos>=0 && tmp<a[pos]){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=tmp;
	}
}


int main(){
	int a[MAX],n;
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap gia tri tung phan tu cua mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	insertsort(a,n);
	cout<<"mang sau khi sap xe theo insersort la:\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}