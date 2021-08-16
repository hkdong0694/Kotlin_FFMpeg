#include <jni.h>
#include <string>
// jstring -> JNI 에서 사용하는 데이터 구조, 자바 문자열의 포인터를 가리키는 포인터 타입이다.

extern "C" {
#include "libavformat/avformat.h"
}

extern "C" jstring
Java_com_example_ffmpegsample_MainActivity_stringFromJNI(JNIEnv* env,jobject ) {
    std::string hello = "Hello from C++";

    av_register_all();

    return env->NewStringUTF(hello.c_str());
}