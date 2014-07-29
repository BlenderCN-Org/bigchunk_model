#ifdef __WAND__
target[name[bigchunk_model-test.exe] type[application] platform[;Windows]]
#endif

#include "model_data.h"
#include <herbs/include_binary/include_binary.h>
#include <herbs/memoryin/memoryin.h>
#include <herbs/main/main.h>

INCLUDE_BINARY(cube,"cube.bmo");

int MAIN(int argc,charsys_t* argv[])
	{
	Herbs::MemoryIn source(cube_begin,cube_end-cube_begin);
	
	BigchunkModel::ModelData data;
	data.load(source);
	
	auto vertices=data.verticesGet();
	
	for(size_t k=0;k<data.nElementsGet();++k)
		{
		printf("%.7g %.7g %.7g\n",*vertices,*(vertices+1),*(vertices+2));
		vertices+=3;
		}
	
	return 0;
	}