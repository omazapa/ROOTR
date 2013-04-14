
#ifndef __TRInside_H__
#define __TRInside_H__
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
 class Function; 
}
#endif
#include<TObject.h>
namespace ROOT
{
  namespace R{
    class TRinside:public TObject
    {
    private:
      RInside *R;
    public:
      TRinside(const int argc, const char *const argv[], const bool loadRcpp=false, const bool verbose=false, const bool interactive=false);
      ~TRinside(){if(R)delete R;}
      void parseEvalQ(std::string code);
      template<typename T >void assign(const T &obj,const std::string & name);
      ClassDef(TRinside, 1) // 
    };
    template<> void TRinside::assign(const TArrayD &obj,const std::string & name);
  }
}

#ifndef __CINT__

#endif

#endif