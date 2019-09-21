#ifndef M4_EYES_H
#define M4_EYES_H

#define COLOR565(r, g, b)               (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))
#define RGB2565(r, g, b)                COLOR565(r, g, b)
#define RGB_TO_565(r, g, b)             COLOR565(r, g, b)
#define RGB_TO_565_BIGENDIAN(r, g, b)   ((COLOR565(r,g,b) >> 8) | (uint16_t)(COLOR565(r,g,b) << 8))

// define glint shape
char glintBitTable[8] = {
  0x3C,
  0x7E,
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  0x7E,
  0x3C,
  };

#define GLINT_RADIUS      4     // matches size of glintBitTable[]
#define GLINT_OFFSET_UP   9
#define GLINT_OFFSET_LEFT 9
#define GLINT_STABILIZER  1/3   // If this were 1, glint would be decoupled from pupil position, i.e. would be stationary in the center of the screen.
                                // If it were 0, glint would be fixed on the pupil and thus would not display a natural reaction to eye rotation.
                                // To see change of glint position as eye rotates: observe eye-roll video at e.g.
                                // https://www.istockphoto.com/video/senior-adult-male-looking-through-magnifying-glass-gm490843002-75323713

#define GLINT_COLOR       (RGB_TO_565_BIGENDIAN(255,255,255))

#endif    // #ifndef M4_EYES_H
