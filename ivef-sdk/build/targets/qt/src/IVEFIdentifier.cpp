#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFIdentifier.h"

namespace ivef {

// Constructor
Identifier::Identifier()
 :  QObject(),
    m_callsign(),
    m_callsignPresent( false ),
    m_IMO( 0 ),
    m_IMOPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_formerName(),
    m_formerNamePresent( false ),
    m_flag(),
    m_flagPresent( false ),
    m_owner(),
    m_ownerPresent( false ),
    m_MMSI( 0 ),
    m_MMSIPresent( false ),
    m_LRIT(),
    m_LRITPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Identifier::Identifier(XmlStreamReader& xml)
 :  QObject(),
    m_callsign(),
    m_callsignPresent( false ),
    m_IMO( 0 ),
    m_IMOPresent( false ),
    m_name(),
    m_namePresent( false ),
    m_formerName(),
    m_formerNamePresent( false ),
    m_flag(),
    m_flagPresent( false ),
    m_owner(),
    m_ownerPresent( false ),
    m_MMSI( 0 ),
    m_MMSIPresent( false ),
    m_LRIT(),
    m_LRITPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Callsign" ) )
    {
        if ( !setCallsign( attr.value( "Callsign" ).toString() ) )
            xml.validationError( "error set Callsign = " + attr.value( "Callsign" ).toString() );
    }
    if ( attr.hasAttribute( "IMO" ) )
    {
        if ( !setIMO( attr.value( "IMO" ).toString().toInt() ) )
            xml.validationError( "error set IMO = " + attr.value( "IMO" ).toString() );
    }
    if ( attr.hasAttribute( "Name" ) )
    {
        if ( !setName( attr.value( "Name" ).toString() ) )
            xml.validationError( "error set Name = " + attr.value( "Name" ).toString() );
    }
    if ( attr.hasAttribute( "FormerName" ) )
    {
        if ( !setFormerName( attr.value( "FormerName" ).toString() ) )
            xml.validationError( "error set FormerName = " + attr.value( "FormerName" ).toString() );
    }
    if ( attr.hasAttribute( "Flag" ) )
    {
        if ( !setFlag( attr.value( "Flag" ).toString() ) )
            xml.validationError( "error set Flag = " + attr.value( "Flag" ).toString() );
    }
    if ( attr.hasAttribute( "Owner" ) )
    {
        if ( !setOwner( attr.value( "Owner" ).toString() ) )
            xml.validationError( "error set Owner = " + attr.value( "Owner" ).toString() );
    }
    if ( attr.hasAttribute( "MMSI" ) )
    {
        if ( !setMMSI( attr.value( "MMSI" ).toString().toInt() ) )
            xml.validationError( "error set MMSI = " + attr.value( "MMSI" ).toString() );
    }
    if ( attr.hasAttribute( "LRIT" ) )
    {
        if ( !setLRIT( attr.value( "LRIT" ).toString() ) )
            xml.validationError( "error set LRIT = " + attr.value( "LRIT" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Identifier" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "OtherId" )
            {
                OtherId val( xml );
                if ( xml.name() != "OtherId" )
                    xml.raiseError( "tag mismatch OtherId" );
                else if ( !addOtherId( val ) )
                    xml.validationError( "error add OtherId"  );
            }
            else if ( xml.name() == "OtherName" )
            {
                OtherName val( xml );
                if ( xml.name() != "OtherName" )
                    xml.raiseError( "tag mismatch OtherName" );
                else if ( !addOtherName( val ) )
                    xml.validationError( "error add OtherName"  );
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
Identifier::Identifier(const Identifier &val)
 :  QObject(),
    m_otherIds( val.m_otherIds ),
    m_otherNames( val.m_otherNames ),
    m_callsign( val.m_callsign ),
    m_callsignPresent( val.m_callsignPresent ),
    m_IMO( val.m_IMO ),
    m_IMOPresent( val.m_IMOPresent ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_formerName( val.m_formerName ),
    m_formerNamePresent( val.m_formerNamePresent ),
    m_flag( val.m_flag ),
    m_flagPresent( val.m_flagPresent ),
    m_owner( val.m_owner ),
    m_ownerPresent( val.m_ownerPresent ),
    m_MMSI( val.m_MMSI ),
    m_MMSIPresent( val.m_MMSIPresent ),
    m_LRIT( val.m_LRIT ),
    m_LRITPresent( val.m_LRITPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Identifier::operator==(const Identifier &val) {

    if (!(m_otherIds == val.m_otherIds)) return false;
    if (!(m_otherNames == val.m_otherNames)) return false;
    if (!(m_callsignPresent == val.m_callsignPresent)) return false;
    if (!(m_callsign == val.m_callsign)) return false;
    if (!(m_IMOPresent == val.m_IMOPresent)) return false;
    if (!(m_IMO == val.m_IMO)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    if (!(m_formerNamePresent == val.m_formerNamePresent)) return false;
    if (!(m_formerName == val.m_formerName)) return false;
    if (!(m_flagPresent == val.m_flagPresent)) return false;
    if (!(m_flag == val.m_flag)) return false;
    if (!(m_ownerPresent == val.m_ownerPresent)) return false;
    if (!(m_owner == val.m_owner)) return false;
    if (!(m_MMSIPresent == val.m_MMSIPresent)) return false;
    if (!(m_MMSI == val.m_MMSI)) return false;
    if (!(m_LRITPresent == val.m_LRITPresent)) return false;
    if (!(m_LRIT == val.m_LRIT)) return false;
    return true;
}

// assignement
Identifier & Identifier::operator=(const Identifier &val) {

    m_otherIds = val.m_otherIds;
    m_otherNames = val.m_otherNames;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_formerNamePresent = val.m_formerNamePresent;
    m_formerName = val.m_formerName;
    m_flagPresent = val.m_flagPresent;
    m_flag = val.m_flag;
    m_ownerPresent = val.m_ownerPresent;
    m_owner = val.m_owner;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_LRITPresent = val.m_LRITPresent;
    m_LRIT = val.m_LRIT;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for Identifier
bool Identifier::removeOtherId(const OtherId& val) {

    if (m_otherIds.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_otherIds.removeOne(val);
}

// setter for Identifier
bool Identifier::addOtherId(const OtherId& val) {

    m_otherIds.append(val);
    m_changed = true;
    return true;
}

// getter for Identifier
const OtherId& Identifier::getOtherIdAt(int i) const {

    return m_otherIds.at(i);
}

// count for Identifier
int Identifier::countOfOtherIds() const {

    return m_otherIds.count();
}

// remover for Identifier
bool Identifier::removeOtherName(const OtherName& val) {

    if (m_otherNames.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_otherNames.removeOne(val);
}

// setter for Identifier
bool Identifier::addOtherName(const OtherName& val) {

    m_otherNames.append(val);
    m_changed = true;
    return true;
}

// getter for Identifier
const OtherName& Identifier::getOtherNameAt(int i) const {

    return m_otherNames.at(i);
}

// count for Identifier
int Identifier::countOfOtherNames() const {

    return m_otherNames.count();
}

// setter for Identifier
bool Identifier::setCallsign(QString val) {

    // check if the new value is within min length
    if (val.length() < 0)
        return false;
    // check if the new value is within max length
    if (val.length() > 9)
        return false;
    m_callsignPresent = true;
    m_callsign = val;
    m_changed = true;
    return true;
}

// getter for Identifier
QString Identifier::getCallsign() const {

    return m_callsign;
}

// check if optional element Identifier has been set
bool Identifier::hasCallsign() const {

    return m_callsignPresent;
}

// setter for Identifier
bool Identifier::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
    m_changed = true;
    return true;
}

// getter for Identifier
int Identifier::getIMO() const {

    return m_IMO;
}

// check if optional element Identifier has been set
bool Identifier::hasIMO() const {

    return m_IMOPresent;
}

// setter for Identifier
bool Identifier::setName(QString val) {

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

// getter for Identifier
QString Identifier::getName() const {

    return m_name;
}

// check if optional element Identifier has been set
bool Identifier::hasName() const {

    return m_namePresent;
}

// setter for Identifier
bool Identifier::setFormerName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_formerNamePresent = true;
    m_formerName = val;
    m_changed = true;
    return true;
}

// getter for Identifier
QString Identifier::getFormerName() const {

    return m_formerName;
}

// check if optional element Identifier has been set
bool Identifier::hasFormerName() const {

    return m_formerNamePresent;
}

// setter for Identifier
bool Identifier::setFlag(QString val) {

    // check if the new value is within min length
    if (val.length() < 2)
        return false;
    // check if the new value is within max length
    if (val.length() > 2)
        return false;
    m_flagPresent = true;
    m_flag = val;
    m_changed = true;
    return true;
}

// getter for Identifier
QString Identifier::getFlag() const {

    return m_flag;
}

// check if optional element Identifier has been set
bool Identifier::hasFlag() const {

    return m_flagPresent;
}

// setter for Identifier
bool Identifier::setOwner(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_ownerPresent = true;
    m_owner = val;
    m_changed = true;
    return true;
}

// getter for Identifier
QString Identifier::getOwner() const {

    return m_owner;
}

// check if optional element Identifier has been set
bool Identifier::hasOwner() const {

    return m_ownerPresent;
}

// setter for Identifier
bool Identifier::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
    m_changed = true;
    return true;
}

// getter for Identifier
int Identifier::getMMSI() const {

    return m_MMSI;
}

// check if optional element Identifier has been set
bool Identifier::hasMMSI() const {

    return m_MMSIPresent;
}

// setter for Identifier
bool Identifier::setLRIT(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 42)
        return false;
    m_LRITPresent = true;
    m_LRIT = val;
    m_changed = true;
    return true;
}

// getter for Identifier
QString Identifier::getLRIT() const {

    return m_LRIT;
}

// check if optional element Identifier has been set
bool Identifier::hasLRIT() const {

    return m_LRITPresent;
}

// Get XML Representation
const QString& Identifier::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Identifier";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasCallsign() ) {
                xml.append(" Callsign=\"" + encode (m_callsign) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasIMO() ) {
                xml.append(" IMO=\"" + QString::number( m_IMO ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasName() ) {
                xml.append(" Name=\"" + encode (m_name) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasFormerName() ) {
                xml.append(" FormerName=\"" + encode (m_formerName) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasFlag() ) {
                xml.append(" Flag=\"" + encode (m_flag) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasOwner() ) {
                xml.append(" Owner=\"" + encode (m_owner) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasMMSI() ) {
                xml.append(" MMSI=\"" + QString::number( m_MMSI ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasLRIT() ) {
                xml.append(" LRIT=\"" + encode (m_LRIT) + endAttr);
        }
        xml.append(">\n");
        if (m_otherIds.count() < 0) {
            m_lastError = "not enough OtherId values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_otherIds.count(); i++ ) {
            OtherId attribute = m_otherIds.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "OtherId:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        if (m_otherNames.count() < 0) {
            m_lastError = "not enough OtherName values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_otherNames.count(); i++ ) {
            OtherName attribute = m_otherNames.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "OtherName:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</Identifier>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Identifier::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Identifier::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Identifier\n";
    // check for presence of optional attribute
    if ( hasCallsign() ) {
        str.append( lead + "    Callsign = " + m_callsign + endAttr);
    }
    // check for presence of optional attribute
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number( m_IMO ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + endAttr);
    }
    // check for presence of optional attribute
    if ( hasFormerName() ) {
        str.append( lead + "    FormerName = " + m_formerName + endAttr);
    }
    // check for presence of optional attribute
    if ( hasFlag() ) {
        str.append( lead + "    Flag = " + m_flag + endAttr);
    }
    // check for presence of optional attribute
    if ( hasOwner() ) {
        str.append( lead + "    Owner = " + m_owner + endAttr);
    }
    // check for presence of optional attribute
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number( m_MMSI ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasLRIT() ) {
        str.append( lead + "    LRIT = " + m_LRIT + endAttr);
    }
    // add all included data
    for(int i=0; i < m_otherIds.count(); i++ ) {
        OtherId attribute = m_otherIds.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_otherNames.count(); i++ ) {
        OtherName attribute = m_otherNames.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& Identifier::lastError() const {
    return m_lastError;
}

const bool& Identifier::changed() const {
    return m_changed;
}

const QString& Identifier::store() const {
    return m_store;
}


} //end ns
