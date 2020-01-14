# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.0)
# プロジェクト名と使用する言語を設定
project(pso-example CXX)

#コンパイラとオプション
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-fPIC -O3 -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#ライブラリ位置(find_packageで探せないもの)
set(Optim_INCLUDE_DIR ./optim_build/include/optim)
set(Optim_LIBRARY_DIR ./optim_build/lib)
set(Optim_LIBS optim)

#ライブラリ(armadillo)
find_package(Armadillo REQUIRED)
include_directories(${Armadillo_INCLUDE_DIR})
link_directories(${Armadillo_LIBRARY_DIR})
#ライブラリ(optim)
include_directories(${Optim_INCLUDE_DIR}) #　コンパイラオプションの -I
link_directories(${Optim_LIBRARY_DIR}) # 同上 -L

# mainという実行ファイルをmain.cppから作成
#add_executable(a.out main.cpp hello.cpp) # 複数あるときの例
add_executable(main main.cpp)
#ライブラリとリンクする
target_link_libraries(main ${Optim_LIBS} ${Armadillo_LIBS})
