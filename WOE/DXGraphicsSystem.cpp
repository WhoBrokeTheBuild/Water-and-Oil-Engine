#include "DXGraphicsSystem.h"

#include "GameTime.h"

DXGraphicsSystem::DXGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen /* = false */ )
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

void DXGraphicsSystem::update(const GameTime* pGameTime)
{

}

void DXGraphicsSystem::doResizeWindow(const int& width, const int& height)
{
}

void DXGraphicsSystem::doChangeFullscreen(const bool& fullscreen)
{
}

void DXGraphicsSystem::doChangeWindowTitle(const string& title)
{
}
