# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
# 사용할 CMake의 최소 버전 설정
cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("myapplication")

# 안드로이드에서 사용할 라이브러리의 이름과 공유 및 정적 여부, 소스 코드 경로 설정
# native-lib , SHARED , native-lib.cpp
# 아래 예제 처럼 컴파일 시 CMake는 컴파일 결과물을 libnative-lib.so 라는 이름으로 저장한다.
add_library( # Sets the name of the library.
        # 라이브러리 이름
        native-lib

        # Sets the library as a shared library.
        # 공유 라이브러리
        SHARED

        # Provides a relative path to your source file(s).
        # 코드 경로 설정!!
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# 소스 코드에서 사용하는 헤더 파일이 들어있는 디렉토리 설정
# 설정해주지 않아도 동기화 이후에는 자동으로 헤더 파일이 인식되기는 하지만
# 설정을 해주면 컴파일 단계에서 연결된 헤더 파일을 볼 수 있다.
# include_directories(src/main/cpp/inclues/)

# 이미 존재하는 안드로이드 NDK 기본 라이브러리 사용하기
# NDK에 있는 log 라는 라이브러리를 찾아서 log-lib이라는 변수명으로 저장 후
# native-lib 에서 불러와 사용하는 코드
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )
target_link_libraries( # Specifies the target library.
        native-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )