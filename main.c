#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core/core_c.h"
#include <stdio.h>

int main( int argc, char** argv ) {
  CvMat *subimage = cvLoadImageM(argv[1], CV_LOAD_IMAGE_ANYDEPTH);
  CvMat *contextImage = cvLoadImageM(argv[2], CV_LOAD_IMAGE_ANYDEPTH);
  int cols = contextImage->cols - subimage->cols + 1;
  int rows = contextImage->rows - subimage->rows + 1;

  CvMat *result = cvCreateMat(rows, cols, CV_32FC1);

  cvMatchTemplate(contextImage, subimage, result, CV_TM_CCORR);

  // normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
  cvNormalize(result, result, 0, 1, CV_MINMAX, NULL);

  // minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
  double minVal, maxVal;
  CvPoint minLoc, maxLoc;
  cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);

  printf("%d, %d\n", minLoc.x, minLoc.y);
  printf("%d, %d\n", maxLoc.x, maxLoc.y);
  printf("%f\n%f\n", minVal, maxVal);

  return 0;
}
