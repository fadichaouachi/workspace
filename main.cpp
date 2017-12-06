/*
 * main.cpp
 *
 *  Created on: 2017-11-28
 *      Author: etudiant
 */

/*!
 * \brief obtenir interactivement avec l’usager, les données nécessaires
 *        pour créer une "Personne" puis de modifier son adresse.
 */
#include <iostream>
#include <sstream>

#include "Date.h"
#include "validationFormat.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Personne.h"
#include "Adresse.h"
#include "Circonscription.h"

long m_jour, m_mois, m_annee;
std::string m_nas, m_nom, m_prenom;

char buffer[256];

int m_numRue, m_parti, choix;
std::string m_nomRue, m_ville, m_codePostale, m_province;

int main()
{
	int i = 1;
	int k = 2;
	util::Date a(12, 05, 1979);
	const util::Adresse adr(i, "rue inconnue", "inconnue", "G1V 0A7", "QC");
	elections::Candidat c("046 454 286", "inconnu", "inconnu", a, adr, k);
	elections::Circonscription circon("Circonscription n0 1", c);

	ostringstream os;

	cout << "--------------------------------------------" << endl
			<< "Bienvenue dans l'outil de gestion des listes électorales"
			<< endl << "--------------------------------------------" << endl;

	os << "votre choix?" << endl << "1:inscription d'un candidat" << endl
			<< "2:inscription d'un electeur" << endl
			<< "3:affichage de la circonscription" << endl << "4:quitter"
			<< endl;

	do
	{

		cout << os.str();

		cin >> choix;
		cin.ignore();

		switch (choix)
		{
		case 1:
		{

			cout << "Veuillez entrer la date de naissance: " << endl;
			cout << "Le jour [1..31]: " << endl;
			cin >> m_jour;
			cin.ignore();
			while (m_jour < 1 || m_jour > 31)
			{
				cout << "jour invalide: veuillez entrer une jour entre 1 et 31"
						<< endl;
				cin >> m_jour;
				cin.ignore();
			}

			cout << "Le moi [1..12]: " << endl;
			cin >> m_mois;
			cin.ignore();
			while (m_mois < 1 || m_mois > 12)
			{
				cout << "mois invalide: veuillez entrer une mois entre 1 et 12"
						<< endl;
				cin >> m_mois;
				cin.ignore();
			}

			cout << "L'annee [1970..2037]: " << endl;
			cin >> m_annee;
			cin.ignore();
			while (m_annee < 1970 || m_annee > 2037)
			{
				cout
						<< "Annee invalide: veuillez entrer une anee entre 1970 et 2037"
						<< endl;
				cin >> m_annee;
				cin.ignore();
			}

			util::Date date(m_jour, m_mois, m_annee);

			while (!date.validerDate(m_jour, m_mois, m_annee))
			{
				cout << "La date de naissance n'est pas valide. " << endl
						<< endl;
				cout << "Veuillez entrer la date de naissance: " << endl;

				cout << "Le jour [1..31]: " << endl;
				cin >> m_jour;
				cin.ignore();

				cout << "Le moi [1..12]: " << endl;
				cin >> m_mois;
				cin.ignore();

				cout << "L'annee [1970..2037]: " << endl;
				cin >> m_annee;
				cin.ignore();

				date.asgDate(m_jour, m_mois, m_annee);

			}

			cout << "Veuillez entrez les informations sur l'adresse: " << endl;

			cout << "Le numéro de la rue: " << endl;
			cin >> m_numRue;
			cin.ignore();
			while (m_numRue < 0)
			{
				cout << "Le numéro de la rue n'est pas valide: " << endl;
				cout << "Entrez un numéro de rue valide: " << endl;
				cin >> m_numRue;
				cin.ignore();
			}

			cout << "Le nom de la rue: " << endl;
			cin.getline(buffer, 255);
			m_nomRue = buffer;
			while (m_nomRue == "")
			{
				cout << "Le nom de la rue n'est pas valide: " << endl;
				cout << "Entrez un nom de rue valide: " << endl;
				cin.getline(buffer, 255);
				m_nomRue = buffer;
			}

			cout << "Le nom de la ville" << endl;
			cin.getline(buffer, 255);
			m_ville = buffer;
			while (m_ville == "")
			{
				cout << "Le nom de la villes n'est pas valide: " << endl;
				cout << "Entrez un nom de ville valide: " << endl;
				cin.getline(buffer, 255);
				m_ville = buffer;
			}
			//A.setVille(ville);

			cout << "Le code postale: " << endl;
			cin.getline(buffer, 255);
			m_codePostale = buffer;
			while (m_codePostale == "")
			{
				cout << "Le code postale n'est pas valide: " << endl;
				cout << "Entrez un code postale valide: " << endl;
				cin.getline(buffer, 255);
				m_codePostale = buffer;
			}
			//A.setCodePostale(codePostale);

			cout << "La province: " << endl;
			cin.getline(buffer, 255);
			m_province = buffer;
			while (m_province == "")
			{
				cout << "Le nom de la province n'est pas valide: " << endl;
				cout << "Entrez un nom de la province  valide: " << endl;
				cin.getline(buffer, 255);
				m_province = buffer;
			}
			//A.setProvince(province);

			const util::Adresse A(m_numRue, m_nomRue, m_ville, m_codePostale,
					m_province);

			cout << "Entrez le prenom: " << endl;
			cin.getline(buffer, 255);
			string prenom = buffer;
			while (prenom == "")
			{
				cout << "Le prenom est vide" << endl;
				cout << "Entrez le prenom: " << endl;
				cin.getline(buffer, 255);
				prenom = buffer;
			}
			m_prenom = buffer;

			cout << "Entrez le nom: " << endl;
			cin.getline(buffer, 255);
			string nom = buffer;
			while (nom == "")
			{
				cout << "Le nom est vide" << endl;
				cout << "Entrez le nom: " << endl;
				cin.getline(buffer, 255);
				nom = buffer;
			}
			m_nom = buffer;

			cout << "Veuillez entrer le numero d'assurance sociale: " << endl;
			cin.getline(buffer, 255);
			while (!util::validerNas(buffer))
			{
				cout << "NAS invalide," << endl;
				cout << "Veuillez entrer le numero d'assurance sociale: "
						<< endl;
				cin.getline(buffer, 255);

			}
			m_nas = buffer;

			cout << "Veuillez selectionner votre parti politique: " << endl
					<< "0:BLOC_QUEBECOIS, 1:CONSERVATEUR, 2:INDEPENDANT, 3:LIBERAL: 4:NOUVEAU_PARTI_DEMOCRATIQUE"
					<< endl;
			cin >> m_parti;

			elections::Candidat candidat(m_nas, m_prenom, m_nom, date, A,
					m_parti);
			circon.inscrire(candidat);

			break;
		}
		case 2:
		{
			cout << "Veuillez entrer la date de naissance: " << endl;
			cout << "Le jour [1..31]: " << endl;
			cin >> m_jour;
			cin.ignore();
			while (m_jour < 1 || m_jour > 31)
			{
				cout << "jour invalide: veuillez entrer une jour entre 1 et 31"
						<< endl;
				cin >> m_jour;
				cin.ignore();
			}

			cout << "Le moi [1..12]: " << endl;
			cin >> m_mois;
			cin.ignore();
			while (m_mois < 1 || m_mois > 12)
			{
				cout << "mois invalide: veuillez entrer une mois entre 1 et 12"
						<< endl;
				cin >> m_mois;
				cin.ignore();
			}

			cout << "L'annee [1970..2037]: " << endl;
			cin >> m_annee;
			cin.ignore();
			while (m_annee < 1970 || m_annee > 2037)
			{
				cout
						<< "Annee invalide: veuillez entrer une anee entre 1970 et 2037"
						<< endl;
				cin >> m_annee;
				cin.ignore();
			}

			util::Date date(m_jour, m_mois, m_annee);

			while (!date.validerDate(m_jour, m_mois, m_annee))
			{
				cout << "La date de naissance n'est pas valide. " << endl
						<< endl;
				cout << "Veuillez entrer la date de naissance: " << endl;

				cout << "Le jour [1..31]: " << endl;
				cin >> m_jour;
				cin.ignore();

				cout << "Le moi [1..12]: " << endl;
				cin >> m_mois;
				cin.ignore();

				cout << "L'annee [1970..2037]: " << endl;
				cin >> m_annee;
				cin.ignore();

				date.asgDate(m_jour, m_mois, m_annee);

			}

			cout << "Veuillez entrez les informations sur l'adresse: " << endl;

			cout << "Le numéro de la rue: " << endl;
			cin >> m_numRue;
			cin.ignore();
			while (m_numRue < 0)
			{
				cout << "Le numéro de la rue n'est pas valide: " << endl;
				cout << "Entrez un numéro de rue valide: " << endl;
				cin >> m_numRue;
				cin.ignore();
			}

			cout << "Le nom de la rue: " << endl;
			cin.getline(buffer, 255);
			m_nomRue = buffer;
			while (m_nomRue == "")
			{
				cout << "Le nom de la rue n'est pas valide: " << endl;
				cout << "Entrez un nom de rue valide: " << endl;
				cin.getline(buffer, 255);
				m_nomRue = buffer;
			}

			cout << "Le nom de la ville" << endl;
			cin.getline(buffer, 255);
			m_ville = buffer;
			while (m_ville == "")
			{
				cout << "Le nom de la villes n'est pas valide: " << endl;
				cout << "Entrez un nom de ville valide: " << endl;
				cin.getline(buffer, 255);
				m_ville = buffer;
			}
			//A.setVille(ville);

			cout << "Le code postale: " << endl;
			cin.getline(buffer, 255);
			m_codePostale = buffer;
			while (m_codePostale == "")
			{
				cout << "Le code postale n'est pas valide: " << endl;
				cout << "Entrez un code postale valide: " << endl;
				cin.getline(buffer, 255);
				m_codePostale = buffer;
			}
			//A.setCodePostale(codePostale);

			cout << "La province: " << endl;
			cin.getline(buffer, 255);
			m_province = buffer;
			while (m_province == "")
			{
				cout << "Le nom de la province n'est pas valide: " << endl;
				cout << "Entrez un nom de la province  valide: " << endl;
				cin.getline(buffer, 255);
				m_province = buffer;
			}
			//A.setProvince(province);

			const util::Adresse A(m_numRue, m_nomRue, m_ville, m_codePostale,
					m_province);

			cout << "Entrez le prenom: " << endl;
			cin.getline(buffer, 255);
			string prenom = buffer;
			while (prenom == "")
			{
				cout << "Le prenom est vide" << endl;
				cout << "Entrez le prenom: " << endl;
				cin.getline(buffer, 255);
				prenom = buffer;
			}
			m_prenom = buffer;

			cout << "Entrez le nom: " << endl;
			cin.getline(buffer, 255);
			string nom = buffer;
			while (nom == "")
			{
				cout << "Le nom est vide" << endl;
				cout << "Entrez le nom: " << endl;
				cin.getline(buffer, 255);
				nom = buffer;
			}
			m_nom = buffer;

			cout << "Veuillez entrer le numero d'assurance sociale: " << endl;
			cin.getline(buffer, 255);
			while (!util::validerNas(buffer))
			{
				cout << "NAS invalide," << endl;
				cout << "Veuillez entrer le numero d'assurance sociale: "
						<< endl;
				cin.getline(buffer, 255);

			}
			m_nas = buffer;

			elections::Electeur electeur(m_nas, m_prenom, m_nom, date, A);
			circon.inscrire(electeur);
			break;
		}
		case 3:
		{
			ostringstream os;

			os << "Circonscription :" << circon.getNom() << endl
					<< "Depute sortant :" << endl << c.reqPersonneFormate()
					<< endl << endl << "Liste des inscrits :" << endl << endl;

			cout << os.str();

			cout << circon.reqCirconscriptionFormate();
			break;
		}
		case 4:
		{
			string fichier;
			cout << "Saisir le nom du fichier de sauvegarde : " << endl;

			cin >> fichier;
			ofstream ofs(fichier.c_str(), ios::out);

			ofs << os.str();
			ofs << circon.reqCirconscriptionFormate();
			cout << endl << "La sauvegarde a été faite dans le fichier "
					<< fichier << endl << endl;
			cout << "Fin du programme" << endl;

			return 0;
			break;
		}
		}
	} while (choix != 4);

	return 0;
}

