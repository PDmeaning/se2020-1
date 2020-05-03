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

	srand((unsigned int)time(0));//��ʼ������Ϊ���ֵ
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll·��
	
	   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_sin = (FUNA)GetProcAddress(handle, TEXT("c_sin"));//ֱ��ʹ��ԭ���̺����� 
        if (c_sin)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//�������1-100֮�����(����ֵ)  
				result=c_sin(x);
			   double wucha=result-sin(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_sin("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"sin("<<x<<")="<<sin(x)<<"       "<<"���Ϊc_sin(x)-sin(x)="<<wucha<<endl;//����С�������λ�������������
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_sin��������1000�����ݣ����С��0.001����"<<sum<<"�飬׼ȷ��Ϊ"<<p<<"%"<<endl;

			
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

	srand((unsigned int)time(0));//��ʼ������Ϊ���ֵ
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll·��
	
	   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_cos = (FUNA)GetProcAddress(handle, TEXT("c_cos"));//ֱ��ʹ��ԭ���̺����� 
        if (c_cos)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//�������1-100֮�����(����ֵ)  
				result=c_cos(x);
			   double wucha=result-cos(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_cos("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//<<"       "<<"cos("<<x<<")="<<cos(x)<<"       "<<"���Ϊc_cos(x)-cos(x)="<<wucha<<endl;//����С�������λ�������������
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_cos��������1000�����ݣ����С��0.001����"<<sum<<"�飬׼ȷ��Ϊ"<<p<<"%"<<endl;

			
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

	srand((unsigned int)time(0));//��ʼ������Ϊ���ֵ
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll·�� 
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_tan = (FUNA)GetProcAddress(handle, TEXT("c_tan"));//ֱ��ʹ��ԭ���̺����� 
        if (c_tan)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//�������1-100֮�����(����ֵ)  
				result=c_tan(x);
			   double wucha=result-tan(x);

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_tan("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"tan("<<x<<")="<<tan(x)<<"       "<<"���Ϊc_tan(x)-tan(x)="<<wucha<<endl;//����С�������λ�������������
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_tan��������1000�����ݣ����С��0.001����"<<sum<<"�飬׼ȷ��Ϊ"<<p<<"%"<<endl;

			
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

	srand((unsigned int)time(0));//��ʼ������Ϊ���ֵ
    
		  HINSTANCE handle = LoadLibrary("mydll.dll");//dll·��   
    
    if (handle)
    {
        typedef double(*FUNA)(double x);

		FUNA c_cot = (FUNA)GetProcAddress(handle, TEXT("c_cot"));//ֱ��ʹ��ԭ���̺����� 
        if (c_cot)
        {
            for(int i=0;i<1000;i++)
			{
				double x= pi*(rand() / double(RAND_MAX));//�������1-100֮�����(����ֵ)  
				result=c_cot(x);
			   double wucha=result-(cos(x)/sin(x));

				if(wucha<0)
					wucha=-wucha;

				if(wucha<0.001)
					sum+=1;

				//cout<<"c_cot("<<x<<")="<<setiosflags(ios::fixed)<<setprecision(4)<<result
					//	<<"       "<<"cot("<<x<<")="<<1/tan(x)<<"       "<<"���Ϊc_cot(x)-cot(x)="<<wucha<<endl;//����С�������λ�������������
				//cout<<"****************************************"<<endl;
			}

	          
			 double p=(sum/1000)*100;
			cout<<"c_cot��������1000�����ݣ����С��0.001����"<<sum<<"�飬׼ȷ��Ϊ"<<p<<"%"<<endl;

			
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