//
// Created by Buz on 5/3/2022.
//

#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H


#include <string>

class Message {
    int id;
    std::string sender;
    std::string receiver;
    std::string content;
public:
    Message(); // constructor.
    Message(int, std::string, std::string, std::string); // constructor with params.
    Message& operator=(const Message&);
    Message(const Message&); // copy constructor.
    bool operator==(Message &);
    void setId(int);
    void setSender(std::string);
    void setReceiver(std::string);
    void setContent(std::string);
    std::string getSender();
    std::string getReceiver();
    std::string getContent();
    ~Message(); // destructor.
};



#endif //PROJECT_MESSAGE_H
