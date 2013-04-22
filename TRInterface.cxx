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



template<> void TRInterface::assign(const TArrayD &obj,const std::string & name)
{
  std::vector<double> vec(obj.GetArray(),obj.GetArray()+obj.GetSize());
  RInside::assign(vec,name);
}
