// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>

#include "art/Persistency/Common/Wrapper.h"
#include "DigitizerSampleArtRecord.hh"
#include "IslandArtRecord.hh"
#include "CrystalFitResultArtRecord.hh"
#include "CaloClusterArtRecord.hh"


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
// Template the putter
template class art::Ptr< gm2dataproducts::IslandArtRecordCollection >;

// For Crystal Fit
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::CrystalFitResultArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::CrystalFitResultArtRecordCollection >;
// Template the putter
template class art::Ptr<gm2dataproducts::CrystalFitResultArtRecord>;

// for clustering
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::XtalHitClusterArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::XtalHitClusterArtRecordCollection >;

template class art::Ptr< gm2ringsim::XtalArtRecord>;
template class std::vector<art::Ptr< gm2ringsim::XtalArtRecord> >;
template class art::Wrapper< std::vector<art::Ptr<gm2ringsim::XtalArtRecord> > >;