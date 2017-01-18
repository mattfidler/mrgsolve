
#include "odepack_dlsoda.h"
#include <algorithm>

odepack_dlsoda::odepack_dlsoda(int npar_, int neq_) {

  Npar = npar_;
  Neq = neq_;

  Y = new double[neq_+1]();
  Ydot = new double[neq_+1]();
  
  // xrwork[0] = 0.0;
  // xrwork[4] = 0.0;      // h0
  // xrwork[5] = 0.0;      // hmax
  // xrwork[6] = 0.0;      // hmin
  // 
  // tcrit = rwork1
  // h0 = rwork5
  // hmax = rwork6
  // hmin = rwork7
   rwork1 = rwork5 = rwork6 = rwork7 = 0.0;
 
 // ml = iwork1
 // mu = iwork2
 // ixpr = iwork5
 // mxstep = iwork6
 // mxhnil = iwork7
 // mxordn = iwork8
 // mxords = iwork9
 // 
 
  iwork1 = iwork2 = iwork5 = 0;
  iwork6 = 500;
  iwork7 = 1;
  iwork8 = 12;
  iwork9 = 5;
  // xiwork[0] = 0;
  // xiwork[1] = 0;
  // xiwork[4] = 0;     // IXPR print if switch
  // xiwork[5] = 500 ; //maxsteps_;
  // xiwork[6] = 1;    //max number of prints
  // xiwork[7] = 12;  // maxordn
  // xiwork[8] = 5;  // maxords

  xitol = 1;
  xiopt = 0;
  xitask = 1;
  xistate = 1;
  xjt = 2;
  xatol[0] = 1E-8;
  xatol[1] = 1E-8;
  xrtol[0] = 1E-8;
  xrtol[1] = 1E-8;
}


odepack_dlsoda::~odepack_dlsoda(){
  delete [] Y;
  delete [] Ydot;
}



void odepack_dlsoda::tol(double atol, double rtol) {
  xatol[0] = xatol[1] = atol;
  xrtol[0] = xrtol[1] = rtol;
}


