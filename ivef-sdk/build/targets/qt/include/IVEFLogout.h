/* 
 *  Logout
 *
 *  Logout is free software: you can redistribute it and/or modify
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

#ifndef __LOGOUT_H__
#define __LOGOUT_H__

#include <QObject>
#include <QString>
#include <QDateTime>

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of Logout
//!
//! DATA logout message, the server will drop the connection if logout is successfull
//!
class Logout : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    Logout();
    //! constructor for parser function
    //!
    Logout(XmlStreamReader&);
    //! copy constructor
    //!
    Logout(const Logout&);
    //! = operator
    //!
    Logout & operator=(const Logout& val);
    //! == operator
    //!
    bool operator==(const Logout& val);
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
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif
