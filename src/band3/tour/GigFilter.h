#ifndef TOUR_GIGFILTER_H
#define TOUR_GIGFILTER_H

#include "system/os/Debug.h"
#include "system/obj/Data.h"
#include "system/utl/Symbols.h"
#include "meta_band/SongSortMgr.h"



class GigFilter {
    public:
    GigFilter();
    virtual ~GigFilter();
    void Init(const DataArray*);
    Symbol GetName() const;
    bool IsInternal() const;
    SongSortMgr::SongFilter* GetFilter() const;
    Symbol GetFilteredPartSym() const;
    // void InitializeMusicLibraryTask(MusicLibrary::MusicLibraryTask&, int, Symbol) const;
    float GetWeight() const;

    Symbol m_symName; // 0x4
    bool m_bIsInternal; // 0x8
    SongSortMgr::SongFilter m_songFilter; // 0xC
    Symbol m_symFilteredPart; // 0x20
    float m_fWeight; // 0x24

};

#endif // TOUR_GIGFILTER_H