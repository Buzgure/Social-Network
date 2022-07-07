//
// Created by Buz on 5/21/2022.
//

#include "MessageRepository.h"
MessageRepository::MessageRepository() {

}

void MessageRepository::addMessage(Message m) {
    sll.insert(m);
}

void MessageRepository::deleteMessage(Message m) {
    sll.deleteNode(m);
}

MessageRepository::~MessageRepository() {

}

std::vector<Message> MessageRepository::showMessages() {
/// Returns a vector containing all the messages.
    return sll.iterator();

}
MessageRepository::MessageRepository(const MessageRepository &mR) {
    sll = mR.sll;
}

SimplyLinkedList<Message> MessageRepository::showAll() {
    /// Returns a list containing all the events.
    return this->sll;
}