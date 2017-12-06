/*
 * validationFormat.cpp
 *
 *  Created on: 2017-10-01
 *      Author: etudiant
 */

#include "validationFormat.h"
#include "sstream"
#include <ctime>

namespace util
{

//bool validerDate(string date);


/*
 * Cette fonction valide le format du numéro d’assurance sociale.
 * Le numéro d’assurance sociale (NAS) correspond à un numéro de neuf chiffres avec des espaces
 */
bool validerNas(const std::string& p_nas)
{

	bool valide = false;
	int longeur = p_nas.length();

	int nas[9];
	int a[9];
	int total = 0;
	int test[9] =
	{ 1, 2, 1, 2, 1, 2, 1, 2, 1 };

	/*
	 * Vérification que le NAS contient contient bien 9 chiffres avec 2 espaces
	 */

	if (longeur == 11)
	{

		if (p_nas[3] == ' ' and p_nas[7] == ' ')
		{
			int p = 0;
			for (int i = 0; i < longeur; i++)
			{
				if ((i != 3) and (i != 7))
				{
					int temp = p_nas[i] - '0';
					nas[p++] = temp;
				}
			}

			for (int j = 0; j < 9; j++)
			{
				a[j] = nas[j] * test[j];
				if (a[j] > 9)
				{
					total = total + (a[j] - 10) + 1;
				}
				else
				{
					total = total + a[j];
				}

			}
			if (total % 10 == 0)
			{
				valide = true;
			}
		}
	}

	return valide;

}

/*
 * Cette fonction valide le format du fichier de données texte lu par l’intermédiaire
 *  d’un flux d’entrée passé en paramètre.
 */
bool validerFormatFichier(std::istream& p_is)
{
	bool valid = false;

		if (p_is)

		{
			vector<string> tableau;

			std::string ligne;

			//initialisation d'un tableau qui va contenir tous les informations de mon fichier
			while (std::getline(p_is, ligne))
			{

				 tableau.push_back(ligne);

			}

			if (tableau[0].empty())
			{
				cout<< "Fichier non valide";
				return false;
			}

			for (unsigned int i = 1 ; i < tableau.size(); i++)
			{

				//bool electeur = false;
				bool depute = false;
				/*
				 *
				 * From here we gonna determine if: electeur ou bien depute
				 * depute: 6 informations(nom de parti, NAS, prenom, nom , date de naissance et adresse)
				 * electeur: 5 informations(NAS, prenom, nom , date de naissance et adresse)
				 */

				if (tableau[i].compare("BLOC_QUEBECOIS") == 0 ||

						tableau[i].compare("CONSERVATEUR") == 0 ||

						tableau[i].compare("INDEPENDANT") == 0 ||

						tableau[i].compare("LIBERAL") == 0 ||

						tableau[i].compare("NOUVEAU_PARTI_DEMOCRATIQUE") == 0)

				{
					//Séquence pour un députe

					cout<< "depute"<<endl;
					depute = true;

					if (validerNas(tableau[i+1])==true)
					{
						if(tableau[i+2].empty() == 0 and tableau[i+3].empty() == 0 and tableau[i+5].empty() ==0)
						{

							/* todo refaire la fonction de validation en utilisant Date::validerdate
							 *
							 * if(validerDate(tableau[i+4]) == true)
							{
								valid = true;

								i = i+5;
							}
							 *
							 */


						}
					}
					else
					{
						return valid = false;
					}

				}

				//Séquence pour un électeur
				else if (validerNas(tableau[i]) == true and depute != true)
				{

					// ceci est un candidat normal

					cout<<"electeur: ";


					if(tableau[i+1].empty() == 0 and tableau[i+2].empty() == 0 and tableau[i+4].empty() == 0)
					{

						/**
						 * todo a refaire!!!! avec DATE:: valider
						 * if(validerDate(tableau[i+3]) == true)
						{
							valid = true;
							i = i+4;
						}
						 */


					}
				}
				else
				{

					//data not good le fichier
					return false;

				}

				depute = false;

			}


		}
		else
		{
			std::cout << " Le fichier n'est pas un format valide " << "\n";
			return valid;
		}
		return valid;
}

}
/*
 * bool validerDate(string date)
{
	bool valid = false;
	if(date.length() == 10 and date[2] == ' ' and date[5] == ' ')
	{

		for (unsigned int i = 0; i < date.length(); ++i)
		{
			if(isdigit(date[i]) or i == 2 or i == 5)
			{
				valid = true;
			}
			else
			{
				return valid = false;
			}
		}
	}

	return valid;
}
 */


/**
 * int main()
{

	string myString;
	cout << "Entrez un nom de fichier: ";
	cin >> myString;

	fstream myfile;
	myfile.open(myString.c_str(), ios::in);
	cout << validerFormatFichier(myfile);

	myfile.close();



	return 0;
}
 */

