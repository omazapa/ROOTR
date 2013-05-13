/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<TRInterface.h>
#include<vector>
using namespace ROOT::R;
ClassImp(TRInterface)
TRInterface::TRInterface(const int argc, const char *const argv[], const bool loadRcpp, const bool verbose, const bool interactive):RInside(argc,argv,loadRcpp,verbose,interactive)
{
}

void TRInterface::parseEvalQ(std::string code)
{
  RInside::parseEvalQ(code);
}

TRObjectProxy TRInterface::parseEval(const std::string &line)
{
  return TRObjectProxy((SEXP)RInside::parseEval(line));
}

template<> void TRInterface::assign(const TArrayD &obj,const std::string & name)
{
  std::vector<double> vec(obj.GetArray(),obj.GetArray()+obj.GetSize());
  RInside::assign(vec,name);
}

template<> void TRInterface::assign(const TString &obj,const std::string & name)
{
  std::string str(obj.Data());
  RInside::assign(str,name);
}

template<> void TRInterface::assign(const TMatrixD &obj,const std::string & name)
{
  Int_t rows=obj.GetNrows();
  Int_t cols=obj.GetNcols();
  Double_t *data=new Double_t[rows*cols];
//   obj.GetMatrix2Array(data,"F"); //ROOT have a bug here
//   TMatrixD m(obj.GetNrows(),obj.GetNcols(),data,"F");
//   m.Print();
  for(int i=0;i<rows;i++)
  {  
      for(int j=0;j<cols;j++) data[i+j*rows]=obj[i][j];
  }
  Rcpp::NumericMatrix mat(obj.GetNrows(),obj.GetNcols(),data);
  RInside::assign(mat,name);
}