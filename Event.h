//
// Created by Buz on 4/12/2022.
//

#ifndef PROJECT_EVENT_H
#define PROJECT_EVENT_H
#include <iostream>

using namespace std;
class Event {
    std::string name; // Name of the event.
    std::string date; // Date of the Event.
    std::string time;
    std::string location; // Location of the event.
    std::string user; // Who created the event.
public:
    Event(std::string ,std::string, std::string, std::string, std::string); // constructor with params.
    void setName(std::string);
    void setDate(std::string);
    void setTime(std::string);
    void setLocation(std::string);
    void setUser(std::string);
    std::string getName();
    std::string getDate();
    std::string getTime();
    std::string getLocation();
    std::string getUser();
    bool operator==(Event const &e); // overload of the == operator
    bool operator!=(Event const &e); // overload of the != operator

    friend ostream& operator<<(ostream &, const Event &); // overload of the << operator
};


#endif //PROJECT_EVENT_H
