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
};
    // Default Constructor
CMatrix :: CMatrix (){
	rowsNumbers = 0 ;
	coloumnsNumbers=0;
	matrix=NULL;
}
  // (zero,unit and any initial value) matrix constructor
CMatrix :: CMatrix (int rn , int cn , int initial , double initialvalue ) {

	this->rowsNumbers = rn ;
	this->coloumnsNumbers = cn ;
	if (rn*cn == 0){ matrix = NULL ;return;}
	matrix = new double* [rn];
	for(int i=0;i<rn;i++)
	{
		matrix[i]=new double[cn];
		for(int j=0;j<cn;j++)
		{
	  switch (initial)
	  {
		  case zeros : 
			{
			  matrix[i][j]=0;
			  break;
			 }
		  case ones  :
			  {
			  matrix[i][j]=1;
			  break;
			  }
		  case value :
			  {
			  matrix[i][j] = initialvalue ; 
			  break;
			  }
	  }
		}
}
}
  // copy constructor 
CMatrix :: CMatrix (CMatrix& m)
{
	this->coloumnsNumbers = m.coloumnsNumbers;
	this->rowsNumbers = m.rowsNumbers ;
	matrix = new double*[rowsNumbers] ;
	for (int i = 0 ; i < rowsNumbers ; i++)
	{    
		matrix[i] = new double[coloumnsNumbers];
		for(int j=0;j < coloumnsNumbers;j++)
		{
			this->matrix[i][j]=m.matrix[i][j] ;
		}
	}
}
   // Destructor
CMatrix :: ~CMatrix (){

	if (this->matrix != NULL ) 
	{
		for(int i = 0 ; i < rowsNumbers ; i++)
			delete[] matrix[i];
		delete[] matrix ;
	}
}
           // Print Matrix
string CMatrix :: getstring (){
	string s = "[";
	 for (int i = 0; i < rowsNumbers ; i++)
	 {
		 for(int j = 0; j < coloumnsNumbers ; j++)
		 {
			char buffer [50] ;
			sprintf_s(buffer,"%g",matrix[i][j]);
			s+=buffer;
			if (j != coloumnsNumbers-1) s+=",";
		 }
	   s+=";";
	   if (i!=rowsNumbers-1)s+="\n";
	 
	 }
	 s+="]";

return s ;
} 
		/*main operations:
		everyone in the team should implement his own function here, by using (CMatrix:: your own function{})*/

		
