const int num5 = 5;
const int num3 = 3;// numero de columnas de los botones y de casi todo
int pin13 = 13;//cable alimentacion de botones
int pin2 = 2;
int index_arriba = 0;
int index_izquierdad = 0;// cable del bonbillo de turno
bool turno=true;
bool estado_Pin2 = true; //verde
int matriz_boton_col[]={A0,A1,A2,A3,A4};
int matriz_led_roja_fil[]={9,10,11};
int matriz_led_verde_fil[]={3,4,5};
int matriz_led_col[]={6,7,8};

int del3 = 255;
// las sigientes matrizes las usamos para movernos con los botones
// si es verde es 1 si es rojo es 2 el tercer valor
int matriz_roja_verde[3][3][3] = {
  {{3,11,0},{4,10,0},{5,9,0}},
  {{3,11,0},{4,10,0},{5,9,0}},
  {{3,11,0},{4,10,0},{5,9,0}}
};
int matriz_mover[3][3] = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
};
int val = 0; // variable para leer las entradas analogicas

void setup() {
  Serial.begin(9600);
  //inicializamos los pines digitales
	pinMode(pin2,OUTPUT);
  // filas rojas led
  for (int i=0;i<num3;i++){
  	pinMode(matriz_roja_verde[0][i][1],OUTPUT);
  }
  // filas verdes led
  for (int i=0;i<num3;i++){
  	pinMode(matriz_roja_verde[0][i][0],OUTPUT);
  }
  // columnas led
  for (int i=0;i<num3;i++){
  	pinMode(matriz_led_col[i],INPUT);
  }
  
}

void mover(){
	// detecta que boton fue presionado 
  digitalWrite(pin13,255);
  ubicar_led();
  // detecta que boton fue presionado 
  for (int j=0;j<num5;j++){
    val = analogRead(matriz_boton_col[j]);
    if (val < 1020){
    }else{
      //abajo
      if(j==0){
        izquierdad();
        break;
      }else if(j==1){
        abajo();
        break;
      }else if(j==2){
        derecha();
        break;
      }else if(j==3){
        arriba();
        break;
      }else if (j==4){
        seleccionar();
        break;
      }
    }
  }
}

void arriba(){
   delay(200);
  if (index_arriba-2>-1){
  	if ( matriz_mover[index_arriba-1][index_izquierdad]!=0){
  		index_arriba = index_arriba-1;
    }else{
      ( matriz_mover[index_arriba-2][index_izquierdad]!=0);
      index_arriba = index_arriba-2;
    }
  }else if (index_arriba-1>-1){
  	if ( matriz_mover[index_arriba-1][index_izquierdad]!=0){
  	  index_arriba = index_arriba-1;
    }else{ 
      (matriz_mover[index_arriba+1][index_izquierdad]!=0);
      index_arriba = index_arriba+1;
    }
  }else{
  	if ( matriz_mover[index_arriba+2][index_izquierdad]!=0){
  		index_arriba = index_arriba+2;
    }else {
      ( matriz_mover[index_arriba+1][index_izquierdad]!=0);
      index_arriba = index_arriba+1;
    }
  }	
}
void abajo(){
  delay(200);
  if (index_arriba+2<3){
  	if ( matriz_mover[index_arriba+1][index_izquierdad]!=0){
  		index_arriba = index_arriba+1;
    }else{
      ( matriz_mover[index_arriba+2][index_izquierdad]!=0);
      index_arriba = index_arriba+2;
    }
  }else if (index_arriba+1<3){
  	if ( matriz_mover[index_arriba+1][index_izquierdad]!=0){
    	index_arriba = index_arriba+1;
    }else{ 
      (matriz_mover[index_arriba-1][index_izquierdad]!=0);
      index_arriba = index_arriba-1;
    }
  }else{
  	if ( matriz_mover[index_arriba-2][index_izquierdad]!=0){
  		index_arriba = index_arriba-2;
    }else {
      ( matriz_mover[index_arriba-1][index_izquierdad]!=0);
      index_arriba = index_arriba-1;
    }
  }	
}
void derecha(){
  delay(200);
  if (index_izquierdad-2>-1){
  	if ( matriz_mover[index_arriba][index_izquierdad-1]!=0){
  		index_izquierdad = index_izquierdad-1;
    }else{
      ( matriz_mover[index_arriba-2][index_izquierdad]!=0);
      index_izquierdad = index_izquierdad-2;
    }
  }else if (index_izquierdad-1>-1){
  	if ( matriz_mover[index_arriba][index_izquierdad-1]!=0){
  	index_izquierdad = index_izquierdad-1;
    }else{ 
      (matriz_mover[index_arriba][index_izquierdad+1]!=0);
      index_izquierdad = index_izquierdad+1;
    }
  }else{
  	if ( matriz_mover[index_arriba][index_izquierdad+2]!=0){
      index_izquierdad = index_izquierdad+2;
    }else {
      ( matriz_mover[index_arriba][index_izquierdad+1]!=0);
      index_izquierdad = index_izquierdad+1;
    }
  }	 
}

