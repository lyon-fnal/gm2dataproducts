#ifndef CALOCLUSTERARTRECORD_HH
#define CALOCLUSTERARTRECORD_HH

#include <vector>
#include "art/Persistency/Common/Ptr.h"
#include "art/Persistency/Common/PtrVector.h"
#include "gm2ringsim/calo/XtalArtRecord.hh"
#include "CrystalFitResultArtRecord.hh"

namespace gm2dataproducts {
	template <class Hit>
	struct ClusterArtRecord {
		std::vector< art::Ptr<Hit> > hits;
		double energy;
		double x0;
		double y0;
		double t0;
		int caloNum;
		int seedHitNum;

		ClusterArtRecord<Hit>() :
			hits(),
			energy(0.),
			x0(0.),
			y0(0.),
			t0(0.),
			caloNum(-1),
			seedHitNum(-1) {};
#ifndef __GCCXML__
			ClusterArtRecord<Hit>(std::vector<art::Ptr<Hit> > hits_,
									double energy_, double x0_, double y0_, double t0_,
									int caloNum_, int seedHitNum_) :
				hits(hits_),
				energy(energy_),
				x0(x0_),
				y0(y0_),
				t0(t0_),
				caloNum(caloNum_),
				seedHitNum(seedHitNum_) {};
#endif
	};

	typedef ClusterArtRecord<gm2ringsim::XtalArtRecord> XtalHitClusterArtRecord;
	typedef std::vector<XtalHitClusterArtRecord> XtalHitClusterArtRecordCollection;

	typedef ClusterArtRecord<gm2dataproducts::CrystalFitResultArtRecord> CrystalFitClusterArtRecord;
	typedef std::vector<CrystalFitClusterArtRecord> CrystalFitClusterArtRecordCollection;
}

#endif
