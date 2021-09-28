#!/usr/bin/env python
# coding: utf-8

# In[1]:

import numpy as np

def add(m,n):
    c=m+n
    return c

def subtract(m,n):
    c=m-n
    return c

def multiply(m,n):
    c=m*n
    return c

def divide(m,n):
    c=m/n
    return c

opt = input("Enter your option: a>list b>4*1 matrix c>4*4 matrix: ")
print("User entered the following option:",opt)


val = input("Enter your value: 1>add 2>subtract 3>multiply 4>divide: ")
print("User entered the following value:",val)

if(opt=='a'):
    a_list = [2,3,4,5]
    b_list = [6,7,8,9]
    a_np = np.array(a_list)
    print("first list is:",a_np)
    b_np = np.array(b_list)
    print("second list is:",b_np)
    
if(opt=='b'):
    a_np = np.random.randint(0,10,(4,1))
    print("4*1 first matrix is:",a_np)
    b_np = np.random.randint(0,10,(4,1))
    print("4*1 second matrix is:",b_np)
    
if(opt=='c'):
    a_np = np.random.randint(0,10,(4,4))
    print("4*4 first matrix is:",a_np)
    b_np = np.random.randint(0,10,(4,4))
    print("4*4 second matrix is:",b_np)    
    
if(val=='1'):
    c = add(a_np, b_np)
    print("\n The addition result is:",c)

if(val=='2'):
    c = subtract(a_np, b_np)
    print("\n The subtract result is:",c)
    
if(val=='3'):
    c = multiply(a_np, b_np)
    print("\n The multiply result is:",c)
    
if(val=='4'):
    c = divide(a_np, b_np)
    print("\n The divide result is:",c)
