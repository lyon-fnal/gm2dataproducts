// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>
#include "art/Persistency/Common/Wrapper.h"
#include "DigitizerSampleArtRecord.hh"
#include "IslandArtRecord.hh"
#include "CrystalFitResult.hh"

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
template class std::vector< gm2dataproducts::CrystalFitResult >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::CrystalFitResult >;
