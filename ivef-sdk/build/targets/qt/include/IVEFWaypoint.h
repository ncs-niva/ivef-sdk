/* 
 *  Waypoint
 *
 *  Waypoint is free software: you can redistribute it and/or modify
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

#ifndef __WAYPOINT_H__
#define __WAYPOINT_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFPos.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of Waypoint
//!
//! Waypoint belonging to the route of this voyage
//!
class Waypoint : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    Waypoint();
    //! constructor for parser function
    //!
    Waypoint(XmlStreamReader&);
    //! copy constructor
    //!
    Waypoint(const Waypoint&);
    //! = operator
    //!
    Waypoint & operator=(const Waypoint& val);
    //! == operator
    //!
    bool operator==(const Waypoint& val);
    //! sets the Pos
    //!
    bool setPos(const Pos& val);

    //! gets the Pos
    //!
    //! \return     Pos
    //!
    const Pos& getPos() const;

    //! returns true if Posis used (optional field).
    //!
    //! \return     bool
    bool hasPos() const;

    //! sets the ATA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601 ) of the Actual Time Of Arrival of the target.
    //!
    bool setATA(QDateTime val);

    //! gets the ATA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601 ) of the Actual Time Of Arrival of the target.
    //!
    //! \return     QDateTime
    //!
    QDateTime getATA() const;

    //! returns true if ATAis used (optional field).
    //!
    //! \return     bool
    bool hasATA() const;

    //! sets the ETA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601) of the Expected Time Of Arrival of the target.
    //!
    bool setETA(QDateTime val);

    //! gets the ETA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601) of the Expected Time Of Arrival of the target.
    //!
    //! \return     QDateTime
    //!
    QDateTime getETA() const;

    //! returns true if ETAis used (optional field).
    //!
    //! \return     bool
    bool hasETA() const;

    //! sets the RTA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601) of the Requested Time Of Arrival of the target.
    //!
    bool setRTA(QDateTime val);

    //! gets the RTA: Date and time in UTC format (YYYY-MM-DDThh:mmZ) (subset of ISO 8601) of the Requested Time Of Arrival of the target.
    //!
    //! \return     QDateTime
    //!
    QDateTime getRTA() const;

    //! returns true if RTAis used (optional field).
    //!
    //! \return     bool
    bool hasRTA() const;

    //! sets the LoCode: Waypoint name in UN/LOCODE optionally addended with local location code (e.g. BEANR0170100497 = Antwerp, HANSADOK 497)
    //!
    bool setLoCode(QString val);

    //! gets the LoCode: Waypoint name in UN/LOCODE optionally addended with local location code (e.g. BEANR0170100497 = Antwerp, HANSADOK 497)
    //!
    //! \return     QString
    //!
    QString getLoCode() const;

    //! returns true if LoCodeis used (optional field).
    //!
    //! \return     bool
    bool hasLoCode() const;

    //! sets the Name: Name of the waypoint
    //!
    bool setName(QString val);

    //! gets the Name: Name of the waypoint
    //!
    //! \return     QString
    //!
    QString getName() const;

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
    Pos m_pos;
    bool m_posPresent;
    QDateTime m_ATA;
    bool m_ATAPresent;
    QDateTime m_ETA;
    bool m_ETAPresent;
    QDateTime m_RTA;
    bool m_RTAPresent;
    QString m_loCode;
    bool m_loCodePresent;
    QString m_name;
    bool m_namePresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif
