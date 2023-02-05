#include <wtypes.h>
#include <iostream>
using namespace std;

// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

int main()
{       
   int horizontal;
   int vertical;
   GetDesktopResolution(horizontal, vertical);
   cout << horizontal << '\n' << vertical << '\n';
   return 0;
}