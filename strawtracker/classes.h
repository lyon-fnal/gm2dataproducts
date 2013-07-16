// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>

#include "art/Persistency/Common/Wrapper.h"
#include "TrackerHitArtRecord.hh"
#include "TrackerGeomHitArtRecord.hh"
#include "FittedTrackArtRecord.hh"
#include "WireID.hh"

// For WireID
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::WireID >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2strawtracker::WireID >;

// For TrackerHits
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::TrackerHitArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2strawtracker::TrackerHitArtRecordCollection >;

// For TrackerGeomHits
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::TrackerGeomHitArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2strawtracker::TrackerGeomHitArtRecordCollection >;

// For FittedTracks
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::FittedTrackArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2strawtracker::FittedTrackArtRecordCollection >;

