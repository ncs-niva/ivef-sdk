#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFPong.h"

namespace ivef {

// Constructor
Pong::Pong()
 :  QObject(),
    m_responseOn(),
    m_responseOnPresent( false ),
    m_sourceId( 0 ),
    m_sourceIdPresent( false ),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Pong::Pong(XmlStreamReader& xml)
 :  QObject(),
    m_responseOn(),
    m_responseOnPresent( false ),
    m_sourceId( 0 ),
    m_sourceIdPresent( false ),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "ResponseOn" ) )
    {
        if ( !setResponseOn( attr.value( "ResponseOn" ).toString() ) )
            xml.validationError( "error set ResponseOn = " + attr.value( "ResponseOn" ).toString() );
    }
    if ( attr.hasAttribute( "SourceId" ) )
    {
        if ( !setSourceId( attr.value( "SourceId" ).toString().toInt() ) )
            xml.validationError( "error set SourceId = " + attr.value( "SourceId" ).toString() );
    }
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
            if (  xml.name() == "Pong" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Pong::Pong(const Pong &val)
 :  QObject(),
    m_responseOn( val.m_responseOn ),
    m_responseOnPresent( val.m_responseOnPresent ),
    m_sourceId( val.m_sourceId ),
    m_sourceIdPresent( val.m_sourceIdPresent ),
    m_timeStamp( val.m_timeStamp ),
    m_timeStampPresent( val.m_timeStampPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Pong::operator==(const Pong &val) {

    if (!(m_responseOnPresent == val.m_responseOnPresent)) return false;
    if (!(m_responseOn == val.m_responseOn)) return false;
    if (!(m_sourceIdPresent == val.m_sourceIdPresent)) return false;
    if (!(m_sourceId == val.m_sourceId)) return false;
    if (!(m_timeStampPresent == val.m_timeStampPresent)) return false;
    if (!(m_timeStamp == val.m_timeStamp)) return false;
    return true;
}

// assignement
Pong & Pong::operator=(const Pong &val) {

    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Pong
bool Pong::setResponseOn(QString val) {

    // check if the new value is within min length
    if (val.length() < 36)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_responseOnPresent = true;
    m_responseOn = val;
    m_changed = true;
    return true;
}

// getter for Pong
QString Pong::getResponseOn() const {

    return m_responseOn;
}

// setter for Pong
bool Pong::setSourceId(int val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
    m_changed = true;
    return true;
}

// getter for Pong
int Pong::getSourceId() const {

    return m_sourceId;
}

// setter for Pong
bool Pong::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
    m_changed = true;
    return true;
}

// getter for Pong
QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
const QString& Pong::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Pong";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_responseOnPresent) {
            xml.append(" ResponseOn=\"" + encode (m_responseOn) + endAttr);
        } else { // required attribute not present
            m_lastError = "ResponseOn not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_sourceIdPresent) {
            xml.append(" SourceId=\"" + QString::number( m_sourceId ) + endAttr);
        } else { // required attribute not present
            m_lastError = "SourceId not set";
            m_store  = QString::null;
            return m_store;
        }
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
QString Pong::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Pong::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Pong\n";
    str.append( lead + "    ResponseOn = " + m_responseOn + endAttr);
    str.append( lead + "    SourceId = " + QString::number( m_sourceId ) + endAttr);
    str.append( lead + "    TimeStamp = " + dateToString( m_timeStamp) + endAttr);
    return str;
}

const QString& Pong::lastError() const {
    return m_lastError;
}

const bool& Pong::changed() const {
    return m_changed;
}

const QString& Pong::store() const {
    return m_store;
}


} //end ns
