create table Asset (
    acquisitionCost float(8),
    priorityID INTEGER,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Asset.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Asset.assetId is 'Die universelle Id des Assets';

create table NetworkNode (
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    isRedundant boolean,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acquisitionCost float(8),
    connectedDevices INTEGER,
    typeID INTEGER,
    statusID INTEGER,
    uptime float(8),
    name VARCHAR(255),
    bandwidthID INTEGER,
    installationDate DATE,
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column NetworkNode.priorityID is 'the priority of the asset
the priority of the asset';
comment on column NetworkNode.assetId is 'Die universelle Id des Assets';

create table EmergencyIncident (
    responseTime TIMESTAMP,
    isActive boolean,
    typeID INTEGER,
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    incidentId VARCHAR(255),
    reportedTime TIMESTAMP,
    PRIMARY KEY(incidentId)
);


create table TransportRoute (
    lastDepartureTime TIMESTAMP,
    frequencyMinutes INTEGER,
    statusID INTEGER,
    routeId VARCHAR(255),
    routeName VARCHAR(255),
    firstDepartureTime TIMESTAMP,
    PRIMARY KEY(routeId)
);


create table GridNode (
    acquisitionCost float(8),
    typeID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    profileID INTEGER,
    current float(8),
    assetId VARCHAR(255),
    priorityID INTEGER,
    voltage float(8),
    installationDate DATE,
    name VARCHAR(255),
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    isRedundant boolean,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column GridNode.assetId is 'Die universelle Id des Assets';
comment on column GridNode.priorityID is 'the priority of the asset
the priority of the asset';

create table MaintenanceTicket (
    ticketId VARCHAR(255),
    issue VARCHAR(255),
    reportTime TIMESTAMP,
    isUrgent boolean,
    resolved boolean,
    bathroomassetId VARCHAR(255),
    PRIMARY KEY(ticketId)
);


create table Elevator (
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    operationalStatusID INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    totalFloors INTEGER,
    currentFloor INTEGER,
    typeID INTEGER,
    installationDate DATE,
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    capacity INTEGER,
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Elevator.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Elevator.assetId is 'Die universelle Id des Assets';

create table QualityCheck (
    passed boolean,
    action VARCHAR(255),
    linelineId VARCHAR(255),
    checkId VARCHAR(255),
    timestamp TIMESTAMP,
    inspector VARCHAR(255),
    PRIMARY KEY(checkId)
);


create table ManufacturingPlant (
    isTwentyFourSeven boolean,
    expectedLifespanYears INTEGER,
    lastMaintenanceDate DATE,
    shiftCount INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    assetId VARCHAR(255),
    priorityID INTEGER,
    productionCapacity float(8),
    totalArea float(8),
    statusID INTEGER,
    employeeCount INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant.assetId is 'Die universelle Id des Assets';
comment on column ManufacturingPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table Artwork (
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    installationDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    materials VARCHAR(255),
    artistTypeID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    typeID INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    requiresRestoration boolean,
    PRIMARY KEY(assetId)
);

comment on column Artwork.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Artwork.assetId is 'Die universelle Id des Assets';

create table WaterSource (
    qualityID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    capacity float(8),
    isActive boolean,
    lastMaintenanceDate DATE,
    currentLevel float(8),
    flowRate float(8),
    statusID INTEGER,
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WaterSource.assetId is 'Die universelle Id des Assets';
comment on column WaterSource.priorityID is 'the priority of the asset
the priority of the asset';

create table TransitCard (
    methodID INTEGER,
    fareTypeID INTEGER,
    cardId VARCHAR(255),
    balance float(8),
    expiryDate DATE,
    isActive boolean,
    PRIMARY KEY(cardId)
);


create table PowerPlant (
    installationDate DATE,
    expectedLifespanYears INTEGER,
    sourceID INTEGER,
    priorityID INTEGER,
    name VARCHAR(255),
    capacity float(8),
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    isBackupSource boolean,
    efficiency float(8),
    statusID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    currentOutput float(8),
    PRIMARY KEY(assetId)
);

comment on column PowerPlant.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PowerPlant.assetId is 'Die universelle Id des Assets';

create table WildlifeIncident (
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresAction boolean,
    resolution VARCHAR(255),
    speciesID INTEGER,
    incidentId VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table VeterinaryClinic (
    priorityID INTEGER,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    capacity INTEGER,
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acquisitionCost float(8),
    installationDate DATE,
    clinicName VARCHAR(255),
    hasLaboratory boolean,
    emergencyTwentyFourHour boolean,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic.priorityID is 'the priority of the asset
the priority of the asset';
comment on column VeterinaryClinic.assetId is 'Die universelle Id des Assets';

create table WeatherStation (
    installationDate DATE,
    precipitation float(8),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    humidity float(8),
    conditionID INTEGER,
    windSpeed float(8),
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    temperature float(8),
    acquisitionCost float(8),
    priorityID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column WeatherStation.assetId is 'Die universelle Id des Assets';
comment on column WeatherStation.priorityID is 'the priority of the asset
the priority of the asset';

create table PostOffice (
    staffCount INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    counterCount INTEGER,
    installationDate DATE,
    statusID INTEGER,
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    hasAutomation boolean,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    storageCapacity float(8),
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column PostOffice.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PostOffice.assetId is 'Die universelle Id des Assets';

create table ProductionCrew (
    productionCompany VARCHAR(255),
    contactPerson VARCHAR(255),
    permitpermitId VARCHAR(255),
    crewId VARCHAR(255),
    PRIMARY KEY(crewId)
);


create table SmartDevice (
    buildingassetId VARCHAR(255),
    deviceId VARCHAR(255),
    deviceType VARCHAR(255),
    isOnline boolean,
    lastPing TIMESTAMP,
    firmwareVersion VARCHAR(255),
    PRIMARY KEY(deviceId)
);


create table Zone (
    area float(8),
    maxDensity float(8),
    installationDate DATE,
    acquisitionCost float(8),
    isHistorical boolean,
    typeID INTEGER,
    heightLimit INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    priorityID INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Zone.assetId is 'Die universelle Id des Assets';
comment on column Zone.priorityID is 'the priority of the asset
the priority of the asset';

create table SignContent (
    startDisplay TIMESTAMP,
    endDisplay TIMESTAMP,
    priority INTEGER,
    signassetId VARCHAR(255),
    contentId VARCHAR(255),
    content VARCHAR(255),
    PRIMARY KEY(contentId)
);


create table WasteCollection (
    estimatedVolume float(8),
    isCompleted boolean,
    typeID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    collectionId VARCHAR(255),
    scheduledTime TIMESTAMP,
    PRIMARY KEY(collectionId)
);


create table HealthcareFacility (
    hasEmergencyUnit boolean,
    currentOccupancy INTEGER,
    lastMaintenanceDate DATE,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    bedCapacity INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    typeID INTEGER,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column HealthcareFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column HealthcareFacility.assetId is 'Die universelle Id des Assets';

create table Plot (
    plotId VARCHAR(255),
    lastMaintenance DATE,
    isOccupied boolean,
    owner VARCHAR(255),
    typeID INTEGER,
    scheduleID INTEGER,
    PRIMARY KEY(plotId)
);


create table EducationalInstitution (
    acquisitionCost float(8),
    staffCount INTEGER,
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    isPublic boolean,
    accreditationStatus VARCHAR(255),
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    studentCapacity INTEGER,
    statusID INTEGER,
    name VARCHAR(255),
    typeID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column EducationalInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column EducationalInstitution.assetId is 'Die universelle Id des Assets';

create table FareTransaction (
    transactionId VARCHAR(255),
    timestamp TIMESTAMP,
    amount float(8),
    route VARCHAR(255),
    isRefunded boolean,
    cardcardId VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table Machine (
    machineId VARCHAR(255),
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    installationDate DATE,
    powerConsumption float(8),
    statusID INTEGER,
    maintenancetasks VARCHAR(255),
    maintenanceresponsible VARCHAR(255),
    maintenancelastMaintenance DATE,
    maintenancenextMaintenance DATE,
    maintenancefrequency INTEGER,
    PRIMARY KEY(machineId)
);


create table Building (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    installationDate DATE,
    totalArea float(8),
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    typeID INTEGER,
    securityLevelID INTEGER,
    name VARCHAR(255),
    occupancy INTEGER,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    floors INTEGER,
    isSmartEnabled boolean,
    PRIMARY KEY(assetId)
);

comment on column Building.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Building.assetId is 'Die universelle Id des Assets';

create table ClimateProject (
    strategyID INTEGER,
    projectId VARCHAR(255),
    description VARCHAR(255),
    startDate DATE,
    budget float(8),
    isActive boolean,
    PRIMARY KEY(projectId)
);


create table EnvironmentalControl (
    pressure float(8),
    particleCount float(8),
    labassetId VARCHAR(255),
    controlId VARCHAR(255),
    humidity float(8),
    withinSpecs boolean,
    temperature float(8),
    PRIMARY KEY(controlId)
);


create table Experiment (
    hasEthicalApproval boolean,
    experimentId VARCHAR(255),
    scheduledStart TIMESTAMP,
    scheduledEnd TIMESTAMP,
    locationassetId VARCHAR(255),
    metadatamethodology VARCHAR(255),
    metadatastartDate DATE,
    metadataendDate DATE,
    dependencies VARCHAR(255),
    phaseID INTEGER,
    PRIMARY KEY(experimentId)
);


create table LibraryMember (
    currentBorrows INTEGER,
    levelID INTEGER,
    memberId VARCHAR(255),
    name VARCHAR(255),
    email VARCHAR(255),
    joinDate DATE,
    membershipExpiry DATE,
    isActive boolean,
    PRIMARY KEY(memberId)
);


create table AnimalShelter (
    acceptsStrays boolean,
    providesVetCare boolean,
    currentOccupancy INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    shelterName VARCHAR(255),
    capacity INTEGER,
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter.assetId is 'Die universelle Id des Assets';
comment on column AnimalShelter.priorityID is 'the priority of the asset
the priority of the asset';

create table Pet (
    breed VARCHAR(255),
    birthDate DATE,
    ownerName VARCHAR(255),
    microchipId VARCHAR(255),
    typeID INTEGER,
    licenseStatusID INTEGER,
    petId VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(petId)
);


create table SportsFacility (
    name VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    isIndoor boolean,
    hasFloodlights boolean,
    spectatorCapacity INTEGER,
    acquisitionCost float(8),
    assetId VARCHAR(255),
    priorityID INTEGER,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column SportsFacility.assetId is 'Die universelle Id des Assets';
comment on column SportsFacility.priorityID is 'the priority of the asset
the priority of the asset';

create table MonitoringStation (
    expectedLifespanYears INTEGER,
    isCalibrated boolean,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    priorityID INTEGER,
    stationId VARCHAR(255),
    lastCalibrationDate DATE,
    name VARCHAR(255),
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation.priorityID is 'the priority of the asset
the priority of the asset';
comment on column MonitoringStation.assetId is 'Die universelle Id des Assets';

create table MaintenanceRecord (
    recordId VARCHAR(255),
    maintenanceDate DATE,
    work VARCHAR(255),
    cost float(8),
    contractor VARCHAR(255),
    furnitureassetId VARCHAR(255),
    PRIMARY KEY(recordId)
);


create table Treatment (
    typeID INTEGER,
    patientpatientId VARCHAR(255),
    treatmentId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    provider VARCHAR(255),
    notes VARCHAR(255),
    completed boolean,
    PRIMARY KEY(treatmentId)
);


create table AuditLog (
    action VARCHAR(255),
    details VARCHAR(255),
    transactiontransactionId VARCHAR(255),
    logId VARCHAR(255),
    timestamp TIMESTAMP,
    performedBy VARCHAR(255),
    PRIMARY KEY(logId)
);


create table LibraryBranch (
    expectedLifespanYears INTEGER,
    branchName VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    computerStations INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    statusID INTEGER,
    capacity INTEGER,
    hasStudyRooms boolean,
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch.priorityID is 'the priority of the asset
the priority of the asset';
comment on column LibraryBranch.assetId is 'Die universelle Id des Assets';

create table ParkingFacility (
    name VARCHAR(255),
    typeID INTEGER,
    availableSpaces INTEGER,
    expectedLifespanYears INTEGER,
    hourlyRate float(8),
    acquisitionCost float(8),
    priorityID INTEGER,
    hasChargingStations boolean,
    totalSpaces INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column ParkingFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column ParkingFacility.assetId is 'Die universelle Id des Assets';

create table Sensor (
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastReading TIMESTAMP,
    sensorType VARCHAR(255),
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    statusID INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    needsCalibration boolean,
    assetId VARCHAR(255),
    priorityID INTEGER,
    unit VARCHAR(255),
    readingValue float(8),
    PRIMARY KEY(assetId)
);

comment on column Sensor.assetId is 'Die universelle Id des Assets';
comment on column Sensor.priorityID is 'the priority of the asset
the priority of the asset';

create table RecyclingFacility (
    statusID INTEGER,
    isAcceptingWaste boolean,
    installationDate DATE,
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    currentStorage float(8),
    name VARCHAR(255),
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    processingCapacity float(8),
    PRIMARY KEY(assetId)
);

comment on column RecyclingFacility.priorityID is 'the priority of the asset
the priority of the asset';
comment on column RecyclingFacility.assetId is 'Die universelle Id des Assets';

create table FinancialAccount (
    institutioninstitutionId VARCHAR(255),
    accountId VARCHAR(255),
    balance float(8),
    currency VARCHAR(255),
    isFrozen boolean,
    accountType VARCHAR(255),
    openedDate DATE,
    PRIMARY KEY(accountId)
);


create table RiskAssessment (
    assessmentDate DATE,
    institutioninstitutionId VARCHAR(255),
    profilecreditScore INTEGER,
    profiledefaultProbability float(8),
    profilelastAssessment DATE,
    assessmentId VARCHAR(255),
    PRIMARY KEY(assessmentId)
);


create table RegulatoryReport (
    institutioninstitutionId VARCHAR(255),
    reportId VARCHAR(255),
    reportType VARCHAR(255),
    reportingPeriod DATE,
    submitted boolean,
    PRIMARY KEY(reportId)
);


create table FinancialInstitution (
    statusID INTEGER,
    isActive boolean,
    lastMaintenanceDate DATE,
    securityLevelID INTEGER,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    acquisitionCost float(8),
    priorityID INTEGER,
    assetId VARCHAR(255),
    institutionId VARCHAR(255),
    installationDate DATE,
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FinancialInstitution.assetId is 'Die universelle Id des Assets';
comment on column FinancialInstitution.institutionId is 'Id of the Institution';

create table Shipment (
    typeID INTEGER,
    statusID INTEGER,
    trackingId VARCHAR(255),
    receivedTime TIMESTAMP,
    estimatedDelivery TIMESTAMP,
    isInsured boolean,
    PRIMARY KEY(trackingId)
);


create table ResourceSchedule (
    scheduleId VARCHAR(255),
    hasConflicts boolean,
    isOptimized boolean,
    equipmentassetId VARCHAR(255),
    PRIMARY KEY(scheduleId)
);


create table CulturalEvent (
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    curator VARCHAR(255),
    categoryID INTEGER,
    ticketingbasePrice float(8),
    ticketingdiscount float(8),
    ticketingavailableSeats INTEGER,
    ticketingisRefundable boolean,
    eventId VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table AuthenticationSystem (
    systemId VARCHAR(255),
    multiFactorEnabled boolean,
    levelID INTEGER,
    PRIMARY KEY(systemId)
);


create table EmissionReport (
    measurementDate DATE,
    verified boolean,
    sourceID INTEGER,
    reportId VARCHAR(255),
    amount float(8),
    unit VARCHAR(255),
    PRIMARY KEY(reportId)
);


create table DataTransfer (
    amount float(8),
    timestamp TIMESTAMP,
    isEncrypted boolean,
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    transferId VARCHAR(255),
    PRIMARY KEY(transferId)
);


create table InventoryItem (
    isDiscounted boolean,
    storeassetId VARCHAR(255),
    itemId VARCHAR(255),
    name VARCHAR(255),
    stockLevel INTEGER,
    price float(8),
    PRIMARY KEY(itemId)
);


create table LoanTransaction (
    borrowDate TIMESTAMP,
    dueDate TIMESTAMP,
    returnDate TIMESTAMP,
    isOverdue boolean,
    fineAmount float(8),
    membermemberId VARCHAR(255),
    resourceresourceId VARCHAR(255),
    loanId VARCHAR(255),
    PRIMARY KEY(loanId)
);


create table DevelopmentProject (
    statusID INTEGER,
    projectId VARCHAR(255),
    description VARCHAR(255),
    startDate DATE,
    completionDate DATE,
    budget float(8),
    PRIMARY KEY(projectId)
);


create table AnimalControl (
    caseId VARCHAR(255),
    reportTime TIMESTAMP,
    incidentType VARCHAR(255),
    location VARCHAR(255),
    resolved boolean,
    resolution VARCHAR(255),
    animalTypeID INTEGER,
    PRIMARY KEY(caseId)
);


create table TouristAttraction (
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    entryFee float(8),
    priorityID INTEGER,
    dailyVisitorCapacity INTEGER,
    typeID INTEGER,
    installationDate DATE,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    isAccessible boolean,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction.priorityID is 'the priority of the asset
the priority of the asset';
comment on column TouristAttraction.assetId is 'Die universelle Id des Assets';

create table DigitalSign (
    priorityID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    typeID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    assetId VARCHAR(255),
    statusID INTEGER,
    contentTypeID INTEGER,
    resolution VARCHAR(255),
    isInteractive boolean,
    PRIMARY KEY(assetId)
);

comment on column DigitalSign.priorityID is 'the priority of the asset
the priority of the asset';
comment on column DigitalSign.assetId is 'Die universelle Id des Assets';

create table MedicalEquipment (
    warrantyExpiry DATE,
    name VARCHAR(255),
    equipmentType VARCHAR(255),
    manufacturer VARCHAR(255),
    acquisitionCost float(8),
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    requiresCalibration boolean,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    hoursInUse INTEGER,
    PRIMARY KEY(assetId)
);

comment on column MedicalEquipment.priorityID is 'the priority of the asset
the priority of the asset';
comment on column MedicalEquipment.assetId is 'Die universelle Id des Assets';

create table AccessCredential (
    clearanceLevelID INTEGER,
    credentialId VARCHAR(255),
    holderName VARCHAR(255),
    validFrom TIMESTAMP,
    validUntil TIMESTAMP,
    isActive boolean,
    labassetId VARCHAR(255),
    PRIMARY KEY(credentialId)
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


create table EmergencyTeam (
    specialtyID INTEGER,
    currentLocationlatitude float(8),
    currentLocationlongitude float(8),
    currentLocationaltitude float(8),
    currentLocationaddressString VARCHAR(255),
    teamId VARCHAR(255),
    memberCount INTEGER,
    isAvailable boolean,
    PRIMARY KEY(teamId)
);


create table DataCollection (
    format VARCHAR(255),
    experimentexperimentId VARCHAR(255),
    collectionStart TIMESTAMP,
    collectionEnd TIMESTAMP,
    isBackedUp boolean,
    sampleSize float(8),
    classificationID INTEGER,
    datasetId VARCHAR(255),
    PRIMARY KEY(datasetId)
);


create table RetailStore (
    isChainStore boolean,
    floorArea float(8),
    installationDate DATE,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    employeeCount INTEGER,
    assetId VARCHAR(255),
    statusID INTEGER,
    segmentID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column RetailStore.priorityID is 'the priority of the asset
the priority of the asset';
comment on column RetailStore.assetId is 'Die universelle Id des Assets';

create table PowerFlow (
    flowId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isStable boolean,
    sourceassetId VARCHAR(255),
    destinationassetId VARCHAR(255),
    PRIMARY KEY(flowId)
);


create table Patient (
    patientId VARCHAR(255),
    bloodType VARCHAR(255),
    admissionDate DATE,
    statusID INTEGER,
    departmentID INTEGER,
    vitalsrespiratoryRate INTEGER,
    vitalsoxygenSaturation float(8),
    vitalstemperature float(8),
    vitalsheartRate INTEGER,
    vitalsbloodPressureSystolic INTEGER,
    vitalsbloodPressureDiastolic INTEGER,
    PRIMARY KEY(patientId)
);


create table Farm (
    irrigationTypeID INTEGER,
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    acquisitionCost float(8),
    area float(8),
    statusID INTEGER,
    lastHarvestDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    isOrganic boolean,
    lastMaintenanceDate DATE,
    priorityID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Farm.assetId is 'Die universelle Id des Assets';
comment on column Farm.priorityID is 'the priority of the asset
the priority of the asset';

create table WaterTreatmentPlant (
    statusID INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    currentThroughput float(8),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    processingCapacity float(8),
    treatmentStages INTEGER,
    isOperating boolean,
    PRIMARY KEY(assetId)
);

comment on column WaterTreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column WaterTreatmentPlant.priorityID is 'the priority of the asset
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


create table Citizen (
    email VARCHAR(255),
    phone VARCHAR(255),
    residencelatitude float(8),
    residencelongitude float(8),
    residencealtitude float(8),
    residenceaddressString VARCHAR(255),
    citizenId VARCHAR(255),
    firstName VARCHAR(255),
    lastName VARCHAR(255),
    dateOfBirth DATE,
    PRIMARY KEY(citizenId)
);


create table SafetyProtocol (
    hazardType VARCHAR(255),
    lastReview DATE,
    requiresTraining boolean,
    labassetId VARCHAR(255),
    protocolId VARCHAR(255),
    PRIMARY KEY(protocolId)
);


create table FilmLocation (
    hasParking boolean,
    maxOccupancy INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    priorityID INTEGER,
    lastMaintenanceDate DATE,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    locationName VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    dailyRate float(8),
    isIndoor boolean,
    statusID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column FilmLocation.priorityID is 'the priority of the asset
the priority of the asset';
comment on column FilmLocation.assetId is 'Die universelle Id des Assets';

create table StreetFurniture (
    stateID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    material VARCHAR(255),
    needsRepair boolean,
    installationDate DATE,
    name VARCHAR(255),
    priorityID INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    typeID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column StreetFurniture.assetId is 'Die universelle Id des Assets';
comment on column StreetFurniture.priorityID is 'the priority of the asset
the priority of the asset';

create table TreatmentOperation (
    startTime TIMESTAMP,
    completionTime TIMESTAMP,
    materialUsed float(8),
    typeID INTEGER,
    routerouteId VARCHAR(255),
    operationId VARCHAR(255),
    PRIMARY KEY(operationId)
);


create table Drone (
    batteryLevel float(8),
    flightStatusID INTEGER,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    maxAltitude float(8),
    typeID INTEGER,
    priorityID INTEGER,
    range float(8),
    lastMaintenanceDate DATE,
    installationDate DATE,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column Drone.assetId is 'Die universelle Id des Assets';
comment on column Drone.priorityID is 'the priority of the asset
the priority of the asset';

create table NoiseComplaint (
    isResolved boolean,
    resolution VARCHAR(255),
    sourceID INTEGER,
    complaintId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    PRIMARY KEY(complaintId)
);


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


create table ArtEvent (
    eventId VARCHAR(255),
    eventType VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    attendees INTEGER,
    artworkassetId VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table Course (
    levelID INTEGER,
    courseId VARCHAR(255),
    title VARCHAR(255),
    credits INTEGER,
    maxEnrollment INTEGER,
    isOnline boolean,
    PRIMARY KEY(courseId)
);


create table TreatmentPlant (
    statusID INTEGER,
    lastMaintenanceDate DATE,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    priorityID INTEGER,
    isOperational boolean,
    name VARCHAR(255),
    dailyCapacity float(8),
    lastInspection DATE,
    acquisitionCost float(8),
    currentFlow float(8),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant.assetId is 'Die universelle Id des Assets';
comment on column TreatmentPlant.priorityID is 'the priority of the asset
the priority of the asset';

create table FlightMission (
    isCompleted boolean,
    droneassetId VARCHAR(255),
    missionId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    purpose VARCHAR(255),
    PRIMARY KEY(missionId)
);


create table StreetLight (
    brightnessID INTEGER,
    energyConsumption float(8),
    hasMotionSensor boolean,
    lastMaintenanceDate DATE,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    statusID INTEGER,
    priorityID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column StreetLight.assetId is 'Die universelle Id des Assets';
comment on column StreetLight.priorityID is 'the priority of the asset
the priority of the asset';

create table ImpactNotification (
    noticeTime TIMESTAMP,
    requiresEvacuation boolean,
    permitpermitId VARCHAR(255),
    notificationId VARCHAR(255),
    PRIMARY KEY(notificationId)
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


create table ComplianceAudit (
    passed boolean,
    labassetId VARCHAR(255),
    auditId VARCHAR(255),
    auditDate DATE,
    auditor VARCHAR(255),
    PRIMARY KEY(auditId)
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


create table PublicBathroom (
    isOccupied boolean,
    priorityID INTEGER,
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    typeID INTEGER,
    hasChangingTable boolean,
    cleaningStatusID INTEGER,
    name VARCHAR(255),
    lastCleaning TIMESTAMP,
    lastMaintenanceDate DATE,
    assetId VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column PublicBathroom.priorityID is 'the priority of the asset
the priority of the asset';
comment on column PublicBathroom.assetId is 'Die universelle Id des Assets';

create table Evacuation (
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    affectedPopulation INTEGER,
    isCompleted boolean,
    incidentincidentId VARCHAR(255),
    evacuationId VARCHAR(255),
    PRIMARY KEY(evacuationId)
);


create table Laboratory (
    installationDate DATE,
    acquisitionCost float(8),
    statusID INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    name VARCHAR(255),
    totalArea float(8),
    hasCleanRoom boolean,
    securityLevelID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    workstationCount INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Laboratory.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Laboratory.assetId is 'Die universelle Id des Assets';

create table Cemetery (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    name VARCHAR(255),
    statusID INTEGER,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    totalPlots INTEGER,
    availablePlots INTEGER,
    priorityID INTEGER,
    assetId VARCHAR(255),
    totalArea float(8),
    hasChapel boolean,
    PRIMARY KEY(assetId)
);

comment on column Cemetery.priorityID is 'the priority of the asset
the priority of the asset';
comment on column Cemetery.assetId is 'Die universelle Id des Assets';

create table FraudDetection (
    resolution VARCHAR(255),
    requiresReview boolean,
    riskcreditScore INTEGER,
    riskdefaultProbability float(8),
    risklastAssessment DATE,
    transactiontransactionId VARCHAR(255),
    detectionId VARCHAR(255),
    PRIMARY KEY(detectionId)
);


create table Equipment (
    equipmentId VARCHAR(255),
    type VARCHAR(255),
    specifications VARCHAR(255),
    requiresPermit boolean,
    powerRequirement float(8),
    PRIMARY KEY(equipmentId)
);


create table ComplianceCheck (
    passedAML boolean,
    transactiontransactionId VARCHAR(255),
    checkId VARCHAR(255),
    passedKYC boolean,
    PRIMARY KEY(checkId)
);


create table Tournament (
    endDate DATE,
    participants INTEGER,
    sponsor VARCHAR(255),
    sportID INTEGER,
    tournamentId VARCHAR(255),
    startDate DATE,
    PRIMARY KEY(tournamentId)
);


create table Restaurant (
    typeID INTEGER,
    statusID INTEGER,
    lastMaintenanceDate DATE,
    hasDelivery boolean,
    expectedLifespanYears INTEGER,
    ratingID INTEGER,
    assetId VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    seatingCapacity INTEGER,
    name VARCHAR(255),
    priorityID INTEGER,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column Restaurant.assetId is 'Die universelle Id des Assets';
comment on column Restaurant.priorityID is 'the priority of the asset
the priority of the asset';

create table WeatherAlert (
    expiryTime TIMESTAMP,
    isActive boolean,
    levelID INTEGER,
    alertId VARCHAR(255),
    message VARCHAR(255),
    issueTime TIMESTAMP,
    PRIMARY KEY(alertId)
);


create table LibraryResource (
    typeID INTEGER,
    resourceId VARCHAR(255),
    title VARCHAR(255),
    publicationDate DATE,
    publisher VARCHAR(255),
    location VARCHAR(255),
    isAvailable boolean,
    PRIMARY KEY(resourceId)
);


create table Vehicle (
    currentPassengerCount INTEGER,
    lastMaintenanceDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    currentFuelLevel float(8),
    acquisitionCost float(8),
    typeID INTEGER,
    assetId VARCHAR(255),
    currentRouterouteId VARCHAR(255),
    priorityID INTEGER,
    expectedLifespanYears INTEGER,
    statusID INTEGER,
    capacity INTEGER,
    name VARCHAR(255),
    registrationNumber VARCHAR(255),
    PRIMARY KEY(registrationNumber)
);

comment on column Vehicle.assetId is 'Die universelle Id des Assets';
comment on column Vehicle.priorityID is 'the priority of the asset
the priority of the asset';

create table CulturalVenue (
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    installationDate DATE,
    priorityID INTEGER,
    capacity INTEGER,
    typeID INTEGER,
    expectedLifespanYears INTEGER,
    assetId VARCHAR(255),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    hasAccessibility boolean,
    acquisitionCost float(8),
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue.priorityID is 'the priority of the asset
the priority of the asset';
comment on column CulturalVenue.assetId is 'Die universelle Id des Assets';

create table ProductionLine (
    typeID INTEGER,
    statusID INTEGER,
    metricsdefectRate INTEGER,
    metricsenergyConsumption float(8),
    metricsactualOutput INTEGER,
    metricsmaterialWaste float(8),
    metricstargetOutput INTEGER,
    metricsefficiency float(8),
    lineId VARCHAR(255),
    workerCount INTEGER,
    outputRate float(8),
    currentProduct VARCHAR(255),
    lastStartup TIMESTAMP,
    PRIMARY KEY(lineId)
);


create table ElevatorsMaintenanceLog (
    logId VARCHAR(255),
    serviceTime TIMESTAMP,
    technician VARCHAR(255),
    work VARCHAR(255),
    resolved boolean,
    elevatorassetId VARCHAR(255),
    PRIMARY KEY(logId)
);


create table Vendor (
    isRegistered boolean,
    licenseExpiry DATE,
    categoryID INTEGER,
    marketassetId VARCHAR(255),
    vendorId VARCHAR(255),
    products VARCHAR(255),
    PRIMARY KEY(vendorId)
);


create table LightingZone (
    dailyUsage float(8),
    zoneId VARCHAR(255),
    schedule VARCHAR(255),
    isDimmed boolean,
    PRIMARY KEY(zoneId)
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


create table PetLicense (
    rabiesVaccinated boolean,
    petpetId VARCHAR(255),
    statusID INTEGER,
    licenseId VARCHAR(255),
    issueDate DATE,
    expiryDate DATE,
    fee float(8),
    PRIMARY KEY(licenseId)
);


create table Market (
    statusID INTEGER,
    stallCapacity INTEGER,
    installationDate DATE,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    typeID INTEGER,
    openTime TIMESTAMP,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    name VARCHAR(255),
    closeTime TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column Market.assetId is 'Die universelle Id des Assets';
comment on column Market.priorityID is 'the priority of the asset
the priority of the asset';

create table Research_facilitiesMaintenanceLog (
    logId VARCHAR(255),
    maintenanceTime TIMESTAMP,
    technician VARCHAR(255),
    cost float(8),
    requiresFollowup boolean,
    equipmentassetId VARCHAR(255),
    PRIMARY KEY(logId)
);


create table Event (
    endTime TIMESTAMP,
    expectedAttendance INTEGER,
    seasonID INTEGER,
    eventId VARCHAR(255),
    name VARCHAR(255),
    startTime TIMESTAMP,
    PRIMARY KEY(eventId)
);


create table SmartMeter (
    lastReadingTime TIMESTAMP,
    isOnline boolean,
    patternID INTEGER,
    meterId VARCHAR(255),
    currentReading float(8),
    peakDemand float(8),
    PRIMARY KEY(meterId)
);


create table SecurityIncident (
    detectionTime TIMESTAMP,
    resolved boolean,
    impactLevelID INTEGER,
    incidentId VARCHAR(255),
    description VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table ResearchEquipment (
    installationDate DATE,
    assetId VARCHAR(255),
    serialNumber VARCHAR(255),
    purchaseDate DATE,
    lastCalibration TIMESTAMP,
    specsprecision float(8),
    specsaccuracy float(8),
    specslastVerification TIMESTAMP,
    warrantyExpiry DATE,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    statusID INTEGER,
    lastMaintenanceDate DATE,
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    requiresSpecialTraining boolean,
    PRIMARY KEY(assetId)
);

comment on column ResearchEquipment.assetId is 'Die universelle Id des Assets';
comment on column ResearchEquipment.priorityID is 'the priority of the asset
the priority of the asset';

create table Inspection (
    inspectionId VARCHAR(255),
    inspectionDate DATE,
    passed boolean,
    followupDate DATE,
    restaurantassetId VARCHAR(255),
    PRIMARY KEY(inspectionId)
);


create table Transaction (
    metadataamount float(8),
    metadataoriginatorId VARCHAR(255),
    metadatatimestamp TIMESTAMP,
    metadatabeneficiaryId VARCHAR(255),
    metadatacurrency VARCHAR(255),
    metadatapurpose VARCHAR(255),
    destinationaccountId VARCHAR(255),
    transactionId VARCHAR(255),
    typeID INTEGER,
    sourceaccountId VARCHAR(255),
    isProcessed boolean,
    status VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table QualityTest (
    metricID INTEGER,
    testId VARCHAR(255),
    value float(8),
    timestamp TIMESTAMP,
    meetsStandard boolean,
    analyst VARCHAR(255),
    PRIMARY KEY(testId)
);


create table WildlifeZone (
    lastSurvey DATE,
    typeID INTEGER,
    statusID INTEGER,
    priorityID INTEGER,
    acquisitionCost float(8),
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    area float(8),
    lastMaintenanceDate DATE,
    installationDate DATE,
    isProtected boolean,
    assetId VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column WildlifeZone.priorityID is 'the priority of the asset
the priority of the asset';
comment on column WildlifeZone.assetId is 'Die universelle Id des Assets';

create table FilmPermit (
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    location VARCHAR(255),
    crewSize INTEGER,
    typeID INTEGER,
    statusID INTEGER,
    permitId VARCHAR(255),
    PRIMARY KEY(permitId)
);


create table SafetyIncident (
    description VARCHAR(255),
    requiresEvacuation boolean,
    typeID INTEGER,
    incidentId VARCHAR(255),
    reportTime TIMESTAMP,
    PRIMARY KEY(incidentId)
);


create table NoiseSensor (
    installationDate DATE,
    statusID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    sourcesID INTEGER,
    locationlatitude float(8),
    locationlongitude float(8),
    locationaltitude float(8),
    locationaddressString VARCHAR(255),
    assetId VARCHAR(255),
    currentLevelID INTEGER,
    lastPeak TIMESTAMP,
    name VARCHAR(255),
    priorityID INTEGER,
    averageReading float(8),
    needsCalibration boolean,
    PRIMARY KEY(assetId)
);

comment on column NoiseSensor.assetId is 'Die universelle Id des Assets';
comment on column NoiseSensor.priorityID is 'the priority of the asset
the priority of the asset';

