#include "SurveyClass.h"

float twoDecimal(float f);

//Default Constructor
SurveyClass::SurveyClass() {
    this->members = new LinkedList;
}

//Copy Constructor
SurveyClass::SurveyClass(const SurveyClass &other) {
    this->members = new LinkedList(*other.members);
}

//Copy assign operator
SurveyClass& SurveyClass::operator=(const SurveyClass &other) {
    if(this->members)
        delete this->members;

    this->members = new LinkedList(*other.members);
    return *this;
}

//Move constructor
SurveyClass::SurveyClass(SurveyClass &&other) {
    this->members = move(other.members);
}

//Move assign operator
SurveyClass& SurveyClass::operator=(SurveyClass &&other) {
    if(this->members)
        delete this->members;

    this->members = move(other.members);
    return *this;
}

// Calculates and returns the average amount of expense.
// The average amount can have up to two decimal points.
float SurveyClass::calculateAverageExpense() {
    float sum = 0;
    int length = members->length;
    Node* temp = members->head;
    while(temp){
        sum += temp->amount;
        temp = temp->next;
    }
    float result = sum/length;
    return twoDecimal(result);
}

// Calculates and returns the maximum amount of expense.
// The maximum amount can have up to two decimal points.
float SurveyClass::calculateMaximumExpense() {
    if(members->length == 0){
        return -1;
    }
    Node* temp = members->head;
    float max = temp->amount;
    temp = temp->next;
    while(temp){
        if(max < temp->amount){
            max = temp->amount;
        }
        temp = temp->next;
    }
    return twoDecimal(max);
}

// Calculates and returns the minimum amount of expense.
// The minimum amount can have up to two decimal points.
float SurveyClass::calculateMinimumExpense() {
    if(members->length == 0){
        return -1;
    }
    Node* temp = members->head;
    float min = temp->amount;
    temp = temp->next;
    while(temp){
        if(min > temp->amount){
            min = temp->amount;
        }
        temp = temp->next;
    }
    return twoDecimal(min);
}

// Adds a new Node to the linked list or updates the corresponding Node in the linked list
void SurveyClass::handleNewRecord(string _name, float _amount) {
    Node* temp = members->head;
    while(temp){
        if(temp->name == _name){
            members->updateNode(_name,_amount);
            return;
        }
        temp = temp->next;
    }
    members->pushTail(_name,_amount);
}

float twoDecimal(float f){
    f *=100;
    int rounded = f;
    f = rounded;
    f = f / 100.0;
    return f;
}

//Destructor
SurveyClass::~SurveyClass() {
    if(this->members){
        delete this->members;
    }
}