#ifndef NETBAND_DATARESULTS_H
#define NETBAND_DATARESULTS_H
#include "ContextWrapper.h"
#include "os/Debug.h"
#include "network/Platform/RootObject.h"

class Updatable : public Quazal::RootObject {
public:
    void SetWrapper(ContextWrapper *);
    virtual ~Updatable();
    
    // todo: fill out members
};

class DataResultList : public Updatable {
public:
    DataResultList();
    virtual ~DataResultList();
    virtual void Update();
    void Clear();

    // todo: fill out members
};

#endif // NETBAND_DATARESULTS_H