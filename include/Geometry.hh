#ifndef CPROJECT_DETGEOMETRY_HH
#define CPROJECT_DETGEOMETRY_HH

#include "G4SystemOfUnits.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include <G4RunManager.hh>
#include <G4GeometryManager.hh>
#include <G4UImanager.hh>
#include "G4VUserDetectorConstruction.hh"
//#include <G4Color.hh>
#include "G4VisAttributes.hh"
//#include <G4AssemblyVolume.hh>

#define SU *mm

class G4VPhysicalVolume;
class G4LogicalVolume;

//class GeomMes;

class Geometry  : public G4VUserDetectorConstruction
{
public:

    G4NistManager*              nist;
	virtual G4VPhysicalVolume *Construct();
    G4Material*                 world_mat;
    G4double                    world_size;
    G4Box*                      world_box;
    G4LogicalVolume*            world_log;    
    G4VPhysicalVolume*          world_pvpl;
	

	G4Box*						Polyetilen100_1, *Polyetilen3, *Polyetilen5, *Vakuum, *Polyetilen5u, *Polyetilen3u, *Polyetilen3uu, *dopSurf, *source;
	G4Tubs*						DE1_tubs, *stilben;
	G4LogicalVolume*			DE1_log, *LogPolyetilen100_1,*LogPolyetilen3, *LogPolyetilen5, *LogVakuum, *LogPolyetilen5u, *LogPolyetilen3u, *LogPolyetilen3uu, *LogDopSurf, *LogStilben, *LogSource;
	G4VPhysicalVolume*          DE1_pvpl, *PhPolyetilen100_1, *PhPolyetilen100_2, *PhPolyetilen3, *PhPolyetilen5, *PhPolyetilen5u, *PhPolyetilen3u, *PhPolyetilen3uu, *PhDopSurf, *PhStilben, *PhSource;
	G4ThreeVector				DE1_vect;


	G4Material*					DE_mat, *Poly3, *Poly5;
	G4Material*					Vakuum_mat;

    Geometry();
    virtual ~Geometry();

	//GeomMes* detMes;
	//void RefGeometry();
};

#endif //CPROJECT_DETGEOMETRY_HH
