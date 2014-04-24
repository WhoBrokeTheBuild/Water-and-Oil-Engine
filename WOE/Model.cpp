#include "Model.h"

void Model::render(void)
{
	for (auto it = m_Meshes.itBegin(); it != m_Meshes.itEnd(); ++it)
	{
		Mesh* pMesh = (*it);
		pMesh->render();
	}
}
