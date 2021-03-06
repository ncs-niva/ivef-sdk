/* 
 *  ILConstruction
 *
 *  ILConstruction is free software: you can redistribute it and/or modify
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
#import "ILUnType.h"

//-----------------------------------------------------------
//! \brief       Class definition of ILConstruction
//!
//! attributes of the object regarding the physical construction
//!

@interface ILConstruction : NSObject { 
    ILUnType *m_unType;
    BOOL m_unTypePresent;
    NSString *m_hullColor;
    BOOL m_hullColorPresent;
    int m_hullType;
    BOOL m_hullTypePresent;
    float m_deadWeight;
    BOOL m_deadWeightPresent;
    float m_grossWeight;
    BOOL m_grossWeightPresent;
    float m_length;
    BOOL m_lengthPresent;
    int m_lloydsShipType;
    BOOL m_lloydsShipTypePresent;
    int m_yearOfBuild;
    BOOL m_yearOfBuildPresent;
    float m_maxAirDraught;
    BOOL m_maxAirDraughtPresent;
    float m_maxDraught;
    BOOL m_maxDraughtPresent;
    int m_maxPersonsOnBoard;
    BOOL m_maxPersonsOnBoardPresent;
    float m_maxSpeed;
    BOOL m_maxSpeedPresent;
    float m_width;
    BOOL m_widthPresent;
}


/* UnType:
   Object type according to CODES FOR
   						      TYPES OF MEANS OF TRANSPORT Revision 2 (UNECE CEFACT Trade Facilitation
   						      Recommendation No. 28 edition 2007) */
//!Setter for UnType
//!
-(BOOL) setUnType:(ILUnType *) val;
//!Getter for UnType
//!
-(ILUnType *) unType;
//!Test for pressence of UnType
//!
-(BOOL) hasUnType;

/* HullColor:
   Color of Hull (in RGB hex) for SAR operations */
//!Setter for HullColor
//!
-(BOOL) setHullColor:(NSString *) val;
//!Getter for HullColor
//!
-(NSString *) hullColor;
//!Test for pressence of HullColor
//!
-(BOOL) hasHullColor;

/* HullType:
   Type of hull (1 = single,  2 = double, 3 =  triple) */
//!Setter for HullType
//!
-(BOOL) setHullType:(int) val;
//!Getter for HullType
//!
-(int) hullType;
//!Test for pressence of HullType
//!
-(BOOL) hasHullType;

/* DeadWeight:
   Dead weight in tons */
//!Setter for DeadWeight
//!
-(BOOL) setDeadWeight:(float) val;
//!Getter for DeadWeight
//!
-(float) deadWeight;
//!Test for pressence of DeadWeight
//!
-(BOOL) hasDeadWeight;

/* GrossWeight:
   Gross weight in tons */
//!Setter for GrossWeight
//!
-(BOOL) setGrossWeight:(float) val;
//!Getter for GrossWeight
//!
-(float) grossWeight;
//!Test for pressence of GrossWeight
//!
-(BOOL) hasGrossWeight;

/* Length:
   The overall length of the target in meter as confirmed by NCA */
//!Setter for Length
//!
-(BOOL) setLength:(float) val;
//!Getter for Length
//!
-(float) length;
//!Test for pressence of Length
//!
-(BOOL) hasLength;

/* LloydsShipType:
   Number indicating type of vessel */
//!Setter for LloydsShipType
//!
-(BOOL) setLloydsShipType:(int) val;
//!Getter for LloydsShipType
//!
-(int) lloydsShipType;
//!Test for pressence of LloydsShipType
//!
-(BOOL) hasLloydsShipType;

/* YearOfBuild:
   The year the vessel was build in 4 digits e.g. 2010 */
//!Setter for YearOfBuild
//!
-(BOOL) setYearOfBuild:(int) val;
//!Getter for YearOfBuild
//!
-(int) yearOfBuild;
//!Test for pressence of YearOfBuild
//!
-(BOOL) hasYearOfBuild;

/* MaxAirDraught:
   Maximum air draught of the object in meters, to be used if voyage data is not available */
//!Setter for MaxAirDraught
//!
-(BOOL) setMaxAirDraught:(float) val;
//!Getter for MaxAirDraught
//!
-(float) maxAirDraught;
//!Test for pressence of MaxAirDraught
//!
-(BOOL) hasMaxAirDraught;

/* MaxDraught:
   Maximum draught of the object in meters, to be used if voyage data is not available */
//!Setter for MaxDraught
//!
-(BOOL) setMaxDraught:(float) val;
//!Getter for MaxDraught
//!
-(float) maxDraught;
//!Test for pressence of MaxDraught
//!
-(BOOL) hasMaxDraught;

/* MaxPersonsOnBoard:
   The maximum number of persons on board of the object (crew, support, passengers, pilots) */
//!Setter for MaxPersonsOnBoard
//!
-(BOOL) setMaxPersonsOnBoard:(int) val;
//!Getter for MaxPersonsOnBoard
//!
-(int) maxPersonsOnBoard;
//!Test for pressence of MaxPersonsOnBoard
//!
-(BOOL) hasMaxPersonsOnBoard;

/* MaxSpeed:
   The maximum speed the object is able to sustain with normal draft and load */
//!Setter for MaxSpeed
//!
-(BOOL) setMaxSpeed:(float) val;
//!Getter for MaxSpeed
//!
-(float) maxSpeed;
//!Test for pressence of MaxSpeed
//!
-(BOOL) hasMaxSpeed;

/* Width:
   Overall width of the target in meter as confirmed by the NCA */
//!Setter for Width
//!
-(BOOL) setWidth:(float) val;
//!Getter for Width
//!
-(float) width;
//!Test for pressence of Width
//!
-(BOOL) hasWidth;
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



