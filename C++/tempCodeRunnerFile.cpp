#include <iostream>
using namespace std;

int main(){
	int x = 10, y = 20;
	int* ptr = &x;
	int &ref = y;
	*ptr++;
	ref++;
	cout << x << " "<< y;
}