#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFNavStatus.h"

namespace ivef {

// Constructor
NavStatus::NavStatus()
 :  QObject(),
    m_value( 0 ),
    m_valuePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
NavStatus::NavStatus(XmlStreamReader& xml)
 :  QObject(),
    m_value( 0 ),
    m_valuePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Value" ) )
    {
        if ( !setValue( attr.value( "Value" ).toString().toInt() ) )
            xml.validationError( "error set Value = " + attr.value( "Value" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "NavStatus" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
NavStatus::NavStatus(const NavStatus &val)
 :  QObject(),
    m_value( val.m_value ),
    m_valuePresent( val.m_valuePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool NavStatus::operator==(const NavStatus &val) {

    if (!(m_valuePresent == val.m_valuePresent)) return false;
    if (!(m_value == val.m_value)) return false;
    return true;
}

// assignement
NavStatus & NavStatus::operator=(const NavStatus &val) {

    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for NavStatus
bool NavStatus::setValue(int val) {

    // check if the new value is within min inclusive
    if (val < 0)
        return false;
    // check if the new value is within max inclusive
    if (val > 15)
        return false;
    m_valuePresent = true;
    m_value = val;
    m_changed = true;
    return true;
}

// getter for NavStatus
int NavStatus::getValue() const {

    return m_value;
}

// Get XML Representation
const QString& NavStatus::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<NavStatus";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_valuePresent) {
            xml.append(" Value=\"" + QString::number( m_value ) + endAttr);
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
QString NavStatus::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString NavStatus::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "NavStatus\n";
    str.append( lead + "    Value = " + QString::number( m_value ) + endAttr);
    return str;
}

const QString& NavStatus::lastError() const {
    return m_lastError;
}

const bool& NavStatus::changed() const {
    return m_changed;
}

const QString& NavStatus::store() const {
    return m_store;
}


} //end ns
