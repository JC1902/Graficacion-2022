#include "matrix.h"
#include <math.h>
#include <assert.h>

Matrix::Matrix(int nr,int nc, float valor)
{
  ren = nr;
  col = nc;
  Mat = new float*[ren];
  assert(Mat);
  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col];
      assert(Mat[i]);
  }

  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = valor;
}

Matrix::Matrix(float nr,float nc, float **m)
{
  ren = nr;
  col = nc;
  Mat = new float*[ren];
  assert(Mat);
  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col];
      assert(Mat[i]);
  }

  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = m[i][j];
}


//CONSTRUCTOR DE COPIA

Matrix::Matrix(Matrix &m)
{
   this->ren=m.numRen();
   this->col=m.numCol();
   Mat =new float*[ren];
   for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }
   for(int i=0; i<ren; i++)
      for( int j=0; j<col; j++)
         Mat[i][j]=m.GET(i,j);
}

void Matrix::Inicializa(int R, int C)
{
   col=C;
   ren=R;
   Mat=new float *[ren];
   for(int i=0; i<ren; i++)
      Mat[i]=new float[col];
   for(int i=0; i<ren; i++)
      for(int j=0; j<col; j++)
          Mat[i][j]=0;
}

double Matrix::conversion(double angulo)
{
    double AnG = (angulo * M_PI)/180.0;

    return AnG;
}

Matrix &Matrix::operator*=(Matrix &mat2)
{
   Matrix aux;
   aux.Inicializa(ren, mat2.numCol());


   for(int i=0; i<ren; i++)
   {
      for(int j=0; j<mat2.numCol(); j++)
      {
         float suma=0;
        // Mat[i][j]=0;
         for(int k=0; k<col; k++)
         {
           suma+=floor(Mat[i][k]*mat2.GET(k,j)+0.5);
           aux.SET(i,j,suma);
         }
         //aux.SET(i,j,suma);
      }
   }
   asignar(aux);
   return *this;
}

Matrix Matrix::operator*(float val)
{
   Matrix temp;
   temp.Inicializa(ren,col);
   for(int i=0; i<ren;i++)
      for(int j=0; j<col; j++)
         temp.SET(i,j,Mat[i][j]* val);
   return temp;
}


Matrix &Matrix::operator*(const Matrix &m1)
{
  //assert((ren == m1.ren) && (col == m1.col));
   Matrix * result = new Matrix(ren,col,0);
   assert(result);
   for(int i=0; i < ren; i++)
     for(int j = 0;  j < col; j++)
                       //DEBE SER EL NUMERO DE COLUMNAS
                     //REN SOLO SI ES CUADRADA EJ: 3 x 3
       for(int k = 0; k < col; k++)
            //result->Mat[i][j]= result->Mat[i][j] + Mat[i][k] * m1.Mat[k][j];
           result->Mat[i][j] += Mat[i][k] * m1.Mat[k][j];


   return *result;
}

Matrix &Matrix::operator=(Matrix &m)
{
//eliminar el tamaño de la matriz destino
  for(int i= 0; i<ren;i++ )
     //Se borran los renglones de la matriz
       delete [] Mat[i];
  //Se borra el arreglo de punteros
  delete []Mat;
//Asignar los nuevos datos de la matriz que llego
  ren=m.numRen();
  col = m.numCol();
  Mat = new float*[ren];
  assert(Mat);
  for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }
  for( int i =0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = m.Mat[i][j];

  return *this;
}


Matrix &Matrix::asignar(Matrix m)
{
   for(int i=0;i<m.numRen();i++)
       for(int j=0;j<m.numCol();j++)
                Mat[i][j]=m.GET(i,j);
   return *this;
}

Matrix::~Matrix()
{
  //Se libera la memoria
  for(int i= 0; i<ren;i++ )
     //Se borran los renglones de la matriz
       delete [] Mat[i];
  //Se borra el arreglo de punteros
  delete []Mat;

}

