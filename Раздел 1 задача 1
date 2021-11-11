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
		cout << "Äâåðü Îòêðûòà.\n"; 
		cout << "Ââåäèòå íîìåð äåéñòâèÿ:\n";
		cout << "1. Âîéòè â êîìíàòó.\n";
		cout << "2. Çàêðûòü äâåðü. \n";

		while (true)
			{
			cin >> b;
				if (b == 1)
				{
					cout << "Â êîìíàòå íè÷åãî èíòåðåñíîãî, äàâàéòå çàêðîåì äâåðü. \n";
					continue;
				}
				else if ((b > 2) || (b < 1))
				{
					cout << "Òàêîãî äåéñòâèÿ íå ïðåäóñìîòðåííî, ïîïðîáóé åù¸ ðàç. \n";
					continue;
				}
				else cout << "Ââåäèòå ÷åòûðåõçíà÷íûé êîä. \n";
				break;
			}

		while (true)
			{		
			cin >> N;
			Code = N;
				if (Code < 1000 || Code > 9999)
				{
					cout << "Îøèáêà. Êîä íå ÷åòûðåõçíà÷íûé. \n\n";
					continue;
				}
				else
				{
					cout << "\nÄâåðü çàïåðòà. \n\n";
					break;
				}
			}
		
		cout << "Ââåäèòå íîìåð äåéñòâèÿ:\n";
		cout << "1. Óéòè.\n";
		cout << "2. Ïîïðîáîâàòü îòêðûòü äâåðü. \n";
		
		while (true)
		{
			cin >> c;
			if (c == 1)
			{
				exit;
			}
			else if ((c > 2) || (c < 1))
			{
				cout << "Òàêîãî äåéñòâèÿ íå ïðåäóñìîòðåííî, ïîïðîáóé åù¸ ðàç. \n";
				continue;
			}
			else cout << "Ââåäèòå ÷åòûðåõçíà÷íûé êîä. \n";
			break;
		}

		while (true)
		{
			cin >> N;
			Code2 = N;
			if (Code2 < 1000 || Code2 > 9999)
			{
				cout << "Îøèáêà. Êîä íå ÷åòûðåõçíà÷íûé. \n";
				continue;
			}
			else if (Code == Code2)
			{
				cout << "Äâåðü îòêðûòà";
				break;
			}
			else
			{
				cout << "Îøèáêà. Íå âåðíûé êîä. \n";
				cout << "Äâåðü çàïåðòà. \n";
				continue;
			}
		}
		exit;
	}
	else cout << "Äâåðü çàïåðòà. Áåç êîäà íàì òóäà íå ïîïàñòü. \n\n";
	
	
		
	return 0;


}
