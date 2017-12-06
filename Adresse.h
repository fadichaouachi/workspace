/**
 * \file Adresse.h
 *
 * \brief  interface de la classe adresse
 * \author fadi chaouachi
 * \version 0.1
 * \date 2017-11-28
 */
#ifndef ADRESSE_H_
#define ADRESSE_H_

#include "ContratException.h"
#include<string>
#include<sstream>

namespace util
{
/**
 * \class Adresse
 * \brief modélise une adresse civique
 */
class Adresse
{
public:

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
	Adresse(int& p_numRue, const std::string& p_nomRue,
			const std::string& p_ville, const std::string& p_codePostale,
			const std::string& p_province);

	friend std::ostream& operator<<(std::ostream& p_os,
			const Adresse& p_adresse);

	/*!
	 * Voici les gets(accesseurs)
	 */
	const std::string& reqAdresse() const;
	std::string reqAdresseFormate() const;
	const std::string& getAdresse() const;
	const std::string& getCodePostale() const;
	const std::string& getNomRue() const;
	int getNumRue() const;
	const std::string& getProvince() const;
	const std::string& getVille() const;

	/**
	 * Voici les sets(mutateurs)
	 */
	//void asgAdresse(const std::string& p_adresse);
	void asgAdresse(const int& p_numRue, const std::string& p_nomRue,
			const std::string& p_ville, const std::string& p_codePostale,
			const std::string& p_province);
	void setAdresse(const std::string& adresse);
	void setCodePostale(const std::string& codePostale);
	void setNomRue(const std::string& nomRue);
	void setNumRue(int numRue);
	void setProvince(const std::string& province);
	void setVille(const std::string& ville);

private:
	/**
	 * \brief chaine de charactere represente l'adresse
	 */
	std::string m_adresse;
	/**
	 * \brief entier represente le numero de la rue
	 */
	int m_numRue;
	/**
	 * \brief chaine de charactere represente nom de la rue, nom de la ville, le code zip, le nom de la procinve
	 */
	std::string m_nomRue, m_ville, m_codePostale, m_province;
	void verifieInvariant() const;

};

}

#endif /* ADDRESSE_H_ */
