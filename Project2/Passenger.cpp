//
// Created by ybedi on 26.10.2018.
//

#include "Passenger.h"

Passenger::Passenger() {
    this->arrivalTime = 0;
    this->boardTime = 0;
    this->luggageTime = 0;
    this->securityTime = 0;
    this->VIP = ' ';
    this->luggage = ' ';

    this->arrivalToLuggageC = 0;
    this->arrivalToSecurityC = 0;
    this->arrivalToBoard = 0;

    this->totalWaitingTime = 0;
}

Passenger::Passenger(int arrivalTime, int boardTime, int luggageTime, int securityTime, char VIP, char luggage) {
    this->arrivalTime = arrivalTime;
    this->boardTime = boardTime;
    this->luggageTime = luggageTime;
    this->securityTime = securityTime;
    this->VIP = VIP;
    this->luggage = luggage;

    this->arrivalToLuggageC = 0;
    this->arrivalToSecurityC = 0;
    this->arrivalToBoard = 0;

    this->totalWaitingTime = 0;
}

//Copy Constructor
Passenger::Passenger(const Passenger &other) {
    this->arrivalTime = other.arrivalTime;
    this->boardTime = other.boardTime;
    this->luggageTime = other.luggageTime;
    this->securityTime = other.securityTime;
    this->VIP = other.VIP;
    this->luggage = other.luggage;

    this->arrivalToLuggageC = other.arrivalToLuggageC;
    this->arrivalToSecurityC = other.arrivalToSecurityC;
    this->arrivalToBoard = other.arrivalToBoard;

    this->totalWaitingTime = other.totalWaitingTime;
}

//Copy assignment operator
Passenger& Passenger::operator=(const Passenger &other) {
    this->arrivalTime = other.arrivalTime;
    this->boardTime = other.boardTime;
    this->luggageTime = other.luggageTime;
    this->securityTime = other.securityTime;
    this->VIP = other.VIP;
    this->luggage = other.luggage;

    this->arrivalToLuggageC = other.arrivalToLuggageC;
    this->arrivalToSecurityC = other.arrivalToSecurityC;
    this->arrivalToBoard = other.arrivalToBoard;

    this->totalWaitingTime = other.totalWaitingTime;

    return *this;
}

//Move constructor
Passenger::Passenger(Passenger &&other) {
    this->arrivalTime = move(other.arrivalTime);
    this->boardTime = move(other.boardTime);
    this->luggageTime = move(other.luggageTime);
    this->securityTime = move(other.securityTime);
    this->VIP = move(other.VIP);
    this->luggage = move(other.luggage);

    this->arrivalToLuggageC = move(other.arrivalToLuggageC);
    this->arrivalToSecurityC = move(other.arrivalToSecurityC);
    this->arrivalToBoard = move(other.arrivalToBoard);

    this->totalWaitingTime = move(other.totalWaitingTime);

    other.arrivalTime = 0;
    other.boardTime = 0;
    other.luggageTime = 0;
    other.securityTime = 0;
    other.VIP = ' ';
    other.luggage = ' ';

    other.arrivalToLuggageC = 0;
    other.arrivalToSecurityC = 0;
    other.arrivalToBoard = 0;

    other.totalWaitingTime = 0;

}

//Move assign operator
Passenger& Passenger::operator=(Passenger &&other) {
    this->arrivalTime = move(other.arrivalTime);
    this->boardTime = move(other.boardTime);
    this->luggageTime = move(other.luggageTime);
    this->securityTime = move(other.securityTime);
    this->VIP = move(other.VIP);
    this->luggage = move(other.luggage);

    this->arrivalToLuggageC = move(other.arrivalToLuggageC);
    this->arrivalToSecurityC = move(other.arrivalToSecurityC);
    this->arrivalToBoard = move(other.arrivalToBoard);

    this->totalWaitingTime = move(other.totalWaitingTime);

    other.arrivalTime = 0;
    other.boardTime = 0;
    other.luggageTime = 0;
    other.securityTime = 0;
    other.VIP = ' ';
    other.luggage = ' ';

    other.arrivalToLuggageC = 0;
    other.arrivalToSecurityC = 0;
    other.arrivalToBoard = 0;
    other.totalWaitingTime = 0;

    return *this;
}

//Less than operator. Compares the boardTime of two passengers
bool Passenger::operator<(const Passenger &other) const {
    if(this->boardTime == other.boardTime){
        return (this->arrivalTime > other.arrivalTime);
    }
    return (this->boardTime > other.boardTime);
}

//Greater than operator. Compares the boardTime of two passengers
bool Passenger::operator>(const Passenger &other) const {
    if(this->boardTime == other.boardTime){
        return (this->arrivalTime < other.arrivalTime);
    }
    return (this->boardTime < other.boardTime);
}

//Equals operator. Compares the boardTime of two passengers
bool Passenger::operator==(const Passenger &other) const {
    return (this->boardTime == other.boardTime);
}
//Destructor
Passenger::~Passenger() {

}
