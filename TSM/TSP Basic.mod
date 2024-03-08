/*********************************************
 * OPL 22.1.1.0 Model
 * Author: Quang Chien
 * Creation Date: Mar 8, 2024 at 4:33:10 PM
 *********************************************/
//tutorial youtube: https://www.youtube.com/watch?v=URHDTzzDJak

// TSP random
// problem size
int n = 10; // số thành phố
range cities = 1..n;

// generate random data

tuple location {
  float x;
  float y;
} //tọa độ của 2 thành phố

tuple edge {
  int i;
  int j;
}

// tạo các đường đi từ các đỉnh, lưu ý k tồn tại edge_1,1
setof(edge) edges = {<i, j> | i, j in cities : i!=j}; //cách tạo 1 set các phần tử i, j
													//với i, j thuộc cities và i khác j

float c[edges];
location cityLocation[cities];

execute { //pre-processing: tính quãng đường giữa mỗi thành phố
	function getDistance(city1, city2){
	  return Opl.sqrt(Opl.pow(city1.x - city2.x, 2) + Opl.pow(city1.y - city2.y, 2));
	}

	for (var i in cities) { //khai báo tọa độ của các thành phố (random)
    	cityLocation[i].x = Opl.rand(100);
    	cityLocation[i].y = Opl.rand(100);
    }
  
	for (var e in edges){ //thêm trọng số cho các cạnh
	  c[e] = getDistance(cityLocation[e.i], cityLocation[e.j]);
	}
}	
	
	//gthich: mỗi edge có 2 tham số i, j là đường nối giữa thành phố i và thành phố j
	//cityLocation[e.i] là thành phố bắt đầu, cityLocation[e.j] là thành phố điểm đến
	
	/*
	Ví dụ: Có 5 thành phố:
	for var i in cities: 
	cityLocation[city1].x = 10; 
	cityLocation[city1].y = 20; 
	có nghĩa là tọa độ (x, y) của thành phố 1 là (10, 20)
	
	Tương tự giả sử thành phố 2 có tọa độ (20, 30)
	
	edges = {<1, 2>, {2, 3> ...}
	
	Vậy:
	for e in edges:
		cityLocation[e.i] là cityLocation[1] (city1)
		cityLocation[e.j] là cityLocation[2] (city2)
	Khi đó getDistance sẽ trả lại quãng đường giữa 2 thành phố 
	*/
	
// decision variable
dvar boolean x[edges]; //có đi từ i đến j hay khôk
dvar float+ u[2..n];

//expression:
dexpr float TotalDistance = sum(e in edges) c[e]*x[e];
minimize TotalDistance;

subject to {
  forall (j in cities) {
    flow_in: //kiểm soát đường đi vào
    sum (i in cities : i != j) x[<i, j>] == 1;
  } //specify điều kiện có thể dùng ':' (such as)
  
  forall (i in cities){
    for_out:
    sum (j in cities : j != i) x[<i, j>] == 1;
  }
  
  forall (i in cities : i>1, j in cities : j>1 && j != i){
    subtour:
    u[i] - u[j] + (n-1)*x[<i, j>] <= n-2;
  }
}

//modify lại để xem được đi qua những cạnh nào =)) :

execute{
  writeln ("go from");
  for (e in edges){
   	if (x[e] == 1){
   	  writeln ("from ", e.i, " to ", e.j);
   	}
  }
}