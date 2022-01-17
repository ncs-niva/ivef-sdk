#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFMSG_IVEF.h"

namespace ivef {

// Constructor
MSG_IVEF::MSG_IVEF()
 :  QObject(),
    m_headerPresent( false ),
    m_bodyPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
MSG_IVEF::MSG_IVEF(XmlStreamReader& xml)
 :  QObject(),
    m_headerPresent( false ),
    m_bodyPresent( false ),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "MSG_IVEF" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Header" )
            {
                Header val( xml );
                if ( xml.name() != "Header" )
                    xml.raiseError( "tag mismatch Header" );
                else if ( !setHeader( val ) )
                    xml.validationError( "error set Header"  );
            }
            else if ( xml.name() == "Body" )
            {
                Body val( xml );
                if ( xml.name() != "Body" )
                    xml.raiseError( "tag mismatch Body" );
                else if ( !setBody( val ) )
                    xml.validationError( "error set Body"  );
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
MSG_IVEF::MSG_IVEF(const MSG_IVEF &val)
 :  QObject(),
    m_header( val.m_header ),
    m_headerPresent( val.m_headerPresent ),
    m_body( val.m_body ),
    m_bodyPresent( val.m_bodyPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool MSG_IVEF::operator==(const MSG_IVEF &val) {

    if (!(m_headerPresent == val.m_headerPresent)) return false;
    if (!(m_header == val.m_header)) return false;
    if (!(m_bodyPresent == val.m_bodyPresent)) return false;
    if (!(m_body == val.m_body)) return false;
    return true;
}

// assignement
MSG_IVEF & MSG_IVEF::operator=(const MSG_IVEF &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for MSG_IVEF
bool MSG_IVEF::setHeader(const Header& val) {

    m_headerPresent = true;
    m_header = val;
    m_changed = true;
    return true;
}

// getter for MSG_IVEF
const Header& MSG_IVEF::getHeader() const {

    return m_header;
}

// setter for MSG_IVEF
bool MSG_IVEF::setBody(const Body& val) {

    m_bodyPresent = true;
    m_body = val;
    m_changed = true;
    return true;
}

// getter for MSG_IVEF
const Body& MSG_IVEF::getBody() const {

    return m_body;
}

// Get XML Representation
const QString& MSG_IVEF::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<MSG_IVEF";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append(">\n");
        // check for presence of required data member
        if ( m_headerPresent) {
            dataMember = m_header.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Header:" + m_header.lastError();
                m_store  = QString::null;
                return m_store;
            }
        } else {
            m_lastError = "Header not set";
            m_store  = QString::null;
            return m_store;
        }
        // check for presence of required data member
        if ( m_bodyPresent) {
            dataMember = m_body.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Body:" + m_body.lastError();
                m_store  = QString::null;
                return m_store;
            }
        } else {
            m_lastError = "Body not set";
            m_store  = QString::null;
            return m_store;
        }
        xml.append( "</MSG_IVEF>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString MSG_IVEF::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString MSG_IVEF::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "MSG_IVEF\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

const QString& MSG_IVEF::lastError() const {
    return m_lastError;
}

const bool& MSG_IVEF::changed() const {
    return m_changed;
}

const QString& MSG_IVEF::store() const {
    return m_store;
}


} //end ns
