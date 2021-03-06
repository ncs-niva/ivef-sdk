<?php

// 
//  ServiceRequest
//
//  ServiceRequest is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  ServiceRequest is distributed in the hope that it will be useful,
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

require_once "IVEFArea.php";
require_once "IVEFTransmission.php";
require_once "IVEFItem.php";
require_once "IVEFFilter.php";

class ServiceRequest { 

    var $m_area; // default value is uninitialized
    var $m_areaPresent;
    var $m_transmission; // default value is uninitialized
    var $m_transmissionPresent;
    var $m_item; // default value is uninitialized
    var $m_itemPresent;
    var $m_filter; // default value is uninitialized
    var $m_filterPresent;

    public function ServiceRequest() {

        date_default_timezone_set('UTC');
        $this->m_areaPresent = false;
        $this->m_areas = array();
        $this->m_transmissionPresent = false;
        $this->m_transmission = new Transmission();
        $this->m_itemPresent = false;
        $this->m_items = array();
        $this->m_filterPresent = false;
        $this->m_filter = new Filter();
    }

    public function removeArea(Area $val ) {
        if ( count($this->m_areas) <= 0) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_areas); $i++) {
            if($this->m_areas[i] == $val) {
                unset($this->m_areas[i]);
            }
        }
        return true;
    }

    public function addArea(Area $val ) {

        $this->m_areas[] = $val;
        return true;
    }

    public function getAreaAt($i) {

        return $this->m_areas[$i];
    }

    public function countOfAreas() {

        return count($this->m_areas);
    }

    public function setTransmission( $val ) {

        $this->m_transmissionPresent = true;
        $this->m_transmission = $val;
        return true;
    }

    public function getTransmission() {

        return $this->m_transmission;
    }

    public function removeItem(Item $val ) {
        if ( count($this->m_items) <= 0) {
            return false; // scalar already at minOccurs
        }
        for($i=0; $i< count($this->m_items); $i++) {
            if($this->m_items[i] == $val) {
                unset($this->m_items[i]);
            }
        }
        return true;
    }

    public function addItem(Item $val ) {

        $this->m_items[] = $val;
        return true;
    }

    public function getItemAt($i) {

        return $this->m_items[$i];
    }

    public function countOfItems() {

        return count($this->m_items);
    }

    public function setFilter( $val ) {

        $this->m_filterPresent = true;
        $this->m_filter = $val;
        return true;
    }

    public function getFilter() {

        return $this->m_filter;
    }

    public function hasFilter() {

        return $this->m_filterPresent;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<ServiceRequest";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
            $rootNodeTag .= "></ServiceRequest>";
        }
        else
            $rootNodeTag = "<ServiceRequest></ServiceRequest>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( count($this->m_areas) < 0) {
            return ""; // not enough values
        }
        foreach($this->m_areas as $attribute) {
        $dom = dom_import_simplexml($xml);
        $child_as_xml = $attribute->toXML(false);
        $child_as_simplexml = new SimpleXMLElement($child_as_xml);
        $child_as_dom = dom_import_simplexml($child_as_simplexml);
        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
        $dom->appendChild($child_as_leaf);
        $xml = simplexml_import_dom($dom);
        } 
        if ( $this->m_transmissionPresent ) {
            $dom = dom_import_simplexml($xml);
            $child_as_xml = $this->m_transmission->toXML(false);
            $child_as_simplexml = new SimpleXMLElement($child_as_xml);
            $child_as_dom = dom_import_simplexml($child_as_simplexml);
            $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
            $dom->appendChild($child_as_leaf);
            $xml = simplexml_import_dom($dom);
        } else { 
            return ""; // not all required data members have been set 
        } 
        if ( count($this->m_items) < 0) {
            return ""; // not enough values
        }
        foreach($this->m_items as $attribute) {
        $dom = dom_import_simplexml($xml);
        $child_as_xml = $attribute->toXML(false);
        $child_as_simplexml = new SimpleXMLElement($child_as_xml);
        $child_as_dom = dom_import_simplexml($child_as_simplexml);
        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);
        $dom->appendChild($child_as_leaf);
        $xml = simplexml_import_dom($dom);
        } 
        if ( $this->hasFilter() ) {
            $dom = dom_import_simplexml($xml);
            $child_as_xml = $this->m_filter->toXML(false);
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

        $str = $lead . "ServiceRequest\n";

        foreach($this->m_areas as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }
        $str .=  $this->m_transmission->toStringWithLead($lead . "    ");
        foreach($this->m_items as $attribute) {
           $str .= $attribute->toStringWithLead($lead . "    ");
        }
        if ( $this->hasFilter() ) {
            $str .=  $this->m_filter->toStringWithLead($lead . "    ") ;
        }

        return $str;
    }
}
?>
