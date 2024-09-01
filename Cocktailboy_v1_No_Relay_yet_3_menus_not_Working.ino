#if 1

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000

#define LOWFLASH (defined(__AVR_ATmega328P__) && defined(MCUFRIEND_KBV_H_))

#include "bitmap_RGB.h"

// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino
const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button back_btn, next_btn, back2_btn, next2_btn, back3_btn, next3_btn,bl_btn, vs_btn, tc_btn, bgm_btn, co_btn, ld_btn, bm_btn, ds_btn, fd_btn, vc_btn, cg_btn, gs_btn, ws_btn, ap_btn, ma_btn, mc_btn, ps_btn, lc_btn, bs_btn  ;

int pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x8410
#define ORANGE  0xE880

void setup()
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    tft.begin(ID);
    tft.setRotation(0);  //PORTRAIT
    tft.fillScreen(BLACK);          
menu2();
}

void mixing()
{    
      tft.fillScreen(BLACK); 
      tft.setTextSize(2);
      tft.setTextColor(WHITE);
      tft.setCursor(80, 160);
      tft.println("Just mixing..."); 
      tft.println(""); 
      tft.println("       Please wait");
      delay(5000);
      tft.fillScreen(BLACK); 
      Menu1();
}

// void menu1()
// {    
//    int x = 0, y, w = 128, h = 64;
//    y=0;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)VodkaSprite, 64 * 64, 1, false);
//    y=68;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)BlueLagoon, 64 * 64, 1, false);
//    y=136;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)Cosmopolitan, 64 * 64, 1, false);
//    y=204;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)LemonDrop, 64 * 64, 1, false);
//    y=272;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)BlueMoon, 64 * 64, 1, false);
//    y=340;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)BlueGinMoon, 64 * 64, 1, false);

//     next_btn.initButton(&tft, 240, 440, 150, 64, WHITE, BLACK, WHITE, "Next >>", 2);
//     back_btn.initButton(&tft,75,440, 150, 64, WHITE, BLACK, WHITE, "<< Back", 2);
//     vs_btn.initButton(&tft, 190, 30, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     bl_btn.initButton(&tft, 190, 98, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     co_btn.initButton(&tft, 190, 166, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     ld_btn.initButton(&tft, 190, 234, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     bm_btn.initButton(&tft, 190, 302, 250, 40, BLACK, BLACK, BLACK, "", 2);
//    bgm_btn.initButton(&tft, 190, 370, 250, 40, BLACK, BLACK, BLACK, "", 2);

//     next_btn.drawButton(false);
//     back_btn.drawButton(false);
//     vs_btn.drawButton(false);
//     bl_btn.drawButton(false);
//     co_btn.drawButton(false);
//     ld_btn.drawButton(false);   
//     bm_btn.drawButton(false);
//     bgm_btn.drawButton(false); 

//       tft.setTextSize(2);
//       tft.setTextColor(WHITE);
//       tft.fillRect(70, 7, 230, 40, BLACK);      
//       tft.drawRect(70, 7, 230, 40, WHITE);
//       tft.setCursor(80, 20);
//       tft.println("Vodka Sprite"); 

//       tft.fillRect(70, 75, 230, 40, BLACK);      
//       tft.drawRect(70, 75, 230, 40, WHITE);
//       tft.setCursor(80, 88);
//       tft.println("Blue Lagoon"); 

//       tft.fillRect(70, 143, 230, 40, BLACK);      
//       tft.drawRect(70, 143, 230, 40, WHITE);
//       tft.setCursor(80, 156);
//       tft.println("Cosmopolitan"); 

//       tft.fillRect(70, 211, 230, 40, BLACK);      
//       tft.drawRect(70, 211, 230, 40, WHITE);
//       tft.setCursor(80, 224);
//       tft.println("Lemon Drop"); 

//       tft.fillRect(70, 279, 230, 40, BLACK);      
//       tft.drawRect(70, 279, 230, 40, WHITE);
//       tft.setCursor(80, 292);
//       tft.println("Blue Moon"); 

//       tft.fillRect(70, 347, 230, 40, BLACK);      
//       tft.drawRect(70, 347, 230, 40, WHITE);
//       tft.setCursor(80, 360);
//       tft.println("Blue Gin Moon"); 
//       }

void menu2()
{    
   int x = 0, y, w = 128, h = 64;
   y=0;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)VodkaCranberry, 64 * 64, 1, false);
   y=68;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)GinSour, 64 * 64, 1, false);
   y=136;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)WhiskySour, 64 * 64, 1, false);
   y=204;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)ApplePie, 64 * 64, 1, false);
   y=272;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)PiscoSour, 64 * 64, 1, false);
   y=340;
    tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
    tft.pushColors((const uint8_t*)Margarita, 64 * 64, 1, false);

    next2_btn.initButton(&tft, 240, 440, 150, 64, WHITE, BLACK, WHITE, "Next >>", 2);
    back2_btn.initButton(&tft,75,440, 150, 64, WHITE, BLACK, WHITE, "<< Back", 2);
    vc_btn.initButton(&tft, 190, 30, 250, 40, BLACK, BLACK, BLACK, "", 2);
    gs_btn.initButton(&tft, 190, 98, 250, 40, BLACK, BLACK, BLACK, "", 2);
    ws_btn.initButton(&tft, 190, 166, 250, 40, BLACK, BLACK, BLACK, "", 2);
    ap_btn.initButton(&tft, 190, 234, 250, 40, BLACK, BLACK, BLACK, "", 2);
    ps_btn.initButton(&tft, 190, 302, 250, 40, BLACK, BLACK, BLACK, "", 2);
    ma_btn.initButton(&tft, 190, 370, 250, 40, BLACK, BLACK, BLACK, "", 2);

    next2_btn.drawButton(false);
    back2_btn.drawButton(false);
    vc_btn.drawButton(false);
    gs_btn.drawButton(false);
    ws_btn.drawButton(false);
    ap_btn.drawButton(false);   
    ps_btn.drawButton(false);
    ma_btn.drawButton(false); 

      tft.setTextSize(2);
      tft.setTextColor(WHITE);
      tft.fillRect(70, 7, 230, 40, BLACK);      
      tft.drawRect(70, 7, 230, 40, WHITE);
      tft.setCursor(80, 20);
      tft.println("Vodka Cranberry"); 

      tft.fillRect(70, 75, 230, 40, BLACK);      
      tft.drawRect(70, 75, 230, 40, WHITE);
      tft.setCursor(80, 88);
      tft.println("Gin Sour"); 

      tft.fillRect(70, 143, 230, 40, BLACK);      
      tft.drawRect(70, 143, 230, 40, WHITE);
      tft.setCursor(80, 156);
      tft.println("Whiskey Sour"); 

      tft.fillRect(70, 211, 230, 40, BLACK);      
      tft.drawRect(70, 211, 230, 40, WHITE);
      tft.setCursor(80, 224);
      tft.println("Apple Pie"); 

      tft.fillRect(70, 279, 230, 40, BLACK);      
      tft.drawRect(70, 279, 230, 40, WHITE);
      tft.setCursor(80, 292);
      tft.println("Pisco Sour"); 

      tft.fillRect(70, 347, 230, 40, BLACK);      
      tft.drawRect(70, 347, 230, 40, WHITE);
      tft.setCursor(80, 360);
      tft.println("Margarita"); 
      }

// void menu3()
// {    
//    int x = 0, y, w = 128, h = 64;
//    y=0;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)LondonCosmo, 64 * 64, 1, false);
//    y=68;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)DoubleStrike, 64 * 64, 1, false);
//    y=136;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)TomCollins, 64 * 64, 1, false);
//    y=204;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)CranberryGin, 64 * 64, 1, false);
//    y=272;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)FlyingDutchmen, 64 * 64, 1, false);
//    y=340;
//     tft.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1);
//     tft.pushColors((const uint8_t*)BlueberrySour, 64 * 64, 1, false);

//     next3_btn.initButton(&tft, 240, 440, 150, 64, WHITE, BLACK, WHITE, "Next >>", 2);
//     back3_btn.initButton(&tft,75,440, 150, 64, WHITE, BLACK, WHITE, "<< Back", 2);
//     lc_btn.initButton(&tft, 190, 30, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     ds_btn.initButton(&tft, 190, 98, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     tc_btn.initButton(&tft, 190, 166, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     cg_btn.initButton(&tft, 190, 234, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     fd_btn.initButton(&tft, 190, 302, 250, 40, BLACK, BLACK, BLACK, "", 2);
//     bs_btn.initButton(&tft, 190, 370, 250, 40, BLACK, BLACK, BLACK, "", 2);

//     next3_btn.drawButton(false);
//     back3_btn.drawButton(false);
//     lc_btn.drawButton(false);
//     ds_btn.drawButton(false);
//     tc_btn.drawButton(false);
//     cg_btn.drawButton(false);   
//     fd_btn.drawButton(false);
//     bs_btn.drawButton(false); 

//       tft.setTextSize(2);
//       tft.setTextColor(WHITE);
//       tft.fillRect(70, 7, 230, 40, BLACK);      
//       tft.drawRect(70, 7, 230, 40, WHITE);
//       tft.setCursor(80, 20);
//       tft.println("London Cosmo"); 

//       tft.fillRect(70, 75, 230, 40, BLACK);      
//       tft.drawRect(70, 75, 230, 40, WHITE);
//       tft.setCursor(80, 88);
//       tft.println("Double Strike"); 

//       tft.fillRect(70, 143, 230, 40, BLACK);      
//       tft.drawRect(70, 143, 230, 40, WHITE);
//       tft.setCursor(80, 156);
//       tft.println("Tom Colins"); 

//       tft.fillRect(70, 211, 230, 40, BLACK);      
//       tft.drawRect(70, 211, 230, 40, WHITE);
//       tft.setCursor(80, 224);
//       tft.println("Cranberry Gin"); 

//       tft.fillRect(70, 279, 230, 40, BLACK);      
//       tft.drawRect(70, 279, 230, 40, WHITE);
//       tft.setCursor(80, 292);
//       tft.println("Flying Dutchman"); 

//       tft.fillRect(70, 347, 230, 40, BLACK);      
//       tft.drawRect(70, 347, 230, 40, WHITE);
//       tft.setCursor(80, 360);
//       tft.println("Blueberry Sour"); 
//       }

