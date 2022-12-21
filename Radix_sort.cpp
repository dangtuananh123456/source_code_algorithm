#include<bits/stdc++.h>
using namespace std;
int a[101], n;
vector<int> tem[10];

void radix_sort_decimal(){
	int x = *max_element(a, a + n);
	int y = log10(x) + 1;
	for(int i = 1; i <= y; i++){
		for(int k = 0; k <= 9; k++){
			tem[k].clear();
		}
		for(int j = 0; j < n;  j++){
			int var = (a[j]%((int)(pow((double)10, (double)i))))/(int)(pow((double)10, (double)(i - 1)));
			tem[var].push_back(a[j]);
		}
		int variable = 0;
		
		//sao chep lai du lieu tu tem --> a
		for(int k = 0; k <= 9; k++){
			for(auto item : tem[k]){
				a[variable] = item;
				variable++;
			}
		}
	}
}

int log_2(int x){
	int i = 0;
	while(pow(2, i) <=  x){
		i++;
	}
	return i + 1;
}

//lay bit thu n cua x
int get_bit_n(int n, int x){
	int i = 1;
	int ans;
	while(i <= n){
		ans = x%2;
		x = x/2;
		i++;
	}
	return ans;
}

void radix_sort_binary(){
	int x = *max_element(a, a + n);
	vector<int> vec(n);
	int max = log_2(x);
	int i = 1;
	while(i <= max){
		vec.clear();
		for(int j = 0; j < n; j++){
			int bit = get_bit_n(i, a[j]);
			if(bit == 1) continue;
			vec.push_back(a[j]);
			a[j] = 0;
		}
		for(int j = 0; j < n; j++){
			if(a[j] != 0){
				vec.push_back(a[j]);
			}
		}
		for(int j = 0; j < n ;j++){
			a[j] = vec[j];
		}
		i++;
	}	
}