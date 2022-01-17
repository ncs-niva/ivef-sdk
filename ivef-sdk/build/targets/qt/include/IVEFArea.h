/* 
 *  Area
 *
 *  Area is free software: you can redistribute it and/or modify
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

#ifndef __AREA_H__
#define __AREA_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFPos.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of Area
//!
//! Geographical location based on one or more polygons
//!
class Area : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    Area();
    //! constructor for parser function
    //!
    Area(XmlStreamReader&);
    //! copy constructor
    //!
    Area(const Area&);
    //! = operator
    //!
    Area & operator=(const Area& val);
    //! == operator
    //!
    bool operator==(const Area& val);
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

    //! sets the Name: Name of the area
    //!
    bool setName(QString val);

    //! gets the Name: Name of the area
    //!
    //! \return     QString
    //!
    QString getName() const;

    //! returns true if Nameis used (optional field).
    //!
    //! \return     bool
    bool hasName() const;

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
    QString m_name;
    bool m_namePresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif
