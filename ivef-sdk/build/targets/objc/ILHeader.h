/* 
 *  ILHeader
 *
 *  ILHeader is free software: you can redistribute it and/or modify
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

#import <Foundation/Foundation.h>

//-----------------------------------------------------------
//! \brief       Class definition of ILHeader
//!
//! HEADER part of every message with version and uniqueness information
//!

@interface ILHeader : NSObject { 
    NSString *m_msgRefId;
    BOOL m_msgRefIdPresent;
    NSString *m_version;
    BOOL m_versionPresent;
}


/* MsgRefId:
   Must be an Universally Unique Identifier for each message  (TU-T Rec. X.667 | ISO/IEC 9834-8.) Reply messages refer to this id to identify the message they are replying to. In its canonical form, a UUID consists of 32 hexadecimal digits, displayed in 5 groups separated by hyphens, in the form 8-4-4-4-12 for a total of 36 characters, enclosed by brackets. For example:
   {550e8400-e29b-41d4-a716-446655440000} */
//!Setter for MsgRefId
//!
-(BOOL) setMsgRefId:(NSString *) val;
//!Getter for MsgRefId
//!
-(NSString *) msgRefId;

/* Version:
   Defines the version of the protocol used. Syntax is major.minor.patch patch releases fix only bugs, minor releases may add functionality but are compatible, major releases are not compatible */
//!Getter for Version
//!
-(NSString *) version;
//!Set attributes by providing a key/value dictionary
//!

-(BOOL) setAttributes:(NSDictionary *)attributeDict;
//!Get attributes as a key/value dictionary
//!
-(NSDictionary *) attributes;
//!Get a XML representation of this class
//!returns nil if not all required fields are set
//!
-(NSString *) XML;
//!Get a string representation of this class
//!
-(NSString *) stringValue;
-(NSString *) stringValueWithLead:(NSString *) lead;
//!Helper routine to encode any string to an XML escaped string
//!
-(NSString *) encode: (NSString *) input;

@end



