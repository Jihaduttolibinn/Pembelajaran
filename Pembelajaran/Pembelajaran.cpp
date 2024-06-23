














#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Perusahaan;
class Karyawan {
public:
	string nama;

	vector<Perusahaan*>daftar_perusahaan;
	Karyawan(string pNama) :nama(pNama) {
		cout << "Karyawan\"" << nama << "\"ada\n";
	}
	void tambahPerusahaan(Perusahaan*);
	void cetakPerusahaan();
};

class Perusahaan {
public:
	string nama;
	vector<Karyawan*>daftar_karyawan;
	Perusahaan(string pNama) :nama(pNama) {
		cout << "Perusahaan\"" << nama << "\ada\n";
	}
	void tambahKaryawan(Karyawan*);
	void cetakKaryawan();
};

void Karyawan::tambahPerusahaan(Perusahaan* pPerusahaan) {
	daftar_perusahaan.push_back(pPerusahaan);
}

void Karyawan::cetakPerusahaan() {
	cout << "Daftar perusahaan yang memiliki karyawan\"" << this->nama << "\":\n";
	for (auto& a : daftar_perusahaan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void Perusahaan::tambahKaryawan(Karyawan* pKaryawan) {
	daftar_karyawan.push_back(pKaryawan);
	pKaryawan->tambahPerusahaan(this);
}

void Perusahaan::cetakKaryawan() {
	cout << "Daftar karyawan dari perusahaan\"" << this->nama << "\":\n";
	for (auto& a : daftar_karyawan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	Perusahaan* varPerusahaan = new Perusahaan("PT Maju Mundur");
	Karyawan* varKaryawan1 = new Karyawan("Budi");
	Karyawan* varKaryawan2 = new Karyawan("Andi");

	varPerusahaan->tambahKaryawan(varKaryawan1);
	varPerusahaan->tambahKaryawan(varKaryawan2);

	varPerusahaan->cetakKaryawan();
	varKaryawan1->cetakPerusahaan();
	varKaryawan2->cetakPerusahaan();

	delete varKaryawan1;
	delete varKaryawan2;
	delete varPerusahaan;

	return 0;
}