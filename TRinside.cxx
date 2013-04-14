#include<TRinside.h>
#include<vector>
using namespace ROOT::R;
ClassImp(TRinside)
TRinside::TRinside(const int argc, const char *const argv[], const bool loadRcpp, const bool verbose, const bool interactive)
{
  R=new RInside(argc,argv,loadRcpp,verbose,interactive);
}
void TRinside::parseEvalQ(std::string code)
{
  R->parseEvalQ(code);
}



template<> void TRinside::assign(const TArrayD &obj,const std::string & name)
{
  std::vector<double> vec(obj.GetArray(),obj.GetArray()+obj.GetSize());
  R->assign(vec,name);
}
