from pySnow import *
import random

# 计算正弦函数的误差
def test_sin():
    num_test = 0
    count_sin = 0
    while num_test<1000:
        a = round(random.uniform(0,360),3)
        m1 = float(sin(a*PI/180))-math.sin(a*PI/180)
        if m1<=0.001:
            count_sin =count_sin + 1
        num_test = num_test + 1
        n1 = round(count_sin/10,2)
    #print(n1)
    return n1

def test_cos():
    num_test = 0
    count_cos = 0
    while num_test<1000:
        a = random.uniform(0.01,360)
        m2 = float(cos(a*PI/180))-math.cos(a*PI/180)
        if m2<=0.001:
            count_cos =count_cos + 1
        num_test = num_test + 1
    n2 = round(count_cos/10,2)
    #print(n2)
    return n2

def test_tan():
    num_test = 0
    count_tan = 0
    while num_test<1000:
        a = round(random.uniform(0,360),3)
        m3 = float(tan(a*PI/180))-math.sin(a*PI/180)/math.cos(a*PI/180)
        if m3<=0.001:
            count_tan =count_tan + 1
        num_test = num_test + 1
    n3 = round(count_tan/10,2)
    #print(n3)
    return n3

def test_cot():
    num_test = 0
    count_cot = 0
    while num_test<1000:
        a = round(random.uniform(0,360),3)
        m4 = float(cot(a*PI/180))-math.cos(a*PI/180)/math.sin(a*PI/180)
        if m4<=0.001:
            count_cot =count_cot + 1
        num_test = num_test + 1
    n4 = round(count_cot/10,2)
    #print(n4)
    return n4
#为了快速验证测试函数的输出是否正确
# test_sin()
# test_cos()
# test_tan()
# test_cot()

