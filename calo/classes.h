// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>
#include "art/Persistency/Common/Wrapper.h"
#include "DigitizerSampleArtRecord.hh"
#include "IslandArtRecord.hh"
#include "CrystalFitResultArtRecord.hh"
#include "ClusterArtRecord.hh"


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
// Template the putter vector
// template class art::Wrapper< art::PtrVector< gm2dataproducts::CrystalFitResultArtRecord > >;

// For Cluster
// Template the vector (no typedef)
template class std::vector< gm2dataproducts::ClusterArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::ClusterArtRecordCollection >;
// Template the putter
template class art::Ptr<gm2dataproducts::ClusterArtRecord>;
