#ifndef TRACKERHITARTRECORD_HH
#define TRACKERHITARTRECORD_HH

// Provides the declaration of the ROOT-storable class used as a starting point
// for the straw tracker analysis.
//
// @author Leah Welty-Rieger
// @author Tasha Arvanitis
// @date July 2013

#include <vector>
#include "WireID.hh"
#include "CLHEP/Vector/ThreeVector.h"

namespace gm2strawtracker {
    struct TrackerHitArtRecord {
        // Specification for the wire: includes station, view, layer,
        // wire #
        WireID id;

        // Time at which the hit was registered (includes both the time of the
        // hit and drift) (units: nanoseconds)
        double time;

        // Width of the pulse from the sensors (in ns)
        double width;

        // Index of the hit (this is the nth time that this straw was hit in the
        // fill)
        int index;

        // Was there some sort of error in reading this out?
        bool errorFlag;

        // Location (in tracking coordinates) of the center of the straw
        CLHEP::Hep3Vector centerLocation;

        // u or v of the straw (only applicable as the u-coordinate for u
        // straws, and as the v-coordinate for v straws)
        double uv;

        // T0, in ns, the drift time, in ns, and drift distance, in mm.
        double t0;
        double driftTime;
        double driftDistance;

        // Default constructor
        TrackerHitArtRecord() :
            id(),
            time(0.),
            width(0.),
            index(0),
            errorFlag(false),
            centerLocation(0., 0., 0.),
            t0(0.),
            driftTime(0.),
            driftDistance(0.)
        {}

        // A nicer constructor: ROOT doesn't see it, but other classes can.
#ifndef __GCCXML__
        TrackerHitArtRecord(WireID inid, double intime, double inwidth, 
                int inindex, bool inerrorFlag, CLHEP::Hep3Vector incenterLoc, 
                double inuv, double int0, double indriftTime,
                double indriftDistance) :
            id(inid),
            time(intime),
            width(inwidth),
            index(inindex),
            errorFlag(inerrorFlag),
            centerLocation(incenterLoc),
            uv(inuv),
            t0(int0),
            driftTime(indriftTime),
            driftDistance(indriftDistance)
        {}

        // Copy constructor
        TrackerHitArtRecord(const TrackerHitArtRecord& other) :
            id(other.id),
            time(other.time),
            width(other.width),
            index(other.index),
            errorFlag(other.errorFlag),
            centerLocation(other.centerLocation),
            uv(other.uv),
            t0(other.t0),
            driftTime(other.driftTime),
            driftDistance(other.driftDistance)
        {}
#endif // __GCCXML__

    }; // TrackerHitArtRecord struct definition

    typedef std::vector<TrackerHitArtRecord> TrackerHitArtRecordCollection;
    
} // namespace

#endif

