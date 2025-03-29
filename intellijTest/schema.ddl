create table Asset (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Asset.assetId is 'Die universelle Id des Assets';
comment on column Asset.priorityID is 'the priority of the asset
the priority of the asset';

create table TransportRoute (
    routeId VARCHAR(255),
    routeName VARCHAR(255),
    statusID INTEGER,
    firstDepartureTime TIMESTAMP,
    lastDepartureTime TIMESTAMP,
    frequencyMinutes INTEGER,
    PRIMARY KEY(routeId)
);


create table TransportRoute_segments (
    RefrouteId VARCHAR(255),
    ValuestartPointlatitude float(8),
    ValuestartPointlongitude float(8),
    ValuestartPointaltitude float(8),
    ValuestartPointaddressString VARCHAR(255),
    ValueendPointlatitude float(8),
    ValueendPointlongitude float(8),
    ValueendPointaltitude float(8),
    ValueendPointaddressString VARCHAR(255),
    Valuedistance float(8),
    ValueestimatedTimeMinutes INTEGER,
    PRIMARY KEY(RefrouteId, ValuestartPointlatitude, ValuestartPointlongitude, ValuestartPointaltitude, ValuestartPointaddressString, ValueendPointlatitude, ValueendPointlongitude, ValueendPointaltitude, ValueendPointaddressString, Valuedistance, ValueestimatedTimeMinutes)
);

comment on column TransportRoute_segments.RefrouteId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column TransportRoute_segments.ValuestartPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValuestartPointaddressString is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointlatitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointlongitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaltitude is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueendPointaddressString is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.Valuedistance is 'Teil der Werte des Sets';
comment on column TransportRoute_segments.ValueestimatedTimeMinutes is 'Teil der Werte des Sets';

create table Vehicle (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    registrationNumber VARCHAR(255),
    capacity INTEGER,
    currentFuelLevel float(8),
    currentPassengerCount INTEGER,
    currentRouterouteId VARCHAR(255),
    PRIMARY KEY(registrationNumber)
);

comment on column Vehicle.assetId is 'Die universelle Id des Assets';
comment on column Vehicle.priorityID is 'the priority of the asset
the priority of the asset';

create table PowerPlant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    sourceID INTEGER,
    capacity float(8),
    currentOutput float(8),
    efficiency float(8),
    isBackupSource boolean,
    PRIMARY KEY(assetId)
);

comment on column PowerPlant.assetId is 'Die universelle Id des Assets';
comment on column PowerPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table SmartMeter (
    meterId VARCHAR(255),
    patternID INTEGER,
    currentReading float(8),
    peakDemand float(8),
    lastReadingTime TIMESTAMP,
    isOnline boolean,
    PRIMARY KEY(meterId)
);


create table WaterSource (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    capacity float(8),
    currentLevel float(8),
    qualityID INTEGER,
    flowRate float(8),
    isActive boolean,
    PRIMARY KEY(assetId)
);

comment on column WaterSource.assetId is 'Die universelle Id des Assets';
comment on column WaterSource.priorityID is 'the priority of the asset
the priority of the asset';

create table WaterTreatmentPlant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    processingCapacity float(8),
    currentThroughput float(8),
    treatmentStages INTEGER,
    isOperating boolean,
    PRIMARY KEY(assetId)
);

comment on column WaterTreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column WaterTreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table WasteCollection (
    collectionId VARCHAR(255),
    typeID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    scheduledTime TIMESTAMP,
    estimatedVolume float(8),
    isCompleted boolean,
    PRIMARY KEY(collectionId)
);


create table RecyclingFacility (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    processingCapacity float(8),
    currentStorage float(8),
    isAcceptingWaste boolean,
    PRIMARY KEY(assetId)
);

comment on column RecyclingFacility.assetId is 'Die universelle Id des Assets';
comment on column RecyclingFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table RecyclingFacility_acceptedTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column RecyclingFacility_acceptedTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RecyclingFacility_acceptedTypes.ValueID is 'Teil der Werte des Sets';

