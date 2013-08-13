// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>

#include "art/Persistency/Common/Wrapper.h"
#include "TrackerHitArtRecord.hh"
#include "FittedTrackArtRecord.hh"
#include "WireID.hh"

// For WireID
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::WireID >;

// For TrackerHits
// Template the vector (no typedef)
template class std::vector< gm2strawtracker::TrackerHitArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2strawtracker::TrackerHitArtRecordCollection >;

// For the vector of art::Ptr's
template class art::Ptr<gm2strawtracker::TrackerHitArtRecord>;
template class std::vector<art::Ptr<gm2strawtracker::TrackerHitArtRecord> >;

// And for the vector of booleans
template class std::vector<bool>;

// For FittedTracks 
// Make a wrapper for just the fitted track, not just for the collection.
template class art::Wrapper< gm2strawtracker::FittedTrackArtRecord >;
