/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Quang Chien
 * Creation Date: Mar 8, 2024 at 2:52:23 PM
 *********************************************/
/* max cT x
s.t. Ax ≤ b,
x ≥ 0
*/

/* khai báo số hàng, cột */
int m = ...;
int n = ...;

/* khai bảo khoảng hàng cột cho ma trận */
range row = 1..m;
range col = 1..n;

/* khai báo biến */
int A[row][col] = ...;
int b[row] = ...;
int c[col] = ...;

dvar int+ x[col];

maximize
  sum (j in col) c[j]*x[j];
  
subject to {
  forall (i in row)
    ct: /*give a name to the constraint in. This name will be used as an 
    identifier when we later want to obtain information about the constraint.*/
    sum (j in col) A[i][j] * x[j] <= b[i];
}

/* Viết nghiệm (sẽ quay lại sau) */

execute {
  writeln("Optimal value: ", cplex.getObjValue());
  writeln("Primal solution:");
  write("x=[");
  for (var j in col){
    write (x[j], " ");
  }
  writeln ("]");
}