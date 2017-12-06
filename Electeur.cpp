/**
 * \file Electeur.h
 *
 * \brief La classe Electeur représente des personnes inscrites comme « simple » électeur dans une circonscription
 *
 * \author Fadi Chaouachi
 *
 * \date 2017-11-28
 *
 * \version 2.2
 */
#include "Electeur.h"
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
 * \brief Le constructeur avec parametres
 * 			On construit un objet Personne avec les parametre recus
 *
 * 	\param[in] p_nas est une chaine de characteres qui represente le nas de la personne
 * 	\param[in] p_prenom est une chaine de characteres qui represente le prenom de la personne
 * 	\param[in] p_nom est une chaine de characteres qui represente le nom de la personne
 * 	\param[in] p_dateNaissance est un objet date qui represente la date de naissance de la personne
 * 	\param[in] p_adresse
 *
 */
Electeur::Electeur(const string& p_nas, const string& p_prenom,
		const string& p_nom, const util::Date& p_dateNaissance,
		const util::Adresse& p_adresse) :
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{

}

/**
 * \brief Méthode qui augmente la méthode reqPersonneFormate de la classe de base Personne et qui
 *
 * \return retourne dans  un objet std::string les informations correspondant à un Electeur formatées
 */
string Electeur::reqPersonneFormate()
{

	ostringstream os;

	os << "Electeur " << endl << Personne::reqPersonneFormate();

	return os.str();
}

/**
 * \brief Cette méthode permet de faire une copie allouée sur le monceau de l'objet courant.
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this); // Appel du constructeur copie
}

/**
 * \brief Destructeur
 */
Electeur::~Electeur()
{
	// TODO Auto-generated destructor stub
}

} /* namespace elections */
