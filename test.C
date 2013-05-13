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
cout<<"------------------------------\n";
r.parseEvalQ("cat(v)");
cout<<"------------------------------\n";
r.parseEvalQ("summary(v)");
cout<<"------------------------------\n";
r.parseEvalQ("v<-2*v");
cout<<"------------------------------\n";
r.parseEvalQ("M = matrix(c(2.1, 4.2, 3.3, 1.4, 5.5, 7.0),nrow=2,ncol=3)");
cout<<"------------------------------\n";
r.parseEvalQ("cat(M)");
cout<<"------------------------------\n";



robj=r.parseEval("str");
TString str=robj.toString();

robj=r.parseEval("v");
TVectorD vout=robj.toVector();
cout<<"------------------------------\n";
TArrayD aout=robj.toArray();
cout<<"------------------------------\n";
robj=r.parseEval("M");
TMatrixD mat=robj.toMatrix();
cout<<"---\n";
cout<<str.Data()<<endl;
cout<<"---\n";
cout<<"["<<vout[0]<<","<<vout[1]<<","<<vout[2]<<"]"<<endl;
cout<<"["<<aout[0]<<","<<aout[1]<<","<<aout[2]<<"]"<<endl;
cout<<"---\n";
mat.Print();
cout<<"---\n";
}
