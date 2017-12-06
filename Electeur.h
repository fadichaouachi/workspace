/**
 * \file electeur.h
 *
 * \brief Fichier qui contient l'interface de la classe electeur
 *
 * \author Fadi Chaouachi
 * \date 28 octobre 2016
 * \version 2.2
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_
#include<string>
#include<sstream>
#include <iostream>
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"
#include "validationFormat.h"

namespace elections
{

class Electeur: public Personne
{
public:

	/**
	 * \brief Constructeur
	 */
	Electeur(const string& p_nas, const string& p_prenom, const string& p_nom,
			const util::Date& p_dateNaissance, const util::Adresse& p_adresse);

	/**
	 * \brief accesseur
	 */
	virtual string reqPersonneFormate();

	virtual Personne* clone() const;
	virtual ~Electeur();
};

} /* namespace elections */

#endif /* ELECTEUR_H_ */
