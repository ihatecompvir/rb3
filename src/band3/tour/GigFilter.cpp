#include "GigFilter.h"

GigFilter::GigFilter() {}

GigFilter::~GigFilter() {}

void GigFilter::Init(const DataArray *i_pConfig) {
    MILO_ASSERT(i_pConfig, 0x1e);

    Symbol name = i_pConfig->Node(0).Sym(i_pConfig);
    m_symName = name;

    i_pConfig->FindData(is_internal, m_bIsInternal, false);
    i_pConfig->FindData(weight, m_fWeight, false);
    m_symFilteredPart = gNullStr;
    i_pConfig->FindData(part_difficulty_filter, m_symFilteredPart, false);

    DataArray *filters = i_pConfig->FindArray(filter, false);
    if (filters != nullptr) {
        for (int i = 0; i < filters->Size(); i++) {
            DataArray *pEntry = filters->Node(i).Array(filters);

            MILO_ASSERT(pEntry, 0x34);
            MILO_ASSERT(pEntry->Size() == 2, 0x35);

            SongSortMgr::SongFilter::FilterType type =
                (SongSortMgr::SongFilter::FilterType)pEntry->Node(0).Int(pEntry);
            Symbol filterName = pEntry->Node(1).Sym(pEntry);

            MILO_ASSERT((0) <= (type) && (type) < (SongSortMgr::SongFilter::kNumFilterTypes), 0x5e);

            m_songFilter.mFilters.begin()[type].insert(filterName);
        }
    }
}

Symbol GigFilter::GetName() const {
    return m_symName;
}

bool GigFilter::IsInternal() const {
    return m_bIsInternal;
}

SongSortMgr::SongFilter *GigFilter::GetFilter() const {
    return (SongSortMgr::SongFilter *)&m_songFilter;
}

Symbol GigFilter::GetFilteredPartSym() const {
    return m_symFilteredPart;
}

// void InitializeMusicLibraryTask(MusicLibrary::MusicLibraryTask&, int, Symbol) const {}

float GigFilter::GetWeight() const {
    return m_fWeight;
}