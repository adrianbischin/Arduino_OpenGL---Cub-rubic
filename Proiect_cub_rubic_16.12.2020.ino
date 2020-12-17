// codificare culori:
// albastru - 0,  portocaliu - 1,  rosu - 2
// galben   - 3,  verde      - 4,  alb  - 5
unsigned char     sus[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
unsigned char  stanga[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
unsigned char    fata[3][3] = {{2,2,2}, {2,2,2}, {2,2,2}};
unsigned char dreapta[3][3] = {{3,3,3}, {3,3,3}, {3,3,3}};
unsigned char     jos[3][3] = {{4,4,4}, {4,4,4}, {4,4,4}};
unsigned char   spate[3][3] = {{5,5,5}, {5,5,5}, {5,5,5}};
unsigned char aux1[3];
unsigned char aux2[3];
unsigned char aux3[3];

int plane_xy__z_equals_0__trig_rotation = 0;
int plane_xy__z_equals_0__inverse_trig_rotation = 0;
int plane_xy__z_equals_1__trig_rotation = 0;
int plane_xy__z_equals_1__inverse_trig_rotation = 0;
int plane_xy__z_equals_2__trig_rotation = 0;
int plane_xy__z_equals_2__inverse_trig_rotation = 0;

int plane_minus_zy__x_equals_0__trig_rotation = 0;
int plane_minus_zy__x_equals_0__inverse_trig_rotation = 0;
int plane_minus_zy__x_equals_1__trig_rotation = 0;
int plane_minus_zy__x_equals_1__inverse_trig_rotation = 0;
int plane_minus_zy__x_equals_2__trig_rotation = 0;
int plane_minus_zy__x_equals_2__inverse_trig_rotation = 0;

int plane_x_minus_z__y_equals_0__trig_rotation = 0;
int plane_x_minus_z__y_equals_0__inverse_trig_rotation = 0;
int plane_x_minus_z__y_equals_1__trig_rotation = 0;
int plane_x_minus_z__y_equals_1__inverse_trig_rotation = 0;
int plane_x_minus_z__y_equals_2__trig_rotation = 0;
int plane_x_minus_z__y_equals_2__inverse_trig_rotation = 0;

int put_the_cube_in_solved_position = 0;
int put_the_cube_in_a_mixed_position = 0;




  

void setup() {
  
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  pinMode(39, INPUT);

  pinMode(40, INPUT);
  pinMode(41, INPUT);
    
}






void loop() {

plane_xy__z_equals_0__trig_rotation = digitalRead(22);
plane_xy__z_equals_0__inverse_trig_rotation = digitalRead(23);
plane_xy__z_equals_1__trig_rotation = digitalRead(24);
plane_xy__z_equals_1__inverse_trig_rotation = digitalRead(25);
plane_xy__z_equals_2__trig_rotation = digitalRead(26);
plane_xy__z_equals_2__inverse_trig_rotation = digitalRead(27);

plane_minus_zy__x_equals_0__trig_rotation = digitalRead(28);
plane_minus_zy__x_equals_0__inverse_trig_rotation = digitalRead(29);
plane_minus_zy__x_equals_1__trig_rotation = digitalRead(30);
plane_minus_zy__x_equals_1__inverse_trig_rotation = digitalRead(31);
plane_minus_zy__x_equals_2__trig_rotation = digitalRead(32);
plane_minus_zy__x_equals_2__inverse_trig_rotation = digitalRead(33);

plane_x_minus_z__y_equals_0__trig_rotation = digitalRead(34);
plane_x_minus_z__y_equals_0__inverse_trig_rotation = digitalRead(35);
plane_x_minus_z__y_equals_1__trig_rotation = digitalRead(36);
plane_x_minus_z__y_equals_1__inverse_trig_rotation = digitalRead(37);
plane_x_minus_z__y_equals_2__trig_rotation = digitalRead(38);
plane_x_minus_z__y_equals_2__inverse_trig_rotation = digitalRead(39);

put_the_cube_in_solved_position = digitalRead(40);
put_the_cube_in_a_mixed_position = digitalRead(41);

  if(put_the_cube_in_solved_position) {
    sus[0][0] = 0;
    sus[0][1] = 0;
    sus[0][2] = 0;
    sus[1][0] = 0;
    sus[1][1] = 0;
    sus[1][2] = 0;
    sus[2][0] = 0;
    sus[2][1] = 0;
    sus[2][2] = 0;

    stanga[0][0] = 1;
    stanga[0][1] = 1;
    stanga[0][2] = 1;
    stanga[1][0] = 1;
    stanga[1][1] = 1;
    stanga[1][2] = 1;
    stanga[2][0] = 1;
    stanga[2][1] = 1;
    stanga[2][2] = 1;

    fata [0][0] = 2;
    fata [0][1] = 2;
    fata [0][2] = 2;
    fata [1][0] = 2;
    fata [1][1] = 2;
    fata [1][2] = 2;
    fata [2][0] = 2;
    fata [2][1] = 2;
    fata [2][2] = 2;

    dreapta[0][0] = 3;
    dreapta[0][1] = 3;
    dreapta[0][2] = 3;
    dreapta[1][0] = 3;
    dreapta[1][1] = 3;
    dreapta[1][2] = 3;
    dreapta[2][0] = 3;
    dreapta[2][1] = 3;
    dreapta[2][2] = 3;

    jos[0][0] = 4;
    jos[0][1] = 4;
    jos[0][2] = 4;
    jos[1][0] = 4;
    jos[1][1] = 4;
    jos[1][2] = 4;
    jos[2][0] = 4;
    jos[2][1] = 4;
    jos[2][2] = 4;

    spate[0][0] = 5;
    spate[0][1] = 5;
    spate[0][2] = 5;
    spate[1][0] = 5;
    spate[1][1] = 5;
    spate[1][2] = 5;
    spate[2][0] = 5;
    spate[2][1] = 5;
    spate[2][2] = 5;
  }
  else {
    if(put_the_cube_in_a_mixed_position) {
      sus[0][0] = 1;
      sus[0][1] = 0;
      sus[0][2] = 3;
      sus[1][0] = 4;
      sus[1][1] = 1;
      sus[1][2] = 5;
      sus[2][0] = 3;
      sus[2][1] = 2;
      sus[2][2] = 0;
  
      stanga[0][0] = 0;
      stanga[0][1] = 3;
      stanga[0][2] = 1;
      stanga[1][0] = 3;
      stanga[1][1] = 3;
      stanga[1][2] = 4;
      stanga[2][0] = 2;
      stanga[2][1] = 4;
      stanga[2][2] = 5;
  
      fata [0][0] = 0;
      fata [0][1] = 0;
      fata [0][2] = 2;
      fata [1][0] = 5;
      fata [1][1] = 4;
      fata [1][2] = 1;
      fata [2][0] = 2;
      fata [2][1] = 3;
      fata [2][2] = 4;
      
      dreapta[0][0] = 3;
      dreapta[0][1] = 1;
      dreapta[0][2] = 4;
      dreapta[1][0] = 0;
      dreapta[1][1] = 5;
      dreapta[1][2] = 1;
      dreapta[2][0] = 1;
      dreapta[2][1] = 2;
      dreapta[2][2] = 2;
  
      jos[0][0] = 4;
      jos[0][1] = 0;
      jos[0][2] = 5;
      jos[1][0] = 2;
      jos[1][1] = 2;
      jos[1][2] = 5;
      jos[2][0] = 3;
      jos[2][1] = 1;
      jos[2][2] = 0;
  
      spate[0][0] = 4;
      spate[0][1] = 4;
      spate[0][2] = 5;
      spate[1][0] = 2;
      spate[1][1] = 0;
      spate[1][2] = 3;
      spate[2][0] = 5;
      spate[2][1] = 5;
      spate[2][2] = 1;
    }
    else {
      if(plane_xy__z_equals_0__trig_rotation) {
        aux1[0] = stanga[0][2];
        aux1[1] = stanga[1][2];
        aux1[2] = stanga[2][2];
      
        stanga[0][2] = sus[2][2];
        stanga[1][2] = sus[2][1];
        stanga[2][2] = sus[2][0];
      
        sus[2][0] = dreapta[0][0];
        sus[2][1] = dreapta[1][0];
        sus[2][2] = dreapta[2][0];
      
        dreapta[0][0] = jos[0][2];
        dreapta[1][0] = jos[0][1];
        dreapta[2][0] = jos[0][0];
      
        jos[0][0] = aux1[0];
        jos[0][1] = aux1[1];
        jos[0][2] = aux1[2];
      
        aux1[0] = fata[0][0];
        aux1[1] = fata[1][0];
        aux1[2] = fata[2][0];
      
        aux2[0] = fata[0][1];
        aux2[1] = fata[1][1];
        aux2[2] = fata[2][1];
      
        aux3[0] = fata[0][2];
        aux3[1] = fata[1][2];
        aux3[2] = fata[2][2];
      
        fata[0][0] = aux3[0];
        fata[0][1] = aux3[1];
        fata[0][2] = aux3[2];
      
        fata[1][0] = aux2[0];
        fata[1][1] = aux2[1];
        fata[1][2] = aux2[2];
      
        fata[2][0] = aux1[0];
        fata[2][1] = aux1[1];
        fata[2][2] = aux1[2];
      }
    
      if(plane_xy__z_equals_0__inverse_trig_rotation) {
        aux1[0] = stanga[0][2];
        aux1[1] = stanga[1][2];
        aux1[2] = stanga[2][2];
      
        stanga[0][2] = jos[0][0];
        stanga[1][2] = jos[0][1];
        stanga[2][2] = jos[0][2];
      
        jos[0][0] = dreapta[2][0];
        jos[0][1] = dreapta[1][0];
        jos[0][2] = dreapta[0][0];
      
        dreapta[0][0] = sus[2][0];
        dreapta[1][0] = sus[2][1];
        dreapta[2][0] = sus[2][2];
      
        sus[2][0] = aux1[2];
        sus[2][1] = aux1[1];
        sus[2][2] = aux1[0];
      
        aux1[0] = fata[0][0];
        aux1[1] = fata[1][0];
        aux1[2] = fata[2][0];
      
        aux2[0] = fata[0][1];
        aux2[1] = fata[1][1];
        aux2[2] = fata[2][1];
      
        aux3[0] = fata[0][2];
        aux3[1] = fata[1][2];
        aux3[2] = fata[2][2];
      
        fata[0][0] = aux1[2];
        fata[0][1] = aux1[1];
        fata[0][2] = aux1[0];
      
        fata[1][0] = aux2[2];
        fata[1][1] = aux2[1];
        fata[1][2] = aux2[0];
      
        fata[2][0] = aux3[2];
        fata[2][1] = aux3[1];
        fata[2][2] = aux3[0];
      }
    
      if(plane_xy__z_equals_1__trig_rotation) {
        aux1[0] = stanga[0][1];
        aux1[1] = stanga[1][1];
        aux1[2] = stanga[2][1];
      
        stanga[0][1] = sus[1][2];
        stanga[1][1] = sus[1][1];
        stanga[2][1] = sus[1][0];
      
        sus[1][0] = dreapta[0][1];
        sus[1][1] = dreapta[1][1];
        sus[1][2] = dreapta[2][1];
      
        dreapta[0][1] = jos[1][2];
        dreapta[1][1] = jos[1][1];
        dreapta[2][1] = jos[1][0];
      
        jos[1][0] = aux1[2];
        jos[1][1] = aux1[1];
        jos[1][2] = aux1[0];
      }
    
      if(plane_xy__z_equals_1__inverse_trig_rotation) {
        aux1[0] = stanga[0][1];
        aux1[1] = stanga[1][1];
        aux1[2] = stanga[2][1];
      
        stanga[0][1] = jos[1][0];
        stanga[1][1] = jos[1][1];
        stanga[2][1] = jos[1][2];
      
        jos[1][0] = dreapta[2][1];
        jos[1][1] = dreapta[1][1];
        jos[1][2] = dreapta[0][1];
      
        dreapta[0][1] = sus[1][0];
        dreapta[1][1] = sus[1][1];
        dreapta[2][1] = sus[1][2];
      
        sus[1][0] = aux1[2];
        sus[1][1] = aux1[1];
        sus[1][2] = aux1[0];
      }
    
      if(plane_xy__z_equals_2__trig_rotation) {
        aux1[0] = stanga[0][0];
        aux1[1] = stanga[1][0];
        aux1[2] = stanga[2][0];
      
        stanga[0][1] = sus[0][2];
        stanga[1][1] = sus[0][1];
        stanga[2][1] = sus[0][0];
      
        sus[0][0] = dreapta[0][2];
        sus[0][1] = dreapta[1][2];
        sus[0][2] = dreapta[2][2];
      
        dreapta[0][2] = jos[2][2];
        dreapta[1][2] = jos[2][1];
        dreapta[2][2] = jos[2][0];
      
        jos[2][0] = aux1[0];
        jos[2][1] = aux1[1];
        jos[2][2] = aux1[2];
      
        aux1[0] = spate[0][0];
        aux1[1] = spate[1][0];
        aux1[2] = spate[2][0];
      
        aux2[0] = spate[0][1];
        aux2[1] = spate[1][1];
        aux2[2] = spate[2][1];
      
        aux3[0] = spate[0][2];
        aux3[1] = spate[1][2];
        aux3[2] = spate[2][2];
      
        spate[2][0] = aux3[2];
        spate[2][1] = aux3[1];
        spate[2][2] = aux3[0];
      
        spate[1][0] = aux2[2];
        spate[1][1] = aux2[1];
        spate[1][2] = aux2[0];
      
        spate[0][0] = aux1[2];
        spate[0][1] = aux1[1];
        spate[0][2] = aux1[0];
      }
    
      if(plane_xy__z_equals_2__inverse_trig_rotation) {
        aux1[0] = stanga[0][0];
        aux1[1] = stanga[1][0];
        aux1[2] = stanga[2][0];
      
        stanga[0][0] = jos[2][0];
        stanga[1][0] = jos[2][1];
        stanga[2][0] = jos[2][2];
      
        jos[2][0] = dreapta[2][2];
        jos[2][1] = dreapta[1][2];
        jos[2][2] = dreapta[0][2];
      
        dreapta[0][2] = sus[0][0];
        dreapta[1][2] = sus[0][1];
        dreapta[2][2] = sus[0][2];
      
        sus[0][0] = aux1[2];
        sus[0][1] = aux1[1];
        sus[0][2] = aux1[0];
      
        aux1[0] = spate[0][0];
        aux1[1] = spate[1][0];
        aux1[2] = spate[2][0];
      
        aux2[0] = spate[0][1];
        aux2[1] = spate[1][1];
        aux2[2] = spate[2][1];
      
        aux3[0] = spate[0][2];
        aux3[1] = spate[1][2];
        aux3[2] = spate[2][2];
      
        spate[0][0] = aux1[2];
        spate[0][1] = aux1[1];
        spate[0][2] = aux1[0];
      
        spate[1][0] = aux2[2];
        spate[1][1] = aux2[1];
        spate[1][2] = aux2[0];
      
        spate[2][0] = aux3[2];
        spate[2][1] = aux3[1];
        spate[2][2] = aux3[0];
      }
      
      if(plane_minus_zy__x_equals_0__trig_rotation) {
        aux1[0] = sus[0][0];
        aux1[1] = sus[1][0];
        aux1[2] = sus[2][0];
      
        sus[0][0] = fata[0][0];
        sus[1][0] = fata[1][0];
        sus[2][0] = fata[2][0];
      
        fata[0][0] = jos[0][0];
        fata[1][0] = jos[1][0];
        fata[2][0] = jos[2][0];
      
        jos[0][0] = spate[0][0];
        jos[1][0] = spate[1][0];
        jos[2][0] = spate[2][0];
      
        spate[0][0] = aux1[0];
        spate[1][0] = aux1[1];
        spate[2][0] = aux1[2];
      
        aux1[0] = stanga[0][0];
        aux1[1] = stanga[0][1];
        aux1[2] = stanga[0][2];
      
        aux2[0] = stanga[1][0];
        aux2[1] = stanga[1][1];
        aux2[2] = stanga[1][2];
      
        aux3[0] = stanga[2][0];
        aux3[1] = stanga[2][1];
        aux3[2] = stanga[2][2];
      
        stanga[0][0] = aux3[2];
        stanga[1][0] = aux3[1];
        stanga[2][0] = aux3[0];
      
        stanga[0][1] = aux2[2];
        stanga[1][1] = aux2[1];
        stanga[2][1] = aux2[0];
      
        stanga[0][2] = aux1[2];
        stanga[1][2] = aux1[1];
        stanga[2][2] = aux1[0];
      }
    
      if(plane_minus_zy__x_equals_0__inverse_trig_rotation) {
        aux1[0] = sus[0][0];
        aux1[1] = sus[1][0];
        aux1[2] = sus[2][0];
      
        sus[0][0] = spate[0][0];
        sus[1][0] = spate[1][0];
        sus[2][0] = spate[2][0];
      
        spate[0][0] = jos[0][0];
        spate[1][0] = jos[1][0];
        spate[2][0] = jos[2][0];
      
        jos[0][0] = fata[0][0];
        jos[1][0] = fata[1][0];
        jos[2][0] = fata[2][0];
      
        fata[0][0] = aux1[0];
        fata[1][0] = aux1[1];
        fata[2][0] = aux1[2];
      
        aux1[0] = stanga[0][0];
        aux1[1] = stanga[0][1];
        aux1[2] = stanga[0][2];
      
        aux2[0] = stanga[1][0];
        aux2[1] = stanga[1][1];
        aux2[2] = stanga[1][2];
      
        aux3[0] = stanga[2][0];
        aux3[1] = stanga[2][1];
        aux3[2] = stanga[2][2];
      
        stanga[0][0] = aux3[2];
        stanga[1][0] = aux3[1];
        stanga[2][0] = aux3[0];
      
        stanga[0][1] = aux2[2];
        stanga[1][1] = aux2[1];
        stanga[2][1] = aux2[0];
      
        stanga[0][2] = aux1[2];
        stanga[1][2] = aux1[1];
        stanga[2][2] = aux1[0];
      }
    
      if(plane_minus_zy__x_equals_1__trig_rotation) {
        aux1[0] = sus[0][1];
        aux1[1] = sus[1][1];
        aux1[2] = sus[2][1];
      
        sus[0][1] = fata[0][1];
        sus[1][1] = fata[1][1];
        sus[2][1] = fata[2][1];
      
        fata[0][1] = jos[0][1];
        fata[1][1] = jos[1][1];
        fata[2][1] = jos[2][1];
      
        jos[0][1] = spate[0][1];
        jos[1][1] = spate[1][1];
        jos[2][1] = spate[2][1];
      
        spate[0][1] = aux1[0];
        spate[1][1] = aux1[1];
        spate[2][1] = aux1[2];
      }
    
      if(plane_minus_zy__x_equals_1__inverse_trig_rotation) {
        aux1[0] = sus[0][1];
        aux1[1] = sus[1][1];
        aux1[2] = sus[2][1];
      
        sus[0][1] = spate[0][1];
        sus[1][1] = spate[1][1];
        sus[2][1] = spate[2][1];
      
        spate[0][1] = jos[0][1];
        spate[1][1] = jos[1][1];
        spate[2][1] = jos[2][1];
      
        jos[0][1] = fata[0][1];
        jos[1][1] = fata[1][1];
        jos[2][1] = fata[2][1];
      
        fata[0][1] = aux1[0];
        fata[1][1] = aux1[1];
        fata[2][1] = aux1[2];
      }
    
      if(plane_minus_zy__x_equals_2__trig_rotation) {
        aux1[0] = sus[0][2];
        aux1[1] = sus[1][2];
        aux1[2] = sus[2][2];
      
        sus[0][2] = fata[0][2];
        sus[1][2] = fata[1][2];
        sus[2][2] = fata[2][2];
      
        fata[0][2] = jos[0][2];
        fata[1][2] = jos[1][2];
        fata[2][2] = jos[2][2];
      
        jos[0][2] = spate[0][2];
        jos[1][2] = spate[1][2];
        jos[2][2] = spate[2][2];
      
        spate[0][2] = aux1[0];
        spate[1][2] = aux1[1];
        spate[2][2] = aux1[2];
      
        aux1[0] = dreapta[0][0];
        aux1[1] = dreapta[0][1];
        aux1[2] = dreapta[0][2];
      
        aux2[0] = dreapta[1][0];
        aux2[1] = dreapta[1][1];
        aux2[2] = dreapta[1][2];
      
        aux3[0] = dreapta[2][0];
        aux3[1] = dreapta[2][1];
        aux3[2] = dreapta[2][2];
      
        dreapta[0][0] = aux3[0];
        dreapta[1][0] = aux3[1];
        dreapta[2][0] = aux3[2];
      
        dreapta[0][1] = aux2[0];
        dreapta[1][1] = aux2[1];
        dreapta[2][1] = aux2[2];
      
        dreapta[0][2] = aux1[0];
        dreapta[1][2] = aux1[1];
        dreapta[2][2] = aux1[2];
      }
    
      if(plane_minus_zy__x_equals_2__inverse_trig_rotation) {
        aux1[0] = sus[0][1];
        aux1[1] = sus[1][1];
        aux1[2] = sus[2][1];
      
        sus[0][1] = spate[0][1];
        sus[1][1] = spate[1][1];
        sus[2][1] = spate[2][1];
      
        spate[0][1] = jos[0][1];
        spate[1][1] = jos[1][1];
        spate[2][1] = jos[2][1];
      
        jos[0][1] = fata[0][1];
        jos[1][1] = fata[1][1];
        jos[2][1] = fata[2][1];
      
        fata[0][1] = aux1[0];
        fata[1][1] = aux1[1];
        fata[2][1] = aux1[2];
      
        aux1[0] = dreapta[0][0];
        aux1[1] = dreapta[0][1];
        aux1[2] = dreapta[0][2];
      
        aux2[0] = dreapta[1][0];
        aux2[1] = dreapta[1][1];
        aux2[2] = dreapta[1][2];
      
        aux3[0] = dreapta[2][0];
        aux3[1] = dreapta[2][1];
        aux3[2] = dreapta[2][2];
      
        dreapta[0][0] = aux1[2];
        dreapta[1][0] = aux1[1];
        dreapta[2][0] = aux1[0];
      
        dreapta[0][1] = aux2[2];
        dreapta[1][1] = aux2[1];
        dreapta[2][1] = aux2[0];
      
        dreapta[0][2] = aux3[2];
        dreapta[1][2] = aux3[1];
        dreapta[2][2] = aux3[0];
      }
      
      if(plane_x_minus_z__y_equals_0__trig_rotation) {
        aux1[0] = fata[2][0];
        aux1[1] = fata[2][1];
        aux1[2] = fata[2][2];
      
        fata[2][0] = dreapta[2][0];
        fata[2][1] = dreapta[2][1];
        fata[2][2] = dreapta[2][2];
      
        dreapta[2][0] = spate[0][2];
        dreapta[2][1] = spate[0][1];
        dreapta[2][2] = spate[0][0];
      
        spate[0][0] = stanga[2][2];
        spate[0][1] = stanga[2][1];
        spate[0][2] = stanga[2][0];
      
        stanga[2][0] = aux1[0];
        stanga[2][1] = aux1[1];
        stanga[2][2] = aux1[2];
      
        aux1[0] = jos[0][0];
        aux1[1] = jos[1][0];
        aux1[2] = jos[2][0];
      
        aux2[0] = jos[0][1];
        aux2[1] = jos[1][1];
        aux2[2] = jos[2][1];
      
        aux3[0] = jos[0][2];
        aux3[1] = jos[1][2];
        aux3[2] = jos[2][2];
      
        jos[0][0] = aux3[0];
        jos[0][1] = aux3[1];
        jos[0][2] = aux3[2];
      
        jos[1][0] = aux2[0];
        jos[1][1] = aux2[1];
        jos[1][2] = aux2[2];
      
        jos[2][0] = aux1[0];
        jos[2][1] = aux1[1];
        jos[2][2] = aux1[2];
      }
    
      if(plane_x_minus_z__y_equals_0__inverse_trig_rotation) {
        aux1[0] = fata[2][0];
        aux1[1] = fata[2][1];
        aux1[2] = fata[2][2];
      
        fata[2][0] = stanga[2][0];
        fata[2][1] = stanga[2][1];
        fata[2][2] = stanga[2][2];
      
        stanga[2][0] = spate[0][2];
        stanga[2][1] = spate[0][1];
        stanga[2][2] = spate[0][0];
      
        spate[0][0] = dreapta[2][2];
        spate[0][1] = dreapta[2][1];
        spate[0][2] = dreapta[2][0];
      
        dreapta[2][0] = aux1[0];
        dreapta[2][1] = aux1[1];
        dreapta[2][2] = aux1[2];
      
        aux1[0] = jos[0][0];
        aux1[1] = jos[1][0];
        aux1[2] = jos[2][0];
      
        aux2[0] = jos[0][1];
        aux2[1] = jos[1][1];
        aux2[2] = jos[2][1];
      
        aux3[0] = jos[0][2];
        aux3[1] = jos[1][2];
        aux3[2] = jos[2][2];
      
        jos[0][0] = aux1[0];
        jos[0][1] = aux1[1];
        jos[0][2] = aux1[2];
      
        jos[1][0] = aux2[0];
        jos[1][1] = aux2[1];
        jos[1][2] = aux2[2];
      
        jos[2][0] = aux3[0];
        jos[2][1] = aux3[1];
        jos[2][2] = aux3[2];
      }
    
      if(plane_x_minus_z__y_equals_1__trig_rotation) {
        aux1[0] = fata[1][0];
        aux1[1] = fata[1][1];
        aux1[2] = fata[1][2];
      
        fata[1][0] = dreapta[1][0];
        fata[1][1] = dreapta[1][1];
        fata[1][2] = dreapta[1][2];
      
        dreapta[1][0] = spate[1][2];
        dreapta[1][1] = spate[1][1];
        dreapta[1][2] = spate[1][0];
      
        spate[1][0] = stanga[1][2];
        spate[1][1] = stanga[1][1];
        spate[1][2] = stanga[1][0];
      
        stanga[1][0] = aux1[0];
        stanga[1][1] = aux1[1];
        stanga[1][2] = aux1[2];
      }
    
      if(plane_x_minus_z__y_equals_1__inverse_trig_rotation) {
        aux1[0] = fata[1][0];
        aux1[1] = fata[1][1];
        aux1[2] = fata[1][2];
      
        fata[1][0] = stanga[1][0];
        fata[1][1] = stanga[1][1];
        fata[1][2] = stanga[1][2];
      
        stanga[1][0] = spate[1][2];
        stanga[1][1] = spate[1][1];
        stanga[1][2] = spate[1][0];
      
        spate[1][0] = dreapta[1][2];
        spate[1][1] = dreapta[1][1];
        spate[1][2] = dreapta[1][0];
      
        dreapta[1][0] = aux1[0];
        dreapta[1][1] = aux1[1];
        dreapta[1][2] = aux1[2];
      }
    
      if(plane_x_minus_z__y_equals_2__trig_rotation) {
        aux1[0] = fata[0][0];
        aux1[1] = fata[0][1];
        aux1[2] = fata[0][2];
      
        fata[0][0] = dreapta[0][0];
        fata[0][1] = dreapta[0][1];
        fata[0][2] = dreapta[0][2];
      
        dreapta[0][0] = spate[2][2];
        dreapta[0][1] = spate[2][1];
        dreapta[0][2] = spate[2][0];
      
        spate[2][0] = stanga[0][2];
        spate[2][1] = stanga[0][1];
        spate[2][2] = stanga[0][0];
      
        stanga[0][0] = aux1[0];
        stanga[0][1] = aux1[1];
        stanga[0][2] = aux1[2];
      
        aux1[0] = sus[0][0];
        aux1[1] = sus[1][0];
        aux1[2] = sus[2][0];
      
        aux2[0] = sus[0][1];
        aux2[1] = sus[1][1];
        aux2[2] = sus[2][1];
      
        aux3[0] = sus[0][2];
        aux3[1] = sus[1][2];
        aux3[2] = sus[2][2];
      
        sus[0][0] = aux1[2];
        sus[0][1] = aux1[1];
        sus[0][2] = aux1[0];
      
        sus[1][0] = aux2[2];
        sus[1][1] = aux2[1];
        sus[1][2] = aux2[0];
      
        sus[2][0] = aux3[2];
        sus[2][1] = aux3[1];
        sus[2][2] = aux3[0];
      }
    
      if(plane_x_minus_z__y_equals_2__inverse_trig_rotation) {
        aux1[0] = fata[0][0];
        aux1[1] = fata[0][1];
        aux1[2] = fata[0][2];
      
        fata[0][0] = stanga[0][0];
        fata[0][1] = stanga[0][1];
        fata[0][2] = stanga[0][2];
      
        stanga[0][0] = spate[2][2];
        stanga[0][1] = spate[2][1];
        stanga[0][2] = spate[2][0];
      
        spate[2][0] = dreapta[0][2];
        spate[2][1] = dreapta[0][1];
        spate[2][2] = dreapta[0][0];
      
        dreapta[0][0] = aux1[0];
        dreapta[0][1] = aux1[1];
        dreapta[0][2] = aux1[2];
      
        aux1[0] = jos[0][0];
        aux1[1] = jos[1][0];
        aux1[2] = jos[2][0];
      
        aux2[0] = jos[0][1];
        aux2[1] = jos[1][1];
        aux2[2] = jos[2][1];
      
        aux3[0] = jos[0][2];
        aux3[1] = jos[1][2];
        aux3[2] = jos[2][2];
      
        jos[0][0] = aux3[0];
        jos[0][1] = aux3[1];
        jos[0][2] = aux3[2];
      
        jos[1][0] = aux2[0];
        jos[1][1] = aux2[1];
        jos[1][2] = aux2[2];
      
        jos[2][0] = aux1[0];
        jos[2][1] = aux1[1];
        jos[2][2] = aux1[2];
      }
    }
  }
  
}
