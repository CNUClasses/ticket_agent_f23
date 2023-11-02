/*
 * theatre.h
 *
 *  Created on: Nov 2, 2023
 *      Author: keith
 */

#ifndef THEATRE_H_
#define THEATRE_H_
#include <mutex>;

class theatre {
public:
	theatre(int cap);
	bool enter();
	int howmanypeopleinside();
private:
	int num_people_in_theatre;
	int cap;
	std::mutex m;
};

#endif /* THEATRE_H_ */
