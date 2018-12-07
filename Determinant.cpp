/*determinant of matrix*/
#include <stdio.h>
#include<math.h>
using namespace std;
double f2foundmax(double **a,int k,int z)
{
	double max=0;
	double buf;
	int c,d;
	for(int i=z;i<k;i++)
	{
		for(int j=z;j<k;j++)
		{
		    	if(max<fabs(a[i][j])) 
				{
		    	max=a[i][j];
		    	c=i;
		    	d=j;
				}
		}
	}//если макс = 0 то матрица нулевая
	for(int i=z;i<k;i++)
	{
		buf=a[z][i];
		a[z][i]=a[c][i];
		a[c][i]=buf;
	}
	for(int j=z;j<k;j++)
	{
		buf=a[j][z];
		a[j][z]=a[j][d];
		a[j][d]=buf;
	}
	
}
void funpreobr(double **a,int k,int z)
{
	double buf;
	for(int q=z;q<(k-z);q++)
	{
		if(q==0 && z==0) continue;
	for(int i=0;i<k;i++)
	{
		buf=a[z+q][i];
		a[z+q][i]=a[z][i];
		a[z][i]=buf;
	}
    }
}
float det(double **a,int k)
{
    int de=1;
    for(int i=0;i<k;i++)
    {
        de*=a[i][i];
    }
    return de;
}
int main()
{
int k=4;
int i;
double **a=new double*[k];
for( i=0;i<k;i++) a[i]=new double [k];
a[0][0]=4;
a[0][1]=4;
a[0][2]=3;
a[0][3]=2;
a[1][0]=4;
a[1][1]=4;
a[1][2]=8;
a[1][3]=1;
a[2][0]=0;
a[2][1]=7;
a[2][2]=2;
a[2][3]=4;
a[3][0]=12;
a[3][1]=4;
a[3][2]=6;
a[3][3]=12;
for(i=0;i<k;i++)
{
    for(int j=0;j<k;j++)
    {
        printf("%f ",a[i][j]);
    }
    printf("\n");
}

double m;
for(int z=0;z<k-1;z++)
{
if(a[z][z]==0)funpreobr(a,k,z);
if(a[z][z]==0)
{
	z=(k-1);
	continue;
}
for(i=z;i<k-1;i++)
{
    
    m=(double)a[i+1][z]/a[z][z];
    for(int j=0;j<k;j++)
    {
        a[i+1][j]-=(double)m*a[z][j];
    }
}
}
printf("\n");
for( i=0;i<k;i++)
{
    for(int j=0;j<k;j++)
    {
        printf("%f ",a[i][j]);
    }
    printf("\n");
}
printf("\n %f",det(a,k));
for(int i=0;i<k;i++) delete[] a[i];
delete [] a;    
}
