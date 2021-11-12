#include <iostream>
using namespace std;



class Door {

	bool doorIsOpen = false;		//Переменная, которая определяет открыта ли дверь
	int code = 0;				//Переменная, которой присваивается числовой код
	bool codeIsSeted = false;		//Переменная, которая определяет установлен ли код

	
	void enterCode()
	{
		int enteredCode;
		cout << "Введите код: ";
		cin >> enteredCode;

		if (enteredCode == code)
		{
			codeIsSeted = false;
			doorIsOpen = true;
			cout << endl;
		}
		else
		{
			cout << "\nВведен неверный код!\n\n";
		}
	}

public:

	
	void openDoor()
	{
		if (doorIsOpen)
		{
			cout << "Дверь уже открыта!\n\n";
			return;
		}

		if (codeIsSeted)
			enterCode();

		if (!codeIsSeted)
		{
			doorIsOpen = true;
			cout << "Вы открыли дверь!\n\n";
		}
	}

	
	void closeDoor()
	{
		if (!doorIsOpen)
		{
			cout << "Дверь уже закрыта!\n\n";
			return;
		}

		doorIsOpen = false;
		cout << "Вы закрыли дверь!\n\n";
	}

	
	void setCode()
	{
		if (doorIsOpen)
		{
			cout << "Невозможно установить код, так как дверь открыта!\n\n";
			return;
		}

		
		if (codeIsSeted)
		{
			cout << "Код уже установлен!\n\n";
			return;
		}

		cout << "Установите новый числовой код: ";
		cin >> code;
		codeIsSeted = true;
		cout << "\nКод успешно установлен!\n\n";
	}
};



int main()
{
	setlocale (LC_CTYPE, "Russian"); 

	Door door; 
	int choice; 

	
	while (true)
	{
		system("cls");
		cout << "1.Открыть дверь\n";
		cout << "2.Закрыть дверь\n";
		cout << "3.Установить числовой код\n\n";
		cout << "0.Выход\n\n";
		cout << "Выберите действие: ";
		cin >> choice;

		if (choice == 1)
		{
			system("cls");		// Очищает консоль
			door.openDoor();	// Выполняем метод
			system("pause");	// Ставим на паузу и ждём следующего действия
		}
		if (choice == 2)
		{
			system("cls");
			door.closeDoor();
			system("pause");
		}
		if (choice == 3)
		{
			system("cls");
			door.setCode();
			system("pause");
		}
		if (choice == 0)
		{
			system("cls");
			exit(0);
			system("pause");
		}
	}
}
