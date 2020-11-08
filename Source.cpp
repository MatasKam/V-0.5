#include "duomenys.h"

int main()
{
	auto start = high_resolution_clock::now();
	duomenys D;
	ifstream klasiokai;
	klasiokai.open("studentai.txt");

	try {
		if (klasiokai.is_open())
		{
			klasiokai >> D.var >> D.pav;
			while (D.q != "Egz.") // perskaito visus namu darbus kiek ju yra
			{
				klasiokai >> D.q;
				if (D.q == "Egz.") {
					break;
				}
				D.kiek.push_back(D.q);
			}
			D.ilgis = D.kiek.size();




			auto startt = high_resolution_clock::now();
			while (!klasiokai.eof())
			{
				klasiokai >> D.vardas >> D.pavarde;
				int xxx;
				for (int i = 1; i <= D.ilgis; i++)
				{
					klasiokai >> xxx;
					D.ndp.push_back(xxx);

				}
				klasiokai >> D.egzp;
				sort(D.ndp.begin(), D.ndp.end());
				D.galbal = (double)accumulate(D.ndp.begin(), D.ndp.end(), 0) / D.ndp.size() * 0.4 + D.egzp * 0.6;

				if (D.ndp.size() % 2 != 0)
				{
					D.med = (double)D.ndp[D.ndp.size() / 2];
				}
				else
				{
					D.med = (double)(D.ndp[(D.ndp.size() - 1) / 2] + D.ndp[D.ndp.size() / 2]) / 2.0;
				}

				D.ndp.clear();
				if (D.galbal < 5)
				{
					D.gaidz.push_back(D);
				}
				else
				{
					D.mldc.push_back(D);
				}
			}
			duration<double> di = high_resolution_clock::now() - startt;
			cout << "skirstymas i dvi grupes ir skaiciavimas truko: " << di.count() << endl;
			rasom(D.gaidz);
			rasomp(D.mldc);
		}
	}
	catch (const ifstream::failure& e) 
	{
		cout << "Nepavyko atidaryti failo";
	}
	klasiokai.close();

	duration<double> diff = high_resolution_clock::now() - start;
	cout << "viso failo skaitymas truko: " << diff.count() << endl;



	return 0;
}