#include "LinkedList.h"

//Default Constructor
LinkedList::LinkedList() {
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList &list) {
    this->length = list.length;
    //Construct head
    if(length > 0){
        this->head = new Node(*(list.head));
    }
    //Find tail
    Node* temp = this->head;
    while(temp && temp->next){
        temp = temp->next;
    }
    this->tail = temp;
}

//Copy assign operator
LinkedList& LinkedList::operator=(const LinkedList &list) {
    this->length = list.length;
    //To avoid memory leak
    if (this->head) {
        delete this->head;
    }
    this->head = new Node(*(list.head));

    //Find tail
    Node *temp = this->head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    this->tail = temp;

    return *this;
}

//Move constructor
LinkedList::LinkedList(LinkedList &&list) {
    this->length = move(list.length);
    this->head = move(list.head);

    //Find tail
    Node *temp = this->head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    this->tail = temp;

    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
}

//Move assign operator
LinkedList& LinkedList::operator=(LinkedList &&list) {
    this->length = move(list.length);
    if(this->head->next)
        delete this->head->next;

    this->head = move(list.head);

    //Find tail
    Node *temp = this->head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    this->tail = temp;

    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return *this;
}

//Insert new element to the back of list
void LinkedList::pushTail(string _name, float _amount) {
    //If list is empty
    if(length == 0){
        this->head = new Node(_name,_amount);
        this->tail = head;
        this->length++;
        return;
    }
    //Find last element
    Node* temp = this->head;
    while(temp->next){
        temp = temp->next;
    }
    //Insert new node
    temp->next = new Node(_name,_amount);
    //Change the tail
    this->tail = temp->next;
    this->length++;
}

//Updates the amount of given name
void LinkedList::updateNode(string _name, float _amount) {
    //If list is empty
    if(length == 0){
        return;
    }

    Node* temp = this->head;
    while(temp){
        if(temp->name == _name){
            temp->amount = _amount;
            break;
        }
        temp = temp->next;
    }

}

//Destructor
LinkedList::~LinkedList() {
    if(this->head){
        delete this->head;
    }
}
