/* 
 *  LoginRequest
 *
 *  LoginRequest is free software: you can redistribute it and/or modify
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

#ifndef __LOGINREQUEST_H__
#define __LOGINREQUEST_H__

#include <QObject>
#include <QString>
#include <QDateTime>

class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of LoginRequest
//!
//! DATA login message with details of the user
//!
class LoginRequest : public QObject { 
    Q_OBJECT

public:
    //! constructor
    //!
    LoginRequest();
    //! constructor for parser function
    //!
    LoginRequest(XmlStreamReader&);
    //! copy constructor
    //!
    LoginRequest(const LoginRequest&);
    //! = operator
    //!
    LoginRequest & operator=(const LoginRequest& val);
    //! == operator
    //!
    bool operator==(const LoginRequest& val);
    //! sets the Encryption: 1 = plain 2 - 6 the 5 most common encryption 0 = custom
    //!
    bool setEncryption(int val);

    //! gets the Encryption: 1 = plain 2 - 6 the 5 most common encryption 0 = custom
    //!
    //! \return     int
    //!
    int getEncryption() const;

    //! sets the Name: Login name
    //!
    bool setName(QString val);

    //! gets the Name: Login name
    //!
    //! \return     QString
    //!
    QString getName() const;

    //! sets the Password: Password value
    //!
    bool setPassword(QString val);

    //! gets the Password: Password value
    //!
    //! \return     QString
    //!
    QString getPassword() const;

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
    int m_encryption;
    bool m_encryptionPresent;
    QString m_name;
    bool m_namePresent;
    QString m_password;
    bool m_passwordPresent;
    QString m_lastError; 
    bool m_changed; 
    QString m_store;
}; 
} //end ns

#endif