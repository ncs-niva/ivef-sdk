#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFWaypoint.h"

namespace ivef {

// Constructor
Waypoint::Waypoint()
 :  QObject(),
    m_posPresent( false ),
    m_ATA(),
    m_ATAPresent( false ),
    m_ETA(),
    m_ETAPresent( false ),
    m_RTA(),
    m_RTAPresent( false ),
    m_loCode(),
    m_loCodePresent( false ),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Waypoint::Waypoint(XmlStreamReader& xml)
 :  QObject(),
    m_posPresent( false ),
    m_ATA(),
    m_ATAPresent( false ),
    m_ETA(),
    m_ETAPresent( false ),
    m_RTA(),
    m_RTAPresent( false ),
    m_loCode(),
    m_loCodePresent( false ),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "ATA" ) )
    {
        if ( !setATA( QDateTime::fromString(attr.value( "ATA" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set ATA = " + attr.value( "ATA" ).toString() );
    }
    if ( attr.hasAttribute( "ETA" ) )
    {
        if ( !setETA( QDateTime::fromString(attr.value( "ETA" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set ETA = " + attr.value( "ETA" ).toString() );
    }
    if ( attr.hasAttribute( "RTA" ) )
    {
        if ( !setRTA( QDateTime::fromString(attr.value( "RTA" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set RTA = " + attr.value( "RTA" ).toString() );
    }
    if ( attr.hasAttribute( "LoCode" ) )
    {
        if ( !setLoCode( attr.value( "LoCode" ).toString() ) )
            xml.validationError( "error set LoCode = " + attr.value( "LoCode" ).toString() );
    }
    if ( attr.hasAttribute( "Name" ) )
    {
        if ( !setName( attr.value( "Name" ).toString() ) )
            xml.validationError( "error set Name = " + attr.value( "Name" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Waypoint" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Pos" )
            {
                Pos val( xml );
                if ( xml.name() != "Pos" )
                    xml.raiseError( "tag mismatch Pos" );
                else if ( !setPos( val ) )
                    xml.validationError( "error set Pos"  );
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
Waypoint::Waypoint(const Waypoint &val)
 :  QObject(),
    m_pos( val.m_pos ),
    m_posPresent( val.m_posPresent ),
    m_ATA( val.m_ATA ),
    m_ATAPresent( val.m_ATAPresent ),
    m_ETA( val.m_ETA ),
    m_ETAPresent( val.m_ETAPresent ),
    m_RTA( val.m_RTA ),
    m_RTAPresent( val.m_RTAPresent ),
    m_loCode( val.m_loCode ),
    m_loCodePresent( val.m_loCodePresent ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Waypoint::operator==(const Waypoint &val) {

    if (!(m_posPresent == val.m_posPresent)) return false;
    if (!(m_pos == val.m_pos)) return false;
    if (!(m_ATAPresent == val.m_ATAPresent)) return false;
    if (!(m_ATA == val.m_ATA)) return false;
    if (!(m_ETAPresent == val.m_ETAPresent)) return false;
    if (!(m_ETA == val.m_ETA)) return false;
    if (!(m_RTAPresent == val.m_RTAPresent)) return false;
    if (!(m_RTA == val.m_RTA)) return false;
    if (!(m_loCodePresent == val.m_loCodePresent)) return false;
    if (!(m_loCode == val.m_loCode)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
Waypoint & Waypoint::operator=(const Waypoint &val) {

    m_posPresent = val.m_posPresent;
    m_pos = val.m_pos;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_RTAPresent = val.m_RTAPresent;
    m_RTA = val.m_RTA;
    m_loCodePresent = val.m_loCodePresent;
    m_loCode = val.m_loCode;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Waypoint
bool Waypoint::setPos(const Pos& val) {

    m_posPresent = true;
    m_pos = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
const Pos& Waypoint::getPos() const {

    return m_pos;
}

// check if optional element Waypoint has been set
bool Waypoint::hasPos() const {

    return m_posPresent;
}

// setter for Waypoint
bool Waypoint::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
QDateTime Waypoint::getATA() const {

    return m_ATA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasATA() const {

    return m_ATAPresent;
}

// setter for Waypoint
bool Waypoint::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
QDateTime Waypoint::getETA() const {

    return m_ETA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasETA() const {

    return m_ETAPresent;
}

// setter for Waypoint
bool Waypoint::setRTA(QDateTime val) {

    m_RTAPresent = true;
    m_RTA = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
QDateTime Waypoint::getRTA() const {

    return m_RTA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasRTA() const {

    return m_RTAPresent;
}

// setter for Waypoint
bool Waypoint::setLoCode(QString val) {

    // check if the new value is within min length
    if (val.length() < 5)
        return false;
    // check if the new value is within max length
    if (val.length() > 15)
        return false;
    m_loCodePresent = true;
    m_loCode = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
QString Waypoint::getLoCode() const {

    return m_loCode;
}

// check if optional element Waypoint has been set
bool Waypoint::hasLoCode() const {

    return m_loCodePresent;
}

// setter for Waypoint
bool Waypoint::setName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_namePresent = true;
    m_name = val;
    m_changed = true;
    return true;
}

// getter for Waypoint
QString Waypoint::getName() const {

    return m_name;
}

// Get XML Representation
const QString& Waypoint::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Waypoint";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasATA() ) {
                xml.append(" ATA=\"" + dateToString( m_ATA) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasETA() ) {
                xml.append(" ETA=\"" + dateToString( m_ETA) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasRTA() ) {
                xml.append(" RTA=\"" + dateToString( m_RTA) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasLoCode() ) {
                xml.append(" LoCode=\"" + encode (m_loCode) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_namePresent) {
            xml.append(" Name=\"" + encode (m_name) + endAttr);
        } else { // required attribute not present
            m_lastError = "Name not set";
            m_store  = QString::null;
            return m_store;
        }
        xml.append(">\n");
        // add optional data if available
        if ( hasPos() ) {
            dataMember = m_pos.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Pos:" + m_pos.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</Waypoint>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Waypoint::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Waypoint::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Waypoint\n";
    // check for presence of optional attribute
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + dateToString( m_ATA) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + dateToString( m_ETA) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasRTA() ) {
        str.append( lead + "    RTA = " + dateToString( m_RTA) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasLoCode() ) {
        str.append( lead + "    LoCode = " + m_loCode + endAttr);
    }
    str.append( lead + "    Name = " + m_name + endAttr);
    // add all optional data if present
    if ( hasPos() ) {
        str.append( m_pos.toString(lead + "    ") );
    }
    return str;
}

const QString& Waypoint::lastError() const {
    return m_lastError;
}

const bool& Waypoint::changed() const {
    return m_changed;
}

const QString& Waypoint::store() const {
    return m_store;
}


} //end ns
