// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>
#include "art/Persistency/Common/Wrapper.h"

#include "DigitizerSampleArtRecord.hh"


// For Digitizer Sample
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::DigitizerSampleArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::DigitizerSampleArtRecordCollection >;

