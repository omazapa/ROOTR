void test()
{
gSystem->Load("libRInterface.so");
TArrayD v(3);
v[0]=0;
v[1]=1;
v[2]=2;
ROOT::R::TRInterface r(0,0,true,true);
ROOT::R::TRObjectProxy robj;

r.assign(v,"v");
r.assign(TString("ROOTR"),"str");
r.parseEvalQ("cat(v)");
r.parseEvalQ("summary(v)");
r.parseEvalQ("v<-2*v");

robj=r.parseEval("str");
TString str=robj.toString();

robj=r.parseEval("v");
TVectorD vout=robj.toVector();
TArrayD aout=robj.toArray();

cout<<"---\n";
cout<<str.Data()<<endl;
cout<<"---\n";
cout<<"["<<vout[0]<<","<<vout[1]<<","<<vout[2]<<"]"<<endl;
cout<<"["<<aout[0]<<","<<aout[1]<<","<<aout[2]<<"]"<<endl;
cout<<"---\n";
}
