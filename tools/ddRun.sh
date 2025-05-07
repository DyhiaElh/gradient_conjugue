#!/bin/bash

OUTDIR="$1"
GRADIENT_DIR=/home/catC/de283294/projet_gradient/data
PROG=/home/catC/de283294/projet_gradient/build/test_gradient

# valgrind --tool=verrou --rounding-mode=random --float=yes $PROG > $OUTDIR/res.dat
valgrind --tool=verrou --float=yes $PROG > $OUTDIR/res.dat

