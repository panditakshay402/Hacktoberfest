#include <iostream>
using namespace std;

int main(){

    // creating 3 variables to side the 3 sides of the triangle
    double side1, side2, side3;
    
    // taking user input, side 1
    cout << "Enter side 1: ";
    cin >> side1;
    
    // taking user input, side 2
    cout << "Enter side 2: ";
    cin >> side2;

    // taking user input, side 3
    cout << "Enter side 3: ";
    cin >> side3;

    if ((side1 == side2) && (side2 == side3))
        cout << "The triangle is Equilateral\n";
    else
        cout << "The Triangle is not Equilateral\n";


    return 0; 
}

// Explaination
/*

inside main()

line-7 : creating variables side1, side2, side3 to store the sides of the triangle

line-10 to line-19 : taking input from the user, the user has to input 3 sides of the triangle.

line-21 : checking whether the sides are equal or not,
            if equal then print "The triangle is Equilateral"
            else print "The Triangle is not Equilateral"

*/