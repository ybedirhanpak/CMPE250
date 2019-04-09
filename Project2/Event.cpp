//
// Created by student on 07.11.2018.
//

#include "Event.h"

Event::Event() {
    this->eventType = NullType;
    this->executionTime = -1;
    this->passenger = nullptr;
    this->listPosition = -1;
}

Event::Event(Type eventType, int executionTime, Passenger *passenger) {
    this->eventType = eventType;
    this->executionTime = executionTime;
    this->passenger = passenger;
    this->listPosition = -1;
}

Event::Event(Type eventType, int executionTime, Passenger *passenger, int listPosition) {
    this->eventType = eventType;
    this->executionTime = executionTime;
    this->passenger = passenger;
    this->listPosition = listPosition;
}

Event::Event(const Event &other) {
    this->eventType = other.eventType;
    this->executionTime = other.executionTime;
    this->passenger = other.passenger;
    this->listPosition = other.listPosition;
}

Event::Event(Event &&other) {
    this->eventType = move(other.eventType);
    this->executionTime = move(other.executionTime);
    this->passenger = move(other.passenger);
    this->listPosition = move(other.listPosition);

    other.eventType = NullType;
    other.executionTime = -1;
    other.passenger = nullptr;
    other.listPosition = -1;
}

Event& Event::operator=(const Event &other) {
    this->eventType = other.eventType;
    this->executionTime = other.executionTime;
    this->passenger = other.passenger;
    this->listPosition = other.listPosition;
    return *this;
}

Event& Event::operator=(Event &&other) {
    this->eventType = move(other.eventType);
    this->executionTime = move(other.executionTime);
    this->passenger = move(other.passenger);
    this->listPosition = move(other.listPosition);

    other.eventType = NullType;
    other.executionTime = -1;
    other.passenger = nullptr;
    other.listPosition = -1;
    return *this;
}

bool Event::operator==(const Event &other) const {
    return this->executionTime == other.executionTime;
}

bool Event::operator<(const Event &other) const {
    if(this->executionTime == other.executionTime){
        if(this->eventType == other.eventType){
            return this->passenger->arrivalTime > other.passenger->arrivalTime;
        }else{
            return this->eventType < other.eventType;
        }
    }
    return this->executionTime > other.executionTime;
}

bool Event::operator>(const Event &other) const {
    if(this->executionTime == other.executionTime){
        if(this->eventType == other.eventType){
            return this->passenger->arrivalTime < other.passenger->arrivalTime;
        }else{
            return this->eventType > other.eventType;
        }
    }
    return this->executionTime < other.executionTime;
}

Event::~Event() {

}
