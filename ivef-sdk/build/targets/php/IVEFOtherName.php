<?php

// 
//  OtherName
//
//  OtherName is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  OtherName is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY ); without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//*********************************************************************************
//  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
//  Generated by schema2code on Mon Jan 17 11:39:43 2022.
//*********************************************************************************
//  Copyright 2010
//


class OtherName { 

    var $m_lang; // default value is uninitialized
    var $m_langPresent;
    var $m_name; // default value is uninitialized
    var $m_namePresent;

    public function OtherName() {

        date_default_timezone_set('UTC');
        $this->m_langPresent = false;
        $this->m_namePresent = false;
    }

    public function setLang( $val ) {

        if (strlen ($val) < 2)
            return false;
        if (strlen ($val) > 2)
            return false;
        $this->m_langPresent = true;
        $this->m_lang = $val;
        return true;
    }

    public function getLang() {

        return $this->m_lang;
    }

    public function setName( $val ) {

        if (strlen ($val) < 1)
            return false;
        if (strlen ($val) > 42)
            return false;
        $this->m_namePresent = true;
        $this->m_name = $val;
        return true;
    }

    public function getName() {

        return $this->m_name;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<OtherName";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
            $rootNodeTag .= "></OtherName>";
        }
        else
            $rootNodeTag = "<OtherName></OtherName>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->m_langPresent ) {
            $xml->addAttribute('Lang', $this->m_lang);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( $this->m_namePresent ) {
            $xml->addAttribute('Name', $this->m_name);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "OtherName\n";

        $str .= $lead . "    Lang = " . $this->m_lang . "\n";
        $str .= $lead . "    Name = " . $this->m_name . "\n";

        return $str;
    }
}
?>
