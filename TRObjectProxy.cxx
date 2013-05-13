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
#include<TRObjectProxy.h>
#include<vector>
using namespace ROOT::R;
ClassImp(TRObjectProxy)

TRObjectProxy::TRObjectProxy(SEXP xx): x(xx) { }

TString TRObjectProxy::toString()
{
  return TString(::Rcpp::as<std::string>(x));
}

// template<> TArrayD   TRObjectProxy::toArray()
// {
//   std::vector<Double_t> vec=::Rcpp::as<std::vector<Double_t> >(x);
//   return TArrayD(vec.size(),vec.data());
// }
// 
// template<> TArrayF   TRObjectProxy::toArray()
// {
//   std::vector<Float_t> vec=::Rcpp::as<std::vector<Float_t> >(x);
//   return TArrayF(vec.size(),vec.data());
// }
// 
// template<> TArrayI   TRObjectProxy::toArray()
// {
//   std::vector<Int_t> vec=::Rcpp::as<std::vector<Int_t> >(x);
//   return TArrayI(vec.size(),vec.data());
// }
// 

// template <> TRObjectProxy::operator TString()
// {
//   return TString(::Rcpp::as<std::string>(x));
// }