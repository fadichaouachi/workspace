/**
 * \file Candidat.cpp
 *
 * \brief  La classe Candidat représente des Personnes inscrites dans une circonscription se portant candidat à la députation sous une « étiquette » politique (parti).
 *
 * \author fadi chaouachi
 * \version 0.1
 * \date 2017-11-28
 */
#include "Candidat.h"
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"
#include <sstream>
#include <iostream>

using namespace std;

namespace elections
{

/*!
 * \brief Le constructeur avec parametres On construit un objet Candidat avec les parametre recus
 *
 * 	\param[in] p_nas est une chaine de characteres qui represente le nas de la personne
 * 	\param[in] p_prenom est une chaine de characteres qui represente le prenom de la personne
 * 	\param[in] p_nom est une chaine de characteres qui represente le nom de la personne
 * 	\param[in] p_dateNaissance est un objet date qui represente la date de naissance de la personne
 * 	\param[in] p_adresse est un objet adresse qui represente l'adresse de la personne
 * 	\param[in] p_parti est un entier qui represente un parti politique
 *
 */
Candidat::Candidat(const std::string& p_nas, const std::string& p_prenom,
		const std::string& p_nom, const util::Date& p_dateNaissance,
		const util::Adresse& p_adresse, int p_parti) :
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(
				p_parti)
{
	PRECONDITION(util::validerNas(p_nas));
	PRECONDITION(!p_prenom.empty());
	PRECONDITION(!p_nom.empty());
	PRECONDITION(
			util::Date::validerDate(p_dateNaissance.reqJour(),
					p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));

	INVARIANTS();
}
/**
 * \brief Selon le choix(int) que l'utilisateur a choisit la fonction va associer a un nom de parti(strng)
 *
 * \return le nom du parti dans du candidat sous la forme d'un string
 */
std::string Candidat::reqPartiPolitiqueString() const
{
	std::string parti;
	switch (m_partiPolitique)
	{
	case BLOC_QUEBECOIS:
		return "BLOC_QUEBECOIS";
		break;
	case CONSERVATEUR:
		return "CONSERVATEUR";
		break;
	case INDEPENDANT:
		return "INDEPENDANT";
		break;
	case LIBERAL:
		return "LIBERAL";
		break;
	case NOUVEAU_PARTI_DEMOCRATIQUE:
		return "NOUVEAU_PARTI_DEMOCRATIQUE";
		break;
	}
	return parti;

}

/*!
 * \brief Méthode qui retourne dans un objet std::string les informations courante correspondant à une personne le tout formaté
 *
 * \return une chaine de charactere string
 * */
string Candidat::reqPersonneFormate()
{
	ostringstream os;

	os << "Candidat" << endl << Personne::reqPersonneFormate() << endl
			<< "Parti politique			:" << reqPartiPolitiqueString();

	return os.str();
}

/**
 * \brief Cette méthode permet de faire une copie allouée sur le monceau de l'objet courant.
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this); // Appel du constructeur copie

}

/**
 * \brief destructeur
 */
Candidat::~Candidat()
{
	// TODO Auto-generated destructor stub
}

} /* namespace elections */
