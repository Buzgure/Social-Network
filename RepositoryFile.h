//
// Created by Buz on 5/15/2022.
//

#ifndef PROJECT_REPOSITORYFILE_H
#define PROJECT_REPOSITORYFILE_H
#include "Repository.h"
template <class T> class RepositoryFile: public Repository<T> {
protected:
    const char* fileName;
public:
    RepositoryFile();
    RepositoryFile(const char*);
    virtual void saveToFile();
    virtual void loadFromFile();
    ~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile():Repository<T>()
{
}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* name)
{
    fileName = name;
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
}

template<class T>
void RepositoryFile<T>::loadFromFile()
{
}


#endif //PROJECT_REPOSITORYFILE_H
