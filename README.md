# se2020
三角函数软件工程项目(test分支)
编写软件：python、c++
--
### 界面
* （1）点击界面的options按钮下拉隐藏的工具，包含Python Language、C++ Language和Exit选项，可对后台执行三角函数计算采用的编辑语言进行选择或执行系统退出操作。
![image](math/tu3.png)
* （2）界面有个输入框，输入角度来计算三角函数的值（程序中会把角度自动转换为弧度来计算）。  
* （3）点击界面sin，cos，tan，cot按钮，可分别计算输入变量的正弦值，余弦值，正切值和余切值。
* （4）点击界面的右边的sin_error，cos-error,tan-error,cot-error即可分别自动输入1000次数据并计算误差。
![image](math/tu4.png)




### 代码
* （1）pch.cpp是使用c++语言实现的cos、cot、sin和tan函数，pch.h是其对应的头文件。
* （2）SnowC.dll是上述两个文件编译生成的Windows动态链接库文件，供python加载后调用c++方法来计算三角函数。
* （3）pySnow.py包括用python语言实现cos、cot、sin和tan函数。
* （4）main.py主要实现了三角函数运算界面（v1.0）显示（python语言），导入pySnow来执行python实现的三角函数，加载SnowC.dll调用C++语言实现的三角函数。
* （5）test.py（python语言）与tset.cpp（C++语言）主要实现了输入1000次数据，并与正确数据比较计算误差数据的功能。其中C++测试模块通过动态加载上一组同学生成的动态链接模块所计算的值与系统三角函数进行比较,测试模块通过调用mydll.dll计算三角函数值后与系统函数比较。
* （6）testmain.py主要实现了三角函数运算测试与原三角函数计算函数的界面(v2.0)显示（python语言）。
### 后台
* 界面尺寸、标题
      ```python   
      python window = tk.Tk()
      window.title("trigonometric function")
      window.geometry("480x400")
      ```
         
* 输入变量
         
      ```python
      e.get()   
      ```
         三角函数值输出
      ```python
      t.insert("end", result)
      ```
         
* 界面按钮，例如
     
     ```python
      tk.Button(window,
                  text="sin",
                  width=15,height=2,
                  width=15, height=1,
                  command=compute_sin)
     ```
     
     
     
* 三角函数计算

  sin计算
  
      ```python
  def snow_sin():
  	var,_ = get_num()
  	if flag:
  		dll.c_sin.restype = ctypes.c_double
  		result = dll.c_sin(c_double(var))
  		print(str(var) + " " + str(result))
  	else:
  		result = sin(var)
  	var_sin_result.set("%.7f" % result)
      ```
  
  
  
  ```c++
  DLL_EXPORT double c_sin(double x)
      {
        int i = 1, negation = 1;//取反
          double sum = 0;
          double index = x;//指数
          double Factorial = 1;//阶乘
          double TaylorExpansion = x;//泰勒展开式求和
          do
          {
              Factorial = Factorial * ((__int64)i + 1) * ((__int64)i + 2);//求阶乘
              index *= x * x;//求num2的次方
              negation = -negation;//每次循环取反
              sum = index / Factorial * negation;
              TaylorExpansion += sum;
              i += 2;
          } while (myabs(sum) > 1e-15);
          return (TaylorExpansion);
      }
  ```
  
  
  
  cos计算
  
  ```python
  def snow_cos():
  	var,_ = get_num()
  	if flag:
  		dll.c_cos.restype = ctypes.c_double
  		result = dll.c_cos(c_double(var))
  	else:
  		result = cos(var)
  	var_cos_result.set("%.7f" % result)
  ```
  
  
  
  ```c++
  DLL_EXPORT double c_cos(double x)
      {
          x = (PI / 2) - x;
          return c_sin(x);
      }
  ```
  



tan计算

```python
def snow_tan():
	var,o = get_num()
	if o != 0 and (o % 90 == 0 and o / 90 % 2 != 0):
		var_tan_result.set("inexistence")
	else:
		if flag:
			dll.c_tan.restype = ctypes.c_double
			result = dll.c_tan(c_double(var))
		else:
			result = tan(var)
		var_tan_result.set("%.7f" % result)
```



```c++
DLL_EXPORT double c_tan(double x)
    {
        return (c_sin(x) / c_cos(x));
    }
```



cot计算

```python
def snow_cot():
	var,o = get_num()
	if o % 90 == 0:
		if o / 90 % 2 == 0:
			var_cot_result.set("inexistence")
		if o / 90 % 2 != 0:
			var_cot_result.set("%.7f" % 1.0)
	else:
		if flag:
			dll.c_cot.restype = ctypes.c_double
			result = dll.c_cot(c_double(var))
		else:
			result = cot(var)
		var_cot_result.set("%.7f" % result)
```



```c++
DLL_EXPORT double c_cot(double x)
{
        return (1 / c_tan(x));
}
```

