#include <iostream>
#include <fstream>
#include <iomanip>
#include "Funzioni.h"
#include <string>
using namespace std;


 /*! \mainpage <CENTER> LA rubrica di viola </CENTER>
    * \author <B> Antonio Pio Viola</B>
    * \version <B> V1.0 </B>
    * \date <B> Consegna progetto:   8/04/2021 </B>
    *
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    *
    * - prendere da input dei contatti
    * - genera un file di testo denominato Rubrica.dat
    *
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */



int main()
{

	Rubrica contatto[MAX];

	int indice_contatti = 0;

	int scelta;

	do
		{
		scelta = menu();
		switch(scelta) {
			case 0: cout<<"Fine Sessione\n";
				break;
			case 1: {
				int contatti_da_inserire = chiediNumeroContatti();
				inserimento(contatto, indice_contatti, contatti_da_inserire);
				scriviSuFile(contatto, indice_contatti);
				break;
				}
		}
	} while(scelta != 0);

    return 0;
}







