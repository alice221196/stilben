#include "Geometry.hh"
#include "G4SubtractionSolid.hh"

#define SU *mm

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
	G4Material* polyethilen = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
	G4Material* bor = nist->FindOrBuildMaterial("G4_B");
	Poly3 = new G4Material('PB3', 1.*g/cm3, 2);
	Poly3->AddMaterial(polyethilen, 0.97);
	Poly3->AddMaterial(bor, 0.03);

	Poly5 = new G4Material('PB5', 1.*g / cm3, 2);
	Poly5->AddMaterial(polyethilen, 0.95);
	Poly5->AddMaterial(bor, 0.05);

	G4Material* stil = nist->FindOrBuildMaterial("G4_STILBENE");


	Vakuum_mat = nist->FindOrBuildMaterial("G4_AIR");
	G4RotationMatrix* ZERO_RM = new G4RotationMatrix(0, 0, 0);

	
	//внешняя труба полиэтилена 3%бора
	Polyetilen3 = new G4Box('P3', 360 SU, 300 SU, 365 SU);
	Vakuum = new G4Box('V1', 280 SU, 310 SU, 275 SU);
	G4SubtractionSolid* sub1 = new G4SubtractionSolid('sub1', Polyetilen3, Vakuum);
	LogPolyetilen3 = new G4LogicalVolume(sub1, Poly3, 'P3L');
	G4VisAttributes CWhite = G4VisAttributes(G4Colour(1, 1, 1, 0.3));
	LogPolyetilen3->SetVisAttributes(CWhite);
	PhPolyetilen3 = new G4PVPlacement(ZERO_RM, { 0, 0, 0 }, LogPolyetilen3, 'PP3', world_log, 0, false, 0);
	//внутренняя труба полиэтилена бора 5% 
	Polyetilen5 = new G4Box('P5', 280 SU, 300 SU, 275 SU);
	G4Box* vak = new G4Box('V2', 200 SU, 310 SU, 195 SU);
	G4SubtractionSolid* sub2 = new G4SubtractionSolid('sub2', Polyetilen5, vak);
	LogPolyetilen5 = new G4LogicalVolume(sub2, Poly5, 'P5L');
	G4VisAttributes blue = G4VisAttributes(G4Colour(0, 0, 1, 0.4));
	LogPolyetilen5->SetVisAttributes(blue);
	PhPolyetilen5 = new G4PVPlacement(ZERO_RM, { 0, 0, 0 }, LogPolyetilen5, 'PP5', world_log, 0, false, 0);
	//блоки чистого полиэтилена
	Polyetilen100_1 = new G4Box('P1', 210 SU, 260 SU, 40 SU);
	LogPolyetilen100_1 = new G4LogicalVolume(Polyetilen100_1, polyethilen, 'P1L');
	G4VisAttributes Red = G4VisAttributes(G4Colour(1, 0, 0, 0.8));
	LogPolyetilen100_1->SetVisAttributes(Red);
	PhPolyetilen100_1 = new G4PVPlacement(ZERO_RM, {0, 40, 165 SU }, LogPolyetilen100_1, 'PP1', world_log, 0, false, 0);
	PhPolyetilen100_2 = new G4PVPlacement(ZERO_RM, { 0, 40, -165 SU }, LogPolyetilen100_1, 'PP1', world_log, 0, false, 0);
	//верхний блок полиэтилена бора 5%
	Polyetilen5u = new G4Box('PU1', 360 SU, 80 SU, 365 SU);
	LogPolyetilen5u = new G4LogicalVolume(Polyetilen5u, Poly5, 'PU5L');
	G4VisAttributes green = G4VisAttributes(G4Colour(0, 1, 0, 0.8));
	LogPolyetilen5u->SetVisAttributes(green);
	PhPolyetilen5u = new G4PVPlacement(ZERO_RM, { 0, 380, 0 SU }, LogPolyetilen5u, 'P5u', world_log, 0, false, 0);
	//нижний блок полиэтилена бора 3%
	Polyetilen3u = new G4Box('PU1', 360 SU, 40 SU, 365 SU);
	LogPolyetilen3u = new G4LogicalVolume(Polyetilen3u, Poly3, 'P1L');
	G4VisAttributes yellow = G4VisAttributes(G4Colour(1, 1, 0, 0.8));
	LogPolyetilen3u->SetVisAttributes(yellow);
	PhPolyetilen3u = new G4PVPlacement(ZERO_RM, { 0, -340, 0 SU }, LogPolyetilen3u, 'P3u', world_log, 0, false, 0);
	//маленький нижний блок полиэтилена бора 3%
	Polyetilen3uu = new G4Box('PU1', 200 SU, 40 SU, 205 SU);
	LogPolyetilen3uu = new G4LogicalVolume(Polyetilen3uu, Poly3, 'P1Lu');
	LogPolyetilen3uu->SetVisAttributes(yellow);
	PhPolyetilen3uu = new G4PVPlacement(ZERO_RM, { 0, -260, 0 SU }, LogPolyetilen3uu, 'P3uu', world_log, 0, false, 0);
	//доб пластина из полиэтилена 5% бора
	dopSurf = new G4Box('DS', 40 SU, 250 SU, 360 SU); 
	LogDopSurf = new G4LogicalVolume(dopSurf, Poly5, 'DL');
	G4VisAttributes surf = G4VisAttributes(G4Colour(0, 1, 1, 0.8));
	LogDopSurf->SetVisAttributes(surf);
	PhDopSurf =new G4PVPlacement(ZERO_RM, { 410 SU,0,0 }, LogDopSurf, 'PD1', world_log, 0, false, 0);
	//сцинтиллятор
	stilben = new G4Tubs('ST', 0, 20 SU, 20 SU,0, 360*deg);
	LogStilben = new G4LogicalVolume(stilben, stil, "ST_log");
	LogStilben->SetVisAttributes(CWhite);
	G4RotationMatrix*  rot = new G4RotationMatrix(CLHEP::HepRotationX(90 * deg));
	PhStilben = new G4PVPlacement(rot, { 0,-158 SU,0 }, LogStilben, 'ST', world_log, 0, false, 0);
	//оболочка источник
	


	//DE1_tubs = new G4Tubs("DE1", 0, 30 SU, 30 SU, 0, 360*deg);
	//DE1_log = new G4LogicalVolume(DE1_tubs, DE_mat, "DE_log");
	//DE1_vect = G4ThreeVector(0, 0, 0);
	
	//DE1_pvpl = new G4PVPlacement(ZERO_RM, DE1_vect, DE1_log, "DetEl_pvpl", world_log, 0, false, 0);
	
	
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
