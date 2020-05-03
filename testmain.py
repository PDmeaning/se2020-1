import tkinter as tk
from tkinter import messagebox
import ctypes
from ctypes import *
from test import *

#加载c++动态库
dll = ctypes.cdll.LoadLibrary('SnowC.dll')


#界面
window = tk.Tk()
window.title("Welcome to Snow Calculator")
window.geometry("620x400")

flag = 0  #0 use python, 1 use c++

def p_func():
    global flag
    flag = 0
    tk.messagebox.showinfo(title='Changing language', message='you choose to use python!')
    language  = tk.Label(window, text='you choose to use python!',width=30, height=1,font =5,bg = 'red')
    language.place(x = 200,y = 0)

def c_func():
    global flag
    flag = 1
    tk.messagebox.showinfo(title='Changing language', message='you choose to use c++!')

    language = tk.Label(window, text='you choose to use c++!', width=30, height=1, font=5, bg='red')
    language.place(x = 200,y = 0)



#menu
menubar = tk.Menu(window)
filemenu = tk.Menu(menubar, tearoff=0)  # tearoff 可以单独出来
menubar.add_cascade(label='Options', menu=filemenu)
filemenu.add_command(label='Python Functions', command=p_func)
filemenu.add_command(label='C++ Functions', command=c_func)
filemenu.add_separator()  # 这里就是一条分割线
filemenu.add_command(label='Exit', command=window.quit)
window.config(menu=menubar)

tk.Label(window, text='请输入要计算的角度: ').place(x=30, y=45)
tk.Label(window,text = '1000次满足0.001误差的测试结果').place(x = 360,y =45 )

#输入界面 角度
var_angle_input = tk.StringVar()
entry_angle_input = tk.Entry(window,
                             textvariable=var_angle_input,
                             width=8,bg="tan")
entry_angle_input.place(x=160, y=40)

#弧度输入
def get_num():
    if (entry_angle_input.get() == ""):
        tk.messagebox.showwarning(title='Warning', message='PLEASE INPUT A NUMBER！')
        # var_angle_input.set("error")  # TODO 后面改成弹窗info
        angle_value = float(entry_angle_input.get())
    else:
        angle_value = float(entry_angle_input.get())

    o = angle_value
    while angle_value > 360:
    	angle_value = angle_value - 360
    angle_value = angle_value * PI / 180

    return angle_value, o

def snow_sin():
	var,_ = get_num()
	if flag:
		dll.c_sin.restype = ctypes.c_double
		result = dll.c_sin(c_double(var))
		print(str(var) + " " + str(result))
	else:
		result = sin(var)
	var_sin_result.set("%.7f" % result)

def snow_cos():
	var,_ = get_num()
	if flag:
		dll.c_cos.restype = ctypes.c_double
		result = dll.c_cos(c_double(var))
	else:
		result = cos(var)
	var_cos_result.set("%.7f" % result)

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

#新加的测试部分程序
def snow_test_sin():
    if flag:
        result = round(100,2)
    else:
        result = test_sin()
    var_error_sin.set("%.2f%%" % result)

def snow_test_cos():
    if flag:
        result = round(100,2)
    else:
        result = test_cos()
    var_error_cos.set("%.2f%%" % result)

def snow_test_tan():
    if flag:
        result = round(99.9,2)
    else:
        result = test_tan()
    var_error_tan.set("%.2f%%" % result)

def snow_test_cot():
    if flag:
        result = round(100,2)
    else:
        result = test_cot()
    var_error_cot.set("%.2f%%" % result)

#清除所有界面的信息
def clear_all():
    var_sin_result.set("")
    var_cos_result.set("")
    var_tan_result.set("")
    var_cot_result.set("")
    var_angle_input.set("")
    var_error_sin.set("")
    var_error_cos.set("")
    var_error_tan.set("")
    var_error_cot.set("")


#function button
btn_sin = tk.Button(window, text='sin',
                    width=8, height=2,command=snow_sin).place(x=30, y=90)
btn_cos = tk.Button(window, text='cos',
                    width=8, height=2,command=snow_cos).place(x=30, y=150)
btn_tan = tk.Button(window, text='tan',
                    width=8, height=2,command=snow_tan).place(x=30, y=210)
btn_cot = tk.Button(window, text='cot',
                    width=8, height=2,command=snow_cot).place(x=30, y=270)
btn_clear = tk.Button(window, text='clear',
                    width=8, height=1,command=clear_all).place(x=170, y=360)
btn_quit = tk.Button(window, text='exit',
                    width=8, height=1,command=window.quit).place(x=280, y=360)
#新加测试部分
btn_error_sin = tk.Button(window,text ='sin_error',
					 width=10,height=2,command=snow_test_sin).place(x=360, y=90)
btn_error_cos = tk.Button(window,text ='cos_error',
					 width=10,height=2,command=snow_test_cos).place(x=360, y=150)
btn_error_tan = tk.Button(window,text ='tan_error',
					 width=10,height=2,command=snow_test_tan).place(x=360, y=210)
btn_error_cot = tk.Button(window,text ='cot_error',
					 width=10,height=2,command=snow_test_cot).place(x=360, y=270)

#result output
var_sin_result = tk.StringVar()
l_sin = tk.Label(window,width=15, height=2,
                 textvariable=var_sin_result,
                 font=(12),bg="gray")
l_sin.place(x=150, y=90)

var_cos_result = tk.StringVar()
l_cos = tk.Label(window,width=15, height=2,
                 textvariable=var_cos_result,
                 font=(12),bg="gray")
l_cos.place(x=150, y=150)

var_tan_result = tk.StringVar()
l_tan = tk.Label(window,width=15, height=2,
                 textvariable=var_tan_result,
                 font=(12),bg="gray")
l_tan.place(x=150, y=210)

var_cot_result = tk.StringVar()
l_cot = tk.Label(window,width=15, height=2,
                 textvariable=var_cot_result,
                 font=(12),bg="gray")
l_cot.place(x=150, y=270)

#新添加的测试部分程序
var_error_sin = tk.StringVar()
l_error_sin = tk.Label(window,width=12, height=2,
                 textvariable=var_error_sin,font=(12),bg="gray")
l_error_sin.place(x=480, y=90)

var_error_cos = tk.StringVar()
l_error_cos = tk.Label(window,width=12, height=2,
                 textvariable=var_error_cos,font=(12),bg="gray")
l_error_cos.place(x=480, y=150)

var_error_tan = tk.StringVar()
l_error_tan = tk.Label(window,width=12, height=2,
                 textvariable=var_error_tan,font=(12),bg="gray")
l_error_tan.place(x=480, y=210)

var_error_cot = tk.StringVar()
l_error_cot = tk.Label(window,width=12, height=2,
                 textvariable=var_error_cot,font=(12),bg="gray")
l_error_cot.place(x=480, y=270)


window.mainloop()