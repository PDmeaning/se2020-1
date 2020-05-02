#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define jingdu 1e-7
#define pi 3.1415926
_int64 fac(unsigned long n)  
{
    _int64 m; int i;
    for(i=0,m=1;i<=n;i++)
    {
        if(i!=0)
            m=m*i;
    }
    return m;
}
long double fcos(double x)
{
   long double temp=0.0,t=5;
    int i=0;
    while(x>=2*pi) x=x-2*pi;       //最多只有2π个弧度
    while(t>=jingdu)
    {
        t=(pow(x,2*i))/fac(2*i);
        temp+=pow(-1,i)*t;
        i++;
        //printf("%.5lf\n",temp);
    }
    return temp;
}
long double fsin( double x)
{
   long  double temp=0.0,t=5;
    int i=0;
    while(x>=2*pi) x=x-2*pi;       //最多只有2π个弧度
    while(t>=jingdu)
    {
        t=(pow(x,(2*i+1)))/fac(2*i+1);
        temp+=pow(-1,i)*t;
        i++;
        
    }
    return temp;
}


long double ftan( double x)
{
   long  double temp=0.0;
   if(x>=pi/2) x=x-pi;
   if(x!=pi/2)
   temp= x+pow(x,3)/3+2*pow(x,5)/15+17*pow(x,7)/315+62*pow(x,9)/2835;
    return temp;
}

long double fcot( double x)
{
   long  double temp=0.0;
   if(x>=pi) x=x-pi;
   if((x!=0)&&(x!=pi))
   temp= 1/x-x/3-pow(x,3)/45-2*pow(x,5)/945;
    return temp;
}
int main()
{
    double r;
    printf("请输入弧度值，180°对应3.1415926弧度，以此类推...\n");
    printf("弧度(rad):");
    scanf("%lf",&r);
    printf("fcos=%.5lf\n",fcos(r));
    printf("cosx=%.51f \n",cos(r));//用系统函数进行对比
	printf("fsinx=%.5lf\n",fsin(r));
    printf("sinx=%.51f\n",sin(r));//用系统函数进行对比
	if ((r!=pi/2)&&(r!=3*pi/2))
	     printf("ftan=%.5lf\n",ftan(r));
	else 	
		printf("ftanx:null\n");
    printf("tanx=%.51f \n",tan(r));//用系统函数进行对比
    if ((r!=0)&&(r!=pi))
		 	printf("fcot=%.5lf\n",fcot(r));
	else 
		printf("fcotx:null\n");
    printf("cotx=%.51f \n",cos(r)/sin(r));
	system("pause");
} 