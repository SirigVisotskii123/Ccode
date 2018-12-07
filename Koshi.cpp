/*solution of differential equations by Cauchy method*/
#include<stdio.h>
#include<math.h>
#define E 2.71828183
void OUT(double x,double *y);
void FPR(double x,double *y,double *F);
double Pogr(double x,double *y);
void main(void)
{
int a,b,n,i,nx=10,np=1,ny=2;
double h,x,y[2],F[2],yp[2],e=0.0001;
printf("Vvedite promezhutok(a,b): ");
scanf("%d %d",&a,&b);
m1:
h=(double)(b-a)/(nx);
printf("\nh=%lf\n",h);
y[0]=2*a;y[1]=pow(E,a);
x=a;
if(np==0) np=nx+1;
printf("x         y1        u1        d1        y2        u2        d2\n");
OUT(x,y);
for(n=0;n<nx;n++)
{
FPR(x,y,F);
x+=h/2;
for(i=0;i<ny;i++)
{
yp[i]=y[i]+(h/2)*F[i];
}
FPR(x,yp,F);
x+=h/2;
for(i=0;i<ny;i++)
{
y[i]=y[i]+h*F[i];
}
if(n%np==0) OUT(x,y); 
}
printf("\n\n");
if(Pogr(x,y)>=e) {nx*=2;np*=2;goto m1;}
}
void OUT(double x,double *y)
{
double u[2];
u[0]=2*x;
u[1]=pow(E,x);
printf("%lf  %lf  %lf  %lf  %lf  %lf  %lf\n",x,y[0],u[0],fabs(u[0]-y[0]),y[1],u[1],fabs(u[1]-y[1]));
}
void FPR(double x,double *y,double *F)
{
F[0]=(y[0]*pow(E,x))/(x*y[1]);
F[1]=2*y[0]+y[1]-4*x;
}
double Pogr(double x,double *y)
{
double u[2];
u[0]=2*x;
u[1]=pow(E,x);
return (fabs(u[1]-y[1]));
}