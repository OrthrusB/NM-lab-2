#include <iostream>
#include <vector> 
using namespace std;

float Calculate(float a, float b, int x) {
    return (a + b * x);
}

int main() {
    int size;
    cout << "Enter size of data: ";
    cin >> size;

    
    vector<float> x(size), y(size);
    float xtotal = 0, ytotal = 0, x2 = 0, xy = 0; 

    for (int i = 0; i < size; i++) {
        cout << "Enter value for x" << i << ": ";
        cin >> x[i];
        xtotal += x[i];
        x2 += x[i] * x[i];

        cout << "Enter value for y" << i << ": ";
        cin >> y[i];
        ytotal += y[i];
        xy += x[i] * y[i];
    }

    float b = (size * xy - xtotal * ytotal) / (size * x2 - xtotal * xtotal);
    float a = (ytotal / size) - b * (xtotal / size);

    cout << "Linear Regression Equation: y = " << a << " + " << b << " * x" << endl;

    int val;
    cout << "Enter x: ";
    cin >> val;
    cout << "Predicted y = " << Calculate(a, b, val) << endl;

    return 0;
}
