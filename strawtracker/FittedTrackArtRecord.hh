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
#include "CLHEP/Vector/ThreeVector.h"

namespace gm2strawtracker {
    // A support struct to encapsulate the idea of a value with an error
    // (just two doubles linked together, really, and it has no way of
    // dealing with asymmetric errors).
    struct ValueWithError {
        double val;
        double err;

        // Default constructor
        ValueWithError()
          : val(0),
            err(0)
        {}

        // Note: the default copy constructor is perfectly good, and will
        // be used in the constructors of other classes

        // A nicer constructor: ROOT doesn't see it, but other classes can.
#ifndef __GCCXML__
        ValueWithError(double value, double error) 
          : val(value),
            err(error)
        {}
#endif // __GCCXML__
    }; // ValueWithError struct definition

    // A support struct to contain the parameters (and errors) describing a
    // helix.
    // The parameters used here are those described at 
    // http://www-jlc.kek.jp/subg/offl/lib/docs/helix_manip/node2.html
    struct HelixParameters {
        // The pivot point chosen for the parametrization. My understanding
        // is that this is defined rather than found, so it needs no error,
        // right?
        CLHEP::Hep3Vector pivot;

        // The radial displacement from the pivot point 
        ValueWithError d_rho;

        // The azimuthal angle of the vector from the pivot point to the
        // 'start point' of the helix. Should be between 0 and 2 pi.
        ValueWithError phi0;

        // The signed curvature (1/c B kappa), where (as I understand it)
        // if rho > 0, then the helix is left-handed.
        ValueWithError rho;

        // The vertical displacement from the pivot point. To avoid
        // redundancy, I think we want |d_z| < 2 pi rho tan(lambda).
        ValueWithError d_z;

        // The dip angle of the helix. Do we want to keep track of lambda
        // or tan(lambda)?
        ValueWithError lambda;

        // Default constructor: all fields have default constructors that
        // set everything to zero, so we really don't have to do anything.
        // The constructor is defined here primarily for clarity's sake
        HelixParameters()
          : pivot(),
            d_rho(),
            phi0(),
            rho(),
            d_z(),
            lambda()
        {}

        // A couple of nicer constructors: ROOT doesn't see it, but other
        // classes can.
#ifndef __GCCXML__
        // A constructor based on fully-formed arguments
        HelixParameters(CLHEP::Hep3Vector pivot_in, ValueWithError d_rho_in,
                ValueWithError phi0_in, ValueWithError rho_in,
                ValueWithError d_z_in, ValueWithError lambda_in) 
          : pivot(pivot_in),
            d_rho(d_rho_in),
            phi0(phi0_in),
            rho(rho_in),
            d_z(d_z_in),
            lambda(lambda_in)
        {}

        // A constructor based on individual values, so no more interesting
        // classes.
        HelixParameters(double x0, double y0, double z0, // pivot
                double d_rho_val, double d_rho_err, // d_rho
                double phi0_val, double phi0_err, // phi0
                double rho_val, double rho_err, // rho
                double d_z_val, double d_z_err, // d_z
                double lambda_val, double lambda_err) // lambda
          : pivot(x0, y0, z0),
            d_rho(d_rho_val, d_rho_err),
            phi0(phi0_val, phi0_err),
            rho(rho_val, rho_err),
            d_z(d_z_val, d_z_err),
            lambda(lambda_val, lambda_err)
        {}
        
#endif // __GCCXML__
    }; // End definition of struct HelixParameters


    // A support struct to contain the parameters (and errors) describing a
    // straight line. For now, this is just in 2D, and the 'y-axis' isn't
    // specified, so it could be x, u, or v.
    struct LineParameters {
        // The slope of the line
        ValueWithError slope;

        // The intercept with the 'y-axis' (at z=0)
        ValueWithError intercept;

        // Default constructor: all fields have default constructors that
        // set everything to zero, so we really don't have to do anything.
        // The constructor is defined here primarily for clarity's sake
        LineParameters()
          : slope(),
            intercept()
        {}

        // A couple of nicer constructors: ROOT doesn't see it, but other
        // classes can.
#ifndef __GCCXML__
        // A constructor based on fully-formed arguments
        LineParameters(ValueWithError slope_in, ValueWithError intercept_in) 
          : slope(slope_in),
            intercept(intercept_in)
        {}

        // A constructor based on individual values, so no more interesting
        // classes.
        LineParameters(double slope_val, double slope_err,
                double intercept_val, double intercept_err) 
          : slope(slope_val, slope_err),
            intercept(intercept_val, intercept_err)
        {}
        
#endif // __GCCXML__
    }; // End definition of struct LineParameters

    // And now, our feature presentation: the fitted track that is so
    // crucial to the analysis.
    struct FittedTrackArtRecord {

        // The collection of pointers (safe for storing and retrieving) to the
        // hits in this track [candidate].
        std::vector<art::Ptr<TrackerGeomHitArtRecord> > hits;

        // Helix parameters (defined and described above)
        HelixParameters helix_fit;
        // Line parameters (ditto)
        LineParameters line_fit;

        // Flags to tell which fit style we're using (could be an enum, but
        // I'm not sure that the line stuff is going to last that long...)
        bool isHelix;
        bool isLine;

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
            helix_fit(), // Default constructor automatically zeros everything
            line_fit(),
            isHelix(false),
            isLine(false),
            chi_squared(0),
            errorFlag(false),
            isFinished(false)
        {}

        // A nicer constructor: ROOT doesn't see it, but other classes can.
#ifndef __GCCXML__
        
        FittedTrackArtRecord(
                std::vector<art::Ptr<TrackerGeomHitArtRecord> > hits_, 
                HelixParameters helix_fit_,
                LineParameters line_fit_,
                bool isHelix_, bool isLine_,
                double chi_squared_, bool errorFlag_, bool isFinished_,
                std::vector<bool> planesHit_) 
          : hits(hits_), 
            helix_fit(helix_fit_),
            line_fit(line_fit_),
            isHelix(isHelix_),
            isLine(isLine_),
            chi_squared(chi_squared_), 
            errorFlag(errorFlag_),
            isFinished(isFinished_), 
            planesHit(planesHit_)
        {}
#endif // __GCCXML__

    }; // FittedTrackArtRecord struct definition

    typedef std::vector<FittedTrackArtRecord> FittedTrackArtRecordCollection;
    
} // namespace

#endif

