#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFBody.h"

namespace ivef {

// Constructor
Body::Body()
 :  QObject(),
    m_loginRequestPresent( false ),
    m_loginResponsePresent( false ),
    m_logoutPresent( false ),
    m_objectDatasPresent( false ),
    m_pingPresent( false ),
    m_pongPresent( false ),
    m_serverStatusPresent( false ),
    m_serviceRequestPresent( false ),
    m_serviceRequestResponsePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Body::Body(XmlStreamReader& xml)
 :  QObject(),
    m_loginRequestPresent( false ),
    m_loginResponsePresent( false ),
    m_logoutPresent( false ),
    m_objectDatasPresent( false ),
    m_pingPresent( false ),
    m_pongPresent( false ),
    m_serverStatusPresent( false ),
    m_serviceRequestPresent( false ),
    m_serviceRequestResponsePresent( false ),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Body" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "LoginRequest" )
            {
                LoginRequest val( xml );
                if ( xml.name() != "LoginRequest" )
                    xml.raiseError( "tag mismatch LoginRequest" );
                else if ( !setLoginRequest( val ) )
                    xml.validationError( "error set LoginRequest"  );
            }
            else if ( xml.name() == "LoginResponse" )
            {
                LoginResponse val( xml );
                if ( xml.name() != "LoginResponse" )
                    xml.raiseError( "tag mismatch LoginResponse" );
                else if ( !setLoginResponse( val ) )
                    xml.validationError( "error set LoginResponse"  );
            }
            else if ( xml.name() == "Logout" )
            {
                Logout val( xml );
                if ( xml.name() != "Logout" )
                    xml.raiseError( "tag mismatch Logout" );
                else if ( !setLogout( val ) )
                    xml.validationError( "error set Logout"  );
            }
            else if ( xml.name() == "ObjectDatas" )
            {
                ObjectDatas val( xml );
                if ( xml.name() != "ObjectDatas" )
                    xml.raiseError( "tag mismatch ObjectDatas" );
                else if ( !setObjectDatas( val ) )
                    xml.validationError( "error set ObjectDatas"  );
            }
            else if ( xml.name() == "Ping" )
            {
                Ping val( xml );
                if ( xml.name() != "Ping" )
                    xml.raiseError( "tag mismatch Ping" );
                else if ( !setPing( val ) )
                    xml.validationError( "error set Ping"  );
            }
            else if ( xml.name() == "Pong" )
            {
                Pong val( xml );
                if ( xml.name() != "Pong" )
                    xml.raiseError( "tag mismatch Pong" );
                else if ( !setPong( val ) )
                    xml.validationError( "error set Pong"  );
            }
            else if ( xml.name() == "ServerStatus" )
            {
                ServerStatus val( xml );
                if ( xml.name() != "ServerStatus" )
                    xml.raiseError( "tag mismatch ServerStatus" );
                else if ( !setServerStatus( val ) )
                    xml.validationError( "error set ServerStatus"  );
            }
            else if ( xml.name() == "ServiceRequest" )
            {
                ServiceRequest val( xml );
                if ( xml.name() != "ServiceRequest" )
                    xml.raiseError( "tag mismatch ServiceRequest" );
                else if ( !setServiceRequest( val ) )
                    xml.validationError( "error set ServiceRequest"  );
            }
            else if ( xml.name() == "ServiceRequestResponse" )
            {
                ServiceRequestResponse val( xml );
                if ( xml.name() != "ServiceRequestResponse" )
                    xml.raiseError( "tag mismatch ServiceRequestResponse" );
                else if ( !setServiceRequestResponse( val ) )
                    xml.validationError( "error set ServiceRequestResponse"  );
            }
            else
            {
                xml.validationError( "unexpected element " + xml.name().toString() );
            }
            break;
        default:
            break;
        }
    }
}

