#ifndef CALOCLUSTERARTRECORD_HH
#define CALOCLUSTERARTRECORD_HH

#include <vector>
#include "art/Persistency/Common/Ptr.h"
#include "art/Persistency/Common/PtrVector.h"
#include "gm2ringsim/calo/XtalArtRecord.hh"

namespace gm2dataproducts {
	struct XtalHitClusterArtRecord {
		art::PtrVector<gm2ringsim::XtalArtRecord> hits;
		double energy;
		double x0;
		double y0;
		double t0;
		int caloNum;
		int seedXtalNum;

		XtalHitClusterArtRecord() :
			hits(),
			energy(0.),
			x0(0.),
			y0(0.),
			t0(0.),
			caloNum(-1),
			seedXtalNum(-1) {};
#ifndef __GCCXML__
			XtalHitClusterArtRecord(art::PtrVector<gm2ringsim::XtalArtRecord> hits_,
									double energy_, double x0_, double y0_, double t0_,
									int caloNum_, int seedXtalNum_) :
				hits(hits_),
				energy(energy_),
				x0(x0_),
				y0(y0_),
				t0(t0_),
				caloNum(caloNum_),
				seedXtalNum(seedXtalNum_) {};
#endif
	};

	typedef std::vector<XtalHitClusterArtRecord> XtalHitClusterArtRecordCollection;
}

#endif