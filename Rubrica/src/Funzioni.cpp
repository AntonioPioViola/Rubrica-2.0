#include "Funzioni.h"

//! \class [FUNZIONI]

//! \relates FUNZIONI
/*! \fn inserimento(Rubrica contatto[], int &indice_contatti, int contatti_da_inserire)
    \brief inserimento contatto
    \param contatto ...
    \param indice_contatti tiene traccia del numero del contatto
    \param contatti_da_inserire la sua funzione e da contatore
*/



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

//! \relates FUNZIONI
/*! \fn scriviSuFile(Rubrica contatto[], int indice_contatti)
    \brief scrittura contatto su file binario
    \param contatto ...
    \param indice_contatti tiene traccia del numero del contatto
*/

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

//! \relates FUNZIONI
/*! \fn leggiDaFile()
    \brief lettura contatti da file binario
*/

void leggiDaFile() {
	fstream f_in("Rubrica.dat", ios::in | ios::binary);
	Rubrica elemento;

	if(f_in) {
		while( f_in.read((char*) &elemento, sizeof(elemento)) ) {
			stampa(elemento);
		}
		f_in.close();
	}
	else
		cout<<"il file Rubrica.dat non esiste"<< endl;
}

//! \relates FUNZIONI
/*! \fn stampa(Rubrica elemento)
    \brief Stampa a video il contatto
    \param elemento contatto da stampare
*/

void stampa(Rubrica elemento) {
		cout << "----------------" << endl;
		cout << "Contatto n. "<< elemento.codiceContatto <<endl;
		cout << "Nome   : " << elemento.nome <<endl;
		cout << "Cognome: " << elemento.cognome <<endl;
		cout << "Numero di telefono : " << elemento.n_telefono <<endl;
}

//! \relates FUNZIONI
/*! \fn cercaContatto(int codice)
    \brief cerca il contatto nel file binario
    \param codice del contatto da ricercare
*/

void cercaContatto(int codice) {
	fstream f_in("Rubrica.dat", ios::in | ios::binary);
	Rubrica elemento;

	if(f_in) {
		while( f_in.read((char*) &elemento, sizeof(elemento)) ) {
			if(elemento.codiceContatto==codice) {
				cout << "Elemento trovato!" << endl;
				stampa(elemento);
				break;
			}

		}
		f_in.close();
	}
	else
		cout<<"il file Rubrica.dat non esiste"<< endl;
}

//! \relates FUNZIONI
/*! \fn menu()
    \brief viene messo a video il menu per effettuare le proprie scelte
*/


int menu() {

	char scelta;
    cout << "\nMENU CONTATTI";
    cout << "\n1. Inserimento contatto";
    cout << "\n2. Stampa rubrica";
    cout << "\n3. Ricerca contatto";
    cout << "\n0. ESCI\n";

	// con il seguente ciclo ci assicuriamo che l'utente inserisca
	// un carattere compreso tra '0' e '3'
	do {
		cout<<"inserisci un numero compreso tra 0 e 3\n";
		cin>>scelta;
	} while(scelta <48 || scelta >52);

	// la differenza scelta - '0' sarà un numero intero compreso tra  0 e 8
	return scelta - '0';
}

//! \relates FUNZIONI
/*! \fn chiediNumeroContatti()
    \brief chiede quanti contatti si vogliano inserire
*/

int chiediNumeroContatti()  {
    int nun_contatti;
	cout << "quanti contatti vuoi inserire? :";
    cin >> nun_contatti;
	cout << endl;
	return nun_contatti;
}

//! \relates FUNZIONI
/*! \fn chiediCodice()
    \brief chiede il codice univoco da assegnare al contatto
*/

int chiediCodice()
{
     int codice;
     cout <<"Inserire qui il codice del contatto : ";
     cin>>codice;
     return codice;
}
