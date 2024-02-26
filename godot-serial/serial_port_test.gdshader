shader_type canvas_item;
global uniform vec4 color;
void vertex() {}

void fragment() {
	COLOR = vec4(color.r, color.g, color.b, color.a);
}


