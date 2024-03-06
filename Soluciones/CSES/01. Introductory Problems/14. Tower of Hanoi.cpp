#include <iostream>
 
using namespace std;
 
void hanoi(int n, int a, int b, int c){
	if(n == 0) return;
	hanoi(n - 1, a, c, b);
	cout<<a<<" "<<c<<"\n";
	hanoi(n - 1, b, a, c);
}
 
int main(){
	int n;
	cin>>n;
	
	cout<<((1<<n) - 1)<<"\n";	
	hanoi(n, 1, 2, 3);
	
	return 0;
}
