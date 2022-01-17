#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFSchema.h"

namespace ivef {

// Constructor
Schema::Schema()
 :  QObject(),
    m_changed(true)
{
}

// Constructor for parser function
Schema::Schema(XmlStreamReader& xml)
 :  QObject(),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Schema" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Schema::Schema(const Schema &val)
 :  QObject(),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Schema::operator==(const Schema &val) {

    return true;
}

// assignement
Schema & Schema::operator=(const Schema &val) {

    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// getter for Schema
QString Schema::getElementFormDefault() const {

    return "qualified";
}

// getter for Schema
QString Schema::getTargetNamespace() const {

    return "http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5";
}

// Get XML Representation
const QString& Schema::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Schema";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append("/>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Schema::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Schema::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Schema\n";
    return str;
}

const QString& Schema::lastError() const {
    return m_lastError;
}

const bool& Schema::changed() const {
    return m_changed;
}

const QString& Schema::store() const {
    return m_store;
}


} //end ns
