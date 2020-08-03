#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void singleanalysis(){
 float a,b,c,d,As,Mu,fu,fy,t;
printf("please enter beam depth(mm) \n");
scanf(" %f",&t);
printf("please enter steel area(mm^2) \n");
scanf(" %f",&As);
printf("please enter beam width(mm) \n");
scanf(" %f",&b);
printf("please enter steel yield stress \n");
scanf(" %f",&fy);
printf("please enter concrete yield stress \n");
scanf(" %f",&fu);
a=(As*1.5*3*fy)/(1.15*2*b*fu);
c=a/0.8;
d=t-50;
if(c>d*690/(690+fy)){
printf("_______________\n_______________\n\n Analysis result: \n \n");
printf("warning:tension steel does not yield \n");
printf("warning:section is over reinforced \n");
float  q,w,e,fs,st,p,root;
q=2*b*fu/(3*1.5);
w=600*As;
e=-480.0*d*As;
p=(w*w)-(4*q*e);
root=sqrt(p);
st=((-w+ root)/(2*q));
fs=600*((0.8*d/st)-1);
Mu=fs*As*(d-st/2);
printf("internal moment capacity= %f \n",Mu);
printf("_______________\n_______________\n\n \n \n");
}
else if((c<d*690/(690+fy))&&(c>d*460/(690+fy))){
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
