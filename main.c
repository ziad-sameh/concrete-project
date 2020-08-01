#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void singleanalysis(){
 double a,b,c,d,As,Mu,fu,fy,t;
printf("please enter beam depth(mm) \n");
scanf(" %d", &t);
printf("please enter steel area(mm^2) \n");
scanf(" %d", &As);
printf("please enter beam width(mm) \n");
scanf(" %d", &b);
printf("please enter steel yield stress \n");
scanf(" %d", &fy);
printf("please enter concrete yield stress \n");
scanf(" %d", &fu);
a=(As*1.5*3*fy)/(1.15*2*b*fu);
c=a/0.8;
d=t-50;
if(c>d*690/(690+fy)){
printf("_______________\n_______________\n\n Analysis result: \n \n");
printf("warning:tension steel does not yield \n");
printf("warning:section is over reinforced \n");
double q,w,e,fs,st,p,root;
q=2.0*b*fu/(3.0*1.5);w=As;e=-480.0*d*As;
p=(w*w)-(4*q*e);
if(p<0)printf("error");
root=sqrt(p);
printf("%d" ,root);
st=((-w+ root)/(2*q));
printf("%d" ,st);
fs=600*((0.8*d/st)-1);
printf("%d" ,fs);
Mu=fs*As*(d-st/2);
printf("internal moment capacity= %f \n",Mu);
printf("_______________\n_______________\n\n \n \n");
}
else if(c==d*690/(690+fy)){
printf("_______________\n_______________\n\n Analysis result: \n \n");
printf("tension steel yields \n");
printf("warning:section is over reinforced \n");
Mu=fy*As/1.15*(d-a/2);
printf("internal moment capacity= %f \n",Mu);
printf("_______________\n_______________\n\n \n \n");
}
else{

printf("_______________\n_______________\n\n Analysis result: \n \n");
printf("tension steel yields \n");
printf("section is under reinforced \n");
Mu=fy*As/1.15*(d-a/2);
printf("internal moment capacity= %f \n",Mu);
printf("_______________\n_______________\n\n \n \n");
}
}

int main()
{
  singleanalysis();
return 0;}
