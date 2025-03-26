create table DevelopmentProject (
    projectId VARCHAR(255),
    description VARCHAR(255),
    startDate DATE,
    completionDate DATE,
    budget float(8),
    status_ID INTEGER,
    PRIMARY KEY(projectId)
);


create table MonitoringStation (
    stationId VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    lastCalibrationDate DATE,
    acquisitionCost float(8),
    priority_ID INTEGER,
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    isCalibrated boolean,
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation.assetId is 'Die universelle Id des Assets';

create table RecyclingFacility (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    processingCapacity float(8),
    currentStorage float(8),
    lastMaintenanceDate DATE,
    priority_ID INTEGER,
    installationDate DATE,
    isAcceptingWaste boolean,
    status_ID INTEGER,
    expectedLifespanYears INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column RecyclingFacility.assetId is 'Die universelle Id des Assets';

create table ArtEvent (
    eventId VARCHAR(255),
    eventType VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    attendees INTEGER,
    artwork_assetId VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table Tournament (
    tournamentId VARCHAR(255),
    startDate DATE,
    endDate DATE,
    participants INTEGER,
    sponsor VARCHAR(255),
    sport_ID INTEGER,
    PRIMARY KEY(tournamentId)
);


create table DigitalSign_activeHours (
    assetId VARCHAR(255),
    activeHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column DigitalSign_activeHours.assetId is 'Referenz zur Ursprungstabelle';

create table WeatherStation (
    assetId VARCHAR(255),
    precipitation float(8),
    condition_ID INTEGER,
    priority_ID INTEGER,
    temperature float(8),
    windSpeed float(8),
    humidity float(8),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    status_ID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column WeatherStation.assetId is 'Die universelle Id des Assets';

create table Zone (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    area float(8),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    heightLimit INTEGER,
    maxDensity float(8),
    type_ID INTEGER,
    installationDate DATE,
    priority_ID INTEGER,
    isHistorical boolean,
    PRIMARY KEY(assetId)
);

comment on column Zone.assetId is 'Die universelle Id des Assets';

create table SafetyProtocol_emergencyProcedures (
    protocolId VARCHAR(255),
    emergencyProcedures VARCHAR(255),
    PRIMARY KEY(protocolId, emergencyProcedures)
);

comment on column SafetyProtocol_emergencyProcedures.protocolId is 'Referenz zur Ursprungstabelle';

create table CulturalVenue (
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    type_ID INTEGER,
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    status_ID INTEGER,
    capacity INTEGER,
    acquisitionCost float(8),
    hasAccessibility boolean,
    name VARCHAR(255),
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue.assetId is 'Die universelle Id des Assets';

create table NetworkNode (
    assetId VARCHAR(255),
    connectedDevices INTEGER,
    uptime float(8),
    isRedundant boolean,
    name VARCHAR(255),
    installationDate DATE,
    priority_ID INTEGER,
    bandwidth_ID INTEGER,
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    type_ID INTEGER,
    lastMaintenanceDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column NetworkNode.assetId is 'Die universelle Id des Assets';

create table Laboratory_certifications (
    assetId VARCHAR(255),
    certifications VARCHAR(255),
    PRIMARY KEY(assetId, certifications)
);

comment on column Laboratory_certifications.assetId is 'Referenz zur Ursprungstabelle';

create table Pet (
    petId VARCHAR(255),
    type_ID INTEGER,
    licenseStatus_ID INTEGER,
    name VARCHAR(255),
    breed VARCHAR(255),
    birthDate DATE,
    ownerName VARCHAR(255),
    microchipId VARCHAR(255),
    PRIMARY KEY(petId)
);


create table FilmLocation_features (
    assetId VARCHAR(255),
    features VARCHAR(255),
    PRIMARY KEY(assetId, features)
);

comment on column FilmLocation_features.assetId is 'Referenz zur Ursprungstabelle';

create table MedicalEquipment (
    assetId VARCHAR(255),
    equipmentType VARCHAR(255),
    acquisitionCost float(8),
    priority_ID INTEGER,
    warrantyExpiry DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    hoursInUse INTEGER,
    requiresCalibration boolean,
    lastMaintenanceDate DATE,
    manufacturer VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column MedicalEquipment.assetId is 'Die universelle Id des Assets';

create table ResourceSchedule_reservedTimes (
    scheduleId VARCHAR(255),
    reservedTimes TIMESTAMP,
    PRIMARY KEY(scheduleId)
);

comment on column ResourceSchedule_reservedTimes.scheduleId is 'Referenz zur Ursprungstabelle';

create table Patient_medications (
    patientId VARCHAR(255),
    medications VARCHAR(255),
    PRIMARY KEY(patientId)
);

comment on column Patient_medications.patientId is 'Referenz zur Ursprungstabelle';

create table AnimalShelter (
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    shelterName VARCHAR(255),
    acceptsStrays boolean,
    lastMaintenanceDate DATE,
    capacity INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    status_ID INTEGER,
    providesVetCare boolean,
    priority_ID INTEGER,
    currentOccupancy INTEGER,
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter.assetId is 'Die universelle Id des Assets';

create table Evacuation (
    evacuationId VARCHAR(255),
    incident_incidentId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    affectedPopulation INTEGER,
    isCompleted boolean,
    PRIMARY KEY(evacuationId)
);


create table EnvironmentalControl_alerts (
    controlId VARCHAR(255),
    alerts VARCHAR(255),
    PRIMARY KEY(controlId)
);

comment on column EnvironmentalControl_alerts.controlId is 'Referenz zur Ursprungstabelle';

create table AuditLog (
    logId VARCHAR(255),
    performedBy VARCHAR(255),
    transaction_transactionId VARCHAR(255),
    timestamp TIMESTAMP,
    action VARCHAR(255),
    details VARCHAR(255),
    PRIMARY KEY(logId)
);


create table InventoryItem (
    itemId VARCHAR(255),
    stockLevel INTEGER,
    price float(8),
    isDiscounted boolean,
    store_assetId VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(itemId)
);


create table Elevator (
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    installationDate DATE,
    currentFloor INTEGER,
    expectedLifespanYears INTEGER,
    totalFloors INTEGER,
    type_ID INTEGER,
    operationalStatus_ID INTEGER,
    status_ID INTEGER,
    priority_ID INTEGER,
    capacity INTEGER,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Elevator.assetId is 'Die universelle Id des Assets';

create table ResourceSchedule_maintenanceWindows (
    scheduleId VARCHAR(255),
    maintenanceWindows VARCHAR(255),
    PRIMARY KEY(scheduleId)
);

comment on column ResourceSchedule_maintenanceWindows.scheduleId is 'Referenz zur Ursprungstabelle';

create table MaintenanceTicket (
    ticketId VARCHAR(255),
    reportTime TIMESTAMP,
    isUrgent boolean,
    resolved boolean,
    bathroom_assetId VARCHAR(255),
    issue VARCHAR(255),
    PRIMARY KEY(ticketId)
);


create table LibraryBranch (
    assetId VARCHAR(255),
    branchName VARCHAR(255),
    computerStations INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    capacity INTEGER,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    hasStudyRooms boolean,
    acquisitionCost float(8),
    status_ID INTEGER,
    priority_ID INTEGER,
    installationDate DATE,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch.assetId is 'Die universelle Id des Assets';

create table DataCollection (
    datasetId VARCHAR(255),
    collectionEnd TIMESTAMP,
    isBackedUp boolean,
    experiment_experimentId VARCHAR(255),
    collectionStart TIMESTAMP,
    sampleSize float(8),
    format VARCHAR(255),
    classification_ID INTEGER,
    PRIMARY KEY(datasetId)
);


create table VeterinaryClinic_specialists (
    assetId VARCHAR(255),
    specialists VARCHAR(255),
    PRIMARY KEY(assetId, specialists)
);

comment on column VeterinaryClinic_specialists.assetId is 'Referenz zur Ursprungstabelle';

create table Machine_capabilities (
    machineId VARCHAR(255),
    capabilities VARCHAR(255),
    PRIMARY KEY(machineId, capabilities)
);

comment on column Machine_capabilities.machineId is 'Referenz zur Ursprungstabelle';

create table TouristAttraction (
    assetId VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    entryFee float(8),
    status_ID INTEGER,
    name VARCHAR(255),
    isAccessible boolean,
    expectedLifespanYears INTEGER,
    priority_ID INTEGER,
    type_ID INTEGER,
    lastMaintenanceDate DATE,
    installationDate DATE,
    acquisitionCost float(8),
    dailyVisitorCapacity INTEGER,
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction.assetId is 'Die universelle Id des Assets';

create table Patient (
    patientId VARCHAR(255),
    department_ID INTEGER,
    vitals_temperature float(8),
    vitals_heartRate INTEGER,
    vitals_bloodPressureSystolic INTEGER,
    vitals_bloodPressureDiastolic INTEGER,
    vitals_respiratoryRate INTEGER,
    vitals_oxygenSaturation float(8),
    bloodType VARCHAR(255),
    admissionDate DATE,
    status_ID INTEGER,
    PRIMARY KEY(patientId)
);


create table Vendor (
    vendorId VARCHAR(255),
    licenseExpiry DATE,
    category_ID INTEGER,
    market_assetId VARCHAR(255),
    products VARCHAR(255),
    isRegistered boolean,
    PRIMARY KEY(vendorId)
);


create table RecyclingFacility_acceptedTypes (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column RecyclingFacility_acceptedTypes.assetId is 'Referenz zur Ursprungstabelle';

create table Laboratory_safetyProtocols (
    assetId VARCHAR(255),
    safetyProtocols VARCHAR(255),
    PRIMARY KEY(assetId, safetyProtocols)
);

comment on column Laboratory_safetyProtocols.assetId is 'Referenz zur Ursprungstabelle';

create table StudyRoom (
    roomId VARCHAR(255),
    capacity INTEGER,
    hasProjector boolean,
    hasWhiteboard boolean,
    isOccupied boolean,
    branch_assetId VARCHAR(255),
    PRIMARY KEY(roomId)
);


create table LoanTransaction (
    loanId VARCHAR(255),
    resource_resourceId VARCHAR(255),
    borrowDate TIMESTAMP,
    dueDate TIMESTAMP,
    returnDate TIMESTAMP,
    isOverdue boolean,
    fineAmount float(8),
    member_memberId VARCHAR(255),
    PRIMARY KEY(loanId)
);


create table RetailStore (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    name VARCHAR(255),
    floorArea float(8),
    priority_ID INTEGER,
    status_ID INTEGER,
    employeeCount INTEGER,
    isChainStore boolean,
    lastMaintenanceDate DATE,
    type_ID INTEGER,
    segment_ID INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column RetailStore.assetId is 'Die universelle Id des Assets';

create table ManufacturingPlant_safetyProtocols (
    assetId VARCHAR(255),
    safetyProtocols VARCHAR(255),
    PRIMARY KEY(assetId, safetyProtocols)
);

comment on column ManufacturingPlant_safetyProtocols.assetId is 'Referenz zur Ursprungstabelle';

create table Farm_crops (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column Farm_crops.assetId is 'Referenz zur Ursprungstabelle';

create table SecurityIncident_affectedSystems (
    incidentId VARCHAR(255),
    affectedSystems VARCHAR(255),
    PRIMARY KEY(incidentId, affectedSystems)
);

comment on column SecurityIncident_affectedSystems.incidentId is 'Referenz zur Ursprungstabelle';

create table ManufacturingPlant (
    assetId VARCHAR(255),
    productionCapacity float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    employeeCount INTEGER,
    shiftCount INTEGER,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    priority_ID INTEGER,
    isTwentyFourSeven boolean,
    totalArea float(8),
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant.assetId is 'Die universelle Id des Assets';

create table Farm (
    assetId VARCHAR(255),
    lastHarvestDate DATE,
    installationDate DATE,
    expectedLifespanYears INTEGER,
    isOrganic boolean,
    irrigationType_ID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    status_ID INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    area float(8),
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Farm.assetId is 'Die universelle Id des Assets';

create table ServiceRequest (
    requestId VARCHAR(255),
    description VARCHAR(255),
    type_ID INTEGER,
    requester_citizenId VARCHAR(255),
    submissionTime TIMESTAMP,
    status VARCHAR(255),
    PRIMARY KEY(requestId)
);


create table Course (
    courseId VARCHAR(255),
    title VARCHAR(255),
    credits INTEGER,
    maxEnrollment INTEGER,
    isOnline boolean,
    level_ID INTEGER,
    PRIMARY KEY(courseId)
);


create table MaintenanceRecord (
    recordId VARCHAR(255),
    maintenanceDate DATE,
    work VARCHAR(255),
    cost float(8),
    contractor VARCHAR(255),
    furniture_assetId VARCHAR(255),
    PRIMARY KEY(recordId)
);


create table ClimateProject (
    projectId VARCHAR(255),
    strategy_ID INTEGER,
    description VARCHAR(255),
    startDate DATE,
    budget float(8),
    isActive boolean,
    PRIMARY KEY(projectId)
);


create table Experiment (
    experimentId VARCHAR(255),
    scheduledStart TIMESTAMP,
    scheduledEnd TIMESTAMP,
    dependencies VARCHAR(255),
    metadata_startDate DATE,
    metadata_endDate DATE,
    metadata_methodology VARCHAR(255),
    hasEthicalApproval boolean,
    phase_ID INTEGER,
    location_assetId VARCHAR(255),
    PRIMARY KEY(experimentId)
);


create table Citizen (
    citizenId VARCHAR(255),
    firstName VARCHAR(255),
    lastName VARCHAR(255),
    dateOfBirth DATE,
    email VARCHAR(255),
    phone VARCHAR(255),
    residence_latitude float(8),
    residence_longitude float(8),
    residence_altitude float(8),
    residence_addressString VARCHAR(255),
    PRIMARY KEY(citizenId)
);


create table Patient_allergies (
    patientId VARCHAR(255),
    allergies VARCHAR(255),
    PRIMARY KEY(patientId, allergies)
);

comment on column Patient_allergies.patientId is 'Referenz zur Ursprungstabelle';

create table FilmPermit_equipment (
    permitId VARCHAR(255),
    equipment VARCHAR(255),
    PRIMARY KEY(permitId)
);

comment on column FilmPermit_equipment.permitId is 'Referenz zur Ursprungstabelle';

create table TransportRoute_segments (
    routeId VARCHAR(255),
    estimatedTimeMinutes INTEGER,
    startPoint_latitude float(8),
    startPoint_longitude float(8),
    startPoint_altitude float(8),
    startPoint_addressString VARCHAR(255),
    endPoint_latitude float(8),
    endPoint_longitude float(8),
    endPoint_altitude float(8),
    endPoint_addressString VARCHAR(255),
    distance float(8),
    PRIMARY KEY(routeId, estimatedTimeMinutes, startPoint_latitude, startPoint_longitude, startPoint_altitude, startPoint_addressString, endPoint_latitude, endPoint_longitude, endPoint_altitude, endPoint_addressString, distance)
);

comment on column TransportRoute_segments.routeId is 'Referenz zur Ursprungstabelle';

create table AuthenticationSystem_activeTokens (
    systemId VARCHAR(255),
    activeTokens VARCHAR(255),
    PRIMARY KEY(systemId, activeTokens)
);

comment on column AuthenticationSystem_activeTokens.systemId is 'Referenz zur Ursprungstabelle';

create table ResourceSchedule_users (
    scheduleId VARCHAR(255),
    users VARCHAR(255),
    PRIMARY KEY(scheduleId, users)
);

comment on column ResourceSchedule_users.scheduleId is 'Referenz zur Ursprungstabelle';

create table DigitalSign (
    assetId VARCHAR(255),
    status_ID INTEGER,
    priority_ID INTEGER,
    installationDate DATE,
    acquisitionCost float(8),
    resolution VARCHAR(255),
    isInteractive boolean,
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    type_ID INTEGER,
    contentType_ID INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column DigitalSign.assetId is 'Die universelle Id des Assets';

create table PostOffice_serviceHours (
    assetId VARCHAR(255),
    serviceHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column PostOffice_serviceHours.assetId is 'Referenz zur Ursprungstabelle';

create table StreetLight_scheduleOn (
    assetId VARCHAR(255),
    scheduleOn TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column StreetLight_scheduleOn.assetId is 'Referenz zur Ursprungstabelle';

create table TransportRoute (
    routeId VARCHAR(255),
    routeName VARCHAR(255),
    firstDepartureTime TIMESTAMP,
    lastDepartureTime TIMESTAMP,
    frequencyMinutes INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(routeId)
);


create table CulturalEvent (
    eventId VARCHAR(255),
    category_ID INTEGER,
    ticketing_basePrice float(8),
    ticketing_discount float(8),
    ticketing_availableSeats INTEGER,
    ticketing_isRefundable boolean,
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    curator VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table ComplianceAudit_protocols (
    auditId VARCHAR(255),
    protocolId VARCHAR(255),
    PRIMARY KEY(auditId)
);

comment on column ComplianceAudit_protocols.auditId is 'Referenz zur Ursprungstabelle';

create table ProductionCrew (
    crewId VARCHAR(255),
    productionCompany VARCHAR(255),
    contactPerson VARCHAR(255),
    permit_permitId VARCHAR(255),
    PRIMARY KEY(crewId)
);


create table LibraryResource (
    resourceId VARCHAR(255),
    location VARCHAR(255),
    isAvailable boolean,
    type_ID INTEGER,
    title VARCHAR(255),
    publicationDate DATE,
    publisher VARCHAR(255),
    PRIMARY KEY(resourceId)
);


create table Treatment (
    treatmentId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    provider VARCHAR(255),
    notes VARCHAR(255),
    completed boolean,
    type_ID INTEGER,
    patient_patientId VARCHAR(255),
    PRIMARY KEY(treatmentId)
);


create table ImpactNotification_mitigation (
    notificationId VARCHAR(255),
    mitigation VARCHAR(255),
    PRIMARY KEY(notificationId, mitigation)
);

comment on column ImpactNotification_mitigation.notificationId is 'Referenz zur Ursprungstabelle';

create table LibraryMember (
    memberId VARCHAR(255),
    membershipExpiry DATE,
    isActive boolean,
    currentBorrows INTEGER,
    level_ID INTEGER,
    name VARCHAR(255),
    email VARCHAR(255),
    joinDate DATE,
    PRIMARY KEY(memberId)
);


create table AuthenticationSystem_supportedMethods (
    systemId VARCHAR(255),
    supportedMethods VARCHAR(255),
    PRIMARY KEY(systemId, supportedMethods)
);

comment on column AuthenticationSystem_supportedMethods.systemId is 'Referenz zur Ursprungstabelle';

create table SmartDevice (
    deviceId VARCHAR(255),
    deviceType VARCHAR(255),
    isOnline boolean,
    lastPing TIMESTAMP,
    firmwareVersion VARCHAR(255),
    building_assetId VARCHAR(255),
    PRIMARY KEY(deviceId)
);


create table VeterinaryClinic (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    hasLaboratory boolean,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    status_ID INTEGER,
    capacity INTEGER,
    clinicName VARCHAR(255),
    emergencyTwentyFourHour boolean,
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic.assetId is 'Die universelle Id des Assets';

create table Laboratory_domains (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column Laboratory_domains.assetId is 'Referenz zur Ursprungstabelle';

create table HealthcareFacility_specialties (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column HealthcareFacility_specialties.assetId is 'Referenz zur Ursprungstabelle';

create table AccessCredential_authorizedAreas (
    credentialId VARCHAR(255),
    authorizedAreas VARCHAR(255),
    PRIMARY KEY(credentialId, authorizedAreas)
);

comment on column AccessCredential_authorizedAreas.credentialId is 'Referenz zur Ursprungstabelle';

create table FinancialAccount (
    accountId VARCHAR(255),
    openedDate DATE,
    institution_institutionId VARCHAR(255),
    accountType VARCHAR(255),
    balance float(8),
    isFrozen boolean,
    currency VARCHAR(255),
    PRIMARY KEY(accountId)
);


create table FinancialInstitution (
    institutionId VARCHAR(255),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    assetId VARCHAR(255),
    status_ID INTEGER,
    name VARCHAR(255),
    acquisitionCost float(8),
    isActive boolean,
    securityLevel_ID INTEGER,
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution.institutionId is 'Id of the Institution';
comment on column FinancialInstitution.assetId is 'Die universelle Id des Assets';

create table ProductionLine (
    lineId VARCHAR(255),
    status_ID INTEGER,
    metrics_efficiency float(8),
    metrics_defectRate INTEGER,
    metrics_energyConsumption float(8),
    metrics_targetOutput INTEGER,
    metrics_actualOutput INTEGER,
    metrics_materialWaste float(8),
    workerCount INTEGER,
    outputRate float(8),
    currentProduct VARCHAR(255),
    lastStartup TIMESTAMP,
    type_ID INTEGER,
    PRIMARY KEY(lineId)
);


create table WeatherAlert (
    alertId VARCHAR(255),
    message VARCHAR(255),
    issueTime TIMESTAMP,
    expiryTime TIMESTAMP,
    isActive boolean,
    level_ID INTEGER,
    PRIMARY KEY(alertId)
);


create table SportsFacility (
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    name VARCHAR(255),
    priority_ID INTEGER,
    isIndoor boolean,
    type_ID INTEGER,
    hasFloodlights boolean,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    spectatorCapacity INTEGER,
    lastMaintenanceDate DATE,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column SportsFacility.assetId is 'Die universelle Id des Assets';

create table Inspection (
    inspectionId VARCHAR(255),
    inspectionDate DATE,
    passed boolean,
    followupDate DATE,
    restaurant_assetId VARCHAR(255),
    PRIMARY KEY(inspectionId)
);


create table ImpactNotification (
    notificationId VARCHAR(255),
    requiresEvacuation boolean,
    permit_permitId VARCHAR(255),
    noticeTime TIMESTAMP,
    PRIMARY KEY(notificationId)
);


create table DataTransfer (
    transferId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    isEncrypted boolean,
    source_assetId VARCHAR(255),
    destination_assetId VARCHAR(255),
    PRIMARY KEY(transferId)
);


create table TreatmentOperation (
    operationId VARCHAR(255),
    startTime TIMESTAMP,
    completionTime TIMESTAMP,
    materialUsed float(8),
    type_ID INTEGER,
    route_routeId VARCHAR(255),
    PRIMARY KEY(operationId)
);


create table ResourceSchedule_experiments (
    scheduleId VARCHAR(255),
    experimentId VARCHAR(255),
    PRIMARY KEY(scheduleId)
);

comment on column ResourceSchedule_experiments.scheduleId is 'Referenz zur Ursprungstabelle';

create table SportsFacility_supportedSports (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column SportsFacility_supportedSports.assetId is 'Referenz zur Ursprungstabelle';

create table SafetyProtocol (
    protocolId VARCHAR(255),
    hazardType VARCHAR(255),
    lastReview DATE,
    requiresTraining boolean,
    lab_assetId VARCHAR(255),
    PRIMARY KEY(protocolId)
);


create table SafetyProtocol_precautions (
    protocolId VARCHAR(255),
    precautions VARCHAR(255),
    PRIMARY KEY(protocolId, precautions)
);

comment on column SafetyProtocol_precautions.protocolId is 'Referenz zur Ursprungstabelle';

create table RegulatoryReport_findings (
    reportId VARCHAR(255),
    findings VARCHAR(255),
    PRIMARY KEY(reportId)
);

comment on column RegulatoryReport_findings.reportId is 'Referenz zur Ursprungstabelle';

create table RiskAssessment_recommendations (
    assessmentId VARCHAR(255),
    recommendations VARCHAR(255),
    PRIMARY KEY(assessmentId)
);

comment on column RiskAssessment_recommendations.assessmentId is 'Referenz zur Ursprungstabelle';

create table FareTransaction (
    transactionId VARCHAR(255),
    card_cardId VARCHAR(255),
    timestamp TIMESTAMP,
    amount float(8),
    route VARCHAR(255),
    isRefunded boolean,
    PRIMARY KEY(transactionId)
);


create table WildlifeZone_presentSpecies (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column WildlifeZone_presentSpecies.assetId is 'Referenz zur Ursprungstabelle';

create table ManufacturingPlant_productionTypes (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column ManufacturingPlant_productionTypes.assetId is 'Referenz zur Ursprungstabelle';

create table StreetFurniture (
    assetId VARCHAR(255),
    needsRepair boolean,
    installationDate DATE,
    priority_ID INTEGER,
    name VARCHAR(255),
    status_ID INTEGER,
    material VARCHAR(255),
    type_ID INTEGER,
    state_ID INTEGER,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column StreetFurniture.assetId is 'Die universelle Id des Assets';

create table Laboratory (
    assetId VARCHAR(255),
    securityLevel_ID INTEGER,
    acquisitionCost float(8),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    totalArea float(8),
    hasCleanRoom boolean,
    name VARCHAR(255),
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    expectedLifespanYears INTEGER,
    workstationCount INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Laboratory.assetId is 'Die universelle Id des Assets';

create table MaintenanceLog (
    logId VARCHAR(255),
    serviceTime TIMESTAMP,
    technician VARCHAR(255),
    work VARCHAR(255),
    resolved boolean,
    elevator_assetId VARCHAR(255),
    PRIMARY KEY(logId)
);


create table SnowRoute (
    routeId VARCHAR(255),
    length float(8),
    estimatedTime INTEGER,
    isCleared boolean,
    lastCleared TIMESTAMP,
    priority_ID INTEGER,
    PRIMARY KEY(routeId)
);


create table PublicBathroom (
    assetId VARCHAR(255),
    lastCleaning TIMESTAMP,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    isOccupied boolean,
    installationDate DATE,
    priority_ID INTEGER,
    name VARCHAR(255),
    hasChangingTable boolean,
    cleaningStatus_ID INTEGER,
    acquisitionCost float(8),
    status_ID INTEGER,
    type_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column PublicBathroom.assetId is 'Die universelle Id des Assets';

create table Transaction (
    transactionId VARCHAR(255),
    destination_accountId VARCHAR(255),
    isProcessed boolean,
    type_ID INTEGER,
    metadata_timestamp TIMESTAMP,
    metadata_originatorId VARCHAR(255),
    metadata_beneficiaryId VARCHAR(255),
    metadata_amount float(8),
    metadata_purpose VARCHAR(255),
    metadata_currency VARCHAR(255),
    status VARCHAR(255),
    source_accountId VARCHAR(255),
    PRIMARY KEY(transactionId)
);


create table RegulatoryReport (
    reportId VARCHAR(255),
    reportType VARCHAR(255),
    institution_institutionId VARCHAR(255),
    reportingPeriod DATE,
    submitted boolean,
    PRIMARY KEY(reportId)
);


create table FinancialInstitution_licenses (
    institutionId VARCHAR(255),
    licenses VARCHAR(255),
    PRIMARY KEY(institutionId)
);

comment on column FinancialInstitution_licenses.institutionId is 'Referenz zur Ursprungstabelle';

create table LibraryResource_authors (
    resourceId VARCHAR(255),
    authors VARCHAR(255),
    PRIMARY KEY(resourceId)
);

comment on column LibraryResource_authors.resourceId is 'Referenz zur Ursprungstabelle';

create table TouristAttraction_openingHours (
    assetId VARCHAR(255),
    openingHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column TouristAttraction_openingHours.assetId is 'Referenz zur Ursprungstabelle';

create table MonitoringStation_readings (
    stationId VARCHAR(255),
    exceedsLimit boolean,
    pollutant_ID INTEGER,
    concentration float(8),
    timestamp TIMESTAMP,
    PRIMARY KEY(stationId)
);

comment on column MonitoringStation_readings.stationId is 'Referenz zur Ursprungstabelle';

create table FilmPermit (
    permitId VARCHAR(255),
    type_ID INTEGER,
    status_ID INTEGER,
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    location VARCHAR(255),
    crewSize INTEGER,
    PRIMARY KEY(permitId)
);


create table NoiseSensor (
    assetId VARCHAR(255),
    installationDate DATE,
    averageReading float(8),
    lastPeak TIMESTAMP,
    needsCalibration boolean,
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    expectedLifespanYears INTEGER,
    currentLevel_ID INTEGER,
    acquisitionCost float(8),
    sources_ID INTEGER,
    lastMaintenanceDate DATE,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column NoiseSensor.assetId is 'Die universelle Id des Assets';

create table FraudDetection (
    detectionId VARCHAR(255),
    requiresReview boolean,
    risk_creditScore INTEGER,
    risk_defaultProbability float(8),
    risk_lastAssessment DATE,
    resolution VARCHAR(255),
    transaction_transactionId VARCHAR(255),
    PRIMARY KEY(detectionId)
);


create table AccessCredential (
    credentialId VARCHAR(255),
    isActive boolean,
    lab_assetId VARCHAR(255),
    clearanceLevel_ID INTEGER,
    holderName VARCHAR(255),
    validFrom TIMESTAMP,
    validUntil TIMESTAMP,
    PRIMARY KEY(credentialId)
);


create table Artwork (
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    status_ID INTEGER,
    priority_ID INTEGER,
    installationDate DATE,
    requiresRestoration boolean,
    type_ID INTEGER,
    artistType_ID INTEGER,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    materials VARCHAR(255),
    expectedLifespanYears INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Artwork.assetId is 'Die universelle Id des Assets';

create table Market (
    assetId VARCHAR(255),
    closeTime TIMESTAMP,
    lastMaintenanceDate DATE,
    priority_ID INTEGER,
    stallCapacity INTEGER,
    type_ID INTEGER,
    openTime TIMESTAMP,
    status_ID INTEGER,
    name VARCHAR(255),
    expectedLifespanYears INTEGER,
    installationDate DATE,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Market.assetId is 'Die universelle Id des Assets';

create table EnvironmentalControl_gasLevels (
    controlId VARCHAR(255),
    gasLevels float(8),
    PRIMARY KEY(controlId)
);

comment on column EnvironmentalControl_gasLevels.controlId is 'Referenz zur Ursprungstabelle';

create table WildlifeZone (
    assetId VARCHAR(255),
    type_ID INTEGER,
    lastMaintenanceDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    area float(8),
    isProtected boolean,
    lastSurvey DATE,
    acquisitionCost float(8),
    priority_ID INTEGER,
    name VARCHAR(255),
    status_ID INTEGER,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    PRIMARY KEY(assetId)
);

comment on column WildlifeZone.assetId is 'Die universelle Id des Assets';

create table MaintenanceLog_tasks (
    logId VARCHAR(255),
    tasks VARCHAR(255),
    PRIMARY KEY(logId)
);

comment on column MaintenanceLog_tasks.logId is 'Referenz zur Ursprungstabelle';

create table ParkingTransaction (
    transactionId VARCHAR(255),
    entryTime TIMESTAMP,
    exitTime TIMESTAMP,
    amount float(8),
    isPaid boolean,
    vehicleSize_ID INTEGER,
    PRIMARY KEY(transactionId)
);


create table ComplianceCheck (
    checkId VARCHAR(255),
    passedAML boolean,
    passedKYC boolean,
    transaction_transactionId VARCHAR(255),
    PRIMARY KEY(checkId)
);


create table RiskAssessment (
    assessmentId VARCHAR(255),
    institution_institutionId VARCHAR(255),
    profile_creditScore INTEGER,
    profile_defaultProbability float(8),
    profile_lastAssessment DATE,
    assessmentDate DATE,
    PRIMARY KEY(assessmentId)
);


create table FraudDetection_anomalyIndicators (
    detectionId VARCHAR(255),
    anomalyIndicators VARCHAR(255),
    PRIMARY KEY(detectionId)
);

comment on column FraudDetection_anomalyIndicators.detectionId is 'Referenz zur Ursprungstabelle';

create table WildlifeIncident (
    incidentId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresAction boolean,
    resolution VARCHAR(255),
    species_ID INTEGER,
    PRIMARY KEY(incidentId)
);


create table SafetyIncident_requiredUnits (
    incidentId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(incidentId)
);

comment on column SafetyIncident_requiredUnits.incidentId is 'Referenz zur Ursprungstabelle';

create table NoiseComplaint (
    complaintId VARCHAR(255),
    resolution VARCHAR(255),
    source_ID INTEGER,
    reportTime TIMESTAMP,
    description VARCHAR(255),
    isResolved boolean,
    PRIMARY KEY(complaintId)
);


create table MaintenanceLog_replacedParts (
    logId VARCHAR(255),
    replacedParts VARCHAR(255),
    PRIMARY KEY(logId)
);

comment on column MaintenanceLog_replacedParts.logId is 'Referenz zur Ursprungstabelle';

create table Drone (
    assetId VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    range float(8),
    type_ID INTEGER,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    batteryLevel float(8),
    status_ID INTEGER,
    priority_ID INTEGER,
    name VARCHAR(255),
    maxAltitude float(8),
    flightStatus_ID INTEGER,
    lastMaintenanceDate DATE,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column Drone.assetId is 'Die universelle Id des Assets';

create table AuthenticationSystem (
    systemId VARCHAR(255),
    level_ID INTEGER,
    multiFactorEnabled boolean,
    PRIMARY KEY(systemId)
);


create table FlightMission (
    missionId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    purpose VARCHAR(255),
    isCompleted boolean,
    drone_assetId VARCHAR(255),
    PRIMARY KEY(missionId)
);


create table EmissionReport (
    reportId VARCHAR(255),
    unit VARCHAR(255),
    measurementDate DATE,
    verified boolean,
    source_ID INTEGER,
    amount float(8),
    PRIMARY KEY(reportId)
);


create table EducationalInstitution (
    assetId VARCHAR(255),
    expectedLifespanYears INTEGER,
    isPublic boolean,
    installationDate DATE,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    lastMaintenanceDate DATE,
    staffCount INTEGER,
    name VARCHAR(255),
    priority_ID INTEGER,
    studentCapacity INTEGER,
    accreditationStatus VARCHAR(255),
    type_ID INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column EducationalInstitution.assetId is 'Die universelle Id des Assets';

create table Restaurant (
    assetId VARCHAR(255),
    type_ID INTEGER,
    priority_ID INTEGER,
    acquisitionCost float(8),
    hasDelivery boolean,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    status_ID INTEGER,
    rating_ID INTEGER,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    seatingCapacity INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Restaurant.assetId is 'Die universelle Id des Assets';

create table LibraryBranch_operatingHours (
    assetId VARCHAR(255),
    operatingHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch_operatingHours.assetId is 'Referenz zur Ursprungstabelle';

create table WaterSource (
    assetId VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    capacity float(8),
    isActive boolean,
    quality_ID INTEGER,
    status_ID INTEGER,
    name VARCHAR(255),
    installationDate DATE,
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    currentLevel float(8),
    flowRate float(8),
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WaterSource.assetId is 'Die universelle Id des Assets';

create table ComplianceAudit (
    auditId VARCHAR(255),
    auditDate DATE,
    auditor VARCHAR(255),
    passed boolean,
    lab_assetId VARCHAR(255),
    PRIMARY KEY(auditId)
);


create table Market_operatingDays (
    assetId VARCHAR(255),
    operatingDays VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column Market_operatingDays.assetId is 'Referenz zur Ursprungstabelle';

create table Laboratory_specializations (
    assetId VARCHAR(255),
    specializations VARCHAR(255),
    PRIMARY KEY(assetId, specializations)
);

comment on column Laboratory_specializations.assetId is 'Referenz zur Ursprungstabelle';

create table PowerFlow (
    flowId VARCHAR(255),
    isStable boolean,
    source_assetId VARCHAR(255),
    destination_assetId VARCHAR(255),
    amount float(8),
    timestamp TIMESTAMP,
    PRIMARY KEY(flowId)
);


create table Vehicle (
    registrationNumber VARCHAR(255),
    type_ID INTEGER,
    status_ID INTEGER,
    assetId VARCHAR(255),
    capacity INTEGER,
    currentFuelLevel float(8),
    currentRoute_routeId VARCHAR(255),
    expectedLifespanYears INTEGER,
    acquisitionCost float(8),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    installationDate DATE,
    currentPassengerCount INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(registrationNumber)
);

comment on column Vehicle.assetId is 'Die universelle Id des Assets';

create table CulturalVenue_facilities (
    assetId VARCHAR(255),
    facilities VARCHAR(255),
    PRIMARY KEY(assetId, facilities)
);

comment on column CulturalVenue_facilities.assetId is 'Referenz zur Ursprungstabelle';

create table Equipment_restrictions (
    equipmentId VARCHAR(255),
    restrictions VARCHAR(255),
    PRIMARY KEY(equipmentId)
);

comment on column Equipment_restrictions.equipmentId is 'Referenz zur Ursprungstabelle';

create table ComplianceAudit_recommendations (
    auditId VARCHAR(255),
    recommendations VARCHAR(255),
    PRIMARY KEY(auditId)
);

comment on column ComplianceAudit_recommendations.auditId is 'Referenz zur Ursprungstabelle';

create table StudyRoom_reservations (
    roomId VARCHAR(255),
    reservations TIMESTAMP,
    PRIMARY KEY(roomId)
);

comment on column StudyRoom_reservations.roomId is 'Referenz zur Ursprungstabelle';

create table TreatmentPlant_stages (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant_stages.assetId is 'Referenz zur Ursprungstabelle';

create table ParkingFacility (
    assetId VARCHAR(255),
    type_ID INTEGER,
    priority_ID INTEGER,
    status_ID INTEGER,
    availableSpaces INTEGER,
    hourlyRate float(8),
    installationDate DATE,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    totalSpaces INTEGER,
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    hasChargingStations boolean,
    acquisitionCost float(8),
    PRIMARY KEY(assetId)
);

comment on column ParkingFacility.assetId is 'Die universelle Id des Assets';

create table VeterinaryClinic_services (
    assetId VARCHAR(255),
    services VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column VeterinaryClinic_services.assetId is 'Referenz zur Ursprungstabelle';

create table Sensor (
    assetId VARCHAR(255),
    needsCalibration boolean,
    installationDate DATE,
    readingValue float(8),
    status_ID INTEGER,
    priority_ID INTEGER,
    name VARCHAR(255),
    sensorType VARCHAR(255),
    lastMaintenanceDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    acquisitionCost float(8),
    unit VARCHAR(255),
    lastReading TIMESTAMP,
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Sensor.assetId is 'Die universelle Id des Assets';

create table ComplianceCheck_regulations (
    checkId VARCHAR(255),
    regulations VARCHAR(255),
    PRIMARY KEY(checkId)
);

comment on column ComplianceCheck_regulations.checkId is 'Referenz zur Ursprungstabelle';

create table Experiment_prerequisites (
    experimentId VARCHAR(255),
    prerequisites VARCHAR(255),
    PRIMARY KEY(experimentId)
);

comment on column Experiment_prerequisites.experimentId is 'Referenz zur Ursprungstabelle';

create table ProductionCrew_vehicles (
    crewId VARCHAR(255),
    vehicles VARCHAR(255),
    PRIMARY KEY(crewId)
);

comment on column ProductionCrew_vehicles.crewId is 'Referenz zur Ursprungstabelle';

create table Inspection_violations (
    inspectionId VARCHAR(255),
    violations VARCHAR(255),
    PRIMARY KEY(inspectionId)
);

comment on column Inspection_violations.inspectionId is 'Referenz zur Ursprungstabelle';

create table ImpactNotification_affectedAreas (
    notificationId VARCHAR(255),
    affectedAreas VARCHAR(255),
    PRIMARY KEY(notificationId, affectedAreas)
);

comment on column ImpactNotification_affectedAreas.notificationId is 'Referenz zur Ursprungstabelle';

create table SecurityIncident (
    incidentId VARCHAR(255),
    resolved boolean,
    impactLevel_ID INTEGER,
    detectionTime TIMESTAMP,
    description VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table MaterialInventory (
    inventoryId VARCHAR(255),
    storageLocation VARCHAR(255),
    hazardous boolean,
    materialType VARCHAR(255),
    quantity float(8),
    unit VARCHAR(255),
    expiryDate DATE,
    supplier VARCHAR(255),
    PRIMARY KEY(inventoryId)
);


create table SignContent (
    contentId VARCHAR(255),
    content VARCHAR(255),
    startDisplay TIMESTAMP,
    endDisplay TIMESTAMP,
    priority INTEGER,
    sign_assetId VARCHAR(255),
    PRIMARY KEY(contentId)
);


create table PostOffice (
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    staffCount INTEGER,
    hasAutomation boolean,
    name VARCHAR(255),
    installationDate DATE,
    storageCapacity float(8),
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    counterCount INTEGER,
    priority_ID INTEGER,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column PostOffice.assetId is 'Die universelle Id des Assets';

create table EmergencyTeam (
    teamId VARCHAR(255),
    isAvailable boolean,
    specialty_ID INTEGER,
    currentLocation_latitude float(8),
    currentLocation_longitude float(8),
    currentLocation_altitude float(8),
    currentLocation_addressString VARCHAR(255),
    memberCount INTEGER,
    PRIMARY KEY(teamId)
);


create table QualityCheck_defects (
    checkId VARCHAR(255),
    defects VARCHAR(255),
    PRIMARY KEY(checkId)
);

comment on column QualityCheck_defects.checkId is 'Referenz zur Ursprungstabelle';

create table StreetLight (
    assetId VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    energyConsumption float(8),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    hasMotionSensor boolean,
    lastMaintenanceDate DATE,
    priority_ID INTEGER,
    acquisitionCost float(8),
    type_ID INTEGER,
    brightness_ID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column StreetLight.assetId is 'Die universelle Id des Assets';

create table AuthenticationSystem_blockedIPs (
    systemId VARCHAR(255),
    blockedIPs VARCHAR(255),
    PRIMARY KEY(systemId, blockedIPs)
);

comment on column AuthenticationSystem_blockedIPs.systemId is 'Referenz zur Ursprungstabelle';

create table PowerPlant (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    source_ID INTEGER,
    lastMaintenanceDate DATE,
    currentOutput float(8),
    efficiency float(8),
    isBackupSource boolean,
    name VARCHAR(255),
    installationDate DATE,
    status_ID INTEGER,
    capacity float(8),
    priority_ID INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column PowerPlant.assetId is 'Die universelle Id des Assets';

create table ProductionCrew_specialNeeds (
    crewId VARCHAR(255),
    specialNeeds VARCHAR(255),
    PRIMARY KEY(crewId, specialNeeds)
);

comment on column ProductionCrew_specialNeeds.crewId is 'Referenz zur Ursprungstabelle';

create table ManufacturingPlant_certifications (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column ManufacturingPlant_certifications.assetId is 'Referenz zur Ursprungstabelle';

create table FilmLocation (
    assetId VARCHAR(255),
    isIndoor boolean,
    dailyRate float(8),
    maxOccupancy INTEGER,
    status_ID INTEGER,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    locationName VARCHAR(255),
    installationDate DATE,
    expectedLifespanYears INTEGER,
    hasParking boolean,
    name VARCHAR(255),
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column FilmLocation.assetId is 'Die universelle Id des Assets';

create table Plot (
    plotId VARCHAR(255),
    isOccupied boolean,
    owner VARCHAR(255),
    type_ID INTEGER,
    schedule_frequency INTEGER,
    schedule_tasks VARCHAR(255),
    schedule_responsible VARCHAR(255),
    schedule_lastMaintenance DATE,
    schedule_nextMaintenance DATE,
    lastMaintenance DATE,
    PRIMARY KEY(plotId)
);


create table QualityCheck (
    checkId VARCHAR(255),
    passed boolean,
    action VARCHAR(255),
    line_lineId VARCHAR(255),
    timestamp TIMESTAMP,
    inspector VARCHAR(255),
    PRIMARY KEY(checkId)
);


create table AnimalShelter_services (
    assetId VARCHAR(255),
    services VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column AnimalShelter_services.assetId is 'Referenz zur Ursprungstabelle';

create table TransitCard (
    cardId VARCHAR(255),
    fareType_ID INTEGER,
    balance float(8),
    expiryDate DATE,
    isActive boolean,
    method_ID INTEGER,
    PRIMARY KEY(cardId)
);


create table Asset (
    assetId VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Asset.assetId is 'Die universelle Id des Assets';

create table SafetyIncident (
    incidentId VARCHAR(255),
    reportTime TIMESTAMP,
    description VARCHAR(255),
    requiresEvacuation boolean,
    type_ID INTEGER,
    PRIMARY KEY(incidentId)
);


create table ComplianceCheck_violations (
    checkId VARCHAR(255),
    violations VARCHAR(255),
    PRIMARY KEY(checkId)
);

comment on column ComplianceCheck_violations.checkId is 'Referenz zur Ursprungstabelle';

create table ResourceSchedule (
    scheduleId VARCHAR(255),
    hasConflicts boolean,
    isOptimized boolean,
    equipment_assetId VARCHAR(255),
    PRIMARY KEY(scheduleId)
);


create table DataPoint (
    dataId VARCHAR(255),
    source VARCHAR(255),
    isVerified boolean,
    type_ID INTEGER,
    value float(8),
    timestamp TIMESTAMP,
    PRIMARY KEY(dataId)
);


create table WasteCollection (
    collectionId VARCHAR(255),
    scheduledTime TIMESTAMP,
    estimatedVolume float(8),
    isCompleted boolean,
    type_ID INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(collectionId)
);


create table LightingZone (
    zoneId VARCHAR(255),
    schedule VARCHAR(255),
    isDimmed boolean,
    dailyUsage float(8),
    PRIMARY KEY(zoneId)
);


create table LightingZone_lights (
    zoneId VARCHAR(255),
    assetId VARCHAR(255),
    PRIMARY KEY(zoneId)
);

comment on column LightingZone_lights.zoneId is 'Referenz zur Ursprungstabelle';

create table CulturalVenue_operatingHours (
    assetId VARCHAR(255),
    operatingHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column CulturalVenue_operatingHours.assetId is 'Referenz zur Ursprungstabelle';

create table RiskAssessment_findings (
    assessmentId VARCHAR(255),
    findings VARCHAR(255),
    PRIMARY KEY(assessmentId)
);

comment on column RiskAssessment_findings.assessmentId is 'Referenz zur Ursprungstabelle';

create table GridNode (
    assetId VARCHAR(255),
    lastMaintenanceDate DATE,
    priority_ID INTEGER,
    voltage float(8),
    profile_ID INTEGER,
    isRedundant boolean,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    current float(8),
    status_ID INTEGER,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    type_ID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column GridNode.assetId is 'Die universelle Id des Assets';

create table Equipment (
    equipmentId VARCHAR(255),
    type VARCHAR(255),
    specifications VARCHAR(255),
    requiresPermit boolean,
    powerRequirement float(8),
    PRIMARY KEY(equipmentId)
);


create table FinancialInstitution_supportedCurrencies (
    institutionId VARCHAR(255),
    supportedCurrencies VARCHAR(255),
    PRIMARY KEY(institutionId, supportedCurrencies)
);

comment on column FinancialInstitution_supportedCurrencies.institutionId is 'Referenz zur Ursprungstabelle';

create table QualityCheck_parameters (
    checkId VARCHAR(255),
    parameters VARCHAR(255),
    PRIMARY KEY(checkId)
);

comment on column QualityCheck_parameters.checkId is 'Referenz zur Ursprungstabelle';

create table Restaurant_operatingHours (
    assetId VARCHAR(255),
    operatingHours TIMESTAMP,
    PRIMARY KEY(assetId)
);

comment on column Restaurant_operatingHours.assetId is 'Referenz zur Ursprungstabelle';

create table DataCollection_validationRules (
    datasetId VARCHAR(255),
    validationRules VARCHAR(255),
    PRIMARY KEY(datasetId, validationRules)
);

comment on column DataCollection_validationRules.datasetId is 'Referenz zur Ursprungstabelle';

create table Shipment (
    trackingId VARCHAR(255),
    receivedTime TIMESTAMP,
    estimatedDelivery TIMESTAMP,
    isInsured boolean,
    type_ID INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(trackingId)
);


create table Building (
    assetId VARCHAR(255),
    isSmartEnabled boolean,
    securityLevel_ID INTEGER,
    status_ID INTEGER,
    expectedLifespanYears INTEGER,
    installationDate DATE,
    type_ID INTEGER,
    acquisitionCost float(8),
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    priority_ID INTEGER,
    floors INTEGER,
    totalArea float(8),
    occupancy INTEGER,
    lastMaintenanceDate DATE,
    PRIMARY KEY(assetId)
);

comment on column Building.assetId is 'Die universelle Id des Assets';

create table HealthcareFacility (
    assetId VARCHAR(255),
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    bedCapacity INTEGER,
    hasEmergencyUnit boolean,
    acquisitionCost float(8),
    expectedLifespanYears INTEGER,
    currentOccupancy INTEGER,
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    type_ID INTEGER,
    installationDate DATE,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column HealthcareFacility.assetId is 'Die universelle Id des Assets';

create table SafetyProtocol_authorizedPersonnel (
    protocolId VARCHAR(255),
    authorizedPersonnel VARCHAR(255),
    PRIMARY KEY(protocolId, authorizedPersonnel)
);

comment on column SafetyProtocol_authorizedPersonnel.protocolId is 'Referenz zur Ursprungstabelle';

create table ResearchEquipment (
    assetId VARCHAR(255),
    specs_precision float(8),
    specs_accuracy float(8),
    specs_lastVerification TIMESTAMP,
    installationDate DATE,
    priority_ID INTEGER,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    serialNumber VARCHAR(255),
    purchaseDate DATE,
    requiresSpecialTraining boolean,
    warrantyExpiry DATE,
    lastCalibration TIMESTAMP,
    acquisitionCost float(8),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    name VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column ResearchEquipment.assetId is 'Die universelle Id des Assets';

create table ComplianceAudit_findings (
    auditId VARCHAR(255),
    findings VARCHAR(255),
    PRIMARY KEY(auditId)
);

comment on column ComplianceAudit_findings.auditId is 'Referenz zur Ursprungstabelle';

create table EmergencyIncident (
    incidentId VARCHAR(255),
    reportedTime TIMESTAMP,
    responseTime TIMESTAMP,
    isActive boolean,
    type_ID INTEGER,
    priority_ID INTEGER,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    PRIMARY KEY(incidentId)
);


create table EnvironmentalControl (
    controlId VARCHAR(255),
    temperature float(8),
    humidity float(8),
    withinSpecs boolean,
    pressure float(8),
    particleCount float(8),
    lab_assetId VARCHAR(255),
    PRIMARY KEY(controlId)
);


create table Event (
    eventId VARCHAR(255),
    startTime TIMESTAMP,
    endTime TIMESTAMP,
    expectedAttendance INTEGER,
    season_ID INTEGER,
    name VARCHAR(255),
    PRIMARY KEY(eventId)
);


create table LibraryBranch_facilities (
    assetId VARCHAR(255),
    facilities VARCHAR(255),
    PRIMARY KEY(assetId)
);

comment on column LibraryBranch_facilities.assetId is 'Referenz zur Ursprungstabelle';

create table QualityTest (
    testId VARCHAR(255),
    value float(8),
    timestamp TIMESTAMP,
    meetsStandard boolean,
    analyst VARCHAR(255),
    metric_ID INTEGER,
    PRIMARY KEY(testId)
);


create table Cemetery_availableTypes (
    assetId VARCHAR(255),
    ID INTEGER,
    PRIMARY KEY(assetId, ID)
);

comment on column Cemetery_availableTypes.assetId is 'Referenz zur Ursprungstabelle';

create table AnimalControl (
    caseId VARCHAR(255),
    reportTime TIMESTAMP,
    incidentType VARCHAR(255),
    location VARCHAR(255),
    resolved boolean,
    resolution VARCHAR(255),
    animalType_ID INTEGER,
    PRIMARY KEY(caseId)
);


create table PetLicense (
    licenseId VARCHAR(255),
    issueDate DATE,
    expiryDate DATE,
    fee float(8),
    rabiesVaccinated boolean,
    pet_petId VARCHAR(255),
    status_ID INTEGER,
    PRIMARY KEY(licenseId)
);


create table Machine (
    machineId VARCHAR(255),
    installationDate DATE,
    powerConsumption float(8),
    status_ID INTEGER,
    maintenance_frequency INTEGER,
    maintenance_tasks VARCHAR(255),
    maintenance_responsible VARCHAR(255),
    maintenance_lastMaintenance DATE,
    maintenance_nextMaintenance DATE,
    manufacturer VARCHAR(255),
    model VARCHAR(255),
    PRIMARY KEY(machineId)
);


create table TreatmentPlant (
    assetId VARCHAR(255),
    acquisitionCost float(8),
    priority_ID INTEGER,
    installationDate DATE,
    isOperational boolean,
    lastMaintenanceDate DATE,
    name VARCHAR(255),
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    status_ID INTEGER,
    currentFlow float(8),
    expectedLifespanYears INTEGER,
    dailyCapacity float(8),
    lastInspection DATE,
    PRIMARY KEY(assetId)
);

comment on column TreatmentPlant.assetId is 'Die universelle Id des Assets';

create table SmartMeter (
    meterId VARCHAR(255),
    currentReading float(8),
    peakDemand float(8),
    lastReadingTime TIMESTAMP,
    isOnline boolean,
    pattern_ID INTEGER,
    PRIMARY KEY(meterId)
);


create table Cemetery (
    assetId VARCHAR(255),
    name VARCHAR(255),
    totalArea float(8),
    totalPlots INTEGER,
    hasChapel boolean,
    priority_ID INTEGER,
    acquisitionCost float(8),
    availablePlots INTEGER,
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    status_ID INTEGER,
    PRIMARY KEY(assetId)
);

comment on column Cemetery.assetId is 'Die universelle Id des Assets';

create table WaterTreatmentPlant (
    assetId VARCHAR(255),
    name VARCHAR(255),
    installationDate DATE,
    location_latitude float(8),
    location_longitude float(8),
    location_altitude float(8),
    location_addressString VARCHAR(255),
    processingCapacity float(8),
    currentThroughput float(8),
    treatmentStages INTEGER,
    status_ID INTEGER,
    acquisitionCost float(8),
    priority_ID INTEGER,
    isOperating boolean,
    lastMaintenanceDate DATE,
    expectedLifespanYears INTEGER,
    PRIMARY KEY(assetId)
);

comment on column WaterTreatmentPlant.assetId is 'Die universelle Id des Assets';

create table ResearchEquipment_supportedExperiments (
    assetId VARCHAR(255),
    supportedExperiments VARCHAR(255),
    PRIMARY KEY(assetId, supportedExperiments)
);

comment on column ResearchEquipment_supportedExperiments.assetId is 'Referenz zur Ursprungstabelle';

