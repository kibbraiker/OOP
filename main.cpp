#include <iostream>
#include <stdlib.h>

using namespace std;

int N = 0, i, Code, Code2;
int b, c;
bool isLocedDoor = true;

int main()
{
	
	setlocale(LC_ALL, "Russian");
	
	if (isLocedDoor)
	{
		cout << "����� �������.\n"; 
		cout << "������� ����� ��������:\n";
		cout << "1. ����� � �������.\n";
		cout << "2. ������� �����. \n";

		while (true)
			{
			cin >> b;
				if (b == 1)
				{
					cout << "� ������� ������ �����������, ������� ������� �����. \n";
					continue;
				}
				else if ((b > 2) || (b < 1))
				{
					cout << "������ �������� �� ��������������, �������� ��� ���. \n";
					continue;
				}
				else cout << "������� �������������� ���. \n";
				break;
			}

		while (true)
			{		
			cin >> N;
			Code = N;
				if (Code < 1000 || Code > 9999)
				{
					cout << "������. ��� �� ��������������. \n\n";
					continue;
				}
				else
				{
					cout << "\n����� �������. \n\n";
					break;
				}
			}
		
		cout << "������� ����� ��������:\n";
		cout << "1. ����.\n";
		cout << "2. ����������� ������� �����. \n";
		
		while (true)
		{
			cin >> c;
			if (c == 1)
			{
				exit;
			}
			else if ((c > 2) || (c < 1))
			{
				cout << "������ �������� �� ��������������, �������� ��� ���. \n";
				continue;
			}
			else cout << "������� �������������� ���. \n";
			break;
		}

		while (true)
		{
			cin >> N;
			Code2 = N;
			if (Code2 < 1000 || Code2 > 9999)
			{
				cout << "������. ��� �� ��������������. \n";
				continue;
			}
			else if (Code == Code2)
			{
				cout << "����� �������";
				break;
			}
			else
			{
				cout << "������. �� ������ ���. \n";
				cout << "����� �������. \n";
				continue;
			}
		}
		exit;
	}
	else cout << "����� �������. ��� ���� ��� ���� �� �������. \n\n";
	
	
		
	return 0;


}