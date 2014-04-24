#version 140

#pragma optionNV(fastmath on)
#pragma optionNV(ifcvt none)
#pragma optionNV(inline all)
#pragma optionNV(strict on)
#pragma optionNV(unroll all)

out vec4 color;

void main() {
	color = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}
