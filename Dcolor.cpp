#include "dcolorComb.h"
#include <iostream>
#include <jni.h>
#include "Dcolor.h"

using namespace cv;


JNIEXPORT jobject JNICALL Java_Dcolor_process
(JNIEnv *, jobject, jobject src, jfloat rad, jfloat h, jfloat v){

  dcolorComb dcolorpro(src, rad, h, v);
  Mat out = dcolorpro.process();

  return out;
}
