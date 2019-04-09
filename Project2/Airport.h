//
// Created by student on 26.10.2018.
//

#ifndef PROJECT2_AIRPORT_H
#define PROJECT2_AIRPORT_H

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "Event.h"

using namespace std;

class Airport {
public:
    //Constructs airport with luggage counters and security counters & if any of airline programs will be used
    Airport(int luggageCs, int securityCs, bool P1, bool P2, bool P3);

    //TODO IMPLEMENT HERE: Copy constructor, copy assign operator, Move constructor, move assign operator

    ~Airport();

    void addIncomingPassenger(const Passenger &passenger);

    void start();

    int getPassengerMissedFlight();

    double getAverageWaitingTime();

private:
    //Time in the airport
    int time = 0;
    //Number of luggage counters
    int luggageCs = 0;
    //Number of security counters
    int securityCs = 0;
    //Number of passengers arrived to the airport
    int passengersTotal = 0;
    //Number of passengers finished procedure
    int passengersFinished = 0;
    //Is all the passengers gone
    bool isAllFinished = false;
    //First-to-Fly First Serve
    bool P1 = false;
    //No Security Check for VIP
    bool P2 = false;
    //Using Online Ticketing
    bool P3 = false;
    //Number of passengers missed her flight
    int passengerMissedFlight = 0;
    //Average waiting time
    double averageWaitingTime = 0;

    queue<Passenger> incomingPassengers;
    queue<Passenger> luggageQueue;
    queue<Passenger> securityQueue;

    priority_queue<Passenger> luggage_PriorityQueue;
    priority_queue<Passenger> security_PriorityQueue;

    list<Passenger> luggageCounters;
    list<Passenger> securityCounters;

    void executeOneCycle();

    void executeLeaveSecurityCounter(Passenger *passenger);

    void executeLeaveLuggageCounter(Passenger *passenger);

    void executeArriveAirport(Passenger *passenger);

    void goToLuggageCheck(Passenger *passenger);

    void goToSecurityCheck(Passenger *passenger);

    void finishProcedure(Passenger *passenger);

    int findPositionLuggageCounter(Passenger *passenger);

    int findPositionSecurityCounter(Passenger *passenger);

};


#endif //PROJECT2_AIRPORT_H
