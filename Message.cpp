//
// Created by Buz on 5/3/2022.
//

#include "Message.h"
Message::Message() {

}

Message::Message(int ID, std::string name1, std::string name2, std::string m) {
    id = ID;
    sender = name1;
    receiver = name2;
    content = m;
}

Message::Message(const Message &m) {
    id = m.id;
    sender = m.sender;
    receiver = m.receiver;
    content = m.content;
}

void Message::setId(int ID) {
    id = ID;
}

void Message::setContent(std::string newContent) {
    content = newContent;
}

void Message::setReceiver(std::string newReceiver) {
    receiver = newReceiver;
}

void Message::setSender(std::string newSender) {
    sender = newSender;
}

std::string Message::getContent() {
    return content;
}

std::string Message::getReceiver() {
    return receiver;
}

std::string Message::getSender() {
    return sender;
}

Message &Message::operator=(const Message & m) {
    if(this != &m){
        id = m.id;
        sender = m.sender;
        receiver = m.receiver;
        content = m.content;
    }


    return *this;
}

bool Message::operator==(Message & m) {
    return(sender == m.sender) && (receiver == m.receiver) && (content == m.content);
}

Message::~Message() {

}