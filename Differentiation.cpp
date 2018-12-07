/*differentiation of functions*/
#include<stdio.h>
#include<math.h>
#define E 2.71828
void main(void)
{
int a,b,i,g,q,k,n;
double m,h,*xi,*yi,*xj,*yj,*proiz,*tochproiz,*proiz2,*tochproiz2;
printf("Zadaite promezhutok[a,b]...\n");
scanf("%d %d",&a,&b);
xj=new double [21];
yj=new double [21];
tochproiz=new double[21];
tochproiz2=new double [21];
for(i=0;i<21;i++)
{
xj[i]=(double)(a+(i*(b-a))/20.);
yj[i]=(double)(pow(E,xj[i]))/(pow(xj[i],3))-pow(sin(xj[i]),3);
tochproiz[i]=(double)(pow(E,xj[i])*pow(xj[i],3)-3*pow(xj[i],2)*pow(E,xj[i]))/pow(xj[i],6)-3*pow(sin(xj[i]),2)*cos(xj[i]);
}
for(i=0;i<21;i++)
{
tochproiz2[i]=((pow(E,xj[i])*pow(xj[i],3)-3*pow(xj[i],2)*pow(E,xj[i]))/(pow(xj[i],6))-3*((pow(E,xj[i])*pow(xj[i],4)-4*pow(xj[i],3)*pow(E,xj[i]))/(pow(xj[i],8))))-(3*(2*sin(xj[i])*pow(cos(xj[i]),2)-pow(sin(xj[i]),3)));
}
for(h=0.2;h>=0.05;h=h/2)
{
printf("\nDlia h=%f\n",h);
m=(float)(b-a)/h;
q=m+1;
xi=new double [q];
yi=new double [q];
for(i=0;i<q;i++)
{
xi[i]=(double)a+i*h;
yi[i]=(double)(pow(E,xi[i]))/(pow(xi[i],3))-pow(sin(xi[i]),3);
}
proiz=new double[21];
proiz2=new double [21];
proiz2[0]=0.0;
proiz2[20]=0.0;
proiz[0]=(double)-1*(3*yi[0]-4*yi[1]+yi[2])/(2*h);
proiz[20]=(double)(yi[q-3]-4*yi[q-2]+3*yi[q-1])/(2*h);
for(g=1;g<20;g++)
{
i=1;
while(xj[g]>xi[i]) i++;
proiz[g]=(yi[i+1]-yi[i-1])/(2*h);
proiz2[g]=(yi[i-1]-2*yi[i]+yi[i+1])/(pow(h,2));
}
for(i=-1;i<21;i++) 
{
if(i==-1)
{
printf("   y       proizv    tochproizv    pogr    2proizv    2tochproizv    pogr\n");
continue;
}	
printf("%f  |%f  |%f  |%f  |%f  |%f  |%f\n",yj[i],proiz[i],tochproiz[i],fabs(tochproiz[i]-proiz[i]),proiz2[i],tochproiz2[i],fabs(tochproiz2[i]-proiz2[i]));
}
delete [] proiz2;
delete [] proiz;
delete [] yi;
delete [] xi;
}
delete [] tochproiz2;
delete [] tochproiz;
delete [] xj;
delete [] yj;
}
