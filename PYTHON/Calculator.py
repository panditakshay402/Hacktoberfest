print("Standard calculator")
print("Method-1: Addition")
print("Method-2: Substraction")
print("Method-3: Multiplication")
print("Method-4: Division")
print("Method-5: Special Operations")
n=int(input("Enter Your choice"))
if n==1:
     a=eval(input("Enter the list of elements to be added"))
     print(sum(a))
elif n==2:
    a=float(input("Enter first number"))
    b=float(input("Enter second number"))
    print("Calculated Result:",a-b)
elif n==3:
    a=float(input("Enter first number"))
    b=float(input("Enter second number"))
    print("Calculated Result:",a*b)
elif n==4:
    a=float(input("Enter first number"))
    b=float(input("Enter second number"))
    print("Calculated Result:",a/b)
elif n==5:
    print("i)Trigonometric function")
    print("ii)Logarithm")
    print("iii)Power function")
    print("iv)Square root function")
    print("v)Natural logarithm")
    print("vi)Exponential function")
    x=int(input("Enter your choice"))
    import math
    if x==1:
        a=float(input("Enter angle in degrees"))
        print("sin",a,"degree is",math.sin(math.radians(a)))
        print("sin",a,"degree is",math.cos(math.radians(a)))
    elif x==2:
        a=float(input("Enter the number"))
        b=float(input("Enter the base"))
        print(math.log(a,b))
    elif x==3:
        a=float(input("Enter the base"))
        b=float(input("Enter the power"))
        print(math.pow(a,b))
    elif x==4:
        a=float(input("Enter a positive number"))
        print(math.sqrt(a))
    elif x==5:
        a=float(input("Enter the number"))
        print(math.log(a,(math.e)))
    elif x==6:
        a=float(input("Enter the power"))
        print(math.exp(a))
else:
    print("Wrong input")
        
        

