#include <cstdlib>
#include <iostream>
#include "IVEFFunctions.h"

#include "IVEFTrackData.h"

namespace ivef {

// Constructor
TrackData::TrackData()
 :  QObject(),
    m_COG( 0.0 ),
    m_COGPresent( false ),
    m_estAccSOG( 0.0 ),
    m_estAccSOGPresent( false ),
    m_estAccCOG( 0.0 ),
    m_estAccCOGPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_length( 0.0 ),
    m_lengthPresent( false ),
    m_heading( 0.0 ),
    m_headingPresent( false ),
    m_ROT( 0.0 ),
    m_ROTPresent( false ),
    m_SOG( 0.0 ),
    m_SOGPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_trackStatus( 0 ),
    m_trackStatusPresent( false ),
    m_width( 0.0 ),
    m_widthPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
TrackData::TrackData(XmlStreamReader& xml)
 :  QObject(),
    m_COG( 0.0 ),
    m_COGPresent( false ),
    m_estAccSOG( 0.0 ),
    m_estAccSOGPresent( false ),
    m_estAccCOG( 0.0 ),
    m_estAccCOGPresent( false ),
    m_id( 0 ),
    m_idPresent( false ),
    m_length( 0.0 ),
    m_lengthPresent( false ),
    m_heading( 0.0 ),
    m_headingPresent( false ),
    m_ROT( 0.0 ),
    m_ROTPresent( false ),
    m_SOG( 0.0 ),
    m_SOGPresent( false ),
    m_sourceId(),
    m_sourceIdPresent( false ),
    m_sourceName(),
    m_sourceNamePresent( false ),
    m_updateTime(),
    m_updateTimePresent( false ),
    m_trackStatus( 0 ),
    m_trackStatusPresent( false ),
    m_width( 0.0 ),
    m_widthPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "COG" ) )
    {
        if ( !setCOG( attr.value( "COG" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set COG = " + attr.value( "COG" ).toString() );
    }
    if ( attr.hasAttribute( "EstAccSOG" ) )
    {
        if ( !setEstAccSOG( attr.value( "EstAccSOG" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set EstAccSOG = " + attr.value( "EstAccSOG" ).toString() );
    }
    if ( attr.hasAttribute( "EstAccCOG" ) )
    {
        if ( !setEstAccCOG( attr.value( "EstAccCOG" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set EstAccCOG = " + attr.value( "EstAccCOG" ).toString() );
    }
    if ( attr.hasAttribute( "Id" ) )
    {
        if ( !setId( attr.value( "Id" ).toString().toInt() ) )
            xml.validationError( "error set Id = " + attr.value( "Id" ).toString() );
    }
    if ( attr.hasAttribute( "Length" ) )
    {
        if ( !setLength( attr.value( "Length" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Length = " + attr.value( "Length" ).toString() );
    }
    if ( attr.hasAttribute( "Heading" ) )
    {
        if ( !setHeading( attr.value( "Heading" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Heading = " + attr.value( "Heading" ).toString() );
    }
    if ( attr.hasAttribute( "ROT" ) )
    {
        if ( !setROT( attr.value( "ROT" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set ROT = " + attr.value( "ROT" ).toString() );
    }
    if ( attr.hasAttribute( "SOG" ) )
    {
        if ( !setSOG( attr.value( "SOG" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set SOG = " + attr.value( "SOG" ).toString() );
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
    if ( attr.hasAttribute( "UpdateTime" ) )
    {
        if ( !setUpdateTime( QDateTime::fromString(attr.value( "UpdateTime" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set UpdateTime = " + attr.value( "UpdateTime" ).toString() );
    }
    if ( attr.hasAttribute( "TrackStatus" ) )
    {
        if ( !setTrackStatus( attr.value( "TrackStatus" ).toString().toInt() ) )
            xml.validationError( "error set TrackStatus = " + attr.value( "TrackStatus" ).toString() );
    }
    if ( attr.hasAttribute( "Width" ) )
    {
        if ( !setWidth( attr.value( "Width" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Width = " + attr.value( "Width" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "TrackData" )
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
            else if ( xml.name() == "NavStatus" )
            {
                NavStatus val( xml );
                if ( xml.name() != "NavStatus" )
                    xml.raiseError( "tag mismatch NavStatus" );
                else if ( !addNavStatus( val ) )
                    xml.validationError( "error add NavStatus"  );
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
TrackData::TrackData(const TrackData &val)
 :  QObject(),
    m_poss( val.m_poss ),
    m_navStatuss( val.m_navStatuss ),
    m_COG( val.m_COG ),
    m_COGPresent( val.m_COGPresent ),
    m_estAccSOG( val.m_estAccSOG ),
    m_estAccSOGPresent( val.m_estAccSOGPresent ),
    m_estAccCOG( val.m_estAccCOG ),
    m_estAccCOGPresent( val.m_estAccCOGPresent ),
    m_id( val.m_id ),
    m_idPresent( val.m_idPresent ),
    m_length( val.m_length ),
    m_lengthPresent( val.m_lengthPresent ),
    m_heading( val.m_heading ),
    m_headingPresent( val.m_headingPresent ),
    m_ROT( val.m_ROT ),
    m_ROTPresent( val.m_ROTPresent ),
    m_SOG( val.m_SOG ),
    m_SOGPresent( val.m_SOGPresent ),
    m_sourceId( val.m_sourceId ),
    m_sourceIdPresent( val.m_sourceIdPresent ),
    m_sourceName( val.m_sourceName ),
    m_sourceNamePresent( val.m_sourceNamePresent ),
    m_updateTime( val.m_updateTime ),
    m_updateTimePresent( val.m_updateTimePresent ),
    m_trackStatus( val.m_trackStatus ),
    m_trackStatusPresent( val.m_trackStatusPresent ),
    m_width( val.m_width ),
    m_widthPresent( val.m_widthPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool TrackData::operator==(const TrackData &val) {

    if (!(m_poss == val.m_poss)) return false;
    if (!(m_navStatuss == val.m_navStatuss)) return false;
    if (!(m_COGPresent == val.m_COGPresent)) return false;
    if (!(m_COG == val.m_COG)) return false;
    if (!(m_estAccSOGPresent == val.m_estAccSOGPresent)) return false;
    if (!(m_estAccSOG == val.m_estAccSOG)) return false;
    if (!(m_estAccCOGPresent == val.m_estAccCOGPresent)) return false;
    if (!(m_estAccCOG == val.m_estAccCOG)) return false;
    if (!(m_idPresent == val.m_idPresent)) return false;
    if (!(m_id == val.m_id)) return false;
    if (!(m_lengthPresent == val.m_lengthPresent)) return false;
    if (!(m_length == val.m_length)) return false;
    if (!(m_headingPresent == val.m_headingPresent)) return false;
    if (!(m_heading == val.m_heading)) return false;
    if (!(m_ROTPresent == val.m_ROTPresent)) return false;
    if (!(m_ROT == val.m_ROT)) return false;
    if (!(m_SOGPresent == val.m_SOGPresent)) return false;
    if (!(m_SOG == val.m_SOG)) return false;
    if (!(m_sourceIdPresent == val.m_sourceIdPresent)) return false;
    if (!(m_sourceId == val.m_sourceId)) return false;
    if (!(m_sourceNamePresent == val.m_sourceNamePresent)) return false;
    if (!(m_sourceName == val.m_sourceName)) return false;
    if (!(m_updateTimePresent == val.m_updateTimePresent)) return false;
    if (!(m_updateTime == val.m_updateTime)) return false;
    if (!(m_trackStatusPresent == val.m_trackStatusPresent)) return false;
    if (!(m_trackStatus == val.m_trackStatus)) return false;
    if (!(m_widthPresent == val.m_widthPresent)) return false;
    if (!(m_width == val.m_width)) return false;
    return true;
}

// assignement
TrackData & TrackData::operator=(const TrackData &val) {

    m_poss = val.m_poss;
    m_navStatuss = val.m_navStatuss;
    m_COGPresent = val.m_COGPresent;
    m_COG = val.m_COG;
    m_estAccSOGPresent = val.m_estAccSOGPresent;
    m_estAccSOG = val.m_estAccSOG;
    m_estAccCOGPresent = val.m_estAccCOGPresent;
    m_estAccCOG = val.m_estAccCOG;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_headingPresent = val.m_headingPresent;
    m_heading = val.m_heading;
    m_ROTPresent = val.m_ROTPresent;
    m_ROT = val.m_ROT;
    m_SOGPresent = val.m_SOGPresent;
    m_SOG = val.m_SOG;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_trackStatusPresent = val.m_trackStatusPresent;
    m_trackStatus = val.m_trackStatus;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for TrackData
bool TrackData::removePos(const Pos& val) {

    if (m_poss.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_poss.removeOne(val);
}

// setter for TrackData
bool TrackData::addPos(const Pos& val) {

    m_poss.append(val);
    m_changed = true;
    return true;
}

// getter for TrackData
const Pos& TrackData::getPosAt(int i) const {

    return m_poss.at(i);
}

// count for TrackData
int TrackData::countOfPoss() const {

    return m_poss.count();
}

// remover for TrackData
bool TrackData::removeNavStatus(const NavStatus& val) {

    if (m_navStatuss.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_navStatuss.removeOne(val);
}

// setter for TrackData
bool TrackData::addNavStatus(const NavStatus& val) {

    m_navStatuss.append(val);
    m_changed = true;
    return true;
}

// getter for TrackData
const NavStatus& TrackData::getNavStatusAt(int i) const {

    return m_navStatuss.at(i);
}

// count for TrackData
int TrackData::countOfNavStatuss() const {

    return m_navStatuss.count();
}

// setter for TrackData
bool TrackData::setCOG(float val) {

    // check if the new value is within min inclusive
    if (val < 0)
        return false;
    // check if the new value is within max inclusive
    if (val > 360)
        return false;
    m_COGPresent = true;
    m_COG = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getCOG() const {

    return m_COG;
}

// setter for TrackData
bool TrackData::setEstAccSOG(float val) {

    m_estAccSOGPresent = true;
    m_estAccSOG = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getEstAccSOG() const {

    return m_estAccSOG;
}

// check if optional element TrackData has been set
bool TrackData::hasEstAccSOG() const {

    return m_estAccSOGPresent;
}

// setter for TrackData
bool TrackData::setEstAccCOG(float val) {

    m_estAccCOGPresent = true;
    m_estAccCOG = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getEstAccCOG() const {

    return m_estAccCOG;
}

// check if optional element TrackData has been set
bool TrackData::hasEstAccCOG() const {

    return m_estAccCOGPresent;
}

// setter for TrackData
bool TrackData::setId(int val) {

    m_idPresent = true;
    m_id = val;
    m_changed = true;
    return true;
}

// getter for TrackData
int TrackData::getId() const {

    return m_id;
}

// setter for TrackData
bool TrackData::setLength(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_lengthPresent = true;
    m_length = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getLength() const {

    return m_length;
}

// check if optional element TrackData has been set
bool TrackData::hasLength() const {

    return m_lengthPresent;
}

// setter for TrackData
bool TrackData::setHeading(float val) {

    // check if the new value is within min inclusive
    if (val < 0)
        return false;
    // check if the new value is within max inclusive
    if (val > 360)
        return false;
    m_headingPresent = true;
    m_heading = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getHeading() const {

    return m_heading;
}

// check if optional element TrackData has been set
bool TrackData::hasHeading() const {

    return m_headingPresent;
}

// setter for TrackData
bool TrackData::setROT(float val) {

    // check if the new value is within min exclusive
    if (val <= -720)
        return false;
    // check if the new value is within max inclusive
    if (val > 720)
        return false;
    m_ROTPresent = true;
    m_ROT = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getROT() const {

    return m_ROT;
}

// check if optional element TrackData has been set
bool TrackData::hasROT() const {

    return m_ROTPresent;
}

// setter for TrackData
bool TrackData::setSOG(float val) {

    // check if the new value is within min inclusive
    if (val < 0)
        return false;
    m_SOGPresent = true;
    m_SOG = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getSOG() const {

    return m_SOG;
}

// setter for TrackData
bool TrackData::setSourceId(QString val) {

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

// getter for TrackData
QString TrackData::getSourceId() const {

    return m_sourceId;
}

// check if optional element TrackData has been set
bool TrackData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for TrackData
bool TrackData::setSourceName(QString val) {

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

// getter for TrackData
QString TrackData::getSourceName() const {

    return m_sourceName;
}

// setter for TrackData
bool TrackData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
    m_changed = true;
    return true;
}

// getter for TrackData
QDateTime TrackData::getUpdateTime() const {

    return m_updateTime;
}

// setter for TrackData
bool TrackData::setTrackStatus(int val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_trackStatusPresent = true;
    m_trackStatus = val;
    m_changed = true;
    return true;
}

// getter for TrackData
int TrackData::getTrackStatus() const {

    return m_trackStatus;
}

// setter for TrackData
bool TrackData::setWidth(float val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    m_widthPresent = true;
    m_width = val;
    m_changed = true;
    return true;
}

// getter for TrackData
float TrackData::getWidth() const {

    return m_width;
}

// check if optional element TrackData has been set
bool TrackData::hasWidth() const {

    return m_widthPresent;
}

// Get XML Representation
const QString& TrackData::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<TrackData";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_COGPresent) {
            xml.append(" COG=\"" + QString::number(m_COG, 'f', 1) + endAttr);
        } else { // required attribute not present
            m_lastError = "COG not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasEstAccSOG() ) {
                xml.append(" EstAccSOG=\"" + QString::number( m_estAccSOG, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasEstAccCOG() ) {
                xml.append(" EstAccCOG=\"" + QString::number( m_estAccCOG, 'f') + endAttr);
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
            if ( hasLength() ) {
                xml.append(" Length=\"" + QString::number( m_length, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasHeading() ) {
                xml.append(" Heading=\"" + QString::number( m_heading, 'f') + endAttr);
        }
            // check for presence of optional attribute
            if ( hasROT() ) {
                xml.append(" ROT=\"" + QString::number(m_ROT, 'f', 1) + endAttr);
        }
            // check for presence of required  attribute
        if ( m_SOGPresent) {
            xml.append(" SOG=\"" + QString::number(m_SOG, 'f', 1) + endAttr);
        } else { // required attribute not present
            m_lastError = "SOG not set";
            m_store  = QString::null;
            return m_store;
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
        if ( m_updateTimePresent) {
            xml.append(" UpdateTime=\"" + dateToString( m_updateTime) + endAttr);
        } else { // required attribute not present
            m_lastError = "UpdateTime not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_trackStatusPresent) {
            xml.append(" TrackStatus=\"" + QString::number( m_trackStatus ) + endAttr);
        } else { // required attribute not present
            m_lastError = "TrackStatus not set";
            m_store  = QString::null;
            return m_store;
        }
            // check for presence of optional attribute
            if ( hasWidth() ) {
                xml.append(" Width=\"" + QString::number( m_width, 'f') + endAttr);
        }
        xml.append(">\n");
        if (m_poss.count() < 0) {
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
        if (m_navStatuss.count() < 0) {
            m_lastError = "not enough NavStatus values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_navStatuss.count(); i++ ) {
            NavStatus attribute = m_navStatuss.at(i);
            dataMember = attribute.toXML(false);
            if (dataMember != QString::null) {
               xml.append( dataMember );
            } else {
                m_lastError = "NavStatus:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</TrackData>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString TrackData::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString TrackData::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "TrackData\n";
    str.append( lead + "    COG = " + QString::number(m_COG, 'f', 1) + endAttr);
    // check for presence of optional attribute
    if ( hasEstAccSOG() ) {
        str.append( lead + "    EstAccSOG = " + QString::number( m_estAccSOG, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasEstAccCOG() ) {
        str.append( lead + "    EstAccCOG = " + QString::number( m_estAccCOG, 'f') + endAttr);
    }
    str.append( lead + "    Id = " + QString::number( m_id ) + endAttr);
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number( m_length, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasHeading() ) {
        str.append( lead + "    Heading = " + QString::number( m_heading, 'f') + endAttr);
    }
    // check for presence of optional attribute
    if ( hasROT() ) {
        str.append( lead + "    ROT = " + QString::number(m_ROT, 'f', 1) + endAttr);
    }
    str.append( lead + "    SOG = " + QString::number(m_SOG, 'f', 1) + endAttr);
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + endAttr);
    }
    str.append( lead + "    SourceName = " + m_sourceName + endAttr);
    str.append( lead + "    UpdateTime = " + dateToString( m_updateTime) + endAttr);
    str.append( lead + "    TrackStatus = " + QString::number( m_trackStatus ) + endAttr);
    // check for presence of optional attribute
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number( m_width, 'f') + endAttr);
    }
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_navStatuss.count(); i++ ) {
        NavStatus attribute = m_navStatuss.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& TrackData::lastError() const {
    return m_lastError;
}

const bool& TrackData::changed() const {
    return m_changed;
}

const QString& TrackData::store() const {
    return m_store;
}


} //end ns
