/* 
 *  ILVesselData
 *
 *  ILVesselData is free software: you can redistribute it and/or modify
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
#import "ILConstruction.h"
#import "ILIdentifier.h"

//-----------------------------------------------------------
//! \brief       Class definition of ILVesselData
//!
//! DATA regarding static elements of an object
//!

@interface ILVesselData : NSObject { 
    ILConstruction *m_construction;
    BOOL m_constructionPresent;
    ILIdentifier *m_identifier;
    BOOL m_identifierPresent;
    int m_class;
    BOOL m_classPresent;
    BOOL m_blackListed;
    BOOL m_blackListedPresent;
    int m_id;
    BOOL m_idPresent;
    NSString *m_specialAttention;
    BOOL m_specialAttentionPresent;
    NSString *m_sourceId;
    BOOL m_sourceIdPresent;
    NSString *m_sourceName;
    BOOL m_sourceNamePresent;
    int m_sourceType;
    BOOL m_sourceTypePresent;
    NSDate *m_updateTime;
    BOOL m_updateTimePresent;
}


/* Construction:
   attributes of the object regarding the physical construction */
//!Setter for Construction
//!
-(BOOL) setConstruction:(ILConstruction *) val;
//!Getter for Construction
//!
-(ILConstruction *) construction;
//!Test for pressence of Construction
//!
-(BOOL) hasConstruction;

/* Identifier:
   (local) Identification of vessel */
//!Setter for Identifier
//!
-(BOOL) setIdentifier:(ILIdentifier *) val;
//!Getter for Identifier
//!
-(ILIdentifier *) identifier;
//!Test for pressence of Identifier
//!
-(BOOL) hasIdentifier;

/* Class:
   0 = Unknown
   1 = Vessel
   2 = Aids to Navigate */
//!Setter for Class
//!
-(BOOL) setClass:(int) val;
//!Getter for Class
//!
-(int) class;
//!Test for pressence of Class
//!
-(BOOL) hasClass;

/* BlackListed:
   Vessel is blacklisted by a NCA */
//!Setter for BlackListed
//!
-(BOOL) setBlackListed:(BOOL) val;
//!Getter for BlackListed
//!
-(BOOL) blackListed;
//!Test for pressence of BlackListed
//!
-(BOOL) hasBlackListed;

/* Id:
   The unique identification of this vesseldata. Valid from first message with TrackStatus!=Terminated to first message with TrackStatus=Terminated */
//!Setter for Id
//!
-(BOOL) setIdent:(int) val;
//!Getter for Id
//!
-(int) ident;

/* SpecialAttention:
   Vessel is under special attention of the NCA or fairway authorities */
//!Setter for SpecialAttention
//!
-(BOOL) setSpecialAttention:(NSString *) val;
//!Getter for SpecialAttention
//!
-(NSString *) specialAttention;
//!Test for pressence of SpecialAttention
//!
-(BOOL) hasSpecialAttention;

/* SourceId:
   Unique identification of the producer  (UN/LOCODE)  in case multiple producers exist on the same LOCODE, the local competent authority can optionally addended this with a local  code (e.g. BE ANR 01 = Antwerp, 01) */
//!Setter for SourceId
//!
-(BOOL) setSourceId:(NSString *) val;
//!Getter for SourceId
//!
-(NSString *) sourceId;
//!Test for pressence of SourceId
//!
-(BOOL) hasSourceId;

/* SourceName:
   Identification of the originator of the data */
//!Setter for SourceName
//!
-(BOOL) setSourceName:(NSString *) val;
//!Getter for SourceName
//!
-(NSString *) sourceName;

/* SourceType:
   Source/originator type: 0 = Unknown, 1 = Transponder, 2 = Database (VTS Plan Server), 3 = Manual (VTS Officer), 4 =  Fused,  5 = External Source */
//!Setter for SourceType
//!
-(BOOL) setSourceType:(int) val;
//!Getter for SourceType
//!
-(int) sourceType;

/* UpdateTime:
   Date and time in UTC format (YYYY-MM-DDThh:mm:ss.sssZ)  (subset of ISO 8601) this data was compiled */
//!Setter for UpdateTime
//!
-(BOOL) setUpdateTime:(NSDate *) val;
//!Getter for UpdateTime
//!
-(NSDate *) updateTime;
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



