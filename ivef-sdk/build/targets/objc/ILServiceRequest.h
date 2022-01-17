/* 
 *  ILServiceRequest
 *
 *  ILServiceRequest is free software: you can redistribute it and/or modify
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
#import "ILArea.h"
#import "ILTransmission.h"
#import "ILItem.h"
#import "ILFilter.h"

//-----------------------------------------------------------
//! \brief       Class definition of ILServiceRequest
//!
//! DATA describing the service a user requests
//!

@interface ILServiceRequest : NSObject { 
    NSMutableArray *m_areas;
    BOOL m_areaPresent;
    ILTransmission *m_transmission;
    BOOL m_transmissionPresent;
    NSMutableArray *m_items;
    BOOL m_itemPresent;
    ILFilter *m_filter;
    BOOL m_filterPresent;
}

//!Remover for Area
//!
-(BOOL) removeArea:(ILArea *) val;
//!Setter for Area
//!
-(BOOL) addArea:(ILArea *) val;
//!Getter for Area
//!
-(ILArea *) areaAt:(int) i;
//!Element counter for Area
//!
-(int) countOfAreas;
//!Get all elements for Area
//!
-(NSArray *) areas;
//!Setter for Transmission
//!
-(BOOL) setTransmission:(ILTransmission *) val;
//!Getter for Transmission
//!
-(ILTransmission *) transmission;
//!Remover for Item
//!
-(BOOL) removeItem:(ILItem *) val;
//!Setter for Item
//!
-(BOOL) addItem:(ILItem *) val;
//!Getter for Item
//!
-(ILItem *) itemAt:(int) i;
//!Element counter for Item
//!
-(int) countOfItems;
//!Get all elements for Item
//!
-(NSArray *) items;
//!Setter for Filter
//!
-(BOOL) setFilter:(ILFilter *) val;
//!Getter for Filter
//!
-(ILFilter *) filter;
//!Test for pressence of Filter
//!
-(BOOL) hasFilter;
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


