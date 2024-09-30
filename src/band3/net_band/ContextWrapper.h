#ifndef NETBAND_CONTEXTWRAPPER_H
#define NETBAND_CONTEXTWRAPPER_H
#include "system/obj/Object.h"
#include "DataResults.h"

class ContextWrapper {
public:
    Hmx::Object *mCallbackObject;
    void *mUpdatable;
    bool mDeleteUpdatable;

    int mId;
    void *mContext; // protocolcallcontext *

    Timer mTimeout;
};

#endif // NETBAND_CONTEXTWRAPPER_H