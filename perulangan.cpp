#include <iostream>
using namespace std;

int main(){
	int h, i, j, k;
	cout << "Program bintang" << endl;
	cout << "Masukan Tinggi bintang  ";
	cin >> h;
	
	for(i=1; i <= h; i++){
		for(j=h; j >= h-i; j--){
			cout << " ";
			}
		for(k=h; k>=(2*i)-1; k--){
			cout << "*";
			}
		cout << endl;
		}
	}
