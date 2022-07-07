//
// Created by Buz on 5/23/2022.
//

#ifndef PROJECT_EVENTREPOSITORY_H
#define PROJECT_EVENTREPOSITORY_H
#include "SimplyLinkedList.h"
#include "Event.h"
class EventRepository {
    SimplyLinkedList<Event> lE; // container of the events.
public:
    EventRepository(); // constr .
    EventRepository(const EventRepository&); // copy constr.
    void addEvent(Event);
    void deleteEvent(Event);
    Event findEvent(std::string);
    std::vector<Event> showEvents();
    SimplyLinkedList<Event> showAll();
    ~EventRepository(); // destructor.
};


#endif //PROJECT_EVENTREPOSITORY_H
