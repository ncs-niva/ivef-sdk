#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFHeader.h"

namespace ivef {

// Constructor
Header::Header()
 :  QObject(),
    m_msgRefId(),
    m_msgRefIdPresent( false ),
    m_version( "0.2.5" ), // initialize fixed value
    m_versionPresent( true ),
    m_changed(true)
{
}

// Constructor for parser function
Header::Header(XmlStreamReader& xml)
 :  QObject(),
    m_msgRefId(),
    m_msgRefIdPresent( false ),
    m_version( "0.2.5" ), // initialize fixed value
    m_versionPresent( true ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "MsgRefId" ) )
    {
        if ( !setMsgRefId( attr.value( "MsgRefId" ).toString() ) )
            xml.validationError( "error set MsgRefId = " + attr.value( "MsgRefId" ).toString() );
    }
    if ( attr.hasAttribute( "Version" ) )
    {
        if ( !setVersion( attr.value( "Version" ).toString() ) )
            xml.validationError( "error set Version = " + attr.value( "Version" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Header" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Header::Header(const Header &val)
 :  QObject(),
    m_msgRefId( val.m_msgRefId ),
    m_msgRefIdPresent( val.m_msgRefIdPresent ),
    m_version( val.m_version ),
    m_versionPresent( val.m_versionPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Header::operator==(const Header &val) {

    if (!(m_msgRefIdPresent == val.m_msgRefIdPresent)) return false;
    if (!(m_msgRefId == val.m_msgRefId)) return false;
    if (!(m_versionPresent == val.m_versionPresent)) return false;
    if (!(m_version == val.m_version)) return false;
    return true;
}

// assignement
Header & Header::operator=(const Header &val) {

    m_msgRefIdPresent = val.m_msgRefIdPresent;
    m_msgRefId = val.m_msgRefId;
    m_versionPresent = val.m_versionPresent;
    m_version = val.m_version;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Header
bool Header::setMsgRefId(QString val) {

    // check if the new value is within min length
    if (val.length() < 36)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_msgRefIdPresent = true;
    m_msgRefId = val;
    m_changed = true;
    return true;
}

// getter for Header
QString Header::getMsgRefId() const {

    return m_msgRefId;
}

// setter for Header
bool Header::setVersion(QString val) {

    m_versionPresent = true;
    m_version = val;
    m_changed = true;
    return true;
}

// getter for Header
QString Header::getVersion() const {

    return m_version;
}

// Get XML Representation
const QString& Header::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Header";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_msgRefIdPresent) {
            xml.append(" MsgRefId=\"" + encode (m_msgRefId) + endAttr);
        } else { // required attribute not present
            m_lastError = "MsgRefId not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_versionPresent) {
            xml.append(" Version=\"" + m_version + endAttr);
        } else { // required attribute not present
            m_lastError = "Version not set";
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
QString Header::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Header::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Header\n";
    str.append( lead + "    MsgRefId = " + m_msgRefId + endAttr);
    str.append( lead + "    Version = " + m_version + endAttr);
    return str;
}

const QString& Header::lastError() const {
    return m_lastError;
}

const bool& Header::changed() const {
    return m_changed;
}

const QString& Header::store() const {
    return m_store;
}


} //end ns
