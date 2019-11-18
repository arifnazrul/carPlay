//
//  JDDataCollectionMeasurement.h
//  JDServices
//
//  Created by Gillispie Leah on 10/5/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDJsonObject.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, JDDataCollectionMeasurementDomainTag) {
    JDDataCollectionMeasurementDomainTagHarvestMoisture = 6,
    JDDataCollectionMeasurementDomainTagYieldBalePerArea = 35,
    JDDataCollectionMeasurementDomainTagYieldWetMass = 36,
    JDDataCollectionMeasurementDomainTagYieldWetMassPerArea = 37,
    JDDataCollectionMeasurementDomainTagYieldWetVolume = 38,
    JDDataCollectionMeasurementDomainTagYieldWetVolumePerArea = 39,
    JDDataCollectionMeasurementDomainTagYieldMassPerArea = 41,
    JDDataCollectionMeasurementDomainTagYieldVolumePerArea = 43,
    JDDataCollectionMeasurementDomainTagAppRateMassMetered = 44,
    JDDataCollectionMeasurementDomainTagAppRateMassMeasured = 45,
    JDDataCollectionMeasurementDomainTagAppRateMassControl = 46,
    JDDataCollectionMeasurementDomainTagAppRateMassTarget = 47,
    JDDataCollectionMeasurementDomainTagAppRateVolumeMetered = 48,
    JDDataCollectionMeasurementDomainTagAppRateVolumeMeasured = 49,
    JDDataCollectionMeasurementDomainTagAppRateVolumeControl = 50,
    JDDataCollectionMeasurementDomainTagAppRateVolumeTarget = 51,
    JDDataCollectionMeasurementDomainTagAppHeightTarget = 52,
    JDDataCollectionMeasurementDomainTagTillageDepthTarget = 53,
    JDDataCollectionMeasurementDomainTagSeedRateMassMetered = 54,
    JDDataCollectionMeasurementDomainTagSeedRateMassMeasured = 55,
    JDDataCollectionMeasurementDomainTagSeedRateMassControl = 56,
    JDDataCollectionMeasurementDomainTagSeedRateMassTarget = 57,
    JDDataCollectionMeasurementDomainTagSeedRateSeedsMetered = 58,
    JDDataCollectionMeasurementDomainTagSeedRateSeedsMeasured = 59,
    JDDataCollectionMeasurementDomainTagSeedRateSeedsControl = 60,
    JDDataCollectionMeasurementDomainTagSeedRateSeedsTarget = 61,
    JDDataCollectionMeasurementDomainTagSeedDepthTarget = 62,
    JDDataCollectionMeasurementDomainTagRelativeHumidity = 63,
    JDDataCollectionMeasurementDomainTagAirTemperature = 64,
    JDDataCollectionMeasurementDomainTagWindSpeed = 65,
    JDDataCollectionMeasurementDomainTagSoilTemperature = 66,
    JDDataCollectionMeasurementDomainTagTotalAreaCovered = 67,
    JDDataCollectionMeasurementDomainTagTotalQuantityAppliedVolume = 69,
    JDDataCollectionMeasurementDomainTagElevation = 74,
    JDDataCollectionMeasurementDomainTagVehicleSpeed = 81,
    JDDataCollectionMeasurementDomainTagFuelRatePerHour = 99,
    JDDataCollectionMeasurementDomainTagAreaProductivity = 133,
    JDDataCollectionMeasurementDomainTagVolumeProductivity = 135,
    JDDataCollectionMeasurementDomainTagInoculantDosing = 145,
    JDDataCollectionMeasurementDomainTagLengthOfCut = 146,
    JDDataCollectionMeasurementDomainTagYieldWetMassFrgPerArea = 182,
    JDDataCollectionMeasurementDomainTagYieldMassFrgPerArea = 183,
    JDDataCollectionMeasurementDomainTagDownForceMargin = 287,
    JDDataCollectionMeasurementDomainTagDeltaT = 308,
    JDDataCollectionMeasurementDomainTagConstituentCrudeProtein = 310,
    JDDataCollectionMeasurementDomainTagConstituentStarch = 311,
    JDDataCollectionMeasurementDomainTagConstituentAcidDetergentFiber = 312,
    JDDataCollectionMeasurementDomainTagConstituentNeutralDetergentFiber = 313,
    JDDataCollectionMeasurementDomainTagConstituentSugar = 314,
    JDDataCollectionMeasurementDomainTagTillageDepthMeasured = 363,
    JDDataCollectionMeasurementDomainTagTillageDepthControl = 364,
    JDDataCollectionMeasurementDomainTagTillagePressureTarget = 368,
    JDDataCollectionMeasurementDomainTagTillagePressureMeasured = 369,
    JDDataCollectionMeasurementDomainTagActualSeedSpacingCV = 376,
    JDDataCollectionMeasurementDomainTagDownForceApplied = 380,
    JDDataCollectionMeasurementDomainTagGroundContact = 381,
    JDDataCollectionMeasurementDomainTagRideQuality = 382,
    JDDataCollectionMeasurementDomainTagTillagePressureControl = 383,
    JDDataCollectionMeasurementDomainTagHarvestTrash = 384,
    JDDataCollectionMeasurementDomainTagYieldRawMassCanePerArea = 388,
    JDDataCollectionMeasurementDomainTagYieldRawMassPerArea = 392,
    JDDataCollectionMeasurementDomainTagYieldNetMassPerArea = 394,
    JDDataCollectionMeasurementDomainTagHarvestWetMassFlow = 510,
    JDDataCollectionMeasurementDomainTagFanSpeedTarget = 515,
    JDDataCollectionMeasurementDomainTagFanSpeedMeasured = 516,
    JDDataCollectionMeasurementDomainTagThreshingSpeedTarget = 518,
    JDDataCollectionMeasurementDomainTagThreshingSpeedMeasured = 519,
    JDDataCollectionMeasurementDomainTagThreshingClearanceTarget = 521,
    JDDataCollectionMeasurementDomainTagThreshingClearanceMeasured = 522,
    JDDataCollectionMeasurementDomainTagChafferPositionTarget = 524,
    JDDataCollectionMeasurementDomainTagChafferPositionMeasured = 525,
    JDDataCollectionMeasurementDomainTagSievePositionTarget = 527,
    JDDataCollectionMeasurementDomainTagSievePositionMeasured = 528,
    JDDataCollectionMeasurementDomainTagWheelSpeed = 560,
    JDDataCollectionMeasurementDomainTagMachineSelectedSpeed = 565,
    JDDataCollectionMeasurementDomainTagThreshingClearance = 579,
    JDDataCollectionMeasurementDomainTagChafferPosition = 580,
    JDDataCollectionMeasurementDomainTagSievePosition = 581,
    JDDataCollectionMeasurementDomainTagCalculatedElementSpeed = 649,
    JDDataCollectionMeasurementDomainTagApplicationMethod = 1001,
    JDDataCollectionMeasurementDomainTagTotalGrainLoss = 2118,
    JDDataCollectionMeasurementDomainTagGrainThroughputScore = 2126,
    JDDataCollectionMeasurementDomainTagShoeGrainSavingsScore = 2136,
    JDDataCollectionMeasurementDomainTagSeparatorGrainSavingsScore = 2137,
    JDDataCollectionMeasurementDomainTagAverageGrainThroughputScore = 2138,
    JDDataCollectionMeasurementDomainTagGrainSavingsScore = 2144,
    JDDataCollectionMeasurementDomainTagAverageGrainSavingsScore = 2145
};

@interface JDDataCollectionMeasurement : JDAPIBaseObject

@property(nonatomic, nullable) NSDecimalNumber *value;

@property(nonatomic, nullable) NSString *domainTag;

@property(nonatomic, nullable) NSString *unitOfMeasure;

@property(nonatomic, nullable) NSString *domainID;

- (instancetype _Nonnull)initWithValue:(NSDecimalNumber *_Nullable)value
                          andDomainTag:(NSString *_Nullable)domainTag
                      andUnitOfMeasure:(NSString *_Nullable)unitOfMeasure
                           andDomainID:(NSString *_Nullable)domainID;

@end
