/*minimum of function*/
#include<stdio.h>
#include<math.h>
#define E 2.71828183
double func(double x);
double MP2(double x,double h);
void main(void)
{
double h,a,b,m,x,y;
printf("Vvedite protmezhutok(a,b): ");
scanf("%lf %lf",&a,&b);
printf("Vvedite kolichestvo uzlov: ");
scanf("%lf",&m);
h=(b-a)/m;
x=a;
printf("\nx         y\n");
while(x<=b)
{
y=func(x);
printf("%lf  %lf\n",x,y);
x+=h;
}
m1:
printf("Vvedite x i ego okrestnost h: ");
scanf("%lf %lf",&x,&h);
printf("z:%lf f(z):%lf",MP2(x,h),func(MP2(x,h)));
printf("\nY/y chtobi prodolzhit...\n");
if(getchar()=='Y'||getchar()=='y') goto m1;
else printf(".......................................................");
}
double func(double x)
{
return ((pow(E,x)/pow(x,3))-30*cos(x));
}
double MP2(double x,double h)
{
int i;
double *X,*Y,p,q,z1,z2,zm;
X=new double [3];
Y=new double [3];
X[0]=x-h;
X[1]=x;
X[2]=x+h;
for(i=0;i<3;i++) Y[i]=func(X[i]); 
m2:
z1=X[0]-X[2];
z2=X[1]-X[2];
p=((Y[0]-Y[2])*z2-(Y[1]-Y[2])*z1)/(z1*z2*(z1-z2));
q=((Y[0]-Y[2])*pow(z2,2)-(Y[1]-Y[2])*pow(z1,2))/(z1*z2*(z2-z1));
zm=((-1)*q)/(2*p);
X[0]=X[1];
X[1]=X[2];
Y[0]=Y[1];
Y[1]=Y[2];
X[2]+=zm;
Y[2]=func(X[2]);
if(fabs(zm)>=0.001) goto m2;
return(X[2]+zm);
delete [] X;
delete [] Y;
}