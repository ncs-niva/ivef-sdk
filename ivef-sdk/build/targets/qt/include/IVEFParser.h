/* 
 *  Parser
 *
 *  Parser is free software: you can redistribute it and/or modify
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

#ifndef __PARSER_H__
#define __PARSER_H__

#include "IVEFMSG_IVEF.h"
class XmlStreamReader;

namespace ivef {

//-----------------------------------------------------------
//! \brief       Class definition of Parser
//!
class Parser : public QObject { 
    Q_OBJECT

public:
    //!constructor
    //!
    Parser();
    //!the actual parse routine
    //!
    bool parseXMLString(QString data, bool cont);

signals:
    //!signals fired by the parser when a new object has been parsed
    //!
    void signalMSG_IVEF( const ivef::MSG_IVEF& obj );
    //!signals fired by the parser when a parser problem occured
    //!
    void signalError(const QString& errorStr);
    void signalWarning(const QString& errorStr);
    void signalValidationError(const QString& errorStr);

private:
    void parse();
    XmlStreamReader* m_xml;

};
} //end ns

#endif
