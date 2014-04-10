#ifndef WOE_BASE_TEXTURE_H
#define WOE_BASE_TEXTURE_H

#include <Arc/ManagedObject.h>

using Arc::ManagedObject;

class BaseTexture
	: public ManagedObject
{
public:

	BaseTexture( const string& filename )
	{
		loadFile(filename);
	}

	virtual bool loadFile( const string& filename ) = 0;

	virtual inline bool isLoaded( void ) const { return m_Loaded; }

	virtual inline unsigned int getHeight( void ) const { return m_Height; }
	virtual inline unsigned int getWidth( void ) const { return m_Width; }

protected:

	BaseTexture( const unsigned int& width, const unsigned int& height, const string& filename )
		: m_Width(width),
		  m_Height(height),
		  m_Filename(filename)
	{ }

	unsigned int		m_Width, m_Height;

	string				m_Filename;

	bool				m_Loaded;
};

#endif // WOE_BASE_TEXTURE_H