#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 200
#include <iostream>
#include <fstream>
using namespace std;



struct Rubrica {
	int codiceContatto;
	int n_telefono;
	char nome[30];
	char cognome[50];
	};

void inserimento(Rubrica contatto[], int &indice_contatti, int contatti_da_inserire);
void scriviSuFile(Rubrica contatto[], int indice_contatti);
int menu();
int chiediNumeroContatti();
void leggiDaFile();
void stampa(Rubrica elemento);



#endif // FUNZIONI_H
