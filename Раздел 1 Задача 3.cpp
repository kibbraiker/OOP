#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, c, x1, x2; 
    double D; // Дискриминант

    cout << "Уравнение вида \'ax^2 + bx + c = 0\' \n";
    cout << "Введите значение a: \n"; 
    cin >> a;
    cout << "Введите значение b: \n";
    cin >> b;
    cout << "Введите значение c: \n";
    cin >> c;

    D = b * b - 4 * a * c; 
    if (D > 0) 
    {
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        cout << "Корни уравнения: \n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    else if (D == 0) 
    {
        x1 = -(b / (2 * a));
        cout << "Дискриминант равен нулю, корень уровнения: \n";
        cout << "x1 = x2 = " << x1 << "\n";
    }
    else if (D < 0) 
        cout << "Дискриминант меньше нуля, корней уравнения не существует.";
}
