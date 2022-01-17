#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFPos.h"

namespace ivef {

// Constructor
Pos::Pos()
 :  QObject(),
    m_altitude( 0.0 ),
    m_altitudePresent( false ),
    m_estAccAlt( 0.0 ),
    m_estAccAltPresent( false ),
    m_estAccLat( 0.0 ),
    m_estAccLatPresent( false ),
    m_estAccLong( 0.0 ),
    m_estAccLongPresent( false ),
    m_lat( 0.0 ),
    m_latPresent( false ),
    m_long( 0.0 ),
    m_longPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Pos::Pos(XmlStreamReader& xml)
 :  QObject(),
    m_altitude( 0.0 ),
    m_altitudePresent( false ),
    m_estAccAlt( 0.0 ),
    m_estAccAltPresent( false ),
    m_estAccLat( 0.0 ),
    m_estAccLatPresent( false ),
    m_estAccLong( 0.0 ),
    m_estAccLongPresent( false ),
    m_lat( 0.0 ),
    m_latPresent( false ),
    m_long( 0.0 ),
    m_longPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Altitude" ) )
    {
        if ( !setAltitude( attr.value( "Altitude" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Altitude = " + attr.value( "Altitude" ).toString() );
    }
    if ( attr.hasAttribute( "EstAccAlt" ) )
    {
        if ( !setEstAccAlt( attr.value( "EstAccAlt" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set EstAccAlt = " + attr.value( "EstAccAlt" ).toString() );
    }
    if ( attr.hasAttribute( "EstAccLat" ) )
    {
        if ( !setEstAccLat( attr.value( "EstAccLat" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set EstAccLat = " + attr.value( "EstAccLat" ).toString() );
    }
    if ( attr.hasAttribute( "EstAccLong" ) )
    {
        if ( !setEstAccLong( attr.value( "EstAccLong" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set EstAccLong = " + attr.value( "EstAccLong" ).toString() );
    }
    if ( attr.hasAttribute( "Lat" ) )
    {
        if ( !setLat( attr.value( "Lat" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Lat = " + attr.value( "Lat" ).toString() );
    }
    if ( attr.hasAttribute( "Long" ) )
    {
        if ( !setLong( attr.value( "Long" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Long = " + attr.value( "Long" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Pos" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Pos::Pos(const Pos &val)
 :  QObject(),
    m_altitude( val.m_altitude ),
    m_altitudePresent( val.m_altitudePresent ),
    m_estAccAlt( val.m_estAccAlt ),
    m_estAccAltPresent( val.m_estAccAltPresent ),
    m_estAccLat( val.m_estAccLat ),
    m_estAccLatPresent( val.m_estAccLatPresent ),
    m_estAccLong( val.m_estAccLong ),
    m_estAccLongPresent( val.m_estAccLongPresent ),
    m_lat( val.m_lat ),
    m_latPresent( val.m_latPresent ),
    m_long( val.m_long ),
    m_longPresent( val.m_longPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Pos::operator==(const Pos &val) {

    if (!(m_altitudePresent == val.m_altitudePresent)) return false;
    if (!(m_altitude == val.m_altitude)) return false;
    if (!(m_estAccAltPresent == val.m_estAccAltPresent)) return false;
    if (!(m_estAccAlt == val.m_estAccAlt)) return false;
    if (!(m_estAccLatPresent == val.m_estAccLatPresent)) return false;
    if (!(m_estAccLat == val.m_estAccLat)) return false;
    if (!(m_estAccLongPresent == val.m_estAccLongPresent)) return false;
    if (!(m_estAccLong == val.m_estAccLong)) return false;
    if (!(m_latPresent == val.m_latPresent)) return false;
    if (!(m_lat == val.m_lat)) return false;
    if (!(m_longPresent == val.m_longPresent)) return false;
    if (!(m_long == val.m_long)) return false;
    return true;
}

// assignement
Pos & Pos::operator=(const Pos &val) {

    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_estAccAltPresent = val.m_estAccAltPresent;
    m_estAccAlt = val.m_estAccAlt;
    m_estAccLatPresent = val.m_estAccLatPresent;
    m_estAccLat = val.m_estAccLat;
    m_estAccLongPresent = val.m_estAccLongPresent;
    m_estAccLong = val.m_estAccLong;
    m_latPresent = val.m_latPresent;
    m_lat = val.m_lat;
    m_longPresent = val.m_longPresent;
    m_long = val.m_long;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Pos
bool Pos::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getAltitude() const {

    return m_altitude;
}

// check if optional element Pos has been set
bool Pos::hasAltitude() const {

    return m_altitudePresent;
}

// setter for Pos
bool Pos::setEstAccAlt(float val) {

    m_estAccAltPresent = true;
    m_estAccAlt = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getEstAccAlt() const {

    return m_estAccAlt;
}

// check if optional element Pos has been set
bool Pos::hasEstAccAlt() const {

    return m_estAccAltPresent;
}

// setter for Pos
bool Pos::setEstAccLat(float val) {

    m_estAccLatPresent = true;
    m_estAccLat = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getEstAccLat() const {

    return m_estAccLat;
}

// check if optional element Pos has been set
bool Pos::hasEstAccLat() const {

    return m_estAccLatPresent;
}

// setter for Pos
bool Pos::setEstAccLong(float val) {

    m_estAccLongPresent = true;
    m_estAccLong = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getEstAccLong() const {

    return m_estAccLong;
}

// check if optional element Pos has been set
bool Pos::hasEstAccLong() const {

    return m_estAccLongPresent;
}

// setter for Pos
bool Pos::setLat(float val) {

    // check if the new value is within min inclusive
    if (val < -90)
        return false;
    // check if the new value is within max inclusive
    if (val > 90)
        return false;
    m_latPresent = true;
    m_lat = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getLat() const {

    return m_lat;
}

// setter for Pos
bool Pos::setLong(float val) {

    // check if the new value is within min exclusive
    if (val <= -180)
        return false;
    // check if the new value is within max inclusive
    if (val > 180)
        return false;
    m_longPresent = true;
    m_long = val;
    m_changed = true;
    return true;
}

// getter for Pos
float Pos::getLong() const {

    return m_long;
}

// Get XML Representation
const QString& Pos::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Pos";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasAltitude() ) {
                xml.append(" Altitude=\"" + QString::number( m_altitude, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasEstAccAlt() ) {
                xml.append(" EstAccAlt=\"" + QString::number( m_estAccAlt, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasEstAccLat() ) {
                xml.append(" EstAccLat=\"" + QString::number( m_estAccLat, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasEstAccLong() ) {
                xml.append(" EstAccLong=\"" + QString::number( m_estAccLong, 'f') + endAttr);
        }
            // check for presence of required  attribute
        if ( m_latPresent) {
            xml.append(" Lat=\"" + QString::number(m_lat, 'f', 5) + endAttr);
        } else { // required attribute not present
            m_lastError = "Lat not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_longPresent) {
            xml.append(" Long=\"" + QString::number(m_long, 'f', 5) + endAttr);
        } else { // required attribute not present
            m_lastError = "Long not set";
            m_store  = QString::null;
            return m_store;
        }
        xml.append("/>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Pos::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Pos::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Pos\n";
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number( m_altitude, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasEstAccAlt() ) {
        str.append( lead + "    EstAccAlt = " + QString::number( m_estAccAlt, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasEstAccLat() ) {
        str.append( lead + "    EstAccLat = " + QString::number( m_estAccLat, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasEstAccLong() ) {
        str.append( lead + "    EstAccLong = " + QString::number( m_estAccLong, 'f') + endAttr);
    }
    str.append( lead + "    Lat = " + QString::number(m_lat, 'f', 5) + endAttr);
    str.append( lead + "    Long = " + QString::number(m_long, 'f', 5) + endAttr);
    return str;
}

const QString& Pos::lastError() const {
    return m_lastError;
}

const bool& Pos::changed() const {
    return m_changed;
}

const QString& Pos::store() const {
    return m_store;
}


} //end ns
