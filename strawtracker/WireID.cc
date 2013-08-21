
// This file provides the definitions for the WireID class.
//
// @author Tasha Arvanitis
// @date August 2013

#include "WireID.hh"

using gm2strawtracker::WireID;
using gm2strawtracker::StrawView;
using gm2strawtracker::u_view;
using gm2strawtracker::v_view;
using gm2strawtracker::na_view;


// Constructors 
// The default constructor initializes everything to -1 - set the fields
// you care about!
gm2strawtracker::WireID::WireID() :
    trackerNumber(-1),
    station(-1),
    view(na_view),
    layer(-1),
    wire(-1)
{}

// ROOT shouldn't see these
#ifndef __GCCXML__
// Two other constructors, which ROOT can't see but other classes
// can.
// An easy constructor - just pass in all the relevant information
gm2strawtracker::WireID::WireID(short trackerNumber_in, short station_in, 
        StrawView view_in, short layer_in, short wire_in)
: trackerNumber(trackerNumber_in),
    station(station_in),
    view(view_in),
    layer(layer_in),
    wire(wire_in)
{}

// A copy constructor
gm2strawtracker::WireID::WireID(const WireID& other)
: trackerNumber(other.trackerNumber),
    station(other.station),
    view(other.view),
    layer(other.layer),
    wire(other.wire)
{}

// Code modified from stackoverflow question 236129. This function takes a
// string and a string containing delimiters as arguments and returns a
// vector of the tokens resulting from such a split. 
std::vector<std::string> gm2strawtracker::WireID::
split(const std::string& str, const std::string& delimiters)
{
    std::vector<std::string> tokens;

    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }

    return tokens;
}

// Check if a string is a positive integer (all the fields should be!)
bool gm2strawtracker::WireID::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

// A construction function to reconstruct a WireID based on its standard
// name (as provided in operator<<) - needed for WireID specification to be
// linked to specific volumes in Geant. If an invalid string of some sort is
// provided (not enough tokens, some tokens either empty or not numbers,
// etc.), then an error message is printed and the WireID returned is filled
// with -1's. 
// Note: This is NOT a member function of the WireID! It's publicly
// available to anyone who wants to use it.
gm2strawtracker::WireID wireIDfromString(std::string str) {
    // Based on the output format in operator<<, the delimiters we want are
    // '~' and ' ' (space). Split the string.
    std::vector<std::string> tokens = WireID::split(str, "~ ");

    // Create the WireID - by default, it has invalid parameters.
    WireID wire;

    // Error checking 
    // Check that it's long enough.
    if (tokens.size() != 5) {
        mf::LogError("WireID") 
            << "Wrong number of tokens in conversion from string" 
            << " to WireID!! Returning invalid WireID." << std::endl;

        return wire;
    }
    // Check that the tokens are actually positive integers. This doesn't
    // check that the tokens fall in the appropriate ranges, as it isn't
    // linked to the geometry description.
    for (size_t i = 0; i < tokens.size(); i++) {
        if (!WireID::is_number(tokens[i])) {
            // Not a number: return the invalid (default) WireID
            mf::LogError("WireID") 
                << "One or more tokens provided for conversion to "
                << "WireID not numeric!! Returning invalid WireID." << std::endl;
            return wire;
        }
    }

    // Once we reach this point, we appear to have a valid string. Let's now
    // fill the WireID based on the tokens
    wire.setTrackerNumber(atoi(tokens[0].c_str()));
    wire.setStation(atoi(tokens[1].c_str()));
    // The view is moderately complicated - I'm hoping to change the
    // printout to actually say 'u' or 'v', rather than '0' or '1'.
    int viewInt = atoi(tokens[2].c_str());
    wire.setView(viewInt == 0 ? u_view : 
            (viewInt == 1 ? v_view : na_view));
    wire.setLayer(atoi(tokens[3].c_str()));
    wire.setWire(atoi(tokens[4].c_str()));

    return wire;
}
// The two functions below provide global functions in the gm2strawtracker
// namespace that allow other classes to print WireIDs to output streams
// using the << operator and compare WireIDs using the < operator.

// The printing function for ease of debugging: tracker number ~ station ~
// view ~ layer ~ wire (Use tilde separation instead of '-' in order to
// avoid confusion with negative numbers)
std::ostream& gm2strawtracker::operator<<(std::ostream& os, const WireID& id) {
    os << id.trackerNumber << " ~ " << id.station << " ~ " << id.view
        //id.view == u_view ? "u" : (id.view == v_view ? "v" : "na")
        << " ~ " << id.layer << " ~ " << id.wire;
    return os;
}

// A comparison function for the WireID, so that it can be sorted. This is
// also essential in order to use a WireID as a key in a std::map.
bool gm2strawtracker::operator<(WireID const& left, WireID const& right) {
    // Compare the 'most significant' things first:
    // The order of comparison is tracker number, station, view, layer, and
    // then wire.
    if (left.trackerNumber != right.trackerNumber) {
        return left.trackerNumber < right.trackerNumber;
    }
    if (left.station != right.station) {
        return left.station < right.station;
    }
    if (left.view != right.view) {
        return left.view < right.view;
    }
    if (left.layer != right.layer) {
        return left.layer < right.layer;
    }
    if (left.wire != right.wire) {
        return left.wire < right.wire;
    }
    // If we get here, we have identical WireID's, so we have to return
    // false (WireID 1 is *not* less than WireID 2). If you return true, all
    // hell breaks loose, because a map can't possibly find an entry, since
    // no two keys will ever look the same!
    return false;
}
#endif //__GCCXML__
