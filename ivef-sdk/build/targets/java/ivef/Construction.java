/* 
 *  Construction
 *
 *  Construction is free software: you can redistribute it and/or modify
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

package ivef;

import java.util.*;
import java.text.DecimalFormat;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

import ivef.UnType;

public class Construction { 

    private UnType m_unType; // default value is uninitialized
    private boolean m_unTypePresent;
    private String m_hullColor; // default value is uninitialized
    private boolean m_hullColorPresent;
    private int m_hullType; // default value is uninitialized
    private boolean m_hullTypePresent;
    private double m_deadWeight; // default value is uninitialized
    private boolean m_deadWeightPresent;
    private double m_grossWeight; // default value is uninitialized
    private boolean m_grossWeightPresent;
    private double m_length; // default value is uninitialized
    private boolean m_lengthPresent;
    private int m_lloydsShipType; // default value is uninitialized
    private boolean m_lloydsShipTypePresent;
    private int m_yearOfBuild; // default value is uninitialized
    private boolean m_yearOfBuildPresent;
    private double m_maxAirDraught; // default value is uninitialized
    private boolean m_maxAirDraughtPresent;
    private double m_maxDraught; // default value is uninitialized
    private boolean m_maxDraughtPresent;
    private int m_maxPersonsOnBoard; // default value is uninitialized
    private boolean m_maxPersonsOnBoardPresent;
    private double m_maxSpeed; // default value is uninitialized
    private boolean m_maxSpeedPresent;
    private double m_width; // default value is uninitialized
    private boolean m_widthPresent;

    public Construction() {

        m_unTypePresent = false;
        m_hullColorPresent = false;
        m_hullTypePresent = false;
        m_deadWeightPresent = false;
        m_grossWeightPresent = false;
        m_lengthPresent = false;
        m_lloydsShipTypePresent = false;
        m_yearOfBuildPresent = false;
        m_maxAirDraughtPresent = false;
        m_maxDraughtPresent = false;
        m_maxPersonsOnBoardPresent = false;
        m_maxSpeedPresent = false;
        m_widthPresent = false;
    }

    public Construction(Construction val) {

        m_unType = val.getUnType();
        if (val != null) {
            m_unTypePresent = true;
        }
        m_hullColor = val.getHullColor();
        if (val != null) {
            m_hullColorPresent = true;
        }
        m_hullType = val.getHullType();
        if (val != null) {
            m_hullTypePresent = true;
        }
        m_deadWeight = val.getDeadWeight();
        if (val != null) {
            m_deadWeightPresent = true;
        }
        m_grossWeight = val.getGrossWeight();
        if (val != null) {
            m_grossWeightPresent = true;
        }
        m_length = val.getLength();
        if (val != null) {
            m_lengthPresent = true;
        }
        m_lloydsShipType = val.getLloydsShipType();
        if (val != null) {
            m_lloydsShipTypePresent = true;
        }
        m_yearOfBuild = val.getYearOfBuild();
        if (val != null) {
            m_yearOfBuildPresent = true;
        }
        m_maxAirDraught = val.getMaxAirDraught();
        if (val != null) {
            m_maxAirDraughtPresent = true;
        }
        m_maxDraught = val.getMaxDraught();
        if (val != null) {
            m_maxDraughtPresent = true;
        }
        m_maxPersonsOnBoard = val.getMaxPersonsOnBoard();
        if (val != null) {
            m_maxPersonsOnBoardPresent = true;
        }
        m_maxSpeed = val.getMaxSpeed();
        if (val != null) {
            m_maxSpeedPresent = true;
        }
        m_width = val.getWidth();
        if (val != null) {
            m_widthPresent = true;
        }
    }

    public boolean setUnType(UnType val) {

        m_unTypePresent = true;
        m_unType = val;
        return true;
    }

    public UnType getUnType() {

        return m_unType;
    }

    public boolean hasUnType() {

        return m_unTypePresent;
    }

    public boolean setHullColor(String val) {

        if (val.length() < 6)
          return false;
        if (val.length() > 6)
          return false;
        m_hullColorPresent = true;
        m_hullColor = val;
        return true;
    }

    public String getHullColor() {

        return m_hullColor;
    }

    public boolean hasHullColor() {

        return m_hullColorPresent;
    }

    public boolean setHullType(int val) {

        if ( ( val != 1 ) &&
             ( val != 2 ) &&
             ( val != 3 ) )
            return false;
        m_hullTypePresent = true;
        m_hullType = val;
        return true;
    }

    public int getHullType() {

        return m_hullType;
    }

    public boolean hasHullType() {

        return m_hullTypePresent;
    }

    public boolean setDeadWeight(double val) {

        if (val <= 0)
          return false;
        m_deadWeightPresent = true;
        m_deadWeight = val;
        return true;
    }

    public double getDeadWeight() {

        return m_deadWeight;
    }

    public boolean hasDeadWeight() {

        return m_deadWeightPresent;
    }

    public boolean setGrossWeight(double val) {

        if (val <= 0)
          return false;
        m_grossWeightPresent = true;
        m_grossWeight = val;
        return true;
    }

    public double getGrossWeight() {

        return m_grossWeight;
    }

    public boolean hasGrossWeight() {

        return m_grossWeightPresent;
    }

    public boolean setLength(double val) {

        if (val <= 0)
          return false;
        m_lengthPresent = true;
        m_length = val;
        return true;
    }

    public double getLength() {

        return m_length;
    }

    public boolean hasLength() {

        return m_lengthPresent;
    }

    public boolean setLloydsShipType(int val) {

        m_lloydsShipTypePresent = true;
        m_lloydsShipType = val;
        return true;
    }

    public int getLloydsShipType() {

        return m_lloydsShipType;
    }

    public boolean hasLloydsShipType() {

        return m_lloydsShipTypePresent;
    }

    public boolean setYearOfBuild(int val) {

        m_yearOfBuildPresent = true;
        m_yearOfBuild = val;
        return true;
    }

    public int getYearOfBuild() {

        return m_yearOfBuild;
    }

    public boolean hasYearOfBuild() {

        return m_yearOfBuildPresent;
    }

    public boolean setMaxAirDraught(double val) {

        if (val <= 0)
          return false;
        m_maxAirDraughtPresent = true;
        m_maxAirDraught = val;
        return true;
    }

    public double getMaxAirDraught() {

        return m_maxAirDraught;
    }

    public boolean hasMaxAirDraught() {

        return m_maxAirDraughtPresent;
    }

    public boolean setMaxDraught(double val) {

        if (val <= 0)
          return false;
        m_maxDraughtPresent = true;
        m_maxDraught = val;
        return true;
    }

    public double getMaxDraught() {

        return m_maxDraught;
    }

    public boolean hasMaxDraught() {

        return m_maxDraughtPresent;
    }

    public boolean setMaxPersonsOnBoard(int val) {

        if (val <= 0)
          return false;
        m_maxPersonsOnBoardPresent = true;
        m_maxPersonsOnBoard = val;
        return true;
    }

    public int getMaxPersonsOnBoard() {

        return m_maxPersonsOnBoard;
    }

    public boolean hasMaxPersonsOnBoard() {

        return m_maxPersonsOnBoardPresent;
    }

    public boolean setMaxSpeed(double val) {

        if (val <= 0)
          return false;
        m_maxSpeedPresent = true;
        m_maxSpeed = val;
        return true;
    }

    public double getMaxSpeed() {

        return m_maxSpeed;
    }

    public boolean hasMaxSpeed() {

        return m_maxSpeedPresent;
    }

    public boolean setWidth(double val) {

        if (val <= 0)
          return false;
        m_widthPresent = true;
        m_width = val;
        return true;
    }

    public double getWidth() {

        return m_width;
    }

    public boolean hasWidth() {

        return m_widthPresent;
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<Construction";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( hasHullColor() ) {
            xml += " HullColor=\"" + encode( m_hullColor) + "\"";
        }
        if ( hasHullType() ) {
            xml += " HullType=\"" + m_hullType + "\"";
        }
        if ( hasDeadWeight() ) {
            xml += " DeadWeight=\"" + nf.format(m_deadWeight) + "\"";
        }
        if ( hasGrossWeight() ) {
            xml += " GrossWeight=\"" + nf.format(m_grossWeight) + "\"";
        }
        if ( hasLength() ) {
            xml += " Length=\"" + nf.format(m_length) + "\"";
        }
        if ( hasLloydsShipType() ) {
            xml += " LloydsShipType=\"" + m_lloydsShipType + "\"";
        }
        if ( hasYearOfBuild() ) {
            xml += " YearOfBuild=\"" + m_yearOfBuild + "\"";
        }
        if ( hasMaxAirDraught() ) {
            DecimalFormat nfm_maxAirDraught = new DecimalFormat("0.0");
            xml += " MaxAirDraught=\"" + nfm_maxAirDraught.format(m_maxAirDraught) + "\"";
        }
        if ( hasMaxDraught() ) {
            DecimalFormat nfm_maxDraught = new DecimalFormat("0.0");
            xml += " MaxDraught=\"" + nfm_maxDraught.format(m_maxDraught) + "\"";
        }
        if ( hasMaxPersonsOnBoard() ) {
            xml += " MaxPersonsOnBoard=\"" + m_maxPersonsOnBoard + "\"";
        }
        if ( hasMaxSpeed() ) {
            xml += " MaxSpeed=\"" + nf.format(m_maxSpeed) + "\"";
        }
        if ( hasWidth() ) {
            xml += " Width=\"" + nf.format(m_width) + "\"";
        }
        String dataMember;
        xml += ">\n";
        if ( hasUnType() ) {
            dataMember =  m_unType.toXML(false) ;
            if (dataMember != null) {
               xml += dataMember;
            } else {
               return null; // not all required data members have been set 
            } 
        } 
        xml += "</Construction>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "Construction\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( hasHullColor() ) {
            str +=  lead + "    HullColor = " + m_hullColor + "\n";
        }
        if ( hasHullType() ) {
            str +=  lead + "    HullType = " + m_hullType + "\n";
        }
        if ( hasDeadWeight() ) {
            str +=  lead + "    DeadWeight = " + nf.format(m_deadWeight) + "\n";
        }
        if ( hasGrossWeight() ) {
            str +=  lead + "    GrossWeight = " + nf.format(m_grossWeight) + "\n";
        }
        if ( hasLength() ) {
            str +=  lead + "    Length = " + nf.format(m_length) + "\n";
        }
        if ( hasLloydsShipType() ) {
            str +=  lead + "    LloydsShipType = " + m_lloydsShipType + "\n";
        }
        if ( hasYearOfBuild() ) {
            str +=  lead + "    YearOfBuild = " + m_yearOfBuild + "\n";
        }
        if ( hasMaxAirDraught() ) {
            DecimalFormat nfm_maxAirDraught = new DecimalFormat("0.0");
            str +=  lead + "    MaxAirDraught = " + nfm_maxAirDraught.format(m_maxAirDraught) + "\n";
        }
        if ( hasMaxDraught() ) {
            DecimalFormat nfm_maxDraught = new DecimalFormat("0.0");
            str +=  lead + "    MaxDraught = " + nfm_maxDraught.format(m_maxDraught) + "\n";
        }
        if ( hasMaxPersonsOnBoard() ) {
            str +=  lead + "    MaxPersonsOnBoard = " + m_maxPersonsOnBoard + "\n";
        }
        if ( hasMaxSpeed() ) {
            str +=  lead + "    MaxSpeed = " + nf.format(m_maxSpeed) + "\n";
        }
        if ( hasWidth() ) {
            str +=  lead + "    Width = " + nf.format(m_width) + "\n";
        }
        if ( hasUnType() ) {
            str +=  m_unType.toString(lead + "    ") ;
        }
        return str;
    }
    public String encode( String str) {

        str = str.replaceAll("&", "&amp;");
        str = str.replaceAll("<", "&lt;");
        str = str.replaceAll(">", "&gt;");
        str = str.replaceAll("\"", "&quot;");
        return str;
    }


}
