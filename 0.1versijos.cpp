#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <conio.h>
#include <stdio.h>
using namespace std;
struct User {
	char name[20];	//Vardas
	char sname[20];	//Pavarde
	int n;			//Kiekis padarytu namu darbu
	int nd[50];		//Balai uz namu darbu
	vector<int> nd1;
	int egz;		//Egzamenas
	double ig;		//Galutinis
	double avg;		//Vidutinis
	double med;		//Mediana
};
const int N = 50;	//Maksimalus studentu kiakis
void Z1() {
	User std[N];
	int n;
	cout << "Pateikite informacija apie keliu studentu ivesite: ";
	(cin >> n).get();
	for (int i = 0; i < n; i++) {
		cout << "Ivedame informcija " << i + 1 << "o(es) studento:" << endl;
		cout << "Vardas: ";
		cin.getline(std[i].name, 20);
		cout << "Pavarde: ";
		cin.getline(std[i].sname, 20);
		cout << "Kiekis padarytu namu darbu: ";
		cin >> std[i].n;
		cout << "Rezultatai is " << std[i].n << " namu darbu (per tarpa):" << endl;
		std[i].avg = 0;
		for (int j = 0; j < std[i].n; j++) {
			cin >> std[i].nd[j];
			std[i].avg += std[i].nd[j]; //suzinome balu suma
		}
		cout << "Egzameno rezultatas: ";
		(cin >> std[i].egz).get();
		std[i].avg /= std[i].n; 						 //suzinome vidurki
		std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz; //suzinome galutini bala
	}
	printf("%20s%20s%30s\n", "Vardas", "Pavarde", "Galutinis (vidurkis)");
	printf("----------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%20s%20s%30.2lf\n", std[i].name, std[i].sname, std[i].ig);
	}
	cout << endl;
	system("pause");
}
void Z2() {
	User std[N];
	int n;
	cout << "Pateikite informacija apie keliu studentu ivesime: ";
	(cin >> n).get();
	for (int i = 0; i < n; i++) {
		cout << "Ivedimas apie " << i + 1 << "o(es) studento:" << endl;
		cout << "Vardas: ";
		cin.getline(std[i].name, 20);
		cout << "Pavarde: ";
		cin.getline(std[i].sname, 20);
		cout << "Kiekis atliktu namu darbu: ";
		cin >> std[i].n;
		cout << "Rezultatai is " << std[i].n << " namu darbu (per tarpa):" << endl;
		std[i].avg = 0;
		for (int j = 0; j < std[i].n; j++) {
			cin >> std[i].nd[j];
			std[i].avg += std[i].nd[j]; //Suzinome balu suma
		}
		cout << "Egzameno rezultatas: ";
		(cin >> std[i].egz).get();
		std[i].avg /= std[i].n; 						 //suzinome vidutini bala
		std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz; //suzinome galutini ezultata
		for(int k = 0; k < std[i].n - 1; k++) {
			for(int j = k + 1; j < std[i].n; j++) {
				if (std[i].nd[k] > std[i].nd[j]) {
					int t = std[i].nd[k];
					std[i].nd[k] = std[i].nd[j];
					std[i].nd[j] = t;
				}
			}
		}
		int k = std[i].n / 2;
		if (std[i].n % 2 != 0)
			std[i].med = std[i].nd[k];
		else
			std[i].med = (std[i].nd[k] + std[i].nd[k - 1]) / 2.0;
	}
	printf("%12s%12s%27s%27s\n", "Vardas", "Pavarde", "Galutinis (vidurkis)", "Galutinis (mediana)");
	printf("------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%12s%12s%27.2lf%27.2lf\n", std[i].name, std[i].sname, std[i].ig, std[i].med);
	}
	cout << endl;
	system("pause");
}
void Z3_1() {
	User std[N];
	int n;
	cout << "Pateikite informacija apie keliu studentu ivesite: ";
	(cin >> n).get();
	for (int i = 0; i < n; i++) {
		cout << "Iveskite informacija apie " << i + 1 << "-o(es) studento:" << endl;
		cout << "Vardas: ";
		cin.getline(std[i].name, 20);
		cout << "Pavarde: ";
		cin.getline(std[i].sname, 20);
		std[i].n = 0;
		cout << "Rezultatai is namu darbu (per tarpa, ivedimo pabaiga 0):" << endl;
		std[i].avg = 0;
		int x;
		do {
			cin >> x;
			if (x > 0) {
				std[i].nd[std[i].n] = x;
				std[i].avg += std[i].nd[std[i].n]; //suzinome balu suma
				std[i].n++;
			}
		} while (x > 0);
		cout << "Egzameno rezultatas: ";
		(cin >> std[i].egz).get();
		std[i].avg /= std[i].n; 						 //suzinome vidutini bala
		std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz; //suzinojome galutini bala
		for(int k = 0; k < std[i].n - 1; k++) {
			for(int j = k + 1; j < std[i].n; j++) {
				if (std[i].nd[k] > std[i].nd[j]) {
					int t = std[i].nd[k];
					std[i].nd[k] = std[i].nd[j];
					std[i].nd[j] = t;
				}
			}
		}
		int k = std[i].n / 2;
		if (std[i].n % 2 != 0)
			std[i].med = std[i].nd[k];
		else
			std[i].med = (std[i].nd[k] + std[i].nd[k - 1]) / 2.0;
	}
	printf("%12s%12s%27s%27s\n", "Vardas", "Pavarde", "Galutinis (vidurkis)", "Galutinis (mediana)");
	printf("------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%12s%12s%27.2lf%27.2lf\n", std[i].name, std[i].sname, std[i].ig, std[i].med);
	}
	cout << endl;
	system("pause");
}
void Z3_2() {
	User std[N];
	int n;
	cout << "Pateikite informacija apie keliu studentu ivesite: ";
	(cin >> n).get();
	for (int i = 0; i < n; i++) {
		cout << "Informacija apie " << i + 1 << " o(es) studento:" << endl;
		cout << "Vardas: ";
		cin.getline(std[i].name, 20);
		cout << "Pavarde: ";
		cin.getline(std[i].sname, 20);
		cout << "Rezultatai is namu darbu(per tarpa, ivedimo baigimas 0):" << endl;
		std[i].avg = 0;
		int x;
		do {
			cin >> x;
			if (x > 0) {
				std[i].nd1.push_back(x); //perkelem elementa i vektorio gala
				std[i].avg += std[i].nd1[std[i].nd1.size() - 1]; //suzinome balu suma
			}
		} while (x > 0);
		cout << "Egzameno rezultatas: ";
		(cin >> std[i].egz).get();
		std[i].avg /= std[i].nd1.size();					 //vidurkis
		std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz; //galutinis balas
		for(int k = 0; k < std[i].nd1.size() - 1; k++) {
			for(int j = k + 1; j < std[i].nd1.size(); j++) {
				if (std[i].nd1[k] > std[i].nd1[j]) {
					int t = std[i].nd1[k];
					std[i].nd1[k] = std[i].nd1[j];
					std[i].nd1[j] = t;
				}
			}
		}
		int k = std[i].nd1.size() / 2;
		if (std[i].nd1.size() % 2 != 0)
			std[i].med = std[i].nd1[k];
		else
			std[i].med = (std[i].nd1[k] + std[i].nd1[k - 1]) / 2.0;
	}
	printf("%12s%12s%27s%27s\n", "Vardas", "Pavarde", "Galutinis (vidurkis)", "Galutinis (mediana)");
	printf("------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%12s%12s%27.2lf%27.2lf\n", std[i].name, std[i].sname, std[i].ig, std[i].med);
	}
	cout << endl;
	system("pause");
}
int main() {
	system("chcp 1251"); // suintaliuojame koda
	char key;
	do {
		system("cls"); //nuvalome ekrana
		cout << "[1]. Uzduotys 1" << endl;
		cout << "[2]. Uzduotys 2" << endl;
		cout << "[3]. Uzduotys 3 3_1" << endl;
		cout << "[4]. Uzduotys 3_2" << endl;
		cout << "[0]. Isejimas" << endl;
		key = getch();
		system("cls"); //nuvalome ekrana
		switch (key) {
			case '1': {
				Z1();
				break;
			}
			case '2': {
				Z2();
				break;
			}
			case '3': {
				Z3_1();
				break;
			}
			case '4': {
				Z3_2();
				break;
			}
		}
	}while (key != '0');
	return 0;
}
