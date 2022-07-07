cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp SimplyLinkedList.cpp SimplyLinkedList.h Event.cpp Event.h MultiMap.cpp MultiMap.h Message.cpp Message.h Repository.cpp Repository.h RepositoryFile.cpp RepositoryFile.h RepositoryFileCSV.cpp RepositoryFileCSV.h User.cpp User.h UserInterface.cpp UserInterface.h Service.cpp Service.h Utils.cpp Utils.h RepoFriend.cpp RepoFriend.h MessageRepository.cpp MessageRepository.h EventRepository.cpp EventRepository.h)
