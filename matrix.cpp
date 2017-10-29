#include <iostream>
#include <string>
#include <cstdio>
#include "stdarg.h"
#include <math.h>
#include "matrix.h"
#include <cstring>
using namespace std;
int main (){

  CMatrix a(3,2,1,2);
 cout << "matrix A = " << endl;
 cout << a.getstring() << endl;
 CMatrix b = a;
 cout << "matrix b = " << endl;
 cout << b.getstring() << endl;


system("pause");
return 0 ;
}