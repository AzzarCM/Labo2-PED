#include <iostream>

using namespace std;

int merge(int a[],int p, int r, int q){
	int n1 = r - p + 1;
	int n2 = q - r;
	
	int la[n1+1];
	int ra[n2+1];
	
	for(int i = 0 ; i < n1 ; i++){
		la[i] = a[p+i];
	}
	
	for(int j = 0 ; j < n2 ; j++){
		ra[j] = a[r+j+1];
	}
	
	la[n1] = 10000000;
	ra[n2] = 10000000;
	
	int i = 0;
	int j = 0;
	
	for(int k = p; k < q+1 ; k++ ){
		if(la[i] <= ra[j]){
			a[k] = la[i];
			i++;
		}else{
			a[k] = ra[j];
			j++;
		}
	}
	
}

int mergeSort(int a[],int p, int q){
	
	int r;
	
	if(p < q ){
		r = (p+q)/2;
		//cout<<"r: "<<r<<" ";
	
		mergeSort(a,p,r);
		mergeSort(a,r+1,q);
		merge(a,p,r,q);
		//cout<<"\n";
	}
}

int main(){
	
	int n = 6; //cambiar tamanio del array
	
	int a[] = {34,5,1,78,4,3}; //array a ordenar
	
	mergeSort(a,0,n-1);
	
	for(int i = 0; i < n ; i++){
		cout<<a[i]<<" ";
	}
}
