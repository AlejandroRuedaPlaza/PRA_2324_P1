#include "Rectangle.h"

//Rectangle::Rectangle(): vs{Point2D(-1,0.5), Point2D(1,0.5), Point2D(1, -0.5), Point2D(-1, -0.5)}{
	//vs={Point2D(-1,0.5), Point2D(1,0.5), Point2D(1, -0.5), Point2D(-1, -0.5)};
Rectangle::Rectangle(){
	vs[0] = Point2D(-1,0.5);
	vs[1] = Point2D(1,0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}


Rectangle::Rectangle(std::string color, Point2D* vertices){
	set_color(color);
	vs = vertices;		
}

Rectangle::Rectangle(const Rectangle &r){
	for(int i=0; i < N_VERTICES ; i++){
		vs[i] = r[i];
	}
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind >= 0 && ind < N_VERTICES){
		return vs[ind];
	}
	throw std::out_of_range("Error get vertex");
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

void set_vertices(Point2D* vetices){
	//TODO
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	this->vs = r.vs;
	set_color(r.color);
	return *this;  
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "HOLA";//TODO
	return out;
}

double Rectangle::area() const{
	//TODO
	return 0;
}

double Rectangle::perimeter() const{
	//TODO
	return 0;
}

void Rectangle::translate(double incX, double incY){
	//TODO
}

void Rectangle::print(){
	std::cout << this;
}
