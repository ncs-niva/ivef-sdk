/* 
 *  ServiceRequest
 *
 *  ServiceRequest is free software: you can redistribute it and/or modify
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

#ifndef __SERVICEREQUEST_H__
#define __SERVICEREQUEST_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFArea.h"
#include "IVEFTransmission.h"
#include "IVEFItem.h"
#include "IVEFFilter.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of ServiceRequest
//!
//! DATA describing the service a user requests
//!
class ServiceRequest : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    ServiceRequest();
    //! constructor for parser function
    //!
    ServiceRequest(XmlStreamReader&);
    //! copy constructor
    //!
    ServiceRequest(const ServiceRequest&);
    //! = operator
    //!
    ServiceRequest & operator=(const ServiceRequest& val);
    //! == operator
    //!
    bool operator==(const ServiceRequest& val);
    //! removes a Area.
    //!
    bool removeArea(const Area& val);

    //! adds a Area.
    //!
    bool addArea(const Area& val);

    //! gets the i-th Area.
    //!
    const Area& getAreaAt(int i) const;

    //!              return the number of Area objects.
    //!
    //! \return     int
    int countOfAreas() const;

    //! sets the Transmission
    //!
    bool setTransmission(const Transmission& val);

    //! gets the Transmission
    //!
    //! \return     Transmission
    //!
    const Transmission& getTransmission() const;

    //! removes a Item.
    //!
    bool removeItem(const Item& val);

    //! adds a Item.
    //!
    bool addItem(const Item& val);

    //! gets the i-th Item.
    //!
    const Item& getItemAt(int i) const;

    //!              return the number of Item objects.
    //!
    //! \return     int
    int countOfItems() const;

    //! sets the Filter
    //!
    bool setFilter(const Filter& val);

    //! gets the Filter
    //!
    //! \return     Filter
    //!
    const Filter& getFilter() const;

    //! returns true if Filteris used (optional field).
    //!
    //! \return     bool
    bool hasFilter() const;

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
    QList<Area> m_areas;
    Transmission m_transmission;
    bool m_transmissionPresent;
    QList<Item> m_items;
    Filter m_filter;
    bool m_filterPresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif