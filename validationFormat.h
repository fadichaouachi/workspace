/*
 * validationFormat.h
 *
 *  Created on: 2017-10-01
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
namespace util
{

bool validerNas(const string& p_nas);
bool validerFormatFichier(std::istream& p_is);


}
#endif /* VALIDATIONFORMAT_H_ */

