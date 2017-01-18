
#include "odepack_dlsoda.h"
#include <algorithm>

odepack_dlsoda::odepack_dlsoda(int npar_, int neq_, int c_solver_) {

  Npar = npar_;
  Neq = neq_;

  C_SOLVER = c_solver_;
  
  Y = new double[neq_+C_SOLVER]();
  Ydot = new double[neq_+C_SOLVER]();
  
  xlrwork = std::max(int(20 + 16 * neq_),int(22 + 9  * neq_ + pow(neq_,2)));
  xliwork = 20+neq_;
  
  xrwork = new double[xlrwork];
  xiwork = new int [xliwork];

  xrwork[0] = 0.0;
  xrwork[4] = 0.0;      // h0
  xrwork[5] = 0.0;      // hmax
  xrwork[6] = 0.0;      // hmin
  
  xiwork[0] = 0;
  xiwork[1] = 0;
  xiwork[4] = 0;     // IXPR print if switch
  xiwork[5] = 500 ; //maxsteps_;
  xiwork[6] = 1;    //max number of prints
  xiwork[7] = 12;  // maxordn
  xiwork[8] = 5;  // maxords
  
  
  // tcrit = rwork1
  // h0 = rwork5
  // hmax = rwork6
  // hmin = rwork7
  rwork1 = rwork5 = rwork6 = rwork7 = 0.0;

  iwork1 = iwork2 = iwork5 = 0; // IXPR print if switch
  iwork6 = 500; //maxsteps_;
  iwork7 = 1; //max number of prints
  iwork8 = 12; // maxordn
  iwork9 = 5; // maxords

  xitol = 1;
  xiopt = 0;
  xitask = 1;
  xistate = 1;
  xjt = 2;
  
  xatol[0] = 1E-8;
  xatol[1] = 1E-8;
  xrtol[0] = 1E-8;
  xrtol[1] = 1E-8;
  xxatol   = 1E-8;
  xxrtol   = 1E-8;
}


odepack_dlsoda::~odepack_dlsoda(){
  delete [] Y;
  delete [] Ydot;
  delete [] xrwork;
  delete [] xiwork;
}



void odepack_dlsoda::tol(double atol, double rtol) {
  xxatol = xatol[0] = xatol[1] = atol;
  xxrtol = xrtol[0] = xrtol[1] = rtol;
}


