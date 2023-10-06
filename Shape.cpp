
#include "Shape.h"

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string c){
	if(c == "red" || c == "green" || c == "blue")
		color = c;
	throw std::invalid_argument("Color no valido");
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if(c == "red" || c == "green" || c == "blue")
		color = c;
	throw std::invalid_argument("Color no valido");
}
