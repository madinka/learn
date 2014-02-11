#include "second.h"

// C

// C++
#include <iostream>

// Third party
#include <gtest/gtest.h>

// сумма элементов, стоящих справа самого 
//   последнего отрицательного элемента

using namespace std;

TEST(Second, None){
	int n = 0;
	cout <<"Vvedite kolichestvo elementov"; 
  //cin>>n;
	int i = 0;
  int ineg = 0;
	float sum = 0;
  // выделение памяти под массив для хранения n элементов
  float *a = new float [n]; 
	
  /*
  cout << "Vvedite elementi massiva";

for (i=0; i<n; i++) 
cin >> a[i];

for (i = 0; i<n; i++) 
cout << a[i] <<' ';

  // записываются номера всех отрицательных элементов, 
  // после выхода из цмкла оставется номер самого последнего
  for (i=0; i < n; i++) { 
    if (a[i]<0) 
      ineg=i;   
  }

  for (sum=0, i=ineg+1; i<n; i++) 
    sum += a[i];

	cout << "Summa " <<sum;
  */
  delete [] a;
}


TEST(Second, Code) {
  for (int i = 0; i < 10; ++i) {
    cout << "Hallo!";
  }
}


