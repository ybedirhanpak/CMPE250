//
// Created by ybedi on 26.10.2018.
//

#ifndef PROJECT2_PASSENGER_H
#define PROJECT2_PASSENGER_H

#include <iostream>
using namespace std;

class Passenger {
public:
    //Variables given as input
    int arrivalTime;
    int boardTime;
    int luggageTime;
    int securityTime;
    char VIP;
    char luggage;

    int arrivalToLuggageC = 0;
    int arrivalToSecurityC = 0;
    int arrivalToBoard = 0;

    int totalWaitingTime = 0;

    //Default constructor
    Passenger();
    //Constructor with given information
    Passenger(int arrivalTime,int boardTime,int luggageTime,int securityTime,char VIP,char luggage);
    //Copy constructor
    Passenger(const Passenger& other);
    //Move constructor
    Passenger(Passenger&& other);
    //Copy assign operator
    Passenger& operator=(const Passenger& other);
    //Move assign operator
    Passenger& operator=(Passenger&& other);
    //Destructor
    ~Passenger();

    //Less than operator
    bool operator<(const Passenger& other) const;

    //Greater than operator
    bool operator>(const Passenger& other) const;

    //Equals operator
    bool operator==(const Passenger& other) const;

};


#endif //PROJECT2_PASSENGER_H
