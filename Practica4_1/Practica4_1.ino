//Maquinas Digitales 2016
//Prof. José Luis del Rio
//Uso de pantalla Nokia 3310 o 5110, que usan el controlador PCD8544 
//Para Graficar

//Es necesario incluir las librerias en Programa/incluir libreria/gestionar librerias
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


// pin 3 - Serial clock out (SCLK)(3)
// pin 4 - Serial data out (DIN)(4)
// pin 5 - Data/Command select (D/C)(5)
// pin 7 - LCD chip select (CS)(7)
// pin 6 - LCD reset (RST)(6)

Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 7, 6);

void setup() {
 display.begin();
  // Inicialización de la pantalla

  //Contraste de la pantalla
  display.setContrast(60);

  display.display(); // Muestra logo
  delay(1);
  display.clearDisplay();   // Limpia la pantalla y el buffer

  // Fijamos a A0 como entrada
  pinMode(A0,INPUT);
}

void loop() {
  int c;
  c=analogRead(A0);
  // Dibuja los ejes y el marco, en una pantalla de 84x48 pixeles
  for (float x=0;x<=84;x++){
  display.drawPixel(x,23+((c/40)*(sin((x/12)))), BLACK);
  display.display();//manda información al display
  } 
  display.clearDisplay();
}
