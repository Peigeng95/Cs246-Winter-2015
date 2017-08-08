#include <iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	int a[10] = {0,0,0,0,0,0,0,0,0,0};//array of coins
	int b[10] = {0,0,0,0,0,0,0,0,0,0};//array of how many coins
	for(int k=0; k<x; k++){
		cin >> a[k];//read in value of coins
	}
	int total;//total amount
	cin >> total;
	int t; // temp value
	for(int j=0;j<10;j++){//put the arry of coins from greatest to smallest
		for(int i=0;i<10-1-j;i++){
			if(a[i]<a[i+1]){
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}  
	}
	for(int p=0; p<x; p++){
		if(total/a[p] != 0){//total is great than a[p]
		//cout << a[p] << endl;
		//cout << total <<endl;
		b[p] = total/a[p];
		//cout << b[p] <<endl;
		total = total%a[p];
		//cout << total << endl;
		}
	}
	if(total != 0){
		cout << "Impossible" <<endl;
	}
	if(total == 0){// case: possible
		for(int m=0; m<10; m++){
			if(b[m] != 0){
			cout << b[m];
			cout <<" x ";
			cout << a[m] <<endl;
			}
		}
	}
}
