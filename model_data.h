#ifdef __WAND__
target[name[model_data.h]type[include]]
dependency[model_data.o]
#endif

#ifndef BIGCHUNKMODEL_MODELDATA_H
#define BIGCHUNKMODEL_MODELDATA_H

#include <herbs/array/array.h>

namespace Herbs
	{
	class StreamIn;
	}

namespace BigchunkModel
	{
	class ModelData
		{
		public:
			void load(Herbs::StreamIn& source);
			
			const float* verticesGet() const
				{return m_vertices.begin();}
				
			const float* normalsGet() const
				{return m_normals.begin();}
				
			const float* uvcoordsGet() const
				{return m_uvcoords.begin();}
			
			size_t nElementsGet() const
				{return m_vertices.length()/3;}
	
		private:
			Herbs::Array<float> m_vertices;
			Herbs::Array<float> m_normals;
			Herbs::Array<float> m_uvcoords;
		};
	}

#endif