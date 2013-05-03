void test()
{
gSystem->Load("libRInterface.so");
TArrayD v(3);
v[0]=0;
v[1]=1;
v[2]=2;
ROOT::R::TRInterface r(0,0,true,true);
r.assign(v,"v");
r.assign(TString("ROOTR"),"str");
r.parseEvalQ("cat(v)");
r.parseEvalQ("summary(v)");
r.parseEvalQ("version");

ROOT::R::TRObjectProxy robj=r.parseEval("str");
TString str=robj.toString();

cout<<"---\n";
cout<<str.Data()<<endl;
cout<<"---\n";
}
