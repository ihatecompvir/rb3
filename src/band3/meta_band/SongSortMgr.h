#ifndef METABAND_SONGSORTMGR_H
#define METABAND_SONGSORTMGR_H
#include <vector>
#include <set>
#include "system/utl/Symbol.h"
#include "system/beatmatch/TrackType.h"

class SongSortMgr {
public:
    SongSortMgr();
    virtual ~SongSortMgr();

    class SongFilter {
    public:
        enum FilterType {
            kFilterDifficulty = 0x0,
            kFilterVocalParts = 0x1,
            kFilterLength = 0x2,
            kFilterSource = 0x3,
            kFilterRating = 0x4,
            kFilterDecade = 0x5,
            kFilterGenre = 0x6,
            kFilterArtist = 0x7,
            kNumVisibleFilterTypes = 0x7,
            kNumFilterTypes = 0x8
        };

        // todo: verify that this is actually what is inside these vectors? seems right but not 100% sure
        std::vector< std::set<Symbol> > mFilters;
        TrackType mRequiredTrackType;
        std::vector<Symbol> mExcludedSongs;

    };
};

#endif