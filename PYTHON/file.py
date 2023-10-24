'''WAP to to store  the inputs from users. You will store (Product name, brand, price, quantity, Total) '''
basepath="product.txt"
mode="w"
myfile=open(basepath,mode)
product_name=input("Enter the product name : ")
brand=input("Enter the brand : ")
price=int(input("Enter the price : "))
quantity=int(input("Enter the quantity : "))
total=price*quantity
myfile.write(f'Product name = {product_name}\n')
myfile.write(f'Brand name = {brand}\n')
myfile.write(f'Price = {price}\n')
myfile.write(f'Quantity = {quantity}\n')
myfile.write(f'Total  = {total}\n\n')
myfile.close()