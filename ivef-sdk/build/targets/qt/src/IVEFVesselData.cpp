#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFVesselData.h"

namespace ivef {

// Constructor
VesselData::VesselData()
 :  QObject(),
    m_constructionPresent( false ),
    m_identifierPresent( false ),
    m_class( 0 ),
    m_classPresent( false ),
    m_blackListed( false ),
    m_blackListedPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_specialAttention(),
    m_specialAttentionPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_sourceType( 0 ),
    m_sourceTypePresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
VesselData::VesselData(XmlStreamReader& xml)
 :  QObject(),
    m_constructionPresent( false ),
    m_identifierPresent( false ),
    m_class( 0 ),
    m_classPresent( false ),
    m_blackListed( false ),
    m_blackListedPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_specialAttention(),
    m_specialAttentionPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_sourceType( 0 ),
    m_sourceTypePresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Class" ) )
    {
        if ( !setClass( attr.value( "Class" ).toString().toInt() ) )
            xml.validationError( "error set Class = " + attr.value( "Class" ).toString() );
    }
    if ( attr.hasAttribute( "BlackListed" ) )
    {
        // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
        QString value = attr.value( "BlackListed" ).toString().toUpper();
        if ( !setBlackListed( value == "YES" ||
                             value == "TRUE" ||
                             value == "1") )
            xml.validationError( "error set BlackListed = " + attr.value( "BlackListed" ).toString() );
    }
    if ( attr.hasAttribute( "Id" ) )
    {
        if ( !setId( attr.value( "Id" ).toString().toInt() ) )
            xml.validationError( "error set Id = " + attr.value( "Id" ).toString() );
    }
    if ( attr.hasAttribute( "SpecialAttention" ) )
    {
        if ( !setSpecialAttention( attr.value( "SpecialAttention" ).toString() ) )
            xml.validationError( "error set SpecialAttention = " + attr.value( "SpecialAttention" ).toString() );
    }
    if ( attr.hasAttribute( "SourceId" ) )
    {
        if ( !setSourceId( attr.value( "SourceId" ).toString() ) )
            xml.validationError( "error set SourceId = " + attr.value( "SourceId" ).toString() );
    }
    if ( attr.hasAttribute( "SourceName" ) )
    {
        if ( !setSourceName( attr.value( "SourceName" ).toString() ) )
            xml.validationError( "error set SourceName = " + attr.value( "SourceName" ).toString() );
    }
    if ( attr.hasAttribute( "SourceType" ) )
    {
        if ( !setSourceType( attr.value( "SourceType" ).toString().toInt() ) )
            xml.validationError( "error set SourceType = " + attr.value( "SourceType" ).toString() );
    }
    if ( attr.hasAttribute( "UpdateTime" ) )
    {
        if ( !setUpdateTime( QDateTime::fromString(attr.value( "UpdateTime" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set UpdateTime = " + attr.value( "UpdateTime" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "VesselData" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Construction" )
            {
                Construction val( xml );
                if ( xml.name() != "Construction" )
                    xml.raiseError( "tag mismatch Construction" );
                else if ( !setConstruction( val ) )
                    xml.validationError( "error set Construction"  );
            }
            else if ( xml.name() == "Identifier" )
            {
                Identifier val( xml );
                if ( xml.name() != "Identifier" )
                    xml.raiseError( "tag mismatch Identifier" );
                else if ( !setIdentifier( val ) )
                    xml.validationError( "error set Identifier"  );
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
VesselData::VesselData(const VesselData &val)
 :  QObject(),
    m_construction( val.m_construction ),
    m_constructionPresent( val.m_constructionPresent ),
    m_identifier( val.m_identifier ),
    m_identifierPresent( val.m_identifierPresent ),
    m_class( val.m_class ),
    m_classPresent( val.m_classPresent ),
    m_blackListed( val.m_blackListed ),
    m_blackListedPresent( val.m_blackListedPresent ),
    m_id( val.m_id ),
    m_idPresent( val.m_idPresent ),
    m_specialAttention( val.m_specialAttention ),
    m_specialAttentionPresent( val.m_specialAttentionPresent ),
    m_sourceId( val.m_sourceId ),
    m_sourceIdPresent( val.m_sourceIdPresent ),
    m_sourceName( val.m_sourceName ),
    m_sourceNamePresent( val.m_sourceNamePresent ),
    m_sourceType( val.m_sourceType ),
    m_sourceTypePresent( val.m_sourceTypePresent ),
    m_updateTime( val.m_updateTime ),
    m_updateTimePresent( val.m_updateTimePresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool VesselData::operator==(const VesselData &val) {

    if (!(m_constructionPresent == val.m_constructionPresent)) return false;
    if (!(m_construction == val.m_construction)) return false;
    if (!(m_identifierPresent == val.m_identifierPresent)) return false;
    if (!(m_identifier == val.m_identifier)) return false;
    if (!(m_classPresent == val.m_classPresent)) return false;
    if (!(m_class == val.m_class)) return false;
    if (!(m_blackListedPresent == val.m_blackListedPresent)) return false;
    if (!(m_blackListed == val.m_blackListed)) return false;
    if (!(m_idPresent == val.m_idPresent)) return false;
    if (!(m_id == val.m_id)) return false;
    if (!(m_specialAttentionPresent == val.m_specialAttentionPresent)) return false;
    if (!(m_specialAttention == val.m_specialAttention)) return false;
    if (!(m_sourceIdPresent == val.m_sourceIdPresent)) return false;
    if (!(m_sourceId == val.m_sourceId)) return false;
    if (!(m_sourceNamePresent == val.m_sourceNamePresent)) return false;
    if (!(m_sourceName == val.m_sourceName)) return false;
    if (!(m_sourceTypePresent == val.m_sourceTypePresent)) return false;
    if (!(m_sourceType == val.m_sourceType)) return false;
    if (!(m_updateTimePresent == val.m_updateTimePresent)) return false;
    if (!(m_updateTime == val.m_updateTime)) return false;
    return true;
}

// assignement
VesselData & VesselData::operator=(const VesselData &val) {

    m_constructionPresent = val.m_constructionPresent;
    m_construction = val.m_construction;
    m_identifierPresent = val.m_identifierPresent;
    m_identifier = val.m_identifier;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_blackListedPresent = val.m_blackListedPresent;
    m_blackListed = val.m_blackListed;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_specialAttentionPresent = val.m_specialAttentionPresent;
    m_specialAttention = val.m_specialAttention;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for VesselData
bool VesselData::setConstruction(const Construction& val) {

    m_constructionPresent = true;
    m_construction = val;
    m_changed = true;
    return true;
}

// getter for VesselData
const Construction& VesselData::getConstruction() const {

    return m_construction;
}

// check if optional element VesselData has been set
bool VesselData::hasConstruction() const {

    return m_constructionPresent;
}

// setter for VesselData
bool VesselData::setIdentifier(const Identifier& val) {

    m_identifierPresent = true;
    m_identifier = val;
    m_changed = true;
    return true;
}

// getter for VesselData
const Identifier& VesselData::getIdentifier() const {

    return m_identifier;
}

// check if optional element VesselData has been set
bool VesselData::hasIdentifier() const {

    return m_identifierPresent;
}

// setter for VesselData
bool VesselData::setClass(int val) {

    // check if the new value is an approved value
    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_classPresent = true;
    m_class = val;
    m_changed = true;
    return true;
}

// getter for VesselData
int VesselData::getClass() const {

    return m_class;
}

// check if optional element VesselData has been set
bool VesselData::hasClass() const {

    return m_classPresent;
}

// setter for VesselData
bool VesselData::setBlackListed(bool val) {

    m_blackListedPresent = true;
    m_blackListed = val;
    m_changed = true;
    return true;
}

// getter for VesselData
bool VesselData::getBlackListed() const {

    return m_blackListed;
}

// check if optional element VesselData has been set
bool VesselData::hasBlackListed() const {

    return m_blackListedPresent;
}

// setter for VesselData
bool VesselData::setId(int val) {

    m_idPresent = true;
    m_id = val;
    m_changed = true;
    return true;
}

// getter for VesselData
int VesselData::getId() const {

    return m_id;
}

// setter for VesselData
bool VesselData::setSpecialAttention(QString val) {

    // check if the new value is within max length
    if (val.length() > 20)
        return false;
    m_specialAttentionPresent = true;
    m_specialAttention = val;
    m_changed = true;
    return true;
}

// getter for VesselData
QString VesselData::getSpecialAttention() const {

    return m_specialAttention;
}

// check if optional element VesselData has been set
bool VesselData::hasSpecialAttention() const {

    return m_specialAttentionPresent;
}

// setter for VesselData
bool VesselData::setSourceId(QString val) {

    // check if the new value is within min length
    if (val.length() < 5)
        return false;
    // check if the new value is within max length
    if (val.length() > 15)
        return false;
    m_sourceIdPresent = true;
    m_sourceId = val;
    m_changed = true;
    return true;
}

// getter for VesselData
QString VesselData::getSourceId() const {

    return m_sourceId;
}

// check if optional element VesselData has been set
bool VesselData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for VesselData
bool VesselData::setSourceName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_sourceNamePresent = true;
    m_sourceName = val;
    m_changed = true;
    return true;
}

// getter for VesselData
QString VesselData::getSourceName() const {

    return m_sourceName;
}

// setter for VesselData
bool VesselData::setSourceType(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_sourceTypePresent = true;
    m_sourceType = val;
    m_changed = true;
    return true;
}

// getter for VesselData
int VesselData::getSourceType() const {

    return m_sourceType;
}

// setter for VesselData
bool VesselData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
    m_changed = true;
    return true;
}

// getter for VesselData
QDateTime VesselData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
const QString& VesselData::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<VesselData";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasClass() ) {
                xml.append(" Class=\"" + QString::number( m_class ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasBlackListed() ) {
                xml.append(" BlackListed=\"" + QString( m_blackListed ? "true" : "false" ) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_idPresent) {
            xml.append(" Id=\"" + QString::number( m_id ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Id not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasSpecialAttention() ) {
                xml.append(" SpecialAttention=\"" + encode (m_specialAttention) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasSourceId() ) {
                xml.append(" SourceId=\"" + encode (m_sourceId) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_sourceNamePresent) {
            xml.append(" SourceName=\"" + encode (m_sourceName) + endAttr);
        } else { // required attribute not present
            m_lastError = "SourceName not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_sourceTypePresent) {
            xml.append(" SourceType=\"" + QString::number( m_sourceType ) + endAttr);
        } else { // required attribute not present
            m_lastError = "SourceType not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_updateTimePresent) {
            xml.append(" UpdateTime=\"" + dateToString( m_updateTime) + endAttr);
        } else { // required attribute not present
            m_lastError = "UpdateTime not set";
            m_store  = QString::null;
            return m_store;
        }
        xml.append(">\n");
        // add optional data if available
        if ( hasConstruction() ) {
            dataMember = m_construction.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Construction:" + m_construction.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        // add optional data if available
        if ( hasIdentifier() ) {
            dataMember = m_identifier.toXML(false);
            if (dataMember != QString::null) {
                xml.append( dataMember );
            } else {
                m_lastError = "Identifier:" + m_identifier.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</VesselData>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString VesselData::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString VesselData::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "VesselData\n";
    // check for presence of optional attribute
    if ( hasClass() ) {
        str.append( lead + "    Class = " + QString::number( m_class ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasBlackListed() ) {
        str.append( lead + "    BlackListed = " + QString( m_blackListed ? "true" : "false" ) + endAttr);
    }
    str.append( lead + "    Id = " + QString::number( m_id ) + endAttr);
    // check for presence of optional attribute
    if ( hasSpecialAttention() ) {
        str.append( lead + "    SpecialAttention = " + m_specialAttention + endAttr);
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + endAttr);
    }
    str.append( lead + "    SourceName = " + m_sourceName + endAttr);
    str.append( lead + "    SourceType = " + QString::number( m_sourceType ) + endAttr);
    str.append( lead + "    UpdateTime = " + dateToString( m_updateTime) + endAttr);
    // add all optional data if present
    if ( hasConstruction() ) {
        str.append( m_construction.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasIdentifier() ) {
        str.append( m_identifier.toString(lead + "    ") );
    }
    return str;
}

const QString& VesselData::lastError() const {
    return m_lastError;
}

const bool& VesselData::changed() const {
    return m_changed;
}

const QString& VesselData::store() const {
    return m_store;
}


} //end ns
