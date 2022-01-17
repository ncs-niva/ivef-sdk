#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFVoyageData.h"

namespace ivef {

// Constructor
VoyageData::VoyageData()
 :  QObject(),
    m_airDraught( 0.0 ),
    m_airDraughtPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_cargoTypeIMO( 0 ),
    m_cargoTypeIMOPresent( false ),
    m_contactIdentity(),
    m_contactIdentityPresent( false ),
    m_destCode(),
    m_destCodePresent( false ),
    m_destName(),
    m_destNamePresent( false ),
    m_departCode(),
    m_departCodePresent( false ),
    m_departName(),
    m_departNamePresent( false ),
    m_draught( 0.0 ),
    m_draughtPresent( false ),
    m_ETA(),
    m_ETAPresent( false ),
    m_ATD(),
    m_ATDPresent( false ),
    m_ISPSLevel( 0.0 ),
    m_ISPSLevelPresent( false ),
    m_overSizedLength( 0.0 ),
    m_overSizedLengthPresent( false ),
    m_overSizedWidth( 0.0 ),
    m_overSizedWidthPresent( false ),
    m_personsOnBoard( 0 ),
    m_personsOnBoardPresent( false ),
    m_pilots( 0.0 ),
    m_pilotsPresent( false ),
    m_routeBound( false ),
    m_routeBoundPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_sourceType( 0 ),
    m_sourceTypePresent( false ),
    m_tankerStatus( 0 ),
    m_tankerStatusPresent( false ),
    m_tugs( false ),
    m_tugsPresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
VoyageData::VoyageData(XmlStreamReader& xml)
 :  QObject(),
    m_airDraught( 0.0 ),
    m_airDraughtPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_cargoTypeIMO( 0 ),
    m_cargoTypeIMOPresent( false ),
    m_contactIdentity(),
    m_contactIdentityPresent( false ),
    m_destCode(),
    m_destCodePresent( false ),
    m_destName(),
    m_destNamePresent( false ),
    m_departCode(),
    m_departCodePresent( false ),
    m_departName(),
    m_departNamePresent( false ),
    m_draught( 0.0 ),
    m_draughtPresent( false ),
    m_ETA(),
    m_ETAPresent( false ),
    m_ATD(),
    m_ATDPresent( false ),
    m_ISPSLevel( 0.0 ),
    m_ISPSLevelPresent( false ),
    m_overSizedLength( 0.0 ),
    m_overSizedLengthPresent( false ),
    m_overSizedWidth( 0.0 ),
    m_overSizedWidthPresent( false ),
    m_personsOnBoard( 0 ),
    m_personsOnBoardPresent( false ),
    m_pilots( 0.0 ),
    m_pilotsPresent( false ),
    m_routeBound( false ),
    m_routeBoundPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_sourceType( 0 ),
    m_sourceTypePresent( false ),
    m_tankerStatus( 0 ),
    m_tankerStatusPresent( false ),
    m_tugs( false ),
    m_tugsPresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "AirDraught" ) )
    {
        if ( !setAirDraught( attr.value( "AirDraught" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set AirDraught = " + attr.value( "AirDraught" ).toString() );
    }
    if ( attr.hasAttribute( "Id" ) )
    {
        if ( !setId( attr.value( "Id" ).toString().toInt() ) )
            xml.validationError( "error set Id = " + attr.value( "Id" ).toString() );
    }
    if ( attr.hasAttribute( "CargoTypeIMO" ) )
    {
        if ( !setCargoTypeIMO( attr.value( "CargoTypeIMO" ).toString().toInt() ) )
            xml.validationError( "error set CargoTypeIMO = " + attr.value( "CargoTypeIMO" ).toString() );
    }
    if ( attr.hasAttribute( "ContactIdentity" ) )
    {
        if ( !setContactIdentity( attr.value( "ContactIdentity" ).toString() ) )
            xml.validationError( "error set ContactIdentity = " + attr.value( "ContactIdentity" ).toString() );
    }
    if ( attr.hasAttribute( "DestCode" ) )
    {
        if ( !setDestCode( attr.value( "DestCode" ).toString() ) )
            xml.validationError( "error set DestCode = " + attr.value( "DestCode" ).toString() );
    }
    if ( attr.hasAttribute( "DestName" ) )
    {
        if ( !setDestName( attr.value( "DestName" ).toString() ) )
            xml.validationError( "error set DestName = " + attr.value( "DestName" ).toString() );
    }
    if ( attr.hasAttribute( "DepartCode" ) )
    {
        if ( !setDepartCode( attr.value( "DepartCode" ).toString() ) )
            xml.validationError( "error set DepartCode = " + attr.value( "DepartCode" ).toString() );
    }
    if ( attr.hasAttribute( "DepartName" ) )
    {
        if ( !setDepartName( attr.value( "DepartName" ).toString() ) )
            xml.validationError( "error set DepartName = " + attr.value( "DepartName" ).toString() );
    }
    if ( attr.hasAttribute( "Draught" ) )
    {
        if ( !setDraught( attr.value( "Draught" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Draught = " + attr.value( "Draught" ).toString() );
    }
    if ( attr.hasAttribute( "ETA" ) )
    {
        if ( !setETA( QDateTime::fromString(attr.value( "ETA" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set ETA = " + attr.value( "ETA" ).toString() );
    }
    if ( attr.hasAttribute( "ATD" ) )
    {
        if ( !setATD( QDateTime::fromString(attr.value( "ATD" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set ATD = " + attr.value( "ATD" ).toString() );
    }
    if ( attr.hasAttribute( "ISPSLevel" ) )
    {
        if ( !setISPSLevel( attr.value( "ISPSLevel" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set ISPSLevel = " + attr.value( "ISPSLevel" ).toString() );
    }
    if ( attr.hasAttribute( "OverSizedLength" ) )
    {
        if ( !setOverSizedLength( attr.value( "OverSizedLength" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set OverSizedLength = " + attr.value( "OverSizedLength" ).toString() );
    }
    if ( attr.hasAttribute( "OverSizedWidth" ) )
    {
        if ( !setOverSizedWidth( attr.value( "OverSizedWidth" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set OverSizedWidth = " + attr.value( "OverSizedWidth" ).toString() );
    }
    if ( attr.hasAttribute( "PersonsOnBoard" ) )
    {
        if ( !setPersonsOnBoard( attr.value( "PersonsOnBoard" ).toString().toInt() ) )
            xml.validationError( "error set PersonsOnBoard = " + attr.value( "PersonsOnBoard" ).toString() );
    }
    if ( attr.hasAttribute( "Pilots" ) )
    {
        if ( !setPilots( attr.value( "Pilots" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Pilots = " + attr.value( "Pilots" ).toString() );
    }
    if ( attr.hasAttribute( "RouteBound" ) )
    {
        // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
        QString value = attr.value( "RouteBound" ).toString().toUpper();
        if ( !setRouteBound( value == "YES" ||
                             value == "TRUE" ||
                             value == "1") )
            xml.validationError( "error set RouteBound = " + attr.value( "RouteBound" ).toString() );
    }
    if ( attr.hasAttribute( "SourceId" ) )
    {
        if ( !setSourceId( attr.value( "SourceId" ).toString() ) )
            xml.validationError( "error set SourceId = " + attr.value( "SourceId" ).toString() );
    }
    if ( attr.hasAttribute( "SourceName" ) )
    {
        if ( !setSourceName( attr.value( "SourceName" ).toString() ) )
            xml.validationError( "error set SourceName = " + attr.value( "SourceName" ).toString() );
    }
    if ( attr.hasAttribute( "SourceType" ) )
    {
        if ( !setSourceType( attr.value( "SourceType" ).toString().toInt() ) )
            xml.validationError( "error set SourceType = " + attr.value( "SourceType" ).toString() );
    }
    if ( attr.hasAttribute( "TankerStatus" ) )
    {
        if ( !setTankerStatus( attr.value( "TankerStatus" ).toString().toInt() ) )
            xml.validationError( "error set TankerStatus = " + attr.value( "TankerStatus" ).toString() );
    }
    if ( attr.hasAttribute( "Tugs" ) )
    {
        // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
        QString value = attr.value( "Tugs" ).toString().toUpper();
        if ( !setTugs( value == "YES" ||
                             value == "TRUE" ||
                             value == "1") )
            xml.validationError( "error set Tugs = " + attr.value( "Tugs" ).toString() );
    }
    if ( attr.hasAttribute( "UpdateTime" ) )
    {
        if ( !setUpdateTime( QDateTime::fromString(attr.value( "UpdateTime" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set UpdateTime = " + attr.value( "UpdateTime" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "VoyageData" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Waypoint" )
            {
                Waypoint val( xml );
                if ( xml.name() != "Waypoint" )
                    xml.raiseError( "tag mismatch Waypoint" );
                else if ( !addWaypoint( val ) )
                    xml.validationError( "error add Waypoint"  );
            }
            else
            {
                xml.validationError( "unexpected element " + xml.name().toString() );
            }
            break;
        default:
            break;
        }
    }
}

// copy constructor
VoyageData::VoyageData(const VoyageData &val)
 :  QObject(),
    m_waypoints( val.m_waypoints ),
    m_airDraught( val.m_airDraught ),
    m_airDraughtPresent( val.m_airDraughtPresent ),
    m_id( val.m_id ),
    m_idPresent( val.m_idPresent ),
    m_cargoTypeIMO( val.m_cargoTypeIMO ),
    m_cargoTypeIMOPresent( val.m_cargoTypeIMOPresent ),
    m_contactIdentity( val.m_contactIdentity ),
    m_contactIdentityPresent( val.m_contactIdentityPresent ),
    m_destCode( val.m_destCode ),
    m_destCodePresent( val.m_destCodePresent ),
    m_destName( val.m_destName ),
    m_destNamePresent( val.m_destNamePresent ),
    m_departCode( val.m_departCode ),
    m_departCodePresent( val.m_departCodePresent ),
    m_departName( val.m_departName ),
    m_departNamePresent( val.m_departNamePresent ),
    m_draught( val.m_draught ),
    m_draughtPresent( val.m_draughtPresent ),
    m_ETA( val.m_ETA ),
    m_ETAPresent( val.m_ETAPresent ),
    m_ATD( val.m_ATD ),
    m_ATDPresent( val.m_ATDPresent ),
    m_ISPSLevel( val.m_ISPSLevel ),
    m_ISPSLevelPresent( val.m_ISPSLevelPresent ),
    m_overSizedLength( val.m_overSizedLength ),
    m_overSizedLengthPresent( val.m_overSizedLengthPresent ),
    m_overSizedWidth( val.m_overSizedWidth ),
    m_overSizedWidthPresent( val.m_overSizedWidthPresent ),
    m_personsOnBoard( val.m_personsOnBoard ),
    m_personsOnBoardPresent( val.m_personsOnBoardPresent ),
    m_pilots( val.m_pilots ),
    m_pilotsPresent( val.m_pilotsPresent ),
    m_routeBound( val.m_routeBound ),
    m_routeBoundPresent( val.m_routeBoundPresent ),
    m_sourceId( val.m_sourceId ),
    m_sourceIdPresent( val.m_sourceIdPresent ),
    m_sourceName( val.m_sourceName ),
    m_sourceNamePresent( val.m_sourceNamePresent ),
    m_sourceType( val.m_sourceType ),
    m_sourceTypePresent( val.m_sourceTypePresent ),
    m_tankerStatus( val.m_tankerStatus ),
    m_tankerStatusPresent( val.m_tankerStatusPresent ),
    m_tugs( val.m_tugs ),
    m_tugsPresent( val.m_tugsPresent ),
    m_updateTime( val.m_updateTime ),
    m_updateTimePresent( val.m_updateTimePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool VoyageData::operator==(const VoyageData &val) {

    if (!(m_waypoints == val.m_waypoints)) return false;
    if (!(m_airDraughtPresent == val.m_airDraughtPresent)) return false;
    if (!(m_airDraught == val.m_airDraught)) return false;
    if (!(m_idPresent == val.m_idPresent)) return false;
    if (!(m_id == val.m_id)) return false;
    if (!(m_cargoTypeIMOPresent == val.m_cargoTypeIMOPresent)) return false;
    if (!(m_cargoTypeIMO == val.m_cargoTypeIMO)) return false;
    if (!(m_contactIdentityPresent == val.m_contactIdentityPresent)) return false;
    if (!(m_contactIdentity == val.m_contactIdentity)) return false;
    if (!(m_destCodePresent == val.m_destCodePresent)) return false;
    if (!(m_destCode == val.m_destCode)) return false;
    if (!(m_destNamePresent == val.m_destNamePresent)) return false;
    if (!(m_destName == val.m_destName)) return false;
    if (!(m_departCodePresent == val.m_departCodePresent)) return false;
    if (!(m_departCode == val.m_departCode)) return false;
    if (!(m_departNamePresent == val.m_departNamePresent)) return false;
    if (!(m_departName == val.m_departName)) return false;
    if (!(m_draughtPresent == val.m_draughtPresent)) return false;
    if (!(m_draught == val.m_draught)) return false;
    if (!(m_ETAPresent == val.m_ETAPresent)) return false;
    if (!(m_ETA == val.m_ETA)) return false;
    if (!(m_ATDPresent == val.m_ATDPresent)) return false;
    if (!(m_ATD == val.m_ATD)) return false;
    if (!(m_ISPSLevelPresent == val.m_ISPSLevelPresent)) return false;
    if (!(m_ISPSLevel == val.m_ISPSLevel)) return false;
    if (!(m_overSizedLengthPresent == val.m_overSizedLengthPresent)) return false;
    if (!(m_overSizedLength == val.m_overSizedLength)) return false;
    if (!(m_overSizedWidthPresent == val.m_overSizedWidthPresent)) return false;
    if (!(m_overSizedWidth == val.m_overSizedWidth)) return false;
    if (!(m_personsOnBoardPresent == val.m_personsOnBoardPresent)) return false;
    if (!(m_personsOnBoard == val.m_personsOnBoard)) return false;
    if (!(m_pilotsPresent == val.m_pilotsPresent)) return false;
    if (!(m_pilots == val.m_pilots)) return false;
    if (!(m_routeBoundPresent == val.m_routeBoundPresent)) return false;
    if (!(m_routeBound == val.m_routeBound)) return false;
    if (!(m_sourceIdPresent == val.m_sourceIdPresent)) return false;
    if (!(m_sourceId == val.m_sourceId)) return false;
    if (!(m_sourceNamePresent == val.m_sourceNamePresent)) return false;
    if (!(m_sourceName == val.m_sourceName)) return false;
    if (!(m_sourceTypePresent == val.m_sourceTypePresent)) return false;
    if (!(m_sourceType == val.m_sourceType)) return false;
    if (!(m_tankerStatusPresent == val.m_tankerStatusPresent)) return false;
    if (!(m_tankerStatus == val.m_tankerStatus)) return false;
    if (!(m_tugsPresent == val.m_tugsPresent)) return false;
    if (!(m_tugs == val.m_tugs)) return false;
    if (!(m_updateTimePresent == val.m_updateTimePresent)) return false;
    if (!(m_updateTime == val.m_updateTime)) return false;
    return true;
}

// assignement
VoyageData & VoyageData::operator=(const VoyageData &val) {

    m_waypoints = val.m_waypoints;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_cargoTypeIMOPresent = val.m_cargoTypeIMOPresent;
    m_cargoTypeIMO = val.m_cargoTypeIMO;
    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_departCodePresent = val.m_departCodePresent;
    m_departCode = val.m_departCode;
    m_departNamePresent = val.m_departNamePresent;
    m_departName = val.m_departName;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATDPresent = val.m_ATDPresent;
    m_ATD = val.m_ATD;
    m_ISPSLevelPresent = val.m_ISPSLevelPresent;
    m_ISPSLevel = val.m_ISPSLevel;
    m_overSizedLengthPresent = val.m_overSizedLengthPresent;
    m_overSizedLength = val.m_overSizedLength;
    m_overSizedWidthPresent = val.m_overSizedWidthPresent;
    m_overSizedWidth = val.m_overSizedWidth;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_pilotsPresent = val.m_pilotsPresent;
    m_pilots = val.m_pilots;
    m_routeBoundPresent = val.m_routeBoundPresent;
    m_routeBound = val.m_routeBound;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_tankerStatusPresent = val.m_tankerStatusPresent;
    m_tankerStatus = val.m_tankerStatus;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for VoyageData
bool VoyageData::removeWaypoint(const Waypoint& val) {

    if (m_waypoints.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_waypoints.removeOne(val);
}

// setter for VoyageData
bool VoyageData::addWaypoint(const Waypoint& val) {

    m_waypoints.append(val);
    m_changed = true;
    return true;
}

// getter for VoyageData
const Waypoint& VoyageData::getWaypointAt(int i) const {

    return m_waypoints.at(i);
}

// count for VoyageData
int VoyageData::countOfWaypoints() const {

    return m_waypoints.count();
}

// setter for VoyageData
bool VoyageData::setAirDraught(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_airDraughtPresent = true;
    m_airDraught = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getAirDraught() const {

    return m_airDraught;
}

// check if optional element VoyageData has been set
bool VoyageData::hasAirDraught() const {

    return m_airDraughtPresent;
}

// setter for VoyageData
bool VoyageData::setId(int val) {

    m_idPresent = true;
    m_id = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
int VoyageData::getId() const {

    return m_id;
}

// setter for VoyageData
bool VoyageData::setCargoTypeIMO(int val) {

    // check if the new value is an approved value
    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_cargoTypeIMOPresent = true;
    m_cargoTypeIMO = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
int VoyageData::getCargoTypeIMO() const {

    return m_cargoTypeIMO;
}

// check if optional element VoyageData has been set
bool VoyageData::hasCargoTypeIMO() const {

    return m_cargoTypeIMOPresent;
}

// setter for VoyageData
bool VoyageData::setContactIdentity(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 254)
        return false;
    m_contactIdentityPresent = true;
    m_contactIdentity = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getContactIdentity() const {

    return m_contactIdentity;
}

// check if optional element VoyageData has been set
bool VoyageData::hasContactIdentity() const {

    return m_contactIdentityPresent;
}

// setter for VoyageData
bool VoyageData::setDestCode(QString val) {

    // check if the new value is within min length
    if (val.length() < 5)
        return false;
    // check if the new value is within max length
    if (val.length() > 15)
        return false;
    m_destCodePresent = true;
    m_destCode = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getDestCode() const {

    return m_destCode;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDestCode() const {

    return m_destCodePresent;
}

// setter for VoyageData
bool VoyageData::setDestName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_destNamePresent = true;
    m_destName = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getDestName() const {

    return m_destName;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDestName() const {

    return m_destNamePresent;
}

// setter for VoyageData
bool VoyageData::setDepartCode(QString val) {

    // check if the new value is within min length
    if (val.length() < 5)
        return false;
    // check if the new value is within max length
    if (val.length() > 15)
        return false;
    m_departCodePresent = true;
    m_departCode = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getDepartCode() const {

    return m_departCode;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDepartCode() const {

    return m_departCodePresent;
}

// setter for VoyageData
bool VoyageData::setDepartName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_departNamePresent = true;
    m_departName = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getDepartName() const {

    return m_departName;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDepartName() const {

    return m_departNamePresent;
}

// setter for VoyageData
bool VoyageData::setDraught(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_draughtPresent = true;
    m_draught = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getDraught() const {

    return m_draught;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDraught() const {

    return m_draughtPresent;
}

// setter for VoyageData
bool VoyageData::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QDateTime VoyageData::getETA() const {

    return m_ETA;
}

// check if optional element VoyageData has been set
bool VoyageData::hasETA() const {

    return m_ETAPresent;
}

// setter for VoyageData
bool VoyageData::setATD(QDateTime val) {

    m_ATDPresent = true;
    m_ATD = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QDateTime VoyageData::getATD() const {

    return m_ATD;
}

// check if optional element VoyageData has been set
bool VoyageData::hasATD() const {

    return m_ATDPresent;
}

// setter for VoyageData
bool VoyageData::setISPSLevel(float val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_ISPSLevelPresent = true;
    m_ISPSLevel = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getISPSLevel() const {

    return m_ISPSLevel;
}

// check if optional element VoyageData has been set
bool VoyageData::hasISPSLevel() const {

    return m_ISPSLevelPresent;
}

// setter for VoyageData
bool VoyageData::setOverSizedLength(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_overSizedLengthPresent = true;
    m_overSizedLength = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getOverSizedLength() const {

    return m_overSizedLength;
}

// check if optional element VoyageData has been set
bool VoyageData::hasOverSizedLength() const {

    return m_overSizedLengthPresent;
}

// setter for VoyageData
bool VoyageData::setOverSizedWidth(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_overSizedWidthPresent = true;
    m_overSizedWidth = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getOverSizedWidth() const {

    return m_overSizedWidth;
}

// check if optional element VoyageData has been set
bool VoyageData::hasOverSizedWidth() const {

    return m_overSizedWidthPresent;
}

// setter for VoyageData
bool VoyageData::setPersonsOnBoard(int val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
int VoyageData::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPersonsOnBoard() const {

    return m_personsOnBoardPresent;
}

// setter for VoyageData
bool VoyageData::setPilots(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_pilotsPresent = true;
    m_pilots = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
float VoyageData::getPilots() const {

    return m_pilots;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPilots() const {

    return m_pilotsPresent;
}

// setter for VoyageData
bool VoyageData::setRouteBound(bool val) {

    m_routeBoundPresent = true;
    m_routeBound = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
bool VoyageData::getRouteBound() const {

    return m_routeBound;
}

// check if optional element VoyageData has been set
bool VoyageData::hasRouteBound() const {

    return m_routeBoundPresent;
}

// setter for VoyageData
bool VoyageData::setSourceId(QString val) {

    // check if the new value is within min length
    if (val.length() < 5)
        return false;
    // check if the new value is within max length
    if (val.length() > 15)
        return false;
    m_sourceIdPresent = true;
    m_sourceId = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getSourceId() const {

    return m_sourceId;
}

// check if optional element VoyageData has been set
bool VoyageData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for VoyageData
bool VoyageData::setSourceName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_sourceNamePresent = true;
    m_sourceName = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QString VoyageData::getSourceName() const {

    return m_sourceName;
}

// setter for VoyageData
bool VoyageData::setSourceType(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_sourceTypePresent = true;
    m_sourceType = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
int VoyageData::getSourceType() const {

    return m_sourceType;
}

// setter for VoyageData
bool VoyageData::setTankerStatus(int val) {

    // check if the new value is an approved value
    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_tankerStatusPresent = true;
    m_tankerStatus = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
int VoyageData::getTankerStatus() const {

    return m_tankerStatus;
}

// check if optional element VoyageData has been set
bool VoyageData::hasTankerStatus() const {

    return m_tankerStatusPresent;
}

// setter for VoyageData
bool VoyageData::setTugs(bool val) {

    m_tugsPresent = true;
    m_tugs = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
bool VoyageData::getTugs() const {

    return m_tugs;
}

// check if optional element VoyageData has been set
bool VoyageData::hasTugs() const {

    return m_tugsPresent;
}

// setter for VoyageData
bool VoyageData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
    m_changed = true;
    return true;
}

// getter for VoyageData
QDateTime VoyageData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
const QString& VoyageData::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<VoyageData";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasAirDraught() ) {
                xml.append(" AirDraught=\"" + QString::number(m_airDraught, 'f', 2) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_idPresent) {
            xml.append(" Id=\"" + QString::number( m_id ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Id not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasCargoTypeIMO() ) {
                xml.append(" CargoTypeIMO=\"" + QString::number( m_cargoTypeIMO ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasContactIdentity() ) {
                xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDestCode() ) {
                xml.append(" DestCode=\"" + encode (m_destCode) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDestName() ) {
                xml.append(" DestName=\"" + encode (m_destName) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDepartCode() ) {
                xml.append(" DepartCode=\"" + encode (m_departCode) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDepartName() ) {
                xml.append(" DepartName=\"" + encode (m_departName) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDraught() ) {
                xml.append(" Draught=\"" + QString::number(m_draught, 'f', 2) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasETA() ) {
                xml.append(" ETA=\"" + dateToString( m_ETA) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasATD() ) {
                xml.append(" ATD=\"" + dateToString( m_ATD) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasISPSLevel() ) {
                xml.append(" ISPSLevel=\"" + QString::number( m_ISPSLevel, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasOverSizedLength() ) {
                xml.append(" OverSizedLength=\"" + QString::number(m_overSizedLength, 'f', 1) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasOverSizedWidth() ) {
                xml.append(" OverSizedWidth=\"" + QString::number(m_overSizedWidth, 'f', 1) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasPersonsOnBoard() ) {
                xml.append(" PersonsOnBoard=\"" + QString::number( m_personsOnBoard ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasPilots() ) {
                xml.append(" Pilots=\"" + QString::number( m_pilots, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasRouteBound() ) {
                xml.append(" RouteBound=\"" + QString( m_routeBound ? "true" : "false" ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasSourceId() ) {
                xml.append(" SourceId=\"" + encode (m_sourceId) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_sourceNamePresent) {
            xml.append(" SourceName=\"" + encode (m_sourceName) + endAttr);
        } else { // required attribute not present
            m_lastError = "SourceName not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_sourceTypePresent) {
            xml.append(" SourceType=\"" + QString::number( m_sourceType ) + endAttr);
        } else { // required attribute not present
            m_lastError = "SourceType not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasTankerStatus() ) {
                xml.append(" TankerStatus=\"" + QString::number( m_tankerStatus ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasTugs() ) {
                xml.append(" Tugs=\"" + QString( m_tugs ? "true" : "false" ) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_updateTimePresent) {
            xml.append(" UpdateTime=\"" + dateToString( m_updateTime) + endAttr);
        } else { // required attribute not present
            m_lastError = "UpdateTime not set";
            m_store  = QString::null;
            return m_store;
        }
        xml.append(">\n");
        if (m_waypoints.count() < 0) {
            m_lastError = "not enough Waypoint values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_waypoints.count(); i++ ) {
            Waypoint attribute = m_waypoints.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "Waypoint:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</VoyageData>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString VoyageData::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString VoyageData::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "VoyageData\n";
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught, 'f', 2) + endAttr);
    }
    str.append( lead + "    Id = " + QString::number( m_id ) + endAttr);
    // check for presence of optional attribute
    if ( hasCargoTypeIMO() ) {
        str.append( lead + "    CargoTypeIMO = " + QString::number( m_cargoTypeIMO ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDestCode() ) {
        str.append( lead + "    DestCode = " + m_destCode + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDestName() ) {
        str.append( lead + "    DestName = " + m_destName + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDepartCode() ) {
        str.append( lead + "    DepartCode = " + m_departCode + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDepartName() ) {
        str.append( lead + "    DepartName = " + m_departName + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught, 'f', 2) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + dateToString( m_ETA) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasATD() ) {
        str.append( lead + "    ATD = " + dateToString( m_ATD) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasISPSLevel() ) {
        str.append( lead + "    ISPSLevel = " + QString::number( m_ISPSLevel, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasOverSizedLength() ) {
        str.append( lead + "    OverSizedLength = " + QString::number(m_overSizedLength, 'f', 1) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasOverSizedWidth() ) {
        str.append( lead + "    OverSizedWidth = " + QString::number(m_overSizedWidth, 'f', 1) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number( m_personsOnBoard ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasPilots() ) {
        str.append( lead + "    Pilots = " + QString::number( m_pilots, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasRouteBound() ) {
        str.append( lead + "    RouteBound = " + QString( m_routeBound ? "true" : "false" ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + endAttr);
    }
    str.append( lead + "    SourceName = " + m_sourceName + endAttr);
    str.append( lead + "    SourceType = " + QString::number( m_sourceType ) + endAttr);
    // check for presence of optional attribute
    if ( hasTankerStatus() ) {
        str.append( lead + "    TankerStatus = " + QString::number( m_tankerStatus ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasTugs() ) {
        str.append( lead + "    Tugs = " + QString( m_tugs ? "true" : "false" ) + endAttr);
    }
    str.append( lead + "    UpdateTime = " + dateToString( m_updateTime) + endAttr);
    // add all included data
    for(int i=0; i < m_waypoints.count(); i++ ) {
        Waypoint attribute = m_waypoints.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& VoyageData::lastError() const {
    return m_lastError;
}

const bool& VoyageData::changed() const {
    return m_changed;
}

const QString& VoyageData::store() const {
    return m_store;
}


} //end ns
