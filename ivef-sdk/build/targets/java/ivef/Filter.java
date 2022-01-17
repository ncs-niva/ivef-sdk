/* 
 *  Filter
 *
 *  Filter is free software: you can redistribute it and/or modify
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


public class Filter { 

    private String m_predicate; // default value is uninitialized
    private boolean m_predicatePresent;

    public Filter() {

        m_predicatePresent = false;
    }

    public Filter(Filter val) {

        m_predicate = val.getPredicate();
        if (val != null) {
            m_predicatePresent = true;
        }
    }

    public boolean setPredicate(String val) {

        if (val.length() < 1)
          return false;
        if (val.length() > 1024)
          return false;
        m_predicatePresent = true;
        m_predicate = val;
        return true;
    }

    public String getPredicate() {

        return m_predicate;
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<Filter";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( m_predicatePresent ) {
            xml += " Predicate=\"" + encode( m_predicate) + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        xml += "/>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "Filter\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

            str +=  lead + "    Predicate = " + m_predicate + "\n";
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
