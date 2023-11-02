/*
 * theatre.cpp
 *
 *  Created on: Nov 2, 2023
 *      Author: keith
 */
#include "theatre.h"

theatre::theatre(int cap):cap(cap),num_people_in_theatre(0) {
}


//m serves as the doorman
bool theatre::enter(){
	std::lock_guard<std::mutex> lck(m);
	//if full cannot go in
	if(num_people_in_theatre==cap)
		return false;

	//otherwise enter
	num_people_in_theatre++;
	return true;
}

int theatre::howmanypeopleinside(){
	std::lock_guard<std::mutex> lck(m);
	return num_people_in_theatre;
}

