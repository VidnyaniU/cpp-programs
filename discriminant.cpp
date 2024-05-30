#include <bits/stdc++.h>
using namespace std;
int get_discriminant(int a, int b, int c, int h, int g, int f)
{

    return (a * (b * c - f * f) - h * (h * c - g * f) + g * (h * f - g * b));
}
void equation_representation(int a, int b, int c, int h, int g, int f)
{
    int discriminant = get_discriminant(a, b, c, h, g, f);
    int coef = (a * b) - (h * h);
    if (discriminant != 0)
    {
        if (coef < 0 && c == 0)
            cout << "Circle" << endl;
        else if (coef > 0)
            cout << "Ellipse" << endl;
        else if (coef < 0)

            cout<< "Hyperbola" << endl;
        else
            cout << "Parabola" << endl;
    }
    else
    {
        if (coef > 0)
            cout << "Two imaginary lines" << endl;

        else if (coef < 0)
            cout << "Two real parallel lines" << endl;
        else
            cout << "Two  real intersecting lines" << endl;
    }
}
int main()
{
    int a = 9, b = 4, c = 0, h = 15, g = -8, f = -40;
    equation_representation(a, b, c, h, g, f);
    return 0;
}