//
// Created by Buz on 5/21/2022.
//

#ifndef PROJECT_MESSAGEREPOSITORY_H
#define PROJECT_MESSAGEREPOSITORY_H

#include <vector>
#include "SimplyLinkedList.h"
#include "Message.h"
class MessageRepository {
    SimplyLinkedList<Message> sll; // container of messages.
public:
    MessageRepository(); // constr
    MessageRepository(const MessageRepository&); // copy constructor.
    void addMessage(Message);
    void deleteMessage(Message);
    std::vector<Message> showMessages();
    SimplyLinkedList<Message> showAll();
    ~MessageRepository(); // destructor.
};


#endif //PROJECT_MESSAGEREPOSITORY_H
