#clear
reset

#you may want to decomment this the first time you compile
rm CMakeCache.txt

#rm $KRATOS_ROOT_PATH/libs/*

cmake289 $KRATOS_ROOT_PATH \
-DCMAKE_C_COMPILER=gcc \
-DCMAKE_CXX_COMPILER=g++ \
-DCMAKE_Fortran_COMPILER=gfortran-4.8 \
-DCMAKE_CXX_FLAGS="${CMAKE_CXX_FLAGS} --std=c++11" \
-DCMAKE_C_FLAGS="${CMAKE_C_FLAGS}" \
-DCMAKE_Fortran_FLAGS="${CMAKE_Fortran_FLAGS}" \
-DCMAKE_BUILD_TYPE=Release \
-DMPI_C_COMPILER="$MPI_ROOT/bin/mpicc" \
-DMPI_CXX_COMPILER="$MPI_ROOT/bin/mpicxx" \
-DPYTHON_INCLUDE_DIR="/usr/include/python2.7" \
-DPYTHON_LIBRARY="/usr/lib/x86_64-linux-gnu/libpython2.7.so" \
-DPYTHON_EXECUTABLE="/usr/bin/python2.7" \
-DEXCLUDE_ITSOL=ON \
-DEXTERNAL_SOLVERS_APPLICATION=ON \
-DSTRUCTURAL_APPLICATION=ON \
-DMKL_SOLVERS_APPLICATION=OFF \
-DMKLSOLVER_INCLUDE_DIR="/opt/intel/mkl/include" \
-DMKLSOLVER_LIB_DIR="/opt/intel/mkl/lib/intel64" \
-DUSE_INTEL_GREATER_THAN_13=TRUE \
-DMETIS_APPLICATION=OFF \
-DUSE_METIS_5=ON \
-DMETIS_ROOT_DIR="/opt/parmetis-4.0.3" \

#add VERBOSE=1 to compile in verbose mode
make install -j`nproc`

