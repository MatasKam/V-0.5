#include "duomenys.h"
void rasom(vector<duomenys>gg)
{
	auto start = high_resolution_clock::now();
	ofstream gaidziai;
	gaidziai.open("nekieti.txt");
	gaidziai << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(33) << "Galutinis balas (Vid.)" << setw(25) << "Galutinis (Med.)" << endl;
	gaidziai << setfill('-') << setw(90) << "-" << endl;

	for (auto& elementas : gg)
	{
		gaidziai << setfill(' ') << setw(17) << elementas.vardas << setw(20) << elementas.pavarde << setw(14) << setprecision(2) << fixed << elementas.galbal << setw(31) << setprecision(2) << fixed << elementas.med << endl;
	}
	gaidziai.close();
	duration<double> diff = high_resolution_clock::now() - start;
	cout << "nekietu mokiniu irasymas i faila truko: " << diff.count() << endl;
}
