#include "DXGraphicsSystem.h"

#include "GameTime.h"

DXGraphicsSystem::DXGraphicsSystem( int width, int height, string title, bool fullscreen /* = false */ )
	: BaseGraphicsSystem(width, height, title, fullscreen)
{

}

DXGraphicsSystem::~DXGraphicsSystem(void)
{
}

void DXGraphicsSystem::beginRender( void )
{
}

void DXGraphicsSystem::endRender( void )
{
}

void DXGraphicsSystem::doResizeWindow( void )
{
}

void DXGraphicsSystem::update(const GameTime* pGameTime)
{

}
