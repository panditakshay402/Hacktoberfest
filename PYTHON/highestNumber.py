def find_highest_number():
    # Get input from the user
    try:
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        num3 = float(input("Enter the third number: "))
    except ValueError:
        print("Invalid input. Please enter numeric values.")
        return

    # Find the highest number
    highest = max(num1, num2, num3)

    # Print the result
    print(f"The highest number is: {highest}")

# Call the function to find the highest number
find_highest_number()