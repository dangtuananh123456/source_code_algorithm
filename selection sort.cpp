#include<bits/stdc++.h>
using namespace std;
#define MAX 100

// selection sort
void selectionsort(int a[],int n)
{
	int min;
	for(int i=0 ; i<n-1;i++){
		min=i;
		for (int j=i+1;j<n;j++){
			if(a[i]>a[j]) min=j;
		}
		swap(a[i],a[min]);
	}
}

int main()
{
	int n,a[MAX];
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap gia tri phan tu cua mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]="; cin>>a[i];
	}
	cout<<endl<<"cout mang sau khi sap xep theo selectionsort: \n";
	selectionsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}