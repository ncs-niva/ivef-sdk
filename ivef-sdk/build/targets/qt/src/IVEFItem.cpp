#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFItem.h"

namespace ivef {

// Constructor
Item::Item()
 :  QObject(),
    m_dataSelector( 0 ),
    m_dataSelectorPresent( false ),
    m_fieldSelector(),
    m_fieldSelectorPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Item::Item(XmlStreamReader& xml)
 :  QObject(),
    m_dataSelector( 0 ),
    m_dataSelectorPresent( false ),
    m_fieldSelector(),
    m_fieldSelectorPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "DataSelector" ) )
    {
        if ( !setDataSelector( attr.value( "DataSelector" ).toString().toInt() ) )
            xml.validationError( "error set DataSelector = " + attr.value( "DataSelector" ).toString() );
    }
    if ( attr.hasAttribute( "FieldSelector" ) )
    {
        if ( !setFieldSelector( attr.value( "FieldSelector" ).toString() ) )
            xml.validationError( "error set FieldSelector = " + attr.value( "FieldSelector" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Item" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Item::Item(const Item &val)
 :  QObject(),
    m_dataSelector( val.m_dataSelector ),
    m_dataSelectorPresent( val.m_dataSelectorPresent ),
    m_fieldSelector( val.m_fieldSelector ),
    m_fieldSelectorPresent( val.m_fieldSelectorPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Item::operator==(const Item &val) {

    if (!(m_dataSelectorPresent == val.m_dataSelectorPresent)) return false;
    if (!(m_dataSelector == val.m_dataSelector)) return false;
    if (!(m_fieldSelectorPresent == val.m_fieldSelectorPresent)) return false;
    if (!(m_fieldSelector == val.m_fieldSelector)) return false;
    return true;
}

// assignement
Item & Item::operator=(const Item &val) {

    m_dataSelectorPresent = val.m_dataSelectorPresent;
    m_dataSelector = val.m_dataSelector;
    m_fieldSelectorPresent = val.m_fieldSelectorPresent;
    m_fieldSelector = val.m_fieldSelector;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Item
bool Item::setDataSelector(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_dataSelectorPresent = true;
    m_dataSelector = val;
    m_changed = true;
    return true;
}

// getter for Item
int Item::getDataSelector() const {

    return m_dataSelector;
}

// setter for Item
bool Item::setFieldSelector(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_fieldSelectorPresent = true;
    m_fieldSelector = val;
    m_changed = true;
    return true;
}

// getter for Item
QString Item::getFieldSelector() const {

    return m_fieldSelector;
}

// Get XML Representation
const QString& Item::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Item";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_dataSelectorPresent) {
            xml.append(" DataSelector=\"" + QString::number( m_dataSelector ) + endAttr);
        } else { // required attribute not present
            m_lastError = "DataSelector not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_fieldSelectorPresent) {
            xml.append(" FieldSelector=\"" + encode (m_fieldSelector) + endAttr);
        } else { // required attribute not present
            m_lastError = "FieldSelector not set";
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
QString Item::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Item::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Item\n";
    str.append( lead + "    DataSelector = " + QString::number( m_dataSelector ) + endAttr);
    str.append( lead + "    FieldSelector = " + m_fieldSelector + endAttr);
    return str;
}

const QString& Item::lastError() const {
    return m_lastError;
}

const bool& Item::changed() const {
    return m_changed;
}

const QString& Item::store() const {
    return m_store;
}


} //end ns
