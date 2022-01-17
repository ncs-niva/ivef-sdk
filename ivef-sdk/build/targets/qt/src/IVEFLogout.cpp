#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFLogout.h"

namespace ivef {

// Constructor
Logout::Logout()
 :  QObject(),
    m_changed(true)
{
}

// Constructor for parser function
Logout::Logout(XmlStreamReader& xml)
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
            if (  xml.name() == "Logout" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Logout::Logout(const Logout &val)
 :  QObject(),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Logout::operator==(const Logout &val) {

    return true;
}

// assignement
Logout & Logout::operator=(const Logout &val) {

    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// Get XML Representation
const QString& Logout::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Logout";
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
QString Logout::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Logout::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Logout\n";
    return str;
}

const QString& Logout::lastError() const {
    return m_lastError;
}

const bool& Logout::changed() const {
    return m_changed;
}

const QString& Logout::store() const {
    return m_store;
}


} //end ns
