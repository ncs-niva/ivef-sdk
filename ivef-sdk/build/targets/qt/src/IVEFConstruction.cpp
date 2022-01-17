#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFConstruction.h"

namespace ivef {

// Constructor
Construction::Construction()
 :  QObject(),
    m_unTypePresent( false ),
    m_hullColor(),
    m_hullColorPresent( false ),
    m_hullType( 0 ),
    m_hullTypePresent( false ),
    m_deadWeight( 0.0 ),
    m_deadWeightPresent( false ),
    m_grossWeight( 0.0 ),
    m_grossWeightPresent( false ),
    m_length( 0.0 ),
    m_lengthPresent( false ),
    m_lloydsShipType( 0 ),
    m_lloydsShipTypePresent( false ),
    m_yearOfBuild( 0 ),
    m_yearOfBuildPresent( false ),
    m_maxAirDraught( 0.0 ),
    m_maxAirDraughtPresent( false ),
    m_maxDraught( 0.0 ),
    m_maxDraughtPresent( false ),
    m_maxPersonsOnBoard( 0 ),
    m_maxPersonsOnBoardPresent( false ),
    m_maxSpeed( 0.0 ),
    m_maxSpeedPresent( false ),
    m_width( 0.0 ),
    m_widthPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Construction::Construction(XmlStreamReader& xml)
 :  QObject(),
    m_unTypePresent( false ),
    m_hullColor(),
    m_hullColorPresent( false ),
    m_hullType( 0 ),
    m_hullTypePresent( false ),
    m_deadWeight( 0.0 ),
    m_deadWeightPresent( false ),
    m_grossWeight( 0.0 ),
    m_grossWeightPresent( false ),
    m_length( 0.0 ),
    m_lengthPresent( false ),
    m_lloydsShipType( 0 ),
    m_lloydsShipTypePresent( false ),
    m_yearOfBuild( 0 ),
    m_yearOfBuildPresent( false ),
    m_maxAirDraught( 0.0 ),
    m_maxAirDraughtPresent( false ),
    m_maxDraught( 0.0 ),
    m_maxDraughtPresent( false ),
    m_maxPersonsOnBoard( 0 ),
    m_maxPersonsOnBoardPresent( false ),
    m_maxSpeed( 0.0 ),
    m_maxSpeedPresent( false ),
    m_width( 0.0 ),
    m_widthPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "HullColor" ) )
    {
        if ( !setHullColor( attr.value( "HullColor" ).toString() ) )
            xml.validationError( "error set HullColor = " + attr.value( "HullColor" ).toString() );
    }
    if ( attr.hasAttribute( "HullType" ) )
    {
        if ( !setHullType( attr.value( "HullType" ).toString().toInt() ) )
            xml.validationError( "error set HullType = " + attr.value( "HullType" ).toString() );
    }
    if ( attr.hasAttribute( "DeadWeight" ) )
    {
        if ( !setDeadWeight( attr.value( "DeadWeight" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set DeadWeight = " + attr.value( "DeadWeight" ).toString() );
    }
    if ( attr.hasAttribute( "GrossWeight" ) )
    {
        if ( !setGrossWeight( attr.value( "GrossWeight" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set GrossWeight = " + attr.value( "GrossWeight" ).toString() );
    }
    if ( attr.hasAttribute( "Length" ) )
    {
        if ( !setLength( attr.value( "Length" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Length = " + attr.value( "Length" ).toString() );
    }
    if ( attr.hasAttribute( "LloydsShipType" ) )
    {
        if ( !setLloydsShipType( attr.value( "LloydsShipType" ).toString().toInt() ) )
            xml.validationError( "error set LloydsShipType = " + attr.value( "LloydsShipType" ).toString() );
    }
    if ( attr.hasAttribute( "YearOfBuild" ) )
    {
        if ( !setYearOfBuild( attr.value( "YearOfBuild" ).toString().toInt() ) )
            xml.validationError( "error set YearOfBuild = " + attr.value( "YearOfBuild" ).toString() );
    }
    if ( attr.hasAttribute( "MaxAirDraught" ) )
    {
        if ( !setMaxAirDraught( attr.value( "MaxAirDraught" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set MaxAirDraught = " + attr.value( "MaxAirDraught" ).toString() );
    }
    if ( attr.hasAttribute( "MaxDraught" ) )
    {
        if ( !setMaxDraught( attr.value( "MaxDraught" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set MaxDraught = " + attr.value( "MaxDraught" ).toString() );
    }
    if ( attr.hasAttribute( "MaxPersonsOnBoard" ) )
    {
        if ( !setMaxPersonsOnBoard( attr.value( "MaxPersonsOnBoard" ).toString().toInt() ) )
            xml.validationError( "error set MaxPersonsOnBoard = " + attr.value( "MaxPersonsOnBoard" ).toString() );
    }
    if ( attr.hasAttribute( "MaxSpeed" ) )
    {
        if ( !setMaxSpeed( attr.value( "MaxSpeed" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set MaxSpeed = " + attr.value( "MaxSpeed" ).toString() );
    }
    if ( attr.hasAttribute( "Width" ) )
    {
        if ( !setWidth( attr.value( "Width" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Width = " + attr.value( "Width" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Construction" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "UnType" )
            {
                UnType val( xml );
                if ( xml.name() != "UnType" )
                    xml.raiseError( "tag mismatch UnType" );
                else if ( !setUnType( val ) )
                    xml.validationError( "error set UnType"  );
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
Construction::Construction(const Construction &val)
 :  QObject(),
    m_unType( val.m_unType ),
    m_unTypePresent( val.m_unTypePresent ),
    m_hullColor( val.m_hullColor ),
    m_hullColorPresent( val.m_hullColorPresent ),
    m_hullType( val.m_hullType ),
    m_hullTypePresent( val.m_hullTypePresent ),
    m_deadWeight( val.m_deadWeight ),
    m_deadWeightPresent( val.m_deadWeightPresent ),
    m_grossWeight( val.m_grossWeight ),
    m_grossWeightPresent( val.m_grossWeightPresent ),
    m_length( val.m_length ),
    m_lengthPresent( val.m_lengthPresent ),
    m_lloydsShipType( val.m_lloydsShipType ),
    m_lloydsShipTypePresent( val.m_lloydsShipTypePresent ),
    m_yearOfBuild( val.m_yearOfBuild ),
    m_yearOfBuildPresent( val.m_yearOfBuildPresent ),
    m_maxAirDraught( val.m_maxAirDraught ),
    m_maxAirDraughtPresent( val.m_maxAirDraughtPresent ),
    m_maxDraught( val.m_maxDraught ),
    m_maxDraughtPresent( val.m_maxDraughtPresent ),
    m_maxPersonsOnBoard( val.m_maxPersonsOnBoard ),
    m_maxPersonsOnBoardPresent( val.m_maxPersonsOnBoardPresent ),
    m_maxSpeed( val.m_maxSpeed ),
    m_maxSpeedPresent( val.m_maxSpeedPresent ),
    m_width( val.m_width ),
    m_widthPresent( val.m_widthPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Construction::operator==(const Construction &val) {

    if (!(m_unTypePresent == val.m_unTypePresent)) return false;
    if (!(m_unType == val.m_unType)) return false;
    if (!(m_hullColorPresent == val.m_hullColorPresent)) return false;
    if (!(m_hullColor == val.m_hullColor)) return false;
    if (!(m_hullTypePresent == val.m_hullTypePresent)) return false;
    if (!(m_hullType == val.m_hullType)) return false;
    if (!(m_deadWeightPresent == val.m_deadWeightPresent)) return false;
    if (!(m_deadWeight == val.m_deadWeight)) return false;
    if (!(m_grossWeightPresent == val.m_grossWeightPresent)) return false;
    if (!(m_grossWeight == val.m_grossWeight)) return false;
    if (!(m_lengthPresent == val.m_lengthPresent)) return false;
    if (!(m_length == val.m_length)) return false;
    if (!(m_lloydsShipTypePresent == val.m_lloydsShipTypePresent)) return false;
    if (!(m_lloydsShipType == val.m_lloydsShipType)) return false;
    if (!(m_yearOfBuildPresent == val.m_yearOfBuildPresent)) return false;
    if (!(m_yearOfBuild == val.m_yearOfBuild)) return false;
    if (!(m_maxAirDraughtPresent == val.m_maxAirDraughtPresent)) return false;
    if (!(m_maxAirDraught == val.m_maxAirDraught)) return false;
    if (!(m_maxDraughtPresent == val.m_maxDraughtPresent)) return false;
    if (!(m_maxDraught == val.m_maxDraught)) return false;
    if (!(m_maxPersonsOnBoardPresent == val.m_maxPersonsOnBoardPresent)) return false;
    if (!(m_maxPersonsOnBoard == val.m_maxPersonsOnBoard)) return false;
    if (!(m_maxSpeedPresent == val.m_maxSpeedPresent)) return false;
    if (!(m_maxSpeed == val.m_maxSpeed)) return false;
    if (!(m_widthPresent == val.m_widthPresent)) return false;
    if (!(m_width == val.m_width)) return false;
    return true;
}

// assignement
Construction & Construction::operator=(const Construction &val) {

    m_unTypePresent = val.m_unTypePresent;
    m_unType = val.m_unType;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_hullTypePresent = val.m_hullTypePresent;
    m_hullType = val.m_hullType;
    m_deadWeightPresent = val.m_deadWeightPresent;
    m_deadWeight = val.m_deadWeight;
    m_grossWeightPresent = val.m_grossWeightPresent;
    m_grossWeight = val.m_grossWeight;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_yearOfBuildPresent = val.m_yearOfBuildPresent;
    m_yearOfBuild = val.m_yearOfBuild;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_maxPersonsOnBoardPresent = val.m_maxPersonsOnBoardPresent;
    m_maxPersonsOnBoard = val.m_maxPersonsOnBoard;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Construction
bool Construction::setUnType(const UnType& val) {

    m_unTypePresent = true;
    m_unType = val;
    m_changed = true;
    return true;
}

// getter for Construction
const UnType& Construction::getUnType() const {

    return m_unType;
}

// check if optional element Construction has been set
bool Construction::hasUnType() const {

    return m_unTypePresent;
}

// setter for Construction
bool Construction::setHullColor(QString val) {

    // check if the new value is within min length
    if (val.length() < 6)
        return false;
    // check if the new value is within max length
    if (val.length() > 6)
        return false;
    m_hullColorPresent = true;
    m_hullColor = val;
    m_changed = true;
    return true;
}

// getter for Construction
QString Construction::getHullColor() const {

    return m_hullColor;
}

// check if optional element Construction has been set
bool Construction::hasHullColor() const {

    return m_hullColorPresent;
}

// setter for Construction
bool Construction::setHullType(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_hullTypePresent = true;
    m_hullType = val;
    m_changed = true;
    return true;
}

// getter for Construction
int Construction::getHullType() const {

    return m_hullType;
}

// check if optional element Construction has been set
bool Construction::hasHullType() const {

    return m_hullTypePresent;
}

// setter for Construction
bool Construction::setDeadWeight(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_deadWeightPresent = true;
    m_deadWeight = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getDeadWeight() const {

    return m_deadWeight;
}

// check if optional element Construction has been set
bool Construction::hasDeadWeight() const {

    return m_deadWeightPresent;
}

// setter for Construction
bool Construction::setGrossWeight(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_grossWeightPresent = true;
    m_grossWeight = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getGrossWeight() const {

    return m_grossWeight;
}

// check if optional element Construction has been set
bool Construction::hasGrossWeight() const {

    return m_grossWeightPresent;
}

// setter for Construction
bool Construction::setLength(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_lengthPresent = true;
    m_length = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getLength() const {

    return m_length;
}

// check if optional element Construction has been set
bool Construction::hasLength() const {

    return m_lengthPresent;
}

// setter for Construction
bool Construction::setLloydsShipType(int val) {

    m_lloydsShipTypePresent = true;
    m_lloydsShipType = val;
    m_changed = true;
    return true;
}

// getter for Construction
int Construction::getLloydsShipType() const {

    return m_lloydsShipType;
}

// check if optional element Construction has been set
bool Construction::hasLloydsShipType() const {

    return m_lloydsShipTypePresent;
}

// setter for Construction
bool Construction::setYearOfBuild(int val) {

    m_yearOfBuildPresent = true;
    m_yearOfBuild = val;
    m_changed = true;
    return true;
}

// getter for Construction
int Construction::getYearOfBuild() const {

    return m_yearOfBuild;
}

// check if optional element Construction has been set
bool Construction::hasYearOfBuild() const {

    return m_yearOfBuildPresent;
}

// setter for Construction
bool Construction::setMaxAirDraught(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getMaxAirDraught() const {

    return m_maxAirDraught;
}

// check if optional element Construction has been set
bool Construction::hasMaxAirDraught() const {

    return m_maxAirDraughtPresent;
}

// setter for Construction
bool Construction::setMaxDraught(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_maxDraughtPresent = true;
    m_maxDraught = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getMaxDraught() const {

    return m_maxDraught;
}

// check if optional element Construction has been set
bool Construction::hasMaxDraught() const {

    return m_maxDraughtPresent;
}

// setter for Construction
bool Construction::setMaxPersonsOnBoard(int val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_maxPersonsOnBoardPresent = true;
    m_maxPersonsOnBoard = val;
    m_changed = true;
    return true;
}

// getter for Construction
int Construction::getMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoard;
}

// check if optional element Construction has been set
bool Construction::hasMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoardPresent;
}

// setter for Construction
bool Construction::setMaxSpeed(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_maxSpeedPresent = true;
    m_maxSpeed = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getMaxSpeed() const {

    return m_maxSpeed;
}

// check if optional element Construction has been set
bool Construction::hasMaxSpeed() const {

    return m_maxSpeedPresent;
}

// setter for Construction
bool Construction::setWidth(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_widthPresent = true;
    m_width = val;
    m_changed = true;
    return true;
}

// getter for Construction
float Construction::getWidth() const {

    return m_width;
}

// check if optional element Construction has been set
bool Construction::hasWidth() const {

    return m_widthPresent;
}

// Get XML Representation
const QString& Construction::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Construction";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasHullColor() ) {
                xml.append(" HullColor=\"" + encode (m_hullColor) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasHullType() ) {
                xml.append(" HullType=\"" + QString::number( m_hullType ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDeadWeight() ) {
                xml.append(" DeadWeight=\"" + QString::number( m_deadWeight, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasGrossWeight() ) {
                xml.append(" GrossWeight=\"" + QString::number( m_grossWeight, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasLength() ) {
                xml.append(" Length=\"" + QString::number( m_length, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasLloydsShipType() ) {
                xml.append(" LloydsShipType=\"" + QString::number( m_lloydsShipType ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasYearOfBuild() ) {
                xml.append(" YearOfBuild=\"" + QString::number( m_yearOfBuild ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasMaxAirDraught() ) {
                xml.append(" MaxAirDraught=\"" + QString::number(m_maxAirDraught, 'f', 1) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasMaxDraught() ) {
                xml.append(" MaxDraught=\"" + QString::number(m_maxDraught, 'f', 1) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasMaxPersonsOnBoard() ) {
                xml.append(" MaxPersonsOnBoard=\"" + QString::number( m_maxPersonsOnBoard ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasMaxSpeed() ) {
                xml.append(" MaxSpeed=\"" + QString::number( m_maxSpeed, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasWidth() ) {
                xml.append(" Width=\"" + QString::number( m_width, 'f') + endAttr);
        }
        xml.append(">\n");
        // add optional data if available
        if ( hasUnType() ) {
            dataMember = m_unType.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "UnType:" + m_unType.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</Construction>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Construction::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Construction::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Construction\n";
    // check for presence of optional attribute
    if ( hasHullColor() ) {
        str.append( lead + "    HullColor = " + m_hullColor + endAttr);
    }
    // check for presence of optional attribute
    if ( hasHullType() ) {
        str.append( lead + "    HullType = " + QString::number( m_hullType ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDeadWeight() ) {
        str.append( lead + "    DeadWeight = " + QString::number( m_deadWeight, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasGrossWeight() ) {
        str.append( lead + "    GrossWeight = " + QString::number( m_grossWeight, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number( m_length, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasLloydsShipType() ) {
        str.append( lead + "    LloydsShipType = " + QString::number( m_lloydsShipType ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasYearOfBuild() ) {
        str.append( lead + "    YearOfBuild = " + QString::number( m_yearOfBuild ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasMaxAirDraught() ) {
        str.append( lead + "    MaxAirDraught = " + QString::number(m_maxAirDraught, 'f', 1) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught, 'f', 1) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasMaxPersonsOnBoard() ) {
        str.append( lead + "    MaxPersonsOnBoard = " + QString::number( m_maxPersonsOnBoard ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasMaxSpeed() ) {
        str.append( lead + "    MaxSpeed = " + QString::number( m_maxSpeed, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number( m_width, 'f') + endAttr);
    }
    // add all optional data if present
    if ( hasUnType() ) {
        str.append( m_unType.toString(lead + "    ") );
    }
    return str;
}

const QString& Construction::lastError() const {
    return m_lastError;
}

const bool& Construction::changed() const {
    return m_changed;
}

const QString& Construction::store() const {
    return m_store;
}


} //end ns
