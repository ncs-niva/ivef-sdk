<?php

// 
//  Pos
//
//  Pos is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Pos is distributed in the hope that it will be useful,
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


class Pos { 

    var $m_altitude; // default value is uninitialized
    var $m_altitudePresent;
    var $m_estAccAlt; // default value is uninitialized
    var $m_estAccAltPresent;
    var $m_estAccLat; // default value is uninitialized
    var $m_estAccLatPresent;
    var $m_estAccLong; // default value is uninitialized
    var $m_estAccLongPresent;
    var $m_lat; // default value is uninitialized
    var $m_latPresent;
    var $m_long; // default value is uninitialized
    var $m_longPresent;

    public function Pos() {

        date_default_timezone_set('UTC');
        $this->m_altitudePresent = false;
        $this->m_estAccAltPresent = false;
        $this->m_estAccLatPresent = false;
        $this->m_estAccLongPresent = false;
        $this->m_latPresent = false;
        $this->m_longPresent = false;
    }

    public function setAltitude( $val ) {

        $this->m_altitudePresent = true;
        $this->m_altitude = $val;
        return true;
    }

    public function getAltitude() {

        return $this->m_altitude;
    }

    public function hasAltitude() {

        return $this->m_altitudePresent;
    }

    public function setEstAccAlt( $val ) {

        $this->m_estAccAltPresent = true;
        $this->m_estAccAlt = $val;
        return true;
    }

    public function getEstAccAlt() {

        return $this->m_estAccAlt;
    }

    public function hasEstAccAlt() {

        return $this->m_estAccAltPresent;
    }

    public function setEstAccLat( $val ) {

        $this->m_estAccLatPresent = true;
        $this->m_estAccLat = $val;
        return true;
    }

    public function getEstAccLat() {

        return $this->m_estAccLat;
    }

    public function hasEstAccLat() {

        return $this->m_estAccLatPresent;
    }

    public function setEstAccLong( $val ) {

        $this->m_estAccLongPresent = true;
        $this->m_estAccLong = $val;
        return true;
    }

    public function getEstAccLong() {

        return $this->m_estAccLong;
    }

    public function hasEstAccLong() {

        return $this->m_estAccLongPresent;
    }

    public function setLat( $val ) {

        if ($val < -90)
          return false;
        if ($val > 90)
          return false;
        $this->m_latPresent = true;
        $this->m_lat = $val;
        return true;
    }

    public function getLat() {

        return $this->m_lat;
    }

    public function setLong( $val ) {

        if ($val <= -180)
          return false;
        if ($val > 180)
          return false;
        $this->m_longPresent = true;
        $this->m_long = $val;
        return true;
    }

    public function getLong() {

        return $this->m_long;
    }

    public function toXML($outputNamespace = true) {

        if ($outputNamespace)
        {
            $rootNodeTag  = "<Pos";
            $rootNodeTag .= " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            $rootNodeTag .= " xmlns=\"http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.5\"";
            $rootNodeTag .= "></Pos>";
        }
        else
            $rootNodeTag = "<Pos></Pos>";
        $xml = new SimpleXMLElement($rootNodeTag);

        if ( $this->hasAltitude() ) {
            $xml->addAttribute('Altitude', number_format($this->m_altitude, 6));
        }
        if ( $this->hasEstAccAlt() ) {
            $xml->addAttribute('EstAccAlt', number_format($this->m_estAccAlt, 6));
        }
        if ( $this->hasEstAccLat() ) {
            $xml->addAttribute('EstAccLat', number_format($this->m_estAccLat, 6));
        }
        if ( $this->hasEstAccLong() ) {
            $xml->addAttribute('EstAccLong', number_format($this->m_estAccLong, 6));
        }
        if ( $this->m_latPresent ) {
            $xml->addAttribute('Lat', number_format($this->m_lat, 5));
        } else { 
            return ""; // not all required attributes have been set 
        } 
        if ( $this->m_longPresent ) {
            $xml->addAttribute('Long', number_format($this->m_long, 5));
        } else { 
            return ""; // not all required attributes have been set 
        } 
        return $xml->asXML();
    }

    public function toString() {

    	return $this->toStringWithLead("");
    }

    public function toStringWithLead( $lead ) {

        $str = $lead . "Pos\n";

        if ( $this->hasAltitude() ) {
            $str .= $lead . "    Altitude = " . number_format($this->m_altitude, 6) . "\n";
        }
        if ( $this->hasEstAccAlt() ) {
            $str .= $lead . "    EstAccAlt = " . number_format($this->m_estAccAlt, 6) . "\n";
        }
        if ( $this->hasEstAccLat() ) {
            $str .= $lead . "    EstAccLat = " . number_format($this->m_estAccLat, 6) . "\n";
        }
        if ( $this->hasEstAccLong() ) {
            $str .= $lead . "    EstAccLong = " . number_format($this->m_estAccLong, 6) . "\n";
        }
        $str .= $lead . "    Lat = " . number_format($this->m_lat, 5) . "\n";
        $str .= $lead . "    Long = " . number_format($this->m_long, 5) . "\n";

        return $str;
    }
}
?>
