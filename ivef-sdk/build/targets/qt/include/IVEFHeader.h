/* 
 *  Header
 *
 *  Header is free software: you can redistribute it and/or modify
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

#ifndef __HEADER_H__
#define __HEADER_H__

#include <QObject>
#include <QString>
#include <QDateTime>

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of Header
//!
//! HEADER part of every message with version and uniqueness information
//!
class Header : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    Header();
    //! constructor for parser function
    //!
    Header(XmlStreamReader&);
    //! copy constructor
    //!
    Header(const Header&);
    //! = operator
    //!
    Header & operator=(const Header& val);
    //! == operator
    //!
    bool operator==(const Header& val);
    //! sets the MsgRefId: Must be an Universally Unique Identifier for each message  (TU-T Rec. X.667 | ISO/IEC 9834-8.) Reply messages refer to this id to identify the message they are replying to. In its canonical form, a UUID consists of 32 hexadecimal digits, displayed in 5 groups separated by hyphens, in the form 8-4-4-4-12 for a total of 36 characters, enclosed by brackets. For example:\n
    //! {550e8400-e29b-41d4-a716-446655440000}
    //!
    bool setMsgRefId(QString val);

    //! gets the MsgRefId: Must be an Universally Unique Identifier for each message  (TU-T Rec. X.667 | ISO/IEC 9834-8.) Reply messages refer to this id to identify the message they are replying to. In its canonical form, a UUID consists of 32 hexadecimal digits, displayed in 5 groups separated by hyphens, in the form 8-4-4-4-12 for a total of 36 characters, enclosed by brackets. For example:\n
    //! {550e8400-e29b-41d4-a716-446655440000}
    //!
    //! \return     QString
    //!
    QString getMsgRefId() const;

    //! sets the Version: Defines the version of the protocol used. Syntax is major.minor.patch patch releases fix only bugs, minor releases may add functionality but are compatible, major releases are not compatible
    //!
    bool setVersion(QString val);

    //! gets the Version: Defines the version of the protocol used. Syntax is major.minor.patch patch releases fix only bugs, minor releases may add functionality but are compatible, major releases are not compatible
    //!
    //! \return     QString
    //!
    QString getVersion() const;

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
    QString m_msgRefId;
    bool m_msgRefIdPresent;
    QString m_version;
    bool m_versionPresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif