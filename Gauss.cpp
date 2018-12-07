/*Solution of a system of linear equations by Gauss method*/
#include<stdio.h>
#include<math.h>
using namespace std;
float modVect(float *nev,int n);
int checkSlb(float **q,int n);
int checkStr(float **q,int n);
int determ(float **q,int n);
int checkNull(float **q,int n);
void maxPreobr(float **q,float *b,int n,int z);
void Gauss(float **q,float *b,int n);
main ()
{
goto m1;
m2:printf("\n\nPovtorite programmu...!!!\n\n");
m1:
int i,g,n;
float **q,*b,E,*x,*nev;
printf("Vvedite tochnost izmerenii(0.001)...\n");
scanf("%f",&E);
printf("Vvedite colichestvo uravnenii(poryadok)...\n");
scanf("%d",&n);
q=new float *[n];
for(i=0;i<n;i++) q[i]=new float [n];
printf("\nVvedite osnovnuyu matricu...\n");
for(i=0;i<n;i++)
for(g=0;g<n;g++)
{
printf("q[%d][%d]= ",i,g);
scanf("%f",&q[i][g]);
}
b=new float [n];
printf("\nVvedite svobodnie chleni...\n");
for(i=0;i<n;i++)
{
printf("b[%d]= ",i);
scanf("%f",&b[i]);
}
printf("\nIshodnaya SLAU...\n");
for(i=0;i<n;i++)
{
for(g=0;g<n;g++)
{
printf("%.1f ",q[i][g]);
if(g==n-1) printf(" | %.1f",b[i]);
}
printf("\n");
}
if(checkStr(q,n)==0 || checkSlb(q,n)==0) goto m2;
if(checkNull(q,n)==0) goto m2;
printf("\nVipolnyaetca pryamoi hod Gaussa...\n");
Gauss(q,b,n);
for(i=0;i<n;i++)
{
for(g=0;g<n;g++)
{
printf("%.1f ",q[i][g]);
if(g==n-1) printf(" | %.1f",b[i]);
}
printf("\n");
}
if(determ(q,n)==0) goto m2;
m3:
printf("\nVicheslenie vectora neizvestnih...\n");
float k;
x=new float [n];
for(i=n-1;i>=0;i--)
{
k=0;
for(g=0;g<n;g++)
{
if(i==g) continue;
k+=x[g]*q[i][g];
}
x[i]=(float)((b[i]-k)/q[i][i]);
}
nev=new float [n];
for(i=0;i<n;i++)
{
k=0;	
for(g=0;g<n;g++)
{
k+=q[i][g]*x[g];
}
nev[i]=b[i] - k;
}
if(E>=modVect(nev,n)) 
{
for(i=0;i<n;i++) printf("x[%d]= %f\n",i,x[i]);
}
else goto m3;
printf("...........................................");
for(;;);
for(i=0;i<n;i++) delete [] q[i];
delete []q;
q=NULL;
delete [] b;
b=NULL;
delete [] x;
x=NULL;
delete [] nev;
nev=NULL;
}
float modVect(float *nev,int n)
{
int i;
float k,l=0;
for(i=0;i<n;i++) l+=pow(nev[i],2);
k=sqrt(l);
return k;  	
}
int checkSlb(float **q,int n)
{
int i,g,z,k=0;
for(z=0;z<n-1;z++)
{
for(i=1;i<n;i++)
{
for(g=0;g<n;g++)
{
if((z+i)>n-1) continue;
if(q[g][z]==q[g][z+i]) k++;
if(q[g][z]!=q[g][z+i]){k=0; continue;}
if(k==n && g==n-1) return 0;
if(g==n-1) k=0;
}
k=0;
}
}
return 1;
}
int checkStr(float **q,int n)                                      
{
int z,i,g,k=0;
for(z=0;z<n-1;z++)
{
for(i=1;i<n;i++)
{
for(g=0;g<n;g++)
{
if((z+i)>n-1) continue;
if(q[z][g]==q[z+i][g]) k++;
if(q[z][g]!=q[z+i][g]){k=0; continue;}
if(k==n && g==n-1) return 0;
if(g==n-1) k=0;
}
k=0;
}
}
return 1;
}
int determ(float **q,int n)
{
int i;
for(i=0;i<n;i++) 
{
if (fabs(q[i][i])>0) continue;
else return 0;
}
return 1;
}
int checkNull(float **q,int n)                                                   
{
int i,g,count=0;
for(i=0;i<n;i++)
{
for(g=0;g<n;g++)
{
if(q[i][g]!=0) continue;
if(q[i][g]==0) count++;
if(g==n-1 && count==n) return 0; 
}
count=0;
}
for(i=0;i<n;i++)
{
for(g=0;g<n;g++)
{
if(q[g][i]!=0) continue;
if(q[g][i]==0) count++;
if(g==n-1 && count==n) return 0; 
}
count=0;
}
return 1;
}
void maxPreobr(float **q,float *b,int n,int z)                                  
{
int i,k;
float *buf,max=0,bufb;
for(i=z;i<n;i++)
{
if(max<q[i][z])
{
max=q[i][z];
k=i;
}
}
if(k!=z)
{
buf=q[z];
q[z]=q[k];
q[k]=buf;
bufb=b[z];
b[z]=b[k];
b[k]=bufb;
}
else return;
}
void Gauss(float **q,float *b,int n)                                          
{
int z,i,g;
float k;
for(z=0;z<n-1;z++)
{
maxPreobr(q,b,n,z);
for(i=z+1;i<n;i++)
{
k=q[i][z]/q[z][z];
b[i]-=b[z]*k;
for(g=z;g<n;g++) 
{
q[i][g]-=q[z][g]*k;
}
}
}
/*for(i=0;i<n;i++)
for(g=0;g<n;g++)
{
if((int)q[i][g]*10==0) q[i][g]=fabs(q[i][g]);
}*/
}
