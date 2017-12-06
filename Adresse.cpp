/**
 * \file Adresse.cpp
 * \brief classe qui preprésente une adresse par une chaine de characte unique
 *
 * \author Fadi Chaouachi
 *
 * \version 0.1
 * \date 2017-11-28
 */
#include <sstream>
#include <iostream>
#include "Adresse.h"
#include "ContratException.h"

using namespace std;

namespace util
{

/*
 * \brief constructeur avec param
 *
 * \param[in] p_numRue: un entier qui represente le numero de la rue
 * \param[in] p_nomRue: une chaine de charactere represente le nom de la rue
 * \param[in] p_ville: une chaine de charactere represente  le nom de la ville
 * \param[in] p_codePostale: une chaine de charactere represente  le code zip
 * \param[in] p_province: une chaine de charactere represente  le nom de la province
 *
 */
Adresse::Adresse(int& p_numRue, const std::string& p_nomRue,
		const std::string& p_ville, const std::string& p_codePostale,
		const std::string& p_province)
//:m_numRue(p_numRue), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostale( p_codePostale), m_province(p_province)
{
	PRECONDITION(p_numRue > 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostale.empty());
	PRECONDITION(!p_province.empty());

	asgAdresse(p_numRue, p_nomRue,p_ville,p_codePostale,p_province);

	POSTCONDITION(m_numRue == p_numRue);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostale == p_codePostale);
	POSTCONDITION(m_province == p_province);

	INVARIANTS();
}

/*
 * \brief permet de modifier une adresse
 *
 * \param[in] p_adresse la nouvelle adresse
 */

void Adresse::asgAdresse(const int& p_numRue, const std::string& p_nomRue,
		const std::string& p_ville, const std::string& p_codePostale,
		const std::string& p_province)
{


	m_numRue = p_numRue;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostale = p_codePostale;
	m_province = p_province;

	POSTCONDITION(m_numRue == p_numRue);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostale == p_codePostale);
	POSTCONDITION(m_province == p_province);
}

/*
 * \brief accesseur
 *
 * \return l'adresse sous la forme d'un objet string
 */
const std::string& Adresse::reqAdresse() const
{
	return m_adresse;
}

/*
 * \brief acesseur
 *
 * \return une chaine de charactere avec l'adresse
 */
std::string Adresse::reqAdresseFormate() const
{
	ostringstream os;

	os << getNumRue() << "," << getNomRue() << "," << getVille() << ","
			<< getCodePostale() << "," << getProvince();

	return os.str();

}

/*
 * \brief accesseur
 *
 * \return le code zip
 */

const std::string& Adresse::getCodePostale() const
{
	return m_codePostale;
}

/*
 * \brief accesseur
 *
 * \return le NOM DE la rue
 */
const std::string& Adresse::getNomRue() const
{
	return m_nomRue;
}

/*
 * \brief accesseur
 *
 * \return le numero de la rue
 */
int Adresse::getNumRue() const
{
	return m_numRue;
}

/*
 * \brief accesseur
 *
 * \return le nomde la province
 */
const std::string& Adresse::getProvince() const
{
	return m_province;
}
/*
 * \brief accesseur
 *
 * \return le nom de la ville
 */
const std::string& Adresse::getVille() const
{
	return m_ville;
}

/*
 * \brief mutateur modifie l'adresse courante
 */
void Adresse::setAdresse(const std::string& adresse)
{
	m_adresse = adresse;
}

/*
 * \brief mutateur modifie le code zip
 */
void Adresse::setCodePostale(const std::string& codePostale)
{
	m_codePostale = codePostale;
}

/*
 * \brief mutateur modifie le nom de la rue
 */
void Adresse::setNomRue(const std::string& nomRue)
{
	m_nomRue = nomRue;
}

/*
 * \brief mutateur le numero de la rue
 */
void Adresse::setNumRue(int numRue)
{
	m_numRue = numRue;
}

/*
 * \brief mutateur le nom de la province
 */
void Adresse::setProvince(const std::string& province)
{
	m_province = province;
}

/*
 * \brief mutateur modifie le nom de la ville
 */
void Adresse::setVille(const std::string& ville)
{
	m_ville = ville;
}

/*
 * \brief opérateur de sortie vers un flux pour l'afichage, l'écriture dans un fichier, etc.
 *
 * \param[in] p_os le flux de sortie
 * \param[in] p_adresse l'adresse à "sortir"
 *
 * \return un flux de sortie pour les appels en cascade
 */
std::ostream& operator<<(std::ostream& p_os, const Adresse& p_adresse)
{
	p_os << p_adresse.m_adresse << endl;
	return p_os;
}

/**
 * \brief Teste l'invariant de la classe adresse. L'invariant de cette classe s'assure que l'adresse est valide
 */
void Adresse::verifieInvariant() const
{

	INVARIANT(m_numRue > 0);
	INVARIANT(!m_codePostale.empty());
	INVARIANT(!m_nomRue.empty());
	INVARIANT(!m_province.empty());
	INVARIANT(!m_ville.empty());

}

} //namespace util

