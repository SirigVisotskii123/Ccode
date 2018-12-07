/*the solution of nonlinear equations*/
#include<stdio.h>
#include<math.h>
#define E 2.71828
double f(double x);
 main ()
{
int a,b,m,i,count1,count2;
double x1,y1,x2,y2,z,de,e=0.0001,*xj,h,*yj;
printf("Vvedite promezhutok[a,b]...\n");
scanf("%d %d",&a,&b);
printf("Vvedite kolichestvo promezhutkov v zadannom intervale(m)...\n");
scanf("%d",&m);
h=(double)(b-a)/m;
xj=new double[m+1];
yj=new double[m+1];
for(i=0;i<=m;i++) {xj[i]=a+i*h;yj[i]=((pow(E,xj[i]))/(pow(xj[i],3))-(pow(sin(xj[i]),3))-2);printf("%d)%lf - %lf\n",i+1,xj[i],yj[i]);}
delete [] yj;
m1:printf("Vvedite nomer priblizheniya iz vidannih[x0,x1]...\n");
scanf("%d %d",&count1,&count2);
x1=xj[count1-1];
x2=xj[count2-1];
y1=f(x1);
y2=f(x2);
de=e+1;
for(i=0;de>e;i++)
{
z=x2-((y2*(x2-x1))/(y2-y1));
de=fabs(x2-z);
printf("%d]%lf\n",i+1,z);
x1=x2;
x2=z;
y1=y2;
y2=f(z);
}
printf("\n%d - colichestvo iteracii|%lf - koren|%lf - znachenie funkcii... \n",i,z,fabs(f(z)));
if(de<=e) goto m1;
delete [] xj;
}
double f(double x)
{
return(((pow(E,x)/pow(x,3))-pow(sin(x),3)-2));
}
