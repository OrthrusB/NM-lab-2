#include <iostream>
#include <cmath>
using namespace std;

float Calculate(float a, float b, int x) {
    return (a * exp(b * x));
}

int main() {
    int size;
    cout << "Enter size of data: ";
    cin >> size;

    float x[size], y[size];
    float xtotal = 0, ytotal = 0, x2 = 0, xy = 0;
    float b, a;

    for (int i = 0; i < size; i++) {
        cout << "Enter value for x" << i << ": ";
        cin >> x[i];
        xtotal += x[i];
        x2 += x[i] * x[i];

        cout << "Enter value for y" << i << ": ";
        cin >> y[i];
        y[i] = log(y[i]); // Transform y values
        ytotal += y[i];
        xy += x[i] * y[i];
    }

    // Calculate coefficients
    b = (size * xy - xtotal * ytotal) / (size * x2 - xtotal * xtotal);
    a = (ytotal / size) - b * (xtotal / size);
    a = exp(a); 

    cout << "Nonlinear Regression Equation: y = " << a << " * e^(" << b << "x)" << endl;

    int val;
    cout << "Enter x: ";
    cin >> val;
    cout << "Predicted y = " << Calculate(a, b, val) << endl;

    return 0;
}
