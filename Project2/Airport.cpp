//
// Created by student on 26.10.2018.
//

#include "Airport.h"

//Constructs the airport with given luggage counter and security counter numbers.
Airport::Airport(int luggageCs, int securityCs, bool P1, bool P2, bool P3) {
    this->luggageCs = luggageCs;
    this->securityCs = securityCs;
    this->P1 = P1;
    this->P2 = P2;
    this->P3 = P3;
}

//Adds incoming Passengers to the incomingPassengers queue.
void Airport::addIncomingPassenger(const Passenger &passenger) {
    this->incomingPassengers.push(passenger);
    this->passengersTotal++;
}
//Starts the simulation
void Airport::start() {
    while(!isAllFinished){
        executeOneCycle();
    }
}

int Airport::getPassengerMissedFlight() {
    return passengerMissedFlight;
}

double Airport::getAverageWaitingTime() {
    return averageWaitingTime;
}

void Airport::executeOneCycle() {
    //Take data from the current positions of the passengers and construct the event queue
    priority_queue<Event> events;

    //Security Counter
    int securityPosition=0;

    for(list<Passenger>::iterator itr = securityCounters.begin(); itr != securityCounters.end();++itr){
        int executionTime = itr->securityTime - (time - itr->arrivalToSecurityC);
        Event nextEvent(LeaveSecurityCounter,executionTime,&(*itr),securityPosition++);
        events.push(nextEvent);
    }

    //Luggage Counter
    int luggagePosition=0;
    for(list<Passenger>::iterator itr = luggageCounters.begin(); itr != luggageCounters.end(); ++itr){
        int executionTime = itr->luggageTime - (time - itr->arrivalToLuggageC);
        Event nextEvent(LeaveLuggageCounter,executionTime,&(*itr),luggagePosition++);
        events.push(nextEvent);
    }
    //Incoming Passenger
    if(!incomingPassengers.empty()){
        Passenger *next = &incomingPassengers.front();
        int executionTime = next->arrivalTime - time;
        Event nextEvent(ArriveAirport,executionTime,next);
        events.push(nextEvent);
    }

    //Execute next event
    const Event *eventToBeExecuted = &events.top();
    int prevExecutionTime=0;

    do{
        prevExecutionTime = eventToBeExecuted->executionTime;
        if (eventToBeExecuted->eventType == LeaveSecurityCounter) {
            executeLeaveSecurityCounter(eventToBeExecuted->passenger);
        }else if (eventToBeExecuted->eventType == LeaveLuggageCounter) {
            executeLeaveLuggageCounter(eventToBeExecuted->passenger);
        }else if (eventToBeExecuted->eventType == ArriveAirport) {
            executeArriveAirport(eventToBeExecuted->passenger);
        }
        events.pop();
        eventToBeExecuted = &events.top();
    }while(!events.empty() && eventToBeExecuted->executionTime == prevExecutionTime);

    if(passengersTotal == passengersFinished){
        isAllFinished = true;
    }
}

/**
 * Destructs the airport.
 */
Airport::~Airport() {
}

void Airport::executeLeaveSecurityCounter(Passenger *passenger) {
    //Let the passenger leave the security counter
    time += passenger->securityTime - (time - passenger->arrivalToSecurityC);
    finishProcedure(passenger);

    //Erase passenger from the securityCounters list.
    int listPosition = findPositionSecurityCounter(passenger);
    list<Passenger>::iterator position = securityCounters.begin();
    advance(position,listPosition);
    securityCounters.erase(position);

    //Let the next passenger in the security queue enter the counter
    if(P1){
        //Do the process for priority queue
        if(!security_PriorityQueue.empty()){
            const Passenger* next = &security_PriorityQueue.top();
            Passenger temp = *next;
            temp.arrivalToSecurityC = time;
            securityCounters.push_back(temp);
            security_PriorityQueue.pop();
        }
    }else{
        //Do the process for normal queue
        if(!securityQueue.empty()){
            Passenger* next = &securityQueue.front();
            next->arrivalToSecurityC = time;
            securityCounters.push_back(*next);
            securityQueue.pop();
        }
    }
}

