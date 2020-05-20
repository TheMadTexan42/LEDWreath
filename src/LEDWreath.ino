// This #include statement was automatically added by the Particle IDE.
#include <FastLED.h>

FASTLED_USING_NAMESPACE;

#define LED_PIN     D5
#define CHIPSET     WS2811
#define NUM_LEDS (140)

CRGB    leds[NUM_LEDS];


void setup() 
{
    delay(2000);
    FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
}

short hue=0;


void loop()
{
    WithBow();
    delay(10000);
    
    for (short i=0; i<13; i++)
    {
        ChasingDots(hue);
        hue+=20;
    }

    for (short i=0; i<26; i++)
    {
        ClappingHalfs(hue);
        hue+=10;
    }

    RainbowTwirl();

    for (short i=0; i<26; i++)
    {
        BreathingCircles(hue);
        hue+=10;
    }

    hue=0;
    
    for (short i=0; i<26; i++)
    {
        ChasingLines(hue);
        hue+=10;
    }

    hue=0;
    
    for (short i=0; i<26; i++)
    {
        ChasingDoubleLines(hue);
        hue+=10;
    }

    hue=0;
    
    for (short i=0; i<26; i++)
    {
        Pinwheel(hue);
        hue+=10;
    }

    for (short i=0; i<13; i++)
    {
        Pinwheel2DRedonGreen();
        hue+=20;
    }
}

void WithBow()
{
    LightAll(100, 100);
    LightLine(26, 0, 255);
    LightLine(2, 0, 255);

//center
    leds[56] = CRGB::Red;

    leds[57] = CRGB::Red;
    leds[83] = CRGB::Red;
    
    leds[57+28] = CRGB::Red;
    leds[57-28] = CRGB::Red;
    leds[83+28] = CRGB::Red;
    leds[83-28] = CRGB::Red;
    
    FastLED.show();
}

void ChasingDots(short hue) 
{
    for (short i=0; i<NUM_LEDS; i++)
    {
        DimAll(200);
        leds[i].setHSV(hue,255,255);
        if(i>=14)
        {
            leds[i-14].setHSV(hue,255,255);
        }
        else
        {
            leds[NUM_LEDS+i-14].setHSV(hue,255,255);
        }
        FastLED.show();
        delay(20);
    }
}

void ClappingHalfs(short hue)
{

    for (short i=0; i<=13; i++)
    {
        LightLine(i, hue, 255);
        LightLine(i+14, hue, 255);
        FastLED.show();
        delay (50);
    }
    delay(50);
    
    for (short i=13; i>=0; i--)
    {
        LightLine(i, hue, 0);
        LightLine(i+14, hue, 0);
        FastLED.show();
        delay (50);
    }
    delay(50);
    
}

void RainbowTwirl()
{
    short hue=0;
    for (short k=0; k<500; k++)
    {
        for (short i=0; i<28; i++)
        {
            LightLine(i, hue, 200);
            hue+=9;
        }
        FastLED.show();
        delay(50);
    }
}

void Pinwheel2DRedonGreen()
{
    for (short j=0; j<4; j++) {
        for (short i=0; i<7; i++)
        {
            LightAll(100, 100);
            LightLine(i, 0, 255);
            LightLine(i+7, 0, 255);
            LightLine(i+14, 0, 255);
            LightLine(i+21, 0, 255);
            FastLED.show();
            delay(50);
        }
    }
    
    for (short j=0; j<4; j++) {
        for (short i=5; i>0; i--)
        {
            LightAll(100, 100);
            LightLine(i, 0, 255);
            LightLine(i+7, 0, 255);
            LightLine(i+14, 0, 255);
            LightLine(i+21, 0, 255);
            FastLED.show();
            delay(50);
        }
    }
}

void LightAll(short hue, short luma)
{
    for (short i=0; i<NUM_LEDS; i++)
    {
        leds[i].setHSV(hue,255,luma);
    }

}

void ChasingLines(short hue)
{
    for (short i=0; i<28; i++)
    {
        DimAll(220);
        LightLine(i, hue, 200);
        FastLED.show();
        delay(25);
    }
}

void ChasingDoubleLines(short hue)
{
    for (short i=0; i<14; i++)
    {
        DimAll(200);
        LightLine(i, hue, 200);
        LightLine(i+14, hue, 200);
        FastLED.show();
        delay(50);
    }
}

void Pinwheel(short hue)
{
    for (short i=0; i<7; i++)
    {
        DimAll(160);
        LightLine(i, hue, 200);
        LightLine(i+7, hue, 200);
        LightLine(i+14, hue, 200);
        LightLine(i+21, hue, 200);
        FastLED.show();
        delay(100);
    }
}

void BreathingCircles(short hue)
{
    for (short i=0; i<5; i++)
    {
        DimAll(160);
        LightCircle(i, hue, 200);
        FastLED.show();
        delay(100);
    }

    for (short i=3; i>0; i--)
    {
        DimAll(160);
        LightCircle(i, hue, 200);
        FastLED.show();
        delay(100);
    }
}

void LightLine(short linenum, short hue, short luma)
{
    // A line is 5 leds that are offset by 28 from each other
    short index;
    index = linenum;
    leds[index].setHSV(hue,255,luma);
    index+=28;
    leds[index].setHSV(hue,255,luma);
    index+=28;
    leds[index].setHSV(hue,255,luma);
    index+=28;
    leds[index].setHSV(hue,255,luma);
    index+=28;
    leds[index].setHSV(hue,255,luma);
}

void LightCircle(short circlenum, short hue, short luma)
{
    short start = circlenum*28;
    short end = start + 28;
    
    for (int i = start; i<end; i++)
    {
        leds[i].setHSV(hue, 255, luma);
    }
}

// scale the brightness of the screenbuffer down
void DimAll(byte value)  
{
  for(int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i].nscale8(value);
  }
}
