#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, c, x1, x2; 
    double D; // ������������

    cout << "��������� ���� \'ax^2 + bx + c = 0\' \n";
    cout << "������� �������� a: \n"; 
    cin >> a;
    cout << "������� �������� b: \n";
    cin >> b;
    cout << "������� �������� c: \n";
    cin >> c;

    D = b * b - 4 * a * c; 
    if (D > 0) 
    {
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        cout << "����� ���������: \n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    else if (D == 0) 
    {
        x1 = -(b / (2 * a));
        cout << "������������ ����� ����, ������ ���������: \n";
        cout << "x1 = x2 = " << x1 << "\n";
    }
    else if (D < 0) 
        cout << "������������ ������ ����, ������ ��������� �� ����������.";
}