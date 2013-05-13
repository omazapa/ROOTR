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
#ifndef __TRObjectProxy_H__
#define __TRObjectProxy_H__
#include<Rtypes.h>
#include<TObject.h>
#include<TString.h>
#include<string>
#include<TVectorT.h>
#include<TMatrixT.h>
#include<TArrayD.h>
#include<TArrayF.h>
#include<TArrayI.h>
#ifndef __CINT__
#include <RInside.h>
#include <Rcpp.h>
#include<string>
#else
class RInside;
class RInside::Proxy;
namespace Rcpp
{
 class RObject;
 class NumericMatrix;
}
//internal R objects (at R api) Rinternals.h 
typedef struct SEXPREC *SEXP;
#endif
#include<TObject.h>
namespace ROOT
{
  namespace R{
        class TRObjectProxy:public TObject {
	private:
	    Rcpp::RObject x;
	public:
	    TRObjectProxy(){};
	    TRObjectProxy(SEXP xx);

	    TString toString();
	    template<class Type> TVectorT<Type> toVector();
	    template<class TypeClass,class TypeData> TypeClass   toArray();
	    template<class Type> TMatrixT<Type>   toMatrix();
	    template <typename T> operator T() {
                      return ::Rcpp::as<T>(x);
	    }
         ClassDef(TRObjectProxy, 0) // 
	};

  }
#ifndef __CINT__
template<class Type> TVectorT<Type> ROOT::R::TRObjectProxy::toVector()
{
  std::vector<Type> vec=::Rcpp::as<std::vector<Type> >(x);
  return TVectorT<Type>(vec.size(),vec.data());
}

template<class TypeClass,class TypeData> TypeClass   ROOT::R::TRObjectProxy::toArray()
{
  std::vector<TypeData> vec=::Rcpp::as<std::vector<TypeData> >(x);
  return TypeClass(vec.size(),vec.data());
}

template<class Type> TMatrixT<Type>   ROOT::R::TRObjectProxy::toMatrix()
{
  Rcpp::NumericMatrix mat=::Rcpp::as<Rcpp::NumericMatrix>(x);
  return TMatrixT<Type>(mat.nrow(),mat.ncol(),mat.begin(),"F");
}



#endif
  
}


#endif