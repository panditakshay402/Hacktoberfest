''''WAP to create the file to store even numbers from user'''
myfile=open(r'numbers.txt','w')
jk=int(input("Enter the limit of numbers : "))
for i in range(jk):
    val=int(input("Enter the no = "))
    myfile.write(str(val))
    myfile.write(" ")

myfile.close()
myfile=open(r'numbers.txt','r')
print(myfile.read())

file1=open(r'even.txt','w')
file2=open(r'odd.txt','w')
data=myfile.read()
List=data.split(' ')
print(List)
for line in List:
    # if(int(line)%2==0):
    #     file1.write(f'{line}\n')
    # else:
    #     file2.write(f'{line}\n')
    print(line , end=' ')

myfile.close()


