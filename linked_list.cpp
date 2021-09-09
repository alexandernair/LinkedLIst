#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

void MyList::add(string name, int score) {
    MyNode *addNode = new MyNode(name, score);
    if(_size == 0){
        _headPtr = addNode;
        _tailPtr = addNode;
        _marker = addNode; 
    }else{
        _tailPtr->setNext(addNode);
        _tailPtr = addNode;
    }
    _size++;
}

void MyList::clear() {
    _marker = _headPtr;
    _prevPtr = nullptr;
    while(_marker != nullptr){
        _prevPtr = _marker;
        _marker = _marker->next();
        delete _prevPtr;
        _size--;
    }
    _headPtr = nullptr;
    _prevPtr = nullptr;
    _tailPtr = nullptr;
}

bool MyList::remove(string name) {
   if(_size == 0){
       return false;
   }
   _marker = _headPtr;
   _prevPtr = nullptr;

   if(_marker->name() == name){
       _headPtr = _marker->next();
       delete _marker;
       _size--;
       return true;
   }
    while(_marker->next() != nullptr){
        _prevPtr = _marker;
        _marker = _marker->next();
        if(_marker->name() == name){
            _prevPtr->setNext(_marker->next());
            delete _marker;
            _size--;
            return true;
        }
    }
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO
    //check if index is last
    if(index > _size || index < 0){
        return false;
    }
    if(index == _size){
        add(name, score);
        return true;
    }
    //check if index is first
    if(index == 0){
         MyNode *insert = new MyNode(name, score);
        insert->setNext(_headPtr);
        _headPtr = insert;
        _size++;
        return true;
 
    }else{

        MyNode *insert = new MyNode(name, score);
        _marker = _headPtr;
        _prevPtr = nullptr;
        size_t count = 0;

        while(count <= index){ 
            count++;
            if(count == index){
                insert->setNext(_marker->next());
                _marker->setNext(insert);
                _size++;
                return true;
            }
        _prevPtr = _marker;
        _marker = _marker->next();
        }
    }
    return false;

}

MyList::MyList() {
    _size = 0;
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _marker = nullptr;
}

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() {
    return _headPtr;
}

void MyList::printList() {
    _marker = _headPtr;
    if (_marker == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    while (_marker != nullptr) {
        cout << "[ " << _marker->name() << ", " << _marker->score() << " ]" << endl;
        _marker = _marker->next();
    }
}

MyNode::MyNode(std::string name, int score) {
    _name = name;
    _score = score;
    _nextPtr = nullptr;
}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}