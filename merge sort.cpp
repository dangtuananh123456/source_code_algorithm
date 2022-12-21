#include<bits/stdc++.h>
using namespace std;
#define MAX 100

//trộn hai dãy con: dãy 1[l;m] and dãy 2 [m+1;r]
void merge(int a[],int l,int m,int r){
	vector<int> x(a+l,a+m+1);
	vector<int > y(a+m+1,a+r+1);
	int i=0,j=0;
	while(i<x.size() && j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];l++;i++;
		}
		else{
			a[l]=y[j];l++;j++;
		}
	}
	while(i<x.size()){
		a[l]=x[i];
		i++;l++;
	}
	while(j<y.size()){
		a[l]=y[j];
		j++;l++;
	}
}

//thuật toán merge sort 
void mergesort(int a[],int l,int r){
	if(l>=r) return;
	int m=(l+r)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);
}
//------------------------------------------

// merge sort theo phong cach pointer
 //step merge two matrix
void merge1(int a[],int l, int m,int r){
	int* point = new int[r - l + 1];
	for(int i = 0; i < r - l + 1; i ++){
		*(point + i) = a[l + i];
	}
	int i = 0, j = m - l + 1;
	int k = l;
	while(i < m - l + 1 && j < r - l + 1){
		if(*(point + i) < *(point + j)){
			a[k] = *(point + i);
			k++; i++;
		}
		else{
			a[k] = *(point + j);
			k++; j++;
		}
	}
	if(i <= m - l){
		while(i <= m - l){
			a[k] = *(point + i);
			i++; k++;
		}
	}
	if(j <= r - l){
		while(j <= r - l){
			a[k] = *(point + j);
			j++; k++;
		}
	}
	delete point;
}
//merge sort algorithm
void mergesort1(int a[], int l, int r){
	if(l >= r){
		return;
	}
	int m = (l + r)/2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
}
//  ------------------------------
int main(){
	int a[MAX],n;
	cout<<"nhap so luong phan tu cua mang: "; cin>>n;
	cout<<"nhap gia tri tung phan tu cua mang:\n";
	srand((int)time(0));
	for(int i=0;i<n;i++){
		a[i]=rand()% 1000+1;
	}
	mergesort(a,0,n-1);
	cout<<"mang sau khi duoc sap xep theo mergesort la:\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}