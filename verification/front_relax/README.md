Relaxation of a front in a channel : simplest example that uses GM-Redi parameterization
================================================================================

A 2-D, y-z set-up is used to mimic a zonally symmetric, reentrant channel with a baroclinicly unstable initial density front. 
As meso-scale eddies are not resolved in this 2-D set-up, the GM-Redi parameterization is used to represent their effects.

### Overview:
This experiment contains 5 set-up (with corresponding input dir) that can be run with
the same executable (built from "build/" dir using customized code from "code/"):
All five uses a simple EOS ($ \rho' = -\ rho_{Nil} alpha T'$) and treats
salt as a passive tracer ; without any surface forcing, the density front is expected
to flatten (GM effect) while salinity spread along isopycnal (Redi diffusion).

The primary test, using input files from "input/" dir, is the simplest one, with flat bottom
and stratified every-where (background $ N = 2.10^{-3}$ see matlab script "input/gendata.m"),
avoiding the need for tapering or clipping.
non-uniform resolution in both direction (15 levels from 50.m to 400.m thickness 
near the bottom and and, in Y-direction, 32 grid-points with about 10.km spacing). 
All binary input files have been generated using matlab script "input/gendata.m".
It uses the skew-flux formulation of GM with same Redi and GM diffusivity 
( GM_background_K $= 1000. m^2/s$, see input/data.gmredi)
Note that 10 dead levels were added (below the bottom) to allow to use the same
executable (compiled with Nr = 25) for all 5 set-up.

The secondary test "input.in_p/" dir is the same as the
primary test but converted to use P-coordinates instead of height coordinates.
For the purpose of comparing P and Z coordinate, gravity and reference density
"rhoNil" are set to round number (resp. 10 and 1000) to facilitate conversions.
Binary input files have been generated from matlab script "input.in_p/gendata.m".
It uses the advective form of GM with same Redi and GM diffusivity 
( GM_background_K = 1000. m^2/s, see input.in_p/data.gmredi).

The next two secondary setup, "input.mxl/" and "input.bvp/" are very similar,
using the same binary input files from "input.mxl/" dir that use the full
25 levels model to represent a 10 level, 200 m thick mixed layer on top of a stratified warm bowl of water.
The "input.mxl/" illustrate the use of the transition-layer tapering scheme "fm07"
with the skew-flux formulation of GM with same Redi and GM diffusivity 
( GM_background_K = 1000. m^2/s, see input.mxl/data.gmredi) and a flat bottom
while the secondary test "input.bvp/" has a sloping bottom and uses the 
Boundary-Value Problem (GM_useBVP=T, with 5 modes: GM_BVP_modeNumber=5,) 
of the GM advective form with same Redi and GM diffusivity 
( GM_background_K = 1000. m^2/s, see input.bvp/data.gmredi).
In addition the sub-meso parameterization is activated (GM_useSubMeso=T).

The last secondary test "input.top/" shares some similarity (similar warm bowl, use BVP
with GM advective form) with the previous ones except that the top model is depressed by
50.m near the center, as it would under, e.g., a floating ice-shelf.
Also the mixed layer is thinner (60.m only) and very weakly stratified (N = 10^-6)
and vertical resolution is slightly different, reaching a maximum depth of 2.5 km
(vs only 2.km in 2 previous set-up).

input/
input.in_p/
input.mxl/
input.bvp/
input.top/

Configure and compile the code:
```
  cd build
  ../../../tools/genmake2 -mods ../code [-of my_platform_optionFile]
  make depend
  make
  cd ..
```

To run primary test:
```
  cd run
  ln -s ../input/* .
  ../build/mitgcmuv > output.txt
```

There is comparison output in the directory:
  results/output.txt

To run any of secondary "scd" test, "$scd" in "in_p", "mxl", "bvp", "top":
with "prepare_run" step only for "bvp"
```
  cd run
  rm *
  ln -s ../input.$scd/* .
  ln -s ../input/* .
  ( ./prepare_run )
  ../build/mitgcmuv > output.txt
```
but for "bvp" test, need also to execute
```
  ./prepare_run
```
just before running "mitgcmuv".

There is comparison output in the directory:
  results/output.$scd.txt

Comments:
  The input data is real*4 and generated using the MATLAB script
  gendata.m.

