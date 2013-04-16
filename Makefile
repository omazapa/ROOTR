CFLAGS= -fPIC -I. -I/usr/share/R/include -I/usr/lib/R/site-library/Rcpp/include -I/usr/local/lib/R/site-library/RInside/include/ -I$(ROOTSYS)/include
LDFLAGS= -shared -L/usr/lib/R/lib -L/usr/local/lib/R/site-library/RInside/lib/ -L$(ROOTSYS)/lib -lR -lRInside -lCore -lCint 


all:cint libTRInterface.so

libTRInterface.so:TRInterface.cxx TRInterface.h TRInterfaceCint.cxx
	$(CXX) $(CFLAGS) TRInterface.cxx TRInterfaceCint.cxx -o $@ $(LDFLAGS)
	

cint:
	rootcint -f TRInterfaceCint.cxx -c $(CFLAGS) TRInterface.h LinkDef.h

run:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/R/site-library/RInside/lib/ root -l -q test.C