void Airport::executeLeaveLuggageCounter(Passenger *passenger) {
    //Let the passenger leave the luggage counter
    time += passenger->luggageTime - (time - passenger->arrivalToLuggageC);

    if(P2){
        if(passenger->VIP == 'V'){
            //Finish procedure
            finishProcedure(passenger);
        }else{
            //Go to Security Check
            goToSecurityCheck(passenger);
        }
    }else{
        //Go to Security Check
        goToSecurityCheck(passenger);
    }

    //Erase passenger from the luggageCounters list.
    int listPosition = findPositionLuggageCounter(passenger);
    list<Passenger>::iterator position = luggageCounters.begin();
    advance(position,listPosition);
    luggageCounters.erase(position);

    //Let the next passenger in the luggage queue enter the luggage counter
    if(P1){
        //Do the process for priority queue
        if(!luggage_PriorityQueue.empty()){
            const Passenger* next = &luggage_PriorityQueue.top();
            Passenger temp = *next;
            temp.arrivalToLuggageC = time;
            luggageCounters.push_back(temp);
            luggage_PriorityQueue.pop();
        }
    }else{
        //Do the process for normal queue
        if(!luggageQueue.empty()){
            Passenger* next = &luggageQueue.front();
            next->arrivalToLuggageC = time;
            luggageCounters.push_back(*next);
            luggageQueue.pop();
        }
    }
}

void Airport::executeArriveAirport(Passenger *passenger) {
    //Let the passenger enter the airport
    time += passenger->arrivalTime - time;

    if(P3 && P2){
        if(passenger->luggage == 'N'){
            if(passenger->VIP == 'V'){
                //Finish procedure
                finishProcedure(passenger);
            }else{
                //Go to Security Part
                goToSecurityCheck(passenger);
            }
        }else{
            //Go to Luggage Part
            goToLuggageCheck(passenger);
        }
    }else{
        if(P3 && !P2){
            if(passenger->luggage == 'N'){
                //Go to Security Part
                goToSecurityCheck(passenger);
            }else{
                //Go to Luggage Part
                goToLuggageCheck(passenger);
            }
        }else{
            //Go to Luggage Part
            goToLuggageCheck(passenger);
        }
    }
    //Erase this passenger from the incoming passengers queue.
    incomingPassengers.pop();
}

void Airport::goToLuggageCheck(Passenger *passenger) {
    //Let passenger enter the luggage check
    if(P1){
        //Do process for priority queue
        if(luggage_PriorityQueue.empty() && luggageCounters.size() < luggageCs){
            passenger->arrivalToLuggageC = time;
            luggageCounters.push_back(*passenger);
        }else{
            luggage_PriorityQueue.push(*passenger);
        }
    }else{
        //Do process for normal queue
        if(luggageQueue.empty() && luggageCounters.size() < luggageCs){
            passenger->arrivalToLuggageC = time;
            luggageCounters.push_back(*passenger);
        }else{
            luggageQueue.push(*passenger);
        }
    }
}

void Airport::goToSecurityCheck(Passenger *passenger) {
    //Let passenger enter the security check
    if(P1){
        //Do process for priority queue
        if(security_PriorityQueue.empty() && securityCounters.size() < securityCs){
            passenger->arrivalToSecurityC = time;
            securityCounters.push_back(*passenger);
        }else{
            security_PriorityQueue.push(*passenger);
        }
    }else{
        //Do process for normal queue
        if(securityQueue.empty() && securityCounters.size() < securityCs){
            passenger->arrivalToSecurityC = time;
            securityCounters.push_back(*passenger);
        }else{
            securityQueue.push(*passenger);
        }
    }
}

void Airport::finishProcedure(Passenger *passenger) {
    //Let passenger finish his procedure and go to the flight.

    passenger->arrivalToBoard = time;
    //Determine if the passenger caught the flight
    if(passenger->arrivalToBoard <= passenger->boardTime){
    //cout<<"Passenger " << passenger->arrivalTime << " has caught the flight."<<endl;
    }else{
    //cout<<"Passenger " << passenger->arrivalTime << " has missed the flight."<<endl;
        passengerMissedFlight++;
    }

    //Increase total waiting time of this passenger and add the proportion to the averageWaitingTime
    passenger->totalWaitingTime = passenger->arrivalToBoard - passenger->arrivalTime;
    averageWaitingTime += (double)(passenger->totalWaitingTime) / passengersTotal;

    //Increase the number of passengers finished procedure
    passengersFinished++;

}

int Airport::findPositionLuggageCounter(Passenger *passenger) {
    int position=0;
    list<Passenger>::iterator itr = luggageCounters.begin();
    for(int i=0;i<luggageCs;i++){
        if(itr->arrivalTime!= passenger->arrivalTime){
            position++;
            ++itr;
        }else{
            return position;
        }
    }
    return position;
}

int Airport::findPositionSecurityCounter(Passenger *passenger) {
    int position=0;
    list<Passenger>::iterator itr = securityCounters.begin();
    for(int i=0;i<securityCs;i++){
        if(itr->arrivalTime != passenger->arrivalTime){
            position++;
            ++itr;
        }else{
            return position;
        }
    }
    return position;
}

