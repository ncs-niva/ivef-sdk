/* 
 *  NavStatus
 *
 *  NavStatus is free software: you can redistribute it and/or modify
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


public class NavStatus { 

    private int m_value; // default value is uninitialized
    private boolean m_valuePresent;

    public NavStatus() {

        m_valuePresent = false;
    }

    public NavStatus(NavStatus val) {

        m_value = val.getValue();
        if (val != null) {
            m_valuePresent = true;
        }
    }

    public boolean setValue(int val) {

        if (val < 0)
          return false;
        if (val > 15)
          return false;
        m_valuePresent = true;
        m_value = val;
        return true;
    }

    public int getValue() {

        return m_value;
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<NavStatus";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( m_valuePresent ) {
            xml += " Value=\"" + m_value + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        xml += "/>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "NavStatus\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

            str +=  lead + "    Value = " + m_value + "\n";
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
