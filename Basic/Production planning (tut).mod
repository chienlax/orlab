/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Quang Chien
 * Creation Date: Mar 8, 2024 at 9:45:10 AM
 

 *********************************************/
 
/*
We will continue with a production planning problem. A company produces two
products: doors and windows. It has three production facilities with limited
production time available:
• Factory 1 produces the metal frame
• Factory 2 produces the wooden frame
• Factory 3 produces glass and mounts the parts
The products are produced in series of 200 items and each series generates a
revenue depending on the product. Each series require a given amount of time
of each factory’s capacity. The problem is to find the number of series of each
product to maximize the revenue. This can be modelled as the following linear
  
Model: maximize r_d x_d + r_w x_w
subject to:
t_d,1 x_d + t_w,1 x_w ≤ c1
t_d,2 x_d + t_w,2 x_w ≤ c2
t_d,3 x_d + tw,3 x_w ≤ c3
x ≥ 0, y ≥ 0

r_p is the revenue of product p
t_p,i is the time needed for the factory i to produce the product p
c_i is the time available at factory i
x_p is the number of series of product p produced  
*/
 
/* Khai báo tập phần tử */
{string} Products = ...;
{string} Factories = ...;

/* Khai báo các biến */
float r[Products] = ...;
/*float t[Products][Factories] = ...;*/
float t[Factories][Products] = ...; /* nếu đổi ngược lại thì phải đổi thứ tự biến */
float c[Factories] = ...;

/* Khai báo biến quyết định */
dvar float+ x[Products];

/* Model */
maximize
  sum(p in Products) r[p] * x[p];

/* Thời gian để công xưởng i sản xuất xong sp p --> t[p][i] */
/* Nếu để thành t[i][p] thì sẽ thế nào? Thì sẽ phải đổi input, tại mảng ban đầu là 2*3
tức là đang đưa input theo kiểu thời gian sản xuất mỗi sản phẩm của mỗi nhà máy
Vì thế đổi thành 3*2 là được, thành thời gian để mỗi nhà máy sản xuất mỗi sp
(còn về ý nghĩa thì k đổi)


subject to {
  forall (i in Factories) 
  	sum (p in Products) t[p][i] * x[p] <= c[i];
}
*/

subject to {
  forall (i in Factories) 
  	sum (p in Products) t[i][p] * x[p] <= c[i];
}
