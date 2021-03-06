#ifndef TkNavigation_SimpleNavigationSchool_H
#define TkNavigation_SimpleNavigationSchool_H

#include "TrackingTools/DetLayers/interface/NavigationSchool.h"
#include "RecoTracker/TkDetLayers/interface/GeometricSearchTracker.h"

#include <vector>

class DetLayer;
class BarrelDetLayer;
class ForwardDetLayer;
class SymmetricLayerFinder;
class SimpleBarrelNavigableLayer;
class SimpleForwardNavigableLayer;
class MagneticField;

/** Concrete navigation school for the Tracker
 */

class dso_hidden SimpleNavigationSchool : public NavigationSchool {
public:
  
  SimpleNavigationSchool() : theField(0),theTracker(0){};
  SimpleNavigationSchool(const GeometricSearchTracker* theTracker,
			 const MagneticField* field);
  ~SimpleNavigationSchool(){cleanMemory();}

  // from base class
  virtual StateType navigableLayers() override;

protected:

  typedef std::vector<const DetLayer*>              DLC;
  typedef std::vector<const BarrelDetLayer*>        BDLC;
  typedef std::vector<const ForwardDetLayer*>       FDLC;
  typedef DLC::iterator                        DLI;
  typedef BDLC::iterator                       BDLI;
  typedef FDLC::iterator                       FDLI;
  typedef BDLC::const_iterator                 ConstBDLI;
  typedef FDLC::const_iterator                 ConstFDLI;
 
  BDLC theBarrelLayers;
  FDLC theForwardLayers;  
  FDLC theRightLayers;
  FDLC theLeftLayers;
  float theBarrelLength;

  typedef std::vector< SimpleBarrelNavigableLayer*>   BNLCType;
  typedef std::vector< SimpleForwardNavigableLayer*>  FNLCType;
  BNLCType  theBarrelNLC;
  FNLCType  theForwardNLC;

  virtual void linkBarrelLayers( SymmetricLayerFinder& symFinder);
  virtual void linkForwardLayers( SymmetricLayerFinder& symFinder);

  virtual void linkNextForwardLayer( BarrelDetLayer const*, FDLC&);

  virtual void linkNextLargerLayer( BDLI, BDLI, BDLC&);

  virtual void linkNextBarrelLayer( ForwardDetLayer const* fl, BDLC&);

  virtual void linkOuterGroup( ForwardDetLayer const* fl,
		       const FDLC& group,
		       FDLC& reachableFL);

  virtual void linkWithinGroup( FDLI fl, const FDLC& group, FDLC& reachableFL);
  
  virtual ConstFDLI outerRadiusIncrease( FDLI fl, const FDLC& group);

  virtual std::vector<FDLC> splitForwardLayers();

  virtual float barrelLength();

  virtual void establishInverseRelations();

  virtual void linkNextLayerInGroup( FDLI fli, const FDLC& group, FDLC& reachableFL);

  const MagneticField* theField;
  const GeometricSearchTracker* theTracker;

  void cleanMemory();
};

#endif // SimpleNavigationSchool_H
