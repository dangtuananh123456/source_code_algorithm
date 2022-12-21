#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//max trong ph?n t? c?a m?ng
int maxarray(int a[],int n){
	int max=a[0];
	for(int i=0;i<n;i++){
		if(max<a[i]) max=a[i];
	}
	return max;
}

//counting sort 
void countingsort(int a[],int n){
	int b[100]={0};
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	for(int i=0;i<=maxarray(a,n);i++){
		if(b[i]!=0) {
			for(int j=1;j<=b[i];j++){
				cout<<i<<"  ";
			}
		}
	}
}

int main()
{
	int a[MAX],n;
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap  gia tri tung phan tu cua mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	countingsort(a,n);
	return 0;
}