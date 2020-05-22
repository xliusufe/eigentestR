//#include "cfunct.h"
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <iostream>
#include <R.h>
#include <Rinternals.h> 
#include <R_ext/Rdynload.h>

using namespace Eigen;

extern "C"{
Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, int d)
{
  Eigen::MatrixXd M = Eigen::MatrixXd::Constant(d,d,2);  
  M = (M + Data)*50; 
  return M;
}


SEXP ExportsMatrixPlus(SEXP d0){
	int i,j,*d_ = INTEGER(d0);
	Eigen::MatrixXd M_, M1_;	
	int d = d_[0];	
	double *M;
	SEXP rM, list, list_names;
	M1_ = Eigen::MatrixXd::Identity(d, d);		
	M_ = _MatrixPlus_(M1_,d);
	// Outcome
	PROTECT(rM = allocVector(REALSXP, d*d));
	M = REAL(rM);
	for(i=0;i<d;i++) for(j=0;j<d;j++)	M[i*d+j] = M_(i,j);
	
	char *names[2] = {"M","d"};
	PROTECT(list_names = allocVector(STRSXP, 1));
	SET_STRING_ELT(list_names, 0,  mkChar(names[0]));
	PROTECT(list = allocVector(VECSXP, 1)); 
	SET_VECTOR_ELT(list, 0, rM);
	setAttrib(list, R_NamesSymbol, list_names); 
	
	UNPROTECT(3); 
	return list;	
}


static const R_CallMethodDef CallEntries[] = {
    {"ExportsMatrixPlus", (DL_FUNC) &ExportsMatrixPlus, 1},
    {NULL, NULL, 0}
};

void R_init_eigentest(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

}