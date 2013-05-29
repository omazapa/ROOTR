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
#ifndef __TRInterface_H__
#define __TRInterface_H__
#include<Rtypes.h>
#include<TObject.h>
#include<string>
#include<TArrayD.h>
#include<TVectorD.h>
#include<TMatrixD.h>
#include<TRObjectProxy.h>
#ifndef __CINT__
#include <RInside.h>
#include <Rcpp.h>
#include<string>
#else
class RInside;
namespace Rcpp
{
 class InternalFunction;
}
#endif
#include<TObject.h>
namespace ROOT
{
  namespace R{
    class TRInterface:public RInside,public TObject
    {
    public:
      TRInterface(const int argc, const char *const argv[], const bool loadRcpp=false, const bool verbose=true, const bool interactive=false);
      ~TRInterface(){}
      void parseEvalQ(TString code);
      TRObjectProxy parseEval(const std::string &line); // parse line, return TRObjectProxy
      template<typename T >void assign(const T &obj,const std::string & name);
      
      //utility methods for plots
      inline void x11(){ parseEvalQ("x11()");}
      void plot(TString code);
      void lines(TString code);
      void text(TString code);
      
      ClassDef(TRInterface, 0) // 
    };
    template<> void TRInterface::assign(const Double_t &value,const std::string & name);
    template<> void TRInterface::assign(const Int_t &value,const std::string & name);
    //Objects Assignation
    template<> void TRInterface::assign(const TArrayD &obj,const std::string & name);
    template<> void TRInterface::assign(const TVectorD &obj,const std::string & name);
    template<> void TRInterface::assign(const TMatrixD &obj,const std::string & name);
    template<> void TRInterface::assign(const TString &obj,const std::string & name);

  }
}

#ifndef __CINT__

#endif

#endif