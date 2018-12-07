/*approximation of functions*/
#include<stdio.h>
#include<math.h>
using namespace std;
#define E 2.718
void Zamena(float **xi,float *yi,int m,int z);
void Gauss(float **xi,float *yi,int m,int z);
main()
{
int m,a,b,i,g;
float *yi,*xj,*yj,*C,**xi,p,*POG,r;
printf("Vvedite interval[a,b]...\n");
scanf("%d %d",&a,&b);
printf("Vvedite colichestvo neizvestnih(4)...\n");
scanf("%d",&m);
printf("\n");
xi=new float *[m];//
for(i=0;i<m;i++) xi[i]=new float [m];
for(i=0;i<m;i++)
{
for(g=0;g<m;g++)
{
xi[i][g]=(float)pow((a+(((i+1)-1)*(b-a))/(m-1)),g);
}
}
yi=new float[m];//
for(i=0;i<m;i++) yi[i]=(float)(pow(E,xi[i][1])/pow(xi[i][1],3))-pow(sin(xi[i][1]),3);
for(i=0;i<m;i++)
{
for(g=0;g<m;g++)
{
printf("%f ",xi[i][g]);
if(g==m-1)printf("| %f",yi[i]);
}
printf("\n");
}
printf("\nVicheslim sistemu metodom Gaussa...\n");
for(int z=0;z<m-1;z++)Gauss(xi,yi,m,z);
for(i=0;i<m;i++)
{
for(g=0;g<m;g++)
{
printf("%.1f ",xi[i][g]);
if(g==m-1)printf("| %f",yi[i]);
}
printf("\n");
}
xj=new float[21];//
for(i=1;i<=21;i++) xj[i-1]=a+((i-1)*(b-a))/20.;
//for(i=0;i<21;i++) printf("%f ",xj[i]);
yj=new float[21];//
for(i=0;i<21;i++) yj[i]=(pow(E,xj[i])/pow(xj[i],3))-pow(sin(xj[i]),3);
//for(i=0;i<21;i++) printf("%f ",yj[i]);
printf("\nNahodim vector C s pomoshu metoda Gaussa...\n");
C=new float [m];
for(i=m-1;i>=0;i--)
{
p=0;
for(g=0;g<m;g++)
{
if(i==g) continue;
p+=C[g]*xi[i][g];
}
C[i]=(float)((yi[i]-p)/xi[i][i]);
}
for(i=0;i<m;i++)printf("%f ",C[i]);
//POG
POG=new float [21];	
//printf("m=%d,C[m]=%f",m,C[m-1]);
for(g=0;g<21;g++)
{
r=C[m-1];
for(i=m-2;i>=0;i--)
{
r=r*xj[g]+C[i];		
}
POG[g]=r;
}
printf("\n\n");
for(i=0;i<21;i++)
{
printf("%f |%f |%f |%f |%f \n",xj[i],yj[i],xj[i],POG[i],fabs(yj[i]-POG[i]));	
}
//printf("\n");
//for(i=0;i<21;i++) printf("%f ",POG[i]);
//for(i=0;i<m;i++)
delete [] POG;
delete [] C;
for(i=0;i<m;i++) delete [] xi[i];
delete [] xi;
delete [] yi;
delete [] xj;
delete [] yj;
for(;;);
}
void Gauss(float **xi,float *yi,int m,int z)
{
int i,g,c=1;
float k;
for(i=z+1;i<m;i++)
{
Zamena(xi,yi,m,z);
k=xi[i][z]/xi[z][z];
yi[i]-=yi[z]*k;
for(g=z;g<m;g++)
{
xi[i][g]-=xi[z][g]*k;
c=(int)xi[i][g]*10000;
if(c==0) xi[i][g]=fabs(xi[i][g]);
c=1;
}
}
}
void Zamena(float **xi,float *yi,int m,int z)
{
int i,k;
float max,*buf,bufy;
for(i=z;i<m;i++)
{
if(xi[i][z]>max){max=xi[i][z];k=i;}
}
if(k!=z)
{
buf=xi[z];
xi[z]=xi[k];
xi[k]=buf;
bufy=yi[z];
yi[z]=yi[k];
yi[k]=bufy;
}
}

