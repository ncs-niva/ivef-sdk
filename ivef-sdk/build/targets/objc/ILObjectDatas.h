/* 
 *  ILObjectDatas
 *
 *  ILObjectDatas is free software: you can redistribute it and/or modify
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
#import "ILObjectData.h"

//-----------------------------------------------------------
//! \brief       Class definition of ILObjectDatas
//!
//! 
//!

@interface ILObjectDatas : NSObject { 
    NSMutableArray *m_objectDatas;
    BOOL m_objectDataPresent;
}


/* ObjectData:
   MESSAGE sent by the supplier containing data regarding objects in its domain */
//!Remover for ObjectData
//!
-(BOOL) removeObjectData:(ILObjectData *) val;
//!Setter for ObjectData
//!
-(BOOL) addObjectData:(ILObjectData *) val;
//!Getter for ObjectData
//!
-(ILObjectData *) objectDataAt:(int) i;
//!Element counter for ObjectData
//!
-(int) countOfObjectDatas;
//!Get all elements for ObjectData
//!
-(NSArray *) objectDatas;
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



