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
	int nd[50];		//Namu darbai
	int egz;		//Egzamenas
	double ig;		//Galutinis
	double avg;		//Vidutinis
	double med;		//Mediana
};
const int N = 50;	//Maksimalus studentu kiekis
int main() {
	system("chcp 1251"); // suinstaliojame kodiruote
	system("cls"); //nuvalome ekrana
	User std[N];
	char buf[10];
	int n, x;
	cout << "Informacija apie keliu studentu generuosime: ";
	(cin >> n).get();
	cout << "Rezultatai is keliu namu darbu : ";
	(cin >> x).get();
	for (int i = 0; i < n; i++) {
		itoa(i + 1, buf, 10);
		//std[i].name[0] = '\0';
		strcpy(std[i].name, "Vardas:");
		strcat(std[i].name, buf);
		//std[i].sname = '\0';
		strcpy(std[i].sname, "Pavarde:");
		strcat(std[i].sname, buf);
		std[i].n = x;
		std[i].avg = 0;
		for (int j = 0; j < std[i].n; j++) {
			std[i].nd[j] = 2 + rand() % 4; //2..5
			std[i].avg += std[i].nd[j];
		}
		std[i].egz = 2 + rand() % 4;
		std[i].avg /= std[i].n;
		std[i].ig = 0.4 * std[i].avg + 0.6 * std[i].egz;
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
	return 0;
}
