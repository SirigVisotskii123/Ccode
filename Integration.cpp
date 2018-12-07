/*integration of a function*/
#include<stdio.h>
#include<math.h>
#define E 2.71828
void main(void)
{
int i,a,b,m;
double eps,h,*xj,*yj,*xi,*yi,q,p,l,o;
printf("Vvedite promezhutok[a,b]..\n");
scanf("%d %d",&a,&b);
xj=new double[21];
yj=new double[21];
for(i=0;i<21;i++)
{
xj[i]=(double)(a+(i)*(b-a)/20.);
yj[i]=(double)(pow(E,xj[i]))/(pow(xj[i],3))-pow(sin(xj[i]),3);
}
printf("\n");
for(eps=0.1;eps>=0.001;eps=eps/10)
{
printf("Dlia eps=%f \n\n",eps);
m=2;
m1:
l=q=p=0;
h=(double)(b-a)/m;
xi=new double[m];
yi=new double[m];
for(i=0;i<m;i++)
{
xi[i]=(double)a+(i)*h;
yi[i]=(double)(pow(E,xi[i]))/(pow(xi[i],3))-pow(sin(xi[i]),3);
for(i=0;i<m;i++)
{
q+=(((pow(E,a+h*i))/(pow(a+h*i,3))-pow(sin(a+h*i),3)+(pow(E,a+h*(i+1)))/(pow(a+h*(i+1),3))-pow(sin(a+h*(i+1)),3))/2.)*h;
p+=(pow(E,(a+((h*i)+h*(i+1))/2.))/pow((a+((h*i)+h*(i+1))/2.),3)-pow(sin((a+((h*i)+h*(i+1))/2.)),3));
}
l=h*p;
printf("m=:%d  |%lf |%lf\n",m,q,l);
}
if(fabs(l-q)>=eps) {m*=2;goto m1;}
else (o=(q+2*l)/3.);
printf("\n%lf\n\n",o);
delete [] xi;
delete [] yi;
}
delete [] xj;
delete [] yj;
}
