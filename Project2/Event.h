//
// Created by student on 07.11.2018.
//

#ifndef PROJECT2_EVENT_H
#define PROJECT2_EVENT_H

#include <list>
#include "Passenger.h"

enum Type{ArriveAirport,LeaveLuggageCounter,LeaveSecurityCounter,NullType};

struct Event {
public:
    Type eventType;
    int executionTime;
    Passenger* passenger;
    int listPosition;

    //Default constructor
    Event();
    //Constructor with given information
    Event(Type eventType, int executionTime, Passenger* passenger);
    //Constructor with given information + given position in the list
    Event(Type eventType, int executionTime, Passenger* passenger,int listPosition);
    //Copy constructor
    Event(const Event &other);
    //Move constructor
    Event(Event &&other);
    //Copy assign operator
    Event&operator=(const Event &other);
    //Move assign operator
    Event&operator=(Event &&other);
    //Destructor
    ~Event();

    //Equals operator
    bool operator==(const Event &other) const ;

    //Greater than operator
    bool operator>(const Event &other) const ;

    //Less than operator
    bool operator<(const Event &other) const ;

};


#endif //PROJECT2_EVENT_H
