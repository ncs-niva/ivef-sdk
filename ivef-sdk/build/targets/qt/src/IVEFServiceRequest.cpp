#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFServiceRequest.h"

namespace ivef {

// Constructor
ServiceRequest::ServiceRequest()
 :  QObject(),
    m_transmissionPresent( false ),
    m_filterPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
ServiceRequest::ServiceRequest(XmlStreamReader& xml)
 :  QObject(),
    m_transmissionPresent( false ),
    m_filterPresent( false ),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "ServiceRequest" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Area" )
            {
                Area val( xml );
                if ( xml.name() != "Area" )
                    xml.raiseError( "tag mismatch Area" );
                else if ( !addArea( val ) )
                    xml.validationError( "error add Area"  );
            }
            else if ( xml.name() == "Transmission" )
            {
                Transmission val( xml );
                if ( xml.name() != "Transmission" )
                    xml.raiseError( "tag mismatch Transmission" );
                else if ( !setTransmission( val ) )
                    xml.validationError( "error set Transmission"  );
            }
            else if ( xml.name() == "Item" )
            {
                Item val( xml );
                if ( xml.name() != "Item" )
                    xml.raiseError( "tag mismatch Item" );
                else if ( !addItem( val ) )
                    xml.validationError( "error add Item"  );
            }
            else if ( xml.name() == "Filter" )
            {
                Filter val( xml );
                if ( xml.name() != "Filter" )
                    xml.raiseError( "tag mismatch Filter" );
                else if ( !setFilter( val ) )
                    xml.validationError( "error set Filter"  );
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
ServiceRequest::ServiceRequest(const ServiceRequest &val)
 :  QObject(),
    m_areas( val.m_areas ),
    m_transmission( val.m_transmission ),
    m_transmissionPresent( val.m_transmissionPresent ),
    m_items( val.m_items ),
    m_filter( val.m_filter ),
    m_filterPresent( val.m_filterPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool ServiceRequest::operator==(const ServiceRequest &val) {

    if (!(m_areas == val.m_areas)) return false;
    if (!(m_transmissionPresent == val.m_transmissionPresent)) return false;
    if (!(m_transmission == val.m_transmission)) return false;
    if (!(m_items == val.m_items)) return false;
    if (!(m_filterPresent == val.m_filterPresent)) return false;
    if (!(m_filter == val.m_filter)) return false;
    return true;
}

// assignement
ServiceRequest & ServiceRequest::operator=(const ServiceRequest &val) {

    m_areas = val.m_areas;
    m_transmissionPresent = val.m_transmissionPresent;
    m_transmission = val.m_transmission;
    m_items = val.m_items;
    m_filterPresent = val.m_filterPresent;
    m_filter = val.m_filter;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for ServiceRequest
bool ServiceRequest::removeArea(const Area& val) {

    if (m_areas.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_areas.removeOne(val);
}

// setter for ServiceRequest
bool ServiceRequest::addArea(const Area& val) {

    m_areas.append(val);
    m_changed = true;
    return true;
}

// getter for ServiceRequest
const Area& ServiceRequest::getAreaAt(int i) const {

    return m_areas.at(i);
}

// count for ServiceRequest
int ServiceRequest::countOfAreas() const {

    return m_areas.count();
}

// setter for ServiceRequest
bool ServiceRequest::setTransmission(const Transmission& val) {

    m_transmissionPresent = true;
    m_transmission = val;
    m_changed = true;
    return true;
}

// getter for ServiceRequest
const Transmission& ServiceRequest::getTransmission() const {

    return m_transmission;
}

// remover for ServiceRequest
bool ServiceRequest::removeItem(const Item& val) {

    if (m_items.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_items.removeOne(val);
}

// setter for ServiceRequest
bool ServiceRequest::addItem(const Item& val) {

    m_items.append(val);
    m_changed = true;
    return true;
}

// getter for ServiceRequest
const Item& ServiceRequest::getItemAt(int i) const {

    return m_items.at(i);
}

// count for ServiceRequest
int ServiceRequest::countOfItems() const {

    return m_items.count();
}

// setter for ServiceRequest
bool ServiceRequest::setFilter(const Filter& val) {

    m_filterPresent = true;
    m_filter = val;
    m_changed = true;
    return true;
}

// getter for ServiceRequest
const Filter& ServiceRequest::getFilter() const {

    return m_filter;
}

// check if optional element ServiceRequest has been set
bool ServiceRequest::hasFilter() const {

    return m_filterPresent;
}

// Get XML Representation
const QString& ServiceRequest::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<ServiceRequest";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
        xml.append(">\n");
        if (m_areas.count() < 0) {
            m_lastError = "not enough Area values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_areas.count(); i++ ) {
            Area attribute = m_areas.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "Area:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // check for presence of required data member
        if ( m_transmissionPresent) {
            dataMember = m_transmission.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Transmission:" + m_transmission.lastError();
                m_store  = QString::null;
                return m_store;
            }
        } else {
            m_lastError = "Transmission not set";
            m_store  = QString::null;
            return m_store;
        }
        if (m_items.count() < 0) {
            m_lastError = "not enough Item values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_items.count(); i++ ) {
            Item attribute = m_items.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "Item:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasFilter() ) {
            dataMember = m_filter.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Filter:" + m_filter.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</ServiceRequest>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString ServiceRequest::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString ServiceRequest::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "ServiceRequest\n";
    // add all included data
    for(int i=0; i < m_areas.count(); i++ ) {
        Area attribute = m_areas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    str.append( m_transmission.toString(lead + "    ") );
    // add all included data
    for(int i=0; i < m_items.count(); i++ ) {
        Item attribute = m_items.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all optional data if present
    if ( hasFilter() ) {
        str.append( m_filter.toString(lead + "    ") );
    }
    return str;
}

const QString& ServiceRequest::lastError() const {
    return m_lastError;
}

const bool& ServiceRequest::changed() const {
    return m_changed;
}

const QString& ServiceRequest::store() const {
    return m_store;
}


} //end ns
