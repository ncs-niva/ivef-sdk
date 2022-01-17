#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFLoginRequest.h"

namespace ivef {

// Constructor
LoginRequest::LoginRequest()
 :  QObject(),
    m_encryption( 0 ),
    m_encryptionPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_password(),
    m_passwordPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
LoginRequest::LoginRequest(XmlStreamReader& xml)
 :  QObject(),
    m_encryption( 0 ),
    m_encryptionPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_password(),
    m_passwordPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Encryption" ) )
    {
        if ( !setEncryption( attr.value( "Encryption" ).toString().toInt() ) )
            xml.validationError( "error set Encryption = " + attr.value( "Encryption" ).toString() );
    }
    if ( attr.hasAttribute( "Name" ) )
    {
        if ( !setName( attr.value( "Name" ).toString() ) )
            xml.validationError( "error set Name = " + attr.value( "Name" ).toString() );
    }
    if ( attr.hasAttribute( "Password" ) )
    {
        if ( !setPassword( attr.value( "Password" ).toString() ) )
            xml.validationError( "error set Password = " + attr.value( "Password" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "LoginRequest" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
LoginRequest::LoginRequest(const LoginRequest &val)
 :  QObject(),
    m_encryption( val.m_encryption ),
    m_encryptionPresent( val.m_encryptionPresent ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_password( val.m_password ),
    m_passwordPresent( val.m_passwordPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool LoginRequest::operator==(const LoginRequest &val) {

    if (!(m_encryptionPresent == val.m_encryptionPresent)) return false;
    if (!(m_encryption == val.m_encryption)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    if (!(m_passwordPresent == val.m_passwordPresent)) return false;
    if (!(m_password == val.m_password)) return false;
    return true;
}

// assignement
LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_encryptionPresent = val.m_encryptionPresent;
    m_encryption = val.m_encryption;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_passwordPresent = val.m_passwordPresent;
    m_password = val.m_password;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for LoginRequest
bool LoginRequest::setEncryption(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_encryptionPresent = true;
    m_encryption = val;
    m_changed = true;
    return true;
}

// getter for LoginRequest
int LoginRequest::getEncryption() const {

    return m_encryption;
}

// setter for LoginRequest
bool LoginRequest::setName(QString val) {

    // check if the new value is within max length
    if (val.length() > 256)
        return false;
    m_namePresent = true;
    m_name = val;
    m_changed = true;
    return true;
}

// getter for LoginRequest
QString LoginRequest::getName() const {

    return m_name;
}

// setter for LoginRequest
bool LoginRequest::setPassword(QString val) {

    // check if the new value is within max length
    if (val.length() > 256)
        return false;
    m_passwordPresent = true;
    m_password = val;
    m_changed = true;
    return true;
}

// getter for LoginRequest
QString LoginRequest::getPassword() const {

    return m_password;
}

// Get XML Representation
const QString& LoginRequest::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<LoginRequest";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_encryptionPresent) {
            xml.append(" Encryption=\"" + QString::number( m_encryption ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Encryption not set";
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
            // check for presence of required  attribute
        if ( m_passwordPresent) {
            xml.append(" Password=\"" + encode (m_password) + endAttr);
        } else { // required attribute not present
            m_lastError = "Password not set";
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
QString LoginRequest::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString LoginRequest::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "LoginRequest\n";
    str.append( lead + "    Encryption = " + QString::number( m_encryption ) + endAttr);
    str.append( lead + "    Name = " + m_name + endAttr);
    str.append( lead + "    Password = " + m_password + endAttr);
    return str;
}

const QString& LoginRequest::lastError() const {
    return m_lastError;
}

const bool& LoginRequest::changed() const {
    return m_changed;
}

const QString& LoginRequest::store() const {
    return m_store;
}


} //end ns
