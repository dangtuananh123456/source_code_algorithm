#include<bits/stdc++.h>
using namespace std;
#define MAX 100
//s?p x?p n?i b?t bubble sort 
void bubblesort(int a[],int n)
{
	int i=n;
	while(i>=1){
		for(int j=0;j<i-1;j++)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
		i--;
	}
}

int main()
{
	int a[MAX],n;
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap gia tri tung phan tu cua mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	bubblesort(a,n);
	cout<<"mang sau khi duoc sap sep theo bubble sort :\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}