/* 
 * File:   EUTelGeometryTelescopeGeoDescription.h
 *
 */

#ifndef EUTELGEOMETRYTELESCOPEGEODESCRIPTION_H
#define	EUTELGEOMETRYTELESCOPEGEODESCRIPTION_H

// C++
#include <map>

// LCIO includes
#include "LCIOSTLTypes.h"

// MARLIN
#include "marlin/Global.h"

// GEAR includes
#include "gear/GearMgr.h"
#include "gear/SiPlanesLayerLayout.h"
#include "gear/SiPlanesParameters.h"

// built only if GEAR is available
#ifdef USE_GEAR

class EUTelGeometryTelescopeGeoDescription {
public:
    EUTelGeometryTelescopeGeoDescription();
    EUTelGeometryTelescopeGeoDescription(const EUTelGeometryTelescopeGeoDescription& orig);
    virtual ~EUTelGeometryTelescopeGeoDescription();

public:
    /** Silicon planes parameters as described in GEAR
     * This structure actually contains the following:
     *  @li A reference to the telescope geoemtry and layout
     *  @li An integer number saying if the telescope is w/ or w/o DUT
     *  @li An integer number saying the number of planes in the
     *  telescope.
     *
     *  This object is provided by GEAR during the init() phase and
     *  stored here for local use.
     */
    gear::SiPlanesParameters* _siPlanesParameters;

    /** Silicon plane layer layout
     * This is the real geoemetry description. For each layer
     *  composing the telescope the relevant information are
     *  available.
     *
     *  This object is taken from the _siPlanesParameters during the
     *  init() phase and stored for local use
     */
    gear::SiPlanesLayerLayout* _siPlanesLayerLayout;

public:
    //    /** Ordered sensor ID
    //     *  This vector contains sensorID sorted according to their 
    //     *  position along the Z axis (beam axis)
    //     */
    //    EVENT::IntVec _orderedSensorID;
    //
    //    /** @TODO: Add description to this variable */
    //    EVENT::IntVec _orderedSensorID_wo_excluded;

    /** Vector of Sensor IDs */
    EVENT::IntVec _sensorIDVec;

    /** Sensor ID map (inverse sensorIDVec) */
    std::map< int, int > _sensorIDVecMap;

    /** Sensor ID vector ordered according to their 
     *  position along the Z axis (beam axis) */
    EVENT::IntVec _sensorIDVecZOrder;

    /** Map from sensor ID to number along Z */
    std::map<int, int> _sensorIDtoZOrderMap;

    // an associative map for getting also the sensorID ordered
    /** @TODO: Add description to this variable */
    std::map< double, int > _sensorIDMap;

    /** @TODO: Add description to this variable */
    EVENT::DoubleVec _siPlaneZPosition;

    /** Number of planes including DUT */
    size_t _nPlanes;

};

#endif  // USE_GEAR

#endif	/* EUTELGEOMETRYTELESCOPEGEODESCRIPTION_H */

