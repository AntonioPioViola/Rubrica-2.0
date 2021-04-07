#include "Funzioni.h"

void inserimento(Rubrica contatto[], int &indice_contatti, int contatti_da_inserire) {
    char esci;
	Rubrica elemento;
	int contatti_inseribili = MAX - indice_contatti;

	if (contatti_da_inserire <= contatti_inseribili) {
		int i = indice_contatti;
		int j = 1;
		while (i < indice_contatti + contatti_da_inserire)
		{
			cout << "per inserire l'elemento n. " << j <<" premere il tasto \"n\", altrimenti 'q' per terminare : ";
			cin >> esci;
			cout<<endl;

			if (esci == 'n')
			{
				cout << "\nelemento n. " <<j;
				cout << "\nInserisci nome : ";
				cin.ignore();
				cin.getline(elemento.nome, 30);
				cout << "\nInserisci cognome : ";
				cin.getline(elemento.cognome, 50);
				cout << "\nInserisci il numero di telefono : ";
				cin >> elemento.n_telefono;
				elemento.codiceContatto = i+1;
			}
			else
			{
				cout << "inseriti  n. "<< j-1 <<" contatti terminato";
				break;
			}
			contatto[i] = elemento;
			i++;
			j++;
		} indice_contatti = i;

	}
}

void scriviSuFile(Rubrica contatto[], int indice_contatti) {
	fstream f_out("Rubrica.dat", ios::out | ios::binary);

	if(f_out) {
		for(int j=0; j<indice_contatti; j++){
			f_out.write( (char*) &contatto[j], sizeof(contatto[j]) );
		}
		f_out.close();
	}
	else
		cout<<"File Rubrica.dat non creato"<< endl;
}


int menu() {

	char scelta;
    cout << "\nMENU CONTATTI";
    cout << "\n1. Inserimento contatto";
    cout << "\n0. ESCI\n";

	// con il seguente ciclo ci assicuriamo che l'utente inserisca
	// un carattere compreso tra '0' e '1'
	do {
		cout<<"inserisci un numero compreso tra 0 e 1\n";
		cin>>scelta;
	} while(scelta <48 || scelta >50);

	// la differenza scelta - '0' sarà un numero intero compreso tra  0 e 8
	return scelta - '0';
}

int chiediNumeroContatti()  {
    int nun_contatti;
	cout << "quanti contatti vuoi inserire? :";
    cin >> nun_contatti;
	cout << endl;
	return nun_contatti;
}
