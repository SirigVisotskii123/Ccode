/*rang of matrix*/
#include <stdio.h>
#include<math.h>
using namespace std;
int rangpor(double **a,int k,int l)
{
	int buf=k,j;
	for(int i=0;i<k;i++)
	{
		int count=0;
		for(j=0;j<l;j++)
		{
			if(fabs(a[i][j])==0) count++;  
		if(count==l) buf--;
		}
		//if(count==j) buf--;	
	}
	return buf;
}
void fundel(double **a,int k,int z)
{
	double p=a[z][z];
	for(int i=0;i<k;i++)
    {
    	a[z][i]=a[z][i]/p;
    }
}
int max(int k,int l)
{
	if(k>=l) return k;
	else return l;
}
int min(int k,int l)
{
	if(k>=l) return l;
	else return k;
}
void funpreobr(double **a,int k,int l,int z)
{
	double buf;
	for(int q=z;q<(k-z);q++)
	{
		if(q==0 && z==0) continue;
	for(int i=0;i<l;i++)
	{
		buf=a[z+q][i];
		a[z+q][i]=a[z][i];
		a[z][i]=buf;
	}
	if(a[z][z]!=0) return;
    }
}
void funrang(double **a,int k,int l)
{
int z;
for(z=0;z<min(k,l)-1;z++)
{
if(a[z][z]==0)funpreobr(a,k,l,z);
if(a[z][z]==0)
{
	z=(min(k,l)-1);
	continue;
}
fundel(a,l,z);
for(int i=z;i<k-1;i++)
{   
    double m=a[i+1][z],x;
    if(z>=1) x=a[i-1][z];
    for(int j=0;j<l;j++)
    {
    	if(i<=z)
		{
		if(z>=1) a[i-z][j]-=(double)x*a[z][j];
        }
		a[i+1][j]-=(double)m*a[z][j];
    }
}
}
fundel(a,l,z);
for(;z>1;z--)
{
for(int i=k-1;i>=0;i--)
{   
    if(i==z)continue; 
    double m=a[i][z];
    for(int j=0;j<l;j++)
    {
    
		a[i][j]-=(double)m*a[z][j];
    }
}
}
}
int main()
{
int k=5;
int l=4;

double **a=new double*[k];
for(int i=0;i<k;i++) a[i]=new double [l];

a[0][0]=4;
a[0][1]=4;
a[0][2]=3;
a[0][3]=6;
a[1][0]=3;
a[1][1]=8;
a[1][2]=1;
a[1][3]=7;
a[2][0]=9;
a[2][1]=1;
a[2][2]=4;
a[2][3]=2;
a[3][0]=7;
a[3][1]=1;
a[3][2]=3;
a[3][3]=2;
a[4][0]=8;
a[4][1]=9;
a[4][2]=1;
a[4][3]=5;

/*
a[0][0]=4;
a[0][1]=4;
a[0][2]=3;
a[0][3]=2;
a[0][4]=7;
a[1][0]=4;
a[1][1]=4;
a[1][2]=8;
a[1][3]=1;
a[1][4]=2;
a[2][0]=3;
a[2][1]=7;
a[2][2]=2;
a[2][3]=4;
a[2][4]=5;
a[3][0]=2;
a[3][1]=6;
a[3][2]=8;
a[3][3]=3;
a[3][4]=7;
*/

for(int i=0;i<k;i++)
{
    for(int j=0;j<l;j++)
    {
        printf("%f ",a[i][j]);
    }
    printf("\n");
}
printf("\n\n");
funrang(a,k,l);
for(int i=0;i<k;i++)
{
    for(int j=0;j<l;j++)
    {
        printf("%f   ",a[i][j]);
    }
    printf("\n");
}

printf("\nrank(a)=%d ",rangpor(a,k,l));
for(int i=0;i<k;i++) delete[] a[i];
delete [] a; 
}
