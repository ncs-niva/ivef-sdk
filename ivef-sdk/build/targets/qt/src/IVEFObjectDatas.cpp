#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFObjectDatas.h"

namespace ivef {

// Constructor
ObjectDatas::ObjectDatas()
 :  QObject(),
    m_changed(true)
{
}

// Constructor for parser function
ObjectDatas::ObjectDatas(XmlStreamReader& xml)
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
            if (  xml.name() == "ObjectDatas" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "ObjectData" )
            {
                ObjectData val( xml );
                if ( xml.name() != "ObjectData" )
                    xml.raiseError( "tag mismatch ObjectData" );
                else if ( !addObjectData( val ) )
                    xml.validationError( "error add ObjectData"  );
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
ObjectDatas::ObjectDatas(const ObjectDatas &val)
 :  QObject(),
    m_objectDatas( val.m_objectDatas ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool ObjectDatas::operator==(const ObjectDatas &val) {

    if (!(m_objectDatas == val.m_objectDatas)) return false;
    return true;
}

// assignement
ObjectDatas & ObjectDatas::operator=(const ObjectDatas &val) {

    m_objectDatas = val.m_objectDatas;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for ObjectDatas
bool ObjectDatas::removeObjectData(const ObjectData& val) {

    m_changed = true;
    return m_objectDatas.removeOne(val);
}

// setter for ObjectDatas
bool ObjectDatas::addObjectData(const ObjectData& val) {

    m_objectDatas.append(val);
    m_changed = true;
    return true;
}

// getter for ObjectDatas
const ObjectData& ObjectDatas::getObjectDataAt(int i) const {

    return m_objectDatas.at(i);
}

// count for ObjectDatas
int ObjectDatas::countOfObjectDatas() const {

    return m_objectDatas.count();
}

// Get XML Representation
const QString& ObjectDatas::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<ObjectDatas";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append(">\n");
        // add all included data
        for(int i=0; i < m_objectDatas.count(); i++ ) {
            ObjectData attribute = m_objectDatas.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "ObjectData:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</ObjectDatas>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString ObjectDatas::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString ObjectDatas::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "ObjectDatas\n";
    // add all included data
    for(int i=0; i < m_objectDatas.count(); i++ ) {
        ObjectData attribute = m_objectDatas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& ObjectDatas::lastError() const {
    return m_lastError;
}

const bool& ObjectDatas::changed() const {
    return m_changed;
}

const QString& ObjectDatas::store() const {
    return m_store;
}


} //end ns