Matrix &Matrix::Identidad()
{
  for(int i=0; i < ren; i++)
    for( int j = 0; j < col; j++)
      if( i == j)
         Mat[i][i]= 1;
      else
         Mat[i][j]= 0;
  return *this;
}

//------------------------------    TRANSFORMACIONES    ------------------------------
Matrix &Matrix::Traslacion(Matrix f, Matrix id, int tx, int ty)
{
    id.Identidad();
    id.SET(2,0,tx);
    id.SET(2,1,ty);

    f *= id;
    this->asignar(f);

    return  *this; // SE REGRESA LA FIGURA TRANSFORMADA
}

// ESCALACION NORMAL
Matrix &Matrix::Escalacion(Matrix fEs, Matrix idEs, float sx, float sy)
{
    idEs.Identidad();
    idEs.SET(0,0, sx);
    idEs.SET(1,1, sy);

    fEs *= idEs;
    this->asignar(fEs);

    return *this;
}

// ESCALACION CON PUNTO FIJO
Matrix &Matrix::EscalacionPF(Matrix f, Matrix idPf,  int pfx, int pfy, float sx, float sy)
{
    idPf.Identidad();
    // VALORES QUE SE REMPLAZAN EN LA MATRIZ
    idPf.SET(2, 0, -pfx * (sx - 1));
    idPf.SET(2, 1, -pfy * (sy - 1));
    idPf.SET(0, 0, sx);
    idPf.SET(1, 1, sy);

    f *= idPf;
    this->asignar(f);

    return *this;
}

Matrix &Matrix::Rotacion(Matrix fRt, Matrix idAn, int An)
{
    conversion(An);

    idAn.Identidad();
    idAn.SET(0, 0, round(cos(An)));
    idAn.SET(0, 1, round(sin(An)));
    idAn.SET(1, 0, round(-sin(An)));
    idAn.SET(1, 1, round(cos(An)));

    fRt *= idAn;
    this->asignar(fRt);

    return *this;
}

Matrix &Matrix::Rotacion2(Matrix fRt, Matrix idAn, int An)
{
    conversion(An);

    idAn.Identidad();
    idAn.SET(0, 0, round(cos(An)));
    idAn.SET(0, 1, round(-sin(An)));
    idAn.SET(1, 0, round(sin(An)));
    idAn.SET(1, 1, round(cos(An)));

    fRt *= idAn;
    this->asignar(fRt);

    return *this;
}

Matrix &Matrix::RotacionPF(Matrix fRt, Matrix idAn, double An, double pgx, double pgy)
{
    double rad = An * M_PI/ 180.0;
    double r20 = pgx*(1 - cos(rad)) + pgy*sin(rad);
    double r21 = pgy*(1 - cos(rad)) - pgx*sin(rad);

    idAn.Identidad();
    idAn.SET(0, 0, cos(rad));
    idAn.SET(0, 1, sin(rad));
    idAn.SET(1, 0, -sin(rad));
    idAn.SET(1, 1, cos(rad));
    idAn.SET(2, 0, r20);
    idAn.SET(2, 1, r21);

    fRt *= idAn;
    this->asignar(fRt);

    return *this;
}

Matrix &Matrix::RotacionPF2(Matrix fRt, Matrix idAn, double pgx, double pgy, double An)
{
    double rad = conversion(An);
    double r20 = -pgx*(cos(rad) - 1) - pgy*sin(rad);
    double r21 = pgx*sin(rad) - pgy*(cos(rad) - 1);

    idAn.Identidad();
    idAn.SET(0, 0, cos(rad));
    idAn.SET(0, 1, -sin(rad));
    idAn.SET(1, 0, sin(rad));
    idAn.SET(1, 1, cos(rad));
    idAn.SET(2, 0, r20);
    idAn.SET(2, 1, r21);

    fRt *= idAn;
    this->asignar(fRt);

    return *this;
}
