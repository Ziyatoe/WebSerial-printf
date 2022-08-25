#ifndef __EXTDWEBSER_H
#define __EXTDWEBSER_H

/*
  from Ziyatoe,
  https://github.com/Ziyatoe/WebSerial-printf

  printf extension for the public WebSerial library
  see the webserial.ino as example

*/
#include <Arduino.h>
#include <WebSerial.h>

#define DEBUG_OUT extendedWebSerial

static class {
public:
    void begin(...) {}
    void print(...) {}
    void println(...) {}
    void flush() {}
    bool available() { return false;}
    int  readBytes(...) { return 0;}
    void printf( const char * format, ... )
    {
      char buffer[256];
      va_list args;
      va_start (args, format);
      vsprintf (buffer,format, args);
      WebSerial.print (buffer);
      va_end (args);
    }

} extendedWebSerial;
//-------------------------------------------------------------

#endif
