#include <iostream>
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime>
#include <string>
using namespace std;




int huonenumf(int h, int v, bool hkanta[], int huonemax)
{

	cout << "\nHuonenumeron valinta.\nHuoneet 1-" << huonemax / 2 << " ovat yhden hengen huoneita, ja huoneet " << huonemax / 2 + 1 << "-" << huonemax << " ovat kahden hengen huoneita.";

	bool virhe3;
	do
	{
		virhe3 = false;
		cout << "\nSyöttäkää haluamanne huonenumero tai painakaa 0 \n";
		cin >> h;


		if (cin.fail())
		{
			cout << "virheellinen syöte, anna luku uudestaan" << endl;
			virhe3 = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (h == 0)
		{
			break;
		}

		else if (v == 1 && h > huonemax / 2)
		{
			if (h == 0)
			{
				break;
			}
			cout << "\nvirhe, antakaa luku väliltä " << 1 << "-" << huonemax / 2;
			virhe3 = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if (h < 0)
		{
			if (h == 0)
			{
				break;
			}
			cout << "\nvirhe, antakaa luku väliltä  " << 1 << "-" << huonemax / 2;
			virhe3 = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if (v == 2 && h <= huonemax / 2)
		{
			if (h == 0)
			{
				break;
			}
			cout << "\nvirhe, antakaa luku väliltä " << huonemax / 2 + 1 << "-" << huonemax;
			virhe3 = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if (h > huonemax)
		{
			if (h == 0)
			{
				break;
			}
			cout << "\nvirhe, antakaa luku väliltä " << huonemax / 2 << "-" << huonemax;
			virhe3 = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if (hkanta[h] == 1)
		{
			cout << "Huone jo varattu, valitkaa toinen huone\n";
			virhe3 = true;
		}


	} while (virhe3);

	do
	{
		if (h == 0) //arvotaan huonenumero
		{
			if (v == 1)
			{
				h = rand() % huonemax / 2;

			}
			else //jos v siis == 2
			{
				h = rand() % huonemax / 2 + huonemax / 2;

			}
		}
	} while (hkanta[h] == 1);

	hkanta[h] = 1;

	return h;
}
