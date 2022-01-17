<?php

// 
//  Header
//
//  Header is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Header is distributed in the hope that it will be useful,
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


class Header { 

    var $m_msgRefId; // default value is uninitialized
    var $m_msgRefIdPresent;
    var $m_version; // default value is uninitialized
    var $m_versionPresent;

    public function Header() {

        date_default_timezone_set('UTC');
        $this->m_msgRefIdPresent = false;
        $this->m_version = "0.2.5";
        $this->m_versionPresent = true;
    }

    public function setMsgRefId( $val ) {

        if (strlen ($val) < 36)
            return false;
        if (strlen ($val) > 42)
            return false;
        $this->m_msgRefIdPresent = true;
        $this->m_msgRefId = $val;
        return true;
    }

    public function getMsgRefId() {

        return $this->m_msgRefId;
    }

    public function setVersion( $val ) {

        $this->m_versionPresent = true;
        $this->m_version = $val;
        return true;
    }

    public function getVersion() {

        return $this->m_version;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Header";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
            $rootNodeTag .= "></Header>";
        }
        else
            $rootNodeTag = "<Header></Header>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->m_msgRefIdPresent ) {
            $xml->addAttribute('MsgRefId', $this->m_msgRefId);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( $this->m_versionPresent ) {
            $xml->addAttribute('Version', $this->m_version);
        } else { 
            return ""; // not all required attributes have been set 
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Header\n";

        $str .= $lead . "    MsgRefId = " . $this->m_msgRefId . "\n";
        $str .= $lead . "    Version = " . $this->m_version . "\n";

        return $str;
    }
}
?>
