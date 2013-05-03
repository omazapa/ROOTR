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
#include<TArrayD.h>

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
	    TRObjectProxy(SEXP xx);

	    TString toString();  
	    template <typename T> operator T() {
			return ::Rcpp::as<T>(x);
	    }
         ClassDef(TRObjectProxy, 0) // 
	};
	    template <> TRObjectProxy::operator TString();
        
  }
}


#endif