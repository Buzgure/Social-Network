//
// Created by Buz on 4/12/2022.
//

#include <cstring>
#include "Event.h"
Event::Event(std::string name, std::string date, std::string time, std::string location, std::string user) {

    this->name = name;
    this->date = date;
    this->time = time;
    this->location = location;
    this->user = user;

}
bool Event::operator==(const Event &e) {
    if(this->name == e.name)
        return true;
    return false;
}

bool Event::operator!=(const Event &e) {
    return(this->name != e.name);
}

ostream& operator<<(ostream &os, const Event &f){
    os << f.name << " " << f.date << " " << f.time<< " "<< f.location<<" created by "<< f.user;
    return os;
}

void Event::setName(std::string n) {
    this->name = n;
}

void Event::setDate(std::string d) {
    this->date = d;
}

void Event::setTime(std::string t) {
    this->time = t;
}

void Event::setLocation(std::string l) {
    this->location = l;
}

std::string Event::getName() {
    return this->name;
}

std::string Event::getDate() {
    return this->date;
}

std::string Event::getTime() {
    return this->time;
}

std::string Event::getLocation() {
    return this->location;
}

void Event::setUser(std::string user) {
    this->user = user;
}

std::string Event::getUser() {
    return this->user;
}



