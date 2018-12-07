/*Solution of a system of linear equations by Seidel method*/
#include<stdio.h>
#include<math.h>
float check(float *buf,float *x,int n);
void Zeidel(float **q,float *b,float *x,int n,float E,float w);
void main(void)
{
int i,g,n;
float **q,*x,*b,E,w,co;
printf("Vvedite tochnost vichislenii...\n");
scanf("%f",&E);
printf("Vvedite parametr relaxacii...\n");
scanf("%f",&w);
printf("Vvedite colichestvo uravnenii(poryadok)...\n");
scanf("%d",&n);
printf("\nVvedite osnovnuyu matricu:\n");
q=new float *[n];
for(i=0;i<n;i++) q[i]=new float [n];
for(i=0;i<n;i++)
for(g=0;g<n;g++)
{
printf("q[%d][%d]= ",i,g);
scanf("%f",&q[i][g]);
}
for(i=0;i<n;i++) q[1][i]-=q[0][i];
//for(i=0;i<n;i++) q[1][i]-=q[0][i];
/*for(i=0;i<n;i++)
{co=0;
for(g=0;g<n;g++)
{
if(i!=g) co+=fabs(q[i][g]);
else continue;
}
if(fabs(q[i][i])<co)
{
for(g=0;g<n;g++)
{
q[i][g]-=q[i-1][g];
}
}
else continue;
}*/
b=new float [n];
printf("\nVvedite svobodnie chleni:\n");
for(i=0;i<n;i++)
{
printf("b[%d]= ",i);
scanf("%f",&b[i]);
}
printf("\nVvedite nachalnie znacheniya:\n"); 
x=new float [n];
for(i=0;i<n;i++)
{
printf("x[%d]= ",i);
scanf("%f",&x[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
for(g=0;g<n;g++)
{
printf("%f * x%d ",q[i][g],g+1);
if(g==n-1) printf("=");
else printf("+");
if(g==n-1) printf("%f",b[i]);
}
printf("\n");
}
printf("\n");
for(;w<2;w=w+0.2)//
{
//if(w!=1) continue;
printf("\n%.1f\n",w);
Zeidel(q,b,x,n,E,w);
printf("\n\n");
for(i=0;i<n;i++) x[i]=0;
}

for(i=0;i<n;i++) delete [] q[i];
delete [] q;
q=NULL;
delete [] x;
x=NULL;
delete [] b;
b=NULL;
}
void Zeidel(float **q,float *b,float *x,int n,float E,float w)
{
int i,g;//,o=0;
float k,*buf;
buf=new float [n];
for(;check(buf,x,n)>=E;)
{
for(i=0;i<n;i++)
{
k=0;
for(g=0;g<n;g++) buf[g]=x[g];
for(g=0;g<n;g++)
{
if(i==g) continue;
k+=q[i][g]*buf[g];
}
x[i]=(float)((b[i]-k)/q[i][i]);
x[i]=w*x[i]+(1-w)*buf[i];//
}
for(i=0;i<n;i++) printf("%f |",x[i]);
if(i==n)printf("\n"); //{o++;printf("\n|%d|",o);}
}
delete [] buf;
}
float check(float *buf,float *x,int n)
{
int i;
float k,l,max=0;
for(i=0;i<n;i++)
{
k=x[i];
l=buf[i];
if(max<fabs(k-l)) max=(float)fabs(k-l);
}
return ((float)fabs(max));
}
