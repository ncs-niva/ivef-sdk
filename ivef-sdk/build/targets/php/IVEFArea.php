<?php

// 
//  Area
//
//  Area is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Area is distributed in the hope that it will be useful,
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

require_once "IVEFPos.php";

class Area { 

    var $m_pos; // default value is uninitialized
    var $m_posPresent;
    var $m_name; // default value is uninitialized
    var $m_namePresent;

    public function Area() {

        date_default_timezone_set('UTC');
        $this->m_posPresent = false;
        $this->m_poss = array();
        $this->m_namePresent = false;
    }

    public function removePos(Pos $val ) {
        if ( count($this->m_poss) <= 3) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_poss); $i++) {
            if($this->m_poss[i] == $val) {
                unset($this->m_poss[i]);
            }
        }
        return true;
    }

    public function addPos(Pos $val ) {

        $this->m_poss[] = $val;
        return true;
    }

    public function getPosAt($i) {

        return $this->m_poss[$i];
    }

    public function countOfPoss() {

        return count($this->m_poss);
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

    public function hasName() {

        return $this->m_namePresent;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Area";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
            $rootNodeTag .= "></Area>";
        }
        else
            $rootNodeTag = "<Area></Area>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->hasName() ) {
            $xml->addAttribute('Name', $this->m_name);
        }
        if ( count($this->m_poss) < 3) {
            return ""; // not enough values
        }
        foreach($this->m_poss as $attribute) {
        $dom = dom_import_simplexml($xml);
        $child_as_xml = $attribute->toXML(false);
        $child_as_simplexml = new SimpleXMLElement($child_as_xml);
        $child_as_dom = dom_import_simplexml($child_as_simplexml);
        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
        $dom->appendChild($child_as_leaf);
        $xml = simplexml_import_dom($dom);
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Area\n";

        if ( $this->hasName() ) {
            $str .= $lead . "    Name = " . $this->m_name . "\n";
        }
        foreach($this->m_poss as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }

        return $str;
    }
}
?>
