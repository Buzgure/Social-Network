////
//// Created by Buz on 5/15/2022.
////
//
//#include "RepositoryFileCSV.h"
//#include <fstream>
//using namespace std;
//template<class T>
//RepositoryFileCSV<T>::RepositoryFileCSV()
//{
//}
//
//template<class T>
//inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName):RepositoryFile<T>(fName)
//{
//}
//
//template<class T>
//void RepositoryFileCSV<T>::loadFromFile()
//{
//    string line;
//    ifstream f(RepositoryFile<T>::fileName);
//    while (getline(f, line)) {
//        T ob(line, ',');
//        Repository<T>::elem.push_back(ob);
//    }
//}
//
//template<class T>
//void RepositoryFileCSV<T>::saveToFile()
//{
//    ofstream f(RepositoryFile<T>::fileName);
//    for (T crt : Repository<T>::elem) {
//        f << crt.toStringDelimiter(',')<<endl;
//    }
//}
//
//template<class T>
//RepositoryFileCSV<T>::~RepositoryFileCSV()
//{
//}
//template<class T>
//void RepositoryFileCSV<T>::add(T & t) {
//    this->elems.push_back(t);
//    this->saveToFile();
//}
//template<class T>
//int RepositoryFileCSV<T>::find(T & t) {
//    for(int i = 0; i< this->elems.size();i++)
//        if(this->elems[i] == t)
//            return i;
//    return -1;
//}
//template<class T>
//int RepositoryFileCSV<T>::size() {
//    return this->elems.size();
//}
//
//template<class T>
//void RepositoryFileCSV<T>::remove(T &t) {
//    auto it = std::find(this->elems.begin(), this->elems.end(), t);
//    if(it != this->elems.end()){
//        this->elems.erase(it);
//        this->saveToFile();
//    }
//}