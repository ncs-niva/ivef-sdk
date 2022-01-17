/* 
 *  TrackData
 *
 *  TrackData is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY ); without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 **********************************************************************************
 *  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
 *  Generated by schema2code on Mon Jan 17 11:39:43 2022.
 **********************************************************************************
 *  Copyright 2010
 *
 */

#ifndef __TRACKDATA_H__
#define __TRACKDATA_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFPos.h"
#include "IVEFNavStatus.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of TrackData
//!
//! DATA describing a position report of an object
//!
class TrackData : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    TrackData();
    //! constructor for parser function
    //!
    TrackData(XmlStreamReader&);
    //! copy constructor
    //!
    TrackData(const TrackData&);
    //! = operator
    //!
    TrackData & operator=(const TrackData& val);
    //! == operator
    //!
    bool operator==(const TrackData& val);
    //! removes a Pos.
    //!
    bool removePos(const Pos& val);

    //! adds a Pos.
    //!
    bool addPos(const Pos& val);

    //! gets the i-th Pos.
    //!
    const Pos& getPosAt(int i) const;

    //!              return the number of Pos objects.
    //!
    //! \return     int
    int countOfPoss() const;

    //! removes a NavStatus.
    //!
    bool removeNavStatus(const NavStatus& val);

    //! adds a NavStatus.
    //!
    bool addNavStatus(const NavStatus& val);

    //! gets the i-th NavStatus.
    //!
    const NavStatus& getNavStatusAt(int i) const;

    //!              return the number of NavStatus objects.
    //!
    //! \return     int
    int countOfNavStatuss() const;

    //! sets the COG: Course over ground  in degrees. (0-360)
    //!
    bool setCOG(float val);

    //! gets the COG: Course over ground  in degrees. (0-360)
    //!
    //! \return     float
    //!
    float getCOG() const;

    //! sets the EstAccSOG: Estimated accuracy\n
    //! standard deviation of the calculated value \n
    //! expressed in m/s
    //!
    bool setEstAccSOG(float val);

    //! gets the EstAccSOG: Estimated accuracy\n
    //! standard deviation of the calculated value \n
    //! expressed in m/s
    //!
    //! \return     float
    //!
    float getEstAccSOG() const;

    //! returns true if EstAccSOGis used (optional field).
    //!
    //! \return     bool
    bool hasEstAccSOG() const;

    //! sets the EstAccCOG: Estimated accuracy\n
    //! standard deviation of the calculated value \n
    //! expressed in degrees
    //!
    bool setEstAccCOG(float val);

    //! gets the EstAccCOG: Estimated accuracy\n
    //! standard deviation of the calculated value \n
    //! expressed in degrees
    //!
    //! \return     float
    //!
    float getEstAccCOG() const;

    //! returns true if EstAccCOGis used (optional field).
    //!
    //! \return     bool
    bool hasEstAccCOG() const;

    //! sets the Id: The unique identification of this track. Valid from first message with TrackStatus!=Terminated to first message with TrackStatus=Terminated
    //!
    bool setId(int val);

    //! gets the Id: The unique identification of this track. Valid from first message with TrackStatus!=Terminated to first message with TrackStatus=Terminated
    //!
    //! \return     int
    //!
    int getId() const;

    //! sets the Length: Measured length of the target in meter
    //!
    bool setLength(float val);

    //! gets the Length: Measured length of the target in meter
    //!
    //! \return     float
    //!
    float getLength() const;

    //! returns true if Lengthis used (optional field).
    //!
    //! \return     bool
    bool hasLength() const;

    //! sets the Heading: Heading of the target in degrees
    //!
    bool setHeading(float val);

    //! gets the Heading: Heading of the target in degrees
    //!
    //! \return     float
    //!
    float getHeading() const;

    //! returns true if Headingis used (optional field).
    //!
    //! \return     bool
    bool hasHeading() const;

    //! sets the ROT: Rate of turn in degrees per minute
    //!
    bool setROT(float val);

    //! gets the ROT: Rate of turn in degrees per minute
    //!
    //! \return     float
    //!
    float getROT() const;

    //! returns true if ROTis used (optional field).
    //!
    //! \return     bool
    bool hasROT() const;

    //! sets the SOG: Speed over ground in meters per second
    //!
    bool setSOG(float val);

    //! gets the SOG: Speed over ground in meters per second
    //!
    //! \return     float
    //!
    float getSOG() const;

    //! sets the SourceId: Unique identification of the producer  (UN/LOCODE)  in case multiple producers exist on the same LOCODE, the local competent authority can optionally addended this with a local  code (e.g. BE ANR 01 = Antwerp, 01)
    //!
    bool setSourceId(QString val);

    //! gets the SourceId: Unique identification of the producer  (UN/LOCODE)  in case multiple producers exist on the same LOCODE, the local competent authority can optionally addended this with a local  code (e.g. BE ANR 01 = Antwerp, 01)
    //!
    //! \return     QString
    //!
    QString getSourceId() const;

    //! returns true if SourceIdis used (optional field).
    //!
    //! \return     bool
    bool hasSourceId() const;

    //! sets the SourceName: Identification of the originator of the data
    //!
    bool setSourceName(QString val);

    //! gets the SourceName: Identification of the originator of the data
    //!
    //! \return     QString
    //!
    QString getSourceName() const;

    //! sets the UpdateTime: Date and time in UTC format (YYYY-MM-DDThh:mm:ss.sssZ) (subset of ISO 8601)  this position was measured.
    //!
    bool setUpdateTime(QDateTime val);

    //! gets the UpdateTime: Date and time in UTC format (YYYY-MM-DDThh:mm:ss.sssZ) (subset of ISO 8601)  this position was measured.
    //!
    //! \return     QDateTime
    //!
    QDateTime getUpdateTime() const;

    //! sets the TrackStatus: 1 = Updated, (sensors are updating the track)\n
    //! 2 = Coasted, (no sensor is updating the track)\n
    //! 3 = Dropped
    //!
    bool setTrackStatus(int val);

    //! gets the TrackStatus: 1 = Updated, (sensors are updating the track)\n
    //! 2 = Coasted, (no sensor is updating the track)\n
    //! 3 = Dropped
    //!
    //! \return     int
    //!
    int getTrackStatus() const;

    //! sets the Width: Measured Width of the target in meter
    //!
    bool setWidth(float val);

    //! gets the Width: Measured Width of the target in meter
    //!
    //! \return     float
    //!
    float getWidth() const;

    //! returns true if Widthis used (optional field).
    //!
    //! \return     bool
    bool hasWidth() const;

    //! generates XML of this object including attributes and child elements
    //! returns QString::null if not all required elements are available
    //! If null returned check lastError() for problem description
    //!
    //! \return     QString
    const QString& toXML(bool outputNamespace = true);

    //! generates output of this object including attributes and child elements
    //!
    //! \return     QString
    QString toString() const;

    //! generates output of this object including attributes and child elements
    //!
    //! \return     QString
    QString toString(QString lead) const;

    //! return last error found in toXML function
    //!
    //! \return     QString
    const QString& lastError() const;

    //! return changed 
    //!
    //! \return     bool
    const bool& changed() const;

    //! return store 
    //!
    //! \return     QString
    const QString& store() const;


private:
    QList<Pos> m_poss;
    QList<NavStatus> m_navStatuss;
    float m_COG;
    bool m_COGPresent;
    float m_estAccSOG;
    bool m_estAccSOGPresent;
    float m_estAccCOG;
    bool m_estAccCOGPresent;
    int m_id;
    bool m_idPresent;
    float m_length;
    bool m_lengthPresent;
    float m_heading;
    bool m_headingPresent;
    float m_ROT;
    bool m_ROTPresent;
    float m_SOG;
    bool m_SOGPresent;
    QString m_sourceId;
    bool m_sourceIdPresent;
    QString m_sourceName;
    bool m_sourceNamePresent;
    QDateTime m_updateTime;
    bool m_updateTimePresent;
    int m_trackStatus;
    bool m_trackStatusPresent;
    float m_width;
    bool m_widthPresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif