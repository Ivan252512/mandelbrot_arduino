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
}

void loop() {

int ImageHeight=57;
int ImageWidth=84;
double MinRe = -2.0;
double MaxRe = 1.0;
double MinIm = -1.2;
double MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
double Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);
unsigned MaxIterations = 30;

for(unsigned y=0; y<ImageHeight; ++y)
{
    double c_im = MaxIm - y*Im_factor;
    for(unsigned x=0; x<ImageWidth; ++x)
    {
        double c_re = MinRe + x*Re_factor;

        double Z_re = c_re, Z_im = c_im;
        bool isInside = true;
        for(unsigned n=0; n<MaxIterations; ++n)
        {
            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
            if(Z_re2 + Z_im2 > 4)
            {
                isInside = false;
                break;
            }
            Z_im = 2*Z_re*Z_im + c_im;
            Z_re = Z_re2 - Z_im2 + c_re;
        }
        if(isInside) { 
  display.drawPixel(x,y, BLACK);
  display.display();
        }
    }
}
}
