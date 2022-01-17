#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFObjectData.h"

namespace ivef {

// Constructor
ObjectData::ObjectData()
 :  QObject(),
    m_trackDataPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
ObjectData::ObjectData(XmlStreamReader& xml)
 :  QObject(),
    m_trackDataPresent( false ),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "ObjectData" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "TrackData" )
            {
                TrackData val( xml );
                if ( xml.name() != "TrackData" )
                    xml.raiseError( "tag mismatch TrackData" );
                else if ( !setTrackData( val ) )
                    xml.validationError( "error set TrackData"  );
            }
            else if ( xml.name() == "VesselData" )
            {
                VesselData val( xml );
                if ( xml.name() != "VesselData" )
                    xml.raiseError( "tag mismatch VesselData" );
                else if ( !addVesselData( val ) )
                    xml.validationError( "error add VesselData"  );
            }
            else if ( xml.name() == "VoyageData" )
            {
                VoyageData val( xml );
                if ( xml.name() != "VoyageData" )
                    xml.raiseError( "tag mismatch VoyageData" );
                else if ( !addVoyageData( val ) )
                    xml.validationError( "error add VoyageData"  );
            }
            else if ( xml.name() == "TaggedItem" )
            {
                TaggedItem val( xml );
                if ( xml.name() != "TaggedItem" )
                    xml.raiseError( "tag mismatch TaggedItem" );
                else if ( !addTaggedItem( val ) )
                    xml.validationError( "error add TaggedItem"  );
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
ObjectData::ObjectData(const ObjectData &val)
 :  QObject(),
    m_trackData( val.m_trackData ),
    m_trackDataPresent( val.m_trackDataPresent ),
    m_vesselDatas( val.m_vesselDatas ),
    m_voyageDatas( val.m_voyageDatas ),
    m_taggedItems( val.m_taggedItems ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool ObjectData::operator==(const ObjectData &val) {

    if (!(m_trackDataPresent == val.m_trackDataPresent)) return false;
    if (!(m_trackData == val.m_trackData)) return false;
    if (!(m_vesselDatas == val.m_vesselDatas)) return false;
    if (!(m_voyageDatas == val.m_voyageDatas)) return false;
    if (!(m_taggedItems == val.m_taggedItems)) return false;
    return true;
}

// assignement
ObjectData & ObjectData::operator=(const ObjectData &val) {

    m_trackDataPresent = val.m_trackDataPresent;
    m_trackData = val.m_trackData;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItems = val.m_taggedItems;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for ObjectData
bool ObjectData::setTrackData(const TrackData& val) {

    m_trackDataPresent = true;
    m_trackData = val;
    m_changed = true;
    return true;
}

// getter for ObjectData
const TrackData& ObjectData::getTrackData() const {

    return m_trackData;
}

// check if optional element ObjectData has been set
bool ObjectData::hasTrackData() const {

    return m_trackDataPresent;
}

// remover for ObjectData
bool ObjectData::removeVesselData(const VesselData& val) {

    if (m_vesselDatas.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_vesselDatas.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addVesselData(const VesselData& val) {

    m_vesselDatas.append(val);
    m_changed = true;
    return true;
}

// getter for ObjectData
const VesselData& ObjectData::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVesselDatas() const {

    return m_vesselDatas.count();
}

// remover for ObjectData
bool ObjectData::removeVoyageData(const VoyageData& val) {

    if (m_voyageDatas.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_voyageDatas.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addVoyageData(const VoyageData& val) {

    m_voyageDatas.append(val);
    m_changed = true;
    return true;
}

// getter for ObjectData
const VoyageData& ObjectData::getVoyageDataAt(int i) const {

    return m_voyageDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVoyageDatas() const {

    return m_voyageDatas.count();
}

// remover for ObjectData
bool ObjectData::removeTaggedItem(const TaggedItem& val) {

    if (m_taggedItems.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_taggedItems.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addTaggedItem(const TaggedItem& val) {

    m_taggedItems.append(val);
    m_changed = true;
    return true;
}

// getter for ObjectData
const TaggedItem& ObjectData::getTaggedItemAt(int i) const {

    return m_taggedItems.at(i);
}

// count for ObjectData
int ObjectData::countOfTaggedItems() const {

    return m_taggedItems.count();
}

// Get XML Representation
const QString& ObjectData::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<ObjectData";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append(">\n");
        // add optional data if available
        if ( hasTrackData() ) {
            dataMember = m_trackData.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "TrackData:" + m_trackData.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        if (m_vesselDatas.count() < 0) {
            m_lastError = "not enough VesselData values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_vesselDatas.count(); i++ ) {
            VesselData attribute = m_vesselDatas.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "VesselData:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        if (m_voyageDatas.count() < 0) {
            m_lastError = "not enough VoyageData values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_voyageDatas.count(); i++ ) {
            VoyageData attribute = m_voyageDatas.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "VoyageData:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        if (m_taggedItems.count() < 0) {
            m_lastError = "not enough TaggedItem values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_taggedItems.count(); i++ ) {
            TaggedItem attribute = m_taggedItems.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "TaggedItem:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</ObjectData>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString ObjectData::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString ObjectData::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "ObjectData\n";
    // add all optional data if present
    if ( hasTrackData() ) {
        str.append( m_trackData.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
        VesselData attribute = m_vesselDatas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
        VoyageData attribute = m_voyageDatas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_taggedItems.count(); i++ ) {
        TaggedItem attribute = m_taggedItems.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& ObjectData::lastError() const {
    return m_lastError;
}

const bool& ObjectData::changed() const {
    return m_changed;
}

const QString& ObjectData::store() const {
    return m_store;
}


} //end ns
