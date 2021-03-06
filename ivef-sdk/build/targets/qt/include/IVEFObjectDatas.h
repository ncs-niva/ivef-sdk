/* 
 *  ObjectDatas
 *
 *  ObjectDatas is free software: you can redistribute it and/or modify
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

#ifndef __OBJECTDATAS_H__
#define __OBJECTDATAS_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFObjectData.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of ObjectDatas
//!
//! 
//!
class ObjectDatas : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    ObjectDatas();
    //! constructor for parser function
    //!
    ObjectDatas(XmlStreamReader&);
    //! copy constructor
    //!
    ObjectDatas(const ObjectDatas&);
    //! = operator
    //!
    ObjectDatas & operator=(const ObjectDatas& val);
    //! == operator
    //!
    bool operator==(const ObjectDatas& val);
    //! removes a ObjectData.
    //!
    bool removeObjectData(const ObjectData& val);

    //! adds a ObjectData.
    //!
    bool addObjectData(const ObjectData& val);

    //! gets the i-th ObjectData.
    //!
    const ObjectData& getObjectDataAt(int i) const;

    //!              return the number of ObjectData objects.
    //!
    //! \return     int
    int countOfObjectDatas() const;

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
    QList<ObjectData> m_objectDatas;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif
