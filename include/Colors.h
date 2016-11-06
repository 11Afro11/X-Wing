#ifndef COLORS_
#define COLORS_

class Colors{
private:
	std::vector<std::vector<GLfloat> > colores;
public:
	Colors(){
		colores.push_back({1.0, 0.0, 0.0});// red, duh
		colores.push_back({0.0, 1.0, 0.0});// green, duh
		colores.push_back({0.0, 0.0, 1.0});// blue, duh
		colores.push_back({1.0, 1.0, 0.0});// yellow
		colores.push_back({1.0, 0.0, 1.0});// purple
		colores.push_back({0.0, 1.0, 1.0});// cyan

		colores.push_back({1.0, 0.5, 0.0});// orang0
		colores.push_back({0.5, 1.0, 0.0});// greenish yellow
		colores.push_back({0.5, 1.0, 0.5});// light green
		colores.push_back({0.0, 0.5, 0.0});// dark green

	}

	Colors & operator = (const Colors & otro){
		colores.clear();
		for(int i = 0; i < otro.colores.size(); i++){
			colores.push_back(otro.colores[i]);
		}
	}

	GLfloat & operator () (int i, int j){
		return colores[i][j];
	}

	int Tam(){
		return colores.size();
	}

};
#endif
