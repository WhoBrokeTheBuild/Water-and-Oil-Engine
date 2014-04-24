#version 140

#pragma optionNV(fastmath on)
#pragma optionNV(ifcvt none)
#pragma optionNV(inline all)
#pragma optionNV(strict on)
#pragma optionNV(unroll all)

in vec4 pos;

void main() {
    vec4 temp = pos;
    gl_Position = temp * vec4(1,-1,2,1) - vec4(0,0,temp.w,0);
}
