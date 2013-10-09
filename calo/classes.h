// classes.h
// How ROOT knows how to deal with our data products
//

#include <vector>

#include "art/Persistency/Common/Wrapper.h"
#include "CaloClusterArtRecord.hh"

// Template the vector (no typedef)
template class std::vector< gm2dataproducts::XtalHitClusterArtRecord >;
// Template the wrapper for the vector (typedef okay)
template class art::Wrapper< gm2dataproducts::XtalHitClusterArtRecordCollection >;

template class art::Ptr< gm2ringsim::XtalArtRecord>;
template class std::vector<art::Ptr< gm2ringsim::XtalArtRecord> >;
template class art::Wrapper< art::PtrVector<gm2ringsim::XtalArtRecord> >;