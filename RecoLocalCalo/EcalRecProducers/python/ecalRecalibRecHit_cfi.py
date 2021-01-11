import FWCore.ParameterSet.Config as cms

# re-calibrated rechit producer
ecalRecalibRecHit = cms.EDProducer("EcalRecalibRecHitProducer",
    EERecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
    EBRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
    EBRecalibRecHitCollection = cms.string('EcalRecHitsEB'),
    EERecalibRecHitCollection = cms.string('EcalRecHitsEE'),
    doEnergyScale = cms.bool(False),
    doEnergyScaleInverse = cms.bool(False),
    doIntercalib = cms.bool(False),
    doIntercalibInverse = cms.bool(False),
    doLaserCorrections = cms.bool(False),
    doLaserCorrectionsInverse = cms.bool(False),
    doTimeCalib = cms.bool(False),
    doTimeCalibInverse = cms.bool(False)
)
