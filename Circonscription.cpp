/**
 * \file Circonscription.cpp
 * \brief La classe Circonscription permet de faire la gestion des listes électorales.
 *
 * \author Fadi Chaouachi
 *
 * \version 0.1
 * \date 2017-11-28
 */
#include "Circonscription.h"
#include "Candidat.h"
#include "Adresse.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace elections
{

/*
 * \brief constructeur avec param
 *
 * \param[in] p_nom:  le nom de la circonscription
 * \param[in] p_depute: Le candidat
 *
 */
Circonscription::Circonscription(const std::string& p_nom,
		const Candidat& p_depute) :
		m_nom(p_nom), m_deputeElu(p_depute)
{

}

const Candidat Circonscription::getDeputeElu() const
{
	return m_deputeElu;
}

const std::string& Circonscription::getNom() const
{
	return m_nom;
}

/**
 * \brief Cette méthode retourne dans un objet std::string les informations formatées concernant la
 * circonscription. On commence par son nom, suivi de son député puis on parcourt toutes les Personnes
 * inscrites dans la circonscription pour avoir les informations formatées sur chacune d’elle.
 *
 * \return retourne dans un objet std::string les informations formatées
 */
std::string Circonscription::reqCirconscriptionFormate() const
{
	ostringstream os;

	for (size_t i = 0; i < m_vInscrits.size(); ++i)
	{
		os << (m_vInscrits[i])->reqPersonneFormate() << endl << endl;
	}

	return os.str();
}

/*
 * \brief Cette méthode permet d’inscrire une personne sur la liste électorale de la circonscription. La classe
 * Circonscription conserve des pointeurs sur des Personnes et elle est responsable de la gestion de la mémoire.
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
}

/**
 * \brief destructeur
 */
Circonscription::~Circonscription()
{
	for (size_t i = 0; i < m_vInscrits.size(); ++i)
	{
		delete m_vInscrits[i];
	}
	m_vInscrits.clear();
}

} /* namespace elections */
