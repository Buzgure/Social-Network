//
// Created by Buz on 5/15/2022.
//

#ifndef PROJECT_REPOSITORY_H
#define PROJECT_REPOSITORY_H
#include<vector>
#include <algorithm>

using namespace std;
template<class T> class Repository {
    ///Template repository used for users.
protected:
    vector<T> elems;
public:
    Repository();
    Repository(const Repository&);
    void addElem(T& b);
    vector<T> getAll();
    int search(T&);
    void modifyElem(int , T &);
    void deleteElem(int pos);
    T elemAt(int pos);
    int size();
};

template<class T>
Repository<T>::Repository() = default;
template<class T>
void Repository<T>::addElem(T &b){
    elems.template emplace_back(b);
}
template<class T>
vector<T> Repository<T>::getAll() {
    return elems;
}
template<class T>
Repository<T>::Repository(const Repository &r) {
    elems = r.elems;
}
template<class T>
int Repository<T>::size() {
    return elems.size();
}
template<class T>
T Repository<T>::elemAt(int pos) {
    return elems[pos];
}
template<class T>
void Repository<T>::deleteElem(int pos) {
    elems.erase(elems.begin() + pos);
}
template<class T>
void Repository<T>::modifyElem(int id, T& e) {
    for(auto & elem : elems)
        if(elem.getId() == id)
            elem = e;

}
template<class T>
int Repository<T>::search(T &e) {
    for(int i = 0; i< elems.size(); i++)
        if(elems[i] == e)
            return i;
    return -1;
}


#endif //PROJECT_REPOSITORY_H
