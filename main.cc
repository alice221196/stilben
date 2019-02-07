#include <Loader.hh>
#include <DataWriter.hh>

int main(int argc, char** argv) {

	OutFile::Open();
	
    Loader* loader = new Loader(argc,argv);
    delete loader;
	
	OutFile::Close();

	//system("pause");
    return 0;
}