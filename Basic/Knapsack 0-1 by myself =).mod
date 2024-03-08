/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Quang Chien
 * Creation Date: Mar 8, 2024 at 3:28:09 PM
 *********************************************/
 
int n = ...;

range num_of_item = 1..n;

/* Các biến cần đặt:
v_i: giá trị của vật thứ i
x_i: có lấy vật i hay không --> biến quyết định
w_i: trọng lượng vật i
c: trọng lượng không được vượt quá
*/

int v[num_of_item] = ...;
int w[num_of_item] = ...;
int c = ...;

dvar int+ x[num_of_item];

maximize
  sum (i in num_of_item) v[i] * x[i];
  
subject to {
  sum (i in num_of_item) w[i] * x[i] <= c;
}
