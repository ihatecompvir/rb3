#pragma once

#include "tour/TourProperty.h"
#include "tour/Tour.h"
#include "utl/Symbol.h"
#include "meta/FixedSizeSaveable.h"
#include <set>
class TourPropertyCollection : public FixedSizeSaveable {
    public:
    TourPropertyCollection();
    virtual ~TourPropertyCollection();
    virtual void SaveFixed(FixedSizeSaveableStream&);
    virtual void LoadFixed(FixedSizeSaveableStream&);
    void Clear();
    float GetPropertyValue(Symbol) const;
    void SetPropertyValue(Symbol, float);
    int SaveSize(int);

    std::map<Symbol, float> m_mapTourProperties;


};
