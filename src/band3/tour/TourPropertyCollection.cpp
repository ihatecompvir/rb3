#include "TourPropertyCollection.h"

TourPropertyCollection::TourPropertyCollection() {
    //mSaveSizeMethod = SaveSize;
}

void TourPropertyCollection::Clear() {
    m_mapTourProperties.clear();
}

int TourPropertyCollection::SaveSize(int version) {
    if (!FixedSizeSaveable::sPrintoutsEnabled) {
        TheDebug << MakeString("* %s = %i\n", "TourPropertyCollection", 0xa4);
    }
    return 0xa4;
}
