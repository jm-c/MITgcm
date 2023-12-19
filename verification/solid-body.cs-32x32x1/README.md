Simple cubed-sphere grid, solid-body rotation test case
========================================================

### Overview:
This is a single level, steady-state example on cubed-sphere (cs-32) grid with initial zonal wind field and surface pressure anomaly that corresponds to an additional relative rotation 
($ \omega' $) on top of the solid-planet rotation ($\Omega$):

$$ U = \omega' \times R $$

The **secondary** test `rough.Bot` uses the logarithmic law of the wall to compute the drag coefficient for quadratic bottom drag as a function of distance from the bottom (i.e. cell thickness) and a prescribed roughness length `zRoughBot = 0.01` (in meters). For this configuration (i.e. vertical grid spacing) this value of `zRoughBot` corresponds to approximately `bottomDragQuadratic=5.E-2`. For consistency, the bottom boundary conditions is set to free slip (`no_slip_bottom=.FALSE.`).

## Instructions
Configure and compile the code:

```
  cd build
  ../../../tools/genmake2 -mods ../code [-of my_platform_optionFile]
  make depend
  make
  cd ..
```

To run:

```
  cd run
  ln -s ../input/* .
  ln -s ../build/mitgcmuv .
  ./mitgcmuv > output.txt
  cd ..
```

There is comparison output in the directory:

```
  results/output.txt
```

## Comments
  The input data is `real*8` and generated using the MATLAB script gendata.m.

