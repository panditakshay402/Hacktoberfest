// Understanding constructors

#include<iostream>
using namespace std;

class Rectangle
{
    int len;                    // they are private data
    int bre;

    public:
        void setLength(int l)           //to assign length
        {
            if(l >= 0)
                len = l;                
            else
                len = 0;                // for negative input length, make it zero
        }

        void setBreadth(int b)          //to assign breadth
        {
            if(b >= 0)
                bre = b;
            else
                bre = 0;
        }

        int getLength()                 //to print length
        { return len; }

        int getBreadth()                //to print breadth
        { return bre; }

        // Rectangle()                  // Unparameterized constructor
        // {
        //     len = 0;
        //     bre = 0;
        // }

        Rectangle(int l=0, int b=0)     // Parameterized constructor (takes care of unparameterized input too)
        {                               // (using the default parameters)
            setLength(l);
            setBreadth(b);
        }

        Rectangle(Rectangle &rect)      // Copy constructor (ref to another rectangle)
        {
            len = rect.len;
            bre = rect.bre;
        }
};

int main()
{
    Rectangle r;                // to call default or unparameterized
    Rectangle r1(12,18);        // to call parameterized
    Rectangle r2(r1);           // to call copy

    cout<<"Length of r is "<<r.getLength()<<endl;
    cout<<"Breadth of r1 is "<<r1.getBreadth()<<endl;
    cout<<"Breadth of r2 is "<<r2.getBreadth()<<endl;
}