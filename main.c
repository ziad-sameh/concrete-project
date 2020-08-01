#include <stdio.h>
#include <stdlib.h>
float solvingtwoequations(float x,float y,float z,float w){
return 0;
}
void singleanalysis(){
 float a,b,c,d,As,Mu,fu,fy,t;
printf("please enter beam depth(mm) \n");
scanf(" %f", &t);
printf("please enter steel area(mm^2) \n");
scanf(" %f", &As);
printf("please enter beam width(mm) \n");
scanf(" %f", &b);
printf("please enter steel yield stress \n");
scanf(" %f", &fy);
printf("please enter concrete yield stress \n");
scanf(" %f", &fu);
a=(As*1.5*3*fy)/(1.15*2*b*fu);
d=t-50;
if(c/0.8>d*690/(690+fy)){
printf("_______________\n_______________\n\n Analysis result: \n \n");
printf("warning:tension steel does not yield \n");
printf("warning:section is over reinforced \n");
printf("_______________\n_______________\n\n \n \n");
}
else if(c/0.8==d*690/(690+fy)){
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
}
