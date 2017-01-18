// This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/ or send a letter to
// Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.


#ifndef ODEPACK_DLSODA_H
#define ODEPACK_DLSODA_H
#include <math.h>

class odepack_dlsoda {

public:
  
  odepack_dlsoda(int npar_, int neq_);
  virtual ~odepack_dlsoda();
  
  void hmax(double value){rwork6 = value; if(value !=0) xiopt=1;}
  void hmin(double value){rwork7 = value;  if(value !=0) xiopt=1;}
  void ixpr(int value){iwork5 = value; if(value !=0) xiopt=1;}
  void maxsteps(int value){iwork6 = value; if(value !=0) xiopt=1;}
  void mxhnil(int value){iwork7 = value; if (value !=0) xiopt=1;}
  int  istate(){return xistate;}
  void istate(int value){xistate = value;}
  void lsoda_init(){xistate=1;}
  int  itask(){return xitask;}
  void itask(int itask){xitask = itask;}
  void tol(double atol, double rtol);
  
  // double* rwork(){return xrwork;}
  // void    rwork(int pos, double value){xrwork[pos] = value;}
  // int*    iwork(){return xiwork;}
  // void    iwork(int pos,int value){xiwork[pos] = value;}
  //void    tcrit(double value){xrwork[0] = value;}
  double* y(){return Y;}
  void    y(const int pos, const double value){Y[pos] = value;}
  double  y(const int pos){return Y[pos];}
  double* ydot(){return Ydot;}
  
  int     npar() {return Npar;}
  int     neq(){return Neq;}

  
protected :

  double          rwork1, rwork5, rwork6, rwork7;
  int             iwork1, iwork2, iwork5, iwork6, iwork7, iwork8, iwork9;

  int     xistate;
  int     xitask,xiopt,xitol;
  int     Neq, Npar;
  int     xjt;

  double xatol[2];
  double xrtol[2];

  double* Y;
  double* Ydot;
};


#endif



