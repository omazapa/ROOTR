void test()
{
gSystem->Load("libRInterface.so");
TArrayD v(3);
v[0]=0;
v[1]=1;
v[2]=2;
ROOT::R::TRInterface r(0,0,true,true);
r.assign(v,"v");
r.parseEvalQ("cat(v)");
r.parseEvalQ("summary(v)");
r.parseEvalQ("version");
}
