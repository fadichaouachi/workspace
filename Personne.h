/**
 * \file Personne.h
 *
 * \brief fichier qui contient l'interface de la classe Personne, qui sert au maintien et a la manipulation des personnes
 *
 * \Author Fadi Chaouachi
 *
 * \Created on: 2017-10-13
 * \version 1.0
 *
 * Dernier modification : 2017-11-28
 *
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <iostream>
#include <sstream>
#include "Adresse.h"
#include "Date.h"
#include "validationFormat.h"

namespace elections
{

/*!
 * \class Personne
 * \brief Cette classe sert au maintien et a la manipulation des personnes
 *  Elle sert aussi a assigner une nouvelle adresse à l'objet courant :
 *  et  retourner dans un objet std::string les informations courante correspondant à une personne le tout formaté
 *
 *
 */
class Personne
{
public:
	Personne();
	Personne(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date& p_dateNaissance,
			const util::Adresse& p_adresse);

	bool operator==(const Personne& p_personne) const;

	friend ostream& operator<<(ostream& p_os, const Personne& p_personne);

	/**
	 * \brief accesseur
	 */
	string reqNas() const;
	string reqPrenom() const;
	string reqNom() const;
	util::Date reqDateNaissance() const;
	util::Adresse reqAdresse() const;
	virtual string reqPersonneFormate();

	virtual Personne* clone() const=0;
	virtual ~Personne();

	/**
	 * \brief Teste l'invariant de la classe Personnes.
	 * L'invariant de cette classe s'assure que la personne est valide
	 */
	void verifieInvariant() const;

private:

	//Un objet string. Le numéro d’assurance sociale.
	std::string m_nas;

	//Des objets string. Le prénom et le nom de la personne. Doivent être non vides.
	std::string m_prenom, m_nom;

	//La date de naissance de la personne.
	//Un classe Date (util::Date ) vous est fournie, elle ne couvre que l’intervalle [1970, 2037]
	//La validité de la date doit être établie par la méthode statique Date::validerDate(…)
	util::Date m_dateNaissance;

	//L'adresse de la personne. Pour le moment la seule contrainte est qu'elle ne doit pas être vide.
	util::Adresse m_adresse;

};

} //namespace elections

#endif /* PERSONNE_H_ */
