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
		cout << "Дверь Открыта.\n"; 
		cout << "Введите номер действия:\n";
		cout << "1. Войти в комнату.\n";
		cout << "2. Закрыть дверь. \n";

		while (true)
			{
			cin >> b;
				if (b == 1)
				{
					cout << "В комнате ничего интересного, давайте закроем дверь. \n";
					continue;
				}
				else if ((b > 2) || (b < 1))
				{
					cout << "Такого действия не предусмотренно, попробуй ещё раз. \n";
					continue;
				}
				else cout << "Введите четырехзначный код. \n";
				break;
			}

		while (true)
			{		
			cin >> N;
			Code = N;
				if (Code < 1000 || Code > 9999)
				{
					cout << "Ошибка. Код не четырехзначный. \n\n";
					continue;
				}
				else
				{
					cout << "\nДверь заперта. \n\n";
					break;
				}
			}
		
		cout << "Введите номер действия:\n";
		cout << "1. Уйти.\n";
		cout << "2. Попробовать открыть дверь. \n";
		
		while (true)
		{
			cin >> c;
			if (c == 1)
			{
				exit;
			}
			else if ((c > 2) || (c < 1))
			{
				cout << "Такого действия не предусмотренно, попробуй ещё раз. \n";
				continue;
			}
			else cout << "Введите четырехзначный код. \n";
			break;
		}

		while (true)
		{
			cin >> N;
			Code2 = N;
			if (Code2 < 1000 || Code2 > 9999)
			{
				cout << "Ошибка. Код не четырехзначный. \n";
				continue;
			}
			else if (Code == Code2)
			{
				cout << "Дверь открыта";
				break;
			}
			else
			{
				cout << "Ошибка. Не верный код. \n";
				cout << "Дверь заперта. \n";
				continue;
			}
		}
		exit;
	}
	else cout << "Дверь заперта. Без кода нам туда не попасть. \n\n";
	
	
		
	return 0;


}
