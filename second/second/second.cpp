#include <iostream>
using namespace std;
int main(){
	int n;
	cout <<"Vvedite kolichestvo elementov"; cin>>n;
	int i, ineg;
	float sum, *a=new float [n]; // выделение памяти под массив для хранения n элементов
	cout << "Vvedite elementi massiva";
	for (i=0; i<n; i++) cin >> a[i];
	for (i=0; i<n; i++) cout << a[i] <<' ';
	for (i=0; i<n; i++) if (a[i]<0) ineg=i;   // записываются номера всех отрицательных элементов, после выхода из цмкла оставется номер самого последнего
	for (sum=0, i=ineg+1; i<n; i++) sum+=a[i];
	cout << "Summa " <<sum;
	return 0;
}
// сумма элементов, стоящих справа самого последнего отрицательного элемента

