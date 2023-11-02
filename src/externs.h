/*
 * externs.h
 *
 *  Created on: Nov 2, 2023
 *      Author: keith
 */

#ifndef EXTERNS_H_
#define EXTERNS_H_
#include <mutex>
#include "theatre.h"
extern int numtickets;
extern std::mutex m;
extern std::mutex m_cout;
extern int numbsold;
extern int MAX_CAP;
extern theatre t1;
extern theatre t2;

#endif /* EXTERNS_H_ */
