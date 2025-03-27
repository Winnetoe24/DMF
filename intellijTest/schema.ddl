create table Asset (
    acquisitionCost float(8),
    priorityID INTEGER,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Asset.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Asset.assetId is 'Die universelle Id des Assets';

create table TransportRoute (
    firstDepartureTime TIMESTAMP,
    lastDepartureTime TIMESTAMP,
    frequencyMinutes INTEGER,
    statusID INTEGER,
    routeId VARCHAR(255),
    routeName VARCHAR(255),
    PRIMARY KEY(routeId)
);


create table TransportRoute_segments (
    RefrouteId VARCHAR(255),
    ValueendPointlatitude float(8),
    ValueendPointlongitude float(8),
    ValueendPointaltitude float(8),
    ValueendPointaddressString VARCHAR(255),
    Valuedistance float(8),
    ValueestimatedTimeMinutes INTEGER,
    ValuestartPointlatitude float(8),
    ValuestartPointlongitude float(8),
    ValuestartPointaltitude float(8),
    ValuestartPointaddressString VARCHAR(255),
    PRIMARY KEY(RefrouteId, ValueendPointlatitude, ValueendPointlongitude, ValueendPointaltitude, ValueendPointaddressString, Valuedistance, ValueestimatedTimeMinutes, ValuestartPointlatitude, ValuestartPointlongitude, ValuestartPointaltitude, ValuestartPointaddressString)
);

comment on column TransportRoute_segments.RefrouteId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column TransportRoute_segments.ValueendPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaddressString is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.Valuedistance is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueestimatedTimeMinutes is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointaddressString is 'Teil der Werte des Sets';

create table Vehicle (
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    currentRouterouteId VARCHAR(255),
    registrationNumber VARCHAR(255),
    assetId VARCHAR(255),
    typeID INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    capacity INTEGER,
    currentFuelLevel float(8),
    currentPassengerCount INTEGER,
    PRIMARY KEY(registrationNumber)
);

comment on column Vehicle.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Vehicle.assetId is 'Die universelle Id des Assets';

create table PowerPlant (
    expectedLifespanYears INTEGER,
    sourceID INTEGER,
    name VARCHAR(255),
    currentOutput float(8),
    efficiency float(8),
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    isBackupSource boolean,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    capacity float(8),
    assetId VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column PowerPlant.assetId is 'Die universelle Id des Assets';
comment on column PowerPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table SmartMeter (
    peakDemand float(8),
    lastReadingTime TIMESTAMP,
    isOnline boolean,
    patternID INTEGER,
    meterId VARCHAR(255),
    currentReading float(8),
    PRIMARY KEY(meterId)
);


create table WaterSource (
    capacity float(8),
    qualityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    currentLevel float(8),
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    installationDate DATE,
    isActive boolean,
    statusID INTEGER,
    flowRate float(8),
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WaterSource.assetId is 'Die universelle Id des Assets';
comment on column WaterSource.priorityID is 'the priority of the asset
the priority of the asset';

create table WaterTreatmentPlant (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    currentThroughput float(8),
    treatmentStages INTEGER,
    processingCapacity float(8),
    isOperating boolean,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    name VARCHAR(255),
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column WaterTreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column WaterTreatmentPlant.assetId is 'Die universelle Id des Assets';

create table WasteCollection (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    collectionId VARCHAR(255),
    scheduledTime TIMESTAMP,
    estimatedVolume float(8),
    isCompleted boolean,
    typeID INTEGER,
    PRIMARY KEY(collectionId)
);


create table RecyclingFacility (
    processingCapacity float(8),
    priorityID INTEGER,
    assetId VARCHAR(255),
    isAcceptingWaste boolean,
    statusID INTEGER,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    currentStorage float(8),
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column RecyclingFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column RecyclingFacility.assetId is 'Die universelle Id des Assets';

create table RecyclingFacility_acceptedTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column RecyclingFacility_acceptedTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RecyclingFacility_acceptedTypes.ValueID is 'Teil der Werte des Sets';

create table MonitoringStation (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    stationId VARCHAR(255),
    isCalibrated boolean,
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    lastCalibrationDate DATE,
    priorityID INTEGER,
    assetId VARCHAR(255),
    installationDate DATE,
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation.priorityID is 'the priority of the asset
the priority of the asset';
comment on column MonitoringStation.assetId is 'Die universelle Id des Assets';

create table MonitoringStation_readings (
    RefstationId VARCHAR(255),
    Index INTEGER,
    Valueconcentration float(8),
    Valuetimestamp TIMESTAMP,
    ValueexceedsLimit boolean,
    ValuepollutantID INTEGER,
    PRIMARY KEY(RefstationId, Index)
);

comment on column MonitoringStation_readings.RefstationId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column MonitoringStation_readings.Index is 'Die Index des Listeneintrags';
comment on column MonitoringStation_readings.Valueconcentration is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.Valuetimestamp is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.ValueexceedsLimit is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.ValuepollutantID is 'Teil der Werte der Liste';

create table EmergencyIncident (
    isActive boolean,
    typeID INTEGER,
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    incidentId VARCHAR(255),
    reportedTime TIMESTAMP,
    responseTime TIMESTAMP,
    PRIMARY KEY(incidentId)
);


create table EmergencyTeam (
    isAvailable boolean,
    specialtyID INTEGER,
    currentLocationlatitude float(8),
    currentLocationlongitude float(8),
    currentLocationaltitude float(8),
    currentLocationaddressString VARCHAR(255),
    teamId VARCHAR(255),
    memberCount INTEGER,
    PRIMARY KEY(teamId)
);


create table Building (
    installationDate DATE,
    isSmartEnabled boolean,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    occupancy INTEGER,
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    totalArea float(8),
    typeID INTEGER,
    securityLevelID INTEGER,
    floors INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Building.assetId is 'Die universelle Id des Assets';
comment on column Building.priorityID is 'the priority of the asset
the priority of the asset';

create table SmartDevice (
    buildingassetId VARCHAR(255),
    deviceId VARCHAR(255),
    deviceType VARCHAR(255),
    isOnline boolean,
    lastPing TIMESTAMP,
    firmwareVersion VARCHAR(255),
    PRIMARY KEY(deviceId)
);


create table Citizen (
    residencelatitude float(8),
    residencelongitude float(8),
    residencealtitude float(8),
    residenceaddressString VARCHAR(255),
    citizenId VARCHAR(255),
    firstName VARCHAR(255),
    lastName VARCHAR(255),
    dateOfBirth DATE,
    email VARCHAR(255),
    phone VARCHAR(255),
    PRIMARY KEY(citizenId)
);


create table ServiceRequest (
    submissionTime TIMESTAMP,
    status VARCHAR(255),
    description VARCHAR(255),
    typeID INTEGER,
    requestercitizenId VARCHAR(255),
    requestId VARCHAR(255),
    PRIMARY KEY(requestId)
);


create table DataPoint (
    value float(8),
    timestamp TIMESTAMP,
    source VARCHAR(255),
    isVerified boolean,
    typeID INTEGER,
    dataId VARCHAR(255),
    PRIMARY KEY(dataId)
);


create table HealthcareFacility (
    statusID INTEGER,
    currentOccupancy INTEGER,
    hasEmergencyUnit boolean,
    bedCapacity INTEGER,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    installationDate DATE,
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column HealthcareFacility.assetId is 'Die universelle Id des Assets';
comment on column HealthcareFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table HealthcareFacility_specialties (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column HealthcareFacility_specialties.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column HealthcareFacility_specialties.ValueID is 'Teil der Werte des Sets';

create table MedicalEquipment (
    priorityID INTEGER,
    hoursInUse INTEGER,
    assetId VARCHAR(255),
    installationDate DATE,
    manufacturer VARCHAR(255),
    requiresCalibration boolean,
    lastMaintenanceDate DATE,
    equipmentType VARCHAR(255),
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    warrantyExpiry DATE,
    acquisitionCost float(8),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column MedicalEquipment.priorityID is 'the priority of the asset
the priority of the asset';
comment on column MedicalEquipment.assetId is 'Die universelle Id des Assets';

create table EducationalInstitution (
    priorityID INTEGER,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    typeID INTEGER,
    studentCapacity INTEGER,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    installationDate DATE,
    assetId VARCHAR(255),
    accreditationStatus VARCHAR(255),
    staffCount INTEGER,
    isPublic boolean,
    PRIMARY KEY(assetId)
);

comment on column EducationalInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column EducationalInstitution.assetId is 'Die universelle Id des Assets';

create table Course (
    title VARCHAR(255),
    credits INTEGER,
    maxEnrollment INTEGER,
    isOnline boolean,
    levelID INTEGER,
    courseId VARCHAR(255),
    PRIMARY KEY(courseId)
);


create table Farm (
    assetId VARCHAR(255),
    isOrganic boolean,
    lastMaintenanceDate DATE,
    irrigationTypeID INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    lastHarvestDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acquisitionCost float(8),
    area float(8),
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Farm.assetId is 'Die universelle Id des Assets';
comment on column Farm.priorityID is 'the priority of the asset
the priority of the asset';

create table Farm_crops (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Farm_crops.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Farm_crops.ValueID is 'Teil der Werte des Sets';

create table Sensor (
    readingValue float(8),
    expectedLifespanYears INTEGER,
    needsCalibration boolean,
    name VARCHAR(255),
    unit VARCHAR(255),
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    lastReading TIMESTAMP,
    statusID INTEGER,
    assetId VARCHAR(255),
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    sensorType VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column Sensor.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Sensor.assetId is 'Die universelle Id des Assets';

create table TouristAttraction (
    dailyVisitorCapacity INTEGER,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    isAccessible boolean,
    typeID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    statusID INTEGER,
    priorityID INTEGER,
    entryFee float(8),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction.assetId is 'Die universelle Id des Assets';
comment on column TouristAttraction.priorityID is 'the priority of the asset
the priority of the asset';

create table TouristAttraction_openingHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column TouristAttraction_openingHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column TouristAttraction_openingHours.Index is 'Die Index des Listeneintrags';
comment on column TouristAttraction_openingHours.Value is 'Werte der Liste';

create table Event (
    expectedAttendance INTEGER,
    seasonID INTEGER,
    eventId VARCHAR(255),
    name VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    PRIMARY KEY(eventId)
);


create table ParkingFacility (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    totalSpaces INTEGER,
    typeID INTEGER,
    lastMaintenanceDate DATE,
    availableSpaces INTEGER,
    hourlyRate float(8),
    statusID INTEGER,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    installationDate DATE,
    priorityID INTEGER,
    name VARCHAR(255),
    hasChargingStations boolean,
    PRIMARY KEY(assetId)
);

comment on column ParkingFacility.assetId is 'Die universelle Id des Assets';
comment on column ParkingFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table ParkingTransaction (
    entryTime TIMESTAMP,
    exitTime TIMESTAMP,
    amount float(8),
    isPaid boolean,
    vehicleSizeID INTEGER,
    transactionId VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table WeatherStation (
    temperature float(8),
    precipitation float(8),
    priorityID INTEGER,
    acquisitionCost float(8),
    windSpeed float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    conditionID INTEGER,
    humidity float(8),
    assetId VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WeatherStation.priorityID is 'the priority of the asset
the priority of the asset';
comment on column WeatherStation.assetId is 'Die universelle Id des Assets';

create table WeatherAlert (
    levelID INTEGER,
    alertId VARCHAR(255),
    message VARCHAR(255),
    issueTime TIMESTAMP,
    expiryTime TIMESTAMP,
    isActive boolean,
    PRIMARY KEY(alertId)
);


create table GridNode (
    voltage float(8),
    isRedundant boolean,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    current float(8),
    priorityID INTEGER,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    statusID INTEGER,
    typeID INTEGER,
    profileID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column GridNode.priorityID is 'the priority of the asset
the priority of the asset';
comment on column GridNode.assetId is 'Die universelle Id des Assets';

create table PowerFlow (
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    flowId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isStable boolean,
    PRIMARY KEY(flowId)
);


create table Zone (
    statusID INTEGER,
    typeID INTEGER,
    maxDensity float(8),
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    isHistorical boolean,
    assetId VARCHAR(255),
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    heightLimit INTEGER,
    installationDate DATE,
    acquisitionCost float(8),
    area float(8),
    PRIMARY KEY(assetId)
);

comment on column Zone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Zone.assetId is 'Die universelle Id des Assets';

create table DevelopmentProject (
    projectId VARCHAR(255),
    description VARCHAR(255),
    startDate DATE,
    completionDate DATE,
    budget float(8),
    statusID INTEGER,
    PRIMARY KEY(projectId)
);


create table SafetyIncident (
    requiresEvacuation boolean,
    typeID INTEGER,
    incidentId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table SafetyIncident_requiredUnits (
    RefincidentId VARCHAR(255),
    Index INTEGER,
    ValueID INTEGER,
    PRIMARY KEY(RefincidentId, Index)
);

comment on column SafetyIncident_requiredUnits.RefincidentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyIncident_requiredUnits.Index is 'Die Index des Listeneintrags';
comment on column SafetyIncident_requiredUnits.ValueID is 'Teil der Werte der Liste';

create table Evacuation (
    affectedPopulation INTEGER,
    isCompleted boolean,
    incidentincidentId VARCHAR(255),
    evacuationId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    PRIMARY KEY(evacuationId)
);


create table NetworkNode (
    typeID INTEGER,
    isRedundant boolean,
    connectedDevices INTEGER,
    installationDate DATE,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    bandwidthID INTEGER,
    uptime float(8),
    acquisitionCost float(8),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column NetworkNode.priorityID is 'the priority of the asset
the priority of the asset';
comment on column NetworkNode.assetId is 'Die universelle Id des Assets';

create table DataTransfer (
    isEncrypted boolean,
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    transferId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    PRIMARY KEY(transferId)
);


create table CulturalVenue (
    acquisitionCost float(8),
    hasAccessibility boolean,
    typeID INTEGER,
    capacity INTEGER,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    statusID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue.priorityID is 'the priority of the asset
the priority of the asset';
comment on column CulturalVenue.assetId is 'Die universelle Id des Assets';

create table CulturalVenue_facilities (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column CulturalVenue_facilities.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column CulturalVenue_facilities.Value is 'Werte des Sets';

create table CulturalVenue_operatingHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column CulturalVenue_operatingHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column CulturalVenue_operatingHours.Index is 'Die Index des Listeneintrags';
comment on column CulturalVenue_operatingHours.Value is 'Werte der Liste';

create table CulturalEvent (
    curator VARCHAR(255),
    categoryID INTEGER,
    ticketingdiscount float(8),
    ticketingavailableSeats INTEGER,
    ticketingisRefundable boolean,
    ticketingbasePrice float(8),
    eventId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    PRIMARY KEY(eventId)
);


create table SportsFacility (
    typeID INTEGER,
    assetId VARCHAR(255),
    isIndoor boolean,
    acquisitionCost float(8),
    spectatorCapacity INTEGER,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    hasFloodlights boolean,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column SportsFacility.assetId is 'Die universelle Id des Assets';
comment on column SportsFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table SportsFacility_supportedSports (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column SportsFacility_supportedSports.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SportsFacility_supportedSports.ValueID is 'Teil der Werte des Sets';

create table Tournament (
    participants INTEGER,
    sponsor VARCHAR(255),
    sportID INTEGER,
    tournamentId VARCHAR(255),
    startDate DATE,
    endDate DATE,
    PRIMARY KEY(tournamentId)
);


create table TreatmentPlant (
    lastInspection DATE,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    assetId VARCHAR(255),
    isOperational boolean,
    priorityID INTEGER,
    dailyCapacity float(8),
    acquisitionCost float(8),
    currentFlow float(8),
    statusID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column TreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table TreatmentPlant_stages (
    RefassetId VARCHAR(255),
    Index INTEGER,
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, Index)
);

comment on column TreatmentPlant_stages.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column TreatmentPlant_stages.Index is 'Die Index des Listeneintrags';
comment on column TreatmentPlant_stages.ValueID is 'Teil der Werte der Liste';

create table QualityTest (
    meetsStandard boolean,
    analyst VARCHAR(255),
    metricID INTEGER,
    testId VARCHAR(255),
    value float(8),
    timestamp TIMESTAMP,
    PRIMARY KEY(testId)
);


create table TransitCard (
    fareTypeID INTEGER,
    cardId VARCHAR(255),
    balance float(8),
    expiryDate DATE,
    isActive boolean,
    methodID INTEGER,
    PRIMARY KEY(cardId)
);


create table FareTransaction (
    amount float(8),
    route VARCHAR(255),
    isRefunded boolean,
    cardcardId VARCHAR(255),
    transactionId VARCHAR(255),
    timestamp TIMESTAMP,
    PRIMARY KEY(transactionId)
);


create table DigitalSign (
    name VARCHAR(255),
    resolution VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    priorityID INTEGER,
    isInteractive boolean,
    contentTypeID INTEGER,
    installationDate DATE,
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column DigitalSign.assetId is 'Die universelle Id des Assets';
comment on column DigitalSign.priorityID is 'the priority of the asset
the priority of the asset';

create table DigitalSign_activeHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column DigitalSign_activeHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column DigitalSign_activeHours.Index is 'Die Index des Listeneintrags';
comment on column DigitalSign_activeHours.Value is 'Werte der Liste';

create table SignContent (
    content VARCHAR(255),
    startDisplay TIMESTAMP,
    endDisplay TIMESTAMP,
    priority INTEGER,
    signassetId VARCHAR(255),
    contentId VARCHAR(255),
    PRIMARY KEY(contentId)
);


create table NoiseSensor (
    currentLevelID INTEGER,
    lastPeak TIMESTAMP,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    averageReading float(8),
    sourcesID INTEGER,
    needsCalibration boolean,
    installationDate DATE,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    priorityID INTEGER,
    statusID INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column NoiseSensor.assetId is 'Die universelle Id des Assets';
comment on column NoiseSensor.priorityID is 'the priority of the asset
the priority of the asset';

create table NoiseComplaint (
    sourceID INTEGER,
    complaintId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    isResolved boolean,
    resolution VARCHAR(255),
    PRIMARY KEY(complaintId)
);


create table StreetLight (
    brightnessID INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    typeID INTEGER,
    acquisitionCost float(8),
    hasMotionSensor boolean,
    installationDate DATE,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    energyConsumption float(8),
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column StreetLight.priorityID is 'the priority of the asset
the priority of the asset';
comment on column StreetLight.assetId is 'Die universelle Id des Assets';

create table StreetLight_scheduleOn (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column StreetLight_scheduleOn.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column StreetLight_scheduleOn.Index is 'Die Index des Listeneintrags';
comment on column StreetLight_scheduleOn.Value is 'Werte der Liste';

create table LightingZone (
    isDimmed boolean,
    dailyUsage float(8),
    zoneId VARCHAR(255),
    schedule VARCHAR(255),
    PRIMARY KEY(zoneId)
);


create table LightingZone_lights (
    RefzoneId VARCHAR(255),
    Index INTEGER,
    ValueassetId VARCHAR(255),
    PRIMARY KEY(RefzoneId, Index)
);

comment on column LightingZone_lights.RefzoneId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LightingZone_lights.Index is 'Die Index des Listeneintrags';
comment on column LightingZone_lights.ValueassetId is 'Teil der Werte der Liste';

create table Market (
    stallCapacity INTEGER,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acquisitionCost float(8),
    closeTime TIMESTAMP,
    openTime TIMESTAMP,
    assetId VARCHAR(255),
    statusID INTEGER,
    installationDate DATE,
    priorityID INTEGER,
    typeID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Market.assetId is 'Die universelle Id des Assets';
comment on column Market.priorityID is 'the priority of the asset
the priority of the asset';

create table Market_operatingDays (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column Market_operatingDays.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Market_operatingDays.Index is 'Die Index des Listeneintrags';
comment on column Market_operatingDays.Value is 'Werte der Liste';

create table Vendor (
    vendorId VARCHAR(255),
    products VARCHAR(255),
    isRegistered boolean,
    licenseExpiry DATE,
    categoryID INTEGER,
    marketassetId VARCHAR(255),
    PRIMARY KEY(vendorId)
);


create table Drone (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    name VARCHAR(255),
    statusID INTEGER,
    batteryLevel float(8),
    acquisitionCost float(8),
    maxAltitude float(8),
    range float(8),
    priorityID INTEGER,
    installationDate DATE,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    flightStatusID INTEGER,
    lastMaintenanceDate DATE,
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Drone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Drone.assetId is 'Die universelle Id des Assets';

create table FlightMission (
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    purpose VARCHAR(255),
    isCompleted boolean,
    droneassetId VARCHAR(255),
    missionId VARCHAR(255),
    PRIMARY KEY(missionId)
);


create table StreetFurniture (
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    priorityID INTEGER,
    material VARCHAR(255),
    installationDate DATE,
    stateID INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    needsRepair boolean,
    typeID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column StreetFurniture.priorityID is 'the priority of the asset
the priority of the asset';
comment on column StreetFurniture.assetId is 'Die universelle Id des Assets';

create table MaintenanceRecord (
    furnitureassetId VARCHAR(255),
    recordId VARCHAR(255),
    maintenanceDate DATE,
    work VARCHAR(255),
    cost float(8),
    contractor VARCHAR(255),
    PRIMARY KEY(recordId)
);


create table Restaurant (
    installationDate DATE,
    lastMaintenanceDate DATE,
    statusID INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    hasDelivery boolean,
    name VARCHAR(255),
    ratingID INTEGER,
    acquisitionCost float(8),
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    seatingCapacity INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Restaurant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Restaurant.assetId is 'Die universelle Id des Assets';

create table Restaurant_operatingHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column Restaurant_operatingHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Restaurant_operatingHours.Index is 'Die Index des Listeneintrags';
comment on column Restaurant_operatingHours.Value is 'Werte der Liste';

create table Inspection (
    passed boolean,
    followupDate DATE,
    restaurantassetId VARCHAR(255),
    inspectionId VARCHAR(255),
    inspectionDate DATE,
    PRIMARY KEY(inspectionId)
);


create table Inspection_violations (
    RefinspectionId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefinspectionId, Index)
);

comment on column Inspection_violations.RefinspectionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Inspection_violations.Index is 'Die Index des Listeneintrags';
comment on column Inspection_violations.Value is 'Werte der Liste';

create table RetailStore (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    segmentID INTEGER,
    acquisitionCost float(8),
    installationDate DATE,
    name VARCHAR(255),
    employeeCount INTEGER,
    isChainStore boolean,
    statusID INTEGER,
    floorArea float(8),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column RetailStore.assetId is 'Die universelle Id des Assets';
comment on column RetailStore.priorityID is 'the priority of the asset
the priority of the asset';

create table InventoryItem (
    price float(8),
    isDiscounted boolean,
    storeassetId VARCHAR(255),
    itemId VARCHAR(255),
    name VARCHAR(255),
    stockLevel INTEGER,
    PRIMARY KEY(itemId)
);


create table Cemetery (
    lastMaintenanceDate DATE,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    availablePlots INTEGER,
    totalPlots INTEGER,
    hasChapel boolean,
    priorityID INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    totalArea float(8),
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Cemetery.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Cemetery.assetId is 'Die universelle Id des Assets';

create table Cemetery_availableTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Cemetery_availableTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Cemetery_availableTypes.ValueID is 'Teil der Werte des Sets';

create table Plot (
    plotId VARCHAR(255),
    lastMaintenance DATE,
    isOccupied boolean,
    owner VARCHAR(255),
    typeID INTEGER,
    scheduleID INTEGER,
    PRIMARY KEY(plotId)
);


create table PostOffice (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    name VARCHAR(255),
    staffCount INTEGER,
    lastMaintenanceDate DATE,
    storageCapacity float(8),
    counterCount INTEGER,
    expectedLifespanYears INTEGER,
    hasAutomation boolean,
    statusID INTEGER,
    acquisitionCost float(8),
    priorityID INTEGER,
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column PostOffice.assetId is 'Die universelle Id des Assets';
comment on column PostOffice.priorityID is 'the priority of the asset
the priority of the asset';

create table PostOffice_serviceHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column PostOffice_serviceHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column PostOffice_serviceHours.Index is 'Die Index des Listeneintrags';
comment on column PostOffice_serviceHours.Value is 'Werte der Liste';

create table Shipment (
    estimatedDelivery TIMESTAMP,
    isInsured boolean,
    typeID INTEGER,
    statusID INTEGER,
    trackingId VARCHAR(255),
    receivedTime TIMESTAMP,
    PRIMARY KEY(trackingId)
);


create table Artwork (
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    artistTypeID INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    materials VARCHAR(255),
    assetId VARCHAR(255),
    priorityID INTEGER,
    typeID INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    requiresRestoration boolean,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Artwork.assetId is 'Die universelle Id des Assets';
comment on column Artwork.priorityID is 'the priority of the asset
the priority of the asset';

create table ArtEvent (
    artworkassetId VARCHAR(255),
    eventId VARCHAR(255),
    eventType VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    attendees INTEGER,
    PRIMARY KEY(eventId)
);


create table Elevator (
    acquisitionCost float(8),
    totalFloors INTEGER,
    operationalStatusID INTEGER,
    capacity INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    name VARCHAR(255),
    typeID INTEGER,
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    assetId VARCHAR(255),
    currentFloor INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Elevator.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Elevator.assetId is 'Die universelle Id des Assets';

create table ElevatorsMaintenanceLog (
    resolved boolean,
    elevatorassetId VARCHAR(255),
    logId VARCHAR(255),
    serviceTime TIMESTAMP,
    technician VARCHAR(255),
    work VARCHAR(255),
    PRIMARY KEY(logId)
);


create table EmissionReport (
    sourceID INTEGER,
    reportId VARCHAR(255),
    amount float(8),
    unit VARCHAR(255),
    measurementDate DATE,
    verified boolean,
    PRIMARY KEY(reportId)
);


create table ClimateProject (
    isActive boolean,
    strategyID INTEGER,
    projectId VARCHAR(255),
    description VARCHAR(255),
    startDate DATE,
    budget float(8),
    PRIMARY KEY(projectId)
);


create table SnowRoute (
    length float(8),
    estimatedTime INTEGER,
    isCleared boolean,
    lastCleared TIMESTAMP,
    priorityID INTEGER,
    routeId VARCHAR(255),
    PRIMARY KEY(routeId)
);


create table TreatmentOperation (
    routerouteId VARCHAR(255),
    operationId VARCHAR(255),
    startTime TIMESTAMP,
    completionTime TIMESTAMP,
    materialUsed float(8),
    typeID INTEGER,
    PRIMARY KEY(operationId)
);


create table WildlifeZone (
    area float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastSurvey DATE,
    installationDate DATE,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    name VARCHAR(255),
    isProtected boolean,
    typeID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column WildlifeZone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column WildlifeZone.assetId is 'Die universelle Id des Assets';

create table WildlifeZone_presentSpecies (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column WildlifeZone_presentSpecies.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column WildlifeZone_presentSpecies.ValueID is 'Teil der Werte des Sets';

create table WildlifeIncident (
    speciesID INTEGER,
    incidentId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresAction boolean,
    resolution VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table PublicBathroom (
    lastCleaning TIMESTAMP,
    assetId VARCHAR(255),
    isOccupied boolean,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    hasChangingTable boolean,
    cleaningStatusID INTEGER,
    statusID INTEGER,
    typeID INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column PublicBathroom.assetId is 'Die universelle Id des Assets';
comment on column PublicBathroom.priorityID is 'the priority of the asset
the priority of the asset';

create table MaintenanceTicket (
    isUrgent boolean,
    resolved boolean,
    bathroomassetId VARCHAR(255),
    ticketId VARCHAR(255),
    issue VARCHAR(255),
    reportTime TIMESTAMP,
    PRIMARY KEY(ticketId)
);


create table ManufacturingPlant (
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    productionCapacity float(8),
    assetId VARCHAR(255),
    employeeCount INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    shiftCount INTEGER,
    acquisitionCost float(8),
    isTwentyFourSeven boolean,
    statusID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    expectedLifespanYears INTEGER,
    totalArea float(8),
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column ManufacturingPlant.assetId is 'Die universelle Id des Assets';

create table ManufacturingPlant_certifications (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column ManufacturingPlant_certifications.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_certifications.ValueID is 'Teil der Werte des Sets';

create table ManufacturingPlant_safetyProtocols (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column ManufacturingPlant_safetyProtocols.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_safetyProtocols.Value is 'Werte des Sets';

create table ManufacturingPlant_productionTypes (
    RefassetId VARCHAR(255),
    Index INTEGER,
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, Index)
);

comment on column ManufacturingPlant_productionTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_productionTypes.Index is 'Die Index des Listeneintrags';
comment on column ManufacturingPlant_productionTypes.ValueID is 'Teil der Werte der Liste';

create table ProductionLine (
    lineId VARCHAR(255),
    workerCount INTEGER,
    outputRate float(8),
    currentProduct VARCHAR(255),
    lastStartup TIMESTAMP,
    typeID INTEGER,
    statusID INTEGER,
    metricsefficiency float(8),
    metricstargetOutput INTEGER,
    metricsactualOutput INTEGER,
    metricsdefectRate INTEGER,
    metricsenergyConsumption float(8),
    metricsmaterialWaste float(8),
    PRIMARY KEY(lineId)
);


create table Machine (
    installationDate DATE,
    powerConsumption float(8),
    statusID INTEGER,
    maintenanceresponsible VARCHAR(255),
    maintenancelastMaintenance DATE,
    maintenancenextMaintenance DATE,
    maintenancefrequency INTEGER,
    maintenancetasks VARCHAR(255),
    machineId VARCHAR(255),
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    PRIMARY KEY(machineId)
);


create table Machine_capabilities (
    RefmachineId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefmachineId, Value)
);

comment on column Machine_capabilities.RefmachineId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Machine_capabilities.Value is 'Werte des Sets';

create table QualityCheck (
    action VARCHAR(255),
    linelineId VARCHAR(255),
    checkId VARCHAR(255),
    timestamp TIMESTAMP,
    inspector VARCHAR(255),
    passed boolean,
    PRIMARY KEY(checkId)
);


create table QualityCheck_parameters (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column QualityCheck_parameters.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column QualityCheck_parameters.Index is 'Die Index des Listeneintrags';
comment on column QualityCheck_parameters.Value is 'Werte der Liste';

create table QualityCheck_defects (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column QualityCheck_defects.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column QualityCheck_defects.Index is 'Die Index des Listeneintrags';
comment on column QualityCheck_defects.Value is 'Werte der Liste';

create table MaterialInventory (
    storageLocation VARCHAR(255),
    hazardous boolean,
    inventoryId VARCHAR(255),
    materialType VARCHAR(255),
    quantity float(8),
    unit VARCHAR(255),
    expiryDate DATE,
    supplier VARCHAR(255),
    PRIMARY KEY(inventoryId)
);


create table Patient (
    vitalsheartRate INTEGER,
    vitalsbloodPressureSystolic INTEGER,
    vitalsbloodPressureDiastolic INTEGER,
    vitalsrespiratoryRate INTEGER,
    vitalsoxygenSaturation float(8),
    vitalstemperature float(8),
    patientId VARCHAR(255),
    bloodType VARCHAR(255),
    admissionDate DATE,
    statusID INTEGER,
    departmentID INTEGER,
    PRIMARY KEY(patientId)
);


create table Patient_allergies (
    RefpatientId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefpatientId, Value)
);

comment on column Patient_allergies.RefpatientId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Patient_allergies.Value is 'Werte des Sets';

create table Patient_medications (
    RefpatientId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefpatientId, Index)
);

comment on column Patient_medications.RefpatientId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Patient_medications.Index is 'Die Index des Listeneintrags';
comment on column Patient_medications.Value is 'Werte der Liste';

create table Treatment (
    patientpatientId VARCHAR(255),
    treatmentId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    provider VARCHAR(255),
    notes VARCHAR(255),
    completed boolean,
    typeID INTEGER,
    PRIMARY KEY(treatmentId)
);


create table LibraryBranch (
    branchName VARCHAR(255),
    capacity INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    priorityID INTEGER,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    installationDate DATE,
    computerStations INTEGER,
    hasStudyRooms boolean,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch.priorityID is 'the priority of the asset
the priority of the asset';
comment on column LibraryBranch.assetId is 'Die universelle Id des Assets';

create table LibraryBranch_facilities (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column LibraryBranch_facilities.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LibraryBranch_facilities.Index is 'Die Index des Listeneintrags';
comment on column LibraryBranch_facilities.Value is 'Werte der Liste';

create table LibraryBranch_operatingHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column LibraryBranch_operatingHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LibraryBranch_operatingHours.Index is 'Die Index des Listeneintrags';
comment on column LibraryBranch_operatingHours.Value is 'Werte der Liste';

create table LibraryResource (
    location VARCHAR(255),
    isAvailable boolean,
    typeID INTEGER,
    resourceId VARCHAR(255),
    title VARCHAR(255),
    publicationDate DATE,
    publisher VARCHAR(255),
    PRIMARY KEY(resourceId)
);


create table LibraryResource_authors (
    RefresourceId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefresourceId, Index)
);

comment on column LibraryResource_authors.RefresourceId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LibraryResource_authors.Index is 'Die Index des Listeneintrags';
comment on column LibraryResource_authors.Value is 'Werte der Liste';

create table LibraryMember (
    email VARCHAR(255),
    joinDate DATE,
    membershipExpiry DATE,
    isActive boolean,
    currentBorrows INTEGER,
    levelID INTEGER,
    memberId VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(memberId)
);


create table LoanTransaction (
    isOverdue boolean,
    fineAmount float(8),
    membermemberId VARCHAR(255),
    resourceresourceId VARCHAR(255),
    loanId VARCHAR(255),
    borrowDate TIMESTAMP,
    dueDate TIMESTAMP,
    returnDate TIMESTAMP,
    PRIMARY KEY(loanId)
);


create table StudyRoom (
    roomId VARCHAR(255),
    capacity INTEGER,
    hasProjector boolean,
    hasWhiteboard boolean,
    isOccupied boolean,
    branchassetId VARCHAR(255),
    PRIMARY KEY(roomId)
);


create table StudyRoom_reservations (
    RefroomId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefroomId, Index)
);

comment on column StudyRoom_reservations.RefroomId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column StudyRoom_reservations.Index is 'Die Index des Listeneintrags';
comment on column StudyRoom_reservations.Value is 'Werte der Liste';

create table Pet (
    birthDate DATE,
    ownerName VARCHAR(255),
    microchipId VARCHAR(255),
    typeID INTEGER,
    licenseStatusID INTEGER,
    petId VARCHAR(255),
    name VARCHAR(255),
    breed VARCHAR(255),
    PRIMARY KEY(petId)
);


create table VeterinaryClinic (
    statusID INTEGER,
    hasLaboratory boolean,
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    capacity INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    installationDate DATE,
    emergencyTwentyFourHour boolean,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    clinicName VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic.priorityID is 'the priority of the asset
the priority of the asset';
comment on column VeterinaryClinic.assetId is 'Die universelle Id des Assets';

create table VeterinaryClinic_services (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column VeterinaryClinic_services.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column VeterinaryClinic_services.Index is 'Die Index des Listeneintrags';
comment on column VeterinaryClinic_services.Value is 'Werte der Liste';

create table VeterinaryClinic_specialists (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column VeterinaryClinic_specialists.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column VeterinaryClinic_specialists.Value is 'Werte des Sets';

create table AnimalControl (
    incidentType VARCHAR(255),
    location VARCHAR(255),
    resolved boolean,
    resolution VARCHAR(255),
    animalTypeID INTEGER,
    caseId VARCHAR(255),
    reportTime TIMESTAMP,
    PRIMARY KEY(caseId)
);


create table PetLicense (
    statusID INTEGER,
    licenseId VARCHAR(255),
    issueDate DATE,
    expiryDate DATE,
    fee float(8),
    rabiesVaccinated boolean,
    petpetId VARCHAR(255),
    PRIMARY KEY(licenseId)
);


create table AnimalShelter (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acceptsStrays boolean,
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    shelterName VARCHAR(255),
    capacity INTEGER,
    currentOccupancy INTEGER,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    providesVetCare boolean,
    assetId VARCHAR(255),
    installationDate DATE,
    statusID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter.priorityID is 'the priority of the asset
the priority of the asset';
comment on column AnimalShelter.assetId is 'Die universelle Id des Assets';

create table AnimalShelter_services (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column AnimalShelter_services.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AnimalShelter_services.Index is 'Die Index des Listeneintrags';
comment on column AnimalShelter_services.Value is 'Werte der Liste';

create table FilmPermit (
    location VARCHAR(255),
    crewSize INTEGER,
    typeID INTEGER,
    statusID INTEGER,
    permitId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    PRIMARY KEY(permitId)
);


create table FilmPermit_equipment (
    RefpermitId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefpermitId, Index)
);

comment on column FilmPermit_equipment.RefpermitId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FilmPermit_equipment.Index is 'Die Index des Listeneintrags';
comment on column FilmPermit_equipment.Value is 'Werte der Liste';

create table FilmLocation (
    locationName VARCHAR(255),
    maxOccupancy INTEGER,
    statusID INTEGER,
    hasParking boolean,
    name VARCHAR(255),
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    isIndoor boolean,
    assetId VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    dailyRate float(8),
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column FilmLocation.assetId is 'Die universelle Id des Assets';
comment on column FilmLocation.priorityID is 'the priority of the asset
the priority of the asset';

create table FilmLocation_features (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column FilmLocation_features.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FilmLocation_features.Value is 'Werte des Sets';

create table ProductionCrew (
    crewId VARCHAR(255),
    productionCompany VARCHAR(255),
    contactPerson VARCHAR(255),
    permitpermitId VARCHAR(255),
    PRIMARY KEY(crewId)
);


create table ProductionCrew_vehicles (
    RefcrewId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcrewId, Index)
);

comment on column ProductionCrew_vehicles.RefcrewId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ProductionCrew_vehicles.Index is 'Die Index des Listeneintrags';
comment on column ProductionCrew_vehicles.Value is 'Werte der Liste';

create table ProductionCrew_specialNeeds (
    RefcrewId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefcrewId, Value)
);

comment on column ProductionCrew_specialNeeds.RefcrewId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ProductionCrew_specialNeeds.Value is 'Werte des Sets';

create table ImpactNotification (
    notificationId VARCHAR(255),
    noticeTime TIMESTAMP,
    requiresEvacuation boolean,
    permitpermitId VARCHAR(255),
    PRIMARY KEY(notificationId)
);


create table ImpactNotification_affectedAreas (
    RefnotificationId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefnotificationId, Value)
);

comment on column ImpactNotification_affectedAreas.RefnotificationId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ImpactNotification_affectedAreas.Value is 'Werte des Sets';

create table ImpactNotification_mitigation (
    RefnotificationId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefnotificationId, Value)
);

comment on column ImpactNotification_mitigation.RefnotificationId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ImpactNotification_mitigation.Value is 'Werte des Sets';

create table Equipment (
    equipmentId VARCHAR(255),
    type VARCHAR(255),
    specifications VARCHAR(255),
    requiresPermit boolean,
    powerRequirement float(8),
    PRIMARY KEY(equipmentId)
);


create table Equipment_restrictions (
    RefequipmentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefequipmentId, Index)
);

comment on column Equipment_restrictions.RefequipmentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Equipment_restrictions.Index is 'Die Index des Listeneintrags';
comment on column Equipment_restrictions.Value is 'Werte der Liste';

create table Laboratory (
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    totalArea float(8),
    securityLevelID INTEGER,
    hasCleanRoom boolean,
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    workstationCount INTEGER,
    priorityID INTEGER,
    statusID INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column Laboratory.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Laboratory.assetId is 'Die universelle Id des Assets';

create table Laboratory_safetyProtocols (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_safetyProtocols.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_safetyProtocols.Value is 'Werte des Sets';

create table Laboratory_specializations (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_specializations.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_specializations.Value is 'Werte des Sets';

create table Laboratory_certifications (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_certifications.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_certifications.Value is 'Werte des Sets';

create table Laboratory_domains (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Laboratory_domains.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_domains.ValueID is 'Teil der Werte des Sets';

create table Experiment (
    metadatastartDate DATE,
    metadataendDate DATE,
    metadatamethodology VARCHAR(255),
    locationassetId VARCHAR(255),
    scheduledStart TIMESTAMP,
    scheduledEnd TIMESTAMP,
    hasEthicalApproval boolean,
    phaseID INTEGER,
    experimentId VARCHAR(255),
    dependencies VARCHAR(255),
    PRIMARY KEY(experimentId)
);


create table Experiment_prerequisites (
    RefexperimentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefexperimentId, Index)
);

comment on column Experiment_prerequisites.RefexperimentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Experiment_prerequisites.Index is 'Die Index des Listeneintrags';
comment on column Experiment_prerequisites.Value is 'Werte der Liste';

create table ResearchEquipment (
    name VARCHAR(255),
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    manufacturer VARCHAR(255),
    serialNumber VARCHAR(255),
    expectedLifespanYears INTEGER,
    model VARCHAR(255),
    installationDate DATE,
    purchaseDate DATE,
    requiresSpecialTraining boolean,
    priorityID INTEGER,
    statusID INTEGER,
    acquisitionCost float(8),
    warrantyExpiry DATE,
    lastCalibration TIMESTAMP,
    specsprecision float(8),
    specsaccuracy float(8),
    specslastVerification TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column ResearchEquipment.assetId is 'Die universelle Id des Assets';
comment on column ResearchEquipment.priorityID is 'the priority of the asset
the priority of the asset';

create table ResearchEquipment_supportedExperiments (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column ResearchEquipment_supportedExperiments.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResearchEquipment_supportedExperiments.Value is 'Werte des Sets';

create table EnvironmentalControl (
    particleCount float(8),
    controlId VARCHAR(255),
    pressure float(8),
    withinSpecs boolean,
    humidity float(8),
    temperature float(8),
    labassetId VARCHAR(255),
    PRIMARY KEY(controlId)
);


create table EnvironmentalControl_alerts (
    RefcontrolId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcontrolId, Index)
);

comment on column EnvironmentalControl_alerts.RefcontrolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column EnvironmentalControl_alerts.Index is 'Die Index des Listeneintrags';
comment on column EnvironmentalControl_alerts.Value is 'Werte der Liste';

create table EnvironmentalControl_gasLevels (
    RefcontrolId VARCHAR(255),
    Index INTEGER,
    Value float(8),
    PRIMARY KEY(RefcontrolId, Index)
);

comment on column EnvironmentalControl_gasLevels.RefcontrolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column EnvironmentalControl_gasLevels.Index is 'Die Index des Listeneintrags';
comment on column EnvironmentalControl_gasLevels.Value is 'Werte der Liste';

create table DataCollection (
    experimentexperimentId VARCHAR(255),
    classificationID INTEGER,
    datasetId VARCHAR(255),
    sampleSize float(8),
    isBackedUp boolean,
    collectionStart TIMESTAMP,
    collectionEnd TIMESTAMP,
    format VARCHAR(255),
    PRIMARY KEY(datasetId)
);


create table DataCollection_validationRules (
    RefdatasetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefdatasetId, Value)
);

comment on column DataCollection_validationRules.RefdatasetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column DataCollection_validationRules.Value is 'Werte des Sets';

create table SafetyProtocol (
    lastReview DATE,
    requiresTraining boolean,
    labassetId VARCHAR(255),
    protocolId VARCHAR(255),
    hazardType VARCHAR(255),
    PRIMARY KEY(protocolId)
);


create table SafetyProtocol_authorizedPersonnel (
    RefprotocolId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefprotocolId, Value)
);

comment on column SafetyProtocol_authorizedPersonnel.RefprotocolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyProtocol_authorizedPersonnel.Value is 'Werte des Sets';

create table SafetyProtocol_precautions (
    RefprotocolId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefprotocolId, Value)
);

comment on column SafetyProtocol_precautions.RefprotocolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyProtocol_precautions.Value is 'Werte des Sets';

create table SafetyProtocol_emergencyProcedures (
    RefprotocolId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefprotocolId, Value)
);

comment on column SafetyProtocol_emergencyProcedures.RefprotocolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyProtocol_emergencyProcedures.Value is 'Werte des Sets';

create table ComplianceAudit (
    auditor VARCHAR(255),
    passed boolean,
    labassetId VARCHAR(255),
    auditId VARCHAR(255),
    auditDate DATE,
    PRIMARY KEY(auditId)
);


create table ComplianceAudit_protocols (
    RefauditId VARCHAR(255),
    Index INTEGER,
    ValueprotocolId VARCHAR(255),
    PRIMARY KEY(RefauditId, Index)
);

comment on column ComplianceAudit_protocols.RefauditId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceAudit_protocols.Index is 'Die Index des Listeneintrags';
comment on column ComplianceAudit_protocols.ValueprotocolId is 'Teil der Werte der Liste';

create table ComplianceAudit_findings (
    RefauditId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefauditId, Index)
);

comment on column ComplianceAudit_findings.RefauditId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceAudit_findings.Index is 'Die Index des Listeneintrags';
comment on column ComplianceAudit_findings.Value is 'Werte der Liste';

create table ComplianceAudit_recommendations (
    RefauditId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefauditId, Index)
);

comment on column ComplianceAudit_recommendations.RefauditId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceAudit_recommendations.Index is 'Die Index des Listeneintrags';
comment on column ComplianceAudit_recommendations.Value is 'Werte der Liste';

create table ResourceSchedule (
    isOptimized boolean,
    equipmentassetId VARCHAR(255),
    scheduleId VARCHAR(255),
    hasConflicts boolean,
    PRIMARY KEY(scheduleId)
);


create table ResourceSchedule_maintenanceWindows (
    RefscheduleId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefscheduleId, Index)
);

comment on column ResourceSchedule_maintenanceWindows.RefscheduleId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResourceSchedule_maintenanceWindows.Index is 'Die Index des Listeneintrags';
comment on column ResourceSchedule_maintenanceWindows.Value is 'Werte der Liste';

create table ResourceSchedule_experiments (
    RefscheduleId VARCHAR(255),
    Index INTEGER,
    ValueexperimentId VARCHAR(255),
    PRIMARY KEY(RefscheduleId, Index)
);

comment on column ResourceSchedule_experiments.RefscheduleId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResourceSchedule_experiments.Index is 'Die Index des Listeneintrags';
comment on column ResourceSchedule_experiments.ValueexperimentId is 'Teil der Werte der Liste';

create table ResourceSchedule_reservedTimes (
    RefscheduleId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefscheduleId, Index)
);

comment on column ResourceSchedule_reservedTimes.RefscheduleId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResourceSchedule_reservedTimes.Index is 'Die Index des Listeneintrags';
comment on column ResourceSchedule_reservedTimes.Value is 'Werte der Liste';

create table ResourceSchedule_users (
    RefscheduleId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefscheduleId, Value)
);

comment on column ResourceSchedule_users.RefscheduleId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResourceSchedule_users.Value is 'Werte des Sets';

create table Research_facilitiesMaintenanceLog (
    technician VARCHAR(255),
    cost float(8),
    requiresFollowup boolean,
    equipmentassetId VARCHAR(255),
    logId VARCHAR(255),
    maintenanceTime TIMESTAMP,
    PRIMARY KEY(logId)
);


create table Research_facilitiesMaintenanceLog_tasks (
    ReflogId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(ReflogId, Index)
);

comment on column Research_facilitiesMaintenanceLog_tasks.ReflogId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Research_facilitiesMaintenanceLog_tasks.Index is 'Die Index des Listeneintrags';
comment on column Research_facilitiesMaintenanceLog_tasks.Value is 'Werte der Liste';

create table Research_facilitiesMaintenanceLog_replacedParts (
    ReflogId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(ReflogId, Index)
);

comment on column Research_facilitiesMaintenanceLog_replacedParts.ReflogId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Research_facilitiesMaintenanceLog_replacedParts.Index is 'Die Index des Listeneintrags';
comment on column Research_facilitiesMaintenanceLog_replacedParts.Value is 'Werte der Liste';

create table AccessCredential (
    holderName VARCHAR(255),
    validFrom TIMESTAMP,
    validUntil TIMESTAMP,
    isActive boolean,
    labassetId VARCHAR(255),
    clearanceLevelID INTEGER,
    credentialId VARCHAR(255),
    PRIMARY KEY(credentialId)
);


create table AccessCredential_authorizedAreas (
    RefcredentialId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefcredentialId, Value)
);

comment on column AccessCredential_authorizedAreas.RefcredentialId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AccessCredential_authorizedAreas.Value is 'Werte des Sets';

create table FinancialInstitution (
    installationDate DATE,
    statusID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    isActive boolean,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    assetId VARCHAR(255),
    securityLevelID INTEGER,
    institutionId VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FinancialInstitution.assetId is 'Die universelle Id des Assets';
comment on column FinancialInstitution.institutionId is 'Id of the Institution';

create table FinancialInstitution_licenses (
    RefinstitutionId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefinstitutionId, Index)
);

comment on column FinancialInstitution_licenses.RefinstitutionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FinancialInstitution_licenses.Index is 'Die Index des Listeneintrags';
comment on column FinancialInstitution_licenses.Value is 'Werte der Liste';

create table FinancialInstitution_supportedCurrencies (
    RefinstitutionId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefinstitutionId, Value)
);

comment on column FinancialInstitution_supportedCurrencies.RefinstitutionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FinancialInstitution_supportedCurrencies.Value is 'Werte des Sets';

create table FinancialAccount (
    accountType VARCHAR(255),
    currency VARCHAR(255),
    balance float(8),
    isFrozen boolean,
    openedDate DATE,
    institutioninstitutionId VARCHAR(255),
    accountId VARCHAR(255),
    PRIMARY KEY(accountId)
);


create table Transaction (
    transactionId VARCHAR(255),
    destinationaccountId VARCHAR(255),
    isProcessed boolean,
    status VARCHAR(255),
    metadatatimestamp TIMESTAMP,
    metadataamount float(8),
    metadatacurrency VARCHAR(255),
    metadatapurpose VARCHAR(255),
    metadatabeneficiaryId VARCHAR(255),
    metadataoriginatorId VARCHAR(255),
    typeID INTEGER,
    sourceaccountId VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table FraudDetection (
    transactiontransactionId VARCHAR(255),
    detectionId VARCHAR(255),
    requiresReview boolean,
    risklastAssessment DATE,
    riskcreditScore INTEGER,
    riskdefaultProbability float(8),
    resolution VARCHAR(255),
    PRIMARY KEY(detectionId)
);


create table FraudDetection_anomalyIndicators (
    RefdetectionId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefdetectionId, Index)
);

comment on column FraudDetection_anomalyIndicators.RefdetectionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FraudDetection_anomalyIndicators.Index is 'Die Index des Listeneintrags';
comment on column FraudDetection_anomalyIndicators.Value is 'Werte der Liste';

create table ComplianceCheck (
    passedAML boolean,
    passedKYC boolean,
    checkId VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    PRIMARY KEY(checkId)
);


create table ComplianceCheck_violations (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column ComplianceCheck_violations.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceCheck_violations.Index is 'Die Index des Listeneintrags';
comment on column ComplianceCheck_violations.Value is 'Werte der Liste';

create table ComplianceCheck_regulations (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column ComplianceCheck_regulations.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceCheck_regulations.Index is 'Die Index des Listeneintrags';
comment on column ComplianceCheck_regulations.Value is 'Werte der Liste';

create table RegulatoryReport (
    reportingPeriod DATE,
    submitted boolean,
    reportId VARCHAR(255),
    reportType VARCHAR(255),
    institutioninstitutionId VARCHAR(255),
    PRIMARY KEY(reportId)
);


create table RegulatoryReport_findings (
    RefreportId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefreportId, Index)
);

comment on column RegulatoryReport_findings.RefreportId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RegulatoryReport_findings.Index is 'Die Index des Listeneintrags';
comment on column RegulatoryReport_findings.Value is 'Werte der Liste';

create table SecurityIncident (
    incidentId VARCHAR(255),
    description VARCHAR(255),
    impactLevelID INTEGER,
    detectionTime TIMESTAMP,
    resolved boolean,
    PRIMARY KEY(incidentId)
);


create table SecurityIncident_affectedSystems (
    RefincidentId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefincidentId, Value)
);

comment on column SecurityIncident_affectedSystems.RefincidentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SecurityIncident_affectedSystems.Value is 'Werte des Sets';

create table AuditLog (
    performedBy VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    action VARCHAR(255),
    details VARCHAR(255),
    logId VARCHAR(255),
    timestamp TIMESTAMP,
    PRIMARY KEY(logId)
);


create table RiskAssessment (
    assessmentId VARCHAR(255),
    assessmentDate DATE,
    institutioninstitutionId VARCHAR(255),
    profilelastAssessment DATE,
    profilecreditScore INTEGER,
    profiledefaultProbability float(8),
    PRIMARY KEY(assessmentId)
);


create table RiskAssessment_recommendations (
    RefassessmentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassessmentId, Index)
);

comment on column RiskAssessment_recommendations.RefassessmentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RiskAssessment_recommendations.Index is 'Die Index des Listeneintrags';
comment on column RiskAssessment_recommendations.Value is 'Werte der Liste';

create table RiskAssessment_findings (
    RefassessmentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassessmentId, Index)
);

comment on column RiskAssessment_findings.RefassessmentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RiskAssessment_findings.Index is 'Die Index des Listeneintrags';
comment on column RiskAssessment_findings.Value is 'Werte der Liste';

create table AuthenticationSystem (
    systemId VARCHAR(255),
    multiFactorEnabled boolean,
    levelID INTEGER,
    PRIMARY KEY(systemId)
);


create table AuthenticationSystem_blockedIPs (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_blockedIPs.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_blockedIPs.Value is 'Werte des Sets';

create table AuthenticationSystem_activeTokens (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_activeTokens.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_activeTokens.Value is 'Werte des Sets';

create table AuthenticationSystem_supportedMethods (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_supportedMethods.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_supportedMethods.Value is 'Werte des Sets';

