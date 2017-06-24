/**************************************************************

	The program reads an BMP infrared image and a BMP colored image file 
    of the same object or landscape and creates a new
	image that has the colored and infrared features of the object.

**************************APPROACH ONE************************************/

#include "../include/qdbmp.h"
#include "../include/qdbmp.c"
#include <stdio.h>

//use argc and argv for console app in UNIX env
int main()
{
	UCHAR	rc, gc, bc,ri,gi,bi;
	UINT	widthc, heightc,widthi,heighti;
	UINT	x, y;//index positions of the array of pixels
	struct BMP*	bmp_color;
	struct BMP* bmp_if;
	struct BMP*  bmp_out;

	/* Read colored and infrared images in bmp_color,bmp_if */

	bmp_color = BMP_ReadFile( "colorwatch.bmp" );
	bmp_if = BMP_ReadFile("ifwatch.bmp");
	BMP_CHECK_ERROR( stdout, -1 );

	/* Get colored image's dimensions */
	widthc = BMP_GetWidth( bmp_color );
	heightc = BMP_GetHeight( bmp_color );
    /* Get infrared image's dimensions */
    widthi = BMP_GetWidth( bmp_if );
	heighti = BMP_GetHeight( bmp_if );
    /* Create new image with 3rd arg as depth*/
    bmp_out=BMP_Create(widthc,heightc,24);

	/* Iterate through all the image's pixels */

	for ( x = 0 ; x < widthc ; ++x )
	{
		for ( y = 0 ; y < heightc ; ++y )
		{
			/* Get pixel's RGB values */

			BMP_GetPixelRGB( bmp_color, x, y, &rc, &gc, &bc );
			BMP_GetPixelRGB( bmp_if, x, y, &ri, &gi, &bi );

           /* set in new image avg of both pixels.Will desaturate the new image*/

		    BMP_SetPixelRGB( bmp_out, x, y, (rc+ri)/2,  (gc+gi)/2,  (bc+bi)/2 );
		}
	}

	/* Save result */
	BMP_WriteFile( bmp_out, "imageout.bmp" );
	BMP_CHECK_ERROR( stdout, -2 );


	/* Free all memory allocated for the images */
	BMP_Free( bmp_out);
    BMP_Free( bmp_color);
    BMP_Free( bmp_if);

	return 0;
}

//end of program
