CFLAGS= -fPIC -I. -I/usr/share/R/include -I/usr/local/lib/R/site-library/Rcpp/include -I/usr/local/lib/R/site-library/RInside/include/ -I$(ROOTSYS)/include
LDFLAGS= -shared -L/usr/lib/R/lib -L/usr/local/lib/R/site-library/RInside/lib/ -L$(ROOTSYS)/lib -lR -lRInside -lCore -lCint -lMatrix


all:cint libRInterface.so

libRInterface.so:TRInterface.cxx TRObjectProxy.cxx  TRObjectProxy.h TRInterface.h TRCint.cxx
	$(CXX) $(CFLAGS) TRInterface.cxx TRObjectProxy.cxx TRCint.cxx -o $@ $(LDFLAGS)


cint:
	rootcint -f TRCint.cxx -c $(CFLAGS) TRObjectProxy.h TRInterface.h LinkDef.h

run:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/R/site-library/RInside/lib/ root -l -q test.C
fit:
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/R/site-library/RInside/lib/ root -l -q CurveFit.C
clean:
	rm -f *~ libRInterface.so *Cint*
