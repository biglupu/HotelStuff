#include <iostream>
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <cstdlib> 
#include <ctime>
#include <string>
using namespace std;

int huonenumf(int, int, bool[], int);


struct vieras {
	string nimi = "Tyhjä";
	int huonekoko = 0;
	int aamupala = 0;
	int nights = 0;
	double hinta = 0;
	int huonenumero = 0;
	long int varausnumero = 0;
	
};



int yksikaksicheck(int);
int yksikaksicheck(int testinumero)
{
	bool yksikaksicheck;
	do
	{
		yksikaksicheck = false;

		cin >> testinumero;
		if (cin.fail())
		{
			system("CLS");
			cout << "Virhe. Anna syöte uudestaan!" << endl;
			yksikaksicheck = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		else if (testinumero != 2 && testinumero != 1)
		{
			system("CLS");
			cout << "Virhe. Anna syöte uudestaan!" << endl;
			yksikaksicheck = true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (yksikaksicheck == true);

	cin.clear();
	return testinumero;
}


vieras luovaraus(int huonenmb, int vieraat)
{
	srand(time(0));
	vieras v;
	cin.clear();
	cout << "Anna nimi jolla varaus tehdään: \n";
	cin.ignore(1);
	cin.clear();
	getline(cin, v.nimi);
	v.nimi = v.nimi.substr(0, 30);

	int aamupala=0;
	cout << "Halutaanko ostaa aamupalan tilauksen yhteydessä? Syötä 1 kyllä, 2 ei\n";
	v.aamupala=yksikaksicheck(aamupala);
	v.huonekoko = vieraat;
	cout << "Montako yötä viivytään (1-14)\n";
	cin >> v.nights;

	v.varausnumero = (huonenmb+7777)*9;
	if (v.huonekoko == 1)
	{
		v.hinta = v.nights * 100;
	}

	else
	{
		v.hinta = v.nights * 150;
	}

	double alennus = rand() % 3 + 1;
	alennus = (10 - alennus) / 10;
	v.hinta = v.hinta * alennus;
	if (v.aamupala == 1)
	{
		v.hinta = v.hinta + v.nights * 5;
	}


	return v;
};





int main() 
{
	setlocale(LC_ALL, "fi_FI");

	vieras v;
	//vaihe 0, Intro ja huonekannan nollaus, loopin aloitus

	vieras vieraslista[300];
	bool huonekanta[300] = { 0 };
	string nimihaku;
	srand(time(0));
	int huoneet = rand() % 260 + 40;
	huoneet = huoneet / 2 * 2;
	int huonehaku;
	int vieraslukumaara=0;
	bool softaloop=true;
	int toimenpide; //menuvalinta
	int hakutoimenpide; //Kohdan 3 sub-menu
	int numberOfNotEmpties = 0;
	

	cout << "Tervetuloa käyttämään hotellin varausjärjetelmää. \n\n";

	
	do
	{
		for (int j = 0; j < 300; j++)
		{
			if (vieraslista[j].nimi != "Tyhjä")
			{
				numberOfNotEmpties++;

			}
		}
		

		bool menuerror;
		do
		{
			menuerror = false;
			cout << "\nVapaita huoneita " << huoneet - numberOfNotEmpties;
			cout << "\n\n------\nPÄÄVALIKKO\n------\nSyötä 1 Uuden huonevarauksen luomiseksi.\nSyötä 2 Vieraan uloskirjaamiseen\nSyötä 3 Hakeaksesi varausta \n\Syötä 4 Listataksesi kaikki varatut huoneet\nSyötä 5 ohjelman sulkemiseksi ja tietokannan nollaamiseksi\n\n";
			cin >> toimenpide;
			if (cin.fail())
			{
				system("CLS");
				cout << "Virheellinen valinta. Anna syöte uudestaan!" << endl;
				menuerror = true;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			else if (toimenpide != 1 && toimenpide != 2 && toimenpide != 3 && toimenpide != 4 && toimenpide != 5)
			{
				system("CLS");
				cout << "Virheellinen valinta. Anna syöte uudestaan!" << endl;
				menuerror = true;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		} while (menuerror == true);

		system("CLS");
		if (toimenpide == 1)
		{

			cout << "Huonevarauksen luonti \n\nKuinka iso suuri huone varataan? \nYhden vai kahden hengen huone: Syötä 1 tai 2\n";
			vieraslukumaara = yksikaksicheck(vieraslukumaara);
			cout << "\nVieraiden lukumäärä: " << vieraslukumaara << endl;
			int huonenumero = 0;

			huonenumero = huonenumf(huonenumero, vieraslukumaara, huonekanta, huoneet);
			vieraslista[huonenumero] = luovaraus(huonenumero, vieraslukumaara);
			system("CLS");
			cout << "Varauksen tiedot: \n\n";
			cout << "Huone numero: " << huonenumero << endl;
			cout << "Varauksen nimi: " << vieraslista[huonenumero].nimi << endl;
			cout << "Varausnumero " << vieraslista[huonenumero].varausnumero << endl;
			cout << "Huonekoko: " << vieraslista[huonenumero].huonekoko << endl;
			cout << "Montako yötä viivytään: " << vieraslista[huonenumero].nights << endl;
			cout << "Aamupala: ";
			if (vieraslista[huonenumero].aamupala == 1)
			{
				cout << "kyllä" << endl;
			}
			else
			{
				cout << "Ei" << endl;
			}

			cout << "Hinta: " << vieraslista[huonenumero].hinta << " euroa" << endl;
		}

		if (toimenpide == 2)
		{
			int huoneUlos;
			cout << "Anna uloskirjattavan huoneen numero\n";

			cin.clear();
			bool uloscheck;
			do
			{
				uloscheck = false;

				cin >> huoneUlos;;
				if (cin.fail())
				{
					system("CLS");
					cout << "Virhe. Anna syöte uudestaan!" << endl;
					uloscheck = true;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				else if (huoneUlos < 1 || huoneUlos > 300)
				{
					system("CLS");
					cout << "Virhe. Anna syöte uudestaan!" << endl;
					uloscheck = true;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

			} while (uloscheck == true);


			cout << "\nHuone " << huoneUlos << endl;
			cout << "Vieras-status/Vieraan nimi: \"" << vieraslista[huoneUlos].nimi << "\"" << endl;
			cout << "Huonekoko/Vieraiden määrä: " << vieraslista[huoneUlos].huonekoko << endl;
			cout << "\nKirjataanko vieras ulos? \nPaina 1 kirjataksesi vieraan ulos. \nPaina 2 jos et halua kirjata vierasta ulos\n";
			int menepois = 1; //uloskirjausvarmistus
			menepois = yksikaksicheck(menepois);
			if (menepois == 1)
			{
				vieraslista[huoneUlos].nimi = "Tyhjä";
				vieraslista[huoneUlos].huonekoko = 0;
				vieraslista[huoneUlos].nights = 0;
				vieraslista[huoneUlos].aamupala = 0;
				huonekanta[huoneUlos] = 0;
				cout << "\nVieras kirjattu ulos";
			}
			else
			{
				cout << "Uloskirjaus keskeytetty";
			}
		}

		if (toimenpide == 3)
		{

			hakutoimenpide = 0;
			bool hakuerror;
			do
			{
				hakuerror = false;
				cout << "Haetaanko nimellä, huonenumerolla vai varausnumerolla?\n \n1 Nimihaku\n2 Huonenumerohaku \n3 Varausnumerohaku. \n4 Palataaksesi päävalikkoon\n\n";
				cin >> hakutoimenpide;
				if (cin.fail())
				{
					system("CLS");
					cout << "Virheellinen valinta. Anna syöte uudestaan!" << endl;
					hakuerror = true;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				else if (hakutoimenpide != 1 && hakutoimenpide != 2 && hakutoimenpide != 3 && hakutoimenpide != 4)
				{
					system("CLS");
					cout << "Virheellinen valinta. Anna syöte uudestaan!" << endl;
					hakuerror = true;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

			} while (hakuerror == true);

			if (hakutoimenpide == 1)
			{
				cout << "Nimihaku. Ole hyvä ja anna varauksen nimi\n";
				cin.ignore(1);
				cin.clear();
				getline(cin, nimihaku);
				v.nimi = v.nimi.substr(0, 30);
				for (int i = 0; i < 300; i++)
				{
					if (vieraslista[i].nimi == nimihaku)
					{
						cout << "Varauksen nimi: " << vieraslista[i].nimi << endl;
						cout << "Huonekoko: " << vieraslista[i].huonekoko << endl;
						cout << "Öiden määrä: " << vieraslista[i].nights << endl;
						cout << "Huoneen numero, " << i << endl;
						cout << "Aamupala: ";
						if (vieraslista[i].aamupala == 1)
						{
							cout << "kyllä" << endl;
						}
						else
						{
							cout << "Ei" << endl;
						}

					}

				}

				cout << "\nKaikki tulokset haulla nimellä \"" << nimihaku << "\" näytetty\n";
			}

			else if (hakutoimenpide == 2)
			{
				cout << "Huonehaku. Syötä huonenumero: \n";
				bool huonehakucheck;
				do
				{
					huonehakucheck = false;

					cin >> huonehaku;;
					if (cin.fail())
					{
						system("CLS");
						cout << "Virhe. Anna syöte uudestaan! Huoneita on välillä 1-" << huoneet << endl;
						huonehakucheck = true;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					else if (huonehaku < 1 || huonehaku > huoneet)
					{
						system("CLS");
						cout << "Virhe. Anna syöte uudestaan! Huoneita on välillä 1-" << huoneet << endl;
						huonehakucheck = true;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}


				} while (huonehakucheck == true);

				cout << "Huone numero: " << huonehaku << endl;

				cout << "Vieras status " << vieraslista[huonehaku].nimi << endl;
				if (vieraslista[huonehaku].nimi != "Tyhjä")
				{
					cout << "Kuinka monta yötä viivytään " << vieraslista[huonehaku].nights << endl;
					cout << "Aamupala: ";
					if (vieraslista[huonehaku].aamupala == 1)
					{
						cout << "kyllä" << endl;
					}
					else
					{
						cout << "Ei" << endl;
					}
				}
				cout << "Huoneen " << huonehaku << " tiedot näytetty\n";
			}
			else if (hakutoimenpide == 3)
			{
				int Varausnumerohaku;
				cout << "Varausnumerohaku. Syötä varausnumero: \n";
				cin >> Varausnumerohaku;
				for (int i = 0; i < 300; i++)
				{
					if (vieraslista[i].varausnumero == Varausnumerohaku)
					{
						cout << "Varauksen nimi: " << vieraslista[i].nimi << endl;
						cout << "Huonekoko: " << vieraslista[i].huonekoko << endl;
						cout << "Öiden määrä: " << vieraslista[i].nights << endl;
						cout << "Huoneen numero, " << i << endl;
						cout << "Aamupala: ";
						if (vieraslista[i].aamupala == 1)
						{
							cout << "kyllä" << endl;
						}
						else
						{
							cout << "Ei" << endl;
						}

					}

				}
			}
			else
			{
				system("CLS");
				cout << "Palattu valikkoon";
			}
		}




			if (toimenpide == 4)
			{
				cout << "Käytössä olevat huoneet: \n";
				for (int j = 0; j < 300; j++)
				{
					if (vieraslista[j].nimi != "Tyhjä")
					{
						cout << j << endl;

					}
				}
				cout << "\n\nkäytössä olevat huoneet listattu\n";
			}




			if (toimenpide == 5)
			{
				cout << "Ohjelma suljettu";
				softaloop = false;
				break;
			}
		} while (softaloop == true);

	
	return 0;
}

