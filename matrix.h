#include <iostream>
#include <string>
#include <cstdio>
#include "stdarg.h"
#include <math.h>
#include <cstring>
using namespace std;
class CMatrix {
  int rowsNumbers , coloumnsNumbers ;
  double** matrix ;
public:
	enum MI {zeros,ones,value};
	CMatrix();
	~CMatrix();
	CMatrix(int rn , int cn , int initial , double initialvalue);
	CMatrix (string s);
	CMatrix (CMatrix& m);
	string getstring ();
	CMatrix operator* (CMatrix &x);
	CMatrix operator - (CMatrix& m);
    CMatrix operator + (CMatrix& m);
	CMatrix getTranspose();
	friend ostream& operator << (ostream& out , CMatrix& m);
	friend void readfile (const char* m);
};