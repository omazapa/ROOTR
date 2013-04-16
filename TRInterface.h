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
    class TRInterface:public TObject
    {
    private:
      RInside *R;
    public:
      TRInterface(const int argc, const char *const argv[], const bool loadRcpp=false, const bool verbose=true, const bool interactive=false);
      ~TRInterface(){if(R)delete R;}
      void parseEvalQ(std::string code);
      template<typename T >void assign(const T &obj,const std::string & name);
      
      ClassDef(TRInterface, 1) // 
    };
    template<> void TRInterface::assign(const TArrayD &obj,const std::string & name);
  }
}

#ifndef __CINT__

#endif

#endif