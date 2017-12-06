/**
 * \file Candidat.h
 *
 * \brief  interface de la classe Candidat
 *
 * \author fadi chaouachi
 * \version 0.1
 * \date 2017-11-28
 */
#ifndef CANDIDAT_H_
#define CANDIDAT_H_

#include<string>
#include<sstream>
#include <iostream>
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"
#include "validationFormat.h"

namespace elections
{

class Candidat: public Personne
{

public:

	Candidat(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date& p_dateNaissance,
			const util::Adresse& p_adresse, int p_parti);

	/**
	 * \brief accesseurs
	 */
	std::string reqPartiPolitiqueString() const;
	virtual string reqPersonneFormate();

	/**
	 * \brief Cette méthode permet de faire une copie allouée sur le monceau de l'objet courant.
	 */
	virtual Personne* clone() const;

	/**
	 * \brief destructeur
	 */
	virtual ~Candidat();

private:
	/**
	 * \brief entier utilise pour le choix du parti dans la liste d'enum
	 */
	int m_partiPolitique;

	/**
	 * \brief liste qui contient tous les partis politique
	 */
	enum PartisPolitiques
	{
		BLOC_QUEBECOIS,
		CONSERVATEUR,
		INDEPENDANT,
		LIBERAL,
		NOUVEAU_PARTI_DEMOCRATIQUE
	};
};

} /* namespace elections */

#endif /* CANDIDAT_H_ */