void izquierdad(){
  delay(200);
  if (index_izquierdad+2<3){
  	if (matriz_mover[index_arriba][index_izquierdad+1]!=0){
  		index_izquierdad = index_izquierdad+1;
    }else{
      (matriz_mover[index_arriba][index_izquierdad+2]!=0);
      index_izquierdad = index_izquierdad+2;
    }
  }else if (index_izquierdad+1<3){
  	if ( matriz_mover[index_arriba][index_izquierdad+1]!=0){
  	  index_izquierdad = index_izquierdad+1;
    }else{ 
      (matriz_mover[index_arriba][index_izquierdad-1]!=0);
      index_izquierdad = index_izquierdad-1;
    }
  }else{
  	if ( matriz_mover[index_arriba][index_izquierdad-2]!=0){
  		index_izquierdad = index_izquierdad-2;
    }else {
      ( matriz_mover[index_arriba][index_izquierdad-1]!=0);
      index_izquierdad = index_izquierdad-1;
    }
  }	
}

void seleccionar(){
  delay(100);
  matriz_mover[index_arriba][index_izquierdad]=0;
  if (estado_Pin2==false){
    matriz_roja_verde[index_izquierdad][index_arriba][2]=1;
  } else {
    matriz_roja_verde[index_izquierdad][index_arriba][2]=2;
  }
  cambio_turno();
}

void ubicar_led(){
  delay(10);
  int aux = matriz_roja_verde[index_izquierdad][index_arriba][2];
  for ( int i=0; i<100; i++){
    matriz_roja_verde[index_izquierdad][index_arriba][2]=2;
    mostrar_matriz();
    matriz_roja_verde[index_izquierdad][index_arriba][2]=1;
    mostrar_matriz();
  }
  matriz_roja_verde[index_izquierdad][index_arriba][2]=aux;
}

void cambio_turno(){
  if (estado_Pin2 == true){
  	estado_Pin2 = false;
	  digitalWrite(pin2,HIGH);
  }else{
  	estado_Pin2 = true;
    digitalWrite(pin2,LOW);
  }
  for (int i =0; i<num3; i++){
    for(int j =0; j<num3; j++){
      if (matriz_mover[j][i]!=0){
        index_izquierdad=i;
        index_arriba=j;
      }
    }
  }
}

void mostrar_matriz(){
  for (int i=0;i<num3;i++){
  	pinMode(matriz_led_col[i],OUTPUT);
    for (int j=0;j<num3;j++){
      if (matriz_roja_verde[i][j][2] == 1){
      	digitalWrite(matriz_roja_verde[i][j][0],HIGH);
      	delay(5);
      	digitalWrite(matriz_roja_verde[i][j][0],LOW);
      }else if (matriz_roja_verde[i][j][2] == 2){
      	digitalWrite(matriz_roja_verde[i][j][1],HIGH);
        delay(5);
        digitalWrite(matriz_roja_verde[i][j][1],LOW);
      }
    }
    pinMode(matriz_led_col[i],INPUT);
  }
}

void loop() {
  mostrar_matriz();
  mover();
}