//
//  JDServicesConstants.h
//  JDServices
//
//  Created by Bott Sebastian on 2014-11-14
//
//  Unpublished Work (c) 2014-2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#pragma mark - Common Mapping Keys
extern NSString *_Nonnull const kKeyObjectCommonIdent;
extern NSString *_Nonnull const kKeyObjectCommonGUID;
extern NSString *_Nonnull const kKeyObjectCommonOwningOrganization;
extern NSString *_Nonnull const kKeyObjectCommonLink;
extern NSString *_Nonnull const kKeyObjectCommonLinks;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelation;
extern NSString *_Nonnull const kKeyObjectCommonLinksUri;
extern NSString *_Nonnull const kKeyObjectCommonName;
extern NSString *_Nonnull const kKeyObjectCommonObjectType;
extern NSString *_Nonnull const kKeyObjectCommonRate;
extern NSString *_Nonnull const kKeyObjectCommonRequired;
extern NSString *_Nonnull const kKeyObjectCommonTotal;
extern NSString *_Nonnull const kKeyObjectCommonType;
extern NSString *_Nonnull const kKeyObjectCommonUID;
extern NSString *_Nonnull const kKeyObjectCommonUnit;
extern NSString *_Nonnull const kKeyObjectCommonUnitId;
extern NSString *_Nonnull const kKeyObjectCommonValue;
extern NSString *_Nonnull const kKeyObjectCommonValueAsDouble;
extern NSString *_Nonnull const kKeyObjectCommonValueAsInteger;
extern NSString *_Nonnull const kKeyObjectCommonValueAsString;
extern NSString *_Nonnull const kKeyObjectCommonValues;
extern NSString *_Nonnull const kKeyObjectCommonVrDomainId;
extern NSString *_Nonnull const kKeyObjectCommonUOM;
extern NSString *_Nonnull const kKeyObjectCommonCreateTimestamp;
extern NSString *_Nonnull const kKeyObjectCommonEventTimestamp;
extern NSString *_Nonnull const kKeyObjectCommonNumber;
extern NSString *_Nonnull const kKeyObjectCommonSerialNumber;
extern NSString *_Nonnull const kKeyObjectCommonFirmwareVersion;
extern NSString *_Nonnull const kKeyObjectCommonArchived;
extern NSString *_Nonnull const kKeyObjectCommonNotes;
extern NSString *_Nonnull const kKeyObjectCommonFlagType;
extern NSString *_Nonnull const kKeyObjectCommonMetadata;
extern NSString *_Nonnull const kKeyObjectCommonPrefKey;
extern NSString *_Nonnull const kKeyObjectCommonHexColor;
extern NSString *_Nonnull const kKeyObjectCommonPreferences;
extern NSString *_Nonnull const kKeyObjectCommonCategoryTitle;
extern NSString *_Nonnull const kKeyObjectCommonSourceNode;
extern NSString *_Nonnull const kKeyObjectCommonPreferred;

#pragma mark - Field Operation Mapping Keys
extern NSString *_Nonnull const kKeyObjectFieldOperationFieldOperationType;

#pragma mark - Field Operation Types
extern NSString *_Nonnull const kFieldOperationTypeValueApplication;
extern NSString *_Nonnull const kFieldOperationTypeValueHarvest;
extern NSString *_Nonnull const kFieldOperationTypeValueSeeding;
extern NSString *_Nonnull const kFieldOperationTypeValueTillage;

#pragma mark - Flags
extern NSString *_Nonnull const kFlagTypeFlag;
extern NSString *_Nonnull const kFlagTypeScout;

#pragma mark - GeoJSON Keys
extern NSString *_Nonnull const kGeoJSONKeyCoordinates;
extern NSString *_Nonnull const kGeoJSONKeyType;
extern NSString *_Nonnull const kGeoJSONKeyFeatures;
extern NSString *_Nonnull const kGeoJSONKeyGeometry;
extern NSString *_Nonnull const kGeoJSONKeyProperties;
extern NSString *_Nonnull const kGeoJSONKeyGeometryTypePoint;
extern NSString *_Nonnull const kGeoJSONKeyGeometryTypeLineString;
extern NSString *_Nonnull const kGeoJSONKeyGeometryTypePolygon;

#pragma mark - Relations
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationAuthor;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationClient;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationContributionDefinition;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationCreate;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationDelete;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationField;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationFlagCategory;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationImplement;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationJob;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationMachine;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationOperationPlan;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationOperator;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationOrganization;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationOwningOrganization;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationProduct;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationSelf;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationTargetResource;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationWorkAssignment;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationWorkOrder;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationWorkQuestion;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationPossibleWorkAnswer;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationTask;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationAddJob;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationAddField;
extern NSString *_Nonnull const kKeyObjectCommonLinksRelationAddMachine;

