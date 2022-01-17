#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFOtherName.h"

namespace ivef {

// Constructor
OtherName::OtherName()
 :  QObject(),
    m_lang(),
    m_langPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
OtherName::OtherName(XmlStreamReader& xml)
 :  QObject(),
    m_lang(),
    m_langPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Lang" ) )
    {
        if ( !setLang( attr.value( "Lang" ).toString() ) )
            xml.validationError( "error set Lang = " + attr.value( "Lang" ).toString() );
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
            if (  xml.name() == "OtherName" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
OtherName::OtherName(const OtherName &val)
 :  QObject(),
    m_lang( val.m_lang ),
    m_langPresent( val.m_langPresent ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool OtherName::operator==(const OtherName &val) {

    if (!(m_langPresent == val.m_langPresent)) return false;
    if (!(m_lang == val.m_lang)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
OtherName & OtherName::operator=(const OtherName &val) {

    m_langPresent = val.m_langPresent;
    m_lang = val.m_lang;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for OtherName
bool OtherName::setLang(QString val) {

    // check if the new value is within min length
    if (val.length() < 2)
        return false;
    // check if the new value is within max length
    if (val.length() > 2)
        return false;
    m_langPresent = true;
    m_lang = val;
    m_changed = true;
    return true;
}

// getter for OtherName
QString OtherName::getLang() const {

    return m_lang;
}

// setter for OtherName
bool OtherName::setName(QString val) {

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

// getter for OtherName
QString OtherName::getName() const {

    return m_name;
}

// Get XML Representation
const QString& OtherName::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<OtherName";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_langPresent) {
            xml.append(" Lang=\"" + encode (m_lang) + endAttr);
        } else { // required attribute not present
            m_lastError = "Lang not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_namePresent) {
            xml.append(" Name=\"" + encode (m_name) + endAttr);
        } else { // required attribute not present
            m_lastError = "Name not set";
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
QString OtherName::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString OtherName::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "OtherName\n";
    str.append( lead + "    Lang = " + m_lang + endAttr);
    str.append( lead + "    Name = " + m_name + endAttr);
    return str;
}

const QString& OtherName::lastError() const {
    return m_lastError;
}

const bool& OtherName::changed() const {
    return m_changed;
}

const QString& OtherName::store() const {
    return m_store;
}


} //end ns
