CFLAGS= -fPIC -I. -I/usr/share/R/include -I/usr/lib/R/site-library/Rcpp/include -I/usr/local/lib/R/site-library/RInside/include/ -I$(ROOTSYS)/include
LDFLAGS= -shared -L/usr/lib/R/lib -L/usr/local/lib/R/site-library/RInside/lib/ -L$(ROOTSYS)/lib -lR -lRInside -lCore -lCint 



libTRinside.so:TRinside.cxx TRinside.h TRinsideCint.cxx
	$(CXX) $(CFLAGS) TRinside.cxx TRinsideCint.cxx -o $@ $(LDFLAGS)
	

cint:
	rootcint -f TRinsideCint.cxx -c $(CFLAGS) TRinside.h LinkDef.h
