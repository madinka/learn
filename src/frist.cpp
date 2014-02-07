#include <iostream>
using namespace std;
void CntTo(int);
int main(){
	int n;
	CntTo(4);
}
void CntTo(int n){
	if (n>0){
		CntTo(n-1);
		cout<<n<<endl;
	}
}