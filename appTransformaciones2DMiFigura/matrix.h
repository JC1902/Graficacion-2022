#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
//class matrix
//{
//public:
  //  matrix();
//};

//#endif // MATRIX_H
class Matrix
{

    int col, ren;
    float **Mat;

    public:

       Matrix(int nr=4,int nc=4, float valor=0);//constructor con arg. por defecto

       Matrix(float nr,float nc, float **m);

       Matrix(Matrix &);//constructor de copia
       ~Matrix();//destructor
       inline void SET(int R, int C, float val){Mat[R][C]=val;}
       float GET(int R, int C){return Mat[R][C];}
       int numCol(){return col;}
       int numRen(){return ren;}
       void Inicializa(int, int);
       double conversion(double);
       Matrix &operator *=(Matrix &mat2);

       Matrix &operator*(const Matrix &m1);

       Matrix operator*(float);//Multiplicar por un escalar

       Matrix &operator=(Matrix &m);

       Matrix & asignar(Matrix);

       Matrix & Identidad();// PERMITE INICIALIZAR LA MATRIZ BASE

       //TRANSFORMACIONES
        //FigTrans                      Fig        Id          tX   tY
        Matrix &Traslacion( Matrix, Matrix, int, int );

        Matrix &Escalacion(Matrix, Matrix, float, float);

        Matrix &EscalacionPF(Matrix, Matrix, int, int, float , float);

        Matrix &Rotacion(Matrix, Matrix, int);

        Matrix &Rotacion2(Matrix, Matrix, int);

        Matrix &RotacionPF(Matrix, Matrix, double, double, double);

        Matrix &RotacionPF2(Matrix, Matrix, double, double, double);
};

#endif // MATRIX_H