// copy constructor
Body::Body(const Body &val)
 :  QObject(),
    m_loginRequest( val.m_loginRequest ),
    m_loginRequestPresent( val.m_loginRequestPresent ),
    m_loginResponse( val.m_loginResponse ),
    m_loginResponsePresent( val.m_loginResponsePresent ),
    m_logout( val.m_logout ),
    m_logoutPresent( val.m_logoutPresent ),
    m_objectDatas( val.m_objectDatas ),
    m_objectDatasPresent( val.m_objectDatasPresent ),
    m_ping( val.m_ping ),
    m_pingPresent( val.m_pingPresent ),
    m_pong( val.m_pong ),
    m_pongPresent( val.m_pongPresent ),
    m_serverStatus( val.m_serverStatus ),
    m_serverStatusPresent( val.m_serverStatusPresent ),
    m_serviceRequest( val.m_serviceRequest ),
    m_serviceRequestPresent( val.m_serviceRequestPresent ),
    m_serviceRequestResponse( val.m_serviceRequestResponse ),
    m_serviceRequestResponsePresent( val.m_serviceRequestResponsePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Body::operator==(const Body &val) {

    if (!(m_loginRequestPresent == val.m_loginRequestPresent)) return false;
    if (!(m_loginRequest == val.m_loginRequest)) return false;
    if (!(m_loginResponsePresent == val.m_loginResponsePresent)) return false;
    if (!(m_loginResponse == val.m_loginResponse)) return false;
    if (!(m_logoutPresent == val.m_logoutPresent)) return false;
    if (!(m_logout == val.m_logout)) return false;
    if (!(m_objectDatasPresent == val.m_objectDatasPresent)) return false;
    if (!(m_objectDatas == val.m_objectDatas)) return false;
    if (!(m_pingPresent == val.m_pingPresent)) return false;
    if (!(m_ping == val.m_ping)) return false;
    if (!(m_pongPresent == val.m_pongPresent)) return false;
    if (!(m_pong == val.m_pong)) return false;
    if (!(m_serverStatusPresent == val.m_serverStatusPresent)) return false;
    if (!(m_serverStatus == val.m_serverStatus)) return false;
    if (!(m_serviceRequestPresent == val.m_serviceRequestPresent)) return false;
    if (!(m_serviceRequest == val.m_serviceRequest)) return false;
    if (!(m_serviceRequestResponsePresent == val.m_serviceRequestResponsePresent)) return false;
    if (!(m_serviceRequestResponse == val.m_serviceRequestResponse)) return false;
    return true;
}

// assignement
Body & Body::operator=(const Body &val) {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDatasPresent = val.m_objectDatasPresent;
    m_objectDatas = val.m_objectDatas;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    m_serviceRequestResponsePresent = val.m_serviceRequestResponsePresent;
    m_serviceRequestResponse = val.m_serviceRequestResponse;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Body
bool Body::setLoginRequest(const LoginRequest& val) {

    m_loginRequestPresent = true;
    m_loginRequest = val;
    m_changed = true;
    return true;
}

// getter for Body
const LoginRequest& Body::getLoginRequest() const {

    return m_loginRequest;
}

// check if optional element Body has been set
bool Body::hasLoginRequest() const {

    return m_loginRequestPresent;
}

// setter for Body
bool Body::setLoginResponse(const LoginResponse& val) {

    m_loginResponsePresent = true;
    m_loginResponse = val;
    m_changed = true;
    return true;
}

// getter for Body
const LoginResponse& Body::getLoginResponse() const {

    return m_loginResponse;
}

// check if optional element Body has been set
bool Body::hasLoginResponse() const {

    return m_loginResponsePresent;
}

// setter for Body
bool Body::setLogout(const Logout& val) {

    m_logoutPresent = true;
    m_logout = val;
    m_changed = true;
    return true;
}

// getter for Body
const Logout& Body::getLogout() const {

    return m_logout;
}

// check if optional element Body has been set
bool Body::hasLogout() const {

    return m_logoutPresent;
}

// setter for Body
bool Body::setObjectDatas(const ObjectDatas& val) {

    m_objectDatasPresent = true;
    m_objectDatas = val;
    m_changed = true;
    return true;
}

// getter for Body
const ObjectDatas& Body::getObjectDatas() const {

    return m_objectDatas;
}

// check if optional element Body has been set
bool Body::hasObjectDatas() const {

    return m_objectDatasPresent;
}

// setter for Body
bool Body::setPing(const Ping& val) {

    m_pingPresent = true;
    m_ping = val;
    m_changed = true;
    return true;
}

// getter for Body
const Ping& Body::getPing() const {

    return m_ping;
}

// check if optional element Body has been set
bool Body::hasPing() const {

    return m_pingPresent;
}

// setter for Body
bool Body::setPong(const Pong& val) {

    m_pongPresent = true;
    m_pong = val;
    m_changed = true;
    return true;
}

// getter for Body
const Pong& Body::getPong() const {

    return m_pong;
}

// check if optional element Body has been set
bool Body::hasPong() const {

    return m_pongPresent;
}

// setter for Body
bool Body::setServerStatus(const ServerStatus& val) {

    m_serverStatusPresent = true;
    m_serverStatus = val;
    m_changed = true;
    return true;
}

// getter for Body
const ServerStatus& Body::getServerStatus() const {

    return m_serverStatus;
}

// check if optional element Body has been set
bool Body::hasServerStatus() const {

    return m_serverStatusPresent;
}

// setter for Body
bool Body::setServiceRequest(const ServiceRequest& val) {

    m_serviceRequestPresent = true;
    m_serviceRequest = val;
    m_changed = true;
    return true;
}

// getter for Body
const ServiceRequest& Body::getServiceRequest() const {

    return m_serviceRequest;
}

// check if optional element Body has been set
bool Body::hasServiceRequest() const {

    return m_serviceRequestPresent;
}

// setter for Body
bool Body::setServiceRequestResponse(const ServiceRequestResponse& val) {

    m_serviceRequestResponsePresent = true;
    m_serviceRequestResponse = val;
    m_changed = true;
    return true;
}

// getter for Body
const ServiceRequestResponse& Body::getServiceRequestResponse() const {

    return m_serviceRequestResponse;
}

// check if optional element Body has been set
bool Body::hasServiceRequestResponse() const {

    return m_serviceRequestResponsePresent;
}

// Get XML Representation
const QString& Body::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Body";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append(">\n");
        // add optional data if available
        if ( hasLoginRequest() ) {
            dataMember = m_loginRequest.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "LoginRequest:" + m_loginRequest.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasLoginResponse() ) {
            dataMember = m_loginResponse.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "LoginResponse:" + m_loginResponse.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasLogout() ) {
            dataMember = m_logout.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Logout:" + m_logout.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasObjectDatas() ) {
            dataMember = m_objectDatas.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "ObjectDatas:" + m_objectDatas.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasPing() ) {
            dataMember = m_ping.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Ping:" + m_ping.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasPong() ) {
            dataMember = m_pong.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Pong:" + m_pong.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasServerStatus() ) {
            dataMember = m_serverStatus.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "ServerStatus:" + m_serverStatus.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasServiceRequest() ) {
            dataMember = m_serviceRequest.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "ServiceRequest:" + m_serviceRequest.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasServiceRequestResponse() ) {
            dataMember = m_serviceRequestResponse.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "ServiceRequestResponse:" + m_serviceRequestResponse.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</Body>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Body::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Body::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Body\n";
    // add all optional data if present
    if ( hasLoginRequest() ) {
        str.append( m_loginRequest.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasLoginResponse() ) {
        str.append( m_loginResponse.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasLogout() ) {
        str.append( m_logout.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasObjectDatas() ) {
        str.append( m_objectDatas.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasPing() ) {
        str.append( m_ping.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasPong() ) {
        str.append( m_pong.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServerStatus() ) {
        str.append( m_serverStatus.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServiceRequest() ) {
        str.append( m_serviceRequest.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServiceRequestResponse() ) {
        str.append( m_serviceRequestResponse.toString(lead + "    ") );
    }
    return str;
}

const QString& Body::lastError() const {
    return m_lastError;
}

const bool& Body::changed() const {
    return m_changed;
}

const QString& Body::store() const {
    return m_store;
}


} //end ns
