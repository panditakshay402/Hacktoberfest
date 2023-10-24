#include <iostream>

class box
{
    double height, width, depth;

public:
    box()
    {
        height = width = depth = 0;
    }
    box(double length)
    {
        height = width = depth = length;
    }
    box(double h,double w,double d)
    {
        height = h;
        width = w;
        depth = d;
    }
    void show()
    {
        std::cout << "Height = " << height;
        std::cout << "\n";
        std::cout << "Width = " << width;
        std::cout << "\n";
        std::cout << "Depth = " << depth;
        std::cout << "\n";
    }
};

int main()
{
    box b1(10,20,10);
    box b2(25);
    box b3;
    b1.show();
    std::cout << "\n------------------\n";
    b2.show();
    std::cout << "\n------------------\n";
    b3.show();
}