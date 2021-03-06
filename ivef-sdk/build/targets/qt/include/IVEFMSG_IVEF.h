/* 
 *  MSG_IVEF
 *
 *  MSG_IVEF is free software: you can redistribute it and/or modify
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

#ifndef __MSG_IVEF_H__
#define __MSG_IVEF_H__

#include <QObject>
#include <QString>
#include <QDateTime>
#include "IVEFHeader.h"
#include "IVEFBody.h"

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of MSG_IVEF
//!
//! Root MESSAGE
//!
class MSG_IVEF : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    MSG_IVEF();
    //! constructor for parser function
    //!
    MSG_IVEF(XmlStreamReader&);
    //! copy constructor
    //!
    MSG_IVEF(const MSG_IVEF&);
    //! = operator
    //!
    MSG_IVEF & operator=(const MSG_IVEF& val);
    //! == operator
    //!
    bool operator==(const MSG_IVEF& val);
    //! sets the Header
    //!
    bool setHeader(const Header& val);

    //! gets the Header
    //!
    //! \return     Header
    //!
    const Header& getHeader() const;

    //! sets the Body
    //!
    bool setBody(const Body& val);

    //! gets the Body
    //!
    //! \return     Body
    //!
    const Body& getBody() const;

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
    Header m_header;
    bool m_headerPresent;
    Body m_body;
    bool m_bodyPresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif
