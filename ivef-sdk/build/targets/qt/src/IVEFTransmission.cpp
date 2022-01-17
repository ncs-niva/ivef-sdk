#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFTransmission.h"

namespace ivef {

// Constructor
Transmission::Transmission()
 :  QObject(),
    m_type( 0 ),
    m_typePresent( false ),
    m_period( 0.0 ),
    m_periodPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Transmission::Transmission(XmlStreamReader& xml)
 :  QObject(),
    m_type( 0 ),
    m_typePresent( false ),
    m_period( 0.0 ),
    m_periodPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Type" ) )
    {
        if ( !setType( attr.value( "Type" ).toString().toInt() ) )
            xml.validationError( "error set Type = " + attr.value( "Type" ).toString() );
    }
    if ( attr.hasAttribute( "Period" ) )
    {
        if ( !setPeriod( attr.value( "Period" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Period = " + attr.value( "Period" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Transmission" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Transmission::Transmission(const Transmission &val)
 :  QObject(),
    m_type( val.m_type ),
    m_typePresent( val.m_typePresent ),
    m_period( val.m_period ),
    m_periodPresent( val.m_periodPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Transmission::operator==(const Transmission &val) {

    if (!(m_typePresent == val.m_typePresent)) return false;
    if (!(m_type == val.m_type)) return false;
    if (!(m_periodPresent == val.m_periodPresent)) return false;
    if (!(m_period == val.m_period)) return false;
    return true;
}

// assignement
Transmission & Transmission::operator=(const Transmission &val) {

    m_typePresent = val.m_typePresent;
    m_type = val.m_type;
    m_periodPresent = val.m_periodPresent;
    m_period = val.m_period;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Transmission
bool Transmission::setType(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_typePresent = true;
    m_type = val;
    m_changed = true;
    return true;
}

// getter for Transmission
int Transmission::getType() const {

    return m_type;
}

// setter for Transmission
bool Transmission::setPeriod(float val) {

    m_periodPresent = true;
    m_period = val;
    m_changed = true;
    return true;
}

// getter for Transmission
float Transmission::getPeriod() const {

    return m_period;
}

// check if optional element Transmission has been set
bool Transmission::hasPeriod() const {

    return m_periodPresent;
}

// Get XML Representation
const QString& Transmission::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Transmission";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_typePresent) {
            xml.append(" Type=\"" + QString::number( m_type ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Type not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasPeriod() ) {
                xml.append(" Period=\"" + QString::number( m_period, 'f') + endAttr);
        }
        xml.append("/>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Transmission::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Transmission::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Transmission\n";
    str.append( lead + "    Type = " + QString::number( m_type ) + endAttr);
    // check for presence of optional attribute
    if ( hasPeriod() ) {
        str.append( lead + "    Period = " + QString::number( m_period, 'f') + endAttr);
    }
    return str;
}

const QString& Transmission::lastError() const {
    return m_lastError;
}

const bool& Transmission::changed() const {
    return m_changed;
}

const QString& Transmission::store() const {
    return m_store;
}


} //end ns
