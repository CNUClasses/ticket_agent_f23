#include <iostream>
#include <mutex>
#include "TicketAgent.h"
#include "externs.h"
using namespace std;

void report(string s){
	lock_guard<mutex> lck(m_cout);
	cout<<s<<endl;
}
TicketAgent::TicketAgent(int id):id(id),ns(0) {
	report("Agent "+to_string(id)+" starting work");
}

TicketAgent::~TicketAgent() {
	report("Agent "+to_string(id)+" finished work and sold "+to_string(ns)+" tickets");

	//add to the global tally
	lock_guard<mutex> lck(m);
	numbsold+=ns;
}

int TicketAgent::selltickets(){
	{
		lock_guard<mutex> lck(m);
		if(numtickets==0)
			return 0;
		numtickets--;
	}
	ns++;

	report("   Agent "+to_string(id)+" sold a ticket");

	if(!t1.enter())
		if(!t2.enter())
			report("Oh No! cannot get in");

	return 1;
}

