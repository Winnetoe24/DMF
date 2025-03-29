create table Asset (
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    name VARCHAR(255),
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Asset.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Asset.assetId is 'Die universelle Id des Assets';

create table TransportRoute (
    routeId VARCHAR(255),
    routeName VARCHAR(255),
    firstDepartureTime TIMESTAMP,
    lastDepartureTime TIMESTAMP,
    frequencyMinutes INTEGER,
    statusID INTEGER,
    PRIMARY KEY(routeId)
);


create table TransportRoute_segments (
    RefrouteId VARCHAR(255),
    ValuestartPointaltitude float(8),
    ValuestartPointaddressString VARCHAR(255),
    ValuestartPointlatitude float(8),
    ValuestartPointlongitude float(8),
    ValueendPointaltitude float(8),
    ValueendPointaddressString VARCHAR(255),
    ValueendPointlatitude float(8),
    ValueendPointlongitude float(8),
    Valuedistance float(8),
    ValueestimatedTimeMinutes INTEGER,
    PRIMARY KEY(RefrouteId, ValuestartPointaltitude, ValuestartPointaddressString, ValuestartPointlatitude, ValuestartPointlongitude, ValueendPointaltitude, ValueendPointaddressString, ValueendPointlatitude, ValueendPointlongitude, Valuedistance, ValueestimatedTimeMinutes)
);

comment on column TransportRoute_segments.RefrouteId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column TransportRoute_segments.ValuestartPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointaddressString is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaddressString is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.Valuedistance is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueestimatedTimeMinutes is 'Teil der Werte des Sets';

create table Vehicle (
    registrationNumber VARCHAR(255),
    installationDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    acquisitionCost float(8),
    typeID INTEGER,
    priorityID INTEGER,
    currentPassengerCount INTEGER,
    capacity INTEGER,
    currentFuelLevel float(8),
    statusID INTEGER,
    currentRouterouteId VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(registrationNumber)
);

comment on column Vehicle.assetId is 'Die universelle Id des Assets';
comment on column Vehicle.priorityID is 'the priority of the asset
the priority of the asset';

create table PowerPlant (
    installationDate DATE,
    acquisitionCost float(8),
    statusID INTEGER,
    efficiency float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    capacity float(8),
    isBackupSource boolean,
    priorityID INTEGER,
    currentOutput float(8),
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    sourceID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column PowerPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PowerPlant.assetId is 'Die universelle Id des Assets';

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
    name VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    acquisitionCost float(8),
    priorityID INTEGER,
    statusID INTEGER,
    currentLevel float(8),
    capacity float(8),
    isActive boolean,
    lastMaintenanceDate DATE,
    qualityID INTEGER,
    expectedLifespanYears INTEGER,
    flowRate float(8),
    installationDate DATE,
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column WaterSource.priorityID is 'the priority of the asset
the priority of the asset';
comment on column WaterSource.assetId is 'Die universelle Id des Assets';

create table WaterTreatmentPlant (
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    isOperating boolean,
    acquisitionCost float(8),
    priorityID INTEGER,
    statusID INTEGER,
    processingCapacity float(8),
    treatmentStages INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    currentThroughput float(8),
    name VARCHAR(255),
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column WaterTreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column WaterTreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table WasteCollection (
    scheduledTime TIMESTAMP,
    estimatedVolume float(8),
    isCompleted boolean,
    typeID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    collectionId VARCHAR(255),
    PRIMARY KEY(collectionId)
);


create table RecyclingFacility (
    installationDate DATE,
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    currentStorage float(8),
    processingCapacity float(8),
    isAcceptingWaste boolean,
    acquisitionCost float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column RecyclingFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column RecyclingFacility.assetId is 'Die universelle Id des Assets';

create table RecyclingFacility_acceptedTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column RecyclingFacility_acceptedTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RecyclingFacility_acceptedTypes.ValueID is 'Teil der Werte des Sets';

create table MonitoringStation (
    name VARCHAR(255),
    acquisitionCost float(8),
    isCalibrated boolean,
    lastCalibrationDate DATE,
    assetId VARCHAR(255),
    installationDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    statusID INTEGER,
    priorityID INTEGER,
    stationId VARCHAR(255),
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation.assetId is 'Die universelle Id des Assets';
comment on column MonitoringStation.priorityID is 'the priority of the asset
the priority of the asset';

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
    responseTime TIMESTAMP,
    isActive boolean,
    typeID INTEGER,
    priorityID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    incidentId VARCHAR(255),
    reportedTime TIMESTAMP,
    PRIMARY KEY(incidentId)
);


create table EmergencyTeam (
    currentLocationaltitude float(8),
    currentLocationaddressString VARCHAR(255),
    currentLocationlatitude float(8),
    currentLocationlongitude float(8),
    teamId VARCHAR(255),
    memberCount INTEGER,
    isAvailable boolean,
    specialtyID INTEGER,
    PRIMARY KEY(teamId)
);


create table Building (
    totalArea float(8),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    occupancy INTEGER,
    typeID INTEGER,
    name VARCHAR(255),
    floors INTEGER,
    securityLevelID INTEGER,
    acquisitionCost float(8),
    isSmartEnabled boolean,
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column Building.assetId is 'Die universelle Id des Assets';
comment on column Building.priorityID is 'the priority of the asset
the priority of the asset';

create table SmartDevice (
    firmwareVersion VARCHAR(255),
    buildingassetId VARCHAR(255),
    deviceId VARCHAR(255),
    deviceType VARCHAR(255),
    isOnline boolean,
    lastPing TIMESTAMP,
    PRIMARY KEY(deviceId)
);


create table Citizen (
    citizenId VARCHAR(255),
    firstName VARCHAR(255),
    lastName VARCHAR(255),
    dateOfBirth DATE,
    email VARCHAR(255),
    phone VARCHAR(255),
    residencealtitude float(8),
    residenceaddressString VARCHAR(255),
    residencelatitude float(8),
    residencelongitude float(8),
    PRIMARY KEY(citizenId)
);


create table ServiceRequest (
    description VARCHAR(255),
    typeID INTEGER,
    requestercitizenId VARCHAR(255),
    requestId VARCHAR(255),
    submissionTime TIMESTAMP,
    status VARCHAR(255),
    PRIMARY KEY(requestId)
);


create table DataPoint (
    timestamp TIMESTAMP,
    source VARCHAR(255),
    isVerified boolean,
    typeID INTEGER,
    dataId VARCHAR(255),
    value float(8),
    PRIMARY KEY(dataId)
);


create table HealthcareFacility (
    lastMaintenanceDate DATE,
    typeID INTEGER,
    statusID INTEGER,
    hasEmergencyUnit boolean,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    currentOccupancy INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    assetId VARCHAR(255),
    bedCapacity INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column HealthcareFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column HealthcareFacility.assetId is 'Die universelle Id des Assets';

create table HealthcareFacility_specialties (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column HealthcareFacility_specialties.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column HealthcareFacility_specialties.ValueID is 'Teil der Werte des Sets';

create table MedicalEquipment (
    name VARCHAR(255),
    warrantyExpiry DATE,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    assetId VARCHAR(255),
    manufacturer VARCHAR(255),
    requiresCalibration boolean,
    expectedLifespanYears INTEGER,
    equipmentType VARCHAR(255),
    hoursInUse INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column MedicalEquipment.priorityID is 'the priority of the asset
the priority of the asset';
comment on column MedicalEquipment.assetId is 'Die universelle Id des Assets';

create table EducationalInstitution (
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    priorityID INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    statusID INTEGER,
    studentCapacity INTEGER,
    isPublic boolean,
    staffCount INTEGER,
    accreditationStatus VARCHAR(255),
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column EducationalInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column EducationalInstitution.assetId is 'Die universelle Id des Assets';

create table Course (
    courseId VARCHAR(255),
    title VARCHAR(255),
    credits INTEGER,
    maxEnrollment INTEGER,
    isOnline boolean,
    levelID INTEGER,
    PRIMARY KEY(courseId)
);


create table Farm (
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    installationDate DATE,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    area float(8),
    lastHarvestDate DATE,
    isOrganic boolean,
    irrigationTypeID INTEGER,
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Farm.assetId is 'Die universelle Id des Assets';
comment on column Farm.priorityID is 'the priority of the asset
the priority of the asset';

create table Farm_crops (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Farm_crops.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Farm_crops.ValueID is 'Teil der Werte des Sets';

create table Sensor (
    unit VARCHAR(255),
    acquisitionCost float(8),
    sensorType VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    readingValue float(8),
    installationDate DATE,
    assetId VARCHAR(255),
    statusID INTEGER,
    name VARCHAR(255),
    needsCalibration boolean,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    priorityID INTEGER,
    lastReading TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column Sensor.assetId is 'Die universelle Id des Assets';
comment on column Sensor.priorityID is 'the priority of the asset
the priority of the asset';

create table TouristAttraction (
    acquisitionCost float(8),
    isAccessible boolean,
    statusID INTEGER,
    installationDate DATE,
    typeID INTEGER,
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    dailyVisitorCapacity INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    entryFee float(8),
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction.priorityID is 'the priority of the asset
the priority of the asset';
comment on column TouristAttraction.assetId is 'Die universelle Id des Assets';

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
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    expectedAttendance INTEGER,
    seasonID INTEGER,
    eventId VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table ParkingFacility (
    typeID INTEGER,
    totalSpaces INTEGER,
    hourlyRate float(8),
    availableSpaces INTEGER,
    name VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    hasChargingStations boolean,
    installationDate DATE,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column ParkingFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column ParkingFacility.assetId is 'Die universelle Id des Assets';

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
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    conditionID INTEGER,
    priorityID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    temperature float(8),
    humidity float(8),
    precipitation float(8),
    lastMaintenanceDate DATE,
    windSpeed float(8),
    PRIMARY KEY(assetId)
);

comment on column WeatherStation.assetId is 'Die universelle Id des Assets';
comment on column WeatherStation.priorityID is 'the priority of the asset
the priority of the asset';

create table WeatherAlert (
    alertId VARCHAR(255),
    message VARCHAR(255),
    issueTime TIMESTAMP,
    expiryTime TIMESTAMP,
    isActive boolean,
    levelID INTEGER,
    PRIMARY KEY(alertId)
);


create table GridNode (
    voltage float(8),
    assetId VARCHAR(255),
    statusID INTEGER,
    typeID INTEGER,
    priorityID INTEGER,
    current float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    isRedundant boolean,
    profileID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column GridNode.assetId is 'Die universelle Id des Assets';
comment on column GridNode.priorityID is 'the priority of the asset
the priority of the asset';

create table PowerFlow (
    destinationassetId VARCHAR(255),
    flowId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isStable boolean,
    sourceassetId VARCHAR(255),
    PRIMARY KEY(flowId)
);


create table Zone (
    priorityID INTEGER,
    statusID INTEGER,
    typeID INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    area float(8),
    acquisitionCost float(8),
    name VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    installationDate DATE,
    heightLimit INTEGER,
    isHistorical boolean,
    expectedLifespanYears INTEGER,
    maxDensity float(8),
    PRIMARY KEY(assetId)
);

comment on column Zone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Zone.assetId is 'Die universelle Id des Assets';

create table DevelopmentProject (
    startDate DATE,
    completionDate DATE,
    budget float(8),
    statusID INTEGER,
    projectId VARCHAR(255),
    description VARCHAR(255),
    PRIMARY KEY(projectId)
);


create table SafetyIncident (
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresEvacuation boolean,
    typeID INTEGER,
    incidentId VARCHAR(255),
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
    evacuationId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    affectedPopulation INTEGER,
    isCompleted boolean,
    incidentincidentId VARCHAR(255),
    PRIMARY KEY(evacuationId)
);


create table NetworkNode (
    typeID INTEGER,
    installationDate DATE,
    statusID INTEGER,
    connectedDevices INTEGER,
    uptime float(8),
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    isRedundant boolean,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    bandwidthID INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column NetworkNode.priorityID is 'the priority of the asset
the priority of the asset';
comment on column NetworkNode.assetId is 'Die universelle Id des Assets';

create table DataTransfer (
    transferId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isEncrypted boolean,
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    PRIMARY KEY(transferId)
);


create table CulturalVenue (
    lastMaintenanceDate DATE,
    installationDate DATE,
    priorityID INTEGER,
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    capacity INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    hasAccessibility boolean,
    statusID INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue.priorityID is 'the priority of the asset
the priority of the asset';
comment on column CulturalVenue.assetId is 'Die universelle Id des Assets';

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
    ticketingbasePrice float(8),
    ticketingdiscount float(8),
    ticketingavailableSeats INTEGER,
    ticketingisRefundable boolean,
    eventId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    PRIMARY KEY(eventId)
);


create table SportsFacility (
    installationDate DATE,
    priorityID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    expectedLifespanYears INTEGER,
    isIndoor boolean,
    typeID INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    spectatorCapacity INTEGER,
    hasFloodlights boolean,
    assetId VARCHAR(255),
    acquisitionCost float(8),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column SportsFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column SportsFacility.assetId is 'Die universelle Id des Assets';

create table SportsFacility_supportedSports (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column SportsFacility_supportedSports.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SportsFacility_supportedSports.ValueID is 'Teil der Werte des Sets';

create table Tournament (
    startDate DATE,
    endDate DATE,
    participants INTEGER,
    sponsor VARCHAR(255),
    sportID INTEGER,
    tournamentId VARCHAR(255),
    PRIMARY KEY(tournamentId)
);


create table TreatmentPlant (
    priorityID INTEGER,
    isOperational boolean,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    assetId VARCHAR(255),
    currentFlow float(8),
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    installationDate DATE,
    dailyCapacity float(8),
    lastInspection DATE,
    acquisitionCost float(8),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column TreatmentPlant.assetId is 'Die universelle Id des Assets';

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
    value float(8),
    timestamp TIMESTAMP,
    meetsStandard boolean,
    analyst VARCHAR(255),
    metricID INTEGER,
    testId VARCHAR(255),
    PRIMARY KEY(testId)
);


create table TransitCard (
    expiryDate DATE,
    isActive boolean,
    methodID INTEGER,
    fareTypeID INTEGER,
    cardId VARCHAR(255),
    balance float(8),
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
    assetId VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    expectedLifespanYears INTEGER,
    resolution VARCHAR(255),
    contentTypeID INTEGER,
    priorityID INTEGER,
    isInteractive boolean,
    typeID INTEGER,
    name VARCHAR(255),
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column DigitalSign.assetId is 'Die universelle Id des Assets';
comment on column DigitalSign.priorityID is 'the priority of the asset
the priority of the asset';

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
    startDisplay TIMESTAMP,
    endDisplay TIMESTAMP,
    priority INTEGER,
    signassetId VARCHAR(255),
    contentId VARCHAR(255),
    content VARCHAR(255),
    PRIMARY KEY(contentId)
);


create table NoiseSensor (
    needsCalibration boolean,
    sourcesID INTEGER,
    lastPeak TIMESTAMP,
    installationDate DATE,
    lastMaintenanceDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    name VARCHAR(255),
    priorityID INTEGER,
    statusID INTEGER,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    currentLevelID INTEGER,
    averageReading float(8),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column NoiseSensor.priorityID is 'the priority of the asset
the priority of the asset';
comment on column NoiseSensor.assetId is 'Die universelle Id des Assets';

create table NoiseComplaint (
    description VARCHAR(255),
    isResolved boolean,
    resolution VARCHAR(255),
    sourceID INTEGER,
    complaintId VARCHAR(255),
    reportTime TIMESTAMP,
    PRIMARY KEY(complaintId)
);


create table StreetLight (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    energyConsumption float(8),
    expectedLifespanYears INTEGER,
    brightnessID INTEGER,
    hasMotionSensor boolean,
    typeID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    statusID INTEGER,
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column StreetLight.assetId is 'Die universelle Id des Assets';
comment on column StreetLight.priorityID is 'the priority of the asset
the priority of the asset';

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
    schedule VARCHAR(255),
    isDimmed boolean,
    dailyUsage float(8),
    zoneId VARCHAR(255),
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
    statusID INTEGER,
    openTime TIMESTAMP,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    typeID INTEGER,
    name VARCHAR(255),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    acquisitionCost float(8),
    installationDate DATE,
    closeTime TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column Market.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Market.assetId is 'Die universelle Id des Assets';

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
    categoryID INTEGER,
    marketassetId VARCHAR(255),
    vendorId VARCHAR(255),
    products VARCHAR(255),
    isRegistered boolean,
    licenseExpiry DATE,
    PRIMARY KEY(vendorId)
);


create table Drone (
    name VARCHAR(255),
    priorityID INTEGER,
    acquisitionCost float(8),
    flightStatusID INTEGER,
    range float(8),
    typeID INTEGER,
    batteryLevel float(8),
    installationDate DATE,
    statusID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    maxAltitude float(8),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Drone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Drone.assetId is 'Die universelle Id des Assets';

create table FlightMission (
    missionId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    purpose VARCHAR(255),
    isCompleted boolean,
    droneassetId VARCHAR(255),
    PRIMARY KEY(missionId)
);


create table StreetFurniture (
    lastMaintenanceDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    installationDate DATE,
    stateID INTEGER,
    statusID INTEGER,
    assetId VARCHAR(255),
    needsRepair boolean,
    acquisitionCost float(8),
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    name VARCHAR(255),
    material VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column StreetFurniture.assetId is 'Die universelle Id des Assets';
comment on column StreetFurniture.priorityID is 'the priority of the asset
the priority of the asset';

create table MaintenanceRecord (
    recordId VARCHAR(255),
    maintenanceDate DATE,
    work VARCHAR(255),
    cost float(8),
    contractor VARCHAR(255),
    furnitureassetId VARCHAR(255),
    PRIMARY KEY(recordId)
);


create table Restaurant (
    expectedLifespanYears INTEGER,
    hasDelivery boolean,
    installationDate DATE,
    ratingID INTEGER,
    assetId VARCHAR(255),
    seatingCapacity INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    typeID INTEGER,
    name VARCHAR(255),
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Restaurant.assetId is 'Die universelle Id des Assets';
comment on column Restaurant.priorityID is 'the priority of the asset
the priority of the asset';

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
    inspectionDate DATE,
    passed boolean,
    followupDate DATE,
    restaurantassetId VARCHAR(255),
    inspectionId VARCHAR(255),
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
    statusID INTEGER,
    name VARCHAR(255),
    priorityID INTEGER,
    floorArea float(8),
    employeeCount INTEGER,
    acquisitionCost float(8),
    typeID INTEGER,
    segmentID INTEGER,
    lastMaintenanceDate DATE,
    isChainStore boolean,
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    installationDate DATE,
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column RetailStore.priorityID is 'the priority of the asset
the priority of the asset';
comment on column RetailStore.assetId is 'Die universelle Id des Assets';

create table InventoryItem (
    stockLevel INTEGER,
    price float(8),
    isDiscounted boolean,
    storeassetId VARCHAR(255),
    itemId VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(itemId)
);


create table Cemetery (
    acquisitionCost float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    totalPlots INTEGER,
    installationDate DATE,
    priorityID INTEGER,
    totalArea float(8),
    lastMaintenanceDate DATE,
    availablePlots INTEGER,
    name VARCHAR(255),
    statusID INTEGER,
    hasChapel boolean,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Cemetery.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Cemetery.assetId is 'Die universelle Id des Assets';

create table Cemetery_availableTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Cemetery_availableTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Cemetery_availableTypes.ValueID is 'Teil der Werte des Sets';

create table Plot (
    isOccupied boolean,
    owner VARCHAR(255),
    typeID INTEGER,
    scheduleID INTEGER,
    plotId VARCHAR(255),
    lastMaintenance DATE,
    PRIMARY KEY(plotId)
);


create table PostOffice (
    name VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    counterCount INTEGER,
    hasAutomation boolean,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    installationDate DATE,
    staffCount INTEGER,
    storageCapacity float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column PostOffice.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PostOffice.assetId is 'Die universelle Id des Assets';

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
    trackingId VARCHAR(255),
    receivedTime TIMESTAMP,
    estimatedDelivery TIMESTAMP,
    isInsured boolean,
    typeID INTEGER,
    statusID INTEGER,
    PRIMARY KEY(trackingId)
);


create table Artwork (
    statusID INTEGER,
    materials VARCHAR(255),
    acquisitionCost float(8),
    assetId VARCHAR(255),
    typeID INTEGER,
    requiresRestoration boolean,
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    name VARCHAR(255),
    artistTypeID INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Artwork.assetId is 'Die universelle Id des Assets';
comment on column Artwork.priorityID is 'the priority of the asset
the priority of the asset';

create table ArtEvent (
    endTime TIMESTAMP,
    attendees INTEGER,
    artworkassetId VARCHAR(255),
    eventId VARCHAR(255),
    eventType VARCHAR(255),
    startTime TIMESTAMP,
    PRIMARY KEY(eventId)
);


create table Elevator (
    priorityID INTEGER,
    typeID INTEGER,
    installationDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    totalFloors INTEGER,
    operationalStatusID INTEGER,
    name VARCHAR(255),
    currentFloor INTEGER,
    acquisitionCost float(8),
    capacity INTEGER,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Elevator.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Elevator.assetId is 'Die universelle Id des Assets';

create table ElevatorsMaintenanceLog (
    logId VARCHAR(255),
    serviceTime TIMESTAMP,
    technician VARCHAR(255),
    work VARCHAR(255),
    resolved boolean,
    elevatorassetId VARCHAR(255),
    PRIMARY KEY(logId)
);


create table EmissionReport (
    amount float(8),
    unit VARCHAR(255),
    measurementDate DATE,
    verified boolean,
    sourceID INTEGER,
    reportId VARCHAR(255),
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
    priorityID INTEGER,
    routeId VARCHAR(255),
    length float(8),
    estimatedTime INTEGER,
    isCleared boolean,
    lastCleared TIMESTAMP,
    PRIMARY KEY(routeId)
);


create table TreatmentOperation (
    typeID INTEGER,
    routerouteId VARCHAR(255),
    operationId VARCHAR(255),
    startTime TIMESTAMP,
    completionTime TIMESTAMP,
    materialUsed float(8),
    PRIMARY KEY(operationId)
);


create table WildlifeZone (
    acquisitionCost float(8),
    name VARCHAR(255),
    installationDate DATE,
    assetId VARCHAR(255),
    area float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    lastMaintenanceDate DATE,
    isProtected boolean,
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    priorityID INTEGER,
    lastSurvey DATE,
    PRIMARY KEY(assetId)
);

comment on column WildlifeZone.assetId is 'Die universelle Id des Assets';
comment on column WildlifeZone.priorityID is 'the priority of the asset
the priority of the asset';

create table WildlifeZone_presentSpecies (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column WildlifeZone_presentSpecies.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column WildlifeZone_presentSpecies.ValueID is 'Teil der Werte des Sets';

create table WildlifeIncident (
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresAction boolean,
    resolution VARCHAR(255),
    speciesID INTEGER,
    incidentId VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table PublicBathroom (
    statusID INTEGER,
    isOccupied boolean,
    typeID INTEGER,
    hasChangingTable boolean,
    lastMaintenanceDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    acquisitionCost float(8),
    priorityID INTEGER,
    cleaningStatusID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    lastCleaning TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column PublicBathroom.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PublicBathroom.assetId is 'Die universelle Id des Assets';

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
    statusID INTEGER,
    priorityID INTEGER,
    isTwentyFourSeven boolean,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    employeeCount INTEGER,
    totalArea float(8),
    assetId VARCHAR(255),
    acquisitionCost float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    lastMaintenanceDate DATE,
    installationDate DATE,
    productionCapacity float(8),
    shiftCount INTEGER,
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column ManufacturingPlant.assetId is 'Die universelle Id des Assets';

create table ManufacturingPlant_productionTypes (
    RefassetId VARCHAR(255),
    Index INTEGER,
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, Index)
);

comment on column ManufacturingPlant_productionTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_productionTypes.Index is 'Die Index des Listeneintrags';
comment on column ManufacturingPlant_productionTypes.ValueID is 'Teil der Werte der Liste';

create table ManufacturingPlant_safetyProtocols (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column ManufacturingPlant_safetyProtocols.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_safetyProtocols.Value is 'Werte des Sets';

create table ManufacturingPlant_certifications (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column ManufacturingPlant_certifications.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_certifications.ValueID is 'Teil der Werte des Sets';

create table ProductionLine (
    currentProduct VARCHAR(255),
    lastStartup TIMESTAMP,
    typeID INTEGER,
    statusID INTEGER,
    metricsactualOutput INTEGER,
    metricsenergyConsumption float(8),
    metricsmaterialWaste float(8),
    metricstargetOutput INTEGER,
    metricsefficiency float(8),
    metricsdefectRate INTEGER,
    lineId VARCHAR(255),
    workerCount INTEGER,
    outputRate float(8),
    PRIMARY KEY(lineId)
);


create table Machine (
    machineId VARCHAR(255),
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    installationDate DATE,
    powerConsumption float(8),
    statusID INTEGER,
    maintenancenextMaintenance DATE,
    maintenancefrequency INTEGER,
    maintenancetasks VARCHAR(255),
    maintenanceresponsible VARCHAR(255),
    maintenancelastMaintenance DATE,
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
    linelineId VARCHAR(255),
    checkId VARCHAR(255),
    timestamp TIMESTAMP,
    inspector VARCHAR(255),
    passed boolean,
    action VARCHAR(255),
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
    quantity float(8),
    unit VARCHAR(255),
    expiryDate DATE,
    supplier VARCHAR(255),
    storageLocation VARCHAR(255),
    hazardous boolean,
    inventoryId VARCHAR(255),
    materialType VARCHAR(255),
    PRIMARY KEY(inventoryId)
);


create table Patient (
    admissionDate DATE,
    statusID INTEGER,
    departmentID INTEGER,
    vitalstemperature float(8),
    vitalsheartRate INTEGER,
    vitalsbloodPressureSystolic INTEGER,
    vitalsbloodPressureDiastolic INTEGER,
    vitalsrespiratoryRate INTEGER,
    vitalsoxygenSaturation float(8),
    patientId VARCHAR(255),
    bloodType VARCHAR(255),
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
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    provider VARCHAR(255),
    notes VARCHAR(255),
    completed boolean,
    typeID INTEGER,
    patientpatientId VARCHAR(255),
    treatmentId VARCHAR(255),
    PRIMARY KEY(treatmentId)
);


create table LibraryBranch (
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    priorityID INTEGER,
    installationDate DATE,
    capacity INTEGER,
    lastMaintenanceDate DATE,
    branchName VARCHAR(255),
    hasStudyRooms boolean,
    statusID INTEGER,
    name VARCHAR(255),
    computerStations INTEGER,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch.priorityID is 'the priority of the asset
the priority of the asset';
comment on column LibraryBranch.assetId is 'Die universelle Id des Assets';

create table LibraryBranch_operatingHours (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value TIMESTAMP,
    PRIMARY KEY(RefassetId, Index)
);

comment on column LibraryBranch_operatingHours.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LibraryBranch_operatingHours.Index is 'Die Index des Listeneintrags';
comment on column LibraryBranch_operatingHours.Value is 'Werte der Liste';

create table LibraryBranch_facilities (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column LibraryBranch_facilities.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column LibraryBranch_facilities.Index is 'Die Index des Listeneintrags';
comment on column LibraryBranch_facilities.Value is 'Werte der Liste';

create table LibraryResource (
    publicationDate DATE,
    publisher VARCHAR(255),
    location VARCHAR(255),
    isAvailable boolean,
    typeID INTEGER,
    resourceId VARCHAR(255),
    title VARCHAR(255),
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
    dueDate TIMESTAMP,
    returnDate TIMESTAMP,
    isOverdue boolean,
    fineAmount float(8),
    membermemberId VARCHAR(255),
    resourceresourceId VARCHAR(255),
    loanId VARCHAR(255),
    borrowDate TIMESTAMP,
    PRIMARY KEY(loanId)
);


create table StudyRoom (
    capacity INTEGER,
    hasProjector boolean,
    hasWhiteboard boolean,
    isOccupied boolean,
    branchassetId VARCHAR(255),
    roomId VARCHAR(255),
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
    typeID INTEGER,
    licenseStatusID INTEGER,
    petId VARCHAR(255),
    name VARCHAR(255),
    breed VARCHAR(255),
    birthDate DATE,
    ownerName VARCHAR(255),
    microchipId VARCHAR(255),
    PRIMARY KEY(petId)
);


create table VeterinaryClinic (
    installationDate DATE,
    acquisitionCost float(8),
    emergencyTwentyFourHour boolean,
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    hasLaboratory boolean,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    statusID INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    clinicName VARCHAR(255),
    capacity INTEGER,
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic.priorityID is 'the priority of the asset
the priority of the asset';
comment on column VeterinaryClinic.assetId is 'Die universelle Id des Assets';

create table VeterinaryClinic_specialists (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column VeterinaryClinic_specialists.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column VeterinaryClinic_specialists.Value is 'Werte des Sets';

create table VeterinaryClinic_services (
    RefassetId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Index)
);

comment on column VeterinaryClinic_services.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column VeterinaryClinic_services.Index is 'Die Index des Listeneintrags';
comment on column VeterinaryClinic_services.Value is 'Werte der Liste';

create table AnimalControl (
    resolved boolean,
    resolution VARCHAR(255),
    animalTypeID INTEGER,
    caseId VARCHAR(255),
    reportTime TIMESTAMP,
    incidentType VARCHAR(255),
    location VARCHAR(255),
    PRIMARY KEY(caseId)
);


create table PetLicense (
    issueDate DATE,
    expiryDate DATE,
    fee float(8),
    rabiesVaccinated boolean,
    petpetId VARCHAR(255),
    statusID INTEGER,
    licenseId VARCHAR(255),
    PRIMARY KEY(licenseId)
);


create table AnimalShelter (
    acceptsStrays boolean,
    currentOccupancy INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    priorityID INTEGER,
    capacity INTEGER,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    shelterName VARCHAR(255),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    providesVetCare boolean,
    installationDate DATE,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter.priorityID is 'the priority of the asset
the priority of the asset';
comment on column AnimalShelter.assetId is 'Die universelle Id des Assets';

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
    acquisitionCost float(8),
    locationName VARCHAR(255),
    isIndoor boolean,
    maxOccupancy INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    dailyRate float(8),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    hasParking boolean,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column FilmLocation.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FilmLocation.assetId is 'Die universelle Id des Assets';

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
    statusID INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    workstationCount INTEGER,
    acquisitionCost float(8),
    securityLevelID INTEGER,
    assetId VARCHAR(255),
    totalArea float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    priorityID INTEGER,
    hasCleanRoom boolean,
    PRIMARY KEY(assetId)
);

comment on column Laboratory.assetId is 'Die universelle Id des Assets';
comment on column Laboratory.priorityID is 'the priority of the asset
the priority of the asset';

create table Laboratory_certifications (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_certifications.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_certifications.Value is 'Werte des Sets';

create table Laboratory_specializations (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_specializations.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_specializations.Value is 'Werte des Sets';

create table Laboratory_safetyProtocols (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_safetyProtocols.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_safetyProtocols.Value is 'Werte des Sets';

create table Laboratory_domains (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Laboratory_domains.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_domains.ValueID is 'Teil der Werte des Sets';

create table Experiment (
    locationassetId VARCHAR(255),
    scheduledEnd TIMESTAMP,
    metadatamethodology VARCHAR(255),
    metadatastartDate DATE,
    metadataendDate DATE,
    experimentId VARCHAR(255),
    scheduledStart TIMESTAMP,
    hasEthicalApproval boolean,
    dependencies VARCHAR(255),
    phaseID INTEGER,
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
    assetId VARCHAR(255),
    requiresSpecialTraining boolean,
    installationDate DATE,
    lastMaintenanceDate DATE,
    manufacturer VARCHAR(255),
    specsprecision float(8),
    specsaccuracy float(8),
    specslastVerification TIMESTAMP,
    name VARCHAR(255),
    warrantyExpiry DATE,
    acquisitionCost float(8),
    purchaseDate DATE,
    model VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    lastCalibration TIMESTAMP,
    serialNumber VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    PRIMARY KEY(assetId)
);

comment on column ResearchEquipment.assetId is 'Die universelle Id des Assets';
comment on column ResearchEquipment.priorityID is 'the priority of the asset
the priority of the asset';

create table ResearchEquipment_supportedExperiments (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column ResearchEquipment_supportedExperiments.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResearchEquipment_supportedExperiments.Value is 'Werte des Sets';

create table EnvironmentalControl (
    particleCount float(8),
    temperature float(8),
    humidity float(8),
    withinSpecs boolean,
    controlId VARCHAR(255),
    pressure float(8),
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
    collectionStart TIMESTAMP,
    collectionEnd TIMESTAMP,
    classificationID INTEGER,
    datasetId VARCHAR(255),
    format VARCHAR(255),
    sampleSize float(8),
    isBackedUp boolean,
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
    protocolId VARCHAR(255),
    hazardType VARCHAR(255),
    lastReview DATE,
    requiresTraining boolean,
    labassetId VARCHAR(255),
    PRIMARY KEY(protocolId)
);


create table SafetyProtocol_emergencyProcedures (
    RefprotocolId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefprotocolId, Value)
);

comment on column SafetyProtocol_emergencyProcedures.RefprotocolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyProtocol_emergencyProcedures.Value is 'Werte des Sets';

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

create table ComplianceAudit (
    auditId VARCHAR(255),
    auditDate DATE,
    auditor VARCHAR(255),
    passed boolean,
    labassetId VARCHAR(255),
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
    scheduleId VARCHAR(255),
    hasConflicts boolean,
    isOptimized boolean,
    equipmentassetId VARCHAR(255),
    PRIMARY KEY(scheduleId)
);


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

create table ResourceSchedule_maintenanceWindows (
    RefscheduleId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefscheduleId, Index)
);

comment on column ResourceSchedule_maintenanceWindows.RefscheduleId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ResourceSchedule_maintenanceWindows.Index is 'Die Index des Listeneintrags';
comment on column ResourceSchedule_maintenanceWindows.Value is 'Werte der Liste';

create table Research_facilitiesMaintenanceLog (
    equipmentassetId VARCHAR(255),
    logId VARCHAR(255),
    maintenanceTime TIMESTAMP,
    technician VARCHAR(255),
    cost float(8),
    requiresFollowup boolean,
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
    credentialId VARCHAR(255),
    holderName VARCHAR(255),
    validFrom TIMESTAMP,
    validUntil TIMESTAMP,
    isActive boolean,
    labassetId VARCHAR(255),
    clearanceLevelID INTEGER,
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
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    institutionId VARCHAR(255),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    isActive boolean,
    securityLevelID INTEGER,
    installationDate DATE,
    assetId VARCHAR(255),
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution.institutionId is 'Id of the Institution';
comment on column FinancialInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FinancialInstitution.assetId is 'Die universelle Id des Assets';

create table FinancialInstitution_supportedCurrencies (
    RefinstitutionId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefinstitutionId, Value)
);

comment on column FinancialInstitution_supportedCurrencies.RefinstitutionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FinancialInstitution_supportedCurrencies.Value is 'Werte des Sets';

create table FinancialInstitution_licenses (
    RefinstitutionId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefinstitutionId, Index)
);

comment on column FinancialInstitution_licenses.RefinstitutionId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FinancialInstitution_licenses.Index is 'Die Index des Listeneintrags';
comment on column FinancialInstitution_licenses.Value is 'Werte der Liste';

create table FinancialAccount (
    accountId VARCHAR(255),
    institutioninstitutionId VARCHAR(255),
    accountType VARCHAR(255),
    balance float(8),
    currency VARCHAR(255),
    isFrozen boolean,
    openedDate DATE,
    PRIMARY KEY(accountId)
);


create table Transaction (
    destinationaccountId VARCHAR(255),
    status VARCHAR(255),
    transactionId VARCHAR(255),
    typeID INTEGER,
    metadatabeneficiaryId VARCHAR(255),
    metadatatimestamp TIMESTAMP,
    metadatacurrency VARCHAR(255),
    metadataamount float(8),
    metadatapurpose VARCHAR(255),
    metadataoriginatorId VARCHAR(255),
    sourceaccountId VARCHAR(255),
    isProcessed boolean,
    PRIMARY KEY(transactionId)
);


create table FraudDetection (
    requiresReview boolean,
    transactiontransactionId VARCHAR(255),
    riskcreditScore INTEGER,
    riskdefaultProbability float(8),
    risklastAssessment DATE,
    detectionId VARCHAR(255),
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
    passedKYC boolean,
    passedAML boolean,
    transactiontransactionId VARCHAR(255),
    checkId VARCHAR(255),
    PRIMARY KEY(checkId)
);


create table ComplianceCheck_regulations (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column ComplianceCheck_regulations.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceCheck_regulations.Index is 'Die Index des Listeneintrags';
comment on column ComplianceCheck_regulations.Value is 'Werte der Liste';

create table ComplianceCheck_violations (
    RefcheckId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcheckId, Index)
);

comment on column ComplianceCheck_violations.RefcheckId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ComplianceCheck_violations.Index is 'Die Index des Listeneintrags';
comment on column ComplianceCheck_violations.Value is 'Werte der Liste';

create table RegulatoryReport (
    reportingPeriod DATE,
    institutioninstitutionId VARCHAR(255),
    reportId VARCHAR(255),
    reportType VARCHAR(255),
    submitted boolean,
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
    impactLevelID INTEGER,
    detectionTime TIMESTAMP,
    description VARCHAR(255),
    resolved boolean,
    incidentId VARCHAR(255),
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
    logId VARCHAR(255),
    action VARCHAR(255),
    details VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    timestamp TIMESTAMP,
    PRIMARY KEY(logId)
);


create table RiskAssessment (
    institutioninstitutionId VARCHAR(255),
    assessmentId VARCHAR(255),
    profilecreditScore INTEGER,
    profiledefaultProbability float(8),
    profilelastAssessment DATE,
    assessmentDate DATE,
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

create table AuthenticationSystem_supportedMethods (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_supportedMethods.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_supportedMethods.Value is 'Werte des Sets';

create table AuthenticationSystem_activeTokens (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_activeTokens.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_activeTokens.Value is 'Werte des Sets';

