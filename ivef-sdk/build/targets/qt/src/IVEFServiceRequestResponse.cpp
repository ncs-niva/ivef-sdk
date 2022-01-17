#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFServiceRequestResponse.h"

namespace ivef {

// Constructor
ServiceRequestResponse::ServiceRequestResponse()
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
ServiceRequestResponse::ServiceRequestResponse(XmlStreamReader& xml)
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
            if (  xml.name() == "ServiceRequestResponse" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
ServiceRequestResponse::ServiceRequestResponse(const ServiceRequestResponse &val)
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
bool ServiceRequestResponse::operator==(const ServiceRequestResponse &val) {

    if (!(m_reasonPresent == val.m_reasonPresent)) return false;
    if (!(m_reason == val.m_reason)) return false;
    if (!(m_responseOnPresent == val.m_responseOnPresent)) return false;
    if (!(m_responseOn == val.m_responseOn)) return false;
    if (!(m_resultPresent == val.m_resultPresent)) return false;
    if (!(m_result == val.m_result)) return false;
    return true;
}

// assignement
ServiceRequestResponse & ServiceRequestResponse::operator=(const ServiceRequestResponse &val) {

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

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setReason(QString val) {

    // check if the new value is within max length
    if (val.length() > 256)
        return false;
    m_reasonPresent = true;
    m_reason = val;
    m_changed = true;
    return true;
}

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getReason() const {

    return m_reason;
}

// check if optional element ServiceRequestResponse has been set
bool ServiceRequestResponse::hasReason() const {

    return m_reasonPresent;
}

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setResponseOn(QString val) {

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

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setResult(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_resultPresent = true;
    m_result = val;
    m_changed = true;
    return true;
}

// getter for ServiceRequestResponse
int ServiceRequestResponse::getResult() const {

    return m_result;
}

// Get XML Representation
const QString& ServiceRequestResponse::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<ServiceRequestResponse";
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
QString ServiceRequestResponse::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString ServiceRequestResponse::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "ServiceRequestResponse\n";
    // check for presence of optional attribute
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + endAttr);
    }
    str.append( lead + "    ResponseOn = " + m_responseOn + endAttr);
    str.append( lead + "    Result = " + QString::number( m_result ) + endAttr);
    return str;
}

const QString& ServiceRequestResponse::lastError() const {
    return m_lastError;
}

const bool& ServiceRequestResponse::changed() const {
    return m_changed;
}

const QString& ServiceRequestResponse::store() const {
    return m_store;
}


} //end ns
