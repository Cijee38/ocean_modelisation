cmake_minimum_required(VERSION 2.8)
add_definitions(-DMS1)

#Initialisation
Project(CPP_Project_gainc_cackowss)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -g")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

#Liste des fichier sources
file(
	GLOB
	headers
	src/*.h
)

#Déclaration des tests
add_executable(
	init_and_read
	${headers}
	src/Dvector.cpp
	tests/InitRead.cpp
)
# add_executable(
# 	operators
# 	${headers}
# 	src/Dvector.cpp
# 	tests/Operators.cpp
# )
add_executable(
	init_complex
	${headers}
	src/Dvector.cpp
	tests/testComplex.cpp
	
)
# add_executable(
# 	resize
# 	${headers}
# 	src/Dvector.cpp
# 	tests/testResize.cpp
# )
# add_executable(
# 	operateur_unaire
# 	${headers}
# 	src/Dvector.cpp
# 	tests/testOpUn.cpp
# )

add_executable(
	height
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	tests/testHeight.cpp
)
add_executable(
	gerstnerWave
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/GerstnerWave.cpp
	tests/testGerstner.cpp
)
add_executable(
	gerstnerWaveModel
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/WaveModel.cpp
	src/GerstnerWave.cpp
	src/GerstnerWaveModel.cpp
	tests/testGerstnerWaveModel.cpp
)
add_executable(
	philipsWave
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/PhilipsWave.cpp
	tests/testPhilips.cpp
)

add_executable(
	philipsWaveModel
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/WaveModel.cpp
	src/PhilipsWave.cpp
	src/PhilipsWaveModel.cpp
	tests/testPhilipsWaveModel.cpp
)
add_executable(
	fftcl
	${headers}
	src/Dvector.cpp
	tests/testFFTCL.cpp
)
add_executable(
	ocean
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/WaveModel.cpp
	src/GerstnerWave.cpp
	src/GerstnerWaveModel.cpp
	src/PhilipsWave.cpp
	src/PhilipsWaveModel.cpp
	src/Ocean.cpp
	tests/testOcean.cpp
)
add_executable(
	final_philips
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/WaveModel.cpp
	src/GerstnerWave.cpp
	src/GerstnerWaveModel.cpp
	src/PhilipsWave.cpp
	src/PhilipsWaveModel.cpp
	src/Ocean.cpp
	src/window.cxx
	src/camera.cxx
	tests/main.cxx
)
add_executable(
	final_gerstner
	${headers}
	src/Dvector.cpp
	src/Height.cpp
	src/Wave.cpp
	src/WaveModel.cpp
	src/GerstnerWave.cpp
	src/GerstnerWaveModel.cpp
	src/PhilipsWave.cpp
	src/PhilipsWaveModel.cpp
	src/Ocean.cpp
	src/window.cxx
	src/camera.cxx
	tests/main_gerstner.cxx
)
target_link_libraries(final_philips ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(final_gerstner ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