#pragma mark - URL Endpoints
extern NSString *_Nonnull const kJDEndpointAwsAssetLocationsAccessToken;
extern NSString *_Nonnull const kJDEndpointClients;
extern NSString *_Nonnull const kJDEndpointChemicals;
extern NSString *_Nonnull const kJDEndpointProductCompanies;
extern NSString *_Nonnull const kJDEndpointContributionDefinitions;
extern NSString *_Nonnull const kJDEndpointVarieties;
extern NSString *_Nonnull const kJDEndpointCropTypes;
extern NSString *_Nonnull const kJDEndpointField;
extern NSString *_Nonnull const kJDEndpointFields;
extern NSString *_Nonnull const kJDEndpointFieldOperations;
extern NSString *_Nonnull const kJDEndpointFileResources;
extern NSString *_Nonnull const kJDEndpointFiles;
extern NSString *_Nonnull const kJDEndpointFlagCategories;
extern NSString *_Nonnull const kJDEndpointFlagCategoryPreferences;
extern NSString *_Nonnull const kJDEndpointFlags;
extern NSString *_Nonnull const kJDEndpointForecast;
extern NSString *_Nonnull const kJDEndpointImplements;
extern NSString *_Nonnull const kJDEndpointJobOrderChange;
extern NSString *_Nonnull const kJDEndpointJobs;
extern NSString *_Nonnull const kJDEndpointStaff;
extern NSString *_Nonnull const kJDEndpointMachines;
extern NSString *_Nonnull const kJDEndpointMachineStylePreferences;
extern NSString *_Nonnull const kJDEndpointMapLayerSummaries;
extern NSString *_Nonnull const kJDEndpointMobileAccess;
extern NSString *_Nonnull const kJDEndpointNotes;
extern NSString *_Nonnull const kJDEndpointOrganizations;
extern NSString *_Nonnull const kJDEndpointPrescriptions;
extern NSString *_Nonnull const kJDEndpointPresignedUrl;
extern NSString *_Nonnull const kJDEndpointProducts;
extern NSString *_Nonnull const kJDEndpointReferenceCropId;
extern NSString *_Nonnull const kJDEndpointTasks;
extern NSString *_Nonnull const kJDEndpointTillageTypes;
extern NSString *_Nonnull const kJDEndpointToggles;
extern NSString *_Nonnull const kJDEndpointUsers;
extern NSString *_Nonnull const kJDEndpointVariableRepresentations;
extern NSString *_Nonnull const kJDEndpointWorkAnswers;
extern NSString *_Nonnull const kJDEndpointWorkAssignments;
extern NSString *_Nonnull const kJDEndpointWorkOrders;
extern NSString *_Nonnull const kJDEndpointWorkQuestions;
extern NSString *_Nonnull const kJDEndpointAccessPoints;
extern NSString *_Nonnull const kJDEndpointPossibleWorkAnswers;
extern NSString *_Nonnull const kJDEndpointLocations;
extern NSString *_Nonnull const kJDEndpointTask;

#pragma mark - URL Embed Keys
extern NSString *_Nonnull const kJDEmbedKeyActiveSimplifiedBoundary;
extern NSString *_Nonnull const kJDEmbedKeyAddresses;
extern NSString *_Nonnull const kJDEmbedKeyBoundaries;
extern NSString *_Nonnull const kJDEmbedKeyBreadcrumbs;
extern NSString *_Nonnull const kJDEmbedKeyClient;
extern NSString *_Nonnull const kJDEmbedKeyClients;
extern NSString *_Nonnull const kJDEmbedKeyContributionDefinition;
extern NSString *_Nonnull const kJDEmbedKeyContributionProduct;
extern NSString *_Nonnull const kJDEmbedKeyEquipmentIcon;
extern NSString *_Nonnull const kJDEmbedKeyEquipmentColor;
extern NSString *_Nonnull const kJDEmbedKeyFarm;
extern NSString *_Nonnull const kJDEmbedKeyFarms;
extern NSString *_Nonnull const kJDEmbedKeyField;
extern NSString *_Nonnull const kJDEmbedKeyFieldOperationMachines;
extern NSString *_Nonnull const kJDEmbedKeyFlagCategory;
extern NSString *_Nonnull const kJDEmbedKeyFlagCategoryWithPreferences;
extern NSString *_Nonnull const kJDEmbedKeyGuidanceLines;
extern NSString *_Nonnull const kJDEmbedKeyAccessPoints;
extern NSString *_Nonnull const kJDEmbedKeyImplements;
extern NSString *_Nonnull const kJDEmbedKeyJobNotes;
extern NSString *_Nonnull const kJDEmbedKeyLocation;
extern NSString *_Nonnull const kJDEmbedKeyLocations;
extern NSString *_Nonnull const kJDEmbedKeyMachine;
extern NSString *_Nonnull const kJDEmbedKeyMapLayers;
extern NSString *_Nonnull const kJDEmbedKeyMeasurementTotals;
extern NSString *_Nonnull const kJDEmbedKeyMeasurementTypes;
extern NSString *_Nonnull const kJDEmbedKeyOperations;
extern NSString *_Nonnull const kJDEmbedKeyPreferences;
extern NSString *_Nonnull const kJDEmbedKeySimplifiedBoundaries;
extern NSString *_Nonnull const kJDEmbedKeyUser;
extern NSString *_Nonnull const kJDEmbedKeyWorkAssignments;
extern NSString *_Nonnull const kJDEmbedKeyWorkOrders;
extern NSString *_Nonnull const kJDEmbedKeyWorkPlan;
extern NSString *_Nonnull const kJDEmbedKeyWorkQuestion;
extern NSString *_Nonnull const kJDEmbedKeyWorkQuestionAssignments;
extern NSString *_Nonnull const kJDEmbedKeyWorkRecords;
extern NSString *_Nonnull const kJDEmbedKeyWorkAnswers;
extern NSString *_Nonnull const kJDEmbedKeyTerminals;
extern NSString *_Nonnull const kJDEmbedKeyStatusUpdates;
extern NSString *_Nonnull const kJDEmbedKeyLastFieldOperation;