void loop(void)
{

  bool down = Touch_getXY();

  /////////////Menu1////////////

  //   next_btn.press(down && next_btn.contains(pixel_x, pixel_y));
  //   back_btn.press(down && back_btn.contains(pixel_x, pixel_y));
  //   vs_btn.press(down && vs_btn.contains(pixel_x, pixel_y));
  //   bl_btn.press(down && bl_btn.contains(pixel_x, pixel_y));
  //   co_btn.press(down && co_btn.contains(pixel_x, pixel_y));
  //   ld_btn.press(down && ld_btn.contains(pixel_x, pixel_y));
  //   bm_btn.press(down && bm_btn.contains(pixel_x, pixel_y));
  //   bgm_btn.press(down && bgm_btn.contains(pixel_x, pixel_y));

////////////////MEnu2///////////////
    next2_btn.press(down && next2_btn.contains(pixel_x, pixel_y));
    back2_btn.press(down && back2_btn.contains(pixel_x, pixel_y));
    vc_btn.press(down && vc_btn.contains(pixel_x, pixel_y));
    gs_btn.press(down && gs_btn.contains(pixel_x, pixel_y));
    ws_btn.press(down && ws_btn.contains(pixel_x, pixel_y));
    ap_btn.press(down && ap_btn.contains(pixel_x, pixel_y));
    ps_btn.press(down && ps_btn.contains(pixel_x, pixel_y));
    ma_btn.press(down && ma_btn.contains(pixel_x, pixel_y));

////////////////MEnu3///////////////
    // next3_btn.press(down && next3_btn.contains(pixel_x, pixel_y));
    // back3_btn.press(down && back3_btn.contains(pixel_x, pixel_y));
    // cg_btn.press(down && cg_btn.contains(pixel_x, pixel_y));
    // vc_btn.press(down && vc_btn.contains(pixel_x, pixel_y));
    // lc_btn.press(down && lc_btn.contains(pixel_x, pixel_y));
    // tc_btn.press(down && tc_btn.contains(pixel_x, pixel_y));
    // fd_btn.press(down && fd_btn.contains(pixel_x, pixel_y));
    // ds_btn.press(down && ds_btn.contains(pixel_x, pixel_y));

 /////////////Menu1////////////
    // if (next_btn.justPressed()) {
    //  Serial.println("Next"); 
    //   // menu2();
    // }
    // if (back_btn.justPressed()) {
    //  Serial.println("Back");
    //   // menu3();
    // }
    //     if (vs_btn.justPressed()) {
    //  Serial.println("Mixing Vodka Sprite");
    //   mixing();  
    //   menu1();
    //       }
    
    // if (bl_btn.justPressed()) {
    //  Serial.println("Mixing Blue Lagoon");
    //   mixing();  
    //   menu1();
    // }

    // if (co_btn.justPressed()) {
    //  Serial.println("Mixing Cosmopilitan");
    //   mixing();  
    //   menu1();

    // }

    // if (ld_btn.justPressed()) {
    //  Serial.println("Mixing Lemon Drop");
    //   mixing();  
    //   menu1();

    // }
    //     if (bm_btn.justPressed()) {
    //  Serial.println("Mixing blue Moon");
    //   mixing();  
    //   menu1();
    // }
    //     if (bgm_btn.justPressed()) {
    //  Serial.println("Mixing blue gin moon");
    //   mixing();  
    //   menu1();
    // }
///////////////////menu2////////////////////
    if (next2_btn.justPressed()) {
     Serial.println("Next2"); 
      // menu3();
    }
    if (back2_btn.justPressed()) {
     Serial.println("Back2");
      menu2();
    }
            if (vc_btn.justPressed()) {
     Serial.println("Mixing Vodka Cranberry");
      mixing();  
      menu2();
    }
        if (gs_btn.justPressed()) {
     Serial.println("Mixing Gin Sour");
      mixing();  
      menu2();
    }        
        if (ws_btn.justPressed()) {
     Serial.println("Mixing Whisky Sour");
      mixing();  
      menu2();
    }    
    if (ap_btn.justPressed()) {
     Serial.println("Mixing Apple Pie");
      mixing();  
      menu2();
    }
        
    if (ps_btn.justPressed()) {
     Serial.println("Mixing Pisco Sour");
      mixing();  
      menu2();
    }
        if (ma_btn.justPressed()) {
     Serial.println("Mixing Margarita");
      mixing();  
      menu2();
    }


/////////////////////menu3////////////////////

//         if (next3_btn.justPressed()) {
//      Serial.println("Next3"); 
//       menu1();
//     }
//     if (back3_btn.justPressed()) {
//      Serial.println("Back3"); 
//       menu2();
//     }
//             if (vc_btn.justPressed()) {
//      Serial.println("Mixing Vodka Cranberry");
//       mixing();  
//       menu3();
//     }
//         if (lc_btn.justPressed()) {
//      Serial.println("London Cosmo");
//       mixing();  
//       menu3();
//     }        
//         if (tc_btn.justPressed()) {
//      Serial.println("Mixing Tom Collins");
//       mixing();  
//       menu3();
//     }    
//     if (fd_btn.justPressed()) {
//      Serial.println("Mixing Flying Dutchman");
//       mixing();  
//       menu3();
//     }

//         if (ds_btn.justPressed()) {
//      Serial.println("Double Strike");
//       mixing();  
//       menu3();
//     }
}
#endif


