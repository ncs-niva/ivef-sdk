#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFOtherId.h"

namespace ivef {

// Constructor
OtherId::OtherId()
 :  QObject(),
    m_id(),
    m_idPresent( false ),
    m_value(),
    m_valuePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
OtherId::OtherId(XmlStreamReader& xml)
 :  QObject(),
    m_id(),
    m_idPresent( false ),
    m_value(),
    m_valuePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Id" ) )
    {
        if ( !setId( attr.value( "Id" ).toString() ) )
            xml.validationError( "error set Id = " + attr.value( "Id" ).toString() );
    }
    if ( attr.hasAttribute( "Value" ) )
    {
        if ( !setValue( attr.value( "Value" ).toString() ) )
            xml.validationError( "error set Value = " + attr.value( "Value" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "OtherId" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
OtherId::OtherId(const OtherId &val)
 :  QObject(),
    m_id( val.m_id ),
    m_idPresent( val.m_idPresent ),
    m_value( val.m_value ),
    m_valuePresent( val.m_valuePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool OtherId::operator==(const OtherId &val) {

    if (!(m_idPresent == val.m_idPresent)) return false;
    if (!(m_id == val.m_id)) return false;
    if (!(m_valuePresent == val.m_valuePresent)) return false;
    if (!(m_value == val.m_value)) return false;
    return true;
}

// assignement
OtherId & OtherId::operator=(const OtherId &val) {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for OtherId
bool OtherId::setId(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_idPresent = true;
    m_id = val;
    m_changed = true;
    return true;
}

// getter for OtherId
QString OtherId::getId() const {

    return m_id;
}

// setter for OtherId
bool OtherId::setValue(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_valuePresent = true;
    m_value = val;
    m_changed = true;
    return true;
}

// getter for OtherId
QString OtherId::getValue() const {

    return m_value;
}

// Get XML Representation
const QString& OtherId::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<OtherId";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_idPresent) {
            xml.append(" Id=\"" + encode (m_id) + endAttr);
        } else { // required attribute not present
            m_lastError = "Id not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_valuePresent) {
            xml.append(" Value=\"" + encode (m_value) + endAttr);
        } else { // required attribute not present
            m_lastError = "Value not set";
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
QString OtherId::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString OtherId::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "OtherId\n";
    str.append( lead + "    Id = " + m_id + endAttr);
    str.append( lead + "    Value = " + m_value + endAttr);
    return str;
}

const QString& OtherId::lastError() const {
    return m_lastError;
}

const bool& OtherId::changed() const {
    return m_changed;
}

const QString& OtherId::store() const {
    return m_store;
}


} //end ns
