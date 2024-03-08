/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Quang Chien
 * Creation Date: Mar 8, 2024 at 9:33:35 AM
 *********************************************/
dvar float x;
dvar float y;

minimize
  4*x - 2*y;
 
subject to {
  x-y >= 1;
  x >= 0;
}