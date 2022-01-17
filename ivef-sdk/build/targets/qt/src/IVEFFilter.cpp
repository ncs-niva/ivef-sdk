#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFFilter.h"

namespace ivef {

// Constructor
Filter::Filter()
 :  QObject(),
    m_predicate(),
    m_predicatePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Filter::Filter(XmlStreamReader& xml)
 :  QObject(),
    m_predicate(),
    m_predicatePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Predicate" ) )
    {
        if ( !setPredicate( attr.value( "Predicate" ).toString() ) )
            xml.validationError( "error set Predicate = " + attr.value( "Predicate" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Filter" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Filter::Filter(const Filter &val)
 :  QObject(),
    m_predicate( val.m_predicate ),
    m_predicatePresent( val.m_predicatePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Filter::operator==(const Filter &val) {

    if (!(m_predicatePresent == val.m_predicatePresent)) return false;
    if (!(m_predicate == val.m_predicate)) return false;
    return true;
}

// assignement
Filter & Filter::operator=(const Filter &val) {

    m_predicatePresent = val.m_predicatePresent;
    m_predicate = val.m_predicate;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Filter
bool Filter::setPredicate(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 1024)
        return false;
    m_predicatePresent = true;
    m_predicate = val;
    m_changed = true;
    return true;
}

// getter for Filter
QString Filter::getPredicate() const {

    return m_predicate;
}

// Get XML Representation
const QString& Filter::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Filter";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_predicatePresent) {
            xml.append(" Predicate=\"" + encode (m_predicate) + endAttr);
        } else { // required attribute not present
            m_lastError = "Predicate not set";
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
QString Filter::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Filter::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Filter\n";
    str.append( lead + "    Predicate = " + m_predicate + endAttr);
    return str;
}

const QString& Filter::lastError() const {
    return m_lastError;
}

const bool& Filter::changed() const {
    return m_changed;
}

const QString& Filter::store() const {
    return m_store;
}


} //end ns
