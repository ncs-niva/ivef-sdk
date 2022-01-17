#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFArea.h"

namespace ivef {

// Constructor
Area::Area()
 :  QObject(),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Area::Area(XmlStreamReader& xml)
 :  QObject(),
    m_name(),
    m_namePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Name" ) )
    {
        if ( !setName( attr.value( "Name" ).toString() ) )
            xml.validationError( "error set Name = " + attr.value( "Name" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Area" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Pos" )
            {
                Pos val( xml );
                if ( xml.name() != "Pos" )
                    xml.raiseError( "tag mismatch Pos" );
                else if ( !addPos( val ) )
                    xml.validationError( "error add Pos"  );
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
Area::Area(const Area &val)
 :  QObject(),
    m_poss( val.m_poss ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Area::operator==(const Area &val) {

    if (!(m_poss == val.m_poss)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
Area & Area::operator=(const Area &val) {

    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for Area
bool Area::removePos(const Pos& val) {

    if (m_poss.count() <= 3) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_poss.removeOne(val);
}

// setter for Area
bool Area::addPos(const Pos& val) {

    m_poss.append(val);
    m_changed = true;
    return true;
}

// getter for Area
const Pos& Area::getPosAt(int i) const {

    return m_poss.at(i);
}

// count for Area
int Area::countOfPoss() const {

    return m_poss.count();
}

// setter for Area
bool Area::setName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_namePresent = true;
    m_name = val;
    m_changed = true;
    return true;
}

// getter for Area
QString Area::getName() const {

    return m_name;
}

// check if optional element Area has been set
bool Area::hasName() const {

    return m_namePresent;
}

// Get XML Representation
const QString& Area::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Area";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasName() ) {
                xml.append(" Name=\"" + encode (m_name) + endAttr);
        }
        xml.append(">\n");
        if (m_poss.count() < 3) {
            m_lastError = "not enough Pos values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_poss.count(); i++ ) {
            Pos attribute = m_poss.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "Pos:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</Area>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Area::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Area::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Area\n";
    // check for presence of optional attribute
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + endAttr);
    }
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& Area::lastError() const {
    return m_lastError;
}

const bool& Area::changed() const {
    return m_changed;
}

const QString& Area::store() const {
    return m_store;
}


} //end ns
