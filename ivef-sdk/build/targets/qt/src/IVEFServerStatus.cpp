#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFServerStatus.h"

namespace ivef {

// Constructor
ServerStatus::ServerStatus()
 :  QObject(),
    m_contactIdentity(),
    m_contactIdentityPresent( false ),
    m_details(),
    m_detailsPresent( false ),
    m_status( false ),
    m_statusPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
ServerStatus::ServerStatus(XmlStreamReader& xml)
 :  QObject(),
    m_contactIdentity(),
    m_contactIdentityPresent( false ),
    m_details(),
    m_detailsPresent( false ),
    m_status( false ),
    m_statusPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "ContactIdentity" ) )
    {
        if ( !setContactIdentity( attr.value( "ContactIdentity" ).toString() ) )
            xml.validationError( "error set ContactIdentity = " + attr.value( "ContactIdentity" ).toString() );
    }
    if ( attr.hasAttribute( "Details" ) )
    {
        if ( !setDetails( attr.value( "Details" ).toString() ) )
            xml.validationError( "error set Details = " + attr.value( "Details" ).toString() );
    }
    if ( attr.hasAttribute( "Status" ) )
    {
        // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
        QString value = attr.value( "Status" ).toString().toUpper();
        if ( !setStatus( value == "YES" ||
                             value == "TRUE" ||
                             value == "1") )
            xml.validationError( "error set Status = " + attr.value( "Status" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "ServerStatus" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
ServerStatus::ServerStatus(const ServerStatus &val)
 :  QObject(),
    m_contactIdentity( val.m_contactIdentity ),
    m_contactIdentityPresent( val.m_contactIdentityPresent ),
    m_details( val.m_details ),
    m_detailsPresent( val.m_detailsPresent ),
    m_status( val.m_status ),
    m_statusPresent( val.m_statusPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool ServerStatus::operator==(const ServerStatus &val) {

    if (!(m_contactIdentityPresent == val.m_contactIdentityPresent)) return false;
    if (!(m_contactIdentity == val.m_contactIdentity)) return false;
    if (!(m_detailsPresent == val.m_detailsPresent)) return false;
    if (!(m_details == val.m_details)) return false;
    if (!(m_statusPresent == val.m_statusPresent)) return false;
    if (!(m_status == val.m_status)) return false;
    return true;
}

// assignement
ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_statusPresent = val.m_statusPresent;
    m_status = val.m_status;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for ServerStatus
bool ServerStatus::setContactIdentity(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 254)
        return false;
    m_contactIdentityPresent = true;
    m_contactIdentity = val;
    m_changed = true;
    return true;
}

// getter for ServerStatus
QString ServerStatus::getContactIdentity() const {

    return m_contactIdentity;
}

// check if optional element ServerStatus has been set
bool ServerStatus::hasContactIdentity() const {

    return m_contactIdentityPresent;
}

// setter for ServerStatus
bool ServerStatus::setDetails(QString val) {

    // check if the new value is within max length
    if (val.length() > 50)
        return false;
    m_detailsPresent = true;
    m_details = val;
    m_changed = true;
    return true;
}

// getter for ServerStatus
QString ServerStatus::getDetails() const {

    return m_details;
}

// check if optional element ServerStatus has been set
bool ServerStatus::hasDetails() const {

    return m_detailsPresent;
}

// setter for ServerStatus
bool ServerStatus::setStatus(bool val) {

    m_statusPresent = true;
    m_status = val;
    m_changed = true;
    return true;
}

// getter for ServerStatus
bool ServerStatus::getStatus() const {

    return m_status;
}

// Get XML Representation
const QString& ServerStatus::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<ServerStatus";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasContactIdentity() ) {
                xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasDetails() ) {
                xml.append(" Details=\"" + encode (m_details) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_statusPresent) {
            xml.append(" Status=\"" + QString( m_status ? "true" : "false" ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Status not set";
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
QString ServerStatus::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString ServerStatus::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "ServerStatus\n";
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + endAttr);
    }
    // check for presence of optional attribute
    if ( hasDetails() ) {
        str.append( lead + "    Details = " + m_details + endAttr);
    }
    str.append( lead + "    Status = " + QString( m_status ? "true" : "false" ) + endAttr);
    return str;
}

const QString& ServerStatus::lastError() const {
    return m_lastError;
}

const bool& ServerStatus::changed() const {
    return m_changed;
}

const QString& ServerStatus::store() const {
    return m_store;
}


} //end ns
