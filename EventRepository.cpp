//
// Created by Buz on 5/23/2022.
//

#include "EventRepository.h"
EventRepository::EventRepository() {

}

void EventRepository::addEvent(Event e) {
    lE.insert(e);
}

void EventRepository::deleteEvent(Event e) {
    lE.deleteNode(e);
}

EventRepository::~EventRepository() {

}

std::vector<Event> EventRepository::showEvents() {
/// Returns a vector containing all the events.

    return lE.iterator();
}

EventRepository::EventRepository(const EventRepository & eR) {
    lE = eR.lE;
}

SimplyLinkedList<Event> EventRepository::showAll() {
    /// Returns a list with al the events.
    return this->lE;
}

Event EventRepository::findEvent(std::string n) {
    /// Function for finding a certain event by it's name.
    vector<Event> vE = lE.iterator();
    for(auto &it: vE)
        if(it.getName() == n)
            return it;

}
