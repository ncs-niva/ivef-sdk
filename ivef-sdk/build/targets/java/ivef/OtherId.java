/* 
 *  OtherId
 *
 *  OtherId is free software: you can redistribute it and/or modify
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


public class OtherId { 

    private String m_id; // default value is uninitialized
    private boolean m_idPresent;
    private String m_value; // default value is uninitialized
    private boolean m_valuePresent;

    public OtherId() {

        m_idPresent = false;
        m_valuePresent = false;
    }

    public OtherId(OtherId val) {

        m_id = val.getId();
        if (val != null) {
            m_idPresent = true;
        }
        m_value = val.getValue();
        if (val != null) {
            m_valuePresent = true;
        }
    }

    public boolean setId(String val) {

        if (val.length() < 1)
          return false;
        if (val.length() > 42)
          return false;
        m_idPresent = true;
        m_id = val;
        return true;
    }

    public String getId() {

        return m_id;
    }

    public boolean setValue(String val) {

        if (val.length() < 1)
          return false;
        if (val.length() > 42)
          return false;
        m_valuePresent = true;
        m_value = val;
        return true;
    }

    public String getValue() {

        return m_value;
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<OtherId";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( m_idPresent ) {
            xml += " Id=\"" + encode( m_id) + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        if ( m_valuePresent ) {
            xml += " Value=\"" + encode( m_value) + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        xml += "/>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "OtherId\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

            str +=  lead + "    Id = " + m_id + "\n";
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
