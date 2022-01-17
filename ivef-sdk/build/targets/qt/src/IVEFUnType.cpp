#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFUnType.h"

namespace ivef {

// Constructor
UnType::UnType()
 :  QObject(),
    m_codeA(),
    m_codeAPresent( false ),
    m_codeB(),
    m_codeBPresent( false ),
    m_mode( 0 ),
    m_modePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
UnType::UnType(XmlStreamReader& xml)
 :  QObject(),
    m_codeA(),
    m_codeAPresent( false ),
    m_codeB(),
    m_codeBPresent( false ),
    m_mode( 0 ),
    m_modePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "CodeA" ) )
    {
        if ( !setCodeA( attr.value( "CodeA" ).toString() ) )
            xml.validationError( "error set CodeA = " + attr.value( "CodeA" ).toString() );
    }
    if ( attr.hasAttribute( "CodeB" ) )
    {
        if ( !setCodeB( attr.value( "CodeB" ).toString() ) )
            xml.validationError( "error set CodeB = " + attr.value( "CodeB" ).toString() );
    }
    if ( attr.hasAttribute( "Mode" ) )
    {
        if ( !setMode( attr.value( "Mode" ).toString().toInt() ) )
            xml.validationError( "error set Mode = " + attr.value( "Mode" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "UnType" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
UnType::UnType(const UnType &val)
 :  QObject(),
    m_codeA( val.m_codeA ),
    m_codeAPresent( val.m_codeAPresent ),
    m_codeB( val.m_codeB ),
    m_codeBPresent( val.m_codeBPresent ),
    m_mode( val.m_mode ),
    m_modePresent( val.m_modePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool UnType::operator==(const UnType &val) {

    if (!(m_codeAPresent == val.m_codeAPresent)) return false;
    if (!(m_codeA == val.m_codeA)) return false;
    if (!(m_codeBPresent == val.m_codeBPresent)) return false;
    if (!(m_codeB == val.m_codeB)) return false;
    if (!(m_modePresent == val.m_modePresent)) return false;
    if (!(m_mode == val.m_mode)) return false;
    return true;
}

// assignement
UnType & UnType::operator=(const UnType &val) {

    m_codeAPresent = val.m_codeAPresent;
    m_codeA = val.m_codeA;
    m_codeBPresent = val.m_codeBPresent;
    m_codeB = val.m_codeB;
    m_modePresent = val.m_modePresent;
    m_mode = val.m_mode;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for UnType
bool UnType::setCodeA(QString val) {

    m_codeAPresent = true;
    m_codeA = val;
    m_changed = true;
    return true;
}

// getter for UnType
QString UnType::getCodeA() const {

    return m_codeA;
}

// setter for UnType
bool UnType::setCodeB(QString val) {

    m_codeBPresent = true;
    m_codeB = val;
    m_changed = true;
    return true;
}

// getter for UnType
QString UnType::getCodeB() const {

    return m_codeB;
}

// check if optional element UnType has been set
bool UnType::hasCodeB() const {

    return m_codeBPresent;
}

// setter for UnType
bool UnType::setMode(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return false;
    m_modePresent = true;
    m_mode = val;
    m_changed = true;
    return true;
}

// getter for UnType
int UnType::getMode() const {

    return m_mode;
}

// Get XML Representation
const QString& UnType::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<UnType";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_codeAPresent) {
            xml.append(" CodeA=\"" + encode (m_codeA) + endAttr);
        } else { // required attribute not present
            m_lastError = "CodeA not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasCodeB() ) {
                xml.append(" CodeB=\"" + encode (m_codeB) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_modePresent) {
            xml.append(" Mode=\"" + QString::number( m_mode ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Mode not set";
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
QString UnType::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString UnType::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "UnType\n";
    str.append( lead + "    CodeA = " + m_codeA + endAttr);
    // check for presence of optional attribute
    if ( hasCodeB() ) {
        str.append( lead + "    CodeB = " + m_codeB + endAttr);
    }
    str.append( lead + "    Mode = " + QString::number( m_mode ) + endAttr);
    return str;
}

const QString& UnType::lastError() const {
    return m_lastError;
}

const bool& UnType::changed() const {
    return m_changed;
}

const QString& UnType::store() const {
    return m_store;
}


} //end ns
