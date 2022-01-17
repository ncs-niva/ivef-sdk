#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFTaggedItem.h"

namespace ivef {

// Constructor
TaggedItem::TaggedItem()
 :  QObject(),
    m_key(),
    m_keyPresent( false ),
    m_value(),
    m_valuePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
TaggedItem::TaggedItem(XmlStreamReader& xml)
 :  QObject(),
    m_key(),
    m_keyPresent( false ),
    m_value(),
    m_valuePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Key" ) )
    {
        if ( !setKey( attr.value( "Key" ).toString() ) )
            xml.validationError( "error set Key = " + attr.value( "Key" ).toString() );
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
            if (  xml.name() == "TaggedItem" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
TaggedItem::TaggedItem(const TaggedItem &val)
 :  QObject(),
    m_key( val.m_key ),
    m_keyPresent( val.m_keyPresent ),
    m_value( val.m_value ),
    m_valuePresent( val.m_valuePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool TaggedItem::operator==(const TaggedItem &val) {

    if (!(m_keyPresent == val.m_keyPresent)) return false;
    if (!(m_key == val.m_key)) return false;
    if (!(m_valuePresent == val.m_valuePresent)) return false;
    if (!(m_value == val.m_value)) return false;
    return true;
}

// assignement
TaggedItem & TaggedItem::operator=(const TaggedItem &val) {

    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for TaggedItem
bool TaggedItem::setKey(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_keyPresent = true;
    m_key = val;
    m_changed = true;
    return true;
}

// getter for TaggedItem
QString TaggedItem::getKey() const {

    return m_key;
}

// setter for TaggedItem
bool TaggedItem::setValue(QString val) {

    m_valuePresent = true;
    m_value = val;
    m_changed = true;
    return true;
}

// getter for TaggedItem
QString TaggedItem::getValue() const {

    return m_value;
}

// Get XML Representation
const QString& TaggedItem::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<TaggedItem";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_keyPresent) {
            xml.append(" Key=\"" + encode (m_key) + endAttr);
        } else { // required attribute not present
            m_lastError = "Key not set";
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
QString TaggedItem::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString TaggedItem::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "TaggedItem\n";
    str.append( lead + "    Key = " + m_key + endAttr);
    str.append( lead + "    Value = " + m_value + endAttr);
    return str;
}

const QString& TaggedItem::lastError() const {
    return m_lastError;
}

const bool& TaggedItem::changed() const {
    return m_changed;
}

const QString& TaggedItem::store() const {
    return m_store;
}


} //end ns
