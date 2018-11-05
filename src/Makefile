CXX = clang++
CXXFLAGS = -Wall -std=c++11 -g

exe:
	$(CXX) $(CXXFLAGS) Dvector.cpp
test1:
	$(CXX) $(CXXFLAGS) Dvector.cpp test1.cpp -o test
testB:
	$(CXX) $(CXXFLAGS) Dvector.cpp testB.cpp -o testB
testCpx:
	$(CXX) $(CXXFLAGS) Dvector.cpp testComplex.cpp -o testCpx
test2:
	$(CXX) $(CXXFLAGS) Dvector.cpp test2.cpp -o test2
resize:
	$(CXX) $(CXXFLAGS) Dvector.cpp testResize.cpp -o resize
unaire:
	$(CXX) $(CXXFLAGS) Dvector.cpp testOpUn.cpp -o unaire
height:
	$(CXX) $(CXXFLAGS) Height.cpp Dvector.cpp testHeight.cpp -o testHeight
gerstner:
	$(CXX) $(CXXFLAGS) Dvector.cpp Wave.cpp GerstnerWave.cpp testGerstner.cpp -o testGerstnerWave
philips:
	$(CXX) $(CXXFLAGS) Dvector.cpp Wave.cpp PhilipsWave.cpp testPhilips.cpp -o testPhilips
gerstnerwavemodel:
	$(CXX) $(CXXFLAGS) Dvector.cpp Height.cpp Wave.cpp WaveModel.cpp GerstnerWaveModel.cpp GerstnerWave.cpp testGerstnerWaveModel.cpp -o testGWM
testFftcl:
	$(CXX) $(CXXFLAGS) Dvector.cpp testFFTCL.cpp -o testFftcl
ocean:
	$(CXX) $(CXXFLAGS) Dvector.cpp Height.cpp Wave.cpp WaveModel.cpp PhilipsWave.cpp PhilipsWaveModel.cpp GerstnerWave.cpp GerstnerWaveModel.cpp Ocean.cpp testOcean.cpp -o testOcean
main:
	$(CXX) $(CXXFLAGS) Dvector.cpp Height.cpp Wave.cpp WaveModel.cpp PhilipsWave.cpp PhilipsWaveModel.cpp GerstnerWave.cpp GerstnerWaveModel.cpp Ocean.cpp window.cxx camera.cxx main.cxx -o testVisu -lGLU -lGL -lglut
