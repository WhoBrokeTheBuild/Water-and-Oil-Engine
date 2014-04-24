#ifndef WOE_SHADER_INFO_H
#define WOE_SHADER_INFO_H

#include <string>
#include "ShaderTypes.h"

using std::string;

struct ShaderInfo
{
public:

	inline ShaderInfo( const string& filename, const ShaderTypes& type )
		: Filename(filename),
		  Type(type)
	{ }

	string Filename;
	ShaderTypes Type;

};

#endif // WOE_SHADER_INFO_H