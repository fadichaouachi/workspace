/**
 * \file Personne.cpp
 *
 * \brief La classe Personne programmée au deuxième TP, représente
 * tous les types de Personnes inscrites dans une circonscription.
 *
 * \author Fadi Chaouachi
 *
 * \date 2017-11-28
 *
 * \version 2.4
 */

#include "Personne.h"
#include "Adresse.h"
#include "Date.h"
#include <iostream>
#include <sstream>

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
 *
 */
Personne::Personne(const std::string& p_nas, const std::string& p_prenom,
		const std::string& p_nom, const util::Date& p_dateNaissance,
		const util::Adresse& p_adresse) :
		m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(
				p_dateNaissance), m_adresse(p_adresse)
{
	PRECONDITION(util::validerNas(p_nas));
	PRECONDITION(!p_prenom.empty());
	PRECONDITION(!p_nom.empty());
	PRECONDITION(
			util::Date::validerDate(p_dateNaissance.reqJour(),
					p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));

	POSTCONDITION(m_nas == p_nas);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);

	INVARIANTS();
}

/*!
 * \brief retourne le numero de nas de la personne
 *
 * \return une chaine de charatere qui represente le nas de la personne
 */
string Personne::reqNas() const
{
	return m_nas;
}

/*!
 * \brief retourne le prenom de la personne
 *
 * \return une chaine de charactere qui represente le prenom de la personne
 */
string Personne::reqPrenom() const
{
	return m_prenom;
}

/*!
 * \brief retourne le nom de la personne
 *
 * \return une chaine de charactere qui represente le nom de la personne
 */
string Personne::reqNom() const
{
	return m_nom;
}

/*!
 * \brief retourne la date de naissance de la personne
 *
 * \return un objet date  qui represente la date de naissance de la personne
 */
util::Date Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

/*!
 * \brief retourne l'adresse de la personne
 *
 * \return une chaine de charactere qui represente l'adresse de la personne
 */
util::Adresse Personne::reqAdresse() const
{
	return m_adresse;
}

/*!
 * \brief Méthode qui retourne dans un objet std::string les informations courante correspondant à une personne le tout formaté
 *
 * \return une chaine de charactere string
 * */
string Personne::reqPersonneFormate()
{

	ostringstream os;

	os << "------------------------------------------" << endl << "NAS				:"
			<< reqNas() << endl << "Prénom				:" << reqPrenom() << endl
			<< "Nom				:" << reqNom() << endl << "Date de naissance		:"
			<< reqDateNaissance().reqDateFormatee() << endl << "Adresse				:"
			<< reqAdresse().reqAdresseFormate();

	return os.str();
}

/*!
 * \brief Opérateur de comparaison d’égalité. La comparaison se fait sur la base de tous les attributs.
 *
 * \param[in] un objet Personne
 *
 * \return vrai ou faux si les attributs de la personne recus en param sont exactement les memes que la personne courante
 */
bool Personne::operator==(const Personne& p_personne) const
{
	bool egal = false;
	if (m_nas == p_personne.m_nas)
	{
		if (m_prenom == p_personne.m_prenom)
		{
			if (m_nom == p_personne.m_nom)
			{
				if (m_dateNaissance == p_personne.m_dateNaissance)
				{
					//if (m_adresse == p_personne.m_adresse)
					//{
					egal = true;
					//}
				}
			}
		}
	}

	return egal;

}

/*!
 * \brief Opérateur de sortie : permet d’inscrire dans le flux
 *        de sortie passé en paramètre sur 5 lignes le nas, le
 *        prénom, le nom, la date de naissance sous la forme de trois
 *        entiers séparés par des espaces puis l’adresse sur une ligne.
 *
 * \param[in] p_os un flux de sortie externe vers la console
 * \param[in]un objet personne
 *
 * \return un flux de sortie avec les informations de la Personne sur 5 lignes differentes
 *
 */

//friend
ostream& operator<<(ostream& p_os, const Personne& p_personne)
{
	string nas = p_personne.reqNas();
	string prenom = p_personne.reqPrenom();
	string nom = p_personne.reqNom();
	util::Date date = p_personne.reqDateNaissance();
	util::Adresse adresse = p_personne.reqAdresse();

	p_os << nas << endl;
	p_os << prenom << endl;
	p_os << nom << endl;

	long jour = date.reqJour();
	long mois = date.reqMois();

	if (jour < 10)
	{
		p_os << "0";
	}
	p_os << jour << " ";
	if (mois < 10)
	{
		p_os << "0";
	}
	p_os << mois << " ";
	p_os << date.reqAnnee() << endl;

	p_os << adresse << endl;

	return p_os;
}

/*!
 * \brief deconstructeur par defaut
 *  */
Personne::~Personne()
{
}

/**
 * \brief Teste l'invariant de la classe Personnes.
 * L'invariant de cette classe s'assure que la personne est valide
 */

void Personne::verifieInvariant() const
{

	INVARIANT(util::validerNas(m_nas));
	INVARIANT(!m_nom.empty());
	INVARIANT(!m_prenom.empty());

}

} //namespace elections

