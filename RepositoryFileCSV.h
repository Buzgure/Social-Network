//
// Created by Buz on 5/15/2022.
//

#ifndef PROJECT_REPOSITORYFILECSV_H
#define PROJECT_REPOSITORYFILECSV_H
#include  "RepositoryFile.h"
#include <fstream>
#include <iostream>
template <class T>
class RepositoryFileCSV:
        public RepositoryFile<T>{
    /// File repository for users.
public:
    RepositoryFileCSV();
    RepositoryFileCSV(const char*);
    void loadFromFile();
    void saveToFile();
    ~RepositoryFileCSV();
    void add(T&);
    int find(T&);
    int size();
    void remove(T&);
    void update(T, T);


};
template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV()
{
}

template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName):RepositoryFile<T>(fName)
{
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
    std::string line;
    ifstream  f(RepositoryFile<T>::fileName);
    if(!f.is_open())
        std::cout<<"ERROR";
    while (getline(f,line)){
        T ob(line, ',');
        Repository<T>::elems.push_back(ob);
    }
}

template<class T>
void RepositoryFileCSV<T>::saveToFile()
{

    ofstream f(RepositoryFile<T>::fileName);
    for(T crt : Repository<T>::elems){
        f << crt.toStringDelimiter(',') << endl;
    }
}


template<class T>
void RepositoryFileCSV<T>::add(T & t) {
    this->elems.push_back(t);
    this->saveToFile();
}
template<class T>
int RepositoryFileCSV<T>::find(T & t) {
    for(int i = 0; i< this->elems.size();i++)
        if(this->elems[i] == t)
            return i;
    return -1;
}
template<class T>
int RepositoryFileCSV<T>::size() {
    return this->elems.size();
}

template<class T>
void RepositoryFileCSV<T>::remove(T &t) {
//    auto it = std::find(this->elems.begin(), this->elems.end(), t);
    int pos = find(t);
    this->elems.erase(this->elems.begin() + pos);
    this->saveToFile();
//    if(it != this->elems.end()){
//        this->elems.erase(it);
//        this->saveToFile();
//    }
}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV() = default;

template<class T>
void RepositoryFileCSV<T>::update(T t, T t1) {
    int pos = find(t);
    this->elems[pos] = t1;
    this->saveToFile();
}


#endif //PROJECT_REPOSITORYFILECSV_H
