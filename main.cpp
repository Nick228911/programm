#include <iostream>
#include <math.h>

using namespace std;

//////////////11111111111111111111/////////////////////////////////////////////////
class point {
public:
    float x;
    float y;

//    конструктор
    point(float x1 = 0, float y1 = 0)
            : x(x1), y(y1) {}

//     конструктор копирования
    point(const point &copoint)
            : x(copoint.x), y(copoint.y) {}

//     деконструктор
    ~point() {}

//    оператор присваивания
    point &operator=(const point &other) {
        if (&other == this) {
            return *this;
        }
        this->x = other.x;
        this->y = other.y;

        return *this;
    }

//    geter
    float x_() const {
        return x;
    }

    float y_() const {
        return y;
    }

};

//////////////////2222222222222222222222222222////////////////////////////////
class broken {
private:
    point *coordins;
    int size;
    float lenght = 0;
public:
//    конструктор
    broken(int size1 = 1)
            : size(size1) {
        this->coordins = new point[size];
        for (int i = 0; i < size; i++) {
            coordins[i].x = 0;
            coordins[i].y = 0;
        }
    }

//    конструктор копирования
    broken(const broken &other) {
        this->size = other.size;
        this->coordins = new point[other.size];
        this->lenght = other.lenght;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    broken &operator=(const broken &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

//    деконструктор
    ~broken() {
        delete[] coordins;
    }

//    вовод
    void c_cin() {
        for (int i = 0; i < size; i++) {
            cout << "x(" << (i + 1) << ") =";
            cin >> coordins[i].x;
            cout << "y(" << (i + 1) << ") =";
            cin >> coordins[i].y;
            cout << "\n";
        }
    }

//    нахождение длины ломаной
    void s_lenght() {
        for (int i = 1; i < size; i++) {
            this->lenght += sqrt(
                    pow((coordins[i].x - coordins[i - 1].x), 2) + pow((coordins[i].y - coordins[i - 1].y), 2));
        }
    }

    float get_lenght() const {
        return lenght;
    }

};

////////////////////////33333333333333////замкнутая ломанная\\\\\\333333333333333/////////////////////////////////////////////
class closed_broken {
protected:
    point *coordins;
    int size;
    float lenght = 0;
public:
//    конструктор
    closed_broken(int size1 = 1)
            : size(size1) {
        this->coordins = new point[size];
        for (int i = 0; i < size; i++) {
            coordins[i].x = 0;
            coordins[i].y = 0;
        }
    }

//    конструктор копирования
    closed_broken(const closed_broken &other) {
        this->size = other.size;
        this->lenght = other.lenght;
        this->coordins = new point[other.size];
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    closed_broken &operator=(const closed_broken &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

//    нахождение длины ломаной
    void s_lenght() {
        for (int i = 1; i < size; i++) {
            this->lenght += sqrt(
                    pow((coordins[i].x - coordins[i - 1].x), 2) + pow((coordins[i].y - coordins[i - 1].y), 2));
        }
        this->lenght += sqrt(
                pow((coordins[size - 1].x - coordins[0].x), 2) + pow((coordins[size - 1].y - coordins[0].y), 2));
//        return *lenght;
    }

//    деконструктор
    ~closed_broken() {
        delete[] coordins;
    }

//    вовод
    void c_cin() {
        for (int i = 0; i < size; i++) {
            cout << "x(" << (i + 1) << ") =";
            cin >> coordins[i].x;
            cout << "y(" << (i + 1) << ") =";
            cin >> coordins[i].y;
            cout << "\n";
        }
    }

    float get_lenght() const {
        return lenght;
    }


};

///////////////444444444//////многоугольник\\\\\\\\44444444444444////////////////////////////////////////////
class polygon {
protected:
    point *coordins;
    int size;
    float lenght = 0;
    float sq = 0;
public:
//    конструктор
    polygon(int size1 = 1)
            : size(size1), lenght(lenght) {
        this->coordins = new point[size];
        for (int i = 0; i < size; i++) {
            coordins[i].x = 0;
            coordins[i].y = 0;
        }
    }

//    конструктор копирования
    polygon(const polygon &other) {
        this->size = other.size;
        this->lenght = other.lenght;
        this->coordins = new point[other.size];
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    polygon &operator=(const polygon &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

//    нахождение длины многоугольника
    void s_lenght() {
        for (int i = 1; i < size; i++) {
            this->lenght += sqrt(
                    pow((coordins[i].x - coordins[i - 1].x), 2) + pow((coordins[i].y - coordins[i - 1].y), 2));
        }
        this->lenght += sqrt(
                pow((coordins[size - 1].x - coordins[0].x), 2) + pow((coordins[size - 1].y - coordins[0].y), 2));
//        return *lenght;
    }

//    нахождение площади многоугольника
    void s_sq() {
        for (int i = 1; i < size; i++) {
            this->sq += abs((coordins[i - 1].x * coordins[i].y) - (coordins[i].x * coordins[i - 1].y));
        }
        this->sq += abs((coordins[size - 1].x * coordins[0].y) - (coordins[0].x * coordins[size - 1].y));
        this->sq = 0.5 * sq;
    }

//    деконструктор
    ~polygon() {
        delete[] coordins;
    }

//    вовод
    void c_cin() {
        for (int i = 0; i < size; i++) {
            cout << "x(" << (i + 1) << ") =";
            cin >> coordins[i].x;
            cout << "y(" << (i + 1) << ") =";
            cin >> coordins[i].y;
            cout << "\n";
        }
    }


    float get_lenght() const {
        return lenght;
    }

    float get_sq() const {
        return sq;
    }

};
////////////////555555555555555/////треугольник\\\\\\\55555555555555555/////////////////////////////////////////////////////

class triangle : public polygon {
private:
//    point *coordins;
//    int size = 3;
//    float lenght = 0;
//    float sq = 0;
public:
//    конструктор
    triangle()
            : polygon(3) {}

//    конструктор копирования
    triangle(const triangle &other) {
        this->size = other.size;
        this->lenght = other.lenght;
        this->coordins = new point[other.size];
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    triangle &operator=(const triangle &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

//    деконструктор
    ~triangle() {
        delete[] coordins;
    }

};


////////66666////трапеция\\\\\66666666666666666/////////////////////////////////////////////////////
class trapeze : polygon {
public:
    trapeze()
            : polygon(4) {}

    //    конструктор копирования
    trapeze(const trapeze &other) {
        this->size = other.size;
        this->lenght = other.lenght;
        this->coordins = new point[other.size];
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    trapeze &operator=(const trapeze &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

    //    деконструктор
    ~trapeze() {
        delete[] coordins;
    }



};



///////////777777/////правильный_многоугольник\\\\\77777777777777777777777777777//////////////////////////////////////////

class regular_polygon : polygon{
public:
    regular_polygon(int size1)
            : polygon(size1) {}

    //    конструктор копирования
    regular_polygon(const regular_polygon &other) {
        this->size = other.size;
        this->lenght = other.lenght;
        this->coordins = new point[other.size];
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
    }

//    оператор присваивания;
    regular_polygon &operator=(const regular_polygon &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        this->lenght = other.lenght;
        delete[] this->coordins;
        for (int i = 0; i < other.size; i++) {
            this->coordins[i] = other.coordins[i];
        }
        return *this;
    }

    //    деконструктор
    ~regular_polygon() {
        delete[] coordins;
    }


};



/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

int main() {
    float perimetr;
//    point A{5, 4};
//    A.x = 4;
//    A.x = 5;
//    point B(A);
//    cout << B.x << " " << B.y;
//    point dd;
//    dd.input();

    triangle ABC;
    ABC.c_cin();
    ABC.s_sq();
    perimetr = ABC.get_sq();
    cout << perimetr;
    return 0;
}
