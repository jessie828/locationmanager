# MySQL Navigator Xport
# Database: locationDB
# locationadmin@localhost

# CREATE DATABASE locationDB;
# USE locationDB;

#
# Table structure for table 'Locations'
#

# DROP TABLE IF EXISTS Locations;
CREATE TABLE `Locations` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `trip_id` int(11) NOT NULL,
  `time` timestamp NOT NULL,
  `altitude` double DEFAULT NULL,
  `latitude` double DEFAULT NULL,
  `longitude` double DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

#
# Dumping data for table 'Locations'
#


#
# Table structure for table 'Trips'
#

# DROP TABLE IF EXISTS Trips;
CREATE TABLE `Trips` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `startDate` timestamp NOT NULL,
  `endDate` timestamp NOT NULL,
  `duration` int(11) DEFAULT NULL,
  `distance` double DEFAULT NULL,
  `average_speed` double DEFAULT NULL,
  `max_speed` double DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;

