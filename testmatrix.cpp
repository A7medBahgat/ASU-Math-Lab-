#include <iostream>
#include <string>
#include <cstdio>
#include "stdarg.h"
#include <math.h>
#include "matrix.h"
#include <cstring>
using namespace std;
int main (){
	
 CMatrix a(3,3,2,2);
 cout <<"matrix A = "<< endl;
 cout << a << endl;
 CMatrix b (3,2,2,5);
 cout <<"matrix b = "<< endl;
 cout << b << endl;
 CMatrix d (2,1,2,2);
 cout <<"matrix d = "<< endl;
 cout << d << endl;
 CMatrix c=a*b*d;
 cout <<"matrix c = "<< endl;
 cout << c << endl;

	CMatrix e(3,2,2,2);
 cout << "matrix e = " << endl;
 cout << e<< endl;
 CMatrix f=e.getTranspose();
 cout << "matrix f = " << endl;
 cout << f<< endl;
 
 CMatrix aa(3,3,2,5);
 cout << "matrix aa = " << endl;
 cout << aa << endl;
CMatrix bb(3,3,2,4);
 cout << "matrix bb = " << endl;
 cout << bb << endl;
CMatrix g=a+bb+aa;//valid
 cout << "matrix g = " << endl;
 cout << g << endl;
 
 system("pause");
return 0 ;
}