#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void singleanalysis(){
float a,b,c,d,As,Mu,fu,fy,t,fs;
printf("please enter beam depth(mm) \n");
scanf(" %f",&t);
printf("please enter beam width(mm) \n");
scanf(" %f",&b);
printf("please enter steel area(mm^2) \n");
scanf(" %f",&As);
printf("please enter steel yield stress(N/mm^2) \n");
scanf(" %f",&fy);
printf("please enter concrete yield stress(N/mm^2) \n");
scanf(" %f",&fu);
a=(As*1.5*3*fy)/(1.15*2*b*fu);
c=a/0.8;d=t-50;
if(c>d*690/(690+fy)){
printf("_______________\n_______________\n\n Analysis results: \n \n");
printf("warning:tension steel does not yield \n");
printf("warning:section is over reinforced \n");
fs=600*((0.8*d/((-600*As+ sqrt((600*As*600*As)-(4*-480.0*d*As*2*b*fu/(3*1.5))))/(2*2*b*fu/(3*1.5))))-1);
Mu=fs*As*(d-((-600*As+ sqrt((600*As*600*As)-(4*-480.0*d*As*2*b*fu/(3*1.5))))/(2*2*b*fu/(3*1.5)))/2);
printf("internal moment capacity= %f (N.mm) \n",Mu);
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

printf("_______________\n_______________\n\n Analysis results: \n \n");
printf("tension steel yields \n");
printf("section is under reinforced \n");
Mu=fy*As/1.15*(d-a/2);
printf("internal moment capacity= %f \n",Mu);
printf("_______________\n_______________\n\n \n \n");
}
}
void singledesign(){
float a,b,c,d,As,Mu,fu,fy,t,fs;char flag1,flag2;
printf("please enter Moment capacity(N.mm) \n");
scanf(" %f",&Mu);
printf("please enter steel yield stress(N/mm^2) \n");
scanf(" %f",&fy);
printf("please enter concrete yield stress(N/mm^2) \n");
scanf(" %f",&fu);
printf("please enter beam width(mm) \n");
scanf(" %f",&b);
printf("Is there any predetermined properties \n (As or beam depth) \n if yes enter (1) if no enter (0) \n");
scanf(" %c",&flag1);
if (flag1 ==1){
printf("for As enter 1 for beam depth enter 2");
scanf("%c ", &flag2);
if (flag2 ==1){
printf("please enter reinforcement steel area (mm^2)");
scanf("%f", &As);
a=3*1.5*As*fy/(2*1.15*b*fu);d=1.15*Mu/(As*fy)+a/2;
printf("_______________\n_______________\n\n design results: \n \n");
printf("As= %f ",As);
printf(" beam depth= %f",t);
printf("beam width= %f",b);
printf("_______________\n_______________\n\n \n \n");
}
/*else if (flag2 ==2){
printf("please enter beam depth (mm)");
scanf("%f", &t);
d=t-50;
As=(-As*fy/1.15 +sqrt((As*fy/1.15)^2-4*-3*1.5*(fy^2)*-Mu/(2*b*fu*1.15^2)))/(2*-3*1.5*(fy^2)/(2*b*fu*1.15^2));
printf("_______________\n_______________\n\n design results: \n \n");
printf("As= %f , beam depth= %f, beam width= %f",As,t,b;
printf("_______________\n_______________\n\n \n \n");
}*/}
else if (flag1 ==0){
As=0.11*sqrt(Mu*b/fy);a=3*1.5*As*fy/(2*1.15*b*fu);d=1.15*Mu/(As*fy)+a/2;t=d+50;
printf("_______________\n_______________\n\n design results: \n \n");
printf("As= %f ",As);
printf(" beam depth= %f",t);
printf("beam width= %f",b);
printf("_______________\n_______________\n\n \n \n");
}
}

void main{
singledesign();
}
