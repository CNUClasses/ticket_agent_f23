
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include "TicketAgent.h"
#include "theatre.h"

const int NUM_TICKS=2000;
using namespace std;

//total number of tickets
int numtickets=NUM_TICKS;
int MAX_CAP=numtickets;
int numbsold=0;
mutex m;
mutex m_cout;
theatre t1(MAX_CAP/2);
theatre t2(MAX_CAP/2);

//
void agent(int id){
	TicketAgent ta(id);
	while(ta.selltickets()){}
}


int main() {
	std::vector<std::thread> vecThreads;

	//how many cores (2 virtual cores per physical core)
	int numbThreads = std::thread::hardware_concurrency();

	//lets start up 1 per core
	for (int i=0;i<numbThreads/2;i++){
		vecThreads.push_back(std::thread(agent,i));
	}

	//wait for em to finish
	for(auto& t : vecThreads){
		t.join();
	}

	cout<<"Numb tickets left="<<numtickets<<endl;
	cout<<"Numb tickets sold="<<numbsold<<endl;
	cout<<"Theatre t1 contains="<<t1.howmanypeopleinside()<<endl;
	return 0;
}
