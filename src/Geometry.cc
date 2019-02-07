#include "Geometry.hh"

//#define SU *mm

Geometry::Geometry() {
    //detMes = new GeomMes(this);
}

Geometry::~Geometry() {}

G4VPhysicalVolume* Geometry::Construct(){
	
	G4GeometryManager::GetInstance()->OpenGeometry();
	G4PhysicalVolumeStore::GetInstance()->Clean(); 
	G4LogicalVolumeStore::GetInstance()->Clean();
	G4SolidStore::GetInstance()->Clean();

	// Параметры мира
	world_size = 5000 SU;
	nist = G4NistManager::Instance();
	world_mat = nist->FindOrBuildMaterial("G4_AIR");
	world_box = new G4Box("world_box", world_size, world_size, world_size);
	world_log = new G4LogicalVolume(world_box, world_mat, "world_log");
	world_pvpl = new G4PVPlacement(0, G4ThreeVector(), world_log, "world_pvpl", 0, false, 0);

 	DE_mat = nist->FindOrBuildMaterial("G4_GLASS_PLATE"); 	
	DE1_tubs = new G4Tubs("DE1", 0, 30 SU, 30 SU, 0, 360*deg);
	DE1_log = new G4LogicalVolume(DE1_tubs, DE_mat, "DE_log");
	DE1_vect = G4ThreeVector(0, 0, 0);
	G4RotationMatrix* ZERO_RM = new G4RotationMatrix(0, 0, 0);
	DE1_pvpl = new G4PVPlacement(ZERO_RM, DE1_vect, DE1_log, "DetEl_pvpl", world_log, 0, false, 0);
	
	G4VisAttributes* CWhite = new G4VisAttributes(G4Colour::G4Colour(1, 1, 1, 0.3));
	DE1_log->SetVisAttributes(CWhite);
	
    return new G4PVPlacement(0, G4ThreeVector(), world_log, "world_pvpl", 0, false, 0);
}

// Функция перерисовки геометрии
/*
void Geometry::RefGeometry() {
	G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
	G4RunManager::GetRunManager()->ReinitializeGeometry();
	G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");
}
*/
//GeomMes::~GeomMes(){}