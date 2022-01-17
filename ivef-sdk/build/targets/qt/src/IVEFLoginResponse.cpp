#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFLoginResponse.h"

namespace ivef {

// Constructor
LoginResponse::LoginResponse()
 :  QObject(),
    m_reason(),
    m_reasonPresent( false ),
    m_responseOn(),
    m_responseOnPresent( false ),
    m_result( 0 ),
    m_resultPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
LoginResponse::LoginResponse(XmlStreamReader& xml)
 :  QObject(),
    m_reason(),
    m_reasonPresent( false ),
    m_responseOn(),
    m_responseOnPresent( false ),
    m_result( 0 ),
    m_resultPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Reason" ) )
    {
        if ( !setReason( attr.value( "Reason" ).toString() ) )
            xml.validationError( "error set Reason = " + attr.value( "Reason" ).toString() );
    }
    if ( attr.hasAttribute( "ResponseOn" ) )
    {
        if ( !setResponseOn( attr.value( "ResponseOn" ).toString() ) )
            xml.validationError( "error set ResponseOn = " + attr.value( "ResponseOn" ).toString() );
    }
    if ( attr.hasAttribute( "Result" ) )
    {
        if ( !setResult( attr.value( "Result" ).toString().toInt() ) )
            xml.validationError( "error set Result = " + attr.value( "Result" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "LoginResponse" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
LoginResponse::LoginResponse(const LoginResponse &val)
 :  QObject(),
    m_reason( val.m_reason ),
    m_reasonPresent( val.m_reasonPresent ),
    m_responseOn( val.m_responseOn ),
    m_responseOnPresent( val.m_responseOnPresent ),
    m_result( val.m_result ),
    m_resultPresent( val.m_resultPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool LoginResponse::operator==(const LoginResponse &val) {

    if (!(m_reasonPresent == val.m_reasonPresent)) return false;
    if (!(m_reason == val.m_reason)) return false;
    if (!(m_responseOnPresent == val.m_responseOnPresent)) return false;
    if (!(m_responseOn == val.m_responseOn)) return false;
    if (!(m_resultPresent == val.m_resultPresent)) return false;
    if (!(m_result == val.m_result)) return false;
    return true;
}

// assignement
LoginResponse & LoginResponse::operator=(const LoginResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_resultPresent = val.m_resultPresent;
    m_result = val.m_result;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for LoginResponse
bool LoginResponse::setReason(QString val) {

    // check if the new value is within max length
    if (val.length() > 256)
        return false;
    m_reasonPresent = true;
    m_reason = val;
    m_changed = true;
    return true;
}

// getter for LoginResponse
QString LoginResponse::getReason() const {

    return m_reason;
}

// check if optional element LoginResponse has been set
bool LoginResponse::hasReason() const {

    return m_reasonPresent;
}

// setter for LoginResponse
bool LoginResponse::setResponseOn(QString val) {

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

// getter for LoginResponse
QString LoginResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for LoginResponse
bool LoginResponse::setResult(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_resultPresent = true;
    m_result = val;
    m_changed = true;
    return true;
}

// getter for LoginResponse
int LoginResponse::getResult() const {

    return m_result;
}

// Get XML Representation
const QString& LoginResponse::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<LoginResponse";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasReason() ) {
                xml.append(" Reason=\"" + encode (m_reason) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_responseOnPresent) {
            xml.append(" ResponseOn=\"" + encode (m_responseOn) + endAttr);
        } else { // required attribute not present
            m_lastError = "ResponseOn not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_resultPresent) {
            xml.append(" Result=\"" + QString::number( m_result ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Result not set";
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
QString LoginResponse::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString LoginResponse::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "LoginResponse\n";
    // check for presence of optional attribute
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + endAttr);
    }
    str.append( lead + "    ResponseOn = " + m_responseOn + endAttr);
    str.append( lead + "    Result = " + QString::number( m_result ) + endAttr);
    return str;
}

const QString& LoginResponse::lastError() const {
    return m_lastError;
}

const bool& LoginResponse::changed() const {
    return m_changed;
}

const QString& LoginResponse::store() const {
    return m_store;
}


} //end ns
