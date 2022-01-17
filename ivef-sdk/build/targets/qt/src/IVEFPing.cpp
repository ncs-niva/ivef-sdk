#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFPing.h"

namespace ivef {

// Constructor
Ping::Ping()
 :  QObject(),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Ping::Ping(XmlStreamReader& xml)
 :  QObject(),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "TimeStamp" ) )
    {
        if ( !setTimeStamp( QDateTime::fromString(attr.value( "TimeStamp" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set TimeStamp = " + attr.value( "TimeStamp" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Ping" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Ping::Ping(const Ping &val)
 :  QObject(),
    m_timeStamp( val.m_timeStamp ),
    m_timeStampPresent( val.m_timeStampPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Ping::operator==(const Ping &val) {

    if (!(m_timeStampPresent == val.m_timeStampPresent)) return false;
    if (!(m_timeStamp == val.m_timeStamp)) return false;
    return true;
}

// assignement
Ping & Ping::operator=(const Ping &val) {

    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Ping
bool Ping::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
    m_changed = true;
    return true;
}

// getter for Ping
QDateTime Ping::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
const QString& Ping::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Ping";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_timeStampPresent) {
            xml.append(" TimeStamp=\"" + dateToString( m_timeStamp) + endAttr);
        } else { // required attribute not present
            m_lastError = "TimeStamp not set";
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
QString Ping::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Ping::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Ping\n";
    str.append( lead + "    TimeStamp = " + dateToString( m_timeStamp) + endAttr);
    return str;
}

const QString& Ping::lastError() const {
    return m_lastError;
}

const bool& Ping::changed() const {
    return m_changed;
}

const QString& Ping::store() const {
    return m_store;
}


} //end ns
