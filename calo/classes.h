// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>
#include "art/Persistency/Common/Wrapper.h"
#include "DigitizerSampleArtRecord.hh"
#include "IslandArtRecord.hh"
#include "CrystalFitResultArtRecord.hh"

// For Digitizer Sample
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::DigitizerSampleArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::DigitizerSampleArtRecordCollection >;

// For Island
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::IslandArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::IslandArtRecordCollection >;

// For Crystal Fit
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::CrystalFitResultArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::CrystalFitResultArtRecordCollection >;
// Template the wrapper for the putter
template class art::Ptr<gm2dataproducts::CrystalFitResultArtRecord>;