create table MonitoringStation (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    stationId VARCHAR(255),
    isCalibrated boolean,
    lastCalibrationDate DATE,
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation.assetId is 'Die universelle Id des Assets';
comment on column MonitoringStation.priorityID is 'the priority of the asset
the priority of the asset';

create table MonitoringStation_readings (
    RefstationId VARCHAR(255),
    Index INTEGER,
    ValuepollutantID INTEGER,
    Valueconcentration float(8),
    Valuetimestamp TIMESTAMP,
    ValueexceedsLimit boolean,
    PRIMARY KEY(RefstationId, Index)
);

comment on column MonitoringStation_readings.RefstationId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column MonitoringStation_readings.Index is 'Die Index des Listeneintrags';
comment on column MonitoringStation_readings.ValuepollutantID is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.Valueconcentration is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.Valuetimestamp is 'Teil der Werte der Liste';
comment on column MonitoringStation_readings.ValueexceedsLimit is 'Teil der Werte der Liste';

create table EmergencyIncident (
    incidentId VARCHAR(255),
    typeID INTEGER,
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    reportedTime TIMESTAMP,
    responseTime TIMESTAMP,
    isActive boolean,
    PRIMARY KEY(incidentId)
);


create table EmergencyTeam (
    teamId VARCHAR(255),
    specialtyID INTEGER,
    memberCount INTEGER,
    currentLocationlatitude float(8),
    currentLocationlongitude float(8),
    currentLocationaltitude float(8),
    currentLocationaddressString VARCHAR(255),
    isAvailable boolean,
    PRIMARY KEY(teamId)
);


create table Building (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    floors INTEGER,
    totalArea float(8),
    occupancy INTEGER,
    securityLevelID INTEGER,
    isSmartEnabled boolean,
    PRIMARY KEY(assetId)
);

comment on column Building.assetId is 'Die universelle Id des Assets';
comment on column Building.priorityID is 'the priority of the asset
the priority of the asset';

create table SmartDevice (
    deviceId VARCHAR(255),
    buildingassetId VARCHAR(255),
    deviceType VARCHAR(255),
    isOnline boolean,
    lastPing TIMESTAMP,
    firmwareVersion VARCHAR(255),
    PRIMARY KEY(deviceId)
);


create table Citizen (
    citizenId VARCHAR(255),
    firstName VARCHAR(255),
    lastName VARCHAR(255),
    residencelatitude float(8),
    residencelongitude float(8),
    residencealtitude float(8),
    residenceaddressString VARCHAR(255),
    dateOfBirth DATE,
    email VARCHAR(255),
    phone VARCHAR(255),
    PRIMARY KEY(citizenId)
);


create table ServiceRequest (
    requestId VARCHAR(255),
    typeID INTEGER,
    requestercitizenId VARCHAR(255),
    submissionTime TIMESTAMP,
    status VARCHAR(255),
    description VARCHAR(255),
    PRIMARY KEY(requestId)
);


create table DataPoint (
    dataId VARCHAR(255),
    typeID INTEGER,
    value float(8),
    timestamp TIMESTAMP,
    source VARCHAR(255),
    isVerified boolean,
    PRIMARY KEY(dataId)
);


create table HealthcareFacility (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    bedCapacity INTEGER,
    currentOccupancy INTEGER,
    hasEmergencyUnit boolean,
    PRIMARY KEY(assetId)
);

comment on column HealthcareFacility.assetId is 'Die universelle Id des Assets';
comment on column HealthcareFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table HealthcareFacility_specialties (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column HealthcareFacility_specialties.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column HealthcareFacility_specialties.ValueID is 'Teil der Werte des Sets';

create table MedicalEquipment (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    equipmentType VARCHAR(255),
    manufacturer VARCHAR(255),
    warrantyExpiry DATE,
    hoursInUse INTEGER,
    requiresCalibration boolean,
    PRIMARY KEY(assetId)
);

comment on column MedicalEquipment.assetId is 'Die universelle Id des Assets';
comment on column MedicalEquipment.priorityID is 'the priority of the asset
the priority of the asset';

create table EducationalInstitution (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    studentCapacity INTEGER,
    staffCount INTEGER,
    isPublic boolean,
    accreditationStatus VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column EducationalInstitution.assetId is 'Die universelle Id des Assets';
comment on column EducationalInstitution.priorityID is 'the priority of the asset
the priority of the asset';

create table Course (
    courseId VARCHAR(255),
    levelID INTEGER,
    title VARCHAR(255),
    credits INTEGER,
    maxEnrollment INTEGER,
    isOnline boolean,
    PRIMARY KEY(courseId)
);


create table Farm (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    area float(8),
    irrigationTypeID INTEGER,
    isOrganic boolean,
    lastHarvestDate DATE,
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    sensorType VARCHAR(255),
    readingValue float(8),
    unit VARCHAR(255),
    lastReading TIMESTAMP,
    needsCalibration boolean,
    PRIMARY KEY(assetId)
);

comment on column Sensor.assetId is 'Die universelle Id des Assets';
comment on column Sensor.priorityID is 'the priority of the asset
the priority of the asset';

create table TouristAttraction (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    dailyVisitorCapacity INTEGER,
    entryFee float(8),
    isAccessible boolean,
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction.assetId is 'Die universelle Id des Assets';
comment on column TouristAttraction.priorityID is 'the priority of the asset
the priority of the asset';

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
    eventId VARCHAR(255),
    seasonID INTEGER,
    name VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    expectedAttendance INTEGER,
    PRIMARY KEY(eventId)
);


create table ParkingFacility (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    totalSpaces INTEGER,
    availableSpaces INTEGER,
    hourlyRate float(8),
    hasChargingStations boolean,
    PRIMARY KEY(assetId)
);

comment on column ParkingFacility.assetId is 'Die universelle Id des Assets';
comment on column ParkingFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table ParkingTransaction (
    transactionId VARCHAR(255),
    vehicleSizeID INTEGER,
    entryTime TIMESTAMP,
    exitTime TIMESTAMP,
    amount float(8),
    isPaid boolean,
    PRIMARY KEY(transactionId)
);


create table WeatherStation (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    temperature float(8),
    humidity float(8),
    windSpeed float(8),
    precipitation float(8),
    conditionID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WeatherStation.assetId is 'Die universelle Id des Assets';
comment on column WeatherStation.priorityID is 'the priority of the asset
the priority of the asset';

create table WeatherAlert (
    alertId VARCHAR(255),
    levelID INTEGER,
    message VARCHAR(255),
    issueTime TIMESTAMP,
    expiryTime TIMESTAMP,
    isActive boolean,
    PRIMARY KEY(alertId)
);


create table GridNode (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    voltage float(8),
    current float(8),
    profileID INTEGER,
    isRedundant boolean,
    PRIMARY KEY(assetId)
);

comment on column GridNode.assetId is 'Die universelle Id des Assets';
comment on column GridNode.priorityID is 'the priority of the asset
the priority of the asset';

create table PowerFlow (
    flowId VARCHAR(255),
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isStable boolean,
    PRIMARY KEY(flowId)
);


create table Zone (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    area float(8),
    maxDensity float(8),
    heightLimit INTEGER,
    isHistorical boolean,
    PRIMARY KEY(assetId)
);

comment on column Zone.assetId is 'Die universelle Id des Assets';
comment on column Zone.priorityID is 'the priority of the asset
the priority of the asset';

create table DevelopmentProject (
    projectId VARCHAR(255),
    statusID INTEGER,
    description VARCHAR(255),
    startDate DATE,
    completionDate DATE,
    budget float(8),
    PRIMARY KEY(projectId)
);


create table SafetyIncident (
    incidentId VARCHAR(255),
    typeID INTEGER,
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresEvacuation boolean,
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
    incidentincidentId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    affectedPopulation INTEGER,
    isCompleted boolean,
    PRIMARY KEY(evacuationId)
);


create table NetworkNode (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    bandwidthID INTEGER,
    connectedDevices INTEGER,
    uptime float(8),
    isRedundant boolean,
    PRIMARY KEY(assetId)
);

comment on column NetworkNode.assetId is 'Die universelle Id des Assets';
comment on column NetworkNode.priorityID is 'the priority of the asset
the priority of the asset';

create table DataTransfer (
    transferId VARCHAR(255),
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isEncrypted boolean,
    PRIMARY KEY(transferId)
);


create table CulturalVenue (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    capacity INTEGER,
    hasAccessibility boolean,
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue.assetId is 'Die universelle Id des Assets';
comment on column CulturalVenue.priorityID is 'the priority of the asset
the priority of the asset';

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
    eventId VARCHAR(255),
    categoryID INTEGER,
    ticketingbasePrice float(8),
    ticketingdiscount float(8),
    ticketingavailableSeats INTEGER,
    ticketingisRefundable boolean,
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    curator VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table SportsFacility (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    spectatorCapacity INTEGER,
    hasFloodlights boolean,
    isIndoor boolean,
    PRIMARY KEY(assetId)
);

comment on column SportsFacility.assetId is 'Die universelle Id des Assets';
comment on column SportsFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table SportsFacility_supportedSports (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column SportsFacility_supportedSports.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SportsFacility_supportedSports.ValueID is 'Teil der Werte des Sets';

create table Tournament (
    tournamentId VARCHAR(255),
    sportID INTEGER,
    startDate DATE,
    endDate DATE,
    participants INTEGER,
    sponsor VARCHAR(255),
    PRIMARY KEY(tournamentId)
);


create table TreatmentPlant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    dailyCapacity float(8),
    currentFlow float(8),
    isOperational boolean,
    lastInspection DATE,
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column TreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';

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
    testId VARCHAR(255),
    metricID INTEGER,
    value float(8),
    timestamp TIMESTAMP,
    meetsStandard boolean,
    analyst VARCHAR(255),
    PRIMARY KEY(testId)
);


create table TransitCard (
    cardId VARCHAR(255),
    methodID INTEGER,
    fareTypeID INTEGER,
    balance float(8),
    expiryDate DATE,
    isActive boolean,
    PRIMARY KEY(cardId)
);


create table FareTransaction (
    transactionId VARCHAR(255),
    cardcardId VARCHAR(255),
    timestamp TIMESTAMP,
    amount float(8),
    route VARCHAR(255),
    isRefunded boolean,
    PRIMARY KEY(transactionId)
);


create table DigitalSign (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    contentTypeID INTEGER,
    resolution VARCHAR(255),
    isInteractive boolean,
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
    contentId VARCHAR(255),
    signassetId VARCHAR(255),
    content VARCHAR(255),
    startDisplay TIMESTAMP,
    endDisplay TIMESTAMP,
    priority INTEGER,
    PRIMARY KEY(contentId)
);


create table NoiseSensor (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    sourcesID INTEGER,
    currentLevelID INTEGER,
    averageReading float(8),
    lastPeak TIMESTAMP,
    needsCalibration boolean,
    PRIMARY KEY(assetId)
);

comment on column NoiseSensor.assetId is 'Die universelle Id des Assets';
comment on column NoiseSensor.priorityID is 'the priority of the asset
the priority of the asset';

create table NoiseComplaint (
    complaintId VARCHAR(255),
    sourceID INTEGER,
    reportTime TIMESTAMP,
    description VARCHAR(255),
    isResolved boolean,
    resolution VARCHAR(255),
    PRIMARY KEY(complaintId)
);


create table StreetLight (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    brightnessID INTEGER,
    energyConsumption float(8),
    hasMotionSensor boolean,
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
    zoneId VARCHAR(255),
    schedule VARCHAR(255),
    isDimmed boolean,
    dailyUsage float(8),
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    stallCapacity INTEGER,
    openTime TIMESTAMP,
    closeTime TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column Market.assetId is 'Die universelle Id des Assets';
comment on column Market.priorityID is 'the priority of the asset
the priority of the asset';

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
    categoryID INTEGER,
    marketassetId VARCHAR(255),
    products VARCHAR(255),
    isRegistered boolean,
    licenseExpiry DATE,
    PRIMARY KEY(vendorId)
);


create table Drone (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    flightStatusID INTEGER,
    batteryLevel float(8),
    maxAltitude float(8),
    range float(8),
    PRIMARY KEY(assetId)
);

comment on column Drone.assetId is 'Die universelle Id des Assets';
comment on column Drone.priorityID is 'the priority of the asset
the priority of the asset';

create table FlightMission (
    missionId VARCHAR(255),
    droneassetId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    purpose VARCHAR(255),
    isCompleted boolean,
    PRIMARY KEY(missionId)
);


create table StreetFurniture (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    stateID INTEGER,
    material VARCHAR(255),
    needsRepair boolean,
    PRIMARY KEY(assetId)
);

comment on column StreetFurniture.assetId is 'Die universelle Id des Assets';
comment on column StreetFurniture.priorityID is 'the priority of the asset
the priority of the asset';

create table MaintenanceRecord (
    recordId VARCHAR(255),
    furnitureassetId VARCHAR(255),
    maintenanceDate DATE,
    work VARCHAR(255),
    cost float(8),
    contractor VARCHAR(255),
    PRIMARY KEY(recordId)
);


create table Restaurant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    ratingID INTEGER,
    seatingCapacity INTEGER,
    hasDelivery boolean,
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
    inspectionId VARCHAR(255),
    restaurantassetId VARCHAR(255),
    inspectionDate DATE,
    passed boolean,
    followupDate DATE,
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    segmentID INTEGER,
    floorArea float(8),
    employeeCount INTEGER,
    isChainStore boolean,
    PRIMARY KEY(assetId)
);

comment on column RetailStore.assetId is 'Die universelle Id des Assets';
comment on column RetailStore.priorityID is 'the priority of the asset
the priority of the asset';

create table InventoryItem (
    itemId VARCHAR(255),
    storeassetId VARCHAR(255),
    name VARCHAR(255),
    stockLevel INTEGER,
    price float(8),
    isDiscounted boolean,
    PRIMARY KEY(itemId)
);


create table Cemetery (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    totalArea float(8),
    totalPlots INTEGER,
    availablePlots INTEGER,
    hasChapel boolean,
    PRIMARY KEY(assetId)
);

comment on column Cemetery.assetId is 'Die universelle Id des Assets';
comment on column Cemetery.priorityID is 'the priority of the asset
the priority of the asset';

create table Cemetery_availableTypes (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Cemetery_availableTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Cemetery_availableTypes.ValueID is 'Teil der Werte des Sets';

create table Plot (
    plotId VARCHAR(255),
    typeID INTEGER,
    scheduleID INTEGER,
    lastMaintenance DATE,
    isOccupied boolean,
    owner VARCHAR(255),
    PRIMARY KEY(plotId)
);


create table PostOffice (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    counterCount INTEGER,
    staffCount INTEGER,
    hasAutomation boolean,
    storageCapacity float(8),
    PRIMARY KEY(assetId)
);

comment on column PostOffice.assetId is 'Die universelle Id des Assets';
comment on column PostOffice.priorityID is 'the priority of the asset
the priority of the asset';

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
    typeID INTEGER,
    statusID INTEGER,
    receivedTime TIMESTAMP,
    estimatedDelivery TIMESTAMP,
    isInsured boolean,
    PRIMARY KEY(trackingId)
);


create table Artwork (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    artistTypeID INTEGER,
    requiresRestoration boolean,
    materials VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Artwork.assetId is 'Die universelle Id des Assets';
comment on column Artwork.priorityID is 'the priority of the asset
the priority of the asset';

create table ArtEvent (
    eventId VARCHAR(255),
    artworkassetId VARCHAR(255),
    eventType VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    attendees INTEGER,
    PRIMARY KEY(eventId)
);


create table Elevator (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    operationalStatusID INTEGER,
    capacity INTEGER,
    currentFloor INTEGER,
    totalFloors INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Elevator.assetId is 'Die universelle Id des Assets';
comment on column Elevator.priorityID is 'the priority of the asset
the priority of the asset';

create table ElevatorsMaintenanceLog (
    logId VARCHAR(255),
    elevatorassetId VARCHAR(255),
    serviceTime TIMESTAMP,
    technician VARCHAR(255),
    work VARCHAR(255),
    resolved boolean,
    PRIMARY KEY(logId)
);


create table EmissionReport (
    reportId VARCHAR(255),
    sourceID INTEGER,
    amount float(8),
    unit VARCHAR(255),
    measurementDate DATE,
    verified boolean,
    PRIMARY KEY(reportId)
);


create table ClimateProject (
    projectId VARCHAR(255),
    strategyID INTEGER,
    description VARCHAR(255),
    startDate DATE,
    budget float(8),
    isActive boolean,
    PRIMARY KEY(projectId)
);


create table SnowRoute (
    routeId VARCHAR(255),
    priorityID INTEGER,
    length float(8),
    estimatedTime INTEGER,
    isCleared boolean,
    lastCleared TIMESTAMP,
    PRIMARY KEY(routeId)
);


create table TreatmentOperation (
    operationId VARCHAR(255),
    typeID INTEGER,
    routerouteId VARCHAR(255),
    startTime TIMESTAMP,
    completionTime TIMESTAMP,
    materialUsed float(8),
    PRIMARY KEY(operationId)
);


create table WildlifeZone (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    area float(8),
    isProtected boolean,
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
    incidentId VARCHAR(255),
    speciesID INTEGER,
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresAction boolean,
    resolution VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table PublicBathroom (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    cleaningStatusID INTEGER,
    isOccupied boolean,
    lastCleaning TIMESTAMP,
    hasChangingTable boolean,
    PRIMARY KEY(assetId)
);

comment on column PublicBathroom.assetId is 'Die universelle Id des Assets';
comment on column PublicBathroom.priorityID is 'the priority of the asset
the priority of the asset';

create table MaintenanceTicket (
    ticketId VARCHAR(255),
    bathroomassetId VARCHAR(255),
    issue VARCHAR(255),
    reportTime TIMESTAMP,
    isUrgent boolean,
    resolved boolean,
    PRIMARY KEY(ticketId)
);


create table ManufacturingPlant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    employeeCount INTEGER,
    productionCapacity float(8),
    isTwentyFourSeven boolean,
    totalArea float(8),
    shiftCount INTEGER,
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant.assetId is 'Die universelle Id des Assets';
comment on column ManufacturingPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table ManufacturingPlant_productionTypes (
    RefassetId VARCHAR(255),
    Index INTEGER,
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, Index)
);

comment on column ManufacturingPlant_productionTypes.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column ManufacturingPlant_productionTypes.Index is 'Die Index des Listeneintrags';
comment on column ManufacturingPlant_productionTypes.ValueID is 'Teil der Werte der Liste';

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

create table ProductionLine (
    lineId VARCHAR(255),
    typeID INTEGER,
    statusID INTEGER,
    metricstargetOutput INTEGER,
    metricsactualOutput INTEGER,
    metricsefficiency float(8),
    metricsdefectRate INTEGER,
    metricsenergyConsumption float(8),
    metricsmaterialWaste float(8),
    workerCount INTEGER,
    outputRate float(8),
    currentProduct VARCHAR(255),
    lastStartup TIMESTAMP,
    PRIMARY KEY(lineId)
);


create table Machine (
    machineId VARCHAR(255),
    statusID INTEGER,
    maintenancelastMaintenance DATE,
    maintenancenextMaintenance DATE,
    maintenancefrequency INTEGER,
    maintenancetasks VARCHAR(255),
    maintenanceresponsible VARCHAR(255),
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    installationDate DATE,
    powerConsumption float(8),
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
    checkId VARCHAR(255),
    linelineId VARCHAR(255),
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
    inventoryId VARCHAR(255),
    materialType VARCHAR(255),
    quantity float(8),
    unit VARCHAR(255),
    expiryDate DATE,
    supplier VARCHAR(255),
    storageLocation VARCHAR(255),
    hazardous boolean,
    PRIMARY KEY(inventoryId)
);


create table Patient (
    patientId VARCHAR(255),
    statusID INTEGER,
    departmentID INTEGER,
    vitalstemperature float(8),
    vitalsheartRate INTEGER,
    vitalsbloodPressureSystolic INTEGER,
    vitalsbloodPressureDiastolic INTEGER,
    vitalsrespiratoryRate INTEGER,
    vitalsoxygenSaturation float(8),
    bloodType VARCHAR(255),
    admissionDate DATE,
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
    treatmentId VARCHAR(255),
    typeID INTEGER,
    patientpatientId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    provider VARCHAR(255),
    notes VARCHAR(255),
    completed boolean,
    PRIMARY KEY(treatmentId)
);


create table LibraryBranch (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    branchName VARCHAR(255),
    capacity INTEGER,
    computerStations INTEGER,
    hasStudyRooms boolean,
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch.assetId is 'Die universelle Id des Assets';
comment on column LibraryBranch.priorityID is 'the priority of the asset
the priority of the asset';

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
    resourceId VARCHAR(255),
    typeID INTEGER,
    title VARCHAR(255),
    publicationDate DATE,
    publisher VARCHAR(255),
    location VARCHAR(255),
    isAvailable boolean,
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
    memberId VARCHAR(255),
    levelID INTEGER,
    name VARCHAR(255),
    email VARCHAR(255),
    joinDate DATE,
    membershipExpiry DATE,
    isActive boolean,
    currentBorrows INTEGER,
    PRIMARY KEY(memberId)
);


create table LoanTransaction (
    loanId VARCHAR(255),
    membermemberId VARCHAR(255),
    resourceresourceId VARCHAR(255),
    borrowDate TIMESTAMP,
    dueDate TIMESTAMP,
    returnDate TIMESTAMP,
    isOverdue boolean,
    fineAmount float(8),
    PRIMARY KEY(loanId)
);


create table StudyRoom (
    roomId VARCHAR(255),
    branchassetId VARCHAR(255),
    capacity INTEGER,
    hasProjector boolean,
    hasWhiteboard boolean,
    isOccupied boolean,
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
    petId VARCHAR(255),
    typeID INTEGER,
    name VARCHAR(255),
    breed VARCHAR(255),
    birthDate DATE,
    licenseStatusID INTEGER,
    ownerName VARCHAR(255),
    microchipId VARCHAR(255),
    PRIMARY KEY(petId)
);


create table VeterinaryClinic (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    clinicName VARCHAR(255),
    emergencyTwentyFourHour boolean,
    capacity INTEGER,
    hasLaboratory boolean,
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic.assetId is 'Die universelle Id des Assets';
comment on column VeterinaryClinic.priorityID is 'the priority of the asset
the priority of the asset';

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
    caseId VARCHAR(255),
    animalTypeID INTEGER,
    reportTime TIMESTAMP,
    incidentType VARCHAR(255),
    location VARCHAR(255),
    resolved boolean,
    resolution VARCHAR(255),
    PRIMARY KEY(caseId)
);


create table PetLicense (
    licenseId VARCHAR(255),
    petpetId VARCHAR(255),
    statusID INTEGER,
    issueDate DATE,
    expiryDate DATE,
    fee float(8),
    rabiesVaccinated boolean,
    PRIMARY KEY(licenseId)
);


create table AnimalShelter (
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    shelterName VARCHAR(255),
    capacity INTEGER,
    currentOccupancy INTEGER,
    acceptsStrays boolean,
    providesVetCare boolean,
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter.assetId is 'Die universelle Id des Assets';
comment on column AnimalShelter.priorityID is 'the priority of the asset
the priority of the asset';

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
    permitId VARCHAR(255),
    typeID INTEGER,
    statusID INTEGER,
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    location VARCHAR(255),
    crewSize INTEGER,
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    locationName VARCHAR(255),
    isIndoor boolean,
    dailyRate float(8),
    maxOccupancy INTEGER,
    hasParking boolean,
    PRIMARY KEY(assetId)
);

comment on column FilmLocation.assetId is 'Die universelle Id des Assets';
comment on column FilmLocation.priorityID is 'the priority of the asset
the priority of the asset';

create table FilmLocation_features (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column FilmLocation_features.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column FilmLocation_features.Value is 'Werte des Sets';

create table ProductionCrew (
    crewId VARCHAR(255),
    permitpermitId VARCHAR(255),
    productionCompany VARCHAR(255),
    contactPerson VARCHAR(255),
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
    permitpermitId VARCHAR(255),
    noticeTime TIMESTAMP,
    requiresEvacuation boolean,
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    securityLevelID INTEGER,
    totalArea float(8),
    workstationCount INTEGER,
    hasCleanRoom boolean,
    PRIMARY KEY(assetId)
);

comment on column Laboratory.assetId is 'Die universelle Id des Assets';
comment on column Laboratory.priorityID is 'the priority of the asset
the priority of the asset';

create table Laboratory_domains (
    RefassetId VARCHAR(255),
    ValueID INTEGER,
    PRIMARY KEY(RefassetId, ValueID)
);

comment on column Laboratory_domains.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_domains.ValueID is 'Teil der Werte des Sets';

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

create table Laboratory_certifications (
    RefassetId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefassetId, Value)
);

comment on column Laboratory_certifications.RefassetId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column Laboratory_certifications.Value is 'Werte des Sets';

create table Experiment (
    experimentId VARCHAR(255),
    phaseID INTEGER,
    metadatamethodology VARCHAR(255),
    metadatastartDate DATE,
    metadataendDate DATE,
    locationassetId VARCHAR(255),
    scheduledStart TIMESTAMP,
    scheduledEnd TIMESTAMP,
    dependencies VARCHAR(255),
    hasEthicalApproval boolean,
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
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    specsprecision float(8),
    specsaccuracy float(8),
    specslastVerification TIMESTAMP,
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    serialNumber VARCHAR(255),
    purchaseDate DATE,
    warrantyExpiry DATE,
    lastCalibration TIMESTAMP,
    requiresSpecialTraining boolean,
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
    controlId VARCHAR(255),
    labassetId VARCHAR(255),
    temperature float(8),
    humidity float(8),
    pressure float(8),
    particleCount float(8),
    withinSpecs boolean,
    PRIMARY KEY(controlId)
);


create table EnvironmentalControl_gasLevels (
    RefcontrolId VARCHAR(255),
    Index INTEGER,
    Value float(8),
    PRIMARY KEY(RefcontrolId, Index)
);

comment on column EnvironmentalControl_gasLevels.RefcontrolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column EnvironmentalControl_gasLevels.Index is 'Die Index des Listeneintrags';
comment on column EnvironmentalControl_gasLevels.Value is 'Werte der Liste';

create table EnvironmentalControl_alerts (
    RefcontrolId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefcontrolId, Index)
);

comment on column EnvironmentalControl_alerts.RefcontrolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column EnvironmentalControl_alerts.Index is 'Die Index des Listeneintrags';
comment on column EnvironmentalControl_alerts.Value is 'Werte der Liste';

create table DataCollection (
    datasetId VARCHAR(255),
    experimentexperimentId VARCHAR(255),
    classificationID INTEGER,
    collectionStart TIMESTAMP,
    collectionEnd TIMESTAMP,
    sampleSize float(8),
    format VARCHAR(255),
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
    labassetId VARCHAR(255),
    hazardType VARCHAR(255),
    lastReview DATE,
    requiresTraining boolean,
    PRIMARY KEY(protocolId)
);


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

create table SafetyProtocol_authorizedPersonnel (
    RefprotocolId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefprotocolId, Value)
);

comment on column SafetyProtocol_authorizedPersonnel.RefprotocolId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column SafetyProtocol_authorizedPersonnel.Value is 'Werte des Sets';

create table ComplianceAudit (
    auditId VARCHAR(255),
    labassetId VARCHAR(255),
    auditDate DATE,
    auditor VARCHAR(255),
    passed boolean,
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
    equipmentassetId VARCHAR(255),
    hasConflicts boolean,
    isOptimized boolean,
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
    logId VARCHAR(255),
    equipmentassetId VARCHAR(255),
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
    labassetId VARCHAR(255),
    clearanceLevelID INTEGER,
    holderName VARCHAR(255),
    validFrom TIMESTAMP,
    validUntil TIMESTAMP,
    isActive boolean,
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
    assetId VARCHAR(255),
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    priorityID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    institutionId VARCHAR(255),
    securityLevelID INTEGER,
    isActive boolean,
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution.assetId is 'Die universelle Id des Assets';
comment on column FinancialInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FinancialInstitution.institutionId is 'Id of the Institution';

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
    transactionId VARCHAR(255),
    typeID INTEGER,
    metadatatimestamp TIMESTAMP,
    metadataoriginatorId VARCHAR(255),
    metadatabeneficiaryId VARCHAR(255),
    metadataamount float(8),
    metadatacurrency VARCHAR(255),
    metadatapurpose VARCHAR(255),
    sourceaccountId VARCHAR(255),
    destinationaccountId VARCHAR(255),
    isProcessed boolean,
    status VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table FraudDetection (
    detectionId VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    riskcreditScore INTEGER,
    riskdefaultProbability float(8),
    risklastAssessment DATE,
    requiresReview boolean,
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
    checkId VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    passedKYC boolean,
    passedAML boolean,
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
    reportId VARCHAR(255),
    institutioninstitutionId VARCHAR(255),
    reportType VARCHAR(255),
    reportingPeriod DATE,
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
    incidentId VARCHAR(255),
    impactLevelID INTEGER,
    detectionTime TIMESTAMP,
    description VARCHAR(255),
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
    logId VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    timestamp TIMESTAMP,
    action VARCHAR(255),
    performedBy VARCHAR(255),
    details VARCHAR(255),
    PRIMARY KEY(logId)
);


create table RiskAssessment (
    assessmentId VARCHAR(255),
    institutioninstitutionId VARCHAR(255),
    profilecreditScore INTEGER,
    profiledefaultProbability float(8),
    profilelastAssessment DATE,
    assessmentDate DATE,
    PRIMARY KEY(assessmentId)
);


create table RiskAssessment_findings (
    RefassessmentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassessmentId, Index)
);

comment on column RiskAssessment_findings.RefassessmentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RiskAssessment_findings.Index is 'Die Index des Listeneintrags';
comment on column RiskAssessment_findings.Value is 'Werte der Liste';

create table RiskAssessment_recommendations (
    RefassessmentId VARCHAR(255),
    Index INTEGER,
    Value VARCHAR(255),
    PRIMARY KEY(RefassessmentId, Index)
);

comment on column RiskAssessment_recommendations.RefassessmentId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column RiskAssessment_recommendations.Index is 'Die Index des Listeneintrags';
comment on column RiskAssessment_recommendations.Value is 'Werte der Liste';

create table AuthenticationSystem (
    systemId VARCHAR(255),
    levelID INTEGER,
    multiFactorEnabled boolean,
    PRIMARY KEY(systemId)
);


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

create table AuthenticationSystem_blockedIPs (
    RefsystemId VARCHAR(255),
    Value VARCHAR(255),
    PRIMARY KEY(RefsystemId, Value)
);

comment on column AuthenticationSystem_blockedIPs.RefsystemId is 'Referenz zur Tabelle deren Referenz mit dieser Tabelle dargestellt wird.';
comment on column AuthenticationSystem_blockedIPs.Value is 'Werte des Sets';

