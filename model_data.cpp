#ifdef __WAND__
target[name[model_data.o] type[object]]
#endif

#include "model_data.h"
#include <bigchunk/reader.h>
#include <herbs/stringbase/stringbase.h>
#include <herbs/exceptionmissing/exceptionmissing.h>

void BigchunkModel::ModelData::load(Herbs::StreamIn& source)
	{
	Bigchunk::Reader reader(source);
	
	Herbs::Stringbase<char> header_name(8);
	size_t status=0;
	while(reader.headerRead(header_name))
		{
		if(header_name=="MODELMET")
			{
			status|=1;
			break;
			}
		reader.skip();
		}

	if(!(status&1))
		{throw Herbs::ExceptionMissing(___FILE__,__LINE__);}

	size_t n_frames=0;
	while(reader.headerRead(header_name))
		{	
		if(header_name=="FRAME")
			{
			if(n_frames==1)
				{return;}
			++n_frames;
			}
		if(n_frames)
			{
			if(header_name=="VERTICES")
				{				
				uint32_t n;
				reader.dataRead(&n,sizeof(n));
				m_vertices.lengthValidSet(3*n);
				reader.dataRead(m_vertices.begin(),sizeof(float)*3*n);
				}
			if(header_name=="NORMALS")
				{				
				uint32_t n;
				reader.dataRead(&n,sizeof(n));
				m_normals.lengthValidSet(3*n);
				reader.dataRead(m_normals.begin(),sizeof(float)*3*n);
				}
			if(header_name=="UVCOORDS")
				{
				uint32_t n;
				reader.dataRead(&n,sizeof(n));
				m_uvcoords.lengthValidSet(2*n);
				reader.dataRead(m_uvcoords.begin(),sizeof(float)*2*n);
				}
			}
		reader.skip();
		}

	
	}