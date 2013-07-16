#ifndef FITTEDTRACKARTRECORD_HH
#define FITTEDTRACKARTRECORD_HH

// Provides the ROOT-readable class used as both intermediate steps and as a
// final result in the track fitting project.
//
// @author Leah Welty-Rieger
// @author Tasha Arvanitis
// @date July 2013

#include <vector>
#include "art/Persistency/Common/Ptr.h"
#include "TrackerGeomHitArtRecord.hh"

namespace gm2strawtracker {
    struct FittedTrackArtRecord {

        // The collection of pointers (safe for storing and retrieving) to the
        // hits in this track [candidate].
        std::vector<art::Ptr<TrackerGeomHitArtRecord> > hits;

        // Fitted values and errors for parameters x, y, z, x', y', and signed
        // curvature. Type still sort of up in the air, but possibly just the
        // TMinuit ROOT class?
        double x;
        double x_err;
        double y;
        double y_err;
        double z;
        double z_err;
        double xprime;
        double xprime_err;
        double yprime;
        double yprime_err;
        double curvature;
        double curvature_err;

        // Estimate of the quality of the fit
        double chi_squared;

        // Flag for whether the fit was successful
        bool errorFlag;

        // Flag to say whether this track is finished or just an intermediate
        // step
        bool isFinished;

        // vector describing which layers were hit.
        // Plane number is counted from the end furthest from the calorimeter.
        std::vector<bool> planesHit;


        // Default constructor
        FittedTrackArtRecord() :
            hits(),
            x(0),
            x_err(0),
            y(0),
            y_err(0),
            z(0),
            z_err(0),
            xprime(0),
            xprime_err(0),
            yprime(0),
            yprime_err(0),
            curvature(0),
            curvature_err(0),
            chi_squared(0),
            errorFlag(false),
            isFinished(false)
        {}

        // A nicer constructor: ROOT doesn't see it, but other classes can.
#ifndef __GCCXML__
        
        FittedTrackArtRecord(std::vector<art::Ptr<TrackerGeomHitArtRecord> > hits_, 
                double x_, double x_err_, double y_, double y_err_,
                double z_, double z_err_, double xprime_, double xprime_err_, 
                double yprime_, double yprime_err_, double curvature_,
                double chi_squared_, bool errorFlag_, bool isFinished_,
                std::vector<bool> planesHit_) :
            hits(hits_), x(x_), x_err(x_err_), y(y_), y_err(y_err_), z(z_),
            z_err(z_err_), xprime(xprime_), xprime_err(xprime_err_),
            yprime(yprime_), yprime_err(yprime_err_), curvature(curvature_),
            chi_squared(chi_squared_), errorFlag(errorFlag_),
            isFinished(isFinished_), planesHit(planesHit_)
        {}
#endif // __GCCXML__

    }; // FittedTrackArtRecord struct definition

    typedef std::vector<FittedTrackArtRecord> FittedTrackArtRecordCollection;
    
} // namespace

#endif

