/**
 * \file Circonscription.h
 *
 * \brief  interface de la classe Circonscription
 *
 * \author fadi chaouachi
 * \version 0.1
 * \date 2017-11-28
 */
#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include<string>
#include<sstream>
#include <iostream>
#include <vector>
#include "Electeur.h"
#include "Candidat.h"

namespace elections
{

class Circonscription
{
public:
	/**
	 * Constructeur avec param
	 */
	Circonscription(const std::string& p_nom, const Candidat& p_depute);

	/**
	 * Destructeur
	 */
	virtual ~Circonscription();

	/**
	 *  les accesseurs
	 */
	const Candidat getDeputeElu() const;
	const std::string& getNom() const;
	std::string reqCirconscriptionFormate() const;

	/**
	 * \brief Cette méthode permet d’inscrire une personne sur la liste électorale de la circonscription
	 */
	void inscrire(const Personne& p_nouvelInscrit);

private:
	/*
	 * brief le nom de la circonscription (ne doit pas être vide)
	 */
	std::string m_nom;

	/*
	 * brief Le candidat sortant qui a été élu aux élections précédentes.
	 */
	Candidat m_deputeElu;

	/**
	 * contenir tous les inscrits à la liste électorale de la circonscription
	 */
	std::vector<Personne*> m_vInscrits;

};

} /* namespace elections */

#endif /* CIRCONSCRIPTION_H_ */
