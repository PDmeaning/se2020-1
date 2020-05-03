#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

using namespace std;

const double pi=3.1415926;


void test_sinc()
{

    double result;  
    double sum=0.0;

	srand((unsigned int)time(0));//初始化种子为随机值
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll路径
	
	   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_sin = (FUNA)GetProcAddress(handle, TEXT("c_sin"));//直接使用原工程函数名 
        if (c_sin)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//随机产生1-100之间的数(弧度值)  
				result=c_sin(x);
			   double wucha=result-sin(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_sin("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"sin("<<x<<")="<<sin(x)<<"       "<<"误差为c_sin(x)-sin(x)="<<wucha<<endl;//保留小数点后四位输出函数计算结果
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_sin共测试了1000组数据，误差小于0.001的有"<<sum<<"组，准确率为"<<p<<"%"<<endl;

			
        }
		else
		{
			cout<<"ERROR on GetProcAddress"<<endl;
		}
			FreeLibrary(handle);
	}
	else
	{
		cout<<"ERROR on LoadLibrary"<<endl;
		std::cout<<GetLastError()<<endl;
	}
	

}
void test_cosc()
{

    double result; 
    double sum=0.0;

	srand((unsigned int)time(0));//初始化种子为随机值
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll路径
	
	   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_cos = (FUNA)GetProcAddress(handle, TEXT("c_cos"));//直接使用原工程函数名 
        if (c_cos)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//随机产生1-100之间的数(弧度值)  
				result=c_cos(x);
			   double wucha=result-cos(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_cos("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//<<"       "<<"cos("<<x<<")="<<cos(x)<<"       "<<"误差为c_cos(x)-cos(x)="<<wucha<<endl;//保留小数点后四位输出函数计算结果
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_cos共测试了1000组数据，误差小于0.001的有"<<sum<<"组，准确率为"<<p<<"%"<<endl;

			
        }
		else
		{
			cout<<"ERROR on GetProcAddress"<<endl;
		}
			FreeLibrary(handle);
	}
	else
	{
		cout<<"ERROR on LoadLibrary"<<endl;
		std::cout<<GetLastError()<<endl;
	}

	 
}

void test_tanc()
{

    double result;  
    double sum=0.0;

	srand((unsigned int)time(0));//初始化种子为随机值
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll路径 
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_tan = (FUNA)GetProcAddress(handle, TEXT("c_tan"));//直接使用原工程函数名 
        if (c_tan)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//随机产生1-100之间的数(弧度值)  
				result=c_tan(x);
			   double wucha=result-tan(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_tan("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"tan("<<x<<")="<<tan(x)<<"       "<<"误差为c_tan(x)-tan(x)="<<wucha<<endl;//保留小数点后三位输出函数计算结果
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_tan共测试了1000组数据，误差小于0.001的有"<<sum<<"组，准确率为"<<p<<"%"<<endl;

			
        }
		else
		{
			cout<<"ERROR on GetProcAddress"<<endl;
		}
			FreeLibrary(handle);
	}
	else
	{
		cout<<"ERROR on LoadLibrary"<<endl;
		std::cout<<GetLastError()<<endl;
	}
	  
		
}

void test_cotc()
{

    double result;  
    double sum=0.0;

	srand((unsigned int)time(0));//初始化种子为随机值
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll路径   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_cot = (FUNA)GetProcAddress(handle, TEXT("c_cot"));//直接使用原工程函数名 
        if (c_cot)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//随机产生1-100之间的数(弧度值)  
				result=c_cot(x);
			   double wucha=result-(cos(x)/sin(x));

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_cot("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"cot("<<x<<")="<<1/tan(x)<<"       "<<"误差为c_cot(x)-cot(x)="<<wucha<<endl;//保留小数点后四位输出函数计算结果
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_cot共测试了1000组数据，误差小于0.001的有"<<sum<<"组，准确率为"<<p<<"%"<<endl;

			
        }
		else
		{
			cout<<"ERROR on GetProcAddress"<<endl;
		}
			FreeLibrary(handle);
	}
	else
	{
		cout<<"ERROR on LoadLibrary"<<endl;
		std::cout<<GetLastError()<<endl;
	}
	 
	    
		
}

void  main()
{
	for(int i=0;i<4;i++)
	{
		if(i==0)
			test_sinc();
		if(i==1)
			test_cosc();
		if(i==2)
			test_tanc();
		if(i==3)
			test_cotc();
		

	}
  system("pause"); 

}