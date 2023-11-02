/*
 * TicketAgent.h
 *
 *  Created on: Oct 31, 2023
 *      Author: keith
 */

#ifndef TICKETAGENT_H_
#define TICKETAGENT_H_

class TicketAgent {
public:
	TicketAgent(int id);
	virtual ~TicketAgent();

	//sell nt tickets
	//return number tickets sold
	//if return 0, then out of tickets
	int selltickets();

private:
	int id;
	int ns;
};

#endif /* TICKETAGENT_H_ */
