#include <iostream>
#include <string>
#include <cstdio>
#include "stdarg.h"
#include <math.h>
#include <cstring>
#include <fstream>
#include "matrix.h"
using namespace std;
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
		  case ones :
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
            ////string constructor  ----------------->
CMatrix :: CMatrix (string s){
	   int rows = 0;
	   char* content;
	char* seperators = " [];";
	for(int i = 0,l =s.length(); i < l ; i++)
	{
	   if (s[i] == ';')
	       rows++;
	}
	this->rowsNumbers = rows ;
	matrix = new double* [rowsNumbers];
	  string x = s.substr(5,s.length());
	  int coloums = 0 ;
	for(int i = 0,l=x.find(';') ; i < l ; i++)
	{
	  if (x[i] != ' ')
		  coloums++;
	}
	this->coloumnsNumbers = coloums ;
    char* buffer = new char [x.length()+1];
	strcpy(buffer,x.c_str());
    char* token = strtok_s(buffer , seperators , &content);
	  int k = 0 , i = 0;
	  matrix[i] = new double [coloumnsNumbers];
	while(token){

		if (k == coloums)
		{  
		  i++;
		matrix[i] = new double [coloumnsNumbers];
		k = 0;
		}
	  double item = atof(token);
	  matrix[i][k] = item ;
	  k++;
	  token = strtok_s(NULL,seperators,&content);
	
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
			char buffer [1000] ;
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
      //Multiplacation
CMatrix CMatrix :: operator* (CMatrix &x)
	{
		if(coloumnsNumbers==x.rowsNumbers )
			{
				CMatrix m(rowsNumbers,x.coloumnsNumbers,0,0);

				for (int rows=0;rows<rowsNumbers;rows++)
					{
						for (int cols=0;cols<x.coloumnsNumbers;cols++)
							{
								double sum=0;
								for (int i=0;i<coloumnsNumbers;i++)
									{
										sum+= this->matrix[rows][i]*x.matrix[i][cols];
									}
								m.matrix[rows][cols]=sum;
							}
					}
				return m;
				m=*this;
			}
		else
			{
				cout<<"Multiplication is invalied edit your matrix size, this is your matrix : "<<endl;
				return x;
			}
	}
          // Minus operator
CMatrix CMatrix::operator - (CMatrix& m)
	{	
      if(rowsNumbers!=m.rowsNumbers||coloumnsNumbers!=m.coloumnsNumbers)
	  {
			cout<<"Invalid matrix dimension please fix it"<<endl;
			return m;
	  }
        CMatrix r(rowsNumbers,coloumnsNumbers,0,0);
        for(int iR=0;iR<r.rowsNumbers;iR++)
            for(int iC=0;iC<r.coloumnsNumbers;iC++)
              {
                r.matrix[iR][iC] = matrix[iR][iC]- m.matrix[iR][iC];
              }
	return r;
	r=*this;
	}
        // plus operator
CMatrix CMatrix::operator +(CMatrix& m)
	{	
      if(rowsNumbers!=m.rowsNumbers||coloumnsNumbers!=m.coloumnsNumbers)
	  {
			cout<<"Invalid matrix dimension please fix it"<<endl;
			return m;
	  }
        CMatrix r(rowsNumbers,coloumnsNumbers,0,0);
        for(int iR=0;iR<r.rowsNumbers;iR++)
            for(int iC=0;iC<r.coloumnsNumbers;iC++)
              {
                r.matrix[iR][iC] = matrix[iR][iC]+ m.matrix[iR][iC];
              }
	return r;
	r=*this;
	}
        //Transpose function
CMatrix CMatrix::getTranspose()
	{
		CMatrix r(coloumnsNumbers,rowsNumbers,0,0);
		for(int iR=0;iR<rowsNumbers;iR++)
		{
			for(int iC=0;iC<coloumnsNumbers;iC++)
			{
				r.matrix[iC][iR]=matrix[iR][iC];
			}
		}
		return r;

	}
void readfile (const char* m){
     ifstream matrixfile ;
	 matrixfile.open(m);
	 string s ;
	 getline(matrixfile,s);
     CMatrix A (s);
	 cout << "--------------------->"<<endl;
	 cout << A << endl;
	 getline(matrixfile,s);
     CMatrix B (s);
	 cout << "--------------------->"<<endl;
	 cout << B << endl;
	 matrixfile.close();
 }
ostream& operator << (ostream& out , CMatrix& m){
 
	 out << m.getstring();
 return out ;
 
 }