#pragma mark - URL additional parameter Keys
extern NSString *_Nonnull const kJDParamOrganizationId;
extern NSString *_Nonnull const kJDParamIncludeInactive;
extern NSString *_Nonnull const kJDParamLastKnown;
extern NSString *_Nonnull const kJDParamTrue;
extern NSString *_Nonnull const kJDParamFalse;
extern NSString *_Nonnull const kJDParamStartDate;
extern NSString *_Nonnull const kJDParamEndDate;
extern NSString *_Nonnull const kJDParamShapeTypes;
extern NSString *_Nonnull const kJDValueStatusAll;

#pragma mark - Header Params
extern NSString *_Nonnull const kJDHeaderParamLocation;

#pragma mark - API Format
extern NSString *_Nonnull const kDateFormatISO;
extern NSString *_Nonnull const kDateFormatISOZulu;

#pragma mark - URL Request Timeouts
extern NSTimeInterval const kJDSynchronizationTimeoutInterval;

#pragma mark - Retry-After delay
extern NSTimeInterval const kJDRetryDelay;

#pragma mark - Deprecated
extern NSString *_Nonnull const kSyncQueueUpdatedNotification DEPRECATED_ATTRIBUTE;

#pragma mark - Login error
extern NSUInteger const kJDLoginErrorNoInternetConnection;

#pragma mark - OAuth / Environment Settings (use JDServicesSetup to initialize)
extern NSString *_Nullable kConsumerKey;
extern NSString *_Nullable kConsumerSecretKey;
extern NSString *_Nullable kConsentToUseDataUri;
extern NSString *_Nullable kBaseURL;
extern NSString *_Nullable kAkanaBaseURL;
extern NSString *_Nullable kScopeUri;
extern NSString *_Nullable kKeychainGroupOAuth;

#pragma mark - Data Collection Measurements
static NSString *_Nonnull const kDataCollectionMeasurementsEventTimestampKey = @"eventTime";
static NSString *_Nonnull const kDataCollectionMeasurementsLatitudeKey = @"lat";
static NSString *_Nonnull const kDataCollectionMeasurementsLongitudeKey = @"lon";
static NSString *_Nonnull const kDataCollectionMeasurementsMeasurementsKey = @"measurements";
static NSString *_Nonnull const kDataCollectionMeasurementValueKey = @"value";
static NSString *_Nonnull const kDataCollectionMeasurementDomainTagKey = @"domainTag";
static NSString *_Nonnull const kDataCollectionMeasurementUnitOfMeasureKey = @"unitOfMeasure";
static NSString *_Nonnull const kDataCollectionMeasurementDomainIDKey = @"domainID";

#pragma mark - Notifications

/*
 * This notification gets posted on the main thread when the reachability for the currently selected environment
 * changes. If you change the environment the notification will be posted for reachability changes of the new
 * environment.
 * You will no longer receive notification for the old environment.
 * The userInfo dictionary of the notification contains the old and the new status represented by the
 * AFNetworkReachabilityStatus
 * enumeration.
 */
extern NSString *_Nonnull const JDEnvironmentReachabilityChangedNotification;

/*
 * UserInfo dictionary key for the old status of {@link JDEnvironmentReachabilityChangedNotification}. The value of this
 * key is NSNumber representing a AFNetworkReachabilityStatus.
 */
extern NSString *_Nonnull const kJDEnvironmentReachabilityChangedNotificationUserInfoKeyOldStatus;

/*
 * UserInfo dictionary key for the new status of {@link JDEnvironmentReachabilityChangedNotification}. The value of this
 * key is NSNumber representing a AFNetworkReachabilityStatus.
 */
extern NSString *_Nonnull const kJDEnvironmentReachabilityChangedNotificationUserInfoKeyNewStatus;

extern NSString *_Nonnull const kJDEnvironmentSelectionVcDidChangeEnvironment;

/**
 * @brief Constants for the MyJohnDeere API.
 */
@interface JDServicesConstants : NSObject

@end
